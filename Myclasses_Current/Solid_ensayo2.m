figure(1);
s=Solid('sphere')';
axis([-4 4 -4 4 -4 4])
%% animating sphere
for n=linspace(0,8*pi,200);
    s(1).drive(Solid.rotation('z',n)*Solid.translation('x',2));
end

%% 
figure(2);
s(2)=Solid(s(1));
s(2).reducePatch(0.2)';
axis([-4 4 -4 4 -4 4])
%% animating after reducing patches
for n=linspace(0,8*pi,200);
    s(2).drive(Solid.rotation('z',n)*Solid.translation('x',2));
end

