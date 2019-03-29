%% building and testing link 
l2(1)=Link('Prototype1_Middle_Link3_2DOF');
l2(1)';
axis(2*[-3 3 -3 3 -3 3])
l2(1).drive([linspace(0,pi/2,100);linspace(0,0,100)])

l2(1).drive([linspace(0,0,100);linspace(0,pi/2,100)])

%% building and testing link 
l2(2)=Link('Prototype1_Middle_Link2_1DOF');
l2(2)';
axis(2*[-3 3 -3 3 -3 3])
l2(2).drive(linspace(0,pi/2,100))

%% building and testing link 
l3(1)=Link('Prototype1_Pinky_Link3_2DOF');
l3(1)';
axis(2*[-3 3 -3 3 -3 3])
l3(1).drive([linspace(0,pi/2,20);linspace(0,0,20)])

l3(1).drive([linspace(0,0,100);linspace(0,2*pi,100)])

%% building and testing link 
l3(2)=Link('Prototype1_Pinky_Link2_1DOF');
l3(2)';
axis(2*[-3 3 -3 3 -3 3])
%%
l3(2).drive(linspace(0,pi/2,100))

%% building and testing link 
l4(1)=Link('Prototype1_Thumb_Link3_2DOF');
l4(1)';
axis(2*[-3 3 -3 3 -3 3])
l4(1).drive([linspace(0,pi/2,20);linspace(0,0,20)])

l4(1).drive([linspace(0,0,100);linspace(0,2*pi,100)])
%% building and testing link 
l4(2)=Link('Prototype1_Thumb_Link2_1DOF');
l4(2)';
axis(2*[-3 3 -3 3 -3 3])
l4(2).drive(linspace(0,pi/2,100))

%% building and testing finger
f(1)=Finger('Prototype1_Index_4DOF');
%%
f(1).BaseFrame=Solid.translation('xz',[0 4]);
f(1)';

axis(2*[-3 3 -3 3 -3 3])
%%
f(1).drive([linspace(0,0,20);linspace(0,pi/4,20);linspace(0,pi/4,20);linspace(0,pi/4,20)])


%% building and testing finger
f(2)=Finger('Prototype1_Middle_4DOF');
%%
f(2).BaseFrame=Solid.translation('xz',[0 4]);
f(2)';

axis(2*[-3 3 -3 3 -3 3])
%%
f(2).drive([linspace(0,pi/2,20);linspace(0,pi/4,20);linspace(0,pi/4,20);linspace(0,pi/4,20)])

%% building and testing finger
f(3)=Finger('Prototype1_Pinky_4DOF');
%%
f(3).BaseFrame=Solid.translation('xz',[0 4]);
f(3)';

axis(2*[-3 3 -3 3 -3 3])
%%
f(3).drive([linspace(0,0,20);linspace(0,pi/4,20);linspace(0,pi/4,20);linspace(0,pi/4,20)])

%% building and testing finger
f(4)=Finger('Prototype1_Ring_4DOF');
%%
f(4).BaseFrame=Solid.translation('xz',[0 4]);
f(4)';

axis(2*[-3 3 -3 3 -3 3])
%%
f(4).drive([linspace(0,pi/2,20);linspace(0,pi/4,20);linspace(0,pi/4,20);linspace(0,pi/4,20)])

%% building and testing finger
f(5)=Finger('Prototype1_Thumb_4DOF');
%%
f(5).BaseFrame=Solid.translation('xz',[0 4]);
f(5)';

axis(2*[-3 3 -3 3 -3 3])
%%
f(5).drive([linspace(0,0,20);linspace(0,pi/4,20);linspace(0,pi/4,20);linspace(0,pi/4,20)])
%%
h=Hand('Prototype1');
h';

jointvar=linspace(0,pi/6,20)';
joints=[zeros(length(jointvar),1) jointvar repmat(jointvar,1,2)];
joints2=[linspace(0,-pi/12,20)' linspace(0,pi/5,20)' linspace(0,pi/6,20)' jointvar];

%% Animating Hand
axis(5+[-10 10 -15 5 -15 5])
h(1).drive({jtraj(zeros(1,4),[0 pi/3 pi/10 pi/6],20) jtraj(zeros(1,4),[0 pi/6 pi/3.5 pi/3],20)...
    jtraj(zeros(1,4),[pi/6 0 pi/5 pi/6],20) jtraj(zeros(1,4),[0 pi/6 pi/3 pi/3],20) ...
    jtraj(zeros(1,4),[0 pi/6 pi/5 pi/3],20) ctraj(rotation('x',-pi/3)...
    ,rotation('y',0),30)},[1 2 5 4 3 0])


