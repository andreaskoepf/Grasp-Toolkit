classdef Link < Solid
    properties        

        JointLimits=[-inf inf];
        JointOffsets=0;
        JointValues=0;  
        
        %LocalFrame=eye(4);        
        
        %Next Body Connected to this Body
        % NextLink=[];
        
        %Tag % Allows placing a tag for any user defined purpose
    end
    
    properties(SetAccess=protected)
        
        DH=zeros(1,4) % Denavit Hartenberg parameters
        JointType='none';
        DOF=1;
        TransformFunction=@(x)eye(4);
        
%         Contact
%         ContactTypeModel
    end
    
    properties(Dependent=true,SetAccess=protected)
        Transform
    end
    
    methods
        
        function link=Link(varargin)
            
            switch nargin
                case 0
                    return
                case 1  
                    
                    if isa(varargin{1},'Link')
                        data=varargin{1}.toStruct;
                        
                        for n=1:length(data)
                            link(n).loadFieldsFromStruct(data(n));
                        end                        
                            
                    elseif isa(varargin{1},'char')
                            
                        % load existing model data file
                        data=Toolkit.loadModelData('Link',varargin{1});                        
                        
                        link.loadFieldsFromStruct(data);
                        link.reducePatch(data.PatchReductionFactor);
                        link.shift(data.NewReferenceFrame\eye(4));
                        link.restore; % This is to ensure that the object is resized
                                                             % properly after shifting
                        %link.scale(data.Scale);                 
                        
                    elseif isa(varargin{1},'struct')
                        
                        % this option may required additional checking 
                        % statements
                        data=varargin{1};
                        
                        for n=1:length(data)
                            link(n).loadFieldsFromStruct(data(n));
                        end
                        
                    end
                 
                    
                   
                otherwise
                    error('Wrong Number of Input Arguments')
            end
                        
        end

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function update(link)
% 
%             
%             % link.Frame=link.LocalFrame*link.Transform;
%             link.update@Solid;
%             
%             if(~isempty(link.NextLink)&& isvalid(link.NextLink))
%                 link.NextLink.LocalFrame=link.Frame;
%                 link.NextLink.update;
%             end
%         end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function updateData(link)
%             link.Frame=link.LocalFrame*link.Transform;
%         end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function transform=get.Transform(link)
            transform=link.TransformFunction(link.JointValues+link.JointOffsets);
        end        
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function connect(link)
%             % connects the objects in a chain in accordance to the order
%             % given in the array
%             
%             for n=1:length(link)-1;
%                 link(n).NextLink=link(n+1);
%             end
%         end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function set.NextLink(link,nextLink)
%             if(isa(nextLink,'Solid'))
%                 link.NextLink=nextLink;
%             end
%         end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.DH(link,dh)
                link.DH=dh(:,1:4);
                link.DOF=size(dh,1);
                
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function set.JointValues(link,q)
%             link.JointValues=q;
%             link.Frame=link.LocalFrame*link.Transform;
%         end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.JointOffsets(link,qoffset)
            
            if(length(qoffset)>=link.DOF)
                link.JointOffsets=reshape(qoffset(1:link.DOF),[link.DOF 1]);
            else
                link.JointOffsets(1:length(qoffset))=reshape(qoffset,[length(q) 1]);
            end
                
            switch link.JointType
                case 'Prismatic'
                    link.DH(:,3)=link.JointOffsets;
                otherwise
                    link.DH(:,4)=link.JointOffsets;
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.JointLimits(link,qlimits)
            if all(size(qlimits)==[link.DOF 2])
                link.JointLimits=qlimits;
            else
                error(['Matrix size should be of ' num2str(link.DOF) ' x 2'])
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
        function newlink=tolink(obj)
            % converts subclass object into a Link object and returns a
            % handle to a new Link object.
            newlink=Link(obj);
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.JointType(link,jointType)
            
            switch jointType
                case {'None' 'n' 'N' 'none'}
                    link.JointType='None';
                    link.TransformFunction=@(x)eye(4);
                case {'Prismatic' 'p' 'P' 'prismatic'}
                    link.JointType='Prismatic';
                    dh=link.DH;
                    link.TransformFunction=@(x)prismaticTransform(dh(1),dh(2),x,dh(4));
                case {'Revolute' 'r' 'R' 'revolute'}
                    link.JointType='Revolute';
                    dh=link.DH;
                    link.TransformFunction=@(x)revoluteTransform(dh(1),dh(2),dh(3),x);
                case {'Spherical' 's' 'S' 'spherical'}
                    link.JointType='Spherical';
                    dh=link.DH;                    
                    link.TransformFunction=@(x)sphericalTransform(dh(:,1),dh(:,2),dh(:,3),x);
                case {'Universal' 'u' 'U' 'universal'}
                    link.JointType='Universal';
                    dh=link.DH;
                    link.TransformFunction=@(x)universalTransform(dh(:,1),dh(:,2),dh(:,3),x);
                otherwise
                    error('Invalid Joint Type')
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFieldsFromStruct(link,data)
            indexes=1:length(data);
            % assigning data to the fields
            %
            for n=indexes;
                link(n).loadFieldsFromStruct@Solid(data(n));
                link(n).DH=data(n).DH;
                link(n).JointType=data(n).JointType;
                link(n).JointLimits=data(n).JointLimits;
                link(n).JointOffsets=data(n).JointOffsets;
                link(n).JointValues=data(n).JointValues;
                
