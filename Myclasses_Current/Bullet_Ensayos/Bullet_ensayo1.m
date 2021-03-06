%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% This program will test the Bullet_Ensayo_Classes.mexw32 
c=Box;
c.Frame=Solid.translation('xyz',[5 6 10])*Solid.rotation('xz',[pi/6 pi/3]);
%% Creating Physics environment object
% defining parameters
cId=int32(1);  % class Identifier corresponds to PhysicsSimpleEnvironment object
mId=int32(0);  % method Identifier corresponds to method called ( 0 is attributed 
               % the constructor
environment=Bullet_Ensayo_Classes(cId,mId);


%% Creating Solid Object
cId=int32(2);
mId=int32(0);
box=Bullet_Ensayo_Classes(cId,mId,c);
%% Adding Solid object to the Physics environment
cId=int32(1);
mId=int32(1);
Bullet_Ensayo_Classes(cId,mId,environment,box)

%% Printing added Solid Objects
cId=int32(1);
mId=int32(4);
Bullet_Ensayo_Classes(cId,mId,environment);
%% Calling the updateTransform function for the Solid Object
cId=int32(2);
mId=int32(3);
Bullet_Ensayo_Classes(cId,mId,box)

%% Retrieving the Solid Objet Position Vector
cId=int32(2);
mId=int32(2);
position=Bullet_Ensayo_Classes(cId,mId,box);

%% Stepping the Simulation
cId=int32(1);
mId=int32(3);
Bullet_Ensayo_Classes(cId,mId,environment)

%% Retrieving the Solid Object Quaternion Vector
cId=int32(2);
mId=int32(1);
quaternion=Bullet_Ensayo_Classes(cId,mId,box);

%% simulating
figure(1)
c';
axis([-16 16 -16 16 -16 16])
%%
for n=1:500;
    cId=int32(1);
    mId=int32(3);
    Bullet_Ensayo_Classes(cId,mId,environment)
    
    cId=int32(2);
    mId=int32(2);
    c.Position=Bullet_Ensayo_Classes(cId,mId,box);
    
    mId=int32(1);
    c.Quaternion=Bullet_Ensayo_Classes(cId,mId,box);
    
    c.update;
    drawnow;
end
    
%% Calling the Simple Physics Environment destructor
cId=int32(1);
mId=int32(-1);
Bullet_Ensayo_Classes(cId,mId,environment);
%% Destroying Solid Object
cId=int32(2);
mId=int32(-1);
Bullet_Ensayo_Classes(cId,mId,box)

