% EPA algorithm attempt
% This is an implementation of the EPA algorithm using the method that
% finds the closest distance from the origin to a set A as long as the 
% origin is contained in A.  At each iteration, it expands a current
% polytope that contains the origin by adding a vertex w which is a support
% point for pk, ( the closest point to the origin in the current polytope).

%A=[-1 1 1 -1;[-1 -1 1 1]];
%% Inputs
A=[0.6+[-1 1 1 -1];0.7+[-1 -1 1 1]];
%A=[[-1 1 1 -1];[-1 -1 1 1]];
%% Inputs :  hexagon
A=zeros(2,6);
b=[-2;2];
%building A
r=1; % inner segment length
for n=1:6;
    A(:,n)=[r*cos((n-1)*pi/3)+0.2;r*sin((n-1)*pi/3)+0.2];
end

%% Inputs: box
box=Box;

% returns a hexahedron when evaluated against the GJK algorithm
%box.Frame=Algorithms.translation('z',0.2)*Algorithms.rotation('x',pi/4);

box.Frame=Algorithms.rotation('x',pi/4);

%box.Frame=Algorithms.translation('xz',[(sqrt(2)/2)*cos(5*pi/12) -0.5+(sqrt(2)/2)*sin(5*pi/12)])...
%   *Algorithms.rotation('y',-pi/6);
%box.Frame=Algorithms.translation('xz',[(sqrt(2)/2)*0.3 (sqrt(2)/2)*0.3])...
%    *Algorithms.rotation('y',-pi/4);
A=box.CurrentVertices';

%% Initialization
[v_,d_,Ak] = Algorithms.GJKOrigin2Set(A); % Initial polytope that contains
tic                                        % the origin
MaxVertices=100; % maximum number of vertices allowed in expanded polytope
CurrentVertices=size(Ak,2); % Current Number of vertices in expanded polytope
Dimensions = size(Ak,1);

% initializing polytope
P=sparse(Dimensions,MaxVertices);
P(:,1:CurrentVertices)=Ak;

%P=[Ak zeros(Dimensions,MaxVertices-CurrentVertices)];


% determining if polytope contains the minimum number of vertices.
% initial polytope must be an ( n - simplex) 
RequiredVertices=Dimensions+2;
NumVertices=CurrentVertices;


% last support point entries
%w_last=zeros(Dimensions,2);


if(NumVertices<RequiredVertices)
    
    % number of possible combination of the elements in Ak
    nCombinations=prod(CurrentVertices-1:CurrentVertices)/prod(1:2);
    
   
    
    % determining if there can be obtained at least n-1 combinations of Ak
    % that would allow computing a well defined normal vector.
    if(CurrentVertices<RequiredVertices-2 || nCombinations<Dimensions-1 )
        
        % initializing set As so that an appropiate set that yields n-1 distinc
        % combinations of 2 points can be formed.
        %As = sparse(Dimensions,CurrentVertices+Dimensions);
        
        %As(:,1:CurrentVertices)=Ak;
        
        % constructing n dimensional basis
        e=eye(Dimensions);
        
        n=0;
        %nVertices=CurrentVertices;
        %while(nCombinations<Dimensions-1 && CurrentVertices<RequiredVertices-2)
        while(CurrentVertices<RequiredVertices-2 || nCombinations<Dimensions-1)
            
            n=n+1;
            w=Algorithms.SupportMapping(e(:,n),A);
            % adding points from the n dimensional basis that do not belong
            % to the set.
            if(~any(all(full(P(:,1:CurrentVertices))==repmat(w(:,1),1,CurrentVertices),1)))
                CurrentVertices=CurrentVertices+1;
                
                % computing support point in the direction of basis vector
                
                P(:,CurrentVertices)=w(:,1);
                nCombinations=prod(CurrentVertices-1:CurrentVertices)/prod(1:2);
            end
            
            
        end
        
        As=full(P(:,1:CurrentVertices));
    
    else
        As=full(P(:,1:CurrentVertices));
    end
    
        
   
    
    % retrieving edge from polytope
    %edge=full(P(:,2)-P(:,1));
    
%     n=1;    
%     
%     direction=1;
    
    % expading current set by adding support points in the direction of the
    % normal vectors
%     while(CurrentVertices<RequiredVertices+2 && n<=Dimensions)
%         
%         % creating normal vector to edge
%         norml=Algorithms.normal(As);
%         
%         %         % making sure that the resultant vector is not 0
%         %         if(all(norml==zeros(Dimensions,1)))
%         %             n=n+1;
%         %             direction=1;
%         %             continue
%         %         end
%         
%         % computing support points
%         w=Algorithms.SupportMapping(direction*norml(:,1),A);
%         
%         %if(~any(all(full(P(:,1:CurrentVertices))==repmat(w(:,1),1,CurrentVertices),1)))
%         fprintf('\nAdding Support Points w:\n')
%         disp(w)
%         
%         % adding point to Polytope
%         nPointsAdded=size(w,2);
%         P(:,CurrentVertices+1:CurrentVertices+nPointsAdded)=w;
%         CurrentVertices=CurrentVertices+nPointsAdded;
%         
%         %w_last(:,1)=w(:,1);
%         
%         
%         %end
%         
%         if(direction<0)
%             n=n+1;
%             direction=1;
%         else
%             direction=-1;
%         end
%         
%             
%         
%         
%             
%     end
    
    % adding support points in the of set A from the normal vectors to As
    
    % creating normal vector to edge
    norml=Algorithms.normal(As);
    
    % computing support points
    w1=Algorithms.SupportMapping(norml(:,1),A);
    w2=Algorithms.SupportMapping(-norml(:,1),A);
    
    % gathering all support points
    w=[w1 w2];
    
    %if(~any(all(full(P(:,1:CurrentVertices))==repmat(w(:,1),1,CurrentVertices),1)))
    fprintf('\nAdding Support Points w:\n')
    disp(w)
    
    % adding point to Polytope
    nPointsAdded=size(w,2);
    P(:,CurrentVertices+1:CurrentVertices+nPointsAdded)=w;
    CurrentVertices=CurrentVertices+nPointsAdded;
    
 
    
    
