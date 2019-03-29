classdef Sphere < Solid
    properties
        Radius=1;
    end
    methods
        function s=Sphere(varargin)
            
            %filename=Toolkit.createToolkitPath('@Sphere','Sphere.stl');            
            s=s@Solid('sphere');
            
            % decreasing the number of vertices -  face elements
            s.reducePatch(0.8);
            
            % setting the Geometry Id property
            s.GeometryID=int32(2); % corresponds to generic sphere geometry
            
            switch nargin
                case 0
                    s.Radius=1;
                    s.Color='b';
                case 1
                    s.Radius=varargin{1};
                    s.Color='b';
                case 2
                    s.Radius=varargin{1};
                    s.Color=varargin{2};
                otherwise
                    error('Invalid number of input arguments')
            end
            

        end
        
        function set.Radius(s,r)
            s.Radius=r;
            resize(s,2*r);
        end
        
        function resize(s,r)
            s.resize@Solid([r(1) r(1) r(1)]);
        end
        
        
        function restore(s)
            s.scale(1);
        end
            
        
        
            
    end
end
                    