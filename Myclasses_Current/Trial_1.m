%% Trial 1
clc
clear classes
%%
joints=linspace(0,pi/6,100)';
joints=[joints zeros(length(joints),1) repmat(joints,1,2)];
joints2=[linspace(0,pi/6,100)' linspace(0,pi/4,100)' linspace(0,pi/3,100)'];
%%
figure(1);
f=Finger([3 3 2],'index3')';
axis([-5 5 -10 2 -2 4])
%%
f.drive(joints2);
%%
figure(1);
f(2)=Finger(1,'middle','Prototype1')';
axis([-5 5 -10 2 -4 4])

%%
p=Phalanx('middle',1);
%%
T1=eye(4)*p.Vertices;
T2=eye(4)*p.Frame;