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
%   InitialWrenchSets: 1 x w WrenchSet array where all of the elements in
%                   this array are used to initialize the wrench space.
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
% creating hand and object
hand = Hand('Prototype1');
obj = Sphere(4);

%%
hand.Frame = Geometry.translation('z',4);
obj.Frame = Geometry.translation('zx',[-1 8]);
hand';
obj';

%% using ccd to find contact pose between the palm and object
palm = Solid(hand.PalmObject);
palmStartTransform = palm.Frame;
palmEndTransform = Geometry.translation('z',-10);
%palm.setPhysicsHandle;
%obj.setPhysicsHandle;


ccd = CollisionDetection.ContinuousCollisionDetection;
%ccd.createMexInstance;
ccd.setObjectA(palm,eye(4));
ccd.setObjectB(obj,eye(4));
%%
pairResult = ccd.performCCDPairTest(palmStartTransform,palmEndTransform,...
    obj.Frame,obj.Frame);

disp(pairResult)

%palm.destroyPhysicsHandle

%% placing hand at contact pose
hand.Frame = pairResult.TOC_TransformA;
hand';
obj';


%% creating joint profiles
numSteps = 4;
numFingers = length(hand.Fingers);
jointProfiles(numFingers) = MotionProfile.JointProfile;

searchIndices = [1 5 2 4 3];

for n = searchIndices
    
    jc1 = MotionProfile.JointConfiguration(hand.Fingers(n));
    jc2 = MotionProfile.JointConfiguration(hand.Fingers(n));
    
    jc1.setJointValues(zeros(hand.Fingers(n).DOF,1));
    jc2.setJointValues([0 pi/2 repmat(pi/2,1,hand.Fingers(n).DOF-2)]);
    
    jointProfiles(n) = MotionProfile.JointProfile(jc1,jc2);
    jointProfiles(n).setNumSteps(numSteps);
    
end
%%
options.JointProfiles = jointProfiles;
options.SearchIndices = searchIndices;
options.InitialWrenchSets = [];
%options.InitialWrenchSets = pairResult.createWrenchSet;


%% initializing variables
continueSearchingForceClosure = true;

currentNumberOfFingersSearched = 0;
currentNumberOfPrimitiveWrenches = 0;
wrenchSpace = WrenchSpace.WrenchSpace;
frictionModel = 'PCF';
friction = 0.5;
resolution = 8;
numWrenchSpaceDimensions = 6;
CollisionGroupContainer = containers.Map(0,struct('field1',[],'field2',[]));
CollisionGroupContainer.remove(0);


        
%% parsing input data

indices = options.SearchIndices;
jointProfiles = options.JointProfiles;
%usingEnvironment = false;
autoGenerateJointLimits = false;

% adding elements to wrench space
if ~isempty(options.InitialWrenchSets)
    
    if isa(options.InitialWrenchSets,'WrenchSpace.WrenchSet')
        
        initialWrenchSets = options.InitialWrenchSets;
        for n = 1:length(initialWrenchSets);
            
            wrenchSpace.addWrenchSet(initialWrenchSets(n));
            
        end
        
    else
        
        error('InitialWrenchSets field in the option input structure shoud contain WrenchSet objects')
        
    end
    
end

%%

