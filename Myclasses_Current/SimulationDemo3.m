% Example program 3
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
% This program places ramdom highly dense concave mesh objects in the
% simulation.

%% creating world with default ground object
world = PhysicsWorld;

%% creating object to be added to the world
f(9)=Solid('flange');
f(9).scale(50);
%f=Solid('handSpring - SW3dPS-Hand 2_Finger Assm-5 SW3dPS-Hand 2_spring joint-3.STL');
f(9).Position=[0 4 50]';
f(9).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/3));

f(10)=Solid('flange');
f(10).scale(50);
%f=Solid('handSpring - SW3dPS-Hand 2_Finger Assm-5 SW3dPS-Hand 2_spring joint-3.STL');
f(10).Position=[0 -4 50]';
f(10).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/3));

for n = 1:8
    
    f(n)=Solid('Sprocket.STL');
    f(n).scale(1);
    %f=Solid('handSpring - SW3dPS-Hand 2_Finger Assm-5 SW3dPS-Hand 2_spring joint-3.STL');
    f(n).Position=[0 0 10 + 5*n]';
    f(n).Mass=5;
    f(n).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/3));

end

%% adding object to the world
for n = 1:10;
    world.addBody(f(n));
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

%% close simulation
clear world