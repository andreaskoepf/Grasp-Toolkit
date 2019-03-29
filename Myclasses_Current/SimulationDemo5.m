%% creating hand and object
hand = Hand('RowdyHand');


%% create rook
obj = Box(2*[3 16 4]);
%obj.scale(1.5);
%%
objectTransform = Geometry.translation('zxy',[0 0 0])*Geometry.rotation('x',0);
objectColor = [0.6 0.6 0.6];
palmStartTransform = Geometry.translation('zyx',[8 2 -5])*Geometry.rotation('yz',[0 0]);
palmEndTransform = palmStartTransform*Geometry.translation('z',-10);
testNo = 2;

%%
figure(2);
axis(40*[-1 1 -1 1 -1 1]);
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

searchIndices = [1 4 2 3];

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

jc1.setJointValues([0 -pi/20 0 0]);
jc2.setJointValues([pi/2.5 -pi/20 pi/2.5 pi/2]);

jointProfiles(1) = MotionProfile.JointProfile(jc1,jc2);
jointProfiles(1).setNumSteps(numSteps);

% creating 2nd finger joint profile
jc1 = MotionProfile.JointConfiguration(hand.Fingers(2));
jc2 = MotionProfile.JointConfiguration(hand.Fingers(2));

jc1.setJointValues([0 0 0 0]);
jc2.setJointValues([pi/2 0 pi/2 pi/4]);

jointProfiles(2) = MotionProfile.JointProfile(jc1,jc2);
jointProfiles(2).setNumSteps(numSteps);

% creating 3rd finger joint profile
jc1 = MotionProfile.JointConfiguration(hand.Fingers(3));
jc2 = MotionProfile.JointConfiguration(hand.Fingers(3));

jc1.setJointValues([0 0 0 0]);
jc2.setJointValues([pi/2 pi/20 pi/2 pi/4]);

jointProfiles(3) = MotionProfile.JointProfile(jc1,jc2);
jointProfiles(3).setNumSteps(numSteps);

% creating thumb joint profile
jc1 = MotionProfile.JointConfiguration(hand.Fingers(4));
jc2 = MotionProfile.JointConfiguration(hand.Fingers(4));

jc1.setJointValues([-pi/10 -pi/8 0 0]);
jc2.setJointValues([-pi/10 0 pi/2 pi/6]);
jointProfiles(4) = MotionProfile.JointProfile(jc1,jc2);
jointProfiles(4).setNumSteps(numSteps);

%%
options.JointProfiles = jointProfiles;
options.SearchIndices = searchIndices;
options.InitialContactPoints = [];
%options.resolution = 8;
options.InitialContactPoints = pairResult.ContactPoints;
tic;
giResults = Grasp.findOptimumGrasp(hand,obj,options);
giTime = toc;

%%
for n = 1:length(giResults.CollisionGroupResults);
    jConf = giResults.CollisionGroupResults(n).createJointConfiguration;
    hand.Fingers(giResults.SearchedIndices(n)).JointValues = jConf.JointValues;
end
hand';

%% storing relative transforms
targetTransform = inv(obj.Frame)*hand.PalmObject.Frame;


%% creating boxes
b(16) = Box([6 24 8]);
%b(16) = Solid;
boxLength =32;
boxHeight = 8;
for n = 1:16;
    
    b(n) = Box(2*[3 16 4]); 
    %b(n) = Solid('Cube');
    %b(n).resize([6 boxLength boxHeight])
    if n > 8
        
        b(n).Frame = Geometry.translation('zxy',[boxHeight/2 64-(n-8)*16 96]);
        
    else
        
        b(n).Frame = Geometry.translation('zxy',[boxHeight/2 64-n*16 60]);
        
    end
    b(n).Mass = 2;
    
end
b';

%% creating world with default ground object
world = PhysicsWorld;


%% adding hand to world
hand.IsDynamic = false;
hand.Frame = Geometry.translation('z',20);
world.addBody(hand.getAllBodies);
%% adding objects to the world
for n=1:length(b);
    
    world.addBody(b(n));
    
end




%% initializing world
world.initializeSimulation;

%% running simulation
world.startSimulation;

%% pause simulation
world.pauseSimulation;

%% stepping simulation
world.stepSimulation;

%% resume simulation
world.resumeSimulation;

%% stopping simulation 
world.stopSimulation;

