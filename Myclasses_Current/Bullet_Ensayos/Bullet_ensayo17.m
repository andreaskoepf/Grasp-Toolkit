%% adding path to the matlab path
addpath F:\work\Myclasses_Current
%% creating physics world
world2=PhysicsWorld;

%% setting sphere as ground
s=Solid('Sprocket.STL');
s.scale(2);
s.IsDynamic=false;
s.Frame=Solid.translation('z',-1);

%% only allow modification to this method if simulation has not been
%% initialized
world2.GroundObject=s;

%% creating objects to be added to the world;
colorArray=repmat('yrbgwyrbgwyrbgwyrbgwyrbgw',1,20);

b(125)=Box;
l=1; % side length
ind=1;
for nx=1:5;
    for ny=1:5;
        for nz=1:5;
        
            b(ind)=Box([l l l]);
            b(ind).Color=colorArray(ind);
            b(ind).Frame=Solid.translation('zxy',[20-2*(l)+(nz-1)*3/2*l -2*(l)+(nx-1)*3/2*l -2*(l)+(ny-1)*3/2*l]);
                       
            
            ind=ind+1;
            
        end
        
    end
end

%% adding objects to the world
for n=1:length(b);
    
    world2.addBody(b(n));
    
end

%% initializing world
world2.initializeSimulation;

%% running simulation
world2.startSimulation;
%% pause simulation
world2.pauseSimulation;
%% resume simulation
world2.resumeSimulation;
%% stepping simulation
world2.stepSimulation;
%% stopping simulation 
world2.stopSimulation;

%% closing simulation
clear world2