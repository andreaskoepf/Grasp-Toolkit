function QhullMex
%   QhullMex
%       Interface to the Qhull Library
%
%   result = QhullMex(programName,command(optional),inputData(optional))
%
%   Inputs:
%       programName : 'qhull'|'rbox' 1 x c char
%           Corresponds to the program to be used.
%       command     : 1 x c char
%           The command to either the rbox or the qhull program.  see
%           qhull.org for more information on the commands. Certain
%           combination of commands allow calling other programs such as
%           qconvex, qdelaunay, qhalf, qvoronoi.  For instance, the program
%           qdelaunay is equivalent to calling qhull d Qbb, then the
%           command that will be passed is 'd Qbb'.  The list of commands
%           that can be used to call other programs are as follows:
%               qconvex == qhull 
%               qdelaunay == qhull d Qbb 
%               qhalf == qhull H 
%               qvoronoi == qhull v Qbb 
%           Use the following equivalences when calling qhull in 5-d and 
%           higher (a 4-d Delaunay triangulation is a 5-d convex hull): 
%               qconvex == qhull Qx 
%               qdelaunay == qhull d Qbb Qx 
%               qhalf == qhull H Qx 
%               qvoronoi == qhull v Qbb Qx 
%       inputData   : n x d double
%           Input data which is only needed when calling any of the qhull
%           programs.  The n index indicates the number of points and the d
%           index indicates the number of dimensions.
%
%   Outputs:
%       result      : 1 x 1 struct
%           The fields in the result data structure can differ depending on
%           the program that was called:
%           rbox:
%               If 'rbox' was called then the structure contains a 
%               "vertices" field with the corresponding vertex data.
%           qhull:
%               The following fields are returned when a qhull program was
%               called:
%               faces
%               offsets
%               normals
%               neighboringFacets
%               area
%               volume
%