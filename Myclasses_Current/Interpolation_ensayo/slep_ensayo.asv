% attempt to implement SLERP (spherical interpolation)
%% creating link
link=Link('Prototype1_Index_Link2_1DOF');
link2 = Link('Prototype1_Index_Link2_1DOF');
link2.Color = 'y';
link3 = Link('Prototype1_Index_Link2_1DOF');

%% initializing motion parameters
theta0=0;
thetaf = pi/2;
link.JointValues = theta0;
startTransform=link.Transform;
link.JointValues = thetaf;
endTransform = link.Transform;

%% displaying link
figure(1);
axis(4*[-1 1 -1 1 -1 1])
link';

%% showing link at start
link.Frame = startTransform;
link';

%% showing link at end
link.Frame = endTransform;
link';


%% computing position slerp
% creating time values
interpResolution = 20;

% obtaining initial and final quaternion
Q0=Algorithms.transform2quatern(startTransform);
Qf=Algorithms.transform2quatern(endTransform);
Q0_inv = [-Q0(1:3) Q0(4)]/norm(Q0);

% obtaining initial and final positions
p0 = startTransform(1:3,4);
pf = endTransform(1:3,4);

% storing arc
arc = zeros(interpResolution,3);
arcJoints = zeros(interpResolution,3);


t = linspace(0,1,interpResolution);

% computing interpolation
theta = thetaf - theta0;
qTheta = acos(Q0*Qf');
interpTransforms = zeros(4,4,interpResolution);
for n=1:interpResolution
    a = sin((1-t(n))*(theta))/sin(theta);
    b = sin(t(n)*theta)/sin(theta);
    % rotation
    %q = a*Q0 + b*Qf;
    q = (1-t(n))*Q0 + t(n)*Qf;
    %q=Q0*((Q0_inv*Qf')^t(n));
    
    %disp(q)
    %disp(Algorithms.quatern2transform(q))
    
    % normalizing quaternion
    q= q/norm(q);
    
    % position
    p = a*p0 + b*pf;
    
    %p = (1-t(n))*p0 + t(n)*pf;
    
    % storing orientation and position results        
    interpTransforms(:,:,n) = Algorithms.quatern2transform(q);
    interpTransforms(1:3,4,n) = p;
    
    % storing arc
    arc(n,:) = p';
    
    %interpTransforms(:,:,n) = Solid.translation('xyz',p')*Algorithms.quatern2transform(q);
end

%% animating through interpolated transforms
figure(1);
axis(4*[-1 1 -1 1 -1 1])
link';
%link2';
interpTheta = linspace(theta0,thetaf,interpResolution);
for n=1:interpResolution;
    link.Frame=interpTransforms(:,:,n);
    link.update;
    link2.JointValues = interpTheta(n);
    arcJoints(n,:) = link2.Transform(1:3,4)';
    
    %link2.JointValues = interpTheta(n);
    %link2.Frame = link2.Transform;
    %link2.update;
    drawnow;
end

%% animating comparing to another link animated in the regular way

figure(2);
axis(4*[-1 1 -1 1 -1 1])
link3';
link2';
interpTheta = linspace(theta0,thetaf,interpResolution);
for n=1:interpResolution;
    link3.Frame=interpTransforms(:,:,n);
    link3.update;
    link2.JointValues = interpTheta(n);
    arcJoints(n,:) = link2.Transform(1:3,4)';
    
    link2.JointValues = interpTheta(n);
    link2.Frame = link2.Transform;
    link2.update;
    drawnow;
end

%% 
link.drive(linspace(theta0,thetaf,20));

%% ploting arcs
figure(4);
plot3(arc(:,1),arc(:,2),arc(:,3),'Color','b','LineWidth',5)
hold on
plot3(arcJoints(:,1),arcJoints(:,2),arcJoints(:,3),'Color','r','LineWidth',2)

daspect([1 1 1])
%plot3(arc(:,1),arc(:,2),arc(:,3),'k',arcJoints(:,1),arcJoints(:,2),arcJoints(:,3),'b')
    
    






