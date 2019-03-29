%% Swept volume trial
addpath 'H:\work\Myclasses_Current'
sweptSolid=Solid;
l=Link('Prototype1_Index_Link1_1DOF');
l.JointValues=0;

l.updateData;

transform=inv(l.Frame);
for n=linspace(-pi/6,pi/6,20);
    l.JointValues=n;    
    l.updateData;    
    sweptSolid=l+sweptSolid;
end
sweptSolid';
sweptSolid.shift(transform);

%%
data=l.toStruct;
data.DefaultVertices=sweptSolid.DefaultVertices;
data.Faces=sweptSolid.Faces;
data.JointValues=0;
data.Dimensions=sweptSolid.Dimensions;
sweptSolid';
%%
sweptLink=Link(data);
sweptLink.reducePatch(0.4)
sweptLink';
%% Convert the mesh to a voxelvolume

% scaling link in order to fit inside grid
sweptLink.LocalFrame=eye(4);
scaleFactor=250/max(sweptLink.Dimensions);
sweptLink.scale(scaleFactor(1));
sweptLink';
%%
% obtaining the minimum x, y and z geometric values
span=sweptLink.getCurrentSpan;
xyzMin=-span([1,3,5]);
% moving the link to a location where all vertices have positive values
transform=Solid.translation('xyz',xyzMin);
sweptLink.Frame=transform;
sweptLink';

%%
FV.vertices=sweptLink.CurrentVertices;
FV.faces=sweptLink.Faces;
% Convert the mesh to a voxelvolume
gridSize=250;
Volume=polygon2voxel(FV,gridSize*[1 1 1],'a');
Volume2=permute(Volume,[2 1 3]);
% Show x,y,z slices
% figure('Name','Test 2.b - Image Slice'),
% subplot(1,3,1), imshow(squeeze(Volume(25,:,:)));
% subplot(1,3,2), imshow(squeeze(Volume(:,25,:)));
% subplot(1,3,3), imshow(squeeze(Volume(:,:,25)));

%  Show iso surface of result
figure('Name','Test Swept Volume Test - extracted isosurface of Volume'), 
p=patch(isosurface(Volume2), 'Facecolor', [1 0 0]);
daspect([1 1 1])


