classdef Transform
    
    properties(Constant = true)
        
        WORLD_SPACE = int32(0);
        PARENT_SPACE = int32(1);
        LOCAL_SPACE = int32(2);
    end
    
    methods (Static = true)
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function invTransform = calculateTransformInverse(transform)
            
            orientation = Transform.getTransformOrientation(transform);
            pos = Transform.getTransformPosition(transform);
            
            invTransform = [orientation',-orientation'*pos;zeros(1,3) 1];
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function pos = getTransformPosition(transform)
            
            pos = transform(1:3,4);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function orient = getTransformOrientation(transform)
            
            orient = transform(1:3,1:3);
            
        end 
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function quatern = getTransformQuaternion(transform)
            
            quatern = Transform.transform2quatern(transform);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function quatern = transform2quatern(transform)
            
            quatern=zeros(1,4);
            quatern(4)=0.5*(sqrt(1+trace(transform(1:3,1:3))));
            quatern(1)=(transform(3,2)-transform(2,3))/(4*quatern(4));
            quatern(2)=(transform(1,3)-transform(3,1))/(4*quatern(4));
            quatern(3)=(transform(2,1)-transform(1,2))/(4*quatern(4));
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function quatern = orientation2quatern(transform)
            
            quatern=zeros(1,4);
            quatern(4)=0.5*(sqrt(1+trace(transform(1:3,1:3))));
            quatern(1)=(transform(3,2)-transform(2,3))/(4*quatern(4));
            quatern(2)=(transform(1,3)-transform(3,1))/(4*quatern(4));
            quatern(3)=(transform(2,1)-transform(1,2))/(4*quatern(4));
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function transform = quatern2orientation(quatern)
            
            transform=zeros(3,3);
            transform(1,1)=1-(2*quatern(2)^2)-(2*quatern(3)^2);
            transform(1,2)=2*(quatern(1)*quatern(2)-quatern(3)*quatern(4));
            transform(1,3)=2*(quatern(1)*quatern(3)+quatern(2)*quatern(4));
            transform(2,1)=2*(quatern(1)*quatern(2)+quatern(3)*quatern(4));
            transform(2,2)=1-(2*quatern(1)^2)-(2*quatern(3)^2);
            transform(2,3)=2*(quatern(2)*quatern(3)-quatern(1)*quatern(4));
            transform(3,1)=2*(quatern(1)*quatern(3)-quatern(2)*quatern(4));
            transform(3,2)=2*(quatern(2)*quatern(3)+quatern(1)*quatern(4));
            transform(3,3)=1-(2*quatern(1)^2)-(2*quatern(2)^2);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function transform = quatern2transform(quatern)
            
            transform=zeros(3,3);
            transform(1,1)=1-(2*quatern(2)^2)-(2*quatern(3)^2);
            transform(1,2)=2*(quatern(1)*quatern(2)-quatern(3)*quatern(4));
            transform(1,3)=2*(quatern(1)*quatern(3)+quatern(2)*quatern(4));
            transform(2,1)=2*(quatern(1)*quatern(2)+quatern(3)*quatern(4));
            transform(2,2)=1-(2*quatern(1)^2)-(2*quatern(3)^2);
            transform(2,3)=2*(quatern(2)*quatern(3)-quatern(1)*quatern(4));
            transform(3,1)=2*(quatern(1)*quatern(3)-quatern(2)*quatern(4));
            transform(3,2)=2*(quatern(2)*quatern(3)+quatern(1)*quatern(4));
            transform(3,3)=1-(2*quatern(1)^2)-(2*quatern(2)^2);
            
        end   
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function R=rotation(axis,angle)
            %this function calculates the rotation matrix about an axis
            if length(axis)~=length(angle)
                error('number of elements of input arguments not equal')
            else
                R=eye(4);
                for n=1:length(axis);
                    
                    switch lower(axis(n))
                        case 'z'
                            R=R*[cos(angle(n)) -sin(angle(n)) 0 0;sin(angle(n)) cos(angle(n)) 0 0;0 0 1 0;0 0 0 1];
                        case 'y'
                            R=R*[cos(angle(n)) 0 sin(angle(n)) 0;0 1 0 0;-sin(angle(n)) 0 cos(angle(n)) 0;0 0 0 1];
                        case 'x'
                            R=R*[1 0 0 0;0 cos(angle(n)) -sin(angle(n)) 0;0 sin(angle(n)) cos(angle(n)) 0;0 0 0 1];
                        otherwise
                            error('Invalid value for axis argument')
                    end
                end
            end
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function T=translation(axis,r)
            % Creates a 4 x 4 traslation matrix along the corresponding axis in axis
            % argument.
            if length(axis)~=length(r)
                error('number of elements of input arguments not equal')
            else
                T=eye(4);
                for n=1:length(axis);
                    switch lower(axis(n))
                        case 'x'
                            T=T*[eye(3),[r(n) 0 0]';0 0 0 1];
                        case 'y'
                            T=T*[eye(3),[0 r(n) 0]';0 0 0 1];
                        case 'z'
                            T=T*[eye(3),[0 0 r(n)]';0 0 0 1];
                        otherwise
                            error('%s not a valid axis',axis(n))
                    end
                end
            end
        end
        
    end
    
end
    
    