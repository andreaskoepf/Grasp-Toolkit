classdef ArticulatedBody < handle
    % The role of this class is to implement functionality
    properties(Dependent=true)
        
        JointValues
        JointOffsets
        JointLimits        
        
        BaseObjectVisible
    end
    
    properties(Dependent=true,SetAccess=protected)
        DH
        
    end
    
    properties
        %BaseFrame=eye(4); %set method sets base object frame
        BaseFrame=eye(4); % BaseFrame
        BaseObject=[];
        Links
        Color
        IsDynamic=int32(0);
        InPhysicsMode=false
    end
    
    properties(SetAccess=protected)        
        
        DOF
        
    end
    
    
    % physics related properties
    properties(SetAccess=protected)
        PhysicsHandle
        ClassIndex=int32(3);
        MethodIndexMap=ArticulatedBody.getMethodIndexMap;
    end
    
    methods
        function kc=ArticulatedBody(varargin)
            
            % should take three kinds of arguments kc,link array and char
            % argument
            switch nargin
                case 0                    
                    kc.Links=Link;
                    return;
                case 1
                    
                        if isa(varargin{1},'ArticulatedBody')
                            
                            % copy constructor
                            
                            kc.BaseObject=varargin{1}.BaseObject;
                            kc.BaseFrame=varargin{1}.BaseFrame;
                            kc.Links=varargin{1}.Links;
                            
                        elseif isa(varargin{1},'Link')
                            
                            kc.Links=varargin{1};
                            
                            
                        elseif isa(varargin{1},'char')
                            % load model from data file
                            
                            % this will be added only if needed
