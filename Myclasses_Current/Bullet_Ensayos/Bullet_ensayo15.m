
%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% creating world with default ground object
world = PhysicsWorld;

%% creating object to be added to the world
f(1)=Finger('Prototype1_Index_4DOF');
f(1).reducePatch(0.2);
f(1).BaseFrame=Solid.translation('z',10);
f(1).IsDynamic=false;

%% adding object to the world
world.addBody(f(1));

%% initializing world
world.initializeSimulation;

%% running simulation
world.startSimulation;
%% pause simulation
world.pauseSimulation;
%% resume simulation
world.resumeSimulation;
%% stepping simulation
world.stepSimulation;
%% stopping simulation 
world.stopSimulation;


%% creating joint data
jointvar=linspace(0,pi/6,200)';
joints=[zeros(length(jointvar),1) jointvar repmat(jointvar,1,2)];
joints2=[linspace(0,-pi/12,200)' linspace(0,pi/5,200)' linspace(0,pi/6,200)' jointvar];

%% animating finger in external simulator
for n=1:size(joints2,1);
    f(1).JointValues=joints2(n,:)';
    f(1).updateToPhysics;
end

%% changing Base
f(1).BaseFrame=Solid.translation('x',5)*f(1).BaseFrame;
f(1).updateToPhysics;

%% close simulation
clear world
