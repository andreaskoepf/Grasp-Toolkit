%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% creating world with default ground object
world = PhysicsWorld;

%% setting sphere as ground
s=Sphere(25);
s.IsDynamic=false;
s.Frame=Solid.translation('z',-22);

world.GroundObject=s;
%% creating link objects
l(20)=Link;

for nz=1:5;
    
    d=(nz-1)*4;
    l(1 + d)=Link('Prototype1_Middle_Link2_1DOF');
    l(1 + d).reducePatch(0.2);
    l(1 + d).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/3));
    l(1 + d).Position=[4 0 10+(nz-1)*5]';

    l(2 + d)=Link('Prototype1_Middle_Link2_1DOF');
    l(2 + d).reducePatch(0.2);
    l(2 + d).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/2));
    l(2 + d).Position=[0 -4 10+(nz-1)*5]';

    l(3 + d)=Link('Prototype1_Middle_Link2_1DOF');
    l(3 + d).reducePatch(0.2);
    l(3 + d).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/2));
    l(3 + d).Position=[0 4 10+(nz-1)*5]';
    
    l(4 + d)=Link('Prototype1_Middle_Link2_1DOF');
    l(4 + d).reducePatch(0.2);
    l(4 + d).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/2));
    l(4 + d).Position=[-4 0 10+(nz-1)*5]';
    
end

%% adding object to the world
for n=1:length(l);
    world.addBody(l(n));
end

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

