%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% This program will test the Continuous Collision Detection Class which
%% has been implemented in the Bullet Physics mex file
%% getting function handle
PhysicsFunction=@MexFiles.BulletPhysicsC2AMex;
%% Creating Continuous Collision Detection Object
% defining parameters
cId=int32(4);  % class Identifier corresponds to ContinuousCollisionDetection object
mId=int32(0);  % method Identifier corresponds to method called ( 0 is attributed 
               % the constructor
               
% creating structure to fake the input argument
ccdObject=struct('field1',0,'field2',0);
               
ccd=PhysicsFunction(cId,mId,ccdObject);


%% Creating Solid Objects
obj=Solid('flange');
obj.scale(10);
obj.setPhysicsHandle;
sphere=Sphere;
sphere.setPhysicsHandle;
%% Setting Collision object a to the CCD Object
cId=int32(4);
mId=int32(1);
PhysicsFunction(cId,mId,ccd,obj.PhysicsHandle)

%% Setting Collision object b to the CCD Object
cId=int32(4);
mId=int32(2);
PhysicsFunction(cId,mId,ccd,sphere.PhysicsHandle)
%% initial configuration
figure(1);
axis(0.5*[-10 10 -10 10 -10 10])
obj.Frame=eye(4);
obj';
spherePos=[1 4 0];
sphere.Frame = Solid.translation('xyz',spherePos);
sphere';
%% Creating initial and final transforms for both bodies
objTransform0=eye(4);
%=Solid.rotation('x',-pi/2)*Solid.translation('z',4);
objTransformf=Solid.translation('y',6)*Solid.rotation('z',pi/2);

sphereTransform0=Solid.translation('xyz',spherePos);
sphereTransformf=Solid.translation('xyz',spherePos);
%% showing bodies at final configuration
figure(1);
obj.Frame=objTransformf;
sphere.Frame=sphereTransformf;
obj';
sphere';
%% Calling the performCCDTest method
cId=int32(4);
mId=int32(3);
[bool,ccdResultStruct]=PhysicsFunction(cId,mId,ccd,objTransform0,objTransformf,sphereTransform0,sphereTransformf);

disp(ccdResultStruct.hitTransformA)
disp(ccdResultStruct.hitTransformB)
disp(ccdResultStruct.contactPoint)
disp(ccdResultStruct.normal)

%% Showing both bodies at collision
if(bool)
    obj.Frame=ccdResultStruct.hitTransformA;
    sphere.Frame=ccdResultStruct.hitTransformB;
    obj';
    sphere';
end

%% destroying all objects
obj.destroyPhysicsHandle;
sphere.destroyPhysicsHandle;

%%
cId=int32(4);
mId=int32(-1);
PhysicsFunction(cId,mId,ccd);

