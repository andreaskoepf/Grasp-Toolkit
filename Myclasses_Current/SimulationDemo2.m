% Example program 2
% Instructions:
% The path where the library resides must be added to the matlab path using 
% the addpath function
% This program must be executed one cell at the time
% To Run a single cell press ctrl + enter
% To Run a single cell and advance towards the next press ctrl + shift +
% enter
% Alternatively each cell can be run with the corresponding icon

%%
% Simulation Instruction:
% Once the simulation is running, the following keys will perform certain
% actions:
% space - resets the simulation
% i     - steps the simulation forward by a single step
% alt + right click - moves the camera
% z - zoom in
% x - zoom out

%%
% Description:
% This program will place a anthropomorphic hand model and a sphere in
% the simulation.  The hand will descend on the sphere and close its
% fingers to grab it. Then, it ascends, rotates and displaces the sphere
% and then releases it.

%% creating world with default ground object
world = PhysicsWorld;

%% creating object to be added to the world
h(1)=Hand('Prototype1B');
h(1).Frame=Solid. translation('zx',[30 -8]);
h(1).IsDynamic=false;

grabbedBox=Box([4 20 4]);
grabbedBox.Mass=100;
grabbedBox.Position=[0 0 2]';

%% adding object to the world
world.addBody(h(1).getAllBodies);
world.addBody(grabbedBox);
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

%% creating joint data
jointvar=linspace(0,pi/6,200)';
joints=[zeros(length(jointvar),1) jointvar repmat(jointvar,1,2)];
joints2=[linspace(0,-pi/12,200)' linspace(0,pi/5,200)' linspace(0,pi/8,200)' jointvar];
jointsThumb=[linspace(0,pi/9,200)' linspace(0,pi/10,200)' linspace(0,pi/6,200)' jointvar];

%% animating hand descending
for n=linspace(32,8,100);
    h(1).Frame=Solid. translation('zx',[n -8]);
    h(1).updateToPhysics;
end

%% animating fingers in external simulator
for n=1:size(joints2,1);
    h(1).Fingers(1).JointValues=joints2(n,:)';
    h(1).Fingers(2).JointValues=joints2(n,:)';
    h(1).Fingers(3).JointValues=joints(n,:)';    
    h(1).Fingers(5).JointValues=jointsThumb(n,:)';
    h(1).Fingers(4).JointValues=joints(n,:)';
    h(1).updateToPhysics;
end

%% animating hand ascending
for n=linspace(8,30,200);
    h(1).Frame=Solid. translation('zx',[n -8]);
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
h(1).Fingers(5).JointValues=zeros(h(1).Fingers(5).DOF,1);
h(1).Fingers(4).JointValues=zeros(h(1).Fingers(4).DOF,1);
h(1).updateToPhysics;

%% changing Base
h(1).Frame=Solid. translation('zx',[32 -10]);
h(1).updateToPhysics;

%% resume simulation
world.resumeSimulation;
    
%% pause simulation
world.pauseSimulation;

%% stopping simulation 
world.stopSimulation;

%% closing simulation
% This command shall only be called once the simulation has been stopped
clear world