%hand.setPhysicsHandle;
%obj.setPhysicsHandle;

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
    
    % creating physics handle
    if ~isEnvironmentEmpty
        
        %environment.setPhysicsHandle;
        
    end
    %ccdOptions.Environment = [];
    ccdOptions.Environment = environment;
    ccdOptions.JointLimitValues = jointLimits;
    ccdOptions.JointSteps = jointSteps;
    
    disp(jointLimits)
    disp(jointSteps)
    % generating collision group result objects
    fprintf('\nForceClosure Search Stage 1 - Calling CCD on %ith finger\n',currentFingerIndex)
    collisionGroupResult = CollisionDetection.ContinuousCollisionDetection.performCCDArticulatedBodyTest(...
        fingerObj,obj,ccdOptions);
    
    % destroying physics handle
    if ~isEnvironmentEmpty
        
        %environment.destroyPhysicsHandle;
        
    end
    
    
    % if no valid collisions were found then advance to the next iteration
    if length(collisionGroupResult) == 1
        
        if collisionGroupResult.NumCollisionPairs == 0
            
            currentNumberOfFingersSearched = currentNumberOfFingersSearched + 1;
            
            
            if currentNumberOfFingersSearched == length(hand.Fingers)

                continueSearchingForceClosure = false;

            else
                
                currentFingerIndex = indices(currentNumberOfFingersSearched + 1);
                
            end
            
            fprintf('\n-----------------------------------------\n')
            fprintf('Found 0 collision groups for the %ith finger\n',currentFingerIndex)
            fprintf('-----------------------------------------\n')
            
            continue
            
        end
        
    end
    
    fprintf('\n-----------------------------------------\n')
    fprintf('Found %i collision groups for the %ith finger\n',length(collisionGroupResult),currentFingerIndex)
    fprintf('-----------------------------------------\n')
    
    numPrimitiveWrenches = zeros(1,length(collisionGroupResult));
    
    % obtaining collision group result object that yields the most
    % primitive wrenches.
    for n = 1:length(collisionGroupResult);
        % retrieving candidate wrench sets
        %candidateWrenchSets(n) = {collisionGroupResult(n).createWrenchSet};
        numPrimitiveWrenches(n) = (collisionGroupResult(n).getNumContactPoints)*...
            resolution;
        
    end
    
    [maxNumWrenches,selectedWrenchGroupIndex] = max(numPrimitiveWrenches);
    
    selectedWrenchGroupIndex = selectedWrenchGroupIndex(1);
    
    % retrieving selected wrench sets
    selectedWrenchSets = collisionGroupResult(selectedWrenchGroupIndex).createWrenchSet;
    
    for n = 1:length(selectedWrenchSets);
        
        selectedWrenchSets(n).setResolution(resolution);
        selectedWrenchSets(n).setFrictionCoefficients(friction);
        
    end
    % set contact model
    
    
    % if there are less than n points then continue gathering wrench sets
    currentNumberOfPrimitiveWrenches = maxNumWrenches+currentNumberOfPrimitiveWrenches;
    
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

% testing for force closure

while continueSearchingForceClosure
    
