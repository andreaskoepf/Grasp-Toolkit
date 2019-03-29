%% Demo Code


figs(1)=figure(1);
s=Solid('middleA')';
axis(s.AxisLimits)

%% Animating Solid Along Z Axis
for n=linspace(0,8*pi,80);
    s.drive(Solid.rotation('z',n));
end

%% Animating Solid Along X Axis with a changing radious
axis(2*s.AxisLimits)
for n=linspace(0,8*pi,80);
    s.drive(Solid.rotation('y',pi/4)*Solid.rotation('x',n)*Solid.translation('y',n/6));
end

%% Creating Multiple Solids
sizes=[3 2 5 3.2];
colors='rgby';
s2(5)=Solid('sphere',4*[1 1 1]);

for n=1:4;
    s2(n)=Solid(s2(5));
    s2(n).resize(sizes(n)*[1 1 1]);
    s2(n).Color=colors(n);
end

s2(1).shift(Solid.translation('x',6));
s2(2).shift(Solid.translation('xz',[-5 -4]));
s2(3).shift(Solid.translation('z',7));
s2(4).shift(Solid.translation('y',4));
figs(2)=figure(2);
axis(0.6*[-15 15 -15 15 -15 15])
s2';

%% Animating Solids simultaneously
figure(figs(2));
axis(0.6*[-15 15 -15 15 -15 15])
for n=linspace(0,8*pi,80);
    s2(3).Frame=Solid.rotation('yx',[-pi/4 n]);
    s2(1).Frame=Solid.rotation('z',-n);
    s2(5).Frame=Solid.translation('z',(-5/24)*n);
    s2(4).Frame=Solid.rotation('x',2*-n)*Solid.translation('y',5);    
    s2';
    
end

%% Animating all objects at once
figs(3)=figure(3);
s3=sum(s2)';
axis(0.6*[-15 15 -15 15 -15 15])
%%
figure(3);
axis(0.6*[-15 15 -15 15 -15 15])
for n=linspace(0,8*pi,80);
    s3.drive(Solid.rotation('z',n));    
end

%%
figure(3);
axis(0.6*[-15 15 -15 15 -15 15])
for n=linspace(0,8*pi,80);
    s3.drive(Solid.rotation('zx',[n -2*n]));    
end

%% Creating Phalanges
p(1)=Phalanx('distal');
p(1).Frame=Solid.translation('xy',[10 7]);

p(2)=Phalanx('middle');
p(2).Frame=Solid.translation('z',-6);

p(3)=Phalanx('proximal');
p(3).Frame=Solid.translation('xyz',[-10 -7 -10]);

%% Displaying Phalanx
figs(4)=figure(4);
p';

%% Creating Fingers
f(1)=Finger([5 4 2]);
f(1).Base=Solid.translation('x',6);

f(2)=Finger([5 3 3 2],'index3');

f(3)=Finger([4 7 3]);
f(3).Base=Solid.translation('x',-6);


%% Displaying Fingers
figs(5)=figure(5);
f';
axis([-10 10 -15 5 -10 10])
%% creating joint data
jointvar=linspace(0,pi/6,20)';

joints=[jointvar zeros(length(jointvar),1) repmat(jointvar,1,2)];

joints2=[linspace(0,-pi/12,20)' linspace(0,pi/5,20)' linspace(0,pi/6,20)' jointvar];

%% Animating fingers
f(1).drive(joints);
f(2).drive(joints);
f(3).drive(joints);

%% Translatin Base
for n=1:20;
    f(2).Base=Solid.translation('y',0.5*(-n));
    f(2)';
end
%% Animating After Translating Base
f(2).drive(joints);

%% Creating Fingers For Hand 
f2(1)=Finger([4 3 2]);
f2(2)=Finger([5 4 2.5]);
f2(3)=Finger([5 3 2]);
f2(4)=Finger([3 2 1.5]);
f2(5)=Finger([6 4 3],'thumb1');

%% Creating Hand
h=Hand(f2,[6 7 6.5 5.5],Hand.getDefault_xOffset(f2));

%% Displaying Hand
figs(6)=figure(6);
h.Base=Solid.rotation('x',-pi/4);
h';
axis([-10 10 -15 5 -10 10])

%% Animating fingers individually
axis([-10 10 -15 5 -10 10])
h.Fingers(1).drive(joints);
h.Fingers(end).drive(joints2);
h.Fingers(end-1).drive(joints);

%% Animating Palm
axis([-10 10 -15 5 -10 10])
h.drive({ctraj(rotation('x',-pi/6),rotation('x',0),30)},0)

%% Animating fingers and palm simultaneously
axis([-10 10 -15 5 -10 10])
h.drive({jtraj(zeros(1,4),[pi/6 0 pi/3 pi/3],20) jtraj(zeros(1,4),[pi/5 0 pi/3.5 pi/3],20)...
    jtraj(zeros(1,4),[-pi/12 pi/5 pi/6 pi/6],20) ...
    ctraj(rotation('x',-pi/3)...
    ,rotation('x',0),30)},[2 3 5 0])

%% Creating Non Typical Hand

f2(7)=Finger(f2(5));
f2(5)=Finger(f2(3));
f2(3)=Finger([6 7 6 5],'index3');
f2(6)=Finger([1 0.4 0.2]);

%% Creating Hand
h2=Hand(f2,[8 9 7 6 5 4],Hand.getDefault_xOffset(f2));

%%
figs(7)=figure(7);
h2.Base=Solid.rotation('x',-pi/3);
h2';

%% Animating finger individually
h2.Fingers(end-1).drive(joints);


