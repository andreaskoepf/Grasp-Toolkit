%% computing analytical results
% this test uses the contact points that result from the Three finger hand
% and sphere grasp. see 'CollisionValidationeTest.m'

% parameters
angle = linspace(0,4*pi/3,3);

linkLength = 10;
linkWidth = 1;
radius = linkLength*(0.5 + sqrt(2)*0.5) - 0.5*linkWidth;

% contact points
r = ones(3,10);

% contact normals
n = ones(3,10);

% creating contact points in world coordinates
p = ones(4,3);
for n1 = 1:3;
    p(1:3,1) = [radius*sqrt(2)*0.5;0;radius*sqrt(2)*0.5];
    p(1:3,2) = [radius;0;0];
    p(1:3,3) = [radius*sqrt(2)*0.5;0;-radius*sqrt(2)*0.5];
    
    p = Algorithms.rotation('z',angle(n1))*p;
    
    r(:,1+3*(n1-1):3*(n1)) = p(1:3,:);
    
    n(:,1+3*(n1-1):3*(n1)) = [-r(:,1+3*(n1-1))/norm(r(:,1+3*(n1-1))) -r(:,2+3*(n1-1))/norm(r(:,2+3*(n1-1)))...
        -r(:,3*(n1))/norm(r(:,3*(n1)))];   
    
    
    
end

% adding contact due to palm
r(:,10) = [0;0;radius];
n(:,10) = [0;0;-1];
%% setting friction cone discretization parameters
% translational and torsional friction coefficients
friction=[0.2];

% contact model
contact='PCF';

% resolution
%resolution=[7 4];
resolution=[4 6 8 9 12];

% setting tolerance
tolerance = 0.000001;

%wsize=2*resolution(1)*resolution(2)-resolution(1)+2;

% inserting field names to excel data cell array
excelData  ={'Resolution Per Contact','Depth','Number Iterations','Total Time (seconds)','Number EP Facets','Contact Model','Tolerance','Friction','WS Vertices','WS Facets'};
for t = 1:size(resolution,2);
    % constructing wrench space
    W=zeros(6,resolution(t)*size(r,2));
    
    for n1=1:size(r,2);
        W(:,1+resolution(t)*(n1-1):resolution(t)*n1)=Algorithms.FrictionConeDiscretization(n(:,n1),r(:,n1),contact,friction,eye(4),resolution(t));
    end
    W=[zeros(6,1) W]';
    % obtaining convex hull
    indices=convhulln(W,{'Qt','Qx'});
    K=unique(reshape(indices,size(indices,2)*size(indices,1),1));
    WC=W(K,:)';
    
    %
    % Using Penetration Depth to obtain the closest point in the Wrench space
    % to the origin
    [d,resultDetails]=Algorithms.PenetrationDepthShow(WC,tolerance);
    
    fprintf('\nTotal Time:\n')
    disp(resultDetails.TotalTime)
    
    fprintf('\nClosest Point:\n')
    disp(resultDetails.ClosestPoint)
    
    fprintf('\nClosest Distance:\n')
    disp(resultDetails.PenetrationDepth)
    
    fprintf('\nResulting expanded polytope subset of A:\n')
    disp(resultDetails.ExpandedPolytope.vertices)
    
    % constructing excel data
    
    excelData(t+1,:)={resolution(t) resultDetails.PenetrationDepth resultDetails.NumberOfIterations ...
        resultDetails.TotalTime,resultDetails.NumFacetsOfExpandedPolytope,contact,tolerance,friction,size(WC,2),size(indices,1)};

end
%% writing to excel document

xlswrite('GraspQuality_Results',excelData,'Test3','A1');

% writing contact points
newRange = t+3;
xlswrite('GraspQuality_Results2',{'Contact Points'},'Test3',['A' num2str(newRange)])
newRange = newRange+1;
xlswrite('GraspQuality_Results2',num2cell(r),'Test3',['A' num2str(newRange)]);
newRange = newRange+6;
xlswrite('GraspQuality_Results2',{'Contact Normals'},'Test3',['A' num2str(newRange)])
newRange = newRange+1;
xlswrite('GraspQuality_Results2',num2cell(n),'Test3',['A' num2str(newRange)])