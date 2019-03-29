% GJK algorithm attempt
% This is an implementation of the GJK algorithm using the method that find
% the closest distance from the origin to a set A as long as the origin is
% not contained in A

%% Inputs
A=[[-1 1 1 -1];2+[-1 -1 1 1]];

%% Inputs :  hexagon
A=zeros(2,6);
%building A
r=1; % inner segment length
for n=1:6;
    A(:,n)=[r*cos((n-1)*pi/3)+3;r*sin((n-1)*pi/3)+0.2];
end

%% Inputs: box
box=Box;
box.Frame=Algorithms.translation('z',1)*Algorithms.rotation('x',pi/4);
%box.Frame=Algorithms.translation('zx',[0.3 0.4]);
A=box.CurrentVertices';

b=[1.2;-0.3;-1];
%% Initialization
%rk=b; % vector that goes from b to closest point in set A pk(b,A)
pk=A(:,1);

Ak=[]; % Subset of linearly independent points of A

ClosestFound=false; 

Et=0.0001; % tolerance

u=0; % minimum value attainable 

NumIter=0;
%while(~ClosestFound && ~all(rk==0) && (NumIter<20))
while(~ClosestFound && (NumIter<20))
    
    NumIter=NumIter+1;
    w=Algorithms.SupportMapping(-pk,A);
    w=w(:,1);
        
    delta=(pk'*(w))/norm(pk); % minimum error
    %delta=norm(b-w);
    
    u=max([u,delta]);
    
    ClosestFound=norm(pk)-u<0.0001;
    %ClosestFound=abs(norm(rk)-u)<=Et;
    
    if(~ClosestFound)
        
        % Distance of minimum norm algorithm
        
        if(size(Ak,2)<=size(Ak,1))
            Ak=[Ak w];
        else
            Ak(:,end)=w;
        end
        
        Akr=Ak;
        fprintf('\nIteration# %i\n',NumIter)
        
        fprintf('\nSimplex Ak\n')
        disp(Ak)
        
        
        if(size(Akr,2)~=1)
            
            NumIter2=0;
            ShiftCounter=0;
            while(NumIter2<=20)
                
                NumIter2=NumIter2+1;
                
                fprintf('\nInternal Iteration #%i\n',NumIter2)
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
                
                fprintf('Coefficient Matrix:\n')
                disp(G)
                
                fprintf('\nColumn Vector\n')
                disp(h)
                
                if(rank(G)~=size(G,1))
                    ShiftCounter=ShiftCounter+1;
                    fprintf('\nMatrix not full rank. Continue with next iteration\n')
                    Akr=circshift(Akr,[0 -1]);
                    
                    disp(Akr)
                    if(ShiftCounter<nColumns)
                        
                        
                        continue;
                    else
                        
                        ShifCounter=0;
                        
                    end
                        
                end
                
                % solving for coefficients
                x=G\h;
                
                fprintf('\nCoefficients\n')
                disp(x)
                
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

fprintf('\nClosest Distance:\n')
disp(d)

fprintf('\nClosest Point:\n')
disp(pk)

fprintf('\nResulting Affinely independent subset of A:\n')
disp(Ak)


        
        
        
            
            
        
