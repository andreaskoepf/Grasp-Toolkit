% creating hand and object
hand = Hand('Prototype1');
obj = Sphere(4);

%%
figure(2);
hand.Color = 'y';
hand.Frame = Geometry.translation('z',4);
obj.Frame = Geometry.translation('zx',[-2 8]);
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

%% zeroing out all joints
for n = 1:length(hand.Fingers)
    
    hand.Fingers(n).JointValues = zeros(1,hand.Fingers(n).DOF);
   
end

hand';

%% creating joint profiles
numSteps = 4;
numFingers = length(hand.Fingers);
jointProfiles(numFingers) = MotionProfile.JointProfile;

searchIndices = [1 2 5 3 4];

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
%options.InitialContactPoints = [];
options.InitialContactPoints = pairResult.ContactPoints;

results = Grasp.findOptimumGrasp(hand,obj,options);