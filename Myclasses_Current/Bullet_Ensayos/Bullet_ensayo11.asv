%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% creating world with default ground object
world = PhysicsWorld;

%% creating object to be added to the world
h(1)=Hand('Prototype1B');
h(1).Frame=Solid. translation('zx',[15 -8]);
h(1).IsDynamic=false;

%% adding object to the world
for n=1:length(h(1).Fingers)
    for m=1:length(h(1).Fingers(n).Links);
        world.addBody(h(1).Fingers(n).Links(m));
    end
end
world.addBody(h(1).PalmObject);
%%
world.initializeSimulation;
%% running simulation
world.runSimulationInExternalAnimator;

%% creating joint data
jointvar=linspace(0,pi/6,200)';
joints=[zeros(length(jointvar),1) jointvar repmat(jointvar,1,2)];
joints2=[linspace(0,-pi/12,200)' linspace(0,pi/5,200)' linspace(0,pi/6,200)' jointvar];
jointsThumb=[linspace(0,pi/9,200)' linspace(0,pi/10,200)' linspace(0,pi/6,200)' jointvar];

%% animating finger in external simulator
for n=1:size(joints2,1);
    h(1).Fingers(1).JointValues=joints2(n,:)';
    h(1).Fingers(2).JointValues=joints2(n,:)';
    h(1).Fingers(3).JointValues=joints(n,:)';    
    h(1).Fingers(5).JointValues=jointsThumb(n,:)';
    h(1).Fingers(4).JointValues=joints(n,:)';
    h(1).updateToPhysics;
end
%% changing Base
h(1).Frame=Solid. translation('zx',[15 -8]);
h(1).updateToPhysics;