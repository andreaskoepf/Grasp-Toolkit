% Gilbert Johnson Keerthi Distance Algorithm
% This programs computes the shortest distance between a convex set A and
% the origin as long as the origin lies outside set A.  If the origin lies
% inside set A then a subset Ak of A that contains the origin is returned, 
% while the shortest distance and closest point are undetermine.
%   [pk,d,Ak] = GJKORIGIN2SET(A,E)
%   inputs:
%       A       :   n x m array representing a Convex Set that does 
%                   not contain the origin.
%       E       :   Error Tolerance. (optional)
%
%   ouputs:
%       pk      :   Closest point to the origin in A.     
%       d       :   Shortest Distance between convex Set A and the origin.
%                   (optional)
%       Ak      :   Subset of A consisting of affinely independent points 
%                   of set A such that pk is an affine combination of the 
%                   points in Ak.
%


function [pk,varargout]=GJKOrigin2Set(A,varargin)



% Initialization
pk=A(:,1); % initializing closest point

Ak=[]; % Subset of linearly independent points of A

d=0; %shortest distance

ClosestFound=false; 

switch nargin
    case 1
        Et=0.0001; % tolerance
    case 2
        Et=varargin{1};
end

u=0; % minimum value attainable 

NumIter=0;

while(~ClosestFound && (NumIter<20))
    
    NumIter=NumIter+1;
    w=Algorithms.SupportMapping(-pk,A);
    w=w(:,1);
        
    delta=(pk'*(w))/norm(pk); % minimum error
    
    u=max([u,delta]);
    
    ClosestFound=norm(pk)-u<Et;
    
    if(~ClosestFound)
        
        % Distance of minimum norm algorithm
        
        if(size(Ak,2)<=size(Ak,1))
            Ak=[Ak w];
        else
            Ak(:,end)=w;
        end
        
        Akr=Ak;
        %fprintf('\nIteration# %i\n',NumIter)
        
        %fprintf('\nSimplex Ak\n')
        %disp(Ak)
        
        
        if(size(Akr,2)~=1)
            
            NumIter2=0;
            ShiftCounter=0;
            while(NumIter2<=20)
                
                NumIter2=NumIter2+1;
                
                %fprintf('\nInternal Iteration #%i\n',NumIter2)
                % forming Matrix M and column m
                nRows=size(Akr,2)-1;
                nColumns=size(Akr,2);
                M=zeros(nRows,nColumns);
                m=zeros(nRows,1);
                
                for nr=2:nRows+1;
                    for nc=1:nColumns;
                        M(nr-1,nc)=dot(Akr(:,nr)-Akr(:,1),Akr(:,nc));
                    end
                    
                    %m(nr-1,1)=dot(Akr(:,nr)-Akr(:,1),b);
                end
                
                G=[ones(1,nColumns);M];
                h=[1;m];
                
                %fprintf('Coefficient Matrix:\n')
                %disp(G)
                
                %fprintf('\nColumn Vector\n')
                %disp(h)
                
                if(rank(G)~=size(G,1))
                    ShiftCounter=ShiftCounter+1;
                    %fprintf('\nMatrix not full rank. Continue with next iteration\n')
                    Akr=circshift(Akr,[0 -1]);
                    
                    %disp(Akr)
                    if(ShiftCounter<nColumns)
                        
                        
                        continue;
                    else
                        
                        ShiftCounter=0;
                        
                    end
                        
                end
                
                % solving for coefficients
                x=G\h;
                
                %fprintf('\nCoefficients\n')
                %disp(x)
                
                indexes=x>1e-6; % elements to retain from Akr
                
                if(all(indexes))
                    
                    % all coefficients obey the affine combination
                    % and sign conditions
                    pk=sum(repmat(x',size(Akr,1),1).*Akr,2);
                    %rk=b-pk;
                    Ak=Akr;
                    break;
                else
                    if(sum(indexes)>1)
                        % eliminates the points corresponding to 
                        % the values of x that are less than 0  
                        Akr=Akr(:,indexes);
                    elseif(sum(indexes)==1)
                        pk=Akr(:,indexes);
                        %rk=b-pk;
                        Ak=Akr(:,indexes);
                        
                        break;
                    else
                        %pivot matrix Ak
                        Akr=circshift(Ak,[0 -1]);
                    end
                    
                end
                
            end
            
            
        else
            pk=Akr;
            %rk=b-pk;
        end
        
    end
    d=norm(pk);
end


switch nargout
    case 2
        
        varargout{1}=d;
        
    case 3
        
        varargout{1}=d;
        varargout{2}=Ak;
        
    otherwise
        
        varargout{1}=d;
        varargout{2}=Ak;
        
end

end