%%
clear world

%% generating joint data
numSteps = 200;
jointClose = zeros(4,numSteps,4);
jointOpen = zeros(4,numSteps,4);
thumbOpen = [-pi/10 -pi/10 pi/6 0]';
indexOpen = [pi/2.5 0 pi/6 pi/6];
for n = 1:length(giResults.CollisionGroupResults);
    jConf = giResults.CollisionGroupResults(n).createJointConfiguration;
    jVals = jConf.JointValues*1.00;
    index = giResults.SearchedIndices(n);
    if index ~= 4
        jointClose(:,:,index) = [linspace(indexOpen(1),jVals(1),numSteps);...
            linspace(indexOpen(2),jVals(2),numSteps);...
            linspace(indexOpen(3),jVals(3),numSteps);...
            linspace(indexOpen(4),jVals(4),numSteps)];
        
        jointOpen(:,:,index) = [linspace(jVals(1),indexOpen(1),numSteps);...
            linspace(jVals(2),indexOpen(2),numSteps);...
            linspace(jVals(3),indexOpen(3),numSteps);...
            linspace(jVals(4),indexOpen(4),numSteps)];
    else
        jointClose(:,:,index) = [linspace(thumbOpen(1),jVals(1),numSteps);...
            linspace(thumbOpen(2),jVals(2),numSteps);...
            linspace(thumbOpen(3),jVals(3),numSteps);...
            linspace(thumbOpen(4),jVals(4),numSteps)];
        
        jointOpen(:,:,index) = [linspace(jVals(1),thumbOpen(1),numSteps);...
            linspace(jVals(2),thumbOpen(2),numSteps);...
            linspace(jVals(3),thumbOpen(3),numSteps);...
            linspace(jVals(4),thumbOpen(4),numSteps)];
    end
            
end

%% hand at open pose
        
            hand.Fingers(1).JointValues=jointOpen(:,end,1);
            hand.Fingers(2).JointValues=jointOpen(:,end,2);
            hand.Fingers(3).JointValues=jointOpen(:,end,3);
            hand.Fingers(4).JointValues=jointOpen(:,end,4);
            hand.updateToPhysics;
        
        
 %% hand at close pose
        
            hand.Fingers(1).JointValues=jointClose(:,end,1);
            hand.Fingers(2).JointValues=jointClose(:,end,2);
            hand.Fingers(3).JointValues=jointClose(:,end,3);
            hand.Fingers(4).JointValues=jointClose(:,end,4);
            hand.updateToPhysics;
       

%% starting counter
counter1 = 1;
counter2 = 1;

while counter1 <=4        
        %% move hand above location of box
        handEndPos = b(counter2+4*(counter1-1)).Frame*targetTransform;
        handEndPos = handEndPos(1:3,4);
        handTransform = Geometry.translation('z',4)*b(counter2 +4*(counter1-1)).Frame*targetTransform;       
        hand.Frame = handTransform;
        hand.updateToPhysics;        
        
        %% descending onto object
        steps2 = 80;
        handCurrentPos = hand.PalmObject.Position;
        handOrientation = [handTransform(1:3,1:3),zeros(3,1);0 0 0 1]; 
        % ascending
        for m = 1:steps2;
            
            hand.Frame = Geometry.translation('xyz',handCurrentPos+m*(handEndPos-handCurrentPos)/steps2)*...
                handOrientation;
            
            hand.updateToPhysics;
            
        end
        
        %%
        % angle and motion data
        theta = (pi/2)*(counter2-1);
        alpha = pi/4;
        gamma = (pi/2)*(counter2-1);
        boxPos = [(boxLength-4)*cos(theta + mod(counter1+1,2)*alpha);
            (boxLength-4)*sin(theta + mod(counter1+1,2)*alpha);
            boxHeight*(counter1-1)+boxHeight/2+ 0.2];
        handCurrentPos = hand.PalmObject.Position;
        handEndPos = handCurrentPos + [0;0;boxPos(3)+boxHeight];
        handOrientation = [handTransform(1:3,1:3),zeros(3,1);0 0 0 1];        
