
%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% creating world with default ground object
world = PhysicsWorld;

%% creating object to be added to the world
s=Sphere(5);
s.Mass=100;
s.Position=[0 0 5]';


%% adding object to the world
world.addBody(s);

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
%% closing simulation
clear world