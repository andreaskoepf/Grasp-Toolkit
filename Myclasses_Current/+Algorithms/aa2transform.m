function T=aa2transform(K,theta)
%SOLID.AA2TRANSFORM
%   T=AA2TRANSFORM(K,THETA)
%   returns the transformation matrix that represents a rotation
%   about K by the angle theta
%
q=Solid.aa2quatern(K,theta);
T=Solid.quatern2transform(q);

end