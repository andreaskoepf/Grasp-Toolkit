%% 
s=Solid(Toolkit.createToolkitPath('Full_hand - Palm-1.STL'));

%%
figure(1);
s(end)';
axis([-8 8 -8 8 -8 8])
%%
points=100;
%%
tic
for n=linspace(0,4*pi,points);
    rotate(s.GraphicsHandle,[1 0 0],n);
    drawnow
end
disp(toc)
%%
t=zeros(4,4,points);
for n=1:points;
    t(:,:,n)=Solid.rotation('x',(4*pi/points)*(n-1));
end
%%
tic
s.drive(t)
disp(toc)