%     if wrenchSpace.isForceClosure;
%         
%         % return output data
%         break;
%         
%     else
        
        % STEP 6 -------------------------------------------------------------
        fprintf('\nSTEP 6 ---------------------------------------------------\n')
        %     % extracting primitive wrenches
        %     W = wrenchSpace.getPrimitiveWrenches;
        %
        %     % using GJK to obtain closests point and plane
        %     [pk,d,Ak] = Geometry.GJKOrigin2Set(W,1e-4);
        %
        %     % determining if a normal vector and its corresponding plane can be
        %     % computed
        %     nPoints = size(Ak,2);
        %
        %     nCombinations = prod(nPoints-1:nPoints)/prod(1:2);
        %     nVectors = numWrenchSpaceDimensions - 1;
        
        %     if(nCombinations >= nVectors)
        %
        %         % STEP 6 - a
        %         % remark:  consider eliminating this alternative since it could
        %         % lead to erroneous FC grasps
        %         [normalVec, manifold] = Geometry.normal(Ak);
        %
        %         % hyperplane that passes through the origin and parallel to the
        %         % closest hyperplane in the wrench space
        %         testHyperplanes = Geometry.Hyperplane(normalVec,0);
        %
        %     else
        
        % STEP 6 - b
        % creating contact point at origin
        contactPointInputStruct = struct(CollisionDetection.ContactPoint);
        contactPointInputStruct.ContactPointOnB = zeros(3,1);
        contactPointInputStruct.ContactNormalOnB = zeros(3,1);
        contactPointInputStruct.FrictionModel = 'FPC';
        originContactPoint = CollisionDetection.ContactPoint(contactPointInputStruct);
        %originContactPoint.ContactPointOnB = zeros(3,1);
        %originContactPoint.FrictionModel = 'FPC';
        
        tempWrenchSets = [WrenchSpace.WrenchSet(originContactPoint)...
            ,wrenchSpace.getWrenchSets];
        
        % creating temporary wrench space
        tempWrenchSpace = WrenchSpace.WrenchSpace;
        
        % adding all wrench sets
        for n = 1:length(tempWrenchSets);
            
            tempWrenchSpace.addWrenchSet(tempWrenchSets(n));
            
        end
        
        % extrating all planes that contain the origin (offset = 0)
        offsets = tempWrenchSpace.getOffsets;
        normalVectors = tempWrenchSpace.getNormals;
        tolerance = 1e-4;
        
        originIndices = (offsets > -tolerance) & (offsets < tolerance);
        
        hyperplaneNormals = normalVectors(originIndices,:);
        numTestHyperplanes = size(hyperplaneNormals,1);
        
        %testHyperplanes(numTestHyperplanes) = Geometry.Hyperplane;
        %testHyperplanes = repmat(Geometry.Hyperplane,1,numTestHyperplanes);
        % creating hyperplanes that pass through the origin
        
        currentHyperplane = Geometry.Hyperplane(hyperplaneNormals(1,:)',0);
        testHyperplaneCounter = 1;
        
        TestHyperplaneContainer = containers.Map(testHyperplaneCounter,currentHyperplane);
        
        for n = 2:numTestHyperplanes;
            
            testHyperplane = Geometry.Hyperplane(hyperplaneNormals(n,:)',0);
            testHyperplane.setTolerance(tolerance);
            
            if ~currentHyperplane.isEquivalentHyperplane(testHyperplane)
                
                testHyperplaneCounter = testHyperplaneCounter + 1;
                TestHyperplaneContainer(testHyperplaneCounter) =  testHyperplane;
                currentHyperplane = testHyperplane;
                
            end
                
                
            
        end
        
%     end
    
    %STEP 7 ---------------------------------------------------------------
    fprintf('\nSTEP 7 ---------------------------------------------------\n')
    fingerObj = hand.Fingers(currentFingerIndex);
    
    if autoGenerateJointLimits
        
        jointLimits = fingerObj.JointLimits;
        jointSteps = 10*ones(fingerObj.DOF,1);
        
    else
        
        jointConf= jointProfiles(currentFingerIndex).JointConfigurations;
        jointLimits = [jointConf(1).JointValues jointConf(2).JointValues];
        jointSteps = repmat(jointProfiles(currentFingerIndex).NumSteps,fingerObj.DOF,1);
        
    end
    
    % setting environment physics handle
    if ~isEnvironmentEmpty
        
        %environment.setPhysicsHandle;
    
    end
    
    %ccdOptions.Environment = [];
    ccdOptions.Environment = environment;
    ccdOptions.JointLimitValues = jointLimits;
    ccdOptions.JointSteps = jointSteps;
    
    fprintf('\n ccd input data\n')
    disp(jointLimits)
    disp(jointSteps)
    % generating collision group result objects
    fprintf('\nForceClosure Search Stage 2 - Calling CCD on %ith finger\n',currentFingerIndex)
    collisionGroupResult = CollisionDetection.ContinuousCollisionDetection.performCCDArticulatedBodyTest(...
        fingerObj,obj,ccdOptions);
    
    % destroying environment physics handle
    
    if ~isEnvironmentEmpty
        
        %environment.destroyPhysicsHandle;
        
    end
    
    % if no valid collisions were found then advance to the next iteration
    if length(collisionGroupResult) == 1
        
        if collisionGroupResult.NumCollisionPairs == 0
            
            currentNumberOfFingersSearched = currentNumberOfFingersSearched + 1;
            
            
            if currentNumberOfFingersSearched == length(hand.Fingers)

                continueSearchingForceClosure = false;

            else
                
                
                currentFingerIndex = indices(currentNumberOfFingersSearched + 1);
                
            end
            
            continue
            
        end
        
    end
    
    
    % STEP 8 --------------------------------------------------------------
    fprintf('\nSTEP 8 ---------------------------------------------------\n')
    selectedCollisionGroup = true(1,length(collisionGroupResult));
    
    % testing wrench sets to determine if they contain a point in all
    % hyperplanes
    isInPositiveHalfSpace = false(1,testHyperplaneCounter);
    for n = 1:length(collisionGroupResult)
        
        wrenchSets = collisionGroupResult(n).createWrenchSet;
        
        for m = 1:length(wrenchSets);
            
            wSet = wrenchSets(m);
            
            
            for p = 1:testHyperplaneCounter;
                
                hPlane = TestHyperplaneContainer(p);
                supportPoint = wSet.computeSupportPoint(hPlane.getNormalVector);
                
                if hPlane.isInPositiveHalfSpace(supportPoint)
                    
                    isInPositiveHalfSpace(p) = true;
                    
                end
                
            end
            
        end
        
        selectedCollisionGroup(n) = all(isInPositiveHalfSpace);
        
    end
    
    %clear testHyperplanes    
    
    % STEP 9 --------------------------------------------------------------
    fprintf('\nSTEP 9 ---------------------------------------------------\n')
    if any(selectedCollisionGroup)
        
        % should implement all three cases presented in step 9
        
        % the grasp is FC the the loop should stop
        continueSearchingForceClosure = false;
        CollisionGroupContainer(currentNumberOfFingersSearched) = collisionGroupResult(selectedCollisionGroup(1));
        
        selectedWrenchSets = collisionGroupResult(selectedCollisionGroup(1)).createWrenchSet;
        
        CollisionGroupContainer(currentNumberOfFingersSearched+1) = collisionGroupResult(selectedCollisionGroup(1));
        
        % adding wrench sets to wrench space
        for n = 1:length(selectedWrenchSets)
            
            fprintf('\nadding wrench set to wrench space\n')
            wrenchSpace.addWrenchSet(selectedWrenchSets(n));
            
        end
        
        % updating finger obj
        jc = collisionGroupResult(selectedCollisionGroup(1)).createJointConfiguration;
        fingerObj.JointValues = jc.JointValues;
        fingerObj.updateAllFrames;
        
        
    else
        
        % find the one with the most elements
        numPrimitiveWrenches = zeros(1,length(collisionGroupResult));
        
        % obtaining collision group result object that yields the most
        % primitive wrenches.
        for n = 1:length(collisionGroupResult);
            % retrieving candidate wrench sets
            %candidateWrenchSets(n) = {collisionGroupResult(n).createWrenchSet};
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
    fprintf('\nSTEP 10 --------------------------------------------------\n')
    currentNumberOfFingersSearched = currentNumberOfFingersSearched + 1;
    currentFingerIndex = indices(currentNumberOfFingersSearched + 1);
    
    if currentNumberOfFingersSearched == length(hand.Fingers)
        
        continueSearchingForceClosure = false;
        
    end
    
end

% gathering results

disp(CollisionGroupContainer.keys)
if CollisionGroupContainer.length == 0
    
    collisionGroupResults = CollisionDetection.CollisionGroupResult;
    
else
   
    collisionGroupResults(length(CollisionGroupContainer)) = CollisionDetection.CollisionGroupResult;
    for n = 1:length(CollisionGroupContainer);
        
        collisionGroupResults(n) = CollisionGroupContainer(n);
        
        
    end
    
end

searchedIndices = indices(1:currentNumberOfFingersSearched);















