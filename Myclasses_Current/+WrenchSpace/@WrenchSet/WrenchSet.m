% support point computation
classdef WrenchSet < handle
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Partially Public Properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(SetAccess = protected)
        
        % generating contact point
        mContactPoint
        
        % linearization attributes
        mNormalWrench
        mNumOfPrimitiveWrenches = 0;
        mPrimitiveWrenches      
        mNumOfDimensions = 6;
        mResolution = 8;
        mFrictionCoefficients
        
        % Status Flags
        mRecomputeLinearization = true;
        
        
%         mFacets
%         mVertices
%         mOffsets
%         mNormals
%         mNumVertices
%         mNumFacets
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Public Constant Properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(Constant)
        
        sQHullFunction = @Geometry.convhulln;
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Constructor 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function ws = WrenchSet(varargin)
            % WrenchSet
            %   Creates a wrench set corresponding to a given contact point
            %   and contact model
            %
            %   ws = WrenchSet
            %       Creates an empty wrench set
            %
            %   ws = WrenchSet(contactPoint)
            %       Creates a wrench set in accordance to the contact point
            %       and uses a default resolution value according to the
            %       contact model defined for the contact point.
            %
            %       Input:
            %           contactPoint:   1 x 1 ContactPoint
            %
            %       Output:
            %           ws: 1 x 1 WrenchSet Object
            %
            %   ws = WrenchSet(contactPoint,resolution)
            %
            %       Input:
            %           contactPoint:   1 x 1 ContactPoint
            %           resolution:     1 x 1 | 1 x 2 double
            %       Output:
            %           ws: 1 x 1 WrenchSet Object
            %
            
            
            switch nargin
                
                case 0
                    
                    return;
                    
                case 1
                    
                    if isa(varargin{1},'WrenchSpace.WrenchSet')
                        
                        ws.loadFromObj(varargin{1});
                        
                    end
                    
                    if ~isa(varargin{1},'CollisionDetection.ContactPoint')
                        
                        error('Input argument must be a Contact Point')
                        
                    end
                    
                    arg1 = varargin{1};
                    resolution = 8;
                    
                case 2
                    
                    if ~isa(varargin{1},'CollisionDetection.ContactPoint')
                        
                        error('Input argument must be a Contact Point')
                        
                    end
                    
                    if ~isa(varargin{2},'double')
                        
                        error('Input argument must be a double')
                        
                    end
                    
                    arg1 = varargin{1};
                    resolution = varargin{2};
                    
                otherwise
                    
                    error('too many input arguments')
                    
            end
            
            ws.setContactPoint(arg1(1));
            
            % setting resolution
            ws.setResolution(resolution);
            

            
            % linearizing friction cone
            ws.computeLinearizedFrictionCone;
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public set methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setContactPoint(ws,contactPoint)
            
            if ~isa(contactPoint,'CollisionDetection.ContactPoint')
                
                error('Input must be a contact point')
                
            end
            
            ws.mContactPoint = contactPoint;
            
            % recomputing resolution in accordance to contact model
            ws.setResolution(ws.mResolution);
            ws.setFrictionCoefficients(ws.mContactPoint.CombinedFriction);
            
            ws.mRecomputeLinearization = true;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setResolution(ws,resolution)
            
            switch ws.mContactPoint.FrictionModel
                
                case 'FPC'
                    
                    res= 1;
                    
                case 'PCF'
                    
                    if sum(resolution) < 4
                        
                        res = 4;
                        
                    else
                        
                        res = sum(resolution);
                        
                    end
                    
                case {'SFCe' 'SFCl'}
                    
                    if length(resolution) == 1
                        
                        if resolution < 9 
                            
                            res = [3 3];
                            
                        else
                            
                            res = ceil([resolution/2 resolution/2]);
                            
                        end
                        
                    else
                        
                        if sum(resolution) < 9 
                            
                            res = [3 3];
                            
                        else
                            
                            res = [resolution(1) sum(resolution(2:end))];
                            
                        end
                        
                    end
                    
            end
            
            ws.mResolution = res;
            
            ws.mRecomputeLinearization = true;
            %ws.computeLinearizedFrictionCone;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setFrictionCoefficients(ws,f)
            
            switch ws.mContactPoint.FrictionModel
                
                case 'FPC'
                    
                    ws.mFrictionCoefficients = f(1);
                    
                case 'PCF'
                    
                    ws.mFrictionCoefficients = f(1);
                    
                case {'SFCe' 'SFCl'}
                    
                    if length(f) == 1
                        
                        ws.mFrictionCoefficients = [f f];
                        
                    else
                        
                        ws.mFrictionCoefficients = [f(1) f(2)];
                        
                    end
                    
            end
            
            ws.mRecomputeLinearization = true;
            
        end
            
            
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public get methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getPrimitiveWrenches(ws)
            
            if(ws.mRecomputeLinearization)
                
                ws.computeLinearizedFrictionCone;
                
            end
            
            val = ws.mPrimitiveWrenches;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getResolution(ws)
            
            val = ws.mResolution;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getNumOfDimensions(ws)
            
            val = ws.mNumOfDimensions;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getContactPoint(ws)
            
            val = ws.mContactPoint;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getNumOfPrimitiveWrenches(ws)
            
            if ws.mRecomputeLinearization
                
                ws.computeLinearizedFrictionCone
                
            end
            
            val = ws.mNumOfPrimitiveWrenches;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getNormalWrench(ws)
            
            if ws.mRecomputeLinearization
                
                ws.computeLinearizedFrictionCone
                
            end
            
            val = ws.mNormalWrench;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getFrictionCoefficients(ws)
            
            val = ws.mFrictionCoefficients;
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public instance methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function fs = createFacetedSet(ws)
            
            qHullResult = Geometry.convhulln((ws.getPrimitiveWrenches)','Qt Qx Tv',true);
            
            fs.faces = qHullResult.faces;
            fs.vertices = ws.getWrenchPrimitives';
            fs.offsets = qHullResult.offsets;
            fs.normal = qHullResult.normal;
            fs.neighboringFacets = qHullResult.neighboringFacets;
            fs.area = qHullResult.area;
            fs.volume = qHullResult.volume;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function sp = computeSupportPoint(ws,vector)
            
            if(ws.mRecomputeLinearization)
                
                ws.computeLinearizedFrictionCone;
                
            end
            
            supportPoints = Geometry.supportMapping(vector,ws.mPrimitiveWrenches);
            sp = supportPoints(:,1);
            
        end
        
    end    

    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % protected instance methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Access = protected)
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function computeLinearizedFrictionCone(ws)
            
            if ~ws.mRecomputeLinearization
                
                return
                
            end
            
            % obtaining parameters
            n = ws.mContactPoint.ContactNormalOnB;
            r = ws.mContactPoint.ContactPointOnB;
            
            friction = ws.mFrictionCoefficients;
            contactModel = ws.mContactPoint.FrictionModel;
            res = ws.mResolution;
            
            ws.mNormalWrench = WrenchSpace.frictionConeDiscretization(n,r,'FPC',0);
            ws.mPrimitiveWrenches = WrenchSpace.frictionConeDiscretization(n,r,contactModel,friction,res);
            ws.mNumOfPrimitiveWrenches = size(ws.mPrimitiveWrenches,2);
            
            ws.mRecomputeLinearization = false;
            
        end
                    
    end
        
        
        
    
end