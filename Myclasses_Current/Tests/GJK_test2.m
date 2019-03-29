% GJK algorithm ensayo
%% Inputs
A=[-1 1 1 -1;-1 -1 1 1];
b=[-2;-2];
[pk,d,Ak]=Algorithms.GJKPoint2Set(b,A);

fprintf('\nClosest Distance:\n')
disp(d)

fprintf('\nClosest Point:\n')
disp(pk)

fprintf('\nResulting Affinely independent subset of A:\n')
disp(Ak)

%% Inputs :  hexagon
A=zeros(2,6);
b=[-2;2];
%building A
r=1; % inner segment length
for n=1:6;
    A(:,n)=[r*cos((n-1)*pi/3);r*sin((n-1)*pi/3)];
end

[pk,d,Ak]=Algorithms.GJKPoint2Set(b,A);

fprintf('\nClosest Distance:\n')
disp(d)

fprintf('\nClosest Point:\n')
disp(pk)

fprintf('\nResulting Affinely independent subset of A:\n')
disp(Ak)

%% Inputs: box
box=Box;
A=box.CurrentVertices';

b=[1.2;-0.3;-1];

[pk,d,Ak]=Algorithms.GJKPoint2Set(b,A);

fprintf('\nClosest Distance:\n')
disp(d)

fprintf('\nClosest Point:\n')
disp(pk)

fprintf('\nResulting Affinely independent subset of A:\n')
disp(Ak)


