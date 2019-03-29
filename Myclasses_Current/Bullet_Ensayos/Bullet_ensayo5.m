%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% creating world with default ground object
world = PhysicsWorld;

%% creating object to be added to the world
l(1)=Link('Prototype1_Middle_Link2_1DOF');
l(1).reducePatch(0.2);
l(1).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/3));
l(1).Position=[0 0 10]';

l(2)=Link('Prototype1_Middle_Link2_1DOF');
l(2).reducePatch(0.2);
l(2).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/2));
l(2).Position=[0 -4 12]';

l(3)=Link('Prototype1_Middle_Link2_1DOF');
l(3).reducePatch(0.2);
l(3).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/2));
l(3).Position=[0 4 12]';

%% adding object to the world
world.addBody(l(1));
world.addBody(l(2));
world.addBody(l(3));

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

%% close simulation
clear world

