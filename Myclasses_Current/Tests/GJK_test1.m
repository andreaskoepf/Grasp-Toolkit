% Testing GJK 
%% Creating sets
A=[-2 -1 1 1 -1;0 -1 -1 1 1]; % square with one vertex at the origin
b=[2,0]'; % vertex one unit away from upper side of square

%%
[d,v,V]=Algorithms.GJKDistance(A,b);

disp('results')
disp(d)
disp(v)
disp(V)