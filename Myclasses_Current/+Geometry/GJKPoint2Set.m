% Gilbert Johnson Keerthi Distance Algorithm
% This programs computes the shortest distance between a point b and a
% convex set A
% point B and a convex compact set A
%   [pk,d,Ak] = GJKPOINT2SET(b,A,E)
%   inputs:
%       b       :   n x 1 array representing a point in n dimensional
%                   space.
%       A       :   n x m array representing a Convex Set.        
%       E       :   Error Tolerance. (optional)
%
%   ouputs:
%       pk      :   Closest point to b in A.     
%       d       :   Shortest Distance between convex Set A and point b.
%                   (optional)
%       Ak      :   Subset of A consisting of affinely independent points 
%                   of set A such that pk is an affine combination of the 
%                   points in Ak.
%       

function [pk,varargout]=GJKPoint2Set(b,A,varargin)



% Initialization
rk=b; % vector that goes from b to closest point in set A pk(b,A)
pk=zeros(size(b));
d=norm(rk);

Ak=[]; % Subset of linearly independent points of A

ClosestFound=false; 

switch nargin
    case 2
        E=0.0001; % tolerance
    case 3
        E=varargin{1};
end

u=0; % minimum value attainable 

NumIter=0;
while(~ClosestFound && ~all(rk==0) && (NumIter<20))
%while(~ClosestFound && (NumIter<20))    
    NumIter=NumIter+1;
    w=Algorithms.SupportMapping(rk,A);
    w=w(:,1);
        
    delta=(-rk'*(w-b))/norm(rk); % minimum error
    %delta=norm(b-w);
    
    u=max([u,delta]);
    
    ClosestFound=norm(rk)-u<E;
    %ClosestFound=abs(norm(rk)-u)<=Et;
    
    if(~ClosestFound)
        
        %-------------------------------------------------------%
        %--------- Distance of minimum norm algorithm ----------%
        %-------------------------------------------------------%
        
        
        
        % forming new simplex
        if(size(Ak,2)<=size(Ak,1))
            Ak=[Ak w];
        else
            Ak(:,end)=w;
        end
        
        Akr=Ak; 
        
        
        if(size(Akr,2)~=1)
            
            NumIter2=0;     % used to limit the number of nested iterations
            ShiftCounter=0; % used to limit the number of shifts to the 
                            % location of the elements in set Akr
                            
                            
            while(NumIter2<=20)
                
                NumIter2=NumIter2+1;
                
                nRows=size(Akr,2)-1;
                nColumns=size(Akr,2);
                M=zeros(nRows,nColumns);
                m=zeros(nRows,1);
                
                for nr=2:nRows+1;
                    for nc=1:nColumns;
                        M(nr-1,nc)=dot(Akr(:,nr)-Akr(:,1),Akr(:,nc));
                    end
                    
                    m(nr-1,1)=dot(Akr(:,nr)-Akr(:,1),b);
                end
                
                % forming system of equations
                G=[ones(1,nColumns);M];
                h=[1;m];
                

                if(rank(G)~=size(G,1))
                    ShiftCounter=ShiftCounter+1;
                    
                    % Matrix not full rank. Continue with next iteration
                    Akr=circshift(Akr,[0 -1]);
                    
                    if(ShiftCounter<nColumns)                        
                        
                        continue;
                        
                    else
                        
                        ShiftCounter=0;
                        
                    end
                    
                        
                end
                
                % solving for coefficients
                x=G\h;              

                
                indexes=x>1e-6; % elements to retain from Akr
                
                if(all(indexes))
                    
                    % all coefficients obey the affine combination
                    % and sign conditions
                    pk=sum(repmat(x',size(Akr,1),1).*Akr,2);
                    rk=b-pk;
                    Ak=Akr;
                    break;
                else
                    if(sum(indexes)>1)
                        % eliminates the points corresponding to 
                        % the values of x that are less than 0  
                        Akr=Akr(:,indexes);
                    elseif(sum(indexes)==1)
                        pk=Akr(:,indexes);
                        rk=b-pk;
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
            rk=b-pk;
        end
        
    end
    d=norm(rk);
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
        
        
        
             
        