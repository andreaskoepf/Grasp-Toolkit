function [K,theta]=transform2aa(varargin)
% Solid.transform2aa   Equivalent angle axis representation
%
%   [K,theta]=Solid.transform2aa(Tb)
%   returns the equivalent angle axes representation K and theta.
%   The vector K is defined relative to global frame eye(3).
%
%   [K,theta]=Solid.transform2aa(Tb,Ta)
%   same as above but defines the angle axis representation that
%   represents the relative rotation of Tb with respect to Ta.
switch nargin
    case 1
        Ta=eye(4);
        Tb=varargin{1};
    case 2
        Ta=varargin{2};
        Tb=varargin{1};
    otherwise
        error('Invalid number of arguments')
end

% obtaining Tranform of B with respect to A
r=(Ta\eye(4))*Tb;

q=Solid.transform2quatern(r);
[K,theta]=Solid.quatern2aa(q);
end