function [results,CollisionGroupContainer] = findForceClosureGrasp(hand,obj,varargin)
%[collisionGroupResults,wrenchSpace,searchedIndices] =
%                                   findForceClosureGrasp(hand,obj)
%[collisionGroupResults,wrenchSpace,searchedIndices] =
%                                   findForceClosureGrasp(hand,obj,options)
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
%

% optional input arguments
%   indices of fingers to use for the search of a Force-Closure grasp
%   environment object to use in the search of valid contact configurations
%
% optional output arguments
%   indices of fingers that contributed to the formation of the resulting
%       Force-Closure grasp.
%   Wrench Space object corresponding to the resulting Force-Closure grasp
%
% additional required parameters
%   Frinction Model
%   CombinedFriction
%   Resolution
%
% notes:
%   incorporate setFrictionModelMethod in wrench set object

% initializing variables
continueSearchingForceClosure = true;

currentNumberOfFingersSearched = 0;
%currentNumberOfPrimitiveWrenches = 0;
wrenchSpace = WrenchSpace.WrenchSpace;
frictionModel = 'PCF';
friction = 0.5;
resolution = 8;
numWrenchSpaceDimensions = 6;
CollisionGroupContainer = containers.Map(0,struct('field1',[],'field2',[]));
CollisionGroupContainer.remove(0);

% creating test hyperplane container
TestHyperplaneContainer = containers.Map(0,struct('field1',[],'field2',[]));
TestHyperplaneContainer.remove(0);

tolerance = 1e-10;

% creating contact point at origin to be used in step 6
warning off
contactPointInputStruct = struct(CollisionDetection.ContactPoint);
contactPointInputStruct.ContactPointOnB = zeros(3,1);
contactPointInputStruct.ContactNormalOnB = zeros(3,1);
contactPointInputStruct.FrictionModel = 'FPC';
originContactPoint = CollisionDetection.ContactPoint(contactPointInputStruct);
warning on
        
switch nargin
    
    case 2
        
        indices = 1:length(hand.Fingers);
        %usingEnvironment = false;
        autoGenerateJointLimits = true;        
        
    case 3
        
        options = varargin{1};        
        
        indices = options.SearchIndices;
        jointProfiles = options.JointProfiles;
        %usingEnvironment = false;
        autoGenerateJointLimits = false;
        
        % adding elements to wrench space
        if ~isempty(options.InitialContactPoints)
            
            if isa(options.InitialContactPoints,'CollisionDetection.ContactPoint')
                
                %initialWrenchSets = repmat(WrenchSpace.WrenchSet,1,length(options.InitialContactPoints));
                for n = 1:length(options.InitialContactPoints);
                    
                    initialWrenchSets = WrenchSpace.WrenchSet(options.InitialContactPoints(n));
                    initialWrenchSets.setResolution(resolution);
                    wrenchSpace.addWrenchSet(initialWrenchSets);
                    
                end
                
            else
                
                error('InitialWrenchSets field in the option input structure shoud contain WrenchSet objects')
                
            end
            
        end 
        
        if isfield(options,'Resolution')
            
            resolution  = options.Resolution;
            
        end
        
        if isfield(tolerance,'Tolerance')
            
            tolerance = options.Tolerance;
            
        end
        
    otherwise
        
        error('invalid number of input arguments')
        
end


%environment = Solid(hand.PalmObject);
isEnvironmentEmpty = true;
environment = [];
currentFingerIndex = indices(1);

% starting search
while continueSearchingForceClosure
    
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
    
    % generating collision group result objects
    fprintf('\nForceClosure Search Stage 1 - Calling CCD on %ith finger\n',currentFingerIndex)
    collisionGroupResult = CollisionDetection.ContinuousCollisionDetection.performCCDArticulatedBodyTest(...
        fingerObj,obj,ccdOptions);
    
   
    % if no valid collisions were found then advance to the next iteration
    if length(collisionGroupResult) == 1
        
        if collisionGroupResult.NumCollisionPairs == 0
            
            currentNumberOfFingersSearched = currentNumberOfFingersSearched + 1;
            
            fprintf('\nFound 0 collision groups for the %ith finger, moving to next iterations\n',currentFingerIndex)
            if currentNumberOfFingersSearched == length(hand.Fingers)

                continueSearchingForceClosure = false;

            else
                
                currentFingerIndex = indices(currentNumberOfFingersSearched + 1);
                
            end
            
            %fprintf('\nFound 0 collision groups for the %ith finger, moving to next iterations\n',currentFingerIndex)
            
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
    
    fprintf('\nFound %i collision groups for the %ith finger\n',length(collisionGroupResult),currentFingerIndex)
    
    numPrimitiveWrenches = zeros(1,length(collisionGroupResult));
    
    % obtaining collision group result object that yields the most
    % primitive wrenches.
    for n = 1:length(collisionGroupResult);
        
        % retrieving candidate wrench sets
        %candidateWrenchSets(n) =
        %{collisionGroupResult(n).createWrenchSet};
        numPrimitiveWrenches(n) = (collisionGroupResult(n).getNumContactPoints)*...
            sum(resolution);
        
    end
    
    [maxNumWrenches,selectedWrenchGroupIndex] = max(numPrimitiveWrenches);
    
    selectedWrenchGroupIndex = selectedWrenchGroupIndex(1);
    
    % retrieving selected wrench sets
    selectedWrenchSets = collisionGroupResult(selectedWrenchGroupIndex).createWrenchSet;
    
    % if there are less than n points then continue gathering wrench sets
