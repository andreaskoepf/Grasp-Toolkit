%% Non Force Closure Case
r = [[0; -2; 3*sqrt(3)/4],...
    [3/4; 0; sqrt(3)/2],...
    [0; 2; 3*sqrt(3)/4]...
    [-3/4; 0; sqrt(3)/2]];

n = [[0; sqrt(3)/2; 1/2],...
    [-sqrt(3)/2; 0; 1/2],...
    [0; -sqrt(3)/2; 1/2],...
    [sqrt(3)/2; 0; 1/2]];
    

%% Force Closure Case
% contact locations
r=[[0;-3/2;sqrt(3)/2],...
    [0;3/2;sqrt(3)/2],...
    [3*sqrt(3)/8;0;3*sqrt(3)/4],...
    [-3*sqrt(3)/8;0;3*sqrt(3)/4]];

% contact normals
n=[[0;sqrt(3)/2;1/2],[0;-sqrt(3)/2;1/2],[-3/5;0;-4/5],[3/5;0;-4/5]];

%%
% translational and torsional friction coefficients
friction=[0.2 0.2];

% contact model
contact='SFCe';

% resolution
resolution=[8 2];

wsize=2*resolution(1)*resolution(2)-resolution(1)+2;

% constructing wrench space
W=zeros(6,wsize*size(r,2));

for n1=1:size(r,2);
    W(:,wsize*(n1-1)+1:wsize*n1)=Algorithms.FrictionConeDiscretization(n(:,n1),r(:,n1),contact,friction,eye(4),resolution);
end

%% creating convex hull without origin
W = W';
indices=convhulln(W,{'Qt','Qx'});
K=unique(reshape(indices,size(indices,2)*size(indices,1),1));
WC=W(K,:)';

%% creating convex hull with origin
W=[zeros(6,1) W]';
% obtaining convex hull

indices=convhulln(W,{'Qt','Qx'});
K=unique(reshape(indices,size(indices,2)*size(indices,1),1));
WC=W(K,:)';

%% computing centroid using normal wrenches
wCentroid = zeros(6,1);

for n1 = 1:size(r,2);
    
    wCentroid = Algorithms.FrictionConeDiscretization(n(:,n1),r(:,n1),'FPC',0) + wCentroid;
    
end
wCentroid = wCentroid/(1 + size(r,2));

%%

[z,S]=Algorithms.RayShootingIntersection(-wCentroid,WC);
%%
wc=[0;0;-0.12;0;0;0];

[z,S]=Algorithms.RayShootingIntersection(-wc,WC);




