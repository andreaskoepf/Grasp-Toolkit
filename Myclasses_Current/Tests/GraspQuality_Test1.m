% contact locations
r=[[0;-3/2;sqrt(3)/2],...
    [0;3/2;sqrt(3)/2],...
    [3*sqrt(3)/8;0;3*sqrt(3)/4],...
    [-3*sqrt(3)/8;0;3*sqrt(3)/4]];

% contact normals
n=[[0;sqrt(3)/2;1/2],[0;-sqrt(3)/2;1/2],[-3/5;0;-4/5],[3/5;0;-4/5]];

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

xlswrite('GraspQuality_Results2',excelData,'Test1','A1');

% writing contact points
newRange = t+3;
xlswrite('GraspQuality_Results2',{'Contact Points'},'Test1',['A' num2str(newRange)])
newRange = newRange+1;
xlswrite('GraspQuality_Results2',num2cell(r),'Test1',['A' num2str(newRange)]);
newRange = newRange+6;
xlswrite('GraspQuality_Results2',{'Contact Normals'},'Test1',['A' num2str(newRange)])
newRange = newRange+1;
xlswrite('GraspQuality_Results2',num2cell(n),'Test1',['A' num2str(newRange)])
