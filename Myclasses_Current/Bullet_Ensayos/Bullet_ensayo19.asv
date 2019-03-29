%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% creating world with default ground object
world = PhysicsWorld;

%% creating object to be added to the world
h(1)=Hand('ThreeFingerHand');
h(1).Frame=Solid. translation('zx',[30 0]);
h(1).IsDynamic=false;
linkLength = 10;
linkWidth = 1;
radius = linkLength*(0.5 + sqrt(2)*0.5) - 0.5*linkWidth;
grabbedSphere=Solid('sphere');
grabbedSphere.scale(2*radius);
grabbedSphere.Mass=10;
grabbedSphere.Position=[0 0 radius]';

%% adding object to the world
world.addBody(h(1).getAllBodies);
world.addBody(grabbedSphere);
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
jointvar=linspace(0,pi/4,200)';
joints=[jointvar repmat(jointvar,1,2)];
%joints2=[linspace(0,-pi/12,200)' linspace(0,pi/5,200)' linspace(0,pi/8,200)' jointvar];
%jointsThumb=[linspace(0,pi/9,200)' linspace(0,pi/10,200)' linspace(0,pi/6,200)' jointvar];

%% animating hand descending
for n=linspace(32,2*radius+1,100);
    h(1).Frame=Solid. translation('zx',[n 0]);
    h(1).updateToPhysics;
end

%% animating fingers in external simulator
for n=1:size(joints,1);
    h(1).Fingers(1).JointValues=joints(n,:)';
    h(1).Fingers(2).JointValues=joints(n,:)';
    h(1).Fingers(3).JointValues=joints(n,:)';    
    %h(1).Fingers(5).JointValues=jointsThumb(n,:)';
    %h(1).Fingers(4).JointValues=joints(n,:)';
    h(1).updateToPhysics;
end

%% animating hand ascending
for n=linspace(2*radius+1,30,200);
    h(1).Frame=Solid. translation('zx',[n 0]);
    h(1).updateToPhysics;
end

%% animating hand rotating
currentTransform=h(1).Frame;
for n=linspace(0,pi/2,200)
    
    h(1).Frame=currentTransform*Solid.rotation('x',n);
    h(1).updateToPhysics;
    
end

%% animating hand moving in the -y direction
currentTransform=h(1).Frame;
for n=linspace(0,-10,100);
    h(1).Frame=currentTransform*Solid.translation('z',n);
    h(1).updateToPhysics;
end

%% zero out joint Values
h(1).Fingers(1).JointValues=zeros(h(1).Fingers(1).DOF,1);
h(1).Fingers(2).JointValues=zeros(h(1).Fingers(2).DOF,1);
h(1).Fingers(3).JointValues=zeros(h(1).Fingers(3).DOF,1);    
%h(1).Fingers(5).JointValues=zeros(h(1).Fingers(5).DOF,1);
%h(1).Fingers(4).JointValues=zeros(h(1).Fingers(4).DOF,1);
h(1).updateToPhysics;
%% changing Base 
h(1).Frame=Solid. translation('zx',[32 0]);
h(1).updateToPhysics;
%% resume simulation
world.resumeSimulation;
%% stopping simulation 
world.stopSimulation;

%% closing simulation
clear world
