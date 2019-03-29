%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% creating world with default ground object
world = PhysicsWorld;
%% creating object to be added to the world
for n = 1:8
    
    f(n)=Solid('Sprocket.STL');
    f(n).scale(1);
    %f=Solid('handSpring - SW3dPS-Hand 2_Finger Assm-5 SW3dPS-Hand 2_spring joint-3.STL');
    f(n).Position=[0 0 10 + 5*n]';
    f(n).Mass=5;
    f(n).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/3));

end

%% adding object to the world
for n = 1:8;
    world.addBody(f(n));
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