%     currentNumberOfPrimitiveWrenches = maxNumWrenches+currentNumberOfPrimitiveWrenches;
    
    % storing selected collision group result object
    CollisionGroupContainer(currentNumberOfFingersSearched+1) = collisionGroupResult(selectedWrenchGroupIndex);
    
    currentNumberOfFingersSearched = currentNumberOfFingersSearched + 1;
    currentFingerIndex = indices(currentNumberOfFingersSearched + 1);
    
    if currentNumberOfFingersSearched == length(hand.Fingers)
        
        continueSearchingForceClosure = false;
        
    end
    
    % adding wrench sets to wrench space
    for n = 1:length(selectedWrenchSets)
        
        fprintf('\nadding wrench set to wrench space\n')
        selectedWrenchSets(n).setResolution(resolution);
        wrenchSpace.addWrenchSet(selectedWrenchSets(n));
        
    end
    
    
    % checking if a proper convex hull can be formed
    if ~wrenchSpace.isProperNPolytope        

        % adding objects to the environment
        jc = collisionGroupResult(selectedWrenchGroupIndex).createJointConfiguration;
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
        
        continue;
        
    else    
        
        %currentNumberOfFingersSearched = currentNumberOfFingersSearched + 1;
        %currentFingerIndex = indices(currentNumberOfFingersSearched + 1);
        if wrenchSpace.isForceClosure;
            
            continueSearchingForceClosure = false;
            
            jc = collisionGroupResult(selectedWrenchGroupIndex).createJointConfiguration;
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
            
        else
            
            % adding objects to the environment
            jc = collisionGroupResult(selectedWrenchGroupIndex).createJointConfiguration;
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
            
        end
        
        break
        
    end
    
end


% second stage of force closure search, steps 6 - 10

