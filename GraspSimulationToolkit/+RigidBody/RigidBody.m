classdef RigidBody < BaseClasses.Node & BaseClasses.MexObjectInterface
    
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   % Rigid Body protected attributes
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   properties(SetAccess = protected)
       
       % identification properties
       mModelName;
       mTag
       
       % mass properties
       mInertiaTensor = eye(3);
       mCOG = zeros(3,1);
       mMass = 1;
       
       % shape
       mShape = Shape.Shape;
       
       
       
   end
   
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   % Rigid Body collision flags
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   properties(Constant = true)
       
       COLLISION_DYNAMIC = int32(1);
       COLLISION_KINEMATIC = int32(2);
       COLLISION_STATIC = int32(3);
       
   end
   
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   % Mex Interface protected properties
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   properties(SetAccess = protected)
       
       mParentPhysicsWorld %    This property contains a reference to a Physics
                           %    World object only when its state flag indicates
                           %    in use.
                           
       % collision state
       mCollisionFlag  = RigidBody.RigidBody.COLLISION_DYNAMIC; % COLLISION_DYNAMIC | COLLISION_KINEMATIC | COLLISION_STATIC                   
   
   end
   
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   % Mex Interfaces static properties
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   properties(Constant = true)
       
       sMexClassIndex = int32(1);
       sMexGatewayFunction = [];
       sMexMethodIndexMap = RigidBody.RigidBody.getMexMethodIndexMap;
       
   end
   
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   % Mex Interface instance methods
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   % All of the methods that start with the "mex" word make a direct call
   % to the associated mex function.
  methods
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function mexSetTransform(rb,transform,transformSpace)
           import RigidBody.*
           
           % class Id
           cId = RigidBody.sMexClassIndex;           
           % method Id
           mId = RigidBody.sMexMethodIndexMap('setTransform');
           
           RigidBody.sMexGatewayFunction(cId,mId,rb.mMexObjectHandle,transform,transformSpace);
           
       end
       
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function transform = mexGetTransform(rb,transformSpace)
           import RigidBody.*
           
           % class Id
           cId = RigidBody.sMexClassIndex;           
           % method Id
           mId = RigidBody.sMexMethodIndexMap('setTransform');
           
           transform = RigidBody.sMexGatewayFunction(cId,mId,rb.mMexObjectHandle,transformSpace);
           
       end
       
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function mexPerformCollisionTest(rb,rb2)
           
       end
       
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function mexApplyForce(rb,force)
           
       end
       
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function mexApplyMoment(rb,moment)
           
       end
       
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function mexSetCollisionState(rb,state)
           
       end
       
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function state = mexGetCollisionState(rb)
           
           state = rb.mCollisionState;
           
       end
       
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function state = getMexObjectState(rb)
           
           state = rb.mMexObjectState;
           
       end
       
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function mexUpdateFromMexObject(rb)
           
       end
       
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function mexUpdateToMexObject(rb)
           
       end
       
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function consInfo = getMexConstructionInfoStruct(rb)
           
           consInfo = rb.getConstructionInfoStruct;
           
       end
       
  end  
  
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   % Mex Interface class methods
   % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   methods(Static = true)
       % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function map = getMexMethodIndexMap
           
           map = containers.Map;
           
       end
       
   end
           
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % constructor and initialization methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function rb = RigidBody(varargin)
            % this method creates a rigid body in accordance to the input
            % arguments.
            
            if nargin == 0
                
                rb.mShape.setParentNode(rb);
                return;
                
            end
            
            switch class(varargin{1})
                case 'char'
                    
                    rb.loadFromModel(varargin{1});
                    
                case 'struct'
                    
                    rb.loadFromStruc(varargin{1});
                    
                otherwise
                    
                    error('Invalid input argument')
                    
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFromModel(rb,modelName)
            
            rb.loadFromStruct(Toolkit.loadModelData('RigidBody.RigidBody',modelName,'ConstructionInfo'));
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFromStruct(rb,constructionInfoStruct)
            
            % entering new data
            rb.mModelName = constructionInfoStruct.ModelName;
            rb.mTag = constructionInfoStruct.Tag;
            rb.mMass = constructionInfoStruct.Mass;
            rb.mCOG = constructionInfoStruct.COG;
            rb.mInertiaTensor = constructionInfoStruct.InertiaTensor;
            %rb.setScale(constructionInfoStruct.Scale);
            
            shape = Shape.Shape(constructionInfoStruct.Shape.ModelName);
            shape.setTransform(constructionInfoStruct.Shape.Transform,Transform.PARENT_SPACE);
            shape.setScale(constructionInfoStruct.Shape.Scale);
            
            
            rb.setShape(shape);    
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function consInfo = getConstructionInfoStruct(rb)
            
            consInfo.ModelName = rb.mModelName;
            consInfo.Tag = rb.mTag;
            consInfo.Mass = rb.mMass;
            consInfo.COG = rb.mCOG;
            consInfo.InertiaTensor = rb.mInertiaTensor;
            consInfo.CollisionFlag = rb.mCollisionFlag;
            %consInfo.Scale = rb.mScale;
            consInfo.Shape = rb.mShape.getConstructionInfoStruct;
            
        end
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % delete method
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function delete(rb)
            
            rb.mShape.removeParentNode;
            rb.delete@BaseClasses.Node;
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Static registration utility methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Static = true)
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function createXMLRegistrationTemplate(modelName)            
            % creates an XML file corresponding the the structure of the
            % rigid body model to be registered.  Once the data has been entered
            % accordingly, save the xml and calle the
            % Toolkit.registerModel('RigidBody.RigidBody',xmlFileName) method to register
            % the model with the specifications given in the xml file.
            
            xmlStruct.ModelName = modelName;
            xmlStruct.Tag = ' ';
            xmlStruct.Mass = '1';
            xmlStruct.COG = '[0;0;0]';
            xmlStruct.InertiaTensor = 'eye(3)';
            %xmlStruct.Scale = '[1 1 1]';            
            xmlStruct.EdgeColor = 'Color.BLUE';
            xmlStruct.FaceColor = 'Color.BLUE';
            
            shapeStruct.ModelName = 'undefined';
            shapeStruct.Transform = 'eye(4)';
            shapeStruct.Scale = '[1 1 1]';
            
            xmlStruct.Shape = shapeStruct;
            
            xmlStr = xml_format(xmlStruct,'off','RigidBodyModel');
            %disp(xmlStr)
            
            % creating xml file
            fName = [modelName,'.xml'];
            % document header
            headerStr = sprintf('%s\n','<!-- RigidBody Model Registration File -->'); 
            
            % document instructions
            instructionStr(1) = {sprintf('%s\n','<!-- Instructions -->')};
            
            % opening file for writing
            file = fopen(fName,'w');
            
            % writing xml header as a comment entry
            fprintf(file,'%s',headerStr);
            
            % writing xml instructions as comment entries
            for n = 1:length(instructionStr);
                fprintf(file,'%s',instructionStr{n});
            end
            
            % writing xml contents
            fprintf(file,'%s',xmlStr);
            
            % closing file
            fclose(file);
            
            % opening file
            open(fName);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function [modelName,modelDataFiles,modelDocuments] = parseXMLRegistrationDocument(xmlFileName)
            % parseXMLRegistrationDocument
            %   [modelName,modelDataFiles,modeDocuments] = parseXMLRegistrationDocument(xmlFileName)
            %   Parses a xml document and returns the corresponding data.
            %   The results and the contents of each output variable are
            %   different for every class. The input argument must contain
            %   an absolute path to a xml document.
            fprintf('\nStarting xml document parsing for shape object')
            
            import Shape.*
            
            xmlStruct = xml_load(xmlFileName,'off');
            
            % retrieving model name
            modelName = xmlStruct.ModelName;
            
            
            try
                
                % retrieving construction Info
                constructionInfo.ModelName = xmlStruct.ModelName;
                constructionInfo.Tag = xmlStruct.Tag;
                constructionInfo.Mass = eval(xmlStruct.Mass);
                constructionInfo.COG = eval(xmlStruct.COG);
                constructionInfo.InertiaTensor = eval(xmlStruct.InertiaTensor);
                %constructionInfo.Scale = eval(xmlStruct.Scale);
                constructionInfo.EdgeColor = eval(xmlStruct.EdgeColor);
                constructionInfo.FaceColor = eval(xmlStruct.FaceColor);

                shape.ModelName = xmlStruct.Shape.ModelName;
                shape.Transform = eval(xmlStruct.Shape.Transform);
                shape.Scale = eval(xmlStruct.Shape.Scale);
                            
            catch
                
                error('Expresion entered in xml document is incorrect')
                
            end
            
            constructionInfo.Shape = shape;
            
            % collecting model data files into struct
            modelDataFiles.ConstructionInfo = constructionInfo;
            
            % collecting model documents into cell array
            modelDocuments{1} = xmlFileName;   
            
            fprintf('\nCompleted xml document parsing for RigidBody object')
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public get methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getModelName(rb)
            
            val = rb.mModelName;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getShape(rb)
            
            val = rb.mShape;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getTag(rb)
            
            val = rb.mTag;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getMass(rb)
            
            val = rb.mMass;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getInertia(rb)
            
            val = rb.mInertia;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getCOG(rb)
            
            val = rb.mCOG;
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public set methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setTag(rb,val)
            
            if ~isa(val,'char')
                
                error('Input must be a char array of 1 x d')
                
            end
            
            rb.mTag = val;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setMass(rb,val)
            
            rb.mMass = val(1);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setCOG(rb,val)
            
            rb.mCOG = reshape(val(1:3),3,1);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setInertia(rb,val)
            
            rb.mInertia = val(1:3,1:3);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setShape(rb,shape)
            
            if ~isa(shape,'Shape.Shape')
                
                error('Input must be a Shape object')
                
            end
            
            rb.mShape.removeParentNode;
            shape.setParentNode(rb);
            rb.mShape = shape;
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % overloaded transform node methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
    
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function setQuaternion(rb,quatern,transformSpace)            
%             % takes a 1 x 4 vector containing the corresponding values
%             % [x y z w] of the quaternion in the given transform space.
%             
%             rb.mShape.setQuaternion(quatern,transformSpace)            
%             rb.setQuaternion@BaseClasses.Node(quatern,transformSpace);
%             
%         end
%         
%         % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function setPosition(rb,pos,transformSpace)
%             % takes a 3 x 1 vector containing the corresponding values
%             % [x y z] of the position in the given transform space.         
%             
%             rb.mShape.setPosition(pos,transformSpace)            
%             rb.setPosition@BaseClasses.Node(pos,transformSpace);
%             
%         end
%         
%         % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function setTransform(rb,transform,transformSpace)
%             % takes a 4 x 4 array containing the corresponding values
%             % of the position and orientation in the given transform space.
%             
%             rb.mShape.setTransform(transform,transformSpace)            
%             rb.setTransform@BaseClasses.Node(transform,transformSpace);
%             
%         end
%         
%         % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function setOrientation(rb,orient,transformSpace)
%             % takes a 3 x 3 array containing the corresponding values
%             % of the orientation in the given transform space.
%             
%             rb.mShape.setOrientation(orient,transformSpace)            
%             rb.setOrientation@BaseClasses.Node(orient,transformSpace);
%             
%         end
%         
%         % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function setScale(rb,scale)
%             
%             rb.mShape.setScale(scale)            
%             rb.setScale@BaseClasses.Node(scale);
%              
%         end        
     
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % overloaded graphics manipulation node methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function update(rb)
            
            rb.mShape.update;
            rb.update@BaseClasses.Node;
            
        end        
                
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function createGraphicsInstance(rb)
            
            rb.mShape.createGraphicsInstance;
            rb.createGraphicsInstance@BaseClasses.Node;
                        
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function destroyGraphicsInstance(rb)
            
            rb.mShape.destroyGraphicsInstance
            rb.destroyGraphicsInstance@BaseClasses.Node;
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % overloaded graphics manipulation protected methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Access = protected)        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function displayWindow(rb)
            
            rb.mShape.displayWindow;
            
        end
        
    end
end
       