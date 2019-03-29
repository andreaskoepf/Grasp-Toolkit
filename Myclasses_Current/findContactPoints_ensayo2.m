
%% declaring objects
f = Finger('Prototype1_Index_3DOF');
obj = Sphere(2);

%% creating mex instance of each link and object
f.setPhysicsHandle;
obj.setPhysicsHandle;

%% initializing properties

f.BaseFrame = Algorithms.rotation('xz',[-pi/2 -pi/2]);
%f.BaseFrame = eye(4);

f.JointValues = zeros(size(f.JointValues));

% setting joint limits
for n = 1: size(f.Links,2)
    jsize = size(f.Links(n).JointLimits,1);
    f.Links(n).JointLimits = repmat([-pi/3 pi/3],jsize,1);
end

f.Links(end).JointLimits = [0 pi/2];

%obj.Frame = Algorithms.translation('xz',[3 3]);
obj.Frame = Algorithms.translation('xyz',[4 0 3]);
% retrieving data



%%
index = 0;
resultContainer = findFingerTOCPosture(f,obj);

%%

if(index > double(resultContainer.Count) - 1)
    index = 0;
end
index = index + 1;
    
testResult = resultContainer(int32(index));

noLinks = double(testResult.Count);
% setting joints
for n = 1:noLinks;
    
    resultStruct = testResult(n);
    f.Links(n).JointValues = resultStruct.TOC_JointValues;
    %f.Links(n).Frame = resultStruct.TOC_TransformA;
end

f.updateAllFrames;
f';

%%
f.destroyPhysicsHandle;
obj.destroyPhysicsHandle;