clear classes 
clc
%%
figure(2);
s(1)=Solid('huacha4');
s(2)=Solid(s(1));
s(2).resize(s(2).Dimensions/2)';
s(2).shift(translation('y',-4))';
s(3)=shift(Solid(s(2)),translation('y',-4));
s';
%%
figure(3);
s2=s(2)+s(1);
s2';
%%
s2.drive(rotation('x',pi/4));
s(1).drive(rotation('x',pi/4));
%%
figure(4);
S=sum(s)'
S.drive(rotation('x',pi/4));


