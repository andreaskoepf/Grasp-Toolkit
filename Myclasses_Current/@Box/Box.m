classdef Box < Solid
    
    
    methods
        function cube = Box(varargin) 
            
            
            
            %filename=Toolkit.createToolkitPath('@Cube','Cube.stl');            
            cube=cube@Solid('box');
            
            % Setting the Geometry ID property
            cube.GeometryID=int32(1); % corresponds to box geometries
            
            switch nargin
                case 0
                    dimensions=1;
                    color='b';
                case 1
                    dimensions=varargin{1};
                    color='b';
                case 2
                    dimensions=varargin{1};
                    color=varargin{2};
                otherwise
                    error('Invalid number of arguments')
            end
            
            % modifying object
            switch length(dimensions)
                case 1
                    cube.scale(dimensions);
                case 2
                    cube.resize([dimensions cube.Dimensions(3)]);
                case 3
                    cube.resize(dimensions);
                otherwise
                    error('Invalide array size')
            end
            
            cube.Color=color;
            
        end
    end
end