end
%%        
                                 
w=[]; % support point

pk=0; % closest point in a facet of P to the origin


ClosestFound=false; 

Et=0.01; % tolerance

u=0; % minimum value attainable 

NumIter=0;

% faceted data
facesOld = zeros(1,Dimensions);

while(NumIter<100)
    
    NumIter=NumIter+1;
    d=0;
    fprintf('\n ________________________________________________________')
    fprintf('\n _____________________ Iteration %i _____________________',NumIter)
    fprintf('\n ________________________________________________________\n')

    
    % constructing faceted geometry
    switch Dimensions
    case {2 3 4}
        K=convhulln(full(P(:,1:CurrentVertices))',{'Qt'});
    otherwise 
        K=convhulln(full(P(:,1:CurrentVertices))',{'Qt','Qx'});
    end
    
    
    
    %  obtaining new faces
    [facesNew,indices] = setdiff(K,facesOld,'rows');
    
    % computing minimum distance dmin for each new facet in the convex hull
    % of current set P which contains the origin
    nfacets=size(facesNew,1);
    npoints=size(facesNew,2);
    
%     nOldFaces = size(facesOld,1);
%     for n = 1:nOldFaces;
%         
%         nNewFaces = size(K,1);
%         
%         for m =1:nNewFaces;
%             
%             [setC,indices] = setdiff(K(m,:),facesOld(n,:));
%             
%             if isempty(setC)
%                 K(m,:) = [];
%                 break
%             end
%             
%         end
%         
%     end
%     
%     facesNew = K;
%     
%     nfacets=size(facesNew,1);
%     npoints=size(facesNew,2);   
        
        
    
    fprintf('\nnew faces added: %i\n',nfacets)
    
    if nfacets == 0
        break;
        
    end
    
    for n=1:nfacets;
        
        % building matrices M and m
        fprintf('\n _________________ Distance to facet %i _________________\n',n)
        M=zeros(npoints-1,npoints);
        m=zeros(npoints-1,1);
        
        nRows=npoints-1;
        nColumns=npoints;
        for nr=1:nRows;
            
            % obtaining consecutive points in a facet
            pa=P(:,facesNew(n,nr));
            pb=P(:,facesNew(n,nr+1));
            
            for nc=1:nColumns;                
                
                M(nr,nc)=dot(pb-pa,P(:,facesNew(n,nc)));
                
            end
            
        end
        
        % constructing linear system
        G=[ones(1,nColumns);M];
        h=[1;m];
        
        fprintf('Coefficient Matrix:\n')
        disp(G)
        
        fprintf('\nColumn Vector\n')
        disp(h)
        
        if(rank(G)==size(G,1))
            x=G\h;
            
            fprintf('\nCoefficients\n')
            disp(x)
            
        else
            
            continue
            
        end
        
        
        % verifying that all x are positive
        if(all(x>=0))
            pkmin=sum(repmat(x',npoints,1).*P(:,facesNew(n,:)),2);
            dmin=norm(pkmin);
            
            fprintf('\nCurrent Points on the %ith facet\n',n)
            disp(full(P(:,facesNew(n,:))))
            
            fprintf('\nCurrent Minimum point of the %ith facet\n',n)
            disp(full(pkmin))
            
            fprintf('\nCurrent Minimum distance of the %ith facet\n',n)
            disp(dmin)
            
            if(d==0)
                d=dmin;
                pk=pkmin;
                fprintf('\nEntered\n')
            else
                
                if(dmin<d)
                    d=dmin;
                    pk=pkmin;
                end
                
            end
            
            fprintf('\nCurrent Minimum point of the current polytope\n')
            disp(full(pk))
            
            fprintf('\nCurrent Minimum distance of the current polytope\n')
            disp(d)
            
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
    
    facesOld = K;
    
end


fprintf('\n _________________________results________________________\n')
fprintf('\nTotal Time:\n')
disp(toc)

fprintf('\nNumber of Iterations:\n')
disp(NumIter)

fprintf('\nClosest Distance:\n')
disp(d)

fprintf('\nClosest Point:\n')
pk=full(pk);
disp(pk)

fprintf('\nExpanded Polytope P subset of A that contains the origin:\n')
Ak=full(P(:,1:CurrentVertices));
disp(Ak)

fprintf('\nFacets of expanded polytope P\n')
disp(size(K,1))         
            
        
    
    
    
    
    
    
    %w=Algorithms.SupportMapping