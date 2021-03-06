% Porsiaca nomas
% Last updated 05/31/2009 19:19 fsdfs
classdef Solid < handle
    
    properties (SetAccess=protected)
        % Contact Data
        Contacts       
        
        % Geometric Definition
        Vertices=[0 0 0 1]';
        Faces=[1 1 1];          
        Dimensions =[0 0 0];% [length width heigth]        
        DefaultVertices=[0 0 0];  
        OffsetFrame=eye(4); % offset frame from local origin
        
        
        
        % Internal Graphics and File Definitions        
        GraphicsHandle % [patch_handle]
        FigureHandle 
        PhysicsHandle % handle return by physics engine implemented in a mex executable file
        ModelName
        Tag
        FileName
        
        
        % Used by the physics simulation
        GeometryID=int32(3);  % corresponds to generic trimesh geometries
        

               
    end
    
    properties (Constant,SetAccess=protected)
        
        % for use with the physics simulation
        ClassIndex=int32(2);
        MethodIndexMap=Solid.getMethodIndexMap;
        GeometryIndexMap=Solid.getGeometryIndexMap;
        
        
    end
    
    properties(SetAccess=public,GetAccess=public)
        
        % Mass Definitions
        I=eye(3);
        COG=zeros(3,1);
        Mass=1;
        
        % Object Reference Frame
        Frame=eye(4);
        
        
        % Used by the physics simulation
        IsDynamic=int32(1);
        InPhysicsMode=int32(0);
        
        
        
        % Additional Utility Definitions
        Color='green';
        Visible=true;
        
        
        
    end
    
    
    properties(Dependent=true,SetAccess=protected)
         AxisLimits;
    end
    
    properties (Dependent=true,SetAccess=private)
        % Geometric Definition
        DefaultDimensions
        CurrentVertices       
               
    end
    
    
    properties (Dependent=true)
        
        Quaternion
        Position
        
    end
    
    
    
    methods
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function solid=Solid(varargin)
            % solid = Solid(filename,dimensions,frame)
            switch nargin
                case 0
                    return
                case 1
                    if isa(varargin{1},'Solid')
                        
                        propNames=fieldnames(varargin{1});
                        actPropNames=fieldnames(Solid); % solid property names
                        
                        % removing Dependent Property Names from the actPropNames
                        actPropNames(strcmp('AxisLimits',actPropNames))=[];
                        actPropNames(strcmp('CurrentVertices',actPropNames))=[];
                        actPropNames(strcmp('DefaultDimensions',actPropNames))=[];
                        actPropNames(strcmp('ClassIndex',actPropNames))=[];
                        actPropNames(strcmp('MethodIndexMap',actPropNames))=[];
                        actPropNames(strcmp('PhysicsHandle',actPropNames))=[];
                        actPropNames(strcmp('InPhysicsMode',actPropNames))=[];
                        actPropNames(strcmp('GraphicsHandle',actPropNames))=[];
                        %actPropNames(strcmp('GeometryID',actPropNames))=[];
                        actPropNames(strcmp('GeometryIndexMap',actPropNames))=[];
                        %actPropNames(strcmp('WorldTransform',actPropNames))=[];
                        
                        
                        for n=1:length(propNames)-1;
                            
                            if any(strcmp(propNames{n},actPropNames))
                                solid.(propNames{n})=varargin{1}.(propNames{n});
                            end
                        end
                        solid.GraphicsHandle=[];
                        solid.FigureHandle=[];
                        
                    elseif isa(varargin{1},'char')
                        
                        if Toolkit.isToolkitModel('Solid',varargin{1})
                            % loads data from saved model
                            data=Toolkit.loadModelData('Solid',varargin{1});                        
                        
                            solid.loadFieldsFromStruct(data);
                            solid.reducePatch(data.PatchReductionFactor);
                            solid.shift(data.NewReferenceFrame\eye(4));
                            solid.restore;
                        
                        else
                            % loading geometric definition from from text file either wrl or stl
                            data=Toolkit.loadGeometryFromFile(varargin{1});


                            indexes=1:length(data);
                            % assigning data to the fields
                            for n=indexes;
                                solid(n).DefaultVertices=data(n).DefaultVertices;
                                solid(n).Faces=data(n).Faces;
                                solid(n).FileName=data(n).FileName;
                                solid(n).resize(solid(n).DefaultDimensions);
                            end
                        
                        end
                        
                        %indexes=1:length(data);
                    elseif nargin >0 && isa(varargin{1},'struct')
                        data=varargin{1};
                        
                        % assigning data to the fields
                        for n=indexes;
                            
                            solid(n).DefaultVertices=data(n).DefaultVertices;
                            solid(n).Faces=data(n).Faces;
                            solid(n).FileName=data(n).FileName;
                            solid(n).ModelName=data(n).ModelName;
                            solid(n).Tag=data(n).Tag;
                            solid(n).I=data(n).I;
                            solid(n).COG=data(n).COG;
                            solid(n).Mass=data(n).Mass;
                            solid(n).Frame=data(n).Frame;
                            solid(n).Color=data(n).Color;
                            solid(n).Visible=data(n).Visible;
                            solid(n).resize(data(n).Dimensions);
                            solid(n).OffsetFrame=data(n).OffsetFrame;                            
                            
                        end
                        
                    else
                        error('wrong data type for input argument')
                    end
                otherwise
                    error('wrong number of input arguments')
            end
            
           
        end
       
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function resize(solid,dimensions)
            solid.Dimensions=abs(dimensions);

            % resizing solid
            sf=solid.Dimensions./solid.DefaultDimensions;   % size factor
            
            % eliminating all nan results if the default dimension is 0
            sf(isnan(sf))=0;
            
            v= solid.DefaultVertices;           % default vertices

            vertices=[sf(1)*v(:,1) sf(2)*v(:,2) sf(3)*v(:,3)];
            solid.Vertices=[vertices';ones(1,size(vertices,1))];
            
            % retrieving offset frame
            offsetFrame=solid.OffsetFrame;
            
            % resetting offset frame
            solid.OffsetFrame=eye(4);
            
            % shifting by offset frame
            solid.shift(offsetFrame);
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function restore(solid)
            solid.resize(solid.DefaultDimensions);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function vertices=get.CurrentVertices(solid)
            v=solid.Frame*solid.Vertices;
            vertices=v(1:3,:)';
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.Vertices(solid,vertices)
            % Trasposes and adds and additional row of ones in order to
            % perform transformatios directly without resizing the matrix
            % data.
            if(~(size(vertices,1)==4))
                solid.Vertices=[vertices';ones(1,size(vertices,1))];
            else
                solid.Vertices=vertices;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.Faces(solid,faces)
            if(~isa(faces,'int32'))
                solid.Faces=int32(faces);
            else
                solid.Faces=faces;
            end
        end
        
%         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function transform=get.WorldTransform(solid)
%             transform=solid.Frame*solid.Transform;
%         end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function out=get.DefaultDimensions(solid)
            vertices=solid.DefaultVertices;
            out(1)=abs(max(vertices(:,1))-min(vertices(:,1)));
            out(2)=abs(max(vertices(:,2))-min(vertices(:,2)));
            out(3)=abs(max(vertices(:,3))-min(vertices(:,3)));
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        
        function out=get.AxisLimits(solid)
            
            minimum=min(min(solid.Vertices(1:3,:)'));
            maximum=max(max(solid.Vertices(1:3,:)'));
            axisLimits=repmat([minimum-0.1*abs(minimum) maximum+0.1*abs(maximum)],3,1)+...
                repmat(solid.Frame(1:3,4),1,2);
            out=[axisLimits(1,:) axisLimits(2,:) axisLimits(3,:)];
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function out=get.Quaternion(solid)
            out=Solid.transform2quatern(solid.Frame);
            %out=single(Solid.transform2quatern(solid.Frame));
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.Quaternion(solid,q)
            rot=Solid.quatern2transform(q);
            solid.Frame(1:3,1:3)=rot(1:3,1:3);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function out=get.Position(solid)
            out=solid.Frame(1:3,4);
            %out=single(solid.Frame(1:3,4));
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.Position(solid,pos)
            solid.Frame(1:3,4)=pos;
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function drive(solid,transform)
            solid';            
            if nargin==2
                for n=1:size(transform,3);
                    solid.Frame=transform(:,:,n);
                    update(solid);
                    drawnow
                end
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function shift(solid,offsetFrame)
            % Offsets the body from its local frame by the given transform.
            
             %retrieving previous offset frame
            prevOffset=solid.OffsetFrame;
            
            % creating new vertices array
            vertices=offsetFrame*(prevOffset\eye(4))*solid.Vertices;
            
            % storing vertices
            solid.Vertices=vertices(1:3,:)';
            
            % storing new offset transform
            solid.OffsetFrame=offsetFrame;
        end 
 
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function scale(solid,f)
            solid.resize(f*solid.Dimensions);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function newsolids=copyArray(solids)
            newsolids(length(solids))=Solid;
            for n=1:length(solids);
                newsolids(n)=Solid(solids(n));
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function ctranspose(solid)


            solid.setHandles;
            
            for n=1:length(solid);
                update(solid(n));
            end
            drawnow
            figure(solid(1).FigureHandle);
            %title(['Imported CAD data from ' filename])
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setHandles(solid)
        % initiates graphics handles if they do not exists    
            
            for n = 1:length(solid);
                if isempty(solid(n).GraphicsHandle)|| ~ishandle(solid(n).GraphicsHandle)
                    solid(n).GraphicsHandle=patch('Vertices',solid(n).CurrentVertices ...
                        ,'Faces',solid(n).Faces,'facec',solid(n).Color...
                        ,'EdgeColor',solid(n).Color,'EdgeLighting','phong','AmbientStrength',1,...
                        'FaceLighting','phong','SpecularColorReflectance',0.5,'AlphaDataMapping','none',...
                        'CDataMapping','direct','DiffuseStrength',0.5);

                    solid(n).FigureHandle=get(get(solid(n).GraphicsHandle,'Parent'),'Parent');
                    set(solid(n).FigureHandle,'Renderer','openGL')
                    
                    % setting parent axes object properties
                    %set(get(solid(n).GraphicsHandle,'Parent'),'NextPlot','add')

                    if isempty(findobj(get(solid(n).GraphicsHandle,'parent'),'Type','light'))
                        light('Position',[-1000 -1000 1000],'Style','local');
                        light('Position',[1000 1000 1000],'Style','local')
                        
%                         light('Position',[0 1 1],'Style','infinite');
%                         light('Position',[0 1 1],'Style','infinite');
%                         light('Position',[0 1 1],'Style','infinite');
%                         light('Position',[0 -1 -1],'Style','infinite');
%                         light('Position',[0 -1 -1],'Style','infinite');
%                         light('Position',[0 -1 -1],'Style','infinite');
%                         light('Position',[0 -1 -1],'Style','infinite');
                    end
                    material shiny;
                    
                    daspect([1 1 1])
                    view([52.5 40])
                    xlabel('X'),ylabel('Y'),zlabel('Z')                   
                    
                    solid(n).Visible=solid(n).Visible;
                end
                %set(get(solid.GraphicsHandle,'Parent'),'XLim',solid.AxisLimits(1,:),'YLim',solid.AxisLimits(2,:),...
                %'ZLim',solid.AxisLimits(3,:));
                

            end     
            
            
            
        end 
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setPhysicsHandle(solid)
            
            % destroy any existing handles and create a new one
            solid.destroyPhysicsHandle;
            
            
            % C++ method call
            % calls the constructor for the Solid Class and stores the
            % corresponding handle            
            cId=solid.ClassIndex;
            mId=Solid.MethodIndexMap('Constructor');
            solid.PhysicsHandle=PhysicsWorld.PhysicsFunction(cId,mId,solid);
            solid.InPhysicsMode=true;
            
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function destroyPhysicsHandle(solid)
            % Using this method when the simulation is running can lead to
            % unexpected results
            if(solid.InPhysicsMode)
            
                try
                    % C++ method call
                    % calls the destructor for the currently stored handle.  An
                    % error message will be thrown in the handle is not valid
                    % or no longer exists.
                    cId=solid.ClassIndex;
                    mId=Solid.MethodIndexMap('Destructor');
                    PhysicsWorld.PhysicsFunction(cId,mId,solid.PhysicsHandle);
                    solid.InPhysicsMode=false;
                catch


                end
            end
            
            solid.InPhysicsMode=false;
        end
            
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function updateFromPhysics(solid)
            
            if(solid.InPhysicsMode)
%                 solid.Position=PhysicsWorld.PhysicsFunction(solid.ClassIndex,...
%                     solid.MethodIndexMap('getPosition'),solid.PhysicsHandle);

                solid.Frame=PhysicsWorld.PhysicsFunction(solid.ClassIndex,...
                    solid.MethodIndexMap('getTransform'),solid.PhysicsHandle);
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function updateToPhysics(solid)
            if(solid.InPhysicsMode)
                cId=solid.ClassIndex;
                mId=Solid.MethodIndexMap('setTransform');
                PhysicsWorld.PhysicsFunction(cId,mId,solid.PhysicsHandle,solid.Frame);
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function [bool,varargout]=collisionPairTest(solid,solid2)
            bool=false;
            if(solid.InPhysicsMode)
                cId=solid.ClassIndex;
                mId=Solid.MethodIndexMap('collisionPairTest');
                
                if nargout > 1
                    
                    [bool,contactStruct]=PhysicsWorld.PhysicsFunction(cId,mId,solid.PhysicsHandle,solid2.PhysicsHandle);
                    varargout{1} = contactStruct;
                else
                    
                    bool = PhysicsWorld.PhysicsFunction(cId,mId,solid.PhysicsHandle,solid2.PhysicsHandle);
                    
                end
                    
%                 if(bool)
%                     solid.Contacts=contactStruct;
%                 end
                
            end
            
        end  
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.InPhysicsMode(solid,boolean)
            if(boolean==0)
                solid.InPhysicsMode=false;
            else
                solid.InPhysicsMode=true;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function update(solid)
            % updates graphics handle in accordance to the current value of
            % the Frame Property
            
            set(solid.GraphicsHandle,'Vertices',solid.CurrentVertices)    
            

        end    
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.Visible(solid,visible)
            switch visible
                case true
                    solid.Visible=visible;
                    if ishandle(solid.GraphicsHandle)                        
                        set(solid.GraphicsHandle,'Visible','on')
                    end
                case false
                    solid.Visible=visible;
                    if ishandle(solid.GraphicsHandle)
                        set(solid.GraphicsHandle,'Visible','off')
                    end
                otherwise
                    error('Invalid data type for input argument visible, use ''true'' or ''false''')
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.IsDynamic(solid,bool)
            
            if(~isa(bool,'int32'))
                bool=int32(bool);
            end
                
            if((bool==int32(1))||(bool==int32(0)))
                solid.IsDynamic=bool;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setAsStaticTrimesh(solid)
            % this function is used by the physics simulation in order to
            % instantiate a suitable collision shape in the simulation.
            
            if(solid.GeometryID~=Solid.GeometryIndexMap('Plane') && solid.GeometryID~=Solid.GeometryIndexMap('Box'))
                solid.GeometryID = Solid.GeometryIndexMap('StaticTrimesh');
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function delete(solid)
            if ishandle(solid.GraphicsHandle)
                delete(solid.GraphicsHandle)
            end
            %refresh(solid.FigureHandle)
            
            solid.destroyPhysicsHandle;            

        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function newsolid = sum(solid)
            for n=1:length(solid);
                if n==1
                    newsolid=Solid(solid(1));
                else
                    newsolid=newsolid+solid(n);
                end
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function newsolid = plus(solid1,solid2)
            vertices=[solid1.CurrentVertices;solid2.CurrentVertices];
            faces=[solid1.Faces;solid2.Faces+size(solid1.Vertices,2)];            
            newsolid=Solid;            
            newsolid.DefaultVertices=vertices;
            %newsolid.DefaultDimensions=getAverageSize(newsolid);
            newsolid.resize(newsolid.DefaultDimensions);
            newsolid.Faces=faces;            
            newsolid.FileName='none';
            
        end
            
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function newsolid=toSolid(obj)            
            newsolid=Solid(obj);       
        end       
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function reducePatch(solid,reduction)
            % reduces number of patches
            switch nargin
                case 1
                    reduction=0.4;
                case 2
                    if reduction==0
                        return;
                    end
            end
            newFV=reducepatch(solid.Faces,solid.DefaultVertices,reduction);
            solid.DefaultVertices=newFV.vertices;
            solid.Faces=newFV.faces;
            solid.resize(solid.Dimensions);
            
            try
                delete(solid.GraphicsHandle);
                solid.GraphicsHandle=[];
            catch
                % Graphics handle hasn't been created yet, do nothing
            end
        end        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.Color(solid,color)
            solid.Color=color;
            try
                set(solid.GraphicsHandle,'FaceColor',solid.Color,'EdgeColor',solid.Color)
            catch
                % Graphics handle hasn't been created yet, do nothing
            end
        end
        
%         function attach(solid,attachedSolid,frame)
%             solid.AttachedBody=attachedSolid;
%             solid.AttachedBodyRelFrame=frame;
%         end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getXSpan(solid)
            span=[min(solid.Vertices(1,:)) max(solid.Vertices(1,:))];
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getYSpan(solid)
            span=[min(solid.Vertices(2,:)) max(solid.Vertices(2,:))];
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getZSpan(solid)
            span=[min(solid.Vertices(3,:)) max(solid.Vertices(3,:))];
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getSpan(solid)
            span=[solid.getXSpan solid.getYSpan solid.getZSpan];
        end
        
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getCurrentXSpan(solid)
            span=[min(solid.CurrentVertices(:,1)) max(solid.CurrentVertices(:,1))];
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getCurrentYSpan(solid)
            span=[min(solid.CurrentVertices(:,2)) max(solid.CurrentVertices(:,2))];
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getCurrentZSpan(solid)
            span=[min(solid.CurrentVertices(:,3)) max(solid.CurrentVertices(:,3))];
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getCurrentSpan(solid)
            span=[solid.getCurrentXSpan solid.getCurrentYSpan solid.getCurrentZSpan];
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function load(solid,arg)
            switch class(arg)
                case 'char'
                    loadGeometryFromFile(solid,arg)
                case 'struct'
                    loadFieldsFromStruct(solid,arg)
                otherwise
                    error('Wrong Type of input argument')
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadGeometryFromFile(solid,filename)
            %this function does not increase the size of the array,
            %preallocate before using this function.
            
            
            data=Toolkit.loadGeometryFromFile(filename);
            indexes=1:length(data);
            
            
            % assigning data to the fields
            for n=indexes;
                solid(n).DefaultVertices=data(n).DefaultVertices;
                solid(n).Faces=data(n).Faces;
                solid(n).FileName=data(n).FileName;
                solid(n).resize(solid(n).DefaultDimensions);
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFieldsFromStruct(solid,data)
            
            
            indexes=1:length(data);
            % assigning data to the fields
            for n=indexes;
                solid(n).DefaultVertices=data(n).DefaultVertices;
                solid(n).Faces=data(n).Faces;
                solid(n).FileName=data(n).FileName;
                solid(n).ModelName=data(n).ModelName;
                solid(n).Tag=data(n).Tag;
                solid(n).I=data(n).I;
                solid(n).COG=data(n).COG;
                solid(n).Mass=data(n).Mass;
                solid(n).Frame=data(n).Frame;
                solid(n).Color=data(n).Color;
                solid(n).Visible=data(n).Visible;
                solid(n).resize(data(n).Dimensions);
                
                % this statement is needed to account for previous class
                % versions that did not have this property.
                if(isfield(data(n),'OffsetFrame'))
                    solid(n).OffsetFrame=data(n).OffsetFrame;
                end
                
            end               
                
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function data=toStruct(solid)
            
            warning off
            for n=1:length(solid);
                data(n)=struct(solid(n));
            end
            warning on
        end
        
        
        
    end
    
    
    methods (Static)
        function R=rotation(axis,angle)
            %this function calculates the rotation matrix about an axis
            if length(axis)~=length(angle)
                error('number of elements of input arguments not equal')
            else
                R=eye(4);
                for n=1:length(axis);

                    switch lower(axis(n))
                        case 'z'
                            R=R*[cos(angle(n)) -sin(angle(n)) 0 0;sin(angle(n)) cos(angle(n)) 0 0;0 0 1 0;0 0 0 1];
                        case 'y'
                            R=R*[cos(angle(n)) 0 sin(angle(n)) 0;0 1 0 0;-sin(angle(n)) 0 cos(angle(n)) 0;0 0 0 1];
                        case 'x'
                            R=R*[1 0 0 0;0 cos(angle(n)) -sin(angle(n)) 0;0 sin(angle(n)) cos(angle(n)) 0;0 0 0 1];
                        otherwise
                            error('Invalid value for axis argument')
                    end
                end
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function T=translation(axis,r)
            % Creates a 4 x 4 traslation matrix along the corresponding axis in axis
            % argument.
            if length(axis)~=length(r)
                error('number of elements of input arguments not equal')
            else
                T=eye(4);
                for n=1:length(axis);
                    switch lower(axis(n))
                        case 'x'
                            T=T*[eye(3),[r(n) 0 0]';0 0 0 1];
                        case 'y'
                            T=T*[eye(3),[0 r(n) 0]';0 0 0 1];
                        case 'z'
                            T=T*[eye(3),[0 0 r(n)]';0 0 0 1];
                        otherwise
                            error('%s not a valid axis',axis(n))
                    end
                end
            end
        end       
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function [K,theta]=transform2aa(varargin)
            % Solid.transform2aa   Equivalent angle axis representation
            %
            %   [K,theta]=Solid.transform2aa(Tb) 
            %   returns the equivalent angle axes representation K and theta.
            %   The vector K is defined relative to global frame eye(3).
            %   
            %   [K,theta]=Solid.transform2aa(Tb,Ta)
            %   same as above but defines the angle axis representation that
            %   represents the relative rotation of Tb with respect to Ta.
                switch nargin
                    case 1
                        Ta=eye(4);
                        Tb=varargin{1};
                    case 2
                        Ta=varargin{2};
                        Tb=varargin{1};
                    otherwise
                        error('Invalid number of arguments')
                end
                
                % obtaining Tranform of B with respect to A
                r=(Ta\eye(4))*Tb;
                
                q=Solid.transform2quatern(r);
                [K,theta]=Solid.quatern2aa(q);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function T=aa2transform(K,theta)
            %SOLID.AA2TRANSFORM
            %   T=AA2TRANSFORM(K,THETA)
            %   returns the transformation matrix that represents a rotation
            %   about K by the angle theta
            %
            q=Solid.aa2quatern(K,theta);
            T=Solid.quatern2transform(q);
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function q=aa2quatern(K,theta)
            q=zeros(1,4);
            q(1:3)=K(1:3)*sin(theta/2);
            q(4)=cos(theta/2);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function [K,theta]=quatern2aa(q)
            theta=2*acos(q(4));
            if abs(theta)<0.001
                K=[0 0 0]';
            else
                K=(q(1:3)/sin(theta/2))';
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function q=transform2quatern(T)
            q=zeros(1,4);
            q(4)=0.5*(sqrt(1+trace(T(1:3,1:3))));
            q(1)=(T(3,2)-T(2,3))/(4*q(4));
            q(2)=(T(1,3)-T(3,1))/(4*q(4));
            q(3)=(T(2,1)-T(1,2))/(4*q(4));
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function T=quatern2transform(q)
            T=zeros(4,4);
            T(4,4)=1;
            T(1,1)=1-(2*q(2)^2)-(2*q(3)^2);
            T(1,2)=2*(q(1)*q(2)-q(3)*q(4));
            T(1,3)=2*(q(1)*q(3)+q(2)*q(4));
            T(2,1)=2*(q(1)*q(2)+q(3)*q(4));
            T(2,2)=1-(2*q(1)^2)-(2*q(3)^2);
            T(2,3)=2*(q(2)*q(3)-q(1)*q(4));
            T(3,1)=2*(q(1)*q(3)-q(2)*q(4));
            T(3,2)=2*(q(2)*q(3)+q(1)*q(4));
            T(3,3)=1-(2*q(1)^2)-(2*q(2)^2);
        end
        

            
    end
    
    methods(Access=protected)
        
%         function destroyPhysicsHandle(solid)
%             
%             % deleting associated c++ Solid object (in the the future, a
%             % more direct way of checking if the handle is valid will be
%             % implemented
%             try
%                 PhysicsWorld.PhysicsFunction(solid.ClassIndex,...
%                 solid.MethodIndexMap('Destructor'),solid.PhysicsHandle);
%             catch
%                 
%             end
%             
%         end

    end
            
                
    
    methods (Static,Access=protected)
        function map=getMethodIndexMap
            
            map=containers.Map;
            
            % adding methods index and string description pairs
            map('Constructor')=int32(0);
            map('getRotation')=int32(1);
            map('getPosition')=int32(2);
            map('updateTransform')=int32(3);
            map('printProperties')=int32(4);
            map('printTrimesh')=int32(5);
            map('setTransform')=int32(6);
            map('getTransform')=int32(7);
            map('collisionPairTest')=int32(9);
            map('Destructor')=int32(-1);
            
        end
        
        function map=getGeometryIndexMap
            
            map=containers.Map;
            
            map('Plane')=int32(0);
            map('Box')=int32(1);
            map('Sphere')=int32(2);
            map('Trimesh')=int32(3);
            map('StaticTrimesh')=int32(4);
        end
            
        
    end
    
end


function size=getAverageSize(solid)
vertices=solid.DefaultVertices;
size(1)=abs(max(vertices(:,1))-min(vertices(:,1)));
size(2)=abs(max(vertices(:,2))-min(vertices(:,2)));
size(3)=abs(max(vertices(:,3))-min(vertices(:,3)));
end
                
                    
                    
            