%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% This program will test the Continuous Collision Detection Class which
%% has been implemented in the Bullet Physics mex file
%% Creating Continuous Collision Detection Object

               
ccd=ContinuousCollisionDetection;
ccd.createMexInstance;


%% Creating Solid Objects
objectA=Link('Prototype1_Index_Link2_1DOF');
objectA.setPhysicsHandle;
objectB=Link('Prototype1_Index_Link2_1DOF');
objectB.Color='y';
objectB.setPhysicsHandle;
%% creating localTransforms

objectA.JointValues = 0;
objectB.JointValues = 0;
localTransformA = objectA.Transform;
localTransformB = objectB.Transform;

%% Setting Collision object a to the CCD Object

ccd.setObjectA(objectA,localTransformA);
%% Setting Collision object b to the CCD Object

ccd.setObjectB(objectB,localTransformB);

%% initial configuration
% link initial and final joint angles
theta0=0;
thetaf=pi/2;

% link position
objectAPos = [0 1 0];
objectATranslation = Algorithms.translation('xyz',objectAPos);

% static link position
objectBPos=[1 4 0];

%% Creating initial and final transforms for both bodies

%=Solid.rotation('x',-pi/2)*Solid.translation('z',4);
objectA.JointValues=theta0;
objectATransform0=objectATranslation*objectA.Transform;
objectA.JointValues=thetaf;
objectATransformf=objectATranslation*objectA.Transform;

objectBTransform0=Solid.translation('xyz',objectBPos);
objectBTransformf=Solid.translation('xyz',objectBPos);

%% showing bodies at initial configuration
figure(1);
axis(0.5*[-10 10 -10 10 -10 10])

objectA.Frame=objectATransform0;
objectA';

objectB.Frame = objectBTransform0;
objectB';
%% showing bodies at final configuration
figure(1);
objectA.Frame=objectATransformf;
objectB.Frame=objectBTransformf;
objectA';
objectB';
%% Calling the performCCDTest method
[bool,ccdResultStruct]=ccd.mexPerformCCDTest(objectATransform0,objectATransformf,objectBTransform0,objectBTransformf);

fprintf('\nTransfor at toc for body a\n')
disp(ccdResultStruct.TOC_TransformA)
fprintf('\nTransfor at toc for body b\n')
disp(ccdResultStruct.TOC_TransformB)
fprintf('\nTOC\n')
disp(ccdResultStruct.TOC)
fprintf('\nNumber Of Contacts\n')
disp(ccdResultStruct.NumContacts)

%% Showing both bodies at collision
if(bool)
    objectA.Frame=ccdResultStruct.TOC_TransformA;
    objectB.Frame=ccdResultStruct.TOC_TransformB;
    objectA';
    objectB';
end

%% computing theta at toc 
if(bool)
    theta_toc=(thetaf-theta0)*ccdResultStruct.TOC + theta0;
    objectA.JointValues=theta_toc;
    objectA.Frame=objectATranslation*objectA.Transform;
    objectB.Frame=ccdResultStruct.TOC_TransformB;
    objectA';
    objectB';
end


%% destroying all objects
objectA.destroyPhysicsHandle;
objectB.destroyPhysicsHandle;

%%
ccd.destroyMexInstance;

