function [theta,u]=EquivalentAngleAxis(o,r)
% Equivalent Angle Axis
%   [theta,axs]=EquivalentAngleAxis(o,r)
%       Computes the smallest angle theta measure from vector o to r about
%       the vector u which is perpendicular to the plane that contains both
%       vector o and r.

% computing vector u perpendicular to the plane that contains o and r
u=cross(o,r);

% computing the angle of rotation between the two vectors about vector u
theta=acos(dot(o,r)/(norm(o)*norm(r)));

end
