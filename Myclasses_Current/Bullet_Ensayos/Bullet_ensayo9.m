
%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% creating world with default ground object
world = PhysicsWorld;
world.NumberOfSimulationSteps=1500;

%% creating object to be added to the world
l(1)=Link('Prototype1_Middle_Link2_1DOF');
l(1).reducePatch(0.2);
l(1).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/3));
l(1).Position=[0 0 10]';
l(1).IsDynamic=false;

%% adding object to the world
world.addBody(l(1));

%%


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

%% Querying object
l.Frame=Solid.translation('z',5)*Solid.rotation('x',pi/4);
disp(l.Frame)
l.updateToPhysics