
%% Creating Hand and joint data
h=Hand('Prototype1')';

jointvar=linspace(0,pi/6,20)';
joints=[zeros(length(jointvar),1) jointvar repmat(jointvar,1,2)];
joints2=[linspace(0,-pi/12,20)' linspace(0,pi/5,20)' linspace(0,pi/6,20)' jointvar];

%% driving palm and finger simultaneously
h.drive({jtraj(zeros(1,4),[-pi/6 0 pi/6 pi/6],20) jtraj(zeros(1,4),[pi/6 0 pi/6 pi/6],20) ctraj(rotation('x',-pi/3)...
    ,rotation('x',0),30)},[1 5 0]);

%%
h.drive({ctraj(rotation('x',-pi/6),rotation('x',0),30)},0)





% for n=1:1000;
%     t2=rMatrix*s(2).Vertices;
% end
% 
% for n=1:1000;
%     t1=rMatrix*s(1).Vertices;
% end

