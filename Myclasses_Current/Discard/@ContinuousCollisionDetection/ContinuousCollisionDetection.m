classdef ContinuousCollisionDetection < handle
    
    properties(SetAccess = protected)
        mObjectA
        mObjectB
        mObjectAMexHandle=uint32(0);;
        mObjectBMexHandle= uint32(0);
        
        mMexHandle = uint32(0);
        
        mMexClassID = int32(4);
        
        mIsMexInstanceValid = false;
        
        mMexFunctionHandle = @MexFiles.BulletPhysicsC2AMex;
        
    end
    
    properties(Constant = true,SetAccess = protected)
        CCDMethodIndexMap = ContinuousCollisionDetection.getMethodIndexMap; % it returns a container with
                                               % with the corresponding char
                                               % integer pairs
                                               
    end
    
    %  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Collision Flags
    %  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(Constant = true)
        
        COLLISION_FOUND = int32(-1);  % collision found at t = 0
        COLLISION_FREE = int32(0); % no collision was found
        TOC_FOUND = int32(1); % toc found
        
    end
    
    
    methods(Static = true,Access = protected)
        function map = getMethodIndexMap
            map = containers.Map('Constructor',int32(0));
            map('setObjectA') = int32(1);
            map('setObjectB') = int32(2);
            map('performCCDTest') = int32(3);
            map('Destructor') = int32(-1);
            
        end
        
    end
    
    % Constructor
    methods
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function ccdObj = ContinuousCollisionDetection
            
            % creating instance and retrieving object handle
            % ccdObj.createInstance;
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setObjectA(ccdObj,solid,localTransform)
            
            if nargin == 2
                localTransform = eye(4);
            else
                if ~(all(size(localTransform)==[4 4]))
                    error('must enter a 4 x 4 transform for the second argument')
                end
            end
            
            if ~ccdObj.mIsMexInstanceValid
                
                ccdObj.createMexInstance(ccdObj);
                
            end
                
                
                
            cId=ccdObj.mMexClassID;
            mId=ContinuousCollisionDetection.CCDMethodIndexMap('setObjectA');
            ccdObj.mMexFunctionHandle(cId,mId,ccdObj.mMexHandle,solid.PhysicsHandle,...
                localTransform);

            ccdObj.mObjectA = solid;
            ccdObj.mObjectAMexHandle = solid.PhysicsHandle;           
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setObjectB(ccdObj,solid,localTransform)
            
            % checking that the third argument is valid
            if nargin == 2
                localTransform = eye(4);
            else
                if ~(all(size(localTransform)==[4 4]))
                    error('must enter a 4 x 4 transform for the second argument')
                end
            end
            
            if ~ccdObj.mIsMexInstanceValid
                
                ccdObj.createMexInstance(ccdObj);
                
            end
                
                
                
            cId=ccdObj.mMexClassID;
            mId=ContinuousCollisionDetection.CCDMethodIndexMap('setObjectB');
            ccdObj.mMexFunctionHandle(cId,mId,ccdObj.mMexHandle,solid.PhysicsHandle,...
                localTransform);

            ccdObj.mObjectA = solid;
            ccdObj.mObjectAMexHandle = solid.PhysicsHandle;           
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function createMexInstance(ccdObj)
            
            if ~ccdObj.mIsMexInstanceValid
                cId=ccdObj.mMexClassID;
                mId=ContinuousCollisionDetection.CCDMethodIndexMap('Constructor');
                ccdObj.mMexHandle = ccdObj.mMexFunctionHandle(cId,mId,ccdObj);

                ccdObj.mIsMexInstanceValid = true;
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function destroyMexInstance(ccdObj)
            
            if ccdObj.mIsMexInstanceValid
                
                cId=ccdObj.mMexClassID;
                mId=ContinuousCollisionDetection.CCDMethodIndexMap('Destructor');
                ccdObj.mMexFunctionHandle(cId,mId,ccdObj.mMexHandle);

                ccdObj.mIsMexInstanceValid = false;
                
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function [collisionFlag,ccdResultStruct] = mexPerformCCDTest(ccdObj,objATransform0,objATransformf,...
                                            objBTransform0,objBTransformf)
        
            if ccdObj.mIsMexInstanceValid
                
                cId=ccdObj.mMexClassID;
                mId=ContinuousCollisionDetection.CCDMethodIndexMap('performCCDTest');
                
                switch nargout
                    
                    case 1         
                        collisionFlag = ccdObj.mMexFunctionHandle(cId,mId,ccdObj.mMexHandle,objATransform0,objATransformf,...
                                            objBTransform0,objBTransformf);
                                        
                    case 2 
                        [collisionFlag,ccdResultStruct] = ccdObj.mMexFunctionHandle(cId,mId,ccdObj.mMexHandle,objATransform0,objATransformf,...
                                            objBTransform0,objBTransformf);
                                        
                    otherwise
                         [collisionFlag,ccdResultStruct] = ccdObj.mMexFunctionHandle(cId,mId,ccdObj.mMexHandle,objATransform0,objATransformf,...
                                            objBTransform0,objBTransformf); 
                                        
                end                
                                        
                                        
            else
                
                error('mex instance is invalid or has not been instantiated')
                
            end
            
        end
       
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function bool = isMexInstanceValid(ccdObj)
            
            bool = ccdObj.mIsMexInstanceValid;
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function delete(ccdObj)
            
            ccdObj.destroyMexInstance;
            
        end
        
    end
    
end
        

                
                
                
        
            
                                               
                                               
                                               
                                               
        