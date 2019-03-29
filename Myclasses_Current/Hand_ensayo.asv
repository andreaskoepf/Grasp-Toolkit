% Hand Demo

%% Creating Hand and joint data
h=Hand('Prototype1B')';
%%
jointvar=linspace(0,pi/6,20)';
joints=[zeros(length(jointvar),1) jointvar repmat(jointvar,1,2)];
joints2=[linspace(0,-pi/12,20)' linspace(0,pi/5,20)' linspace(0,pi/6,20)' jointvar];

%% Animating Hand
figure(1);
axis([-5 20 -15 5 -10 10])
h';

%%
%while(true)
h.Fingers(1).drive(joints2')
h.Fingers(2).drive(jtraj(zeros(1,4),[0 pi/3 pi/10 pi/6],20)')
h.drive({jtraj(zeros(1,4),[0 pi/3 pi/10 pi/6],20) jtraj(zeros(1,4),[0 pi/6 pi/3.5 pi/3],20)...
    jtraj(zeros(1,4),[0 -pi/10 pi/5 pi/6],20) jtraj(zeros(1,4),[0 pi/6 pi/3 pi/3],20) ...
    jtraj(zeros(1,4),[0 pi/6 pi/5 pi/3],20) ctraj(rotation('x',-pi/3)...
    ,rotation('x',0),30)},[1 2 5 4 3 0])
%end

%% Adding object
s=Solid('link1.stl');
s';
s.Color='b';
s.scale(2);
%%
s.Frame=Solid.translation('xyz',[-6 -9 -8])*Solid.rotation('y',-pi/6)*Solid.rotation('z',-pi/4);
s';

