% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Givens
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% object Frame
ObjectFrame=eye(4);

% contact force normal vector
n=[0 0 1]';

% contact point location relative to the object frame
r=[1;1;1];

% contact type
ContactType='SFCe';

% discretization aproximation [J K]
Discretization=[10 1];

% friction coefficients [u us]
FrictionCoeff=[0.5 0.5]; 

% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Initializing
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% extracting z axis of the object frame
no=ObjectFrame(1:3,3);

[theta,u]=Algorithms.EquivalentAngleAxis(no,n);

% conputing contact frame of reference relative to the object frame of
% reference
ContactFrame=Algorithms.aa2transform(u,theta);

% retrieving tangent vectors of the contact frame
o=ContactFrame(1:3,1);
t=ContactFrame(1:3,2);

switch lower(ContactType)
    case lower('PC')
        
    case lower('PCF')
        
    case lower('SFCe')
        % GraspMatrix
        G=[n o t zeros(3,1);cross(r,n) cross(r,o) cross(r,t) n];
        
        % retreiving discretization parameters
        J=Discretization(1);
        K=Discretization(2);        
        if(K<2)
            K=2;
        end
        
        % retreiving friction coefficients,
        u=FrictionCoeff(1);
        us=FrictionCoeff(2);
                
        % creating tau values
        tau=zeros(3,2*J*K-J+2);
        
        index=1;
        for k=-K:K;
            for j=1:J;            
                tau(:,index)=[u*cos(2*j*pi/J)*cos(k*pi/(2*K));u*sin(2*j*pi/J)*cos(k*pi/(2*K));...
                    us*sin(k*pi/(2*K))];
                index=index+1;
                
                if(abs(k)==K)
                    break;
                end
            end
        end
        
        % creating s
        s=[ones(1,size(tau,2));tau];
        
        % creating primitive wrench array
        w=G*s;       
        
        
    case lower('SFCl')
                % GraspMatrix
        G=[n o t zeros(3,1);cross(r,n) cross(r,o) cross(r,t) n];
        
        % retreiving discretization parameters
        J=Discretization(1);
        K=1;
        
        % retreiving friction coefficients,
        u=FrictionCoeff(1);
        us=FrictionCoeff(2);
                
        % creating tau values
        tau=zeros(3,2*J*K-J+2);
        
        index=1;
        for k=-K:K;
            for j=1:J;            
                tau(:,index)=[u*cos(2*j*pi/J)*cos(k*pi/(2*K));u*sin(2*j*pi/J)*cos(k*pi/(2*K));...
                    us*sin(k*pi/(2*K))];
                index=index+1;
                
                if(abs(k)==K)
                    break;
                end
            end
        end
        
        % creating s
        s=[ones(1,size(tau,2));tau];
        
        % creating primitive wrench array
        w=G*s; 
        
        
    otherwise
        
        
        
        
        
end











