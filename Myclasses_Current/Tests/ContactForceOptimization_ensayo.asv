% force optimization attempts
wreq=[3 2 -10 0 0 1]';
% contact locations
r=[[0;-3/2;sqrt(3)/2],...
    [0;3/2;sqrt(3)/2],...
    [3*sqrt(3)/8;0;3*sqrt(3)/4],...
    [-3*sqrt(3)/8;0;3*sqrt(3)/4]];

% contact normals
n=[[0;sqrt(3)/2;1/2],[0;-sqrt(3)/2;1/2],[-3/5;0;-4/5],[3/5;0;-4/5]];

WC=zeros(6,4);
% GraspMatrix
for n1=1:size(n,2);    
    o=cross(n(:,n1),[1 0 0]');
    t=cross(n(:,n1),o);
    % GraspMatrix
    G=[n(:,n1) o t zeros(3,1);cross(r(:,n1),n(:,n1)) cross(r(:,n1),o) ...
        cross(r(:,n1),t) n(:,n1)];
    WC(:,n1)=G*[1 0 0 0]';
end
%%
% % translational and torsional friction coefficients
% friction=[0.2 0.2];
% 
% % contact model
% contact='SFCe';
% 
% % resolution
% resolution=[8 2];
% 
% wsize=2*resolution(1)*resolution(2)-resolution(1)+2;
% 
% % constructing wrench space
% W=zeros(6,wsize*size(r,2));
% 
% for n1=1:size(r,2);
%     W(:,wsize*(n1-1)+1:wsize*n1)=Algorithms.FrictionConeDiscretization(n(:,n1),r(:,n1),contact,friction,eye(4),resolution);
% end
% W=[zeros(6,1) W]';
% % obtaining convex hull
% 
% indices=convhulln(W,{'Qt','Qx'});
% K=unique(reshape(indices,size(indices,2)*size(indices,1),1));
% WC=W(K,:)';

% finding intersection point between wreq and WC
[z,V]=Algorithms.RayShootingIntersection(wreq,WC);

% finding minimum delta
dmin=norm(wreq)/norm(z);