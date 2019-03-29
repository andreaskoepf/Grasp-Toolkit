% this program will attempt to generate a normal vector in n dimensional
% space

% It's required to provide an (N-1) manifold ( a line in 2-D, a surface in
% 3_D, a volume in 4-D) or (N-1) edge vectors in order to have a well
% defined normal vector

[v,d,Ak] = Algorithms.GJKOrigin2Set(A);
%%
% verifying that initial manifold contains the minimum number of points

nPoints=size(Ak,2); % number of points
nDimensions=size(Ak,1); % number of dimensions

nEdges=nDimensions-1; % number of required edges

% determining maximum number of unique combinations of point pairs of M in
% order to form (N-1) required edges.

nCombinations=prod(nPoints-1:nPoints)/prod(1:2);

if(nCombinations>=nEdges) 
    % combine points pairs in M to form unique edges 
    
    M=zeros(nDimensions,nEdges); % initializing manifold
    
    nCollected=0; % number of vectors collected in M
    nRemain=nEdges; % number of remaining vectors to collect into manifold M
    shiftDim=-1;
    
    while(nRemain > 0)
        
        V=circshift(Ak,[0 shiftDim])-Ak;
        
        if(nPoints>=nEdges)
            M=V(:,1:nEdges);
            break;
        else
            if(nCollected+nPoints>nEdges)
                M(:,nCollected+1:end)=V(:,1:nEdges-nCollected);
            else
                M(:,nCollected+1:nCollected+nPoints)=V;
            end
            nCollected=nCollected+nPoints;
            nRemain=nEdges-nCollected;
            shiftDim=-1+shiftDim;
        end
    end
else
    error('An (N-1) manifold of (N-1) vectors can not be formed with the provided number of points')
end

% computing determinant of submatrices of M in order to obtain components
% of the normal vector
n=zeros(nDimensions,1);
% shiftSign=1;
% for ni=1:nPoints;
%     
%     rows=1:nPoints;
%     rows(ni)=[];
%     n(ni,1)=shiftSign*det(M(rows,:));
%     shiftSign=-shiftSign;
%     
% end

shiftSign=1;
for ni=1:nDimensions;
    
    rows=1:nDimensions;
    rows(ni)=[];
    n(ni,1)=shiftSign*det(M(rows,:));
    shiftSign=-shiftSign;
    
end


fprintf('\nThe normal vector n to the (N-1) manifold is:\n')
disp(n);
    
    
        



