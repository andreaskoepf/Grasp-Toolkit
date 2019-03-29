% creating hand and object
hand2 = Hand('Prototype1');
obj2 = Box([4 20 4]);

%%
figure(2);
hand2.Frame = Geometry.translation('z',4);
obj2.Frame = Geometry.translation('zx',[-2 8]);
hand2.Color = 'y';
hand2';
obj2';

%% using ccd to find contact pose between the palm and object
palm = Solid(hand2.PalmObject);
palmStartTransform = palm.Frame;
palmEndTransform = Geometry.translation('z',-10);
%palm.setPhysicsHandle;
%obj.setPhysicsHandle;


ccd = CollisionDetection.ContinuousCollisionDetection;
%ccd.createMexInstance;
ccd.setObjectA(palm,eye(4));
ccd.setObjectB(obj2,eye(4));
%%
pairResult = ccd.performCCDPairTest(palmStartTransform,palmEndTransform,...
    obj2.Frame,obj2.Frame);

disp(pairResult)

%palm.destroyPhysicsHandle

%% placing hand at contact pose
hand2.Frame = pairResult.TOC_TransformA;
hand2';
obj2';

%% zeroing out all joints
for n = 1:length(hand2.Fingers)
    
    hand2.Fingers(n).JointValues = zeros(1,hand2.Fingers(n).DOF);
   
end

hand2';

%% creating joint profiles
numSteps = 4;
numFingers = length(hand2.Fingers);
jointProfiles(numFingers) = MotionProfile.JointProfile;

searchIndices = [1 5 2 4 3];

for n = searchIndices
    
    jc1 = MotionProfile.JointConfiguration(hand2.Fingers(n));
    jc2 = MotionProfile.JointConfiguration(hand2.Fingers(n));
    
    jc1.setJointValues(zeros(hand2.Fingers(n).DOF,1));
    jc2.setJointValues([0 pi/2 repmat(pi/2,1,hand2.Fingers(n).DOF-2)]);
    
    jointProfiles(n) = MotionProfile.JointProfile(jc1,jc2);
    jointProfiles(n).setNumSteps(numSteps);
    
end
%%
options.JointProfiles = jointProfiles;
options.SearchIndices = searchIndices;
%options.InitialContactPoints = [];
options.InitialContactPoints = pairResult.ContactPoints;

results = Grasp.findForceClosureGrasp(hand2,obj2,options);

%% destroying physics handle
%hand.destroyPhysicsHandle;
%obj.destroyPhysicsHandle;