while continueSearchingForceClosure
        
        % STEP 6 -------------------------------------------------------------
        
        % STEP 6 - b     
        tempWrenchSets = [WrenchSpace.WrenchSet(originContactPoint)...
            ,wrenchSpace.getWrenchSets];
        
        % creating temporary wrench space
        tempWrenchSpace = WrenchSpace.WrenchSpace;
        
        % adding all wrench sets to temporary wrench space 
        for n = 1:length(tempWrenchSets);
            
            tempWrenchSpace.addWrenchSet(tempWrenchSets(n));
            
        end
        
        % extrating all planes that contain the origin (offset = 0)
        offsets = tempWrenchSpace.getOffsets;
        hyperplaneNormals = tempWrenchSpace.getNormals;        
        
        % finding all elements in offset = 0 -+ tolerance
        originIndices = (offsets > -tolerance) & (offsets < tolerance);
        
        fprintf('\nNumber of hyperplanes that pass through the origin : %i\n',length(find(originIndices)))
        
        % normal vector of all hyperplanes that contain the origin
        hyperplaneNormals = hyperplaneNormals(originIndices,:);
        numTestHyperplanes = size(hyperplaneNormals,1);
        
        % creating first test hyperplane
        currentHyperplane = Geometry.Hyperplane(hyperplaneNormals(1,:)',0);
        currentHyperplane.setTolerance(tolerance);
        testHyperplaneCounter = 1;
        
        % creating container that holds all test hyperplane
        TestHyperplaneContainer(testHyperplaneCounter) = currentHyperplane;
        
        % creating hyperplanes that pass through the origin
        for n = 2:numTestHyperplanes;
            
            testHyperplane = Geometry.Hyperplane(hyperplaneNormals(n,:)',0);
            
            if ~currentHyperplane.isEquivalentHyperplane(testHyperplane)
                
                testHyperplaneCounter = testHyperplaneCounter + 1;
                TestHyperplaneContainer(testHyperplaneCounter) =  testHyperplane;
                testHyperplane.setTolerance(tolerance);
                currentHyperplane = testHyperplane;
                
            end
            
        end
 
    %STEP 7 ---------------------------------------------------------------
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
    
    % generating collision group result objects
    fprintf('ForceClosure Search Stage 2 - Calling CCD on %ith finger\n',currentFingerIndex)
    collisionGroupResult = CollisionDetection.ContinuousCollisionDetection.performCCDArticulatedBodyTest(...
        fingerObj,obj,ccdOptions);

    % if no valid collisions were found then advance to the next iteration
    if length(collisionGroupResult) == 1
        
        if collisionGroupResult.NumCollisionPairs == 0
            
            currentNumberOfFingersSearched = currentNumberOfFingersSearched + 1;
            
            
            if currentNumberOfFingersSearched == length(hand.Fingers)

                continueSearchingForceClosure = false;

            else
                
                currentFingerIndex = indices(currentNumberOfFingersSearched + 1);
                
            end
            
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
    
    fprintf('\nFound %i collision groups for the %ith finger\n',length(collisionGroupResult),currentFingerIndex)
    % STEP 8 --------------------------------------------------------------
    selectedCollisionGroup = true(1,length(collisionGroupResult));
    
    % testing wrench sets to determine if they contain a point in all
    % hyperplanes
    isInPositiveHalfSpace = false(1,testHyperplaneCounter);
    for n = 1:length(collisionGroupResult)
        
        wrenchSets = collisionGroupResult(n).createWrenchSet;
        
        for m = 1:length(wrenchSets);
            
            wSet = wrenchSets(m);
            wSet.setResolution(resolution);
            
            
            for p = 1:testHyperplaneCounter;
                
                hPlane = TestHyperplaneContainer(p);
                supportPoint = wSet.computeSupportPoint(hPlane.getNormalVector);
                
                if hPlane.isInPositiveHalfSpace(supportPoint)
                    
                    isInPositiveHalfSpace(p) = true;
                    
                end
                
            end
            
            % test with these lines of code
            if all(isInPositiveHalfSpace)
                
                % current wrench set is in intersection sector of all
                % positive half-spaces of the test hyperplanes 
                break;
                
            else
                
                % reset
                isInPositiveHalfSpace = false(1,testHyperplaneCounter);
                
            end
            
        end
        
        selectedCollisionGroup(n) = all(isInPositiveHalfSpace);
        
        % if at least one configuration is found to produce a FC wrench
        % space then break the loop
        if selectedCollisionGroup(n)
            
            selectedGroupIndex = find(selectedCollisionGroup);
            selectedGroupIndex = selectedGroupIndex(1);
            break
            
        end
        
    end
    
    % removing all elements from TestHyperplane Container
    TestHyperplaneContainer.remove(TestHyperplaneContainer.keys);
    
    % STEP 9 --------------------------------------------------------------
    if any(selectedCollisionGroup)
        
        % should implement all three cases presented in step 9
        fprintf('\nForce closure found\n')
        % the grasp is FC the the loop should stop
        continueSearchingForceClosure = false;
        %CollisionGroupContainer(currentNumberOfFingersSearched) = collisionGroupResult(selectedCollisionGroup(1));
        
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
        
    else
        
        % find the one with the most elements
        numPrimitiveWrenches = zeros(1,length(collisionGroupResult));
        
        % obtaining collision group result object that yields the most
        % primitive wrenches.
        for n = 1:length(collisionGroupResult);
            
            % retrieving candidate wrench sets
            numPrimitiveWrenches(n) = (collisionGroupResult(n).getNumContactPoints)*...
                resolution;
            
        end
        
        [maxNumWrenches,selectedWrenchGroupIndex] = max(numPrimitiveWrenches);
        
        selectedWrenchGroupIndex = selectedWrenchGroupIndex(1);
        
        % retrieving selected wrench sets
        selectedWrenchSets = collisionGroupResult(selectedWrenchGroupIndex).createWrenchSet;
        
        CollisionGroupContainer(currentNumberOfFingersSearched+1) = collisionGroupResult(selectedWrenchGroupIndex);
        
        % adding wrench sets to wrench space
        for n = 1:length(selectedWrenchSets)
            
            fprintf('\nadding wrench set to wrench space\n')
            selectedWrenchSets(n).setResolution(resolution);
            wrenchSpace.addWrenchSet(selectedWrenchSets(n));
            
        end
        
        % adding objects to the environment
        jc = collisionGroupResult(selectedWrenchGroupIndex).createJointConfiguration;
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
        
    end
    
    % STEP 10 -------------------------------------------------------------
    
    currentNumberOfFingersSearched = currentNumberOfFingersSearched + 1;
    
    
    if currentNumberOfFingersSearched == length(hand.Fingers)
        
        continueSearchingForceClosure = false;
        
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

searchedIndices = indices(1:currentNumberOfFingersSearched);

results.CollisionGroupResults = collisionGroupResults;
results.WrenchSpace = wrenchSpace;
results.SearchedIndices = searchedIndices;
results.Environment = environment;


end












