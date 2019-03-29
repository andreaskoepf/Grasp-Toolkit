classdef Toolkit < handle
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public constant properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(Constant = true)
        
        TOOLKIT_NAME = 'GraspSimulationToolkit';
        ROOT = Toolkit.getRootPath;
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % internal model map containter
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(Constant = true,Access = protected)
        
        sModelMap = Toolkit.loadModelMap;
        
    end    
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public static methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Static = true)
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function p=createToolkitPath(varargin)
            % path = createToolkitPath(relPath1,realPath2,...)
            %   creates a path with the given arguments relative to the
            %   toolkit directory.
            
            p=fullfile(Toolkit.ROOT,varargin{:});
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function p=createRelativePath(varargin)
            % path = createRelativePath(rootPath,relPath1,relPath2,...)
            %   create a path relative to the firtst path argument.
            
            p=fullfile(varargin{:});
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function s=loadToolkitFile(varargin)
            % loadToolkitFile
            %   loadToolkitFile(fileName,var1Name,var2Name,...)
            %   The first argument is the name of the data file. The rest
            %   of the arguments are the list of variable names to be 
            %   retrieved.
            
            if nargin==1
                s=load(Toolkit.createToolkitPath(varargin{:}));
            elseif nargin>1
                s=load(Toolkit.createToolkitPath(varargin{1}),varargin{2:end});
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function saveToolkitFile(varargin)
            % saveToolkitFile
            %   saveToolkitFile(fileName,var1Name,var1Value,...)
            %   The first argument is the name of the data file. The rest
            %   of the arguments are pairs of variable names and
            %   corresponding variable values.
            
            % creating data structure
            if(nargin>1 && mod(nargin-1,2)==0)
                s=struct;
                for n=1:(nargin-1)/2;
                    s.(varargin{2*n})=varargin{2*n+1};
                end
                
                save(Toolkit.createToolkitPath(varargin{1}),'-struct','s')
            else
                error('Incorrect number of input arguments')
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function copyToolkitDocument(source,destination)
            % copyToolkitDocument
            %   copyToolkitDocument(source,destination)
            %   Copies document specified in source into toolkit directory 
            %   specified by the destination argument.
            
            if ~copyfile(source,Toolkit.createToolkitPath(destination))
                
                error(sprintf('%s\n%s',['File ',source,' could not be copied into '],...
                    [Toolkit.createToolkitPath(destination),' directory']))
                
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function appendToolkitFile(varargin)
            % appendToolkitFile
            %   appendToolkitFile(fileName,var1Name,var1Value,...)
            %   The first argument is the name of the data file. It will be
            %   saved relative to the Toolkit directory.  The rest
            %   of the arguments are pairs of variable names and
            %   corresponding variable values. It appends new variables
            %   onto the existing file
            
            % creating data structure
            if(nargin>1 && mod(nargin-1,2)==0)
                s=struct;
                for n=1:(nargin-1)/2;
                    s.(varargin{2*n})=varargin{2*n+1};
                end
                
                save(Toolkit.createToolkitPath(varargin{1}),'-struct','s','-append')
            else
                error('Incorrect number of input arguments')
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function saveModelData(className,modelName,dataFileName,data)
            % saveModelData
            %   saveModelData(className,modelName,dataFileName,data)
            %   Saves model data in corresponding model directory under the
            %   name specified by the third argument.  This method is valid
            %   only for registered models.            
            
            fileName = Toolkit.createRelativePath('Data',className,'ModelFiles',modelName,...
                'ModelData');
            
            Toolkit.appendToolkitFile(fileName,dataFileName,data);
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function copyModelDocument(className,modelName,source)
            % copyModelDocument
            %   copyModelDocument(className,modelName,source)
            %   Copies document specified in source into corresponding
            %   model directory.  This method is valid only for registered
            %   models.
            
            directoryName = Toolkit.createRelativePath('Data',className,'ModelFiles',...
                modelName);
            
            Toolkit.copyToolkitDocument(source,directoryName);
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function data = loadModelData(className,modelName,dataFileName)
            % loadModelData
            %   data = loadModelData(className,modelName,dataFileName)
            %   Loads the model data corresponding to the file specified by
            %   the third argument.  This method is only valid for
            %   registered models.
            
            if Toolkit.isToolkitModel(className,modelName)
                
                fileName = Toolkit.createRelativePath('Data',className,'ModelFiles',modelName,...
                    'ModelData');

                s = Toolkit.loadToolkitFile(fileName,dataFileName);
                
                data = s.(dataFileName);
                
            else
                
                error(['Model ',modelName,' is not registered under the ',className,' class'])
                
            end
            
        end       
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function registerModel(className,xmlFileName)
            % registerModel
            %   registerModel(className,xmlFileName)
            %   Registers a new model under the class specified by the
            %   first argument.  The xml file should contain all the
            %   details and data corresponding to the construction info of
            %   the given class model.
            %   Details of the structure of the xml file are different for
            %   every class.  Call the createXMLRegistrationTemplate method
            %   of the Toolkit class in order to generate a xml template
            %   file for a given class model.  
            %   If the model Name in the xml file already exist then the
            %   old data is overrided and the new one is used for that
            %   model.  A model is available for use inmediately after
            %   registration is succesfully completed
            
            % initialing directories if they haven't been initialized
            Toolkit.ROOT;
            
            % importing package
            import Mesh.*
            import Shape.*            
            
            % calling the parseXMLRegistrationFile of the corresponding
            % class name
            
            try
                try
                    [modelName,modelDataFiles,modelDocuments] = eval([className,'.parseXMLRegistrationDocument(''',...
                        xmlFileName,''');']);
                catch
                    
                    error([className,' does not have a parseXMLRegistrationDocument method, registration was not completed'])
                    
                end
                
                
                
                % checking if directories exists
                directoryName=Toolkit.createRelativePath('Data',className,'ModelFiles',modelName);
                
                % This ensures that non registered models won't be allowed
                % to save or load any data files
                if ~isdir(directoryName)
                    
                    % creating directory
                    mkdir(Toolkit.createToolkitPath(directoryName));
                    
                    % creating model data file
                    Toolkit.saveToolkitFile(Toolkit.createRelativePath(directoryName,...
                        'ModelData'),'ModelName',modelName);
                    
                end
                
                % saving model data
                dataFileNames = fieldnames(modelDataFiles);
                
                for n = 1:length(dataFileNames)
                    
                    Toolkit.saveModelData(className,modelName,dataFileNames{n},...
                        modelDataFiles.(dataFileNames{n}));
                    
                end
                
                % copying each additional file onto model directory
                for n = 1:length(modelDocuments);
                    
                    try
                        
                        Toolkit.copyModelDocument(className,modelName,modelDocuments{n});
                        
                    catch
                        
                        warning(sprintf('%s\n%s',['Could not copy ',modelDocuments{n}],...
                            [' to ',className,':\t',modelName,' model directory']))
                        
                    end
                    
                end
                
                % updating model map
                if ~Toolkit.sModelMap.isKey(className)
                    
                    modelMap = Toolkit.sModelMap;
                    modelMap(className) = containers.Map;
                    
                end
                
                classMap = Toolkit.sModelMap(className);
                
                % adding new model to corresponding class map
                classMap(modelName) = directoryName;
                
                % saving model map
                Toolkit.saveModelMap;
                
                % displaying completion message
                fprintf('\n\n\t--%s model "%s" was successfully registered--\n\n',className,modelName)
                
            catch
                
                % displaying error message
                fprintf('\n\n\t--%s model "%s" could not be registered--\n\n',className,modelName)
                
                % removing directory if one was created for the model
                if ~Toolkit.isToolkitModel(className,modelName)
                    rmdir(Toolkit.createToolkitPath(directoryName),'s');
                end
                
            end
           
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function createXMLRegistrationTemplate(className,modelName)
            
            import Mesh.*
            import Shape.*
            
            Toolkit.ROOT;
            try
                
                eval([className,'.createXMLRegistrationTemplate(''',...
                    modelName,''');']);
                
            catch
                
                error([className,' does not have a createXMLRegistrationTemplate method'])
                
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function data=parseMeshDocument(fileName)
            % parseMeshDocument
            %   data = parseMeshDocument(fileName)
            %   Reads the mesh document and returns the vertex and face
            %   data in a matlab data structure.  At this time, only stl 
            %   documents are supported.  The fileName arguments must
            %   contain an absolute path to the mesh file location.       
            
            % the value of this variable will be increased if there are
            % multiple graphical entities contained in a single file.
            
            
            % verifying if file extension is supported
            dotIndex=regexp(fileName,'\.');
            
            if isempty(dotIndex)
                
                error('Could not recognize document extension')
                
            end
            
            switch fileName(dotIndex:end)
                case {'.stl' '.STL'}
                    
                    [data.Faces,data.Vertices,data.Color]=rndread(fileName);
                    data.FileName=fileName;
                    
                case {'.wrl'}
                    [nParts,data_out,infoline] = read_vrml(fileName);
                    
                    indexes=1:nParts;
                    
                    data(nParts) = struct('Vertices',[],'Faces',[],'Color',[],...
                        'FileName',[]);
                    for n=indexes;
                        data(n).Vertices=data_out(n).pts;
                        data(n).Faces=data_out(n).knx;
                        data(n).Color=data_out(n).color;
                        data(n).FileName=fileName;
                    end
                    
                    % redefining indexes
                    
                otherwise
                    
                    error([fileName(dotIndex:end) ' not a suported extension'])
            end
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function classes=getRegisteredClasses
            classes=Toolkit.sModelMap.keys;
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function models=getRegisteredModels(className)
            if Toolkit.isToolkitClass(className)
                modelMap=Toolkit.sModelMap(className);
                models=modelMap.keys;
            else
                error([className ' is not a valid class'])
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function b=isToolkitClass(className)
            b=Toolkit.sModelMap.isKey(className);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function dispRegisteredModels(varargin)
            switch nargin
                case 0
                    classNames=Toolkit.getRegisteredClasses;
                otherwise
                    classNames=varargin;
            end
            
            for n=1:length(classNames);
                fprintf('\n\t%s Class Models:\n',classNames{n})                
                modelNames=Toolkit.getRegisteredModels(classNames{n});
                for m=1:length(modelNames);
                    fprintf('\t\t- %s\n',modelNames{m})
                end
                
            end
        end            
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function b=isToolkitModel(className,modelName)
            if (Toolkit.isToolkitClass(className))
                modelMap=Toolkit.sModelMap(className);
                b=modelMap.isKey(modelName);
            else
                b=false;
            end
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % protected static methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods (Static=true,Access=private)        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function map=loadModelMap
            
            % checking if directory exists
            directoryName = Toolkit.createToolkitPath('Data','Toolkit');
            
            if ~isdir(directoryName)
                mkdir(directoryName);
                map=containers.Map;
                
                % saving model map
                location=Toolkit.createRelativePath('Data','Toolkit','ModelMap');
                Toolkit.saveToolkitFile(location,'ModelMap',map)
                return;
            end
            
            location=Toolkit.createRelativePath('Data','Toolkit','ModelMap');
            s = Toolkit.loadToolkitFile(location,'ModelMap');
            map=s.ModelMap;
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function saveModelMap
                                    
            location=Toolkit.createRelativePath('Data','Toolkit','ModelMap');
            Toolkit.appendToolkitFile(location,'ModelMap',Toolkit.sModelMap)
        end        
   
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function r=getRootPath
            pathFiles=what(Toolkit.TOOLKIT_NAME);
            r=pathFiles.path;
            %disp('method getRootPath called')     
            
            % adding additional paths
            rootXMLToolboxDir = Toolkit.createRelativePath(r,'XMLToolbox','lib');
            
            % checking if path has been added
            p = javaclasspath('-dynamic');
            
            if ~any(strcmp([rootXMLToolboxDir '\xmlParserAPIs.jar'],p))
                
                javaPath{1} = [rootXMLToolboxDir '\axis.jar'];
                javaPath{2} = [rootXMLToolboxDir '\commons-discovery.jar'];
                javaPath{3} = [rootXMLToolboxDir '\commons-logging.jar'];
                javaPath{4} = [rootXMLToolboxDir '\dom4j.jar'];
                javaPath{5} = [rootXMLToolboxDir '\jakarta-regexp-1.3.jar'];
                javaPath{6} = [rootXMLToolboxDir '\jaxrpc.jar'];
                javaPath{7} = [rootXMLToolboxDir '\jcert.jar'];

                javaPath{8} = [rootXMLToolboxDir '\jnet.jar'];
                javaPath{9} = [rootXMLToolboxDir '\jsr173_1.0_api.jar'];
                javaPath{10} = [rootXMLToolboxDir '\jsr173_1.0_ri.jar'];
                javaPath{11} = [rootXMLToolboxDir '\jsse.jar'];
                javaPath{12} = [rootXMLToolboxDir '\jug.jar'];
                javaPath{13} = [rootXMLToolboxDir '\saaj.jar'];
                javaPath{14} = [rootXMLToolboxDir '\sunjce_provider.jar'];

                javaPath{15} = [rootXMLToolboxDir '\wsdl4j.jar'];
                javaPath{16} = [rootXMLToolboxDir '\xalan.jar'];
                javaPath{17} = [rootXMLToolboxDir '\xercesImpl.jar'];
                javaPath{18} = [rootXMLToolboxDir '\xml-apis.jar'];
                javaPath{19} = [rootXMLToolboxDir '\xmlParserAPIs.jar'];
                javaPath{20} = [rootXMLToolboxDir '\xmlsec.jar'];

                matlabPath = Toolkit.createRelativePath(r,'XMLToolbox');

                % adding paths
                warning off
                javaclasspath(javaPath);
                warning on

                addpath(matlabPath);
                addpath(r);
                
            end
            
            % importing packages globally
            %evalin('base','x = 2')
            evalin('base','import GST.*')
            evalin('base','import GST.BaseClasses.*')
            
        end
        

    end
    
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% additional utility functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
 
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 function [nel,w3d,infoline] = read_vrml(filename)
 %/*********************************************************************************
 % FUNCTION NAME : read_vrml
 % AUTHOR        : G. Akroyd
 % PURPOSE  : reads a VRML or Inventor file and stores data points and connectivity
 %             in arrays ready for drawing wireframe images.
 %
 % VARIABLES/PARAMETERS:
 %  i/p  filename       name of vrml file
 %  o/p  nel            number of geometry parts (elements) in file
 %  o/p  w3d            geometry structure ;-
 %                       w3d.pts   array of x y z values for each element
 %                       w3d.knx   array of connection nodes for each element
 %                       w3d.color color of each element
 %                       w3d.polynum number of polygons for each element
 %                       w3d.trans  transparency of each element
 %
 % Version / Date : 3.0   / 23-9-02
 %                  removed triang optn & replaced face array Nan padding
 %                   with 1st value padding to correct opengl display prob.
 % Version / Date : 2.0   / 17-7-00
 %                  changed output to a structure rather than separate arrays
 %                   to use less memory.
 %                  1.0   / 21-6-99
 %                  original version
 %**************************************************************************
 %********/
 
 keynames=char('Coordinate3','point','coordIndex');
 
 fp = fopen(filename,'r');
 if fp == -1
     fclose all;
     str = sprintf('Cannot open file %s \n',filename);
     errordlg(str);
     error(str);
 end
 
 %* initialise arrays & counters */
 fv = zeros(1,3);
 foundkey=zeros(1,3); %* flags to determine if keywords found */
 endpts=0; %/* flag set when end of co-ord pts reached for an element */
 npt=0; %/* counter for num pts or conections */
 npol=1; % counter for number of polygons in an element
 nel=1; %/* counter for num of elements */
 color(1,1:3) = [0.5 0.55 0.5]; % default color
 maxnp = 0;
 tempstr = ' ';
 lastel = 1;
 lnum = 1;
 w3d(1).name = 'patch1';
 infoline = '#';
 trnsp(1) = 1; % transparency array - one val per element
 
 %/* start of main loop for reading file line by line */
 while ( tempstr ~= -1)
     tempstr = fgets(fp); % -1 if eof
     if tempstr(1) == '#' & lnum == 2,
         infoline = tempstr;
     end
     lnum = lnum +1; % line counter
     if ~isempty(findstr(tempstr,'DEF')) & ~endpts,
         w3d(nel).name = sscanf(tempstr,'%*s %s %*s %*s');
     end
     
     if ~isempty(findstr(tempstr,'rgb')) | ~isempty(findstr(tempstr,'diffuseColor')) % get color data
         sp = findstr(tempstr,'[');
         if isempty(sp), sp = 12 + findstr(tempstr,'diffuseColor'); end
         nc = 0;
         if ~isempty(sp)
             sp = sp +1;
             [cvals,nc]=sscanf(tempstr(sp:length(tempstr)),'%f %f %f,');
         end
         if nc >= 3
             if nel > lastel+1
                 for m = lastel+1:nel-1
                     color(m,1:3) = color(1,1:3); % if color not set then make equal to 1st
                 end
             end
             % if multi colors set then populate color matrix, this is an inventor feature
             for s = 1:fix(nc/3)
                 color(s+nel-1,1:3) = cvals(3*s-2:3*s)';
                 lastel = s+nel-1;
             end
         end
     end
     if ~isempty(findstr(tempstr,'transparency')), % get transparency level
         sp = findstr(tempstr,'trans');
         [tvals,nc]=sscanf(tempstr(sp+12:length(tempstr)),'%f');
         if nc > 0, trnsp(nel) = tvals(1); end
     end
     
     for i=1:3  %/* check for each keyword in line */
         key = deblank(keynames(i,:));
         if ~isempty(findstr(tempstr,key)) & isempty(findstr(tempstr,'#'))
             %/* if key found again before all found there is a problem
             %  so reset flag for that key */
             if ~foundkey(i), foundkey(i)=1;else foundkey(i)=0; end
             if(i>1 & ~foundkey(i-1)) foundkey(i)=0; end %/* previous key must exist first ! */
         end
     end
     if(foundkey(1) & foundkey(2)) %/* start of if A  first 2 keys found */
         if foundkey(3) %/* scan for connectivity data */
             tempstr = [tempstr,' #']; %/* last word marker for end of line */
             skip = '';
             %/* loop puts integer values in a line into connection array */
             word = ' ';
             while(word(1) ~= '#')
                 format = sprintf('%s %%s#',skip);
                 [word,nw] = sscanf(tempstr,format);
                 skip = [skip,'%*s'];
                 [node,nred] = sscanf(word,'%d,');
                 if nred>0
                     for p = 1:nred
                         if node(p) ~= -1
                             npt = npt +1;
                             % increment node value as matlab counts from 1, vrml 0
                             w3d(nel).knx(npol,npt) = node(p)+1;
                         else
                             if npt > maxnp(nel), maxnp(nel) = npt; end
                             npt = 0;
                             npol = npol + 1;
                         end
                     end
                 end
             end
             
             if ~isempty(findstr(tempstr,']')) %/* End of data block marker */
                 polynum(nel)=npol-1; %/* store num of polygons in this element */
                 endpts=0; %/* reset flag ready for next element search */
                 npt=0;
                 npol=1;
                 foundkey = zeros(1,4); %/* reset keyword flags for next search */
                 nel = nel+1; %/* now looking for next element so increment counter
                 maxnp(nel) = 0;
                 w3d(nel).name = sprintf('patch%d',nel); % name next block
             end
         end %/* end of scan for connectivity */
         
         %/* got 1st 2 keys but not 3rd and not end of co-ords data */
         if(foundkey(2) & ~foundkey(3) & ~endpts) %/* scan for pts data */
             sp = findstr(tempstr,'[');
             if isempty(sp)
                 %/* points data in x y z columns */
                 [fv,nv]=sscanf(tempstr,'%f %f %f,');
             else
                 %/* if block start marker [ in line - need to skip over it to data
                 %   hence pointer to marker incremented */
                 sp = sp +1;
                 [fv,nv]=sscanf(tempstr(sp:length(tempstr)),'%f %f %f,');
             end
             if(nv>0)
                 if mod(nv,3) ~= 0
                     fclose(fp);
                     error('Error reading 3d wire co-ordinates: should be x y z, on each line');
                 end
                 nov = fix(nv/3);
                 for p = 1:nov
                     npt = npt+1;
                     w3d(nel).pts(npt,1:3)=fv(3*p-2:3*p);
                 end
             end
             if ~isempty(findstr(tempstr,']')) %/* end of pts data block */
                 endpts=1; %/* flag to stop entry to pts scan while reading connections */
                 npt=0;
             end
         end %/* end of scan for data pts */
     end %/* end of if A */
 end %/* end of main loop */
 
 if nel == 0
     fclose(fp);
     error('Error reading 3d file: no data found');
 end
 nel = nel -1;
 
 % if not same number of verticies in each polygon we need to fill
 % out rest of row in array with 1st value
 nc = size(color);
 ts = size(trnsp);
 
 for i = 1:nel
     facs = w3d(i).knx;
     ind1 = find(facs==0); [rown,coln] = ind2sub(size(facs),ind1);
     facs(ind1) = facs(rown);
     w3d(i).knx = facs;
     if i > 1 & i > nc(1), color(i,1:3) = color(1,1:3); end % extend color array to cover all elements
     w3d(i).color = color(i,1:3);
     w3d(i).polynum = polynum(i);
     if i > ts(2) | trnsp(i)==0,
         trnsp(i) = 1;
     end % extend transparency array to cover all elements
     w3d(i).trans = trnsp(i);
 end
 
 fclose(fp);
 
 %  END OF FUNCTION read_vrml
 
 %=====================================================================================
 end
 
            
            
            
        
        