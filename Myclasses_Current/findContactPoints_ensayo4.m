
%% declaring objects
f = Finger('Prototype1_Index_4DOF');
obj = Box([2 2 2]);

%% creating mex instance of each link and object
%f.setPhysicsHandle;
%obj.setPhysicsHandle;

%% initializing properties

f.BaseFrame = Algorithms.translation('y',-2)*Algorithms.rotation('xy',[0 -pi/2]);
%f.BaseFrame = eye(4);

f.JointValues = zeros(size(f.JointValues));

% setting joint limits
for n = 1: size(f.Links,2)
    jsize = size(f.Links(n).JointLimits,1);
    f.Links(n).JointLimits = repmat([0 pi/3],jsize,1);
end

f.Links(1).JointLimits = [0 0;0 pi/3];

%obj.Frame = Algorithms.translation('xz',[3 3]);
obj.Frame = Algorithms.translation('xyz',[3 -2 3]);
% retrieving data
%%
f';
obj'

%%
index = 0;
f.JointValues = zeros(1,f.DOF);
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