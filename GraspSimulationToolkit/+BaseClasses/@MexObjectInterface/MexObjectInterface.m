classdef MexObjectInterface < handle
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Mex Object Handle and Status
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(SetAccess = protected)
        
        mMexObjectHandle = uint32(0);
        mMexObjectState = BaseClasses.MexObjectInterface.STATUS_UNDEFINED;
                                    % undefined is the default value for
                                    % this property.  Certain events such
                                    % as instantiation cause that this
                                    % property take on other states values 
                                    % such as defined in Use to be set.
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Abstract Instance properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(Abstract = true,SetAccess = protected,Constant = true)
        
        sMexClassIndex % must define a unique integer that corresponds to 
                       % a particular class in the mex function.  This is
                       % necessary to determine which methods are called.
                       % The sMexClassIndexMap static property should be
                       % used to obtain the corresponding interger of the
                       % class that the mex Object represents.
                       
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Inherited Static Protected Properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(Constant = true,Access = protected)
        
%         sMexClassIndexMap = BaseClasses.MexObjectInterface.getMexClassIndexMap;
%         % stores a reference to a container map that contains the char
%         % integer value pairs that correspond to a given class name and
%         % index integer
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Mex Object Status Flags
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(Constant = true)
        
        STATUS_UNDEFINED = int32(0);
        STATUS_DEFINED = int32(1);
        STATUS_IN_USE = int32(2);
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Abstract Static Properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(Abstract = true, Constant  = true)
        
        sMexGatewayFunction % function handle to gateway mex function
        sMexMethodIndexMap % map container containing the char and integer pairs 
                     % corresponding to the method name and method index.
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Abstract Static Protected Methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Static = true,Abstract = true)
        
        map = getMexMethodIndexMap % generates the method index map and returns
                                % it.  This method should be used to
                                % initialize the sMethodIndexMap property
                                
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Inherited Static Public Methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Static  = true)
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function index = getMexMethodIndex(methodName)
            
            index = BaseClasses.MexObjectInterface.sMexMethodIndexMap(methodName);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function index = getMexClassIndex
            
            index = BaseClasses.MexObjectInterface.sMexClassIndex;
            
        end
        
%         % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function map = getMexClassIndexMap
%             
%             map = containers.Map;
%             
%         end
        
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Inherited Instance Public Methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function mexCreateInstance(mexObjInt)            
            
            if mexObjInt.mMexObjectStatus ~= BaseClasses.MexObjectInterface.STATUS_DEFINED
                
                % obtaining construction info
                constructionInfo  = mexObjInt.getMexConstructionInfoStruct;

                % obtaining the corresponding class and method indices
                cId = mexObjInt.sMexClassIndex;
                mId = BaseClasses.MexObjectInterface.sMexMethodIndexMap('Constructor');

                % calling the mex object constructor through the mex function
                % and storing the return mex object handle
                mexObjInt.mMexObjectHandle = BaseClasses.MexObjectInterface.sMexGatewayFunction(...
                    cId,mId,constructionInfo);

                % setting the status of the mex object to defined
                mexObjInt.mMexObjectState = BaseClasses.MexObjectInterface.STATUS_DEFINED;
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function mexDestroyInstance(mexObjInt)            
            
            if mexObjInt.mMexObjectStatus ~= BaseClasses.MexObjectInterface.STATUS_UNDEFINED
                
                % obtaining the corresponding class and method indices
                cId = mexObjInt.sMexClassIndex;
                mId = BaseClasses.MexObjectInterface.sMexMethodIndexMap('Destructor');

                % calling the mex object destructor through the mex function
                % and passing the stored handle to it
                BaseClasses.MexObjectInterface.sMexGatewayFunction(cId,mId,...
                    mexObjInt.mMexObjectHandle);

                % setting the status of the mex object to defined
                mexObjInt.mMexObjectState = BaseClasses.MexObjectInterface.STATUS_UNDEFINED;
                
            end                
            
        end
        
    end     
    
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Abstract Instance Public Methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Abstract = true)        
      
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        constructionInfo =  getMexConstructionInfoStruct(mexObjInt);
        % this method needs to return data structure that contains the
        % necessary information to instantiate the corresponding mexObject
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        mexUpdateFromMexObject(mexObjInt);
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        mexUpdateToMexObject(mexObjInt);
        
    end
    
end
        
        
        