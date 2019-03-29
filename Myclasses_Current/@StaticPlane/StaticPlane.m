classdef StaticPlane < Solid
    
    properties
        PlaneNormal=[0 0 1]';
        PlaneConstant=0;
    end
    
    methods
        function plane=StaticPlane(varargin)
            
            plane=plane@Solid;
            
            plane.GeometryID=int32(0);
            
            plane.IsDynamic=int32(0);
            
            plane.Color='y';
                       
                        
%             plane.DefaultVertices=[0.5 0.5 0;
%                                     -0.5 0.5 0;
%                                     -0.5 -0.5 0;
%                                     0.5 -0.5 0];

            plane.DefaultVertices=[0 0 0;
                                    0.5 0.5 0;
                                    -0.5 0.5 0;
                                    -0.5 -0.5 0;
                                    0.5 -0.5 0];
                                
            plane.Dimensions=[1 1 0];
                                
            plane.Faces=[1 2 3;1 3 4;1 4 5;1 5 2];
            
            plane.scale(1);
            
            
            
            switch nargin
                case 0
                    return;
                case 1
                    
                    normalVec=varargin{1};
                    d=0;
                    s=1; % scaling 
                    
                case 2
                    
                    normalVec=varargin{1};
                    d=varargin{2};
                    s=1;
                    
                case 3
                    normalVec=varargin{1};
                    d=varargin{2};
                    s=varargin{3};
                    
                otherwise
                    
                    error('wrong number of input arguments, enter StaticPlane([a b c]'',d)')
                    
            end
            
            if(all(size(normalVec)~=[3 1]))
                error('normal vector must be a 3 x 1 array')
            end
            
            % computing axis of rotation
            ax=cross(normalVec,plane.PlaneNormal);
            ax=ax/(norm(ax)); % normalizing
            
            if(any(isnan(ax)))
                ax=[0 0 0]';
            end
            
            % computing angle of rotation
            theta=acos(dot(normalVec,plane.PlaneNormal)/(norm(normalVec)*norm(plane.PlaneNormal)));
            
            % setting the rotation
            plane.Quaternion=Solid.aa2quatern(ax,theta);           
            
            
            % storing the normal and plane Constant
            plane.PlaneNormal=normalVec;
            plane.PlaneConstant=d;
            
            % computing plane origin  (set x=0 and y=0)          
            c=plane.PlaneNormal(3);
            
            
            if(c==0)
                plane.Position=[0 0 0]';
            else
                plane.Position=[0 0 d/c]';
            end
            
            plane.scale(s);
            
            
            
        end
        
    end
    
end