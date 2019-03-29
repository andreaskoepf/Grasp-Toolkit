%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% creating world with default ground object
world = PhysicsWorld;

%% creating object to be added to the world
f=Solid('flange');
f.scale(50);
%f=Solid('handSpring - SW3dPS-Hand 2_Finger Assm-5 SW3dPS-Hand 2_spring joint-3.STL');
f.Position=[0 0 20]';
f.Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/3));

%% adding object to the world
world.addBody(f);

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
%% clear world
clear world