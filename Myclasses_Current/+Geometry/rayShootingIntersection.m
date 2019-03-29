function [z,varargout]=rayShootingIntersection(r,A)
% Ray Shooting Intersection
% This programs computes the intersection point between a convex set A that
% contains the origin and a ray in the direction of the vector r that
% starts the origin.
%   inputs:
%       r       :   n x 1 vector to be used for construction of a ray that
%                   starts at the origin and moves in the direction of r.
%       A       :   n x m array representing a Convex Set that contain the 
%                   origin. n is the number of dimensions and m is the
%                   number of points in the set A.
%   ouputs:
%       z       :   Intersection point between set A and a ray in the 
%                   direction of r.     
%       V       :   Subset of A consisting of affinely independent points 
%                   of set A such that the intersection point z is the 
%                   result of an affine combination of the points in Ak.
%

% Initialization
u=r/norm(r); % unit vector in the direction of z
w= Algorithms.SupportMapping(u,A); % support point
%bl=(u'*w(:,1))*u; % initial point b;
bl = norm(w(:,1))*u;
E=0.000001; % tolerance

% determining shortest distance
[v,d,V]=Algorithms.GJKPoint2Set(bl,A);

numIter=0;
while(d>E && numIter~=100) 
    numIter=numIter+1;
    
    % computing new point 
    bl=bl-(d^2/((bl-v)'*u))*u;    
    
    % determining shortest distance
    [v,d,V]=Algorithms.GJKPoint2Set(bl,A);
    
  
end
z=bl;

switch nargout
    case 2
        varargout{1}=V;
end

end