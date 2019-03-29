
%% declaring objects
f = Finger('Prototype1_Index_4DOF');
obj2 = Box([2 2 2]);



%% creating mex instance of each link and object
%f.setPhysicsHandle;
%obj.setPhysicsHandle;

%% initializing properties

f.BaseFrame = Algorithms.rotation('xy',[0 -pi/2]);
%f.BaseFrame = eye(4);

f.JointValues = zeros(size(f.JointValues));

% creating joint limits
jointLimits = zeros(f.DOF,2);
jointSteps = 10 * ones(f.DOF,1);

% setting joint limits
for n = 1: f.DOF;
    
    jointLimits(n,:) = [0 pi/2];
end

jointLimits(1,:) = [0,0];

%f.Links(end).JointLimits = [0 pi/2];

%obj.Frame = Algorithms.translation('xz',[3 3]);
obj2.Frame = Algorithms.translation('xyz',[3 0 3]);
% retrieving data

%% creating viewing window
figure(1)
axis([-8 8 -8 8 -6 10])
f';
obj2';
%%
index = 0;
options.Environment = [];
options.JointLimitValues = jointLimits;
options.JointSteps = jointSteps;
collisionResultGroups = CollisionDetection.ContinuousCollisionDetection.performCCDArticulatedBodyTest(f,obj2,options);

%%

if(index > length(collisionResultGroups) - 1)
    index = 0;
end
index = index + 1;
    
collisionPairResults = collisionResultGroups(index).CollisionPairResults;

noLinks = length(collisionPairResults);
% setting joints
for n = 1:noLinks;
    
    %resultStruct = testResult(n);
    f.Links(n).JointValues = collisionPairResults(n).TOC_JointValues;
    %f.Links(n).Frame = resultStruct.TOC_TransformA;
end

f.updateAllFrames;
f';

%%
%f.destroyPhysicsHandle;
%obj.destroyPhysicsHandle;