%% creating hand and object
hand = Hand('RowdyHand');

%% create sphere
obj = Sphere(4);

%%
objectTransform = Geometry.translation('zxy',[0 0 0]);
objectColor = [1 1 0];
palmStartTransform = Geometry.translation('zyx',[8 2 -8])*Geometry.rotation('x',0);
palmEndTransform = palmStartTransform*Geometry.translation('z',-10);
testNo = 1;

%%
figure(2);
axis(20*[-1 1 -1 1 -1 1]);
%hand.Color = 'y';
hand.Frame = palmStartTransform;
hand.PalmObject.Color = [1 1 1];
obj.Frame = objectTransform;
obj.Color = objectColor;
hand';
obj';

%% using ccd to find contact pose between the palm and object
palm = Solid(hand.PalmObject);
%palmStartTransform = palm.Frame;
%palmEndTransform = Geometry.translation('z',-10);
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

searchIndices = [4 2 3 1];

% for n = searchIndices
%     
%     jc1 = MotionProfile.JointConfiguration(hand.Fingers(n));
%     jc2 = MotionProfile.JointConfiguration(hand.Fingers(n));
%     
%     jc1.setJointValues([0 -pi/10 0 0]);
%     jc2.setJointValues([pi/2 pi/10 pi/3 pi/2]);
%     
%     jointProfiles(n) = MotionProfile.JointProfile(jc1,jc2);
%     jointProfiles(n).setNumSteps(numSteps);
%     
% end

% creating 1st finger joint profile
jc1 = MotionProfile.JointConfiguration(hand.Fingers(1));
jc2 = MotionProfile.JointConfiguration(hand.Fingers(1));

jc1.setJointValues([0 0 0 0]);
jc2.setJointValues([pi/2 -pi/8 pi/2 pi/2]);

jointProfiles(1) = MotionProfile.JointProfile(jc1,jc2);
jointProfiles(1).setNumSteps(numSteps);

% creating 2nd finger joint profile
jc1 = MotionProfile.JointConfiguration(hand.Fingers(2));
jc2 = MotionProfile.JointConfiguration(hand.Fingers(2));

jc1.setJointValues([0 0 0 0]);
jc2.setJointValues([pi/2 0 pi/2 pi/2]);

jointProfiles(2) = MotionProfile.JointProfile(jc1,jc2);
jointProfiles(2).setNumSteps(numSteps);

% creating 3rd finger joint profile
jc1 = MotionProfile.JointConfiguration(hand.Fingers(3));
jc2 = MotionProfile.JointConfiguration(hand.Fingers(3));

jc1.setJointValues([0 0 0 0]);
jc2.setJointValues([pi/2 pi/10 pi/2 pi/2]);

jointProfiles(3) = MotionProfile.JointProfile(jc1,jc2);
jointProfiles(3).setNumSteps(numSteps);

% creating thumb joint profile
jc1 = MotionProfile.JointConfiguration(hand.Fingers(4));
jc2 = MotionProfile.JointConfiguration(hand.Fingers(4));

jc1.setJointValues([0 -pi/10 0 0]);
jc2.setJointValues([-pi/10 pi/2 pi/2 pi/2]);
jointProfiles(4) = MotionProfile.JointProfile(jc1,jc2);
jointProfiles(4).setNumSteps(numSteps);


%%
options.JointProfiles = jointProfiles;
options.SearchIndices = searchIndices;
%options.InitialContactPoints = [];
options.InitialContactPoints = pairResult.ContactPoints;

tic; 
fcResults = Grasp.findForceClosureGrasp(hand,obj,options);
fcTime = toc;

%%
for n = 1:length(fcResults.CollisionGroupResults);
    jConf = fcResults.CollisionGroupResults(n).createJointConfiguration;
    hand.Fingers(fcResults.SearchedIndices(n)).JointValues = jConf.JointValues;
end
hand';
%% creating excel data
excelData = {'Object','Triangles','SearchOrder','Q_FC','t_FC','N_FC'};

%% adding data to cell array for excel doc
excelData(1 + testNo,:) = {obj.ModelName,size(obj.Faces,1),['[' num2str(searchIndices) ']'],...
    fcResults.WrenchSpace.getQuality,fcTime,length(fcResults.SearchedIndices)};
%% writing to excel
xlswrite('GraspSynthesis_Experiment_Results',excelData,'RowdyHand_FCTest','A1')
    


