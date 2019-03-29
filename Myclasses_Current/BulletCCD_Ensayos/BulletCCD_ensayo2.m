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
link=Link('Prototype1_Index_Link2_1DOF');
link.setPhysicsHandle;
sphere=Sphere;
sphere.setPhysicsHandle;

%% creating localTransforms

link.JointValues = 0;
localTransformA = link.Transform;
%% Setting Collision object a to the CCD Object
cId=int32(4);
mId=int32(1);
PhysicsFunction(cId,mId,ccd,link.PhysicsHandle,localTransformA)
%PhysicsFunction(cId,mId,ccd,link.PhysicsHandle)
%% Setting Collision object b to the CCD Object
cId=int32(4);
mId=int32(2);
PhysicsFunction(cId,mId,ccd,sphere.PhysicsHandle)
%% initial configuration
figure(1);

theta0=0;
thetaf=pi/2;

axis(0.5*[-10 10 -10 10 -10 10])
link.JointValues=theta0;

link.Frame = link.Transform;
%link.Frame = eye(4);
link';
spherePos=[1 2 0];
sphere.Frame = Solid.translation('xyz',spherePos);
sphere';
%% Creating initial and final transforms for both bodies
link.JointValues=theta0;
linkTransform0=link.Transform;
%linkTranform0 = eye(4);
%=Solid.rotation('x',-pi/2)*Solid.translation('z',4);
link.JointValues=thetaf;
linkTransformf=Solid.translation('y',0)*link.Transform;
%linkTransformf=Solid.translation('y',4);


sphereTransform0=Solid.translation('xyz',spherePos);
sphereTransformf=Solid.translation('xyz',spherePos);
%% showing bodies at final configuration
figure(1);
link.Frame=linkTransformf;
sphere.Frame=sphereTransformf;
link';
sphere';
%% Calling the performCCDTest method
cId=int32(4);
mId=int32(3);
[bool,ccdResultStruct]=PhysicsFunction(cId,mId,ccd,linkTransform0,linkTransformf,sphereTransform0,sphereTransformf);

%disp(ccdResultStruct.TOC_TransformA)
%disp(ccdResultStruct.TOC_TransformB)
disp(ccdResultStruct.TOC)
disp(ccdResultStruct.NumContacts)

%% Showing both bodies at collision
if(bool)
    link.Frame=ccdResultStruct.TOC_TransformA;
    sphere.Frame=ccdResultStruct.TOC_TransformB;
    link';
    sphere';
end

%% computing theta at toc 
if(bool)
    theta_toc=(thetaf-theta0)*ccdResultStruct.TOC;
    link.JointValues=theta0+theta_toc;
    link.Frame=link.Transform;
    box.Frame=ccdResultStruct.TOC_TransformB;
    link';
    box';
end

%% destroying all objects
link.destroyPhysicsHandle;
sphere.destroyPhysicsHandle;

%%
cId=int32(4);
mId=int32(-1);
PhysicsFunction(cId,mId,ccd);

