
% this program checks that the objects are getting built properly
%% creating Continuous Collision Detection Object
cId=int32(4);  % class Identifier corresponds to ContinuousCollisionDetection object
mId=int32(0);  % method Identifier corresponds to method called ( 0 is attributed 
               % the constructor
               
% creating structure to fake the input argument
ccdObject=struct('field1',0,'field2',0);
               
ccd=MexFiles.BulletPhysicsMex(cId,mId,ccdObject);

%% creating link object
link=Link('Prototype1_Index_Link2_1DOF');
link.setPhysicsHandle;

%% setting Collision object a to the CCD Object
cId=int32(4);
mId=int32(1);
MexFiles.BulletPhysicsMex(cId,mId,ccd,link.PhysicsHandle)


%%
nVertices=size(link.CurrentVertices,1);
vertices=repmat(-link.COG,nVertices,1)+link.Vertices(1:3,:)';

%% destroying all objects
link.destroyPhysicsHandle;

%%
cId=int32(4);
mId=int32(-1);
MexFiles.BulletPhysicsMex(cId,mId,ccd);