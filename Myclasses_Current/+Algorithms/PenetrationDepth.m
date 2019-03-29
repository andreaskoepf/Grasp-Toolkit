% Penetration Depth
% This is an implementation of the Penetration Depth algorithm using a method that
% finds the closest distance from the origin to a set A as long as the 
% origin is contained in A.  At each iteration, it expands a current
% polytope that contains the origin by adding a vertex w which is a support
% point for the closest point to the origin in the current polytope. 
%   [pk,d,pltp] = PenetrationDepth(A,E)
%   inputs:
%       A       :   n x m array representing a Convex Set that contains the
%                   origin.
%       E       :   Error Tolerance. (optional)
%
%   ouputs:
%       pk      :   Closest point to the origin in A.     
%       d       :   Shortest Distance between convex Set A and the origin.
%                   (optional)
%       pltp    :   Struct with fields "vertices" and "faces" contain the
%                   corresponding vertices and faces arrays that define the
%                   n - dimensional expanded polytope. (optional)
%

function [pk,varargout]=PenetrationDepth(A,varargin)


% Initialization
[v_,d_,Ak] = Algorithms.GJKOrigin2Set(A); % Initial polytope that contains
tic                                        % the origin
MaxVertices=100; % maximum number of vertices allowed in expanded polytope
CurrentVertices=size(Ak,2); % Current Number of vertices in expanded polytope
Dimensions = size(Ak,1);

% initializing polytope
P=sparse(Dimensions,MaxVertices);
P(:,1:CurrentVertices)=Ak;

% determining if polytope contains the minimum number of vertices.
% initial polytope must be an ( n - simplex) 
RequiredVertices=Dimensions+2;


% adding additional vertices to starting polytope that contains the origin
if(CurrentVertices<RequiredVertices)
    
    % number of possible unique combination of two elements of Ak
    nCombinations=prod(CurrentVertices-1:CurrentVertices)/prod(1:2);
    
   
    
    % determining if there can be obtained at least n-1 combinations of Ak
    % that would allow computing a well defined normal vector.
    if(CurrentVertices<RequiredVertices-2 || nCombinations<Dimensions-1 )
        
        % constructing n dimensional basis
        e=eye(Dimensions);
        
        n=0;
        while(CurrentVertices<RequiredVertices-2 || nCombinations<Dimensions-1)
            
            n=n+1;
            
            % computing support point in the direction of basis vector
            w=Algorithms.SupportMapping(e(:,n),A);
            
            % adding points from the n dimensional basis that do not belong
            % to the set.
            if(~any(all(full(P(:,1:CurrentVertices))==repmat(w(:,1),1,CurrentVertices),1)))
                
                CurrentVertices=CurrentVertices+1;                
                P(:,CurrentVertices)=w(:,1);
                nCombinations=prod(CurrentVertices-1:CurrentVertices)/prod(1:2);
                
            end
            
            
        end
        
        As=full(P(:,1:CurrentVertices));
    
    else
        
        As=full(P(:,1:CurrentVertices));
        
    end
    
    % computing normal vector to set As    
    norml=Algorithms.normal(As);
    
    % computing support points
    w1=Algorithms.SupportMapping(norml(:,1),A);
    w2=Algorithms.SupportMapping(-norml(:,1),A);
    
    % gathering all support points
    w=[w1 w2];
        
%     fprintf('\nAdding Support Points w:\n')
%     disp(w)
    
    % adding point to Polytope
    nPointsAdded=size(w,2);
    P(:,CurrentVertices+1:CurrentVertices+nPointsAdded)=w;
    CurrentVertices=CurrentVertices+nPointsAdded;
    
 
    
    
end
        

%pk=0; % closest point in a facet of P to the origin


switch nargin
    case 1
        Et=0.000001; % tolerance
    case 2
        Et=varargin{1};
end

NumIter=0;