%%
        % hand closing fingers
        for n=1:numSteps;
            hand.Fingers(1).JointValues=jointClose(:,n,1);
            hand.Fingers(2).JointValues=jointClose(:,n,2);
            hand.Fingers(3).JointValues=jointClose(:,n,3);
            hand.Fingers(4).JointValues=jointClose(:,n,4);
            hand.updateToPhysics;
        end
        
        %%
        
        
        steps2 = 400;
        
        % ascending
        for m = 1:steps2;
            
            hand.Frame = Geometry.translation('xyz',handCurrentPos+m*(handEndPos-handCurrentPos)/steps2)*...
                handOrientation;
            
            hand.updateToPhysics;
            
        end
        
                 %% rotating
        
        if ~(gamma == 0 && mod(counter1+1,2)==0)
            
            if gamma > pi
                
                gamma = -pi/2;
                
            end
            handCurrentTransform = hand.Frame;
            handCurrentOrientation = [handCurrentTransform(1:3,1:3),zeros(3,1);0 0 0 1];
            delta = linspace(0,gamma + mod(counter1+1,2)*alpha,steps2);
            for m = 1:steps2;

                hand.Frame = Geometry.translation('xyz',handCurrentTransform(1:3,4))...
                    *Geometry.rotation('z',delta(m))*handCurrentOrientation;

                hand.updateToPhysics;

            end

        end
        
        %% moving to target pos in x  and y
        
        handCurrentTransform = hand.Frame;
        handCurrentPos = handCurrentTransform(1:3,4);
        handEndPos = Geometry.translation('xyz',boxPos)*Geometry.rotation('z',theta)*targetTransform;
        handEndPos = handEndPos(1:3,4);
        handCurrentTransform = hand.Frame;
        handCurrentOrientation = [handCurrentTransform(1:3,1:3),zeros(3,1);0 0 0 1];
        
        % 
        steps3 = steps2 + 400;
        for m = 1:steps3;
            
            hand.Frame = Geometry.translation('xyz',handCurrentPos+m*([handEndPos(1:2);handCurrentPos(3)]-handCurrentPos)/steps3)*...
                handCurrentOrientation;
            
            hand.updateToPhysics;
            
        end
        

        
        %% descending to target
        handCurrentTransform = hand.Frame;
        handCurrentPos = handCurrentTransform(1:3,4);
        handCurrentOrientation = [handCurrentTransform(1:3,1:3),zeros(3,1);0 0 0 1];
        
        
        for m = 1:steps2;
            
            hand.Frame = Geometry.translation('xyz',handCurrentPos+m*(handEndPos-handCurrentPos)/steps2)*handCurrentOrientation;
            
            hand.updateToPhysics;
            
        end
        
        pause(1);
        
        %%
        % hand opening fingers
        hand.Fingers(1).JointValues=jointOpen(:,end,1);
        hand.Fingers(2).JointValues=jointOpen(:,end,2);
        hand.Fingers(3).JointValues=jointOpen(:,end,3);
        hand.Fingers(4).JointValues=jointOpen(:,end,4);
        hand.updateToPhysics;
%         for n=1:numStxxxxeps;
%             hand.Fingers(1).JointValues=jointOpen(:,n,1);
%             hand.Fingers(2).JointValues=jointOpen(:,n,2);
%             hand.Fingers(3).JointValues=jointOpen(:,n,3);
%             hand.Fingers(4).JointValues=jointOpen(:,n,4);
%             hand.updateToPhysics;
%         end
        
        
        counter2 = counter2+1;
        
        if counter2 >4
            counter2 = 1;
            counter1 = counter1 + 1;
        
        end
        
end
        
    
        
       
        
    
  
    
    
    

%% initializing world
world.initializeSimulation;

%% running simulation
world.startSimulation;
%% pause simulation
world.pauseSimulation;
%% stepping simulation
world.stepSimulation;
%% resume simulation
world.resumeSimulation;
%% stopping simulation 
world.stopSimulation;

%% clear world
clear world

%% creating excel data
testNo=1;
excelData = {'Object','Triangles','SearchOrder','Q_GI','t_GI','N_GI'};

%% adding data to cell array for excel doc
excelData(1 + testNo,:) = {obj.ModelName,size(obj.Faces,1),['[' num2str(searchIndices) ']'],...
    giResults.WrenchSpace.getQuality,giTime,length(giResults.SearchedIndices)};
%% writing to excel
xlswrite('GraspSimulation_Experiment_Results',excelData,'RowdyHand_Box_Grasp','A1')
    




    


