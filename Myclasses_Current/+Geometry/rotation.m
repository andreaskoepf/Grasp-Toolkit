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