%                 if strcmp('LocalFrame',fieldnames(data))
%                     % temporal solution 
%                     link(n).LocalFrame=data(n).LocalFrame;
%                 end
%                link(n).Contact=data(n).Contact;
%                link(n).ContactTypeModel=data(n).ContactTypeModel;
                
            end
            
        end    
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function scale(link,scaleFactor)
            
            link.scale@Solid(scaleFactor);
            link.DH(:,1)=scaleFactor*link.DH(:,1);
            if ~strcmpi(link.JointType,'Prismatic')
                link.DH(:,3)=scaleFactor*link.DH(:,3);
            end
            
            link.JointType=link.JointType;  %  this step is performed in 
            %  order to reassign new input parameters to the transform
            %  function handle
            
%             if(~isempty(link.NextLink)&& isvalid(link.NextLink))
%                 scale(link.NextLink,scaleFactor);
%             end
            
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function restore(link)
            link.restore@Solid;
            link.scale(1);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function drive(link,jointValues)
            link';
            for n=1:size(jointValues,2);
                link.JointValues=jointValues(:,n);
                link.Frame=link.Transform;
                link.update;
                drawnow
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function newlinks=copyArray(links)
            newlinks(length(links))=Link;
            for n=1:length(links);
                newlinks(n)=Link(links(n));
            end
        end

    end
    
end

function T=prismaticTransform(L,alpha,D,theta)

% D is the variable and the other arguments are constant
    ct=cos(theta);
    st=sin(theta);
    ca=cos(alpha);
    sa=sin(alpha);
    T=[ct -st*ca st*sa L*ct
    st ct*ca -ct*sa L*st
    0 sa ca D
    0 0 0 1];
end

function T=revoluteTransform(L,alpha,D,theta)

% theta is the variable and the other arguments are constant
ct=cos(theta);
st=sin(theta);
ca=cos(alpha);
sa=sin(alpha);
T=[ct -st*ca st*sa L*ct
    st ct*ca -ct*sa L*st
    0 sa ca D
    0 0 0 1];
end


function T=sphericalTransform(L,alpha,D,theta)
    T=revoluteTransform(L(1),alpha(1),D(1),theta(1))*revoluteTransform(L(2),alpha(2),D(2),theta(2))...
        *revoluteTransform(L(3),alpha(3),D(3),theta(3));
end

function T=universalTransform(L,alpha,D,theta)
    T=revoluteTransform(L(1),alpha(1),D(1),theta(1))*revoluteTransform(L(2),alpha(2),D(2),theta(2));
end


    
            
            
                    
                    
        