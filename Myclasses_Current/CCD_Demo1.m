%% Creating Continuous Collision Detection Object               
ccd=CollisionDetection.ContinuousCollisionDetection;
%ccd.createMexInstance;


%% Creating Solid Objects
objectA=Solid('Sprocket.STL');
objectA.Color = [0 0 1];
objectB=Box([2 2 2]);
objectB.Color='y';
%objectB.setPhysicsHandle;
%% creating localTransforms
localTransformA = translation('y',4);
localTransformB = eye(4);

%% Setting Collision object a to the CCD Object

ccd.setObjectA(objectA,localTransformA);
%% Setting Collision object b to the CCD Object

ccd.setObjectB(objectB,localTransformB);

%% initial configuration
% world transform for both objects
worldTransform = Algorithms.rotation('y',0);

% static link position
objectAPos = [0 -4 4];
objectBPos=[0 4 0];

%% Creating initial and final transforms for both bodies
objectATransform0=worldTransform*Solid.translation('xyz',objectAPos);
objectATransformf=worldTransform*Solid.translation('xyz',objectBPos)*rotation('yx',[pi/6 -pi/3]);

objectBTransform0=worldTransform*Solid.translation('xyz',objectBPos);
objectBTransformf=worldTransform*Solid.translation('xyz',objectBPos);

%% showing bodies at initial configuration
figure(1);
axis(0.5*[-10 10 -10 10 -10 10])

objectA.Frame=objectATransform0;
objectA';

objectB.Frame = objectBTransform0;
objectB';

grid on
%% showing bodies at final configuration
figure(1);
objectA.Frame=objectATransformf;
objectB.Frame=objectBTransformf;
objectA';
objectB';
%% Calling the performCCDTest method
ccdResultStruct = ccd.performCCDPairTest(objectATransform0,objectATransformf,objectBTransform0,objectBTransformf);
%[bool,ccdResultStruct]=ccd.mexPerformCCDTest(objectATransform0,objectATransformf,objectBTransform0,objectBTransformf);

fprintf('\nTransfor at toc for body a\n')
disp(ccdResultStruct.TOC_TransformA)
fprintf('\nTransfor at toc for body b\n')
disp(ccdResultStruct.TOC_TransformB)
fprintf('\nTOC\n')
disp(ccdResultStruct.TOC)
fprintf('\nNumber Of Contacts\n')
disp(ccdResultStruct.NumContacts)

%% Showing both bodies at collision
if(ccdResultStruct.CollisionFlag == CollisionDetection.ContinuousCollisionDetection.TOC_FOUND)
    objectA.Frame=ccdResultStruct.TOC_TransformA;
    objectB.Frame=ccdResultStruct.TOC_TransformB;
    objectA';
    objectB';
end



%%
%ccd.destroyMexInstance;
