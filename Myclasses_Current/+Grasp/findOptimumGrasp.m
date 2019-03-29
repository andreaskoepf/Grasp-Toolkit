function results = findOptimumGrasp(hand,obj,varargin)
%results  =  findOptimum(hand,obj,options)
% options struct
%   JointProfiles:   f x 1 JointProfile array where f is equal to
%                       the number of fingers and each object contains a
%                       corresponding an initial and final Joint
%                       Configuration as well as the number of step.  Their
%                       order should be equal to the corresponding index in
%                       the hand object
%   SearchIndices:  f x 1 double array where each element corresponds to an
%                   index of a corresponding finger in the hand object.
%                   This will be use to guide the search in a corresponding
%                   order.
%   InitialContactPoints: 1 x p ContactPoint array whose corresponding
%                   wrench sets are used to initialize the Wrench Space.
%   Resolution :    1 x 1 | 1 x 2 double array indicating the number of
%                   points to be used in the discretization of each
%                   friction cone produced by a given contact.  Use a 1 x 2
%                   double array if the friction models are SFCe or SFCl.
%   Tolerance :     1 x 1 double tolerance value used for all corresponding
%                   computations.

% parsing inputs in option data structure
% initializing variables
continueSearchingOptimumGrasp = true;

frictionModel = 'PCF';
friction = 0.5;
resolution = 8;
numWrenchSpaceDimensions = 6;

% creating test hyperplane container
TestHyperplaneContainer = containers.Map(0,struct('field1',[],'field2',[]));
TestHyperplaneContainer.remove(0);

% creating test hyperplane container
tolerance = 1e-10;



switch nargin
    
    case 2
        
        indices = 1:length(hand.Fingers);
        %usingEnvironment = false;
        autoGenerateJointLimits = true;
        
        % input structure to findForceClosureGrasp Method
        fcOptions.SearchIndices = 1:length(hand.Fingers);
        fcOptions.Resolution = resolution;
        fcOptions.Tolerance = tolerance;
        
    case 3
        
        options = varargin{1};
        
        
        indices = options.SearchIndices;
        
        % parsing joint profiles
        if isfield(options,'JointProfiles') && ~isempty(options.JointProfiles)
            
            jointProfiles = options.JointProfiles;
            autoGenerateJointLimits = false;
            
        else
            
            autoGenerateJointLimits = true;
            
        end
        
        
        % parsing resolution
        if isfield(options,'Resolution') && ~isempty(options.Resolution)
            
            resolution  = options.Resolution;
            
        end
        
        
        
        % parsing tolerance
        if isfield(tolerance,'Tolerance') && ~isempty(options.Tolerance)
            
            tolerance = options.Tolerance;
            
        end
        
        fcOptions = options;
        
    otherwise
        
        error('invalid number of input arguments')
        
end

% calling findForceClosureGrasp
[results,CollisionGroupContainer] = Grasp.findForceClosureGrasp(hand,obj,fcOptions);


% retrieving data
wrenchSpace = results.WrenchSpace;
currentNumberOfFingersSearched = length(results.SearchedIndices);
environment = results.Environment;
isEnvironmentEmpty = false;

if currentNumberOfFingersSearched == length(indices)
    
    return
    
end

if ~wrenchSpace.isForceClosure
    
    error('Force Closure Grasp could not be found, try a different finger search order')
    
end

if isempty(results.Environment)
    
    isEnvironmentEmpty = true;
    
end


currentFingerIndex = indices(currentNumberOfFingersSearched+1);