%                             s=Toolkit.loadToolkitFile('@ArticulatedBody','Models',varargin{1}...
%                                 ,'Data.mat');
%                             data=s.Data;
                        end
                            
            end    
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        
        function set.Links(kc,segments)
            % this method should only be used if the segments need to be
            % set to a whole new different group of objects
            % it also initializes the property DOF
            
            if isa(segments,'Link')
                
                % assigning segments and connecting
                kc.Links=segments;
                % kc.Links.connect;
                
                % setting DOF
                kc.DOF=length(kc.JointValues); 
                
                % setting joint values equal to 0
                kc.JointValues=zeros(kc.DOF,1);

            else
                error('Invalid argument type for Links')
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function addLink(kc,link)
            
            if isa(link,'Link')
                
                % assigning segments and connecting
                kc.Links=[kc.Links link];
                %kc.Links.connect;
                
                % setting DOF
                kc.DOF=length(kc.JointValues); 
                
                % setting joint values equal to 0
                kc.JointValues=zeros(kc.DOF,1);

            else
                error('Invalid argument type for Links')
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.JointValues(kc,q)
                        
            q=q(:);
            index=0;
            %frame=kc.BaseFrame;
            for n=1:length(kc.Links);
                kc.Links(n).JointValues=q(1+index:kc.Links(n).DOF+index);
                % updating link frame
                %frame=frame*kc.Links(n).Transform;
                %kc.Links(n).Frame=frame;
                index=index+kc.Links(n).DOF;
            end
            
            kc.updateAllFrames;
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function jout=get.JointValues(kc)
            jout=zeros(kc.DOF,1);
            index=0;
            for n=1:length(kc.Links);
                jout(1+index:index+kc.Links(n).DOF)=kc.Links(n).JointValues;
                index=index+kc.Links(n).DOF;
            end
                
        end
            
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.JointOffsets(kc,qOffset)
            
            q=qOffset(:);
            index=0;
            for n=1:length(kc.Links);
                kc.Links(n).JointOffsets=q(1+index:kc.Links(n).DOF+index);
                index=index+kc.Links(n).DOF;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function jout=get.JointOffsets(kc)
            jout=zeros(kc.DOF,1);
            index=0;
            for n=1:length(kc.Links);
                jout(1+index:index+kc.Links(n).DOF)=kc.Links(n).JointOffsets;
                index=index+kc.Links(n).DOF;
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.JointLimits(kc,qlimits)
           
            q= reshape(qlimits,[length(qlimits) 2]);
            index=0;
            for n=1:length(kc.Links);
                kc.Links(n).JointLimits=q(1+index:kc.Links(n).DOF+index,1:2);
                index=index+kc.Links(n).DOF;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function jout=get.JointLimits(kc)
            jout=zeros(kc.DOF,2);
            index=0;
            for n=1:length(kc.Links);
                jout(1+index:index+kc.Links(n).DOF,:)=kc.Links(n).JointLimits;
                index=index+kc.Links(n).DOF;
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.BaseFrame(kc,frame)
            % sets object frame of reference.  All the objects that belong
            % to this object will be represented in relation to this frame
            % kc.Links(1).LocalFrame=frame;
            kc.BaseFrame=frame;
            kc.updateAllFrames;
            if kc.isBaseObjectValid
                kc.BaseObject.Frame=frame;
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function frame=get.BaseFrame(kc)
            
            if(kc.isBaseObjectValid)
                frame=kc.BaseObject.Frame;
            else
                frame=kc.BaseFrame;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.Color(kc,c)
            for n=1:length(kc.Links);
                kc.Links(n).Color=c;
            end
            
            if kc.isBaseObjectValid
                kc.BaseObject.Color=c;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.BaseObject(kc,obj)
            if isa(obj,'Solid')
                kc.BaseObject=obj;
                kc.BaseFrame=obj.Frame;
                
                return
            end
            
            error('invalid data type, use either Solid or any derived subclass')            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function dh=get.DH(kc)
            % setting DH
            
            dh=zeros(kc.DOF,4);
            
            index=0;
            for n=1:length(kc.Links);
                dh(1+index:index+kc.Links(n).DOF,1:4)=kc.Links(n).DH;
                index=index+kc.Links(n).DOF;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function update(kc)
            if kc.isBaseObjectValid
                kc.BaseObject.update;
            end
            
            for n=1:length(kc.Links);
                kc.Links(n).update;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function updateAllFrames(kc)
            % updates all bodies reference frames
            frame=kc.BaseFrame;
            for n=1:length(kc.Links);
                frame=frame*kc.Links(n).Transform;
                kc.Links(n).Frame=frame;
            end            
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.IsDynamic(kc,bool)
            if kc.isBaseObjectValid
                kc.BaseObject.IsDynamic=bool;
            end
            
            for n=1:length(kc.Links);
                kc.Links(n).IsDynamic=bool;
            end
            
            if(~isa(bool,'int32'))
                bool=int32(bool);
            end
                
            if((bool==int32(1))||(bool==int32(0)))
                kc.IsDynamic=bool;
            end
        end            
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setPhysicsHandle(kc)
            % assigns physics handle to the articulated body and to all of
            % the bodies that belong to it
            bodies=kc.getAllBodies;
            for n=1:length(bodies);
                bodies{n}.setPhysicsHandle;
            end
             
            % retrieving handle to physics object
            cId=kc.ClassIndex;
            mId=kc.MethodIndexMap('Constructor');
            kc.PhysicsHandle=PhysicsWorld.PhysicsFunction(cId,mId);
            
            kc.InPhysicsMode=true;
            % adding all bodies to the articulated body 
            for n=1:length(bodies)
                kc.addBody(bodies{n});
            end
             
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function updateFromPhysics(kc)
            if kc.isBaseObjectValid
                kc.BaseObject.updateFromPhysics;
            end
            
            for n=1:length(kc.Links);
                kc.Links(n).updateFromPhysics;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function updateToPhysics(kc)          
            
                
            kc.startUpdate;
            
            if kc.isBaseObjectValid
                kc.BaseObject.updateToPhysics;
            end
            
            for n=1:length(kc.Links);
                kc.Links(n).updateToPhysics;
            end
            
            kc.stopUpdate;
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function destroyPhysicsHandle(kc)
            
            % destroying handle to physics object
            if(kc.InPhysicsMode)
                cId=kc.ClassIndex;
                mId=kc.MethodIndexMap('Destructor');
                PhysicsWorld.PhysicsFunction(cId,mId,kc.PhysicsHandle);
            end
            
            bodies=kc.getAllBodies;
            for n=1:length(bodies);
                bodies{n}.destroyPhysicsHandle;
            end
            
            kc.InPhysicsMode=false;
        end 
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function bodies = getAllBodies(kc)
            bodies=cell(1,length(kc.Links)+1);
            for n=1:length(kc.Links);
                bodies{n}=kc.Links(n);
            end
            
            if kc.isBaseObjectValid
                bodies{n+1}=kc.BaseObject;
            else
                bodies(n+1)=[];
            end
        end
   
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
        function bool=isBaseObjectValid(kc)
            bool=(~isempty(kc.BaseObject) && isvalid(kc.BaseObject));
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function ctranspose(kc)
            
            for n=1:length(kc);                
                kc(n).setHandles;
                kc(n).update;                
            end
            
            grid on
            drawnow            
            figure(kc(1).Links(1).FigureHandle);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setHandles(kc)
            
            for n=1:length(kc)
                if (~isempty(kc(n).BaseObject) && isvalid(kc(n).BaseObject))
                    kc(n).BaseObject.setHandles;
                end
                for m=1:length(kc(n).Links);
                    kc(n).Links(m).setHandles;
                end
            end
        end
        
       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function drive(kc,jointValues)
           kc.ctranspose;
           for n=1:size(jointValues,2);
               kc.JointValues=jointValues(:,n);
               kc.update;
               drawnow;
           end
       end
       
       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function reducePatch(kc,factor)
           for n=1:length(kc.Links);
               kc.Links(n).reducePatch(factor);
           end
           
           if kc.isBaseObjectValid
               kc.BaseObject.reducePatch(factor);
           end
       end               
       
       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function set.BaseObjectVisible(kc,boolean)
           if kc.isBaseObjectValid
               kc.BaseObject.Visible=boolean;
           end
       end
       
       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function boolean=get.BaseObjectVisible(kc)
           if kc.isBaseObjectValid
               boolean=kc.BaseObject.Visible;
           else
               boolean=false;
           end
       end
       
       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function delete(kc)
           
           kc.destroyPhysicsHandle;
           
       end
       
       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function scale(kc,f)
           
           for n = 1:length(kc.Links);
               
                kc.Links(n).scale(f);
                
           end
           
           if kc.isBaseObjectValid
                kc.BaseObject(1).scale(f);
           end
       end
       
       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function data=toStruct(kc)
            
            warning off
            for n=1:length(kc);
                data(n)=struct(kc(n));
            end
            warning on
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFieldsFromStruct(kc,data)
            % kc.loadFieldsFromStruct(data)
            %       kc.loadFieldsFromStruct(data)   loads data from data
            %       structure fields onto object properties.  The data
            %       structure must've been created with the toStruct method
            %       or have the same fields as one created with the
            %       toStruct method.
            %       
            
            indexes=1:length(data);
            % assigning data to the fields
            for n=indexes;

                for m=1:length(data(n).Links)
                    links(m)=Phalanx(data(n).Links(m));
                end
                kc(n).Links=links;
                if ~isempty(data(n).BaseObject)
                    kc(n).BaseObject=Solid(data(n).BaseObject);
                end
                kc(n).BaseFrame=data(n).BaseFrame;
                kc(n).DOF=data(n).DOF;


            end
        end
        
        

        
        
    end
    
    methods(Access=protected)        
 
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function addBody(kc,body)            
            % this function adds the body to the articulated body once it
            % is assigned a valid physics handle
            
            if(kc.InPhysicsMode)
                cId=kc.ClassIndex;
                mId=kc.MethodIndexMap('addBody');
                PhysicsWorld.PhysicsFunction(cId,mId,kc.PhysicsHandle,body.PhysicsHandle);
            end
            
            
        end
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function startUpdate(kc)
            % this function is used to coordinate motions of all bodies
            % that belong to the articulated body during the simulation
            
            if(kc.InPhysicsMode)
                cId=kc.ClassIndex;
                mId=kc.MethodIndexMap('startUpdate');
                PhysicsWorld.PhysicsFunction(cId,mId,kc.PhysicsHandle);
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function stopUpdate(kc)
            % this function is called once each body's transform has been
            % updated.              
            
            if(kc.InPhysicsMode)
                cId=kc.ClassIndex;
                mId=kc.MethodIndexMap('stopUpdate');
                PhysicsWorld.PhysicsFunction(cId,mId,kc.PhysicsHandle);
            end
        end       
        
        
    end
    
    methods (Static,Access=protected)
        function map=getMethodIndexMap
            
            map=containers.Map;
            
            % adding methods index and string description pairs
            map('Constructor')=int32(0);
            map('addBody')=int32(1);
            map('startUpdate')=int32(2);
            map('stopUpdate')=int32(3);            
            map('Destructor')=int32(-1);
            
        end
        
    end
end