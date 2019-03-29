% redesign scaling and its effects on transform operations and the mesh
% class

classdef Node < handle
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Transform related properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties (SetAccess = protected)
        mOrientation = eye(3); % 3 x 3 orientation matrix in local space
        mPosition = zeros(3,1); % 3 x 1 position vector in local space
        mScale = ones(1,3); % scale values in the x, y and z directions in 
                            % local space
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Entity containtment properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties (SetAccess = protected, GetAccess = protected)
        mParentNode
        mChildNodes; % containers.Map object
        mNumOfChildNodes = int32(0);
        mHasParentNode = false;
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Constructor
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function node = Node
            %import GST.BaseClasses.Transform
            
            % initializing the container
            node.mChildNodes = containers.Map(int32(0),node);
            node.mChildNodes.remove(int32(0));
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % delete method
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function delete(node)            
            
            node.removeAllChildNodes;
            node.destroyGraphicsInstance;
            
        end
        
    end
    
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Transform related get methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getQuaternion(node,transformSpace)
            % returns 1 x 4 vector containing the corresponding values
            % [x y z w] of the quaternion in the given transform space.
            switch nargin
                case 1
                    transformSpace=Transform.WORLD_SPACE;                    
            end
            
            
            orient = node.getOrientation(transformSpace);
            val = Transform.orientation2quatern(orient);
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getPosition(node, transformSpace)
            % returns 3 x 1 vector containing the corresponding values
            % [x y z] of the position in the given transform space.
            
            switch nargin
                case 1
                    transformSpace=Transform.WORLD_SPACE;                    
            end
            
            switch (transformSpace)
                case Transform.WORLD_SPACE
                    val = node.getWorldPosition;
                case Transform.LOCAL_SPACE
                    val = node.getLocalRelativePosition;
                case Transform.PARENT_SPACE
                    val = node.getLocalPosition;
                otherwise
                    val = node.getWorldPosition;
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getTransform(node,transformSpace)
            % returns 4 x 4 double array containing the corresponding the
            % orientation and position in the given transform space.
            
            switch nargin
                case 1
                    transformSpace=Transform.WORLD_SPACE;                    
            end
            
            switch transformSpace
                case Transform.WORLD_SPACE
                    val = node.getWorldTransform;
                case Transform.LOCAL_SPACE
                    val = node.getLocalRelativeTransform;
                case Transform.PARENT_SPACE
                    val = node.getLocalTransform;
                otherwise
                    val = node.getWorldTransform;
            end 
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getOrientation(node,transformSpace)
            % returns 3 x 3 double array containing the corresponding the
            % orientation in the given transform space.
            
            switch nargin
                case 1
                    transformSpace=Transform.WORLD_SPACE;                    
            end
            
            switch transformSpace
                case Transform.WORLD_SPACE
                    val = node.getWorldOrientation;
                case Transform.LOCAL_SPACE
                    val = node.getLocalRelativeOrientation;
                case Transform.PARENT_SPACE
                    val = node.getLocalOrientation;
                otherwise
                    val = node.getWorldOrientation;
            end
            
        end
        
         % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
         function val = getScale(node)
             
