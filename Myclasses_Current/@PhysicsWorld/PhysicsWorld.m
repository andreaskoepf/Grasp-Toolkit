classdef PhysicsWorld < handle
    
    properties (SetAccess=protected) 
        PhysicsHandle
        FigureHandle
        AxisHandle
        ObjectContainer=cell(1);
        NumberOfObjects=0;
        
        % boolean for indicating if the simulation is initialized
        IsInitialized=false;
        
    end
    
    properties
        WorldAABB=[-20 20 -20 20 0 20]; % World Axis Aligned Bounding Box 
        GroundObject % Solid object
        Gravity=[0 0 -9.81];
    end
    
    
    properties (Constant,SetAccess=protected)
        MethodIndexMap=PhysicsWorld.getMethodIndexMap;
        ClassIndex=int32(1);
        PhysicsFunction=@MexFiles.BulletPhysicsC2AMex;
    end
    
    events(ListenAccess=protected,NotifyAccess=protected)
        
        UPDATE
        UPDATE_FROM_PHYSICS
        
    end
        
        
    
    methods
        function world=PhysicsWorld
            
            world.GroundObject=StaticPlane([0 0 1]',0,40);
            world.GroundObject.Color=[0.6 0.6 0.6]';
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function initializeSimulation(world)
            % C++ method call
            % Creates handles for all objects registered in the physics
            % world and the physics world itself, adds all the objects to
            % the world and performs initialization routines.
            
            if(~world.IsInitialized)
                %world.closeSimulation;                
                world.setPhysicsHandle;                
                
                cId=world.ClassIndex;
                mId=PhysicsWorld.MethodIndexMap('initializeSimulation');
                world.PhysicsFunction(cId,mId,world.PhysicsHandle);                
                world.IsInitialized=true;
                
            end
            
            % Instantiating Simple Physics environment object and
            % retrieving handle
            
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function stopSimulation(world)
            
            if(~world.IsInitialized)
                warning(['Simulation has not been initialized yet'])
            end            
            % C++ method call 
            % Removes all bodies from the dynamics world and closes any
            % visualizers that were opened when the call to closeSimulation
            % was made
            cId=world.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('stopSimulation');
            world.PhysicsFunction(cId,mId,world.PhysicsHandle);  
            
            
            %world.destroyPhysicsHandle;
            %world.IsInitialized=false;
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function stepSimulation(world)
            
            if(~world.IsInitialized)
                warning(['Simulation has not been initialized yet'])
            end            
            % C++ method call
            % this method advances the simulation one time step.
            % if the simulation was running continously then the simulation
            % is first paused and then advanced one step
            cId=world.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('stepSimulation');
            world.PhysicsFunction(cId,mId,world.PhysicsHandle);            
            

            % updating the position and orientation data for all objects in
            % the simulation
            %%world.updateFromPhysics;
                
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function resetSimulation(world)
            
            if(~world.IsInitialized)
                warning(['Simulation has not been initialized yet'])
            end
            % C++ method call
            % this method resets the simulation to the initial state.
            cId=world.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('stepSimulation');
            world.PhysicsFunction(cId,mId,world.PhysicsHandle);            
            

            % updating the position and orientation data for all objects in
            % the simulation
            %%world.updateFromPhysics;
                
            
        end
                
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function startSimulation(world)
            if(~world.IsInitialized)
                world.initializeSimulation;
            end
            % C++ method call
            % this method will either initialize the visualizer and start
            % the simulation, resume the simulation if it had been
            % previously paused or do nothing if the simulation is already
            % running
            cId=world.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('startSimulation');
            world.PhysicsFunction(cId,mId,world.PhysicsHandle);
        end
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function resumeSimulation(world)
            if(~world.IsInitialized)
                warning(['Simulation has not been initialized yet'])
            end
            
            % C++ method call
            % this method resumes the simulation 
            % the visualizer must be opened for this method to be valid
            cId=world.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('resumeSimulation');
            world.PhysicsFunction(cId,mId,world.PhysicsHandle);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function pauseSimulation(world)
            if(~world.IsInitialized)
                warning(['Simulation has not been initialized yet'])
            end
            
            % C++ method call
            % this method pauses the simulation 
            % the visualizer must be opened for this method to be valid
            cId=world.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('pauseSimulation');
            world.PhysicsFunction(cId,mId,world.PhysicsHandle);
        end
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function addBody(world,body)
            
            
            if isa(body,'cell')
                for n=1:length(body);
                    world.addSingleBody(body{n});
                end
            else
                world.addSingleBody(body);
            end
            
                        
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function body=getBody(world,key)
            
                body=world.ObjectContainer{key,1};          
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function removeBody(world,key)   
            
                if(world.IsInitialized)
                        world.removeBodyFromPhysicsWorld(world.getBody(key))
                        
                        % destroy physics handle
                        world.getBody(key).destroyPhysicsHandle;
                end
            
                world.ObjectContainer{key,1}=[];
                
                
                % deleting listeners
                delete(world.ObjectContainer{key,2}(1))
                delete(world.ObjectContainer{key,2}(2))
                
                world.ObjectContainer{key,2}=[];
                
                world.decreaseNObj;
                
                
            
        end        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
        function addlistener(world,obj)
            
            h(1)=world.addlistener@handle('UPDATE',@(src,evnt)obj.update);
            h(2)=world.addlistener@handle('UPDATE_FROM_PHYSICS',@(src,evnt)obj.updateFromPhysics);
            
            
            %storing handles in the Object Container
            world.ObjectContainer{world.NumberOfObjects,2}=h;
        
        end  
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function updateFromPhysics(world)
            world.notify('UPDATE_FROM_PHYSICS')
        end      

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function update(world)
            
            world.notify('UPDATE')
            
%             for n=1:world.NumberOfObjects;
%                 world.ObjectContainer{n,1}.update;
%                 
%             end
                
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function ctranspose(world)
            
            % setting graphics for the ground object
            world.GroundObject.setHandles;
            world.GroundObject.update;
            
            for n=1:world.NumberOfObjects;
                world.ObjectContainer{n,1}.setHandles;  % setting graphics handles
                world.ObjectContainer{n,1}.update;  % updating graphic data                
            end
            
            
                
                world.FigureHandle=world.GroundObject.FigureHandle;
                
                        
                world.AxisHandle=get(world.FigureHandle,'CurrentAxes');
                set(world.AxisHandle,'XLim',world.WorldAABB(1:2))
                set(world.AxisHandle,'YLim',world.WorldAABB(3:4))
                set(world.AxisHandle,'ZLim',world.WorldAABB(5:6))
            
            grid on
            drawnow; 
            figure(world.FigureHandle);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function printObjects(world)
            cId=world.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('printSolidObjects');
            world.PhysicsFunction(cId,mId,world.PhysicsHandle)
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function printHandleValues(world)
            cId=world.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('printHandleValues');
            world.PhysicsFunction(cId,mId,world.PhysicsHandle)
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function delete(world)
            
            if(world.IsInitialized)
                world.destroyPhysicsHandle;
            end
            
        end        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%        
        function set.GroundObject(world,ground)
            
            if(isa(ground,'Solid'))
                ground.IsDynamic=false;
                ground.setAsStaticTrimesh;
                world.GroundObject=ground;
            else
                error('Object is not of or a derived type from Solid')
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function s=toStruct(world)
            warning off
            s=struct(world);
            s=rmfield(s,'PhysicsFunction');
            s=rmfield(s,'ObjectContainer');
            s=rmfield(s,'ClassIndex');
            s=rmfield(s,'MethodIndexMap');
            warning on
        end
            
        
    end
    
    methods (Access=protected)
        
        
        function addSingleBody(world,body)
            % adds body to world container
            
            if ~PhysicsWorld.isValidPhysicsBody(body)
                error('added object or contained objects are not valid for the physics simulation');
            end
            
            newKey=world.NumberOfObjects+1;
            world.ObjectContainer{newKey,1}=body;
            world.increaseNObj;
            world.addlistener(body);
            
            if(world.IsInitialized)
                body.setPhysicsHandle;
                if(isa(body,'Solid'))
                    world.addBodyToPhysicsWorld(body)
                else
                    try
                        bodies=body.getAllBodies;
                        
                        for n=1:length(bodies);                            
                            world.addBodyToPhysicsWorld(bodies{n});
                        end
                        
                    catch
                        error('body could not be added to the physics world')
                    end
                end
            end
                                           
            
        end
        
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function addBodyToPhysicsWorld(world,obj)
            
            cId=PhysicsWorld.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('addBody');
            if(isa(obj.PhysicsHandle,'uint32'))
                disp('handle type uint32')
            end
            world.PhysicsFunction(cId,mId,world.PhysicsHandle,obj.PhysicsHandle(1));

        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
        function setPhysicsHandle(world)
            

            % setting physics handles for ground object
            world.GroundObject.setPhysicsHandle
            
            
            
            % setting physics handles for all objects
            for n=1:world.NumberOfObjects;
                

                obj=world.ObjectContainer{n,1};
                obj.setPhysicsHandle;
                
                
            end
            
            %setting physics handle for the world
            cId=world.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('Constructor');
            world.PhysicsHandle=world.PhysicsFunction(cId,mId,world);
            
            % adding ground to physics world
            world.setGroundToPhysicsWorld;
            
            
            % adding objects to the world
            for n=1:world.NumberOfObjects;
                body=world.ObjectContainer{n,1};
                if(isa(body,'Solid'))
                    world.addBodyToPhysicsWorld(world.ObjectContainer{n,1});
                else
                    
                    bodies=body.getAllBodies;
                    
                    for m=1:length(bodies);
                        
                        world.addBodyToPhysicsWorld(bodies{m});
                        
                    end
                    
                end
            end
                        
            
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function destroyPhysicsHandle(world)
            
            % needs a way to check if the physics handle is valid            
            world.PhysicsFunction(PhysicsWorld.ClassIndex,PhysicsWorld.MethodIndexMap('Destructor'),...
                world.PhysicsHandle);
            
            % destroy the ground object
            world.GroundObject.destroyPhysicsHandle;
            
            % destroy handles for all registered objects
            for n=1:world.NumberOfObjects;

               world.ObjectContainer{n,1}.destroyPhysicsHandle;
                
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setGroundToPhysicsWorld(world)
            cId=PhysicsWorld.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('setGroundObject');
            if(isa(world.GroundObject.PhysicsHandle,'uint32'))
                disp('handle type uint32')
            end
            world.PhysicsFunction(cId,mId,world.PhysicsHandle,world.GroundObject.PhysicsHandle(1));
            
        end            
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function removeBodyFromPhysicsWorld(world,obj)
            
            % this function will call the removeBody method of the
            % SimplePhysicsEnvironment class
            
            cId=PhysicsWorld.ClassIndex;
            mId=PhysicsWorld.MethodIndexMap('removeBody');            
            world.PhysicsFunction(cId,mId,world.PhysicsHandle,obj.PhysicsHandle(1));
            
            
        end
            
               
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                      
        function decreaseNObj(world)
            world.NumberOfObjects=world.NumberOfObjects-1;
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function increaseNObj(world)
            world.NumberOfObjects=world.NumberOfObjects+1;
        end
        
    end
    
    methods (Static)
        
        
        function bool=isValidPhysicsBody(object)
            % check is the object is of a valid class for the simulation
            % by it it belongs to the solid class or if it contains the 
            % required methods
            if(isa(object,'Solid'))
                bool=true;
                return;
            end
            
            if(ismethod(object,'setPhysicsHandle')&&ismethod(object,'destroyPhysicsHandle')...
                &&ismethod(object,'updateFromPhysics')&&ismethod(object,'updateToPhysics')...
                &&ismethod(object,'getAllBodies'))
                % cheking every object inside the parent object
                bodies=object.getAllBodies;
                
                for n=1:length(bodies);
                    if(~PhysicsWorld.isValidPhysicsBody(bodies{n}))
                        bool=false;
                        return;
                    end
                end
                
                bool=true;
                
            else
                bool=false;
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function map=getMethodIndexMap
            
            map=containers.Map;
            
            % adding methods index and string description pairs
            map('Constructor')=int32(0);
            map('addBody')=int32(1);
            map('printSolidObjects')=int32(2);
            map('printHandleValues')=int32(3);
            map('setGroundObject')=int32(4);
            map('removeBody')=int32(5);
            map('startSimulation')=int32(6);
            map('resumeSimulation')=int32(7);
            map('pauseSimulation')=int32(8);
            map('stopSimulation')=int32(9);            
            map('stepSimulation')=int32(10);
            map('resetSimulation')=int32(11);
            map('initializeSimulation')=int32(12);
            map('Destructor')=int32(-1);
        end
        
    end
       
        
end