% STARTING SEARCH FOR OPTIMUM GRAPS
while continueSearchingOptimumGrasp
    
    
    % STEP 2 --------------------------------------------------------------
    fprintf('\nSTEP 2 ---------------------------------------------------\n')
    fingerObj = hand.Fingers(currentFingerIndex);
    
    if autoGenerateJointLimits
        
        jointLimits = fingerObj.JointLimits;
        jointSteps = 10*ones(fingerObj.DOF,1);
        
    else
        
        jointConf= jointProfiles(currentFingerIndex).JointConfigurations;
        jointLimits = [jointConf(1).JointValues jointConf(2).JointValues];
        jointSteps = repmat(jointProfiles(currentFingerIndex).NumSteps,fingerObj.DOF,1);
        
    end
    
    ccdOptions.Environment = environment;
    ccdOptions.JointLimitValues = jointLimits;
    ccdOptions.JointSteps = jointSteps;
    
    fprintf('\nFinding Optimum FC Grasp: Step - 2:  Calling CCD on %ith finger\n',currentFingerIndex)
    collisionGroupResult = CollisionDetection.ContinuousCollisionDetection.performCCDArticulatedBodyTest(...
        fingerObj,obj,ccdOptions);
    
    % if no valid collisions were found then advance to the next iteration
    if length(collisionGroupResult) == 1
        
        if collisionGroupResult.NumCollisionPairs == 0
            
            currentNumberOfFingersSearched = currentNumberOfFingersSearched + 1;
            
            
            if currentNumberOfFingersSearched == length(hand.Fingers)
                
                continueSearchingOptimumGrasp = false;
                
            else
                
                currentFingerIndex = indices(currentNumberOfFingersSearched + 1);
                
            end
            
            fprintf('\nFound 0 collision groups for the %ith finger, moving to next iterations\n',currentFingerIndex)
            
            % adding objects to the environment
            fingerObj.JointValues = jointLimits(:,1); % may produce an invalid configuration if there is interpenetration
            fingerObj.updateAllFrames;
            
            %CollisionGroupContainer(currentNumberOfFingersSearched+1) = collisionGroupResult(selectedWrenchGroupIndex);
            
            for n = 1:length(fingerObj.Links);
                
                if isEnvironmentEmpty
                    
                    environment = Solid(fingerObj.Links(n));
                    isEnvironmentEmpty = false;
                    
                else
                    
                    environment = environment + fingerObj.Links(n);
                    
                end
                
            end
            
            continue
            
        end
        
    end
    
    % STEP 3 --------------------------------------------------------------
    fprintf('\nSTEP 3 ---------------------------------------------------\n')
    
    wrenchSpace.resetCurrentFacetIndex;
    
    
    % STEP 4 --------------------------------------------------------------
    fprintf('\nSTEP 4 ---------------------------------------------------\n')
    % retrieving hyperplane corresponding to the closest facet in the
    % wrench space
    testHyperplane = wrenchSpace.getCurrentFacetHyperplane;
    
    
    continueSearchingOptimumSet = true;
    collisionGroupsIndices = 1:length(collisionGroupResult);
    collisionGroupsInPositiveHalfSpace = false(1,length(collisionGroupResult));
    collisionGroupsMaxDistance = zeros(1,length(collisionGroupResult));
    maxDistance = 0;
    remainingCollisionGroupsIndices = collisionGroupsIndices;
    
    % STEP 5 --------------------------------------------------------------
    fprintf('\nSTEP 5 ---------------------------------------------------\n')
    
    fprintf('\nTesting against closest hyperplanes\n')
    
    counter0 = 0;
    while continueSearchingOptimumSet
        
        for n = remainingCollisionGroupsIndices;
            
            wrenchSets = collisionGroupResult(n).createWrenchSet;
            
            for m = 1:length(wrenchSets)
                
                wSet = wrenchSets(m);
                wSet.setResolution(resolution);
                
                supportPoint = wSet.computeSupportPoint(testHyperplane.getNormalVector);
                
                if testHyperplane.isInPositiveHalfSpace(supportPoint)
                    
                    collisionGroupsInPositiveHalfSpace(n) = true;
                    
                    distance = testHyperplane.computeAbsDistanceToPoint(supportPoint);
                    
                    if distance > collisionGroupsMaxDistance(n)
                        
                        collisionGroupsMaxDistance(n) = distance;
                        
                    end
                    
                    
                end
                
            end
            
        end
        
        
        if any(collisionGroupsInPositiveHalfSpace) 
            
            % find next closest distinc hyperplane
            while(testHyperplane.isEquivalentHyperplane(wrenchSpace.getNextFacetHyperplane))
                
            end
            
            testHyperplane = wrenchSpace.getCurrentFacetHyperplane;
            
            remainingCollisionGroupsIndices = collisionGroupsIndices(collisionGroupsInPositiveHalfSpace);
            
            [maxDistance,selectedGroupIndex] = max(collisionGroupsMaxDistance);
            
            %fprintf('\nThere are %i collision groups , testing the next hyperplane\n',length(remainingCollisionGroupsIndices))
            %disp(remainingCollisionGroupsIndices)
            
            if length(remainingCollisionGroupsIndices) == 1 
                
                continueSearchingOptimumSet = false;
                break
                
            end
            
            if counter0 > 160
                
                continueSearchingOptimumSet = false;
                fprintf('\nreached %i iterations, ending iteration\n',counter0-1)
                break
                
            end
            
            
                
            
            % reseting tracking variables
            collisionGroupsMaxDistance = zeros(1,length(collisionGroupResult));
            collisionGroupsInPositiveHalfSpace = false(1,length(collisionGroupResult));
            
        else % there are no more collision groups that can increase the wrench space
            
            continueSearchingOptimumSet = false;
            
            if maxDistance == 0 % no collision group increases the wrench space
                
                
                selectedGroupIndex = 1;
                
            else
                
                selectedGroupIndex = selectedGroupIndex(1);
                
            end
            
        end
        
        counter0 = counter0 + 1;
        
    end
    
    
    % STEP 6 --------------------------------------------------------------
    fprintf('\nSTEP 6 ---------------------------------------------------\n')
    selectedWrenchSets = collisionGroupResult(selectedGroupIndex).createWrenchSet;
    
    CollisionGroupContainer(currentNumberOfFingersSearched+1) = collisionGroupResult(selectedGroupIndex);
    
    % adding wrench sets to wrench space
    for n = 1:length(selectedWrenchSets)
        
        fprintf('\nadding wrench set to wrench space\n')
        selectedWrenchSets(n).setResolution(resolution);
        wrenchSpace.addWrenchSet(selectedWrenchSets(n));
        
    end
    
    % updating finger obj
    jc = collisionGroupResult(selectedGroupIndex).createJointConfiguration;
    fingerObj.JointValues = jc.JointValues;
    fingerObj.updateAllFrames;
    
    for n = 1:length(fingerObj.Links);
        
        if isEnvironmentEmpty
            
            environment = Solid(fingerObj.Links(n));
            isEnvironmentEmpty = false;
            
        else
            
            environment = environment + fingerObj.Links(n);
            
        end
        
    end
    
    currentNumberOfFingersSearched = currentNumberOfFingersSearched + 1;
    
    
    if currentNumberOfFingersSearched == length(hand.Fingers)
        
        continueSearchingOptimumGrasp = false;
        
    else
        
        currentFingerIndex = indices(currentNumberOfFingersSearched + 1);
        
    end
    
end

% gathering results

if CollisionGroupContainer.length == 0
    
    collisionGroupResults = CollisionDetection.CollisionGroupResult;
    
else
    
    collisionGroupResults(length(CollisionGroupContainer)) = CollisionDetection.CollisionGroupResult;
    keys = CollisionGroupContainer.keys;
    for n = 1:length(CollisionGroupContainer);
        
        collisionGroupResults(n) = CollisionGroupContainer(keys{n});
        
        
    end
    
end

results.CollisionGroupResults = collisionGroupResults;
results.WrenchSpace = wrenchSpace;
results.SearchedIndices = indices(1:currentNumberOfFingersSearched);
results.Environment = environment;

end
