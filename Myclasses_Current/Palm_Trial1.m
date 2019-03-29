%% creating fingers
f(1)=Finger([4 3 2]);
f(2)=Finger([5 3 2]);
f(3)=Finger([5 3 2]);
f(4)=Finger([3 2 1.5]);
f(5)=Finger([6 3 2],'index3');
f(6)=Finger([1 0.4 0.3]);
f(7)=Finger([6 4 3],'thumb3');
%%
joints=linspace(0,pi/6,40)';
joints=[joints zeros(length(joints),1) repmat(joints,1,2)];
%% creating hand
% h=Hand(f,[6 9 8 7 6],[0 2 4 6 8],1)';
h=Hand(f,[6 9 8 7 6 4],Hand.getDefault_xOffset(f));
%%

h.Base=Solid.rotation('x',-pi/3);
h';
axis([-15 15 -15 15 -10 20]);

%% setting finger joints
h.Fingers(1).CurrentJoints=[pi/6 0 pi/6 pi/6];
%%
for n=linspace(0,-pi/6,20);
    h.Base=Solid.rotation('x',n);
    h.update;
    drawnow
%    h';
end

%% driving single finger
h.Fingers(1).drive(joints);

%% driving palm and finger simultaneously
h.drive({jtraj(zeros(1,4),[pi/6 0 pi/6 pi/6],20) jtraj(zeros(1,4),[pi/6 0 pi/6 pi/6],20) ctraj(rotation('x',-pi/3)...
    ,rotation('x',0),20)},[2 3 0]);
