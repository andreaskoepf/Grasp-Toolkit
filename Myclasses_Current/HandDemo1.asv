% creating hand
h = Hand('ThreeFingerHand');
h.PalmObject.Color = [0 0 1];

%%
for n = 1:3;
    
    h.Fingers(n).JointValues = [pi/10 pi/2 pi/4];
    h.Fingers(n).Color = 'y';
    
end

%%
figure(1);
h';

%%
h2 = Hand('RowdyHand');

%%
h2.PalmObject.Color = [1 1 1];
h2.Frame = rotation('y',-pi/4);
for n = 1:3;
    
    h2.Fingers(n).JointValues = [0 0 pi/6 0];
    h2.Fingers(n).Links(end).Color = [0 0 1];
end
h2.Fingers(2).JointValues = [pi/6 0 pi/6 0];
h2.Fingers(3).JointValues = [pi/3 0 pi/6 pi/6];
h2.Fingers(end).JointValues = [0 pi/10 pi/6 pi/6];

%%
figure(2);
h2';

%% Creating Hand and joint data
h4=Hand('Prototype1');
%%
jointvar=linspace(0,pi/6,20)';
joints=[zeros(length(jointvar),1) jointvar repmat(jointvar,1,2)];
joints2=[linspace(0,-pi/12,20)' linspace(0,pi/5,20)' linspace(0,pi/6,20)' jointvar];

%% Animating Hand
figure(4);
axis([-5 20 -15 5 -10 10])
h4';

%%
%while(true)
h4.Fingers(1).drive(joints2')
h4.Fingers(2).drive(jtraj(zeros(1,4),[0 pi/3 pi/10 pi/6],20)')
h4.drive({jtraj(zeros(1,4),[0 pi/3 pi/10 pi/6],20) jtraj(zeros(1,4),[0 pi/6 pi/3.5 pi/3],20)...
    jtraj(zeros(1,4),[0 -pi/10 pi/5 pi/6],20) jtraj(zeros(1,4),[0 pi/6 pi/3 pi/3],20) ...
    jtraj(zeros(1,4),[0 pi/6 pi/5 pi/3],20) ctraj(rotation('x',-pi/3)...
    ,rotation('x',0),30)},[1 2 5 4 3 0])
%end
