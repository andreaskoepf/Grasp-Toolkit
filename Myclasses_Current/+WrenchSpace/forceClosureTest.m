function bool = forceClosureTest(W,w)
% ForceClosure
%   Test if the convex set W is force closure ( The origin lies
%   in the interior)
%
%   bool = WrenchSpace.ForceClosure(W)
%   Inputs:
%       W:  6 x m double
%           Six dimensional convex set of contact wrenches.
%   Outputs:
%       bool: 1 x 1 logical
%           True if W is force closure. Otherwise bool is false
%
%   bool = WrenchSpace.ForceClosure(W,w)
%   Inputs:
%       W:  6 x m double
%           Six dimensional convex set of contact wrenches.
%       w:  6 x 1 double
%           Point that lies in the interior of W which is used
%           to test for force closure. Typically, it should be
%           equal to the centroid of W.
%   Outputs:
%       bool: 1 x 1 logical
%           True if W is force closure. Otherwise bool is false
%

switch nargin
    case 0
        
        bool = false;
        return
        
    case 1
        
        w = sum(W,2)/(1 + size(W,2));
        
    case 2
        
    otherwise
        
        error('too many input arguments')
        
end


z = Geometry.rayShootingIntersection(-w,W);


% if this fails to produce an appropiate result then use the
% convhulln with the origin added to the original set.
if norm(w) < norm(z - w)
%if norm(z)> 1e-6
    
    bool = true;
    
else
    
    bool = false;
    
end

end