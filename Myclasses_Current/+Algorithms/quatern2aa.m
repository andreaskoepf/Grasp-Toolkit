function [K,theta]=quatern2aa(q)
theta=2*acos(q(4));
if abs(theta)<0.001
    K=[0 0 0]';
else
    K=(q(1:3)/sin(theta/2))';
end
end