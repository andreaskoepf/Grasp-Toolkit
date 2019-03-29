function results = convhulln(varargin)
%   convhulln
%       Equivalent to matlab's default convhulln function but calls the 
%       QhullMex function instead.  Returns a structure array containing 
%       the faces data as well as additional fields such as offsets, 
%       normals, neighboringFacets, area and volume.
%   results  = convhulln(vertices,command(optional),sort(optional))
%       Inputs:
%           vertices    : n x d double
%               Vertices of geometry where n indicates number of vertices
%               and d in the number of dimensions.
%           command     : 1 x c char    (optional)
%               Char array containing the commands sent to the qhull
%               program.  When ommitted the commands argument defaults to
%               'Qt Qv Tv'.  See qhull.org for details on the commands
%               to the qhull program.
%           sort        : true | false 1 x 1 logical    (optional)
%               Logical boolean indicating whether the results should be
%               sorted in increasing order in relation to the offsets.
%       Outputs:
%           result        : 1 x 1 struct
%               Structure array containing the convex hull computation
%               results.


programName = 'qhull';

switch nargin
    case 1
        
        vertices = varargin{1};
        commands = 'Qt Qv Tv';
        sortBool = false;
        
    case 2
        
        vertices = varargin{1};
        
        if ~ischar(varargin{2})
            
            error('second argument must be a char array containing the commands to qhull')
            
        end
        
        commands = varargin{2};
        sortBool = false;
        
    case 3
        
        vertices = varargin{1};
        
        if ~ischar(varargin{2})
            
            error('second argument must be a char array containing the commands to qhull')
            
        end
        
        commands = varargin{2};
        sortBool = varargin{3};
        
        
    otherwise 
        
        error('incorrect number of input arguments')
        
end

results = Geometry.QhullMex(programName,vertices,commands);

if sortBool
    
    [offsets,indices]= sort(abs(results.offsets),1);
    
    results.faces = results.faces(indices,:);
    results.offsets = results.offsets(indices);
    results.normal = results.normal(indices,:);
    results.neighboringFacets = results.neighboringFacets(indices,:);
    
end
    
    

end

