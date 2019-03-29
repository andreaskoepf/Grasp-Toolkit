% GJK algorithm
% Uses the GJK algorithm to compute the shortest distance between a convex
% set A and the origin as long as the origin is not contained in set A.
%% Inputs
A=[[-1 1 1 -1];2+[-1 -1 1 1]];

%% Inputs :  hexagon
A=zeros(2,6);
%building A
r=1; % inner segment length
for n=1:6;
    A(:,n)=[r*cos((n-1)*pi/3)+1;r*sin((n-1)*pi/3)+sqrt(3)/2];
end

%% Inputs: box
box=Box;
box.Frame=Algorithms.translation('z',1)*Algorithms.rotation('x',pi/4);
%box.Frame=Algorithms.translation('zx',[0.3 0.4]);
A=box.CurrentVertices';

%%
[pk,d,Ak]=Algorithms.GJKOrigin2Set(A);

fprintf('\nClosest Distance:\n')
disp(d)

fprintf('\nClosest Point:\n')
disp(pk)

fprintf('\nResulting Affinely independent subset of A:\n')
disp(Ak)