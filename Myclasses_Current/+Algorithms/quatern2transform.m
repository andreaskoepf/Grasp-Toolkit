% QUATERN2TRANSFORM
%   T = quatern2transform(q)
%   Inputs:
%
%       q   :   1 x 4 array containing quaternion values [x y z w]
%
%   Outputs:
%
%       T   :   4 x 4 array containing the corresponding orientation
%               transform.


function T=quatern2transform(q)

% normalizing quaternion
q = q/norm(q);

T=zeros(4,4);
T(4,4)=1;
T(1,1)=1-2*(q(2)^2)-2*(q(3)^2);
T(1,2)=2*(q(1)*q(2)-q(3)*q(4));
T(1,3)=2*(q(1)*q(3)+q(2)*q(4));
T(2,1)=2*(q(1)*q(2)+q(3)*q(4));
T(2,2)=1-2*(q(1)^2)-2*(q(3)^2);
T(2,3)=2*(q(2)*q(3)-q(1)*q(4));
T(3,1)=2*(q(1)*q(3)-q(2)*q(4));
T(3,2)=2*(q(2)*q(3)+q(1)*q(4));
T(3,3)=1-2*(q(1)^2)-2*(q(2)^2);
end