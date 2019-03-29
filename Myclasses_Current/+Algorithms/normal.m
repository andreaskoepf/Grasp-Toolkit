% Normal vector in N dimensional space
% This program computes the normal vector in N dimensional space to a set
% A which contains sufficient points such that an (N-1) manifold ((N-1) 
% unique vectors)can be formed .  Then, the normal vector n should be 
% perpendicular to each vector in the manifold.
%   [n,M] = NORMAL(A)
%   inputs:
%       A       :   n x m array representing a Set of m points in n
%                   dimensional space.
%   outputs:
%       n       :   n x 1 column vector that represents a normal vector to
%                   an (n-1) manifold M of vectors formed from points in 
%                   the input set A.
%       M       :   n x n-1 array representing a Set of n-1 vectors in N 
%                   dimensional space that is normal to n. (optional) 

function [n,varargout]=normal(A)

nPoints=size(A,2); % number of points
nDimensions=size(A,1); % number of dimensions

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
        
        V=circshift(A,[0 shiftDim])-A;
        
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

shiftSign=1;
for ni=1:nDimensions;
    
    rows=1:nDimensions;
    rows(ni)=[];
    n(ni,1)=shiftSign*det(M(rows,:));
    shiftSign=-shiftSign;
    
end

switch nargout
    case 2
        varargout{1}=M;
end

end