%              if node.hasParentNode
%                  
%                 parentScale = node.mParentNode.getScale;
%                 localScale = node.mScale;
%                 
%                 val = parentScale.*localScale;
%              else
%                  
%                  val = node.mScale;
%                  
%              end

                val = node.mScale;
             
         end
         
         % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
         function val = getDerivedScale(node)
             
             if node.hasParentNode
                 
                parentScale = node.mParentNode.getDerivedScale;
                parentRelScale = node.mParentNode.mScale;
                
                val = parentScale.*parentRelScale;
                
             else
                 
                %val = node.mScale;
                val = ones(1,3);
                 
             end
             
         end
         
         % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%         
         function val = getParentScale(node)
             
             if node.hasParentNode
                 
                 val = node.mParentNode.getScale;
                 
             else
                 
                 val = ones(1,3);
                 
             end
             
         end
         
         % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
         function val = getXScale(node)
             
             scale = node.getScale;
             val = scale(1);
             
         end
         
         % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
         function val = getYScale(node)
             
             scale = node.getScale;
             val = scale(2);
             
         end
         
         % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
         function val = getZScale(node)
             
             scale = node.getScale;
             val = scale(3);
             
         end
         
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Transform related set methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setQuaternion(node,quatern,transformSpace)            
            % takes a 1 x 4 vector containing the corresponding values
            % [x y z w] of the quaternion in the given transform space.
            switch nargin
                case 2
                    transformSpace=Transform.WORLD_SPACE;                    
            end
            
            orient = Transform.quatern2orient(quatern);
            node.setOrientation(orient,transformSpace);
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setPosition(node,pos,transformSpace)
            % takes a 3 x 1 vector containing the corresponding values
            % [x y z] of the position in the given transform space.         
            switch nargin
                case 2
                    transformSpace=Transform.WORLD_SPACE;                    
            end
            
            
            switch (transformSpace)
                case Transform.WORLD_SPACE
                    node.setWorldPosition(pos);
                case Transform.LOCAL_SPACE
                    node.setLocalRelativePosition(pos);
                case Transform.PARENT_SPACE
                    node.setLocalPosition(pos);
                otherwise
                    node.setWorldPosition(pos);
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setTransform(node,transform,transformSpace)
            % takes a 4 x 4 array containing the corresponding values
            % of the position and orientation in the given transform space.
            switch nargin
                case 2
                    transformSpace=Transform.WORLD_SPACE;
            end
            
            switch (transformSpace)
                case Transform.WORLD_SPACE
                    node.setWorldTransform(transform);
                case Transform.LOCAL_SPACE
                    node.setLocalRelativeTransform(transform);
                case Transform.PARENT_SPACE
                    node.setLocalTransform(transform);
                otherwise
                    node.setWorldTransform(transform);
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setOrientation(node, orient, transformSpace)
            % takes a 3 x 3 array containing the corresponding values
            % of the orientation in the given transform space.
            switch nargin
                case 2
                    transformSpace=Transform.WORLD_SPACE;
            end
            
            switch (transformSpace)
                case Transform.WORLD_SPACE
                    node.setWorldOrientation(orient(1:3,1:3));
                case Transform.LOCAL_SPACE
                    node.setLocalRelativeOrientation(orient(1:3,1:3));
                case Transform.PARENT_SPACE
                    node.setLocalOrientation(orient(1:3,1:3));
                otherwise
                    node.setWorldOrientation(orient(1:3,1:3));
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setScale(node,scale)
%             if node.hasParentNode
%                  
%                 parentScale = node.mParentNode.getScale;
%                 node.mScale = scale./parentScale;
%                 
%              else
%                  
%                  node.mScale = scale;
%                  
%             end
            
            node.mScale = reshape(scale,1,3);
            node.update;
            %node.setScale(reshape(scale,1,3));
             
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setXScale(node,val)
            
            scale = [val node.mScale(2) node.mScale(3)];
            
            node.setScale(scale);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setYScale(node,val)
            
            scale = [node.mScale(1) val node.mScale(3)];
            
            node.setScale(scale);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setZScale(node,val)
            
            scale = [node.mScale(1) node.mScale(2) val];
            
            node.setScale(scale);
            
        end
        
    end   
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Transform related protected get methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    methods (Access = protected)
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getWorldTransform(node)
            
            if node.hasParentNode
                parentScale = node.getDerivedScale';
                parentTransform = node.mParentNode.getWorldTransform;
                localTransform = [node.mOrientation parentScale.*node.mPosition;0 0 0 1];
                
                val = parentTransform*localTransform;
                
            else
                val = [node.mOrientation node.mPosition;0 0 0 1];
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getLocalTransform(node)
            
            parentScaleRel = node.mParentNode.getScale';
            val = [node.mOrientation parentScaleRel.*node.mPosition;0 0 0 1];
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getUnscaledLocalTransform(node)
            
            val = [node.mOrientation node.mPosition;0 0 0 1];
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getLocalRelativeTransform(node)            
            
            val = eye(4);            
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getWorldPosition(node)
            
            if node.hasParentNode
                orient = node.mParentNode.getWorldOrientation;
                
                parentScale = node.getDerivedScale';
                
                val = orient*(parentScale.*node.mPosition) + node.mParentNode.getWorldPosition;
                
            else
                val = node.mPosition;
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getLocalPosition(node)
            
            parentScaleRel = node.mParentNode.getScale';
            val = parentScaleRel.*node.mPosition;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getLocalRelativePosition(node)
                        
            val = zeros(3,1);            
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getWorldOrientation(node)
            
            if node.hasParentNode
                parentOrientation = node.mParentNode.getWorldOrientation;
                localOrientation = node.mOrientation;
                
                val = parentOrientation * localOrientation;
                
            else
                val = node.mOrientation;
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getLocalOrientation(node)
            
            val = node.mOrientation;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getLocalRelativeOrientation(node)            
            
            val = eye(3);            
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Transform related protected set methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    methods (Access = protected)
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setWorldTransform(node,transform)
            
            localTransform = node.convertWorldToLocalTransform(transform);
            
            node.mPosition = localTransform(1:3,4);
            node.mOrientation = localTransform(1:3,1:3);
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setLocalTransform(node,transform)
            
            node.mPosition = transform(1:3,4);
            node.mOrientation = transform(1:3,1:3);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setLocalRelativeTransform(node,transform)            
            
            orient = transform(1:3,1:3);
            pos = transform(1:3,4);
            
            node.mPosition =node.mOrientation*pos + node.mPosition;
            node.mOrientation = node.mOrientation*orient;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setWorldPosition(node,pos)
            
            node.mPosition = node.convertWorldToLocalPosition(pos);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setLocalPosition(node,pos)
            
            node.mPosition = [pos(1); pos(2); pos(3)];
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setLocalRelativePosition(node, pos)
            
            node.mPosition =node.mOrientation*pos + node.mPosition;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setWorldOrientation(node,orient)
                       
            node.mOrientation = node.convertWorldToLocalOrientation(orient);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setLocalOrientation(node,orient)
            
            node.mOrientation = orient;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setLocalRelativeOrientation(node,orient)

            node.mOrientation = node.mOrientation*orient;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function localTransform = convertWorldToLocalTransform(node,transform)
            
            if node.hasParentNode
                
                parentWorldTransform = node.mParentNode.getWorldTransform;
                invTransform = Transform.calculateTransformInverse(parentWorldTransform);
                localTransform = invTransform*transform;
                
            else
                
                localTransform = transform;
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function localOrient = convertWorldToLocalOrientation(node,orient)
            
            if node.hasParentNode
                
                parentWorldOrient = node.mParentNode.getWorldOrientation;
                localOrient = parentWorldOrient'*orient;
                
            else
                
                localOrient = orient;
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function localPos = convertWorldToLocalPosition(node,pos)
            
            if node.hasParentNode
                
                parentWorldPos = node.mParentNode.getWorldPosition;
                parentWorldOrient = node.mParentNode.getWorldOrientation;
                localPos = parentWorldOrient'*(pos - parentWorldPos);
                
            else
                
                localPos = pos;
                
            end
            
        end
        
    end        
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Entity containment methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function parentNode = getParentNode(node)
            parentNode = node.mParentNode;
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setParentNode(node,parentNode)
            import BaseClasses.Node
            
            if(isa(parentNode,'Node'))                
                
                if(node==parentNode)
                    
                    error('Setting a Node as its own parent node is an invalid operation')
                    
                else
                
                    node.removeParentNode;
                    node.mParentNode = parentNode;
                    node.mHasParentNode = true;
                    
                end
                
            else
                
                error('Object is not from the Node class or any Node subclass')
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function bool = hasParentNode(node)
            
            bool = node.mHasParentNode;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function removeParentNode(node)
            if(~isempty(node.mParentNode))
                currentParentNode = node.mParentNode;
                    
                index = currentParentNode.getChildNodeIndex(node);
                currentParentNode.removeChildNode(index);
                node.mParentNode = [];
                node.mHasParentNode = false;
            end
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function addChildNode(node,childNode)
            import BaseClasses.Node
            
            if(isa(childNode,'Node'))
                
                % increasing child node count
                if node.isChildNode(childNode)
                    
                    return;
                    
                else
                    
                    if node==childNode
                        
                        error('Setting a Node as its own child node is an invalid operation')
                        
                    else
                    
                        node.mNumOfChildNodes = node.mNumOfChildNodes + int32(1);
                        node.mChildNodes(node.mNumOfChildNodes) = childNode;

                        childNode.setParentNode(node);
                    end
                    
                end
                
            else
                
                error('Object is not from the Node class or any Node subclass')
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function removeChildNode(node,index)
            if node.mChildNodes.isKey(int32(index))
                node.mChildNodes.remove(int32(index));
                node.mNumOfChildNodes = node.mNumOfChildNodes - int32(1);
            end
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function childNode = getChildNode(node,index)
            
            if node.mChildNodes.isKey(int32(index))
                childNode = node.mChildNodes(int32(index));
            else
                error('Index exceeds current number of child nodes')
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function count = getNumOfChildNodes(node)
            
            count = node.mNumOfChildNodes;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function removeAllChildNodes(node)
            
            for n = int32(1):node.mNumOfChildNodes;
                
                node.removeChildNode(n);
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function index = getChildNodeIndex(node,childNode)
            
            
            if node.isChildNode(childNode)
                
                for n = int32(1):node.mNumOfChildNodes;
                    if childNode == node.mChildNodes(n)
                        index = n;
                        break;
                    end
                end
                
            else 
                index = int32(-1);
            end
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function bool = isChildNode(node,childNode)
            
            bool = false;
            for n = int32(1):node.mNumOfChildNodes;
                if childNode == node.mChildNodes(n)
                    bool = true;
                    break;
                end
            end
            
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Graphics Manipulation methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods   
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function update(node)
            for n = int32(1):node.mNumOfChildNodes;
                
                childNode = node.mChildNodes(n);
                childNode.update;
                
            end
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function ctranspose(node)
            
            %             for n = int32(1):node.mNumOfChildNodes;
            %                 node.mChildNodes(n)';
            %             end
            node.createGraphicsInstance;
            
            for n=1:length(node);
                
                update(node(n));
                
            end
            
            drawnow;
            node.displayWindow;            
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function Animate(node,transformData)
            
            node';
            for n = 1:size(transformData,3);
                node.setTransform(transformData(n),Transform.WORLD_SPACE);
                node.update;
                drawnow;
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function createGraphicsInstance(node)
            
            for n = int32(1):node.mNumOfChildNodes;
                
                childNode = node.mChildNodes(n);
                %node.mChildNodes(n).createGraphicsInstance;
                childNode.createGraphicsInstance;
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function destroyGraphicsInstance(node)
            
            for n = int32(1):node.mNumOfChildNodes;
                
                node.mChildNodes(n).destroyGraphicsInstance;
                
            end
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Graphics Manipulation protected methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Access = protected)        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function displayWindow(node)
            
            if node.mNumOfChildNodes > int32(0)
                
                childNode = node.getChildNode(int32(1));
                childNode.displayWindow;
                
            end
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Appearance manipulation public methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function color = getColor(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                color = zeros(1,3);
                return
                
            end
            
            switch nargin
                case 1
                    index = int32(1);
            end
            
            childNode = node.getChildNode(int32(index));
            color = childNode.getColor;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function color = getEdgeColor(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                color = zeros(1,3);
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);                    
                    
            end
            
            childNode = node.getChildNode(int32(index));
            color = childNode.getEdgeColor;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function color = getFaceColor(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                color = zeros(1,3);
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            color = childNode.getFaceColor;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function t = getTransparency(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                t = 0;
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            t = childNode.getTransparency;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function t = getFaceTransparency(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                t = 0;
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            t = childNode.getFaceTransparency;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function t = getEdgeTransparency(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                t = 0;
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            t = childNode.getEdgeTransparency;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function color = getMarkerColor(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                color = zeros(1,3);
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            color = childNode.getMarkerColor;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function color = getMarkerEdgeColor(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                color = zeros(1,3);
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            color = childNode.getMarkerEdgeColor;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function color = getMarkerFaceColor(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                color = zeros(1,3);
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            color = childNode.getMarkerFaceColor;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function s = getMarkerSize(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                s = 0;
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            s = childNode.getMarkerSize;
            
        end
            
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function bool = isFaceVisible(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                bool = false;
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            bool = childNode.isFaceVisible;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function bool = isEdgeVisible(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                bool = false;
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            bool = childNode.isEdgeVisible;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function bool = isVisible(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                bool = false;
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            bool = childNode.isVisible;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function bool = isMarkerVisible(node,index)
            
            if node.mNumOfChildNodes == int32(0)
                
                bool = false;
                return
                
            end
            
            switch nargin
                case 1
                    
                    index = int32(1);
                    
            end
            
            childNode = node.getChildNode(int32(index));
            bool = childNode.isMarkerVisible;
            
        end
      
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setColor(node,color,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setColor(color)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setEdgeColor(node,color,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setEdgeColor(color)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setFaceColor(node,color,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setFaceColor(color)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setTransparency(node,t,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setTransparency(t)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setFaceTransparency(node,t,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setFaceTransparency(t)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setEdgeTransparency(node,t,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setEdgeTransparency(t)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setEdgeVisible(node,bool,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setEdgeVisible(bool)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setMarkerColor(node,color,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setMarkerColor(color)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setMarkerEdgeColor(node,color,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setMarkerEdgeColor(color)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setMarkerFaceColor(node,color,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setMarkerFaceColor(color)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setMarkerSize(node,s,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setMarkerSize(s)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setMarkerType(node,t,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setMarkerType(t)
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setMarkerVisible(node,bool,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setMarkerVisible(bool)
                
            end
            
        end
                        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setVisible(node,bool,index)
            
            switch nargin
                case 2
                    index = int32(1):node.mNumOfChildNodes;
            end
            
            for n = index
                
                childNode = node.getChildNode(n);
                childNode.setVisible(bool)
                
            end
            
        end
        
    end    
    
end
            
            
            
                
                
                
        
    
    
    
    
    
    
        
        
    
    
                 
                 
            
            
            
            
        
    
    