while(NumIter<100)
    
    NumIter=NumIter+1;
    d=0;
    %fprintf('\n ________________________________________________________')
    %fprintf('\n _____________________ Iteration %i _____________________',NumIter)
    %fprintf('\n ________________________________________________________\n')

    
    % constructing faceted geometry
    switch Dimensions
    case {2 3 4}
        K=convhulln(full(P(:,1:CurrentVertices))',{'Qt'});
    otherwise 
        K=convhulln(full(P(:,1:CurrentVertices))',{'Qt','Qx'});
    end
    
    % computing minimum distance dmin for each facet in the convex set P
    % which contains the origin
    nfacets=size(K,1);
    npoints=size(K,2);
    for n=1:nfacets;
        
        % building matrices M and m
        %fprintf('\n _________________ Distance to facet %i _________________\n',n)
        M=zeros(npoints-1,npoints);
        m=zeros(npoints-1,1);
        
        nRows=npoints-1;
        nColumns=npoints;
        for nr=1:nRows;
            
            % obtaining consecutive points in a facet
            pa=P(:,K(n,nr));
            pb=P(:,K(n,nr+1));
            
            for nc=1:nColumns;                
                
                M(nr,nc)=dot(pb-pa,P(:,K(n,nc)));
                
            end
            
        end
        
        % constructing linear system
        G=[ones(1,nColumns);M];
        h=[1;m];
        
        %fprintf('Coefficient Matrix:\n')
        %disp(G)
        
        %fprintf('\nColumn Vector\n')
        %disp(h)
        
        if(rank(G)==size(G,1))
            x=G\h;
            
            %fprintf('\nCoefficients\n')
            %disp(x)
            
        end
        
        
        % verifying that all x are positive
        if(all(x>=0))
            pkmin=sum(repmat(x',npoints,1).*P(:,K(n,:)),2);
            dmin=norm(pkmin);
            
            %fprintf('\nCurrent Points on the %ith facet\n',n)
            %disp(full(P(:,K(n,:))))
            
            %fprintf('\nCurrent Minimum point of the %ith facet\n',n)
            %disp(full(pkmin))
            
            %fprintf('\nCurrent Minimum distance of the %ith facet\n',n)
            %disp(dmin)
            
            if(d==0)
                d=dmin;
                pk=pkmin;
                %fprintf('\nEntered\n')
            else
                
                if(dmin<d)
                    d=dmin;
                    pk=pkmin;
                end
                
            end
            
            %fprintf('\nCurrent Minimum point of the current polytope\n')
            %disp(full(pk))
            
            %fprintf('\nCurrent Minimum distance of the current polytope\n')
            %disp(d)
            
        end
        
    end
        
        
    % computing new support point
    w=Algorithms.SupportMapping(pk,A);
    w=w(:,1);
    
    % minimum distance allowed
    delta=dot(pk/d,w); 
    
    ClosestFound= delta-d <= Et;
    if(ClosestFound)
        break
    else
        
        % expanding polytope
        CurrentVertices=CurrentVertices+1;
        P(:,CurrentVertices)=w;
    end
    
end

% fprintf('\n _________________________results________________________\n')
% fprintf('\nTotal Time:\n')
% disp(toc)
% 
% fprintf('\nNumber of Iterations:\n')
% disp(NumIter)
% 
% fprintf('\nClosest Distance:\n')
% disp(d)
% 
% fprintf('\nClosest Point:\n')
pk=full(pk);
% disp(pk)
% 
% fprintf('\nExpanded Polytope P subset of A that contains the origin:\n')
Ak=full(P(:,1:CurrentVertices));
% disp(Ak)
% 
% fprintf('\nFacets of expanded polytope P\n')
% disp(size(K,1))



switch nargout
    case 2
        
        varargout{1}=d;
        
    case 3
        
        varargout{1}=d;
        
        expdPolytope=struct('vertices','faces');
        expdPolytope.vertices=Ak;
        expdPolytope.faces=K;
        varargout{2}=expdPolytope;
        
    otherwise
        
        varargout{1}=d;
        expdPolytope=struct('vertices','faces');
        expdPolytope.vertices=Ak;
        expdPolytope.faces=K;
        varargout{2}=expdPolytope;
        
end

end