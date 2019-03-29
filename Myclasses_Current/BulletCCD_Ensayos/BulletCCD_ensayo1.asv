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
box=Box;
box.Color='y';
box.setPhysicsHandle;
sphere=Sphere;
sphere.setPhysicsHandle;
%% Setting Collision object a to the CCD Object
cId=int32(4);
mId=int32(1);
PhysicsFunction(cId,mId,ccd,box.PhysicsHandle)

%% Setting Collision object b to the CCD Object
cId=int32(4);
mId=int32(2);
PhysicsFunction(cId,mId,ccd,sphere.PhysicsHandle)

%% initial configuration
figure(1);

worldTransform = Algorithms.rotation('x',0);
% Creating initial and final transforms for both bodies
boxTransform0=worldTransform*Solid.rotation('yz',[0 0])*Solid.rotation('x',0);
boxTransformf=worldTransform*Solid.translation('z',3)*Solid.rotation('yz',[pi/3 pi/4]);

sphereTransform0=worldTransform*Solid.translation('z',4)*Solid.rotation('x',0);
sphereTransformf=worldTransform*Solid.translation('z',4)*Solid.rotation('x',0);

axis(0.5*[-10 10 -10 10 -10 10])
box.Frame = boxTransform0;
box';
sphere.Frame = sphereTransform0;
sphere';


%boxTransformf=Solid.translation('y',4);



%% showing bodies at final configuration
figure(1);
box.Frame=boxTransformf;
sphere.Frame=sphereTransformf;
box';
sphere';
%% Calling the performCCDTest method
cId=int32(4);
mId=int32(3);
[bool,ccdResultStruct]=PhysicsFunction(cId,mId,ccd,boxTransform0,boxTransformf,sphereTransform0,sphereTransformf);

fprintf('\nTransform at toc for body a\n')
disp(ccdResultStruct.TOC_TransformA)
fprintf('\nTransform at toc for body b\n')
disp(ccdResultStruct.TOC_TransformB)
fprintf('\nTOC\n')
disp(ccdResultStruct.TOC)
fprintf('\nNumber of Contacts\n')
disp(ccdResultStruct.NumContacts)
%% Showing both bodies at collision
if(bool)
    box.Frame = ccdResultStruct.TOC_TransformA;
    sphere.Frame = ccdResultStruct.TOC_TransformB;
    
    figure(1);
    box';
    sphere';
end

%% Contact Points
fprintf('\nContact On A\t\tContact On B\n')
contactResult=ccdResultStruct.ContactResultStruct;
for n=1:ccdResultStruct.NumContacts;
    fprintf('%1.3f\t\t\t\t\t%1.3f\n',...
        contactResult(n).ContactPointOnA(1),contactResult(n).ContactPointOnB(1))
    fprintf('%1.3f\t\t\t\t\t%1.3f\n',...
        contactResult(n).ContactPointOnA(2),contactResult(n).ContactPointOnB(2))
    fprintf('%1.3f\t\t\t\t\t%1.3f\n\n',...
        contactResult(n).ContactPointOnA(3),contactResult(n).ContactPointOnB(3))
end


%% Contact Normals
fprintf('\nNormal On A\t\tNormal On B\t\tNormal On World\n')
contactResult=ccdResultStruct.ContactResultStruct;
for n=1:ccdResultStruct.NumContacts;
    fprintf('%1.3f\t\t\t\t%1.3f\t\t\t\t%1.3f\n',...
        contactResult(n).ContactNormalOnA(1),contactResult(n).ContactNormalOnB(1)...
        ,contactResult(n).ContactNormalWorldOnB(1))
    fprintf('%1.3f\t\t\t\t%1.3f\t\t\t\t%1.3f\n',...
        contactResult(n).ContactNormalOnA(2),contactResult(n).ContactNormalOnB(2)...
        ,contactResult(n).ContactNormalWorldOnB(2))
    fprintf('%1.3f\t\t\t\t%1.3f\t\t\t\t%1.3f\n\n',...
        contactResult(n).ContactNormalOnA(3),contactResult(n).ContactNormalOnB(3)...
        ,contactResult(n).ContactNormalWorldOnB(3))
end



%% destroying all objects
box.destroyPhysicsHandle;
sphere.destroyPhysicsHandle;

cId=int32(4);
mId=int32(-1);
PhysicsFunction(cId,mId,ccd);
