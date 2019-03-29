classdef SphereShape < Shape.Shape
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Box shape protected attributes
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(SetAccess = protected)
        
        mRadius = 0.5;
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % constructor
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function shape = SphereShape(varargin)
            % SphereShape
            %   shape = SphereShape;
            %       creates a sphere shape with default radius of 0.5
            %
            %   shape = SphereShape(r)
            %       creates a sphere shape with specified radius
            %   Inputs:
            %       r: 1 x 1 double
            %
            %   Outputs:
            %       shape: 1 x 1 shape object
            %
            
            switch nargin
                case 0
                    
                    radius = 0.5;
                    
                case 1
                    
                    radius = varargin{1};
                    
                otherwise
                    
                    error('too many input arguments')
                    
            end
            
            shape.loadFromModel('SphereShape');
            shape.setRadius(radius);
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public set methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setRadius(sphere,radius)
            
            sphere.setScale(2*[radius radius radius]);
            sphere.mRadius = radius;
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public get methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function radius = getRadius(sphere)
            
            radius = sphere.mRadius;
            
        end
        
    end
    
end
            