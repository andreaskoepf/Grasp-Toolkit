% Last updated 05/31/2009 19:19
classdef Solid < handle
    
    properties (SetAccess=protected)
        Vertices=[0 0 0 1]';
        Faces=[1 1 1];                
        GraphicsHandle % [patch_handle]
        FigureHandle
        DefaultDimensions=[0 0 0];
        FileName
        DefaultVertices=[0 0 0]';
        Dimensions =[0 0 0];% [length width heigth]
    end
    
    properties(SetAccess=public,GetAccess=public)
        Color='green';
        Frame=eye(4);        
        AxisLimits
    end
    
    
    properties (Dependent=true,SetAccess=private)
        CurrentVertices
        
    end
    methods
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function solid=Solid(varargin)
            % solid = Solid(filename,dimensions,frame,defaultDimensions)
            
            
                
            if nargin >0 && isa(varargin{1},'Solid') 
                
                propNames=fieldnames(varargin{1});
                
                for n=1:length(propNames)-1;
                    
                    if strcmp(propNames{n},'Vertices')
                        solid.(propNames{n})=varargin{1}.(propNames{n})(1:3,:)';                        
                    else
                        solid.(propNames{n})=varargin{1}.(propNames{n});
                    end
                end
                solid.GraphicsHandle=[];
                return
                
            elseif nargin >0 && isa(varargin{1},'char')  
                solid.FileName=varargin{1};
                
                % Reading graphics file and initializing corresponding
                % property values
                try 
                    [faces,vertices,color]=rndread([solid.FileName '.stl']);
                catch
                    [faces,vertices,color]=rndread([solid.FileName '.STL']);
                end
                solid.Vertices=vertices;
                solid.DefaultVertices=vertices;
                solid.Faces=faces;
                
                
            end
            
            % initializing property values
            % The set.Dimensions method will scale the solid to the desired
            % size.            
            switch nargin
                case 0
                    return
                case 1
                    solid.DefaultDimensions=getAverageSize(solid);
                    solid.resize(getAverageSize(solid));
                case 2
                    solid.DefaultDimensions=getAverageSize(solid);
                    solid.resize(varargin{2});
                    
                case 3
                    solid.DefaultDimensions=getAverageSize(solid);
                    solid.resize(varargin{2});
                    solid.Frame=varargin{3};
                case 4
                    solid.DefaultDimensions=varargin{4};                    
                    solid.resize(varargin{2});
                    solid.Frame=varargin{3};
                otherwise
                    error('Wrong number of input arguments')
            end

        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function solid=resize(solid,dimensions)
            solid.Dimensions=abs(dimensions);

            % resizing solid
            sf=solid.Dimensions./solid.DefaultDimensions;   % size factor
            v= solid.DefaultVertices;           % default vertices

            solid.Vertices=[sf(1)*v(:,1) sf(2)*v(:,2) sf(3)*v(:,3)];
            minimum=min(min(solid.Vertices(1:3,:)'));
            maximum=max(max(solid.Vertices(1:3,:)'));
            axisLimits=repmat([minimum-0.1*abs(minimum) maximum+0.1*abs(maximum)],3,1)+...
                repmat(solid.Frame(1:3,4),1,2);
            solid.AxisLimits=[axisLimits(1,:) axisLimits(2,:) axisLimits(3,:)];
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function vertices=get.CurrentVertices(solid)
            v=solid.Frame*solid.Vertices;
            vertices=v(1:3,:)';
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.Vertices(solid,vertices)
            % Trasposes and adds and additional row of ones in order to
            % perform transformatios directly without resizing the matrix
            % data.
            solid.Vertices=[vertices';ones(1,size(vertices,1))];
        end        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function drive(solid,transform)
            solid';            
            if nargin==2
                for n=1:size(transform,3);
                    solid.Frame=transform(:,:,n);
                    update(solid);
                    drawnow
                end
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function solid=shift(solid,transform)
            vertices=transform*solid.Vertices;
            defaultVertices=transform*[solid.DefaultVertices';ones(1,size(solid.DefaultVertices,1))];
            solid.Vertices=vertices(1:3,:)';
            solid.DefaultVertices=defaultVertices(1:3,:)';

        end
        
        function solid=scale(solid,f)
            solid.resize(f*solid.DefaultDimensions);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function newsolids=copyArray(solids)
            newsolids(length(solids))=Solid;
            for n=1:length(solids);
                newsolids(n)=Solid(solids(n));
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function solid=ctranspose(solid)


            solid.setHandles;
            
            for n=1:length(solid);
                update(solid(n));
            end
            drawnow
            figure(solid(1).FigureHandle);
            %title(['Imported CAD data from ' filename])
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setHandles(solid)
            
            
            for n = 1:length(solid);
                if isempty(solid(n).GraphicsHandle)|| ~ishandle(solid(n).GraphicsHandle)
                    solid(n).GraphicsHandle=patch('Vertices',solid(n).CurrentVertices ...
                        ,'Faces',solid(n).Faces,'facec',solid(n).Color...
                        ,'EdgeColor','none','DiffuseStrength',1,'AmbientStrength',1,...
                        'FaceLighting','gouraud','SpecularColorReflectance',0.1,'AlphaDataMapping','none',...
                        'CDataMapping','direct');

                    solid(n).FigureHandle=get(get(solid(n).GraphicsHandle,'Parent'),'Parent');
                    set(solid(n).FigureHandle,'Renderer','openGL')
                    
                    % setting parent axes object properties
                    %set(get(solid(n).GraphicsHandle,'Parent'),'NextPlot','add')

                    if isempty(findobj(get(solid(n).GraphicsHandle,'parent'),'Type','light'))
                        light('Position',[0 1 1],'Style','infinite');
                        light('Position',[0 1 1],'Style','infinite');
                        light('Position',[0 1 1],'Style','infinite');
                        light('Position',[0 1 1],'Style','infinite');
                        light('Position',[0 -1 -1],'Style','infinite');
                        light('Position',[0 -1 -1],'Style','infinite');
                        light('Position',[0 -1 -1],'Style','infinite');
                        light('Position',[0 -1 -1],'Style','infinite');
                    end
                    material metal;
                    
                    daspect([1 1 1])
                    view(3)
                    xlabel('X'),ylabel('Y'),zlabel('Z')                   
                    

                end
                %set(get(solid.GraphicsHandle,'Parent'),'XLim',solid.AxisLimits(1,:),'YLim',solid.AxisLimits(2,:),...
                %'ZLim',solid.AxisLimits(3,:));
                

            end     
            
            
            
        end        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function update(solid)
            % updates graphics handle in accordance to the current value of
            % the Frame Property
%             for n=1:length(solid);
%                 set(solid(n).GraphicsHandle,'Vertices',solid(n).CurrentVertices)
%             end            
            set(solid.GraphicsHandle,'Vertices',solid.CurrentVertices)
            
            

        end    
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function delete(solid)
            if ishandle(solid.GraphicsHandle)
                delete(solid.GraphicsHandle)
            end
            %refresh(solid.FigureHandle)
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function newsolid = sum(solid)
            for n=1:length(solid);
                if n==1
                    newsolid=Solid(solid(1));
                else
                    newsolid=newsolid+solid(n);
                end
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function newsolid = plus(solid1,solid2)
            vertices=[solid1.Vertices solid2.Vertices];
            faces=[solid1.Faces;solid2.Faces+size(solid1.Vertices,2)];            
            newsolid=Solid;            
            newsolid.DefaultVertices=vertices(1:3,:)';
            newsolid.DefaultDimensions=getAverageSize(newsolid);
            newsolid.resize(newsolid.DefaultDimensions);
            newsolid.Faces=faces;            
            newsolid.FileName='none';
            
        end
            
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function newsolid=toSolid(obj)
            newsolid=Solid;
            
            % coping properties
            
            propNames=fieldnames(obj);
            actPropNames=fieldnames(newsolid);

            for n=1:length(propNames);

                if strcmp(propNames{n},'Vertices')
                    newsolid.(propNames{n})=obj.(propNames{n})(1:3,:)';
                elseif any(strcmp(propNames{n},actPropNames(1:end-1)))
                    newsolid.(propNames{n})=obj.(propNames{n});
                end
            end
            newsolid.GraphicsHandle=[];
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function solid=reducePatch(solid,reduction)

            switch nargin
                case 1
                    reduction=0.4;
            end
            newFV=reducepatch(solid.Faces,solid.DefaultVertices,reduction);
            solid.DefaultVertices=newFV.vertices;
            solid.Faces=newFV.faces;
            solid.resize(solid.Dimensions);
            
            try
                delete(solid.GraphicsHandle);
                solid.GraphicsHandle=[];
            catch
                % Graphics handle hasn't been created yet, do nothing
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.Color(solid,color)
            solid.Color=color;
            try
                set(solid.GraphicsHandle,'FaceColor',solid.Color)
            catch
                % Graphics handle hasn't been created yet, do nothing
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getXSpan(solid)
            span=[min(solid.Vertices(1,:)) max(solid.Vertices(1,:))];
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getYSpan(solid)
            span=[min(solid.Vertices(2,:)) max(solid.Vertices(2,:))];
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getZSpan(solid)
            span=[min(solid.Vertices(3,:)) max(solid.Vertices(3,:))];
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function span=getSpan(solid)
            span=[solid.getXSpan solid.getYSpan solid.getXSpan];
        end
        
        
        
    end
    
    
    methods (Static)
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
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function T=translation(axis,r)
            % Creates a 4 x 4 traslation matrix along the corresponding axis in axis
            % argument.
            if length(axis)~=length(r)
                error('number of elements of input arguments not equal')
            else
                T=eye(4);
                for n=1:length(axis);
                    switch lower(axis(n))
                        case 'x'
                            T=T*[eye(3),[r(n) 0 0]';0 0 0 1];
                        case 'y'
                            T=T*[eye(3),[0 r(n) 0]';0 0 0 1];
                        case 'z'
                            T=T*[eye(3),[0 0 r(n)]';0 0 0 1];
                        otherwise
                            error('%s not a valid axis',axis(n))
                    end
                end
            end
        end       
        


    end
    
    
end

function [fout, vout, cout] = rndread(filename)
% Reads CAD STL ASCII files, which most CAD programs can export.
% Used to create Matlab patches of CAD 3D data.
% Returns a vertex list and face list, for Matlab patch command.
% 
% filename = 'hook.stl';  % Example file.
%
fid=fopen(filename, 'r'); %Open the file, assumes STL ASCII format.
if fid == -1 
    error('File could not be opened, check name or path.')
end
%
% Render files take the form:
%   
%solid BLOCK
%  color 1.000 1.000 1.000
%  facet
%      normal 0.000000e+00 0.000000e+00 -1.000000e+00
%      normal 0.000000e+00 0.000000e+00 -1.000000e+00
%      normal 0.000000e+00 0.000000e+00 -1.000000e+00
%    outer loop
%      vertex 5.000000e-01 -5.000000e-01 -5.000000e-01
%      vertex -5.000000e-01 -5.000000e-01 -5.000000e-01
%      vertex -5.000000e-01 5.000000e-01 -5.000000e-01
%    endloop
% endfacet
%
% The first line is object name, then comes multiple facet and vertex lines.
% A color specifier is next, followed by those faces of that color, until
% next color line.
%
CAD_object_name = sscanf(fgetl(fid), '%*s %s');  %CAD object name, if needed.
%                                                %Some STLs have it, some don't.   
vnum=0;       %Vertex number counter.
report_num=0; %Report the status as we go.
VColor = 0;
%
while feof(fid) == 0                    % test for end of file, if not then do stuff
    tline = fgetl(fid);                 % reads a line of data from file.
    fword = sscanf(tline, '%s ');       % make the line a character string
% Check for color
    if strncmpi(fword, 'c',1) == 1;    % Checking if a "C"olor line, as "C" is 1st char.
       VColor = sscanf(tline, '%*s %f %f %f'); % & if a C, get the RGB color data of the face.
    end                                % Keep this color, until the next color is used.
    if strncmpi(fword, 'v',1) == 1;    % Checking if a "V"ertex line, as "V" is 1st char.
       vnum = vnum + 1;                % If a V we count the # of V's
       report_num = report_num + 1;    % Report a counter, so long files show status
       if report_num > 249;
           %disp(sprintf('Reading vertix num: %d.',vnum));
           report_num = 0;
       end
       v(:,vnum) = sscanf(tline, '%*s %f %f %f'); % & if a V, get the XYZ data of it.
       c(:,vnum) = VColor;              % A color for each vertex, which will color the faces.
    end                                 % we "*s" skip the name "color" and get the data.                                          
end
%   Build face list; The vertices are in order, so just number them.
%
fnum = vnum/3;      %Number of faces, vnum is number of vertices.  STL is triangles.
flist = 1:vnum;     %Face list of vertices, all in order.
F = reshape(flist, 3,fnum); %Make a "3 by fnum" matrix of face list data.
%
%   Return the faces and vertexs.
%
fout = F';  %Orients the array for direct use in patch.
vout = v';  % "
cout = c';
%
fclose(fid);
end

function size=getAverageSize(solid)
vertices=solid.DefaultVertices;
size(1)=abs(max(vertices(:,1))-min(vertices(:,1)));
size(2)=abs(max(vertices(:,2))-min(vertices(:,2)));
size(3)=abs(max(vertices(:,3))-min(vertices(:,3)));
end
                
                    
                    
            