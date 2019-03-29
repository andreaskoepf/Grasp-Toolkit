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
% This program places 500 boxes colliding with a static sphere.

%% creating physics world
world=PhysicsWorld;

%% setting sphere as ground
s=Sphere(25);
s.IsDynamic=false;
s.Frame=Solid.translation('z',-22);

world.GroundObject=s;

%% creating objects to be added to the world;
colorArray=repmat('yrbgwyrbgwyrbgwyrbgwyrbgw',1,20);

b(500)=Box;
l=1; % side length
ind=1;
for nx=1:5;
    for ny=1:5;
        for nz=1:20;
        
            b(ind)=Box([l l l]);
            b(ind).Color=colorArray(ind);
            b(ind).Frame=Solid.translation('zxy',[20-2*(l)+(nz-1)*3/2*l -2*(l)+(nx-1)*3/2*l -2*(l)+(ny-1)*3/2*l]);
                       
            
            ind=ind+1;
            
        end
        
    end
end

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

%% closing simulation
clear world