%% Creating Continuous Collision Detection Object               
ccd=CollisionDetection.ContinuousCollisionDetection;
%ccd.createMexInstance;
%% Creating Solid Objects
box=Box;
box.Color='y';
sphere=Sphere;
%% creating localTransforms

localTransformA = eye(4);
localTransformB = eye(4);
%% Setting Collision object a to the CCD Object

ccd.setObjectA(box,localTransformA);
%% Setting Collision object b to the CCD Object

ccd.setObjectB(sphere,localTransformB);


%% initial configuration
figure(4);

worldTransform = Algorithms.rotation('x',0);
% Creating initial and final transforms for both bodies
objectATransform0=worldTransform*Solid.rotation('yz',[0 0])*Solid.rotation('x',0);
objectATransformf=worldTransform*Solid.translation('z',3)*Solid.rotation('yz',[0 pi/4]);

objectBTransform0=worldTransform*Solid.translation('z',4)*Solid.rotation('x',0);
objectBTransformf=worldTransform*Solid.translation('z',4)*Solid.rotation('x',0);

axis(0.5*[-10 10 -10 10 -10 10])
box.Frame = objectATransform0;
box';
sphere.Frame = objectBTransform0;
sphere';


%boxTransformf=Solid.translation('y',4);



%% showing bodies at final configuration
figure(4);
box.Frame=objectATransformf;
sphere.Frame=objectBTransformf;
box';
sphere';
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
    box.Frame = ccdResultStruct.TOC_TransformA;
    sphere.Frame = ccdResultStruct.TOC_TransformB;
    
    figure(4);
    box';
    sphere';
end
