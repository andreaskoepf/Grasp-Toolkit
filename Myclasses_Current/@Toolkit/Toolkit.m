classdef Toolkit < handle 
    
  
    properties (Constant=true,SetAccess=private)
        
        ToolkitName='MyClasses_Current';
        Root=getRootPath
    end
    
    properties (Constant=true,Access=private)
        ModelMap=Toolkit.loadModelMap;
    end
    
    
    
    methods(Static=true)
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function p=createToolkitPath(varargin)
            p=fullfile(Toolkit.Root,varargin{:});
        end

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function p=createRelativePath(varargin)
            p=fullfile(varargin{:});
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function data=loadGeometryFromFile(arg1)
                
            
                filename=arg1;
                % the value of this variable will be increased if there are
                % multiple graphical entities contained in a single file.
                
                
                % verifying if file extension is supported
                dotIndex=regexp(arg1,'\.');
                
                if isempty(dotIndex)
                    
                    % Reading graphics file and initializing corresponding
                    filename=[arg1 '.stl'];
                    try
                        [data.Faces,data.DefaultVertices,data.Color]=rndread(filename);
                        data.FileName=filename;
                    catch
                        
                        try
                            filename=[arg1 '.STL'];
                            [data.Faces,data.DefaultVertices,data.Color]=rndread(filename);
                            data.FileName=filename;
                        catch
                            filename=[arg1 '.wrl'];
                            [nParts,data_out,infoline] = read_vrml(filename);
                            
                            indexes=1:nParts;
                            
                            for n=indexes;
                                data(n).DefaultVertices=data_out(n).pts;
                                data(n).Faces=data_out(n).knx;
                                data(n).Color=data_out(n).color;
                                data(n).FileName=filename;
                            end
                        end
                    end
                    
                else
                    switch filename(dotIndex:end)
                        case {'.stl' '.STL'}
                            
                            [data.Faces,data.DefaultVertices,data.Color]=rndread(filename);
                            data.FileName=filename;
                            
                        case {'.wrl'}
                            [nParts,data_out,infoline] = read_vrml(filename);
                            
                            indexes=1:nParts;
                            
                            for n=indexes;
                                data(n).DefaultVertices=data_out(n).pts;
                                data(n).Faces=data_out(n).knx;
                                data(n).Color=data_out(n).color;
                                data(n).FileName=filename;
                            end
                            
                            % redefining indexes
                            
                        otherwise
                            
                            error([filename(dotIndex:end) ' not a suported extension'])
                    end
                end               
                
                
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
        

        function registerModel(className)
            
            switch className
                case {'Solid' 'solid'}
                    Toolkit.registerSolid;                    
                case {'Link' 'link'}
                    Toolkit.registerLink;
                case {'Phalanx' 'phalanx'}
                    Toolkit.registerPhalanx;
                case {'Palm' 'palm'}
                    Toolkit.registerPalm;
                case {'Finger' 'finger'}
                    Toolkit.registerFinger;
                case {'Hand' 'hand'}
                    Toolkit.registerHand;
                otherwise
                    error('This class does not currently have a register routine')
            end
            
        end
        
        function removeRegisteredModel(className,modelName)
            if Toolkit.isToolkitClass(className) && Toolkit.isToolkitModel(className,modelName)
                fprintf('\n\tWould you like to remove %s model:  %s\n',className,modelName)
                fprintf('\t1 - Yes\n\t2 - No\n')
                option=input('Select option:  ');
                
                switch option
                    case 1
                        modelMap=Toolkit.ModelMap(className);
                        
                        % removing directory where all of the model and
                        % associated data reside
                        directoryName=Toolkit.createToolkitPath(['@' className],'ModelFiles',modelName);
                        
                        
                        if(~rmdir(directoryName,'s'))
                            fprintf('\n\t %s model "%s" could not be removed\n',className,modelName)
                        end
                        
                        modelMap.remove(modelName);
                        
                        fprintf('\n\t %s model "%s" has been removed\n',className,modelName)
                    otherwise
                        fprintf('\n\t %s model "%s" has not been removed\n',className,modelName)
                        
                end
            else
                error('Not a valid class or model')
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function data=loadModelData(className,modelName)
            
            
            if(Toolkit.isToolkitModel(className,modelName))
                
                ClassModelMap=Toolkit.ModelMap(className);

                location=ClassModelMap(modelName);           


                try
                    s=Toolkit.loadToolkitFile(location,'ConstructionData');
                catch
                    error('data for this model could not be loaded')
                end
                
                data=s.ConstructionData;
                
            else
                error(['The ' modelName ' model has not been register as a ' className ' Model'])
            end
            
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function classes=getRegisteredClasses
            classes=Toolkit.ModelMap.keys;
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function models=getRegisteredModels(className)
            if Toolkit.isToolkitClass(className)
                modelMap=Toolkit.ModelMap(className);
                models=modelMap.keys;
            else
                error([className ' is not a valid class'])
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function b=isToolkitClass(className)
            b=Toolkit.ModelMap.isKey(className);
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
                modelMap=Toolkit.ModelMap(className);
                b=modelMap.isKey(modelName);
            else
                b=false;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function registerSolid
            
            if ~Toolkit.isToolkitClass('Solid')
                Toolkit.addToolkitClass('Solid')
            end
            map=Toolkit.ModelMap;
            SolidModelMap=map('Solid');
            % initiating data structure fields
            data.Class='Solid';
            data.ModelName=[];            
            data.Tag=[];
            data.FileName=[]; 
            data.DefaultVertices=[0 0 0];
            data.Faces=[1 1 1];
            data.Frame=eye(4);
            data.Dimensions=[0 0 0];
            data.NewReferenceFrame=eye(4);        
            data.PatchReductionFactor=0;
            data.Visible=true;
            data.Color='b';            
            data.Mass=1;
            data.I=eye(3);
            data.COG=zeros(3,1);
            
            completionArray=zeros(1,2);
            while (true)
                type(Toolkit.createToolkitPath('@Toolkit','solid_options.txt'))
                option=input('Enter option number :  ');
                
                switch option
                    case 1
                        fprintf('\n\tEnter a char array with the Model Name:\n')
                        data.ModelName=input('Entry: ');
                        completionArray(1)=1;
                    case 2
                        fprintf('\n\tEnter a desired value for the Tag:\n')
                        data.Tag=input('Entry: ');
                    case 3
                        fprintf('\n\tLocate File and click "Open"\n')
                        [filename,filenamePath]=uigetfile({'*.stl';'*.STL';'*.wrl';'*.WRL'},'Select STL file');
                        
                        try
                            d=Toolkit.loadGeometryFromFile(Toolkit.createRelativePath(filenamePath,filename));
                            data.DefaultVertices=d(1).DefaultVertices;
                            data.Faces=d(1).Faces;
                            data.Dimensions=getAverageSize(data.DefaultVertices);
                            completionArray(2)=1;                            
                            
                            
                            fprintf('\n\tThe following file: \n\t%s\n\twas successfully read. Geometry data has been stored',...
                                Toolkit.createRelativePath(filenamePath,filename))
                            
                        catch
                            fprintf('\n\tThe following file: \n\t%s\n\tcould not be read. Geometry could no be loaded',...
                                Toolkit.createRelativePath(filenamePath,filename))
                            
                        end
                        
                    case 4
                        fprintf(['\n\tEnter new 4 x 4 Orientation and Position Transformation Matrices\n\t'...
                            'in relation to the World Frame I 4 x 4:\n'])
                        data.NewReferenceFrame=input('Entry: ');
                        
                    case 5
                        fprintf(['\n\tEnter scalar value between 0 and 1 representative of the reduction \n'...
                            '\tpercentage\n'])
                        data.PatchReduction=abs(input('Entry: '));
                        
                    case 6
                        fprintf('\n\tEnter either a single char character or a 1 x 3 color vector.\n')
                        data.Color=input('Entry: ');
                        
                    case 7
                        fprintf('\n\tEnter a mass value:\n')
                        data.Mass =input('Entry: ');
                        
                    case 8
                        fprintf('\n\tEnter a 3 x 3 Inertia Tensor matrix:\n')
                        data.I =input('Entry: ');
                        
                    case 9
                        fprintf('\n\tEnter a 3 x 1 COG array:\n')
                        data.COG =input('Entry: ');
                        
                    case 10
                        fieldNames=fieldnames(data);
                        fprintf('\n\tThe currently saved properties are:\n')
                        
                        d=1;
                        for n=1:length(fieldNames);
                            
                            switch fieldNames{n}
                                case 'Class'
                                    fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                case 'FileName'
                                    fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                    %disp([filenamePath filename])
                                    disp(data.(fieldNames{n}))
                                    
                                    fprintf('\n\tDefaultVertices: %i x %i array',size(data.DefaultVertices,1),...
                                        size(data.DefaultVertices,2))
                                    
                                    fprintf('\n\tFaces:\t\t\t %i x %i array',size(data.Faces,1),...
                                        size(data.Faces,2))
                                    
                                    fprintf('\n\tDimensions:\t\t [%1.2f %1.2f %1.2f]',data.Dimensions(1),...
                                        data.Dimensions(2),data.Dimensions(3))
                                    
                                    d=d+1;
                                case {'Frame' 'Visible' 'DefaultVertices' 'Faces' 'Dimensions'}
                                otherwise
                                    fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                    disp(data.(fieldNames{n}))
                                    
                                    d=d+1;
                            end
                        end
                    case 11
                        if all(completionArray)
                            
                            fieldNames=fieldnames(data);
                            fprintf('\n\tThe following data will be saved:\n')
                            d=1;
                            for n=1:length(fieldNames);
                                
                                switch fieldNames{n}
                                    case 'Class'
                                        fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                    case 'FileName'
                                        fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                        %disp([filenamePath filename])
                                        disp(data.(fieldNames{n}))
                                        
                                        fprintf('\n\tDefaultVertices: %i x %i array',size(data.DefaultVertices,1),...
                                            size(data.DefaultVertices,2))
                                        
                                        fprintf('\n\tFaces:\t\t\t %i x %i array',size(data.Faces,1),...
                                            size(data.Faces,2))
                                        
                                        fprintf('\n\tDimensions:\t\t\t [%1.2f %1.2f %1.2f] array',data.Dimensions(1),...
                                            data.Dimensions(2),data.Dimensions(3))
                                        
                                        d=d+1;
                                    case {'Frame' 'Visible' 'DefaultVertices' 'Faces' 'Dimensions'}
                                    otherwise
                                        fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                        disp(data.(fieldNames{n}))
                                        
                                        d=d+1;
                                end
                            end
                            
                            while(true)
                                fprintf('\n\tsave this data?\n\t1 - Yes\n\t2 - No\n')
                                option=input('Enter option number :  ');
                                
                                switch option
                                    case 1                                        
                                        
                                        % checking if directories exists
                                        directoryName=Toolkit.createToolkitPath(['@' 'Solid'],'ModelFiles',data.ModelName);
                                        if(~isdir(directoryName))
                                            mkdir(Toolkit.createToolkitPath(['@' 'Solid'],'ModelFiles'),data.ModelName);
                                        end
                                        
                                        % copy STL file to Link Class directory
                                        if copyfile([filenamePath filename],Toolkit.createToolkitPath('@Solid','ModelFiles',data.ModelName))
                                            data.FileName=Toolkit.createRelativePath('@Solid','ModelFiles',data.ModelName,filename);
                                            fprintf('\n\tFile was successfully copied to Solid directory')
                                        else
                                            fprintf('\n\tFile could not be copied to class directory')
                                        end
                                        
                                        destination=Toolkit.createRelativePath(['@' 'Solid'],'ModelFiles',data.ModelName,'ModelData');
                                        SolidModelMap(data.ModelName)=destination;
                                        
                                        
                                        Toolkit.saveToolkitFile(destination,'ConstructionData',data);
                                        Toolkit.saveModelMap;
                                        
                                        fprintf('\n\tSolid Model Succesfully saved\n')
                                        fprintf('\tModel Name %s is now registered\n',data.ModelName)
                                        return;
                                        
                                    case 2
                                        fprintf('\n\tModel Data was not saved\n')
                                        break;
                                    otherwise
                                        fprintf('\n\tWrong entry, Model Data was not saved\n')
                                end
                            end
                        else
                            fprintf('\n\tNot all required fields have been filled\n')
                        end
                                    
                            
                    case 12
                        type(Toolkit.createToolkitPath('@Toolkit','solid_instructions.txt'))
                    case 0
                        break;
                    otherwise
                        fprintf('\n\tWrong entry\n')
                        continue
                        
                        
                end
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function registerLink
            
            if ~Toolkit.isToolkitClass('Link')
                Toolkit.addToolkitClass('Link')
            end
            map=Toolkit.ModelMap;
            LinkModelMap=map('Link');
            % initiating data structure fields
            data.Class='Link';
            data.ModelName=[];            
            data.Tag=[];
            data.FileName=[]; 
            data.DefaultVertices=[0 0 0];
            data.Faces=[1 1 1];
            data.Frame=eye(4);
            data.Dimensions=[0 0 0];
            data.NewReferenceFrame=eye(4);        
            data.PatchReductionFactor=0;
            data.Visible=true;
            data.Color='b';            
            data.DH=[];
            data.JointType=[];
            data.JointLimits=[];
            data.JointOffsets=[];
            data.JointValues=[];
            data.Mass=1;
            data.I=eye(3);
            data.COG=zeros(3,1);
            
            completionArray=zeros(1,4);
            while (true)
                type(Toolkit.createToolkitPath('@Toolkit','link_options.txt'))
                option=input('Enter option number :  ');
                
                % when there is no entry then skip subsequent operations
                if isempty(option)
                    continue
                end
                
                switch option
                    case 1
                        fprintf('\n\tEnter a char array with the Model Name:\n')
                        data.ModelName=input('Entry: ');
                        completionArray(1)=1;
                    case 2
                        fprintf('\n\tEnter a desired value for the Tag:\n')
                        data.Tag=input('Entry: ');
                    case 3
                        fprintf('\n\tLocate File and click "Open"\n')
                        [filename,filenamePath]=uigetfile({'*.stl';'*.STL';'*.wrl';'*.WRL'},'Select STL file');
                        
                        try
                            d=Toolkit.loadGeometryFromFile(Toolkit.createRelativePath(filenamePath,filename));
                            data.DefaultVertices=d(1).DefaultVertices;
                            data.Faces=d(1).Faces;
                            data.Dimensions=getAverageSize(data.DefaultVertices);
                            completionArray(2)=1;                            
                            data.FileName=[filenamePath filename];
                            
                            fprintf('\n\tThe following file: \n\t%s\n\twas successfully read. Geometry data has been stored',...
                                Toolkit.createRelativePath(filenamePath,filename))
                            
                        catch
                            fprintf('\n\tThe following file: \n\t%s\n\tcould not be read. Geometry could no be loaded',...
                                Toolkit.createRelativePath(filenamePath,filename))
                            
                        end
                        
                    case 4
                        fprintf(['\n\tEnter new 4 x 4 Orientation and Position Transformation Matrices\n\t'...
                            'in relation to the World Frame I 4 x 4:\n'])
                        data.NewReferenceFrame=input('Entry: ');
                        
                    case 5
                        fprintf(['\n\tEnter scalar value between 0 and 1 representative of the reduction \n'...
                            '\tpercentage\n'])
                        data.PatchReductionFactor=abs(input('Entry: '));
                        
                    case 6
                        fprintf('\n\tEnter either a single char character or a 1 x 3 color vector.\n')
                        data.Color=input('Entry: ');
                    case 7
                        fprintf('\n\tEnter a n x 4 array containing the DH parameters(Standard DH only).')
                        fprintf('\n\tThe parameters should be ordered as [a(i) alpha(i) d(i) theta(i)]\n')
                        data.DH=input('Entry: ');
                        
                        % initializing all related joint values if they
                        % have not been initialized already
                        if isempty(data.JointLimits)
                            data.JointLimits=inf*repmat([-1 1],size(data.DH,1),1);
                        end
                        
                        if isempty(data.JointOffsets)
                            data.JointOffsets=zeros(size(data.DH,1),1);
                        end
                        
                        if isempty(data.JointValues)
                            data.JointValues=zeros(size(data.DH,1),1);
                        end
                        completionArray(3)=1;
                    case 8
                        fprintf('\n\tSelect on of the following options for the joint type:\n')
                        fprintf('\t\t1 - Prismatic\n\t\t2 - Revolute\n\t\t3 - Universal\n\t\t4 - Spherical')
                        fprintf('\n\t\t5 - none\n')
                        option=input('Enter option number :  ');
                        switch option
                            case 1
                                data.JointType='Prismatic';
                            case 2
                                data.JointType='Revolute';
                            case 3
                                data.JointType='Universal';
                            case 4
                                data.JointType='Spherical';
                            case 5
                                data.JointType='none';
                            otherwise
                                disp(['"' num2str(option) '" is not a valid selection'])
                        end
                        completionArray(4)=1;
                        
                    case 9
                        fprintf('\n\tEnter a n x 2 array of joint limits:\n')
                        data.JointLimits=input('Entry: ');
                        
                    case 10
                        fprintf('\n\tEnter a n x 1 array of joint offsets:\n')
                        data.JointOffsets =input('Entry: ');
                        
                    case 11
                        fprintf('\n\tEnter a n x 1 array of joint values:\n')
                        data.JointValues =input('Entry: ');
                        
                    case 12
                        fprintf('\n\tEnter a mass value:\n')
                        data.Mass =input('Entry: ');
                        
                    case 13
                        fprintf('\n\tEnter a 3 x 3 Inertia Tensor matrix:\n')
                        data.I =input('Entry: ');
                        
                    case 14
                        fprintf('\n\tEnter a 3 x 1 COG array:\n')
                        data.COG =input('Entry: ');
                    
                    case 15
                        fprintf('\n\tWhich Class would you like to get data from:\n')
                        classNames={'Solid' 'Link'};
                        for n=1:length(classNames);
                            fprintf('\n\t\t%i- %s',n,classNames{n})
                        end
                        
                        fprintf('\n\t\t0- Exit to main menu\n')
                        option=input('Entry: ');
                        
                        if option<=0 || option>length(classNames)
                            
                            fprintf('\n\tno data was inherited\n')
                            continue
                        end
                        
                        %
                        
                        className=classNames{option};
                        modelNames=Toolkit.getRegisteredModels(classNames{option});
                        
                        while(true)
                            fprintf('\n\tSelect one of the following options\n')
                            fprintf('\n\t\t1 - Display registered %s Models',className)
                            fprintf('\n\t\t2 - Add %s Model',className)
                            fprintf('\n\t\t0 - Exit to main menu\n')
                            
                            option=input('Entry: ');
                            
                            switch option
                                case 1
                                    
                                    for n=1:length(modelNames);
                                        fprintf('\n\t\t%i- %s',n,modelNames{n})
                                    end
                                case 2
                                    fprintf('\n\tEnter a valid %s Model Name or a matching index:\n',className)
                                    entry=input('Entry: ');
                                    if isa(entry,'numeric')
                                        retrievedModelName=modelNames(entry(1));
                                        
                                    elseif isa(entry,'char')
                                        if Toolkit.isToolkitModel(className,entry)
                                            retrievedModelName={entry};
                                        else
                                            fprintf('\n\tInvalid model name\n')
                                            continue
                                            
                                        end
                                    end
                                    
                                    idata=Toolkit.loadModelData(className,retrievedModelName{:});
                                    fnames=fieldnames(idata);
                                    
                                    for m=1:length(fnames);
                                        data.(fnames{m})=idata.(fnames{m});
                                    end
                                    data.Class='Link';
                                    
                                    [filenamePath,filename,ext]=fileparts(data.FileName);
                                    filename=[filename ext];
                                    switch className
                                        case 'Solid'
                                            completionArray(2)=1;
                                        case 'Link'
                                            completionArray(2:4)=1;
                                    end
                                    
                                    
                                    
                                case 0
                                    break;
                                    
                            end
                        end
                        
                       
                    case 16
                        fieldNames=fieldnames(data);
                        fprintf('\n\tThe currently saved properties are:\n')
                        
                        d=1;
                        for n=1:length(fieldNames);
                            
                            switch fieldNames{n}
                                case 'Class'
                                    fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                case 'FileName'
                                    fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                    %disp([filenamePath filename])
                                    disp(data.(fieldNames{n}))
                                    
                                    fprintf('\n\tDefaultVertices: %i x %i array',size(data.DefaultVertices,1),...
                                        size(data.DefaultVertices,2))
                                    
                                    fprintf('\n\tFaces:\t\t\t %i x %i array',size(data.Faces,1),...
                                        size(data.Faces,2))
                                    
                                    fprintf('\n\tDimensions:\t\t [%1.2f %1.2f %1.2f]',data.Dimensions(1),...
                                        data.Dimensions(2),data.Dimensions(3))
                                    
                                    d=d+1;
                                case {'Frame' 'Visible' 'DefaultVertices' 'Faces' 'Dimensions'}
                                otherwise
                                    fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                    disp(data.(fieldNames{n}))
                                    
                                    d=d+1;
                            end
                        end
                    case 17
                        if all(completionArray)
                            
                            fieldNames=fieldnames(data);
                            fprintf('\n\tThe following data will be saved:\n')
                            d=1;
                            for n=1:length(fieldNames);
                                
                                switch fieldNames{n}
                                    case 'Class'
                                        fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                    case 'FileName'
                                        fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                        %disp([filenamePath filename])
                                        disp(data.(fieldNames{n}))
                                        
                                        fprintf('\n\tDefaultVertices: %i x %i array',size(data.DefaultVertices,1),...
                                            size(data.DefaultVertices,2))
                                        
                                        fprintf('\n\tFaces:\t\t\t %i x %i array',size(data.Faces,1),...
                                            size(data.Faces,2))
                                        
                                        fprintf('\n\tDimensions:\t\t [%1.2f %1.2f %1.2f]',data.Dimensions(1),...
                                            data.Dimensions(2),data.Dimensions(3))
                                        
                                        d=d+1;
                                    case {'Frame' 'Visible' 'DefaultVertices' 'Faces' 'Dimensions'}
                                    otherwise
                                        fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                        disp(data.(fieldNames{n}))
                                        
                                        d=d+1;
                                end
                            end
                            
                            while(true)
                                fprintf('\n\tsave this data?\n\t1 - Yes\n\t2 - No\n')
                                option=input('Enter option number :  ');
                                
                                switch option
                                    case 1                                        
                                        
                                        
                                        % checking if directories exists
                                        directoryName=Toolkit.createToolkitPath(['@' 'Link'],'ModelFiles',data.ModelName);
                                        if(~isdir(directoryName))
                                            mkdir(Toolkit.createToolkitPath(['@' 'Link'],'ModelFiles'),data.ModelName);
                                        end
                                        
                                        % copy STL file to Link Class directory
                                        if copyfile([filenamePath filename],Toolkit.createToolkitPath('@Link','ModelFiles',data.ModelName))
                                            data.FileName=Toolkit.createRelativePath('@Link','ModelFiles',data.ModelName,filename);
                                            fprintf('\n\tFile was successfully copied to Link directory')
                                        else
                                            fprintf('\n\tFile could not be copied to class directory')
                                        end
                                        
                                        destination=Toolkit.createRelativePath(['@' 'Link'],'ModelFiles',data.ModelName,'ModelData');
                                        LinkModelMap(data.ModelName)=destination;
                                        
                                        
                                        Toolkit.saveToolkitFile(destination,'ConstructionData',data);
                                        Toolkit.saveModelMap;
                                        
                                        fprintf('\n\tLink Model Succesfully saved\n')
                                        fprintf('\tModel Name %s is now registered\n',data.ModelName)
                                        return;
                                      
                                        
                                    case 2
                                        fprintf('\n\tModel Data was not saved\n')
                                        break;
                                    otherwise
                                        fprintf('\n\tWrong entry, Model Data was not saved\n')
                                end
                            end
                        else
                            fprintf('\n\tNot all required fields have been filled\n')
                        end
                                    
                            
                    case 18
                        type(Toolkit.createToolkitPath('@Toolkit','link_instructions.txt'))
                    case 0
                        break;
                    otherwise
                        fprintf('\n\tWrong entry\n')
                        continue
                        
                        
                end
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function registerPhalanx
            
            if ~Toolkit.isToolkitClass('Phalanx')
                Toolkit.addToolkitClass('Phalanx')
            end
            map=Toolkit.ModelMap;
            PhalanxModelMap=map('Phalanx');
            % initiating data structure fields
            data.Class='Phalanx';
            data.ModelName=[];            
            data.Tag=[];
            data.FileName=[]; 
            data.DefaultVertices=[0 0 0];
            data.Faces=[1 1 1];
            data.Frame=eye(4);
            data.Dimensions=[0 0 0];
            data.NewReferenceFrame=eye(4);        
            data.PatchReductionFactor=0;
            data.Visible=true;
            data.Color='b';            
            data.DH=[];
            data.JointType=[];
            data.JointLimits=[];
            data.JointOffsets=[];
            data.JointValues=[];
            data.Mass=1;
            data.I=eye(3);
            data.COG=zeros(3,1);
            data.ContactModelType=[];
            
            completionArray=zeros(1,4);
            while (true)
                type(Toolkit.createToolkitPath('@Toolkit','phalanx_options.txt'))
                option=input('Enter option number :  ');
                
                % when there is no entry then skip subsequent operations
                if isempty(option)
                    continue
                end
                
                switch option
                    case 1
                        fprintf('\n\tEnter a char array with the Model Name:\n')
                        data.ModelName=input('Entry: ');
                        completionArray(1)=1;
                    case 2
                        fprintf('\n\tEnter a desired value for the Tag:\n')
                        data.Tag=input('Entry: ');
                    case 3
                        fprintf('\n\tLocate File and click "Open"\n')
                        [filename,filenamePath]=uigetfile({'*.stl';'*.STL';'*.wrl';'*.WRL'},'Select STL file');
                        
                        try
                            d=Toolkit.loadGeometryFromFile(Toolkit.createRelativePath(filenamePath,filename));
                            data.DefaultVertices=d(1).DefaultVertices;
                            data.Faces=d(1).Faces;
                            data.Dimensions=getAverageSize(data.DefaultVertices);
                            completionArray(2)=1;                            
                            
                            
                            fprintf('\n\tThe following file: \n\t%s\n\twas successfully read. Geometry data has been stored',...
                                Toolkit.createRelativePath(filenamePath,filename))
                            
                        catch
                            fprintf('\n\tThe following file: \n\t%s\n\tcould not be read. Geometry could no be loaded',...
                                Toolkit.createRelativePath(filenamePath,filename))
                            
                        end
                        
                    case 4
                        fprintf(['\n\tEnter new 4 x 4 Orientation and Position Transformation Matrices\n\t'...
                            'in relation to the World Frame I 4 x 4:\n'])
                        data.NewReferenceFrame=input('Entry: ');
                        
                    case 5
                        fprintf(['\n\tEnter scalar value between 0 and 1 representative of the reduction \n'...
                            '\tpercentage\n'])
                        data.PatchReductionFactor=abs(input('Entry: '));
                        
                    case 6
                        fprintf('\n\tEnter either a single char character or a 1 x 3 color vector.\n')
                        data.Color=input('Entry: ');
                    case 7
                        fprintf('\n\tEnter a n x 4 array containing the DH parameters(Standard DH only).')
                        fprintf('\n\tThe parameters should be ordered as [a(i) alpha(i) d(i) theta(i)]\n')
                        data.DH=input('Entry: ');
                        
                        % initializing all related joint values if they
                        % have not been initialized already
                        if isempty(data.JointLimits)
                            data.JointLimits=inf*repmat([-1 1],size(data.DH,1),1);
                        end
                        
                        if isempty(data.JointOffsets)
                            data.JointOffsets=zeros(size(data.DH,1),1);
                        end
                        
                        if isempty(data.JointValues)
                            data.JointValues=zeros(size(data.DH,1),1);
                        end
                        completionArray(3)=1;
                    case 8
                        fprintf('\n\tSelect on of the following options for the joint type:\n')
                        fprintf('\t\t1 - Prismatic\n\t\t2 - Revolute\n\t\t3 - Universal\n\t\t4 - Spherical')
                        fprintf('\n\t\t5 - none\n')
                        option=input('Enter option number :  ');
                        switch option
                            case 1
                                data.JointType='Prismatic';
                            case 2
                                data.JointType='Revolute';
                            case 3
                                data.JointType='Universal';
                            case 4
                                data.JointType='Spherical';
                            case 5
                                data.JointType='none';
                            otherwise
                                disp(['"' num2str(option) '" is not a valid selection'])
                        end
                        completionArray(4)=1;
                        
                    case 9
                        fprintf('\n\tEnter a n x 2 array of joint limits:\n')
                        data.JointLimits=input('Entry: ');
                        
                    case 10
                        fprintf('\n\tEnter a n x 1 array of joint offsets:\n')
                        data.JointOffsets =input('Entry: ');
                        
                    case 11
                        fprintf('\n\tEnter a n x 1 array of joint values:\n')
                        data.JointValues =input('Entry: ');
                        
                    case 12
                        fprintf('\n\tEnter a mass value:\n')
                        data.Mass =input('Entry: ');
                        
                    case 13
                        fprintf('\n\tEnter a 3 x 3 Inertia Tensor matrix:\n')
                        data.I =input('Entry: ');
                        
                    case 14
                        fprintf('\n\tEnter a 3 x 1 COG array:\n')
                        data.COG =input('Entry: ');
                    
                    case 15
                        fprintf('\n\tWhich Class would you like to get data from:\n')
                        classNames={'Solid' 'Link' 'Phalanx'};
                        for n=1:length(classNames);
                            fprintf('\n\t\t%i- %s',n,classNames{n})
                        end
                        
                        fprintf('\n\t\t0- Exit to main menu\n')
                        option=input('Entry: ');
                        
                        if option<=0 || option>length(classNames) 
                           
                            fprintf('\n\tno data was inherited\n') 
                            continue
                        end
                        
                        %
                        
                        className=classNames{option};
                        modelNames=Toolkit.getRegisteredModels(classNames{option});
                        
                        while(true)
                            fprintf('\n\tSelect one of the following options\n')
                            fprintf('\n\t\t1 - Display registered %s Models',className)
                            fprintf('\n\t\t2 - Add %s Model',className)
                            fprintf('\n\t\t0 - Exit to main menu\n')
                            
                            option=input('Entry: ');
                            
                            switch option
                                case 1
                                    
                                    for n=1:length(modelNames);
                                        fprintf('\n\t\t%i- %s',n,modelNames{n})
                                    end
                                case 2
                                    fprintf('\n\tEnter a valid %s Model Name or a matching index:\n',className)
                                    entry=input('Entry: ');
                                    if isa(entry,'numeric')
                                        retrievedModelName=modelNames(entry(1));
                                        
                                    elseif isa(entry,'char')
                                        if Toolkit.isToolkitModel(className,entry)
                                            retrievedModelName={entry};
                                        else
                                            fprintf('\n\tInvalid model name\n')
                                            continue
                                            
                                        end
                                    end
                                        
                                    idata=Toolkit.loadModelData(className,retrievedModelName{:});
                                    fnames=fieldnames(idata);
                                    
                                    for m=1:length(fnames);
                                        data.(fnames{m})=idata.(fnames{m});
                                    end
                                    data.Class='Phalanx';
                                   
                                    [filenamePath,filename,ext]=fileparts(data.FileName);
                                    filename=[filename ext];
                                    
                                    switch className
                                        case 'Solid'
                                            completionArray(2)=1;
                                        case 'Link'
                                            completionArray(2:4)=1;
                                        case 'Phalanx'
                                            completionArray(2:4)=1;
                                    end
                                        

                                    
                                case 0
                                    break;
                                    
                            end
                        end

                        
                       
                    case 16
                        fieldNames=fieldnames(data);
                        fprintf('\n\tThe currently saved properties are:\n')
                        
                        d=1;
                        for n=1:length(fieldNames);
                            
                            switch fieldNames{n}
                                case 'Class'
                                    fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                case 'FileName'
                                    fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                    %disp([filenamePath filename])
                                    disp(data.(fieldNames{n}))
                                    
                                    fprintf('\n\tDefaultVertices: %i x %i array',size(data.DefaultVertices,1),...
                                        size(data.DefaultVertices,2))
                                    
                                    fprintf('\n\tFaces:\t\t\t %i x %i array',size(data.Faces,1),...
                                        size(data.Faces,2))
                                    
                                    fprintf('\n\tDimensions:\t\t [%1.2f %1.2f %1.2f]',data.Dimensions(1),...
                                        data.Dimensions(2),data.Dimensions(3))
                                    
                                    d=d+1;
                                case {'Frame' 'Visible' 'DefaultVertices' 'Faces' 'Dimensions'}
                                otherwise
                                    fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                    disp(data.(fieldNames{n}))
                                    
                                    d=d+1;
                            end
                        end
                    case 17
                        if all(completionArray)
                            
                            fieldNames=fieldnames(data);
                            fprintf('\n\tThe following data will be saved:\n')
                            d=1;
                            for n=1:length(fieldNames);
                                
                                switch fieldNames{n}
                                    case 'Class'
                                        fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                    case 'FileName'
                                        fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                        %disp([filenamePath filename])
                                        disp(data.(fieldNames{n}))
                                        
                                        fprintf('\n\tDefaultVertices: %i x %i array',size(data.DefaultVertices,1),...
                                            size(data.DefaultVertices,2))
                                        
                                        fprintf('\n\tFaces:\t\t\t %i x %i array',size(data.Faces,1),...
                                            size(data.Faces,2))
                                        
                                        fprintf('\n\tDimensions:\t\t [%1.2f %1.2f %1.2f]',data.Dimensions(1),...
                                            data.Dimensions(2),data.Dimensions(3))
                                        
                                        d=d+1;
                                    case {'Frame' 'Visible' 'DefaultVertices' 'Faces' 'Dimensions'}
                                    otherwise
                                        fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                        disp(data.(fieldNames{n}))
                                        
                                        d=d+1;
                                end
                            end
                            
                            while(true)
                                fprintf('\n\tsave this data?\n\t1 - Yes\n\t2 - No\n')
                                option=input('Enter option number :  ');
                                
                                switch option
                                    case 1                                        
                                        
                                        % checking if directories exists
                                        directoryName=Toolkit.createToolkitPath(['@' 'Phalanx'],'ModelFiles',data.ModelName);
                                        if(~isdir(directoryName))
                                            mkdir(Toolkit.createToolkitPath(['@' 'Phalanx'],'ModelFiles'),data.ModelName);
                                        end
                                        
                                        % copy STL file to Link Class directory
                                        if copyfile([filenamePath filename],Toolkit.createToolkitPath('@Phalanx','ModelFiles',data.ModelName))
                                            data.FileName=Toolkit.createRelativePath('@Phalanx','ModelFiles',data.ModelName,filename);
                                            fprintf('\n\tFile was successfully copied to Phalanx directory')
                                        else
                                            fprintf('\n\tFile could not be copied to class directory')
                                        end
                                        
                                        destination=Toolkit.createRelativePath(['@' 'Phalanx'],'ModelFiles',data.ModelName,'ModelData');
                                        PhalanxModelMap(data.ModelName)=destination;
                                        
                                        
                                        Toolkit.saveToolkitFile(destination,'ConstructionData',data);
                                        Toolkit.saveModelMap;
                                        
                                        fprintf('\n\tPhalanx Model Succesfully saved\n')
                                        fprintf('\tModel Name %s is now registered\n',data.ModelName)
                                        return;                                       
                         
                                        
                                    case 2
                                        fprintf('\n\tModel Data was not saved\n')
                                        break;
                                    otherwise
                                        fprintf('\n\tWrong entry, Model Data was not saved\n')
                                end
                            end
                        else
                            fprintf('\n\tNot all required fields have been filled\n')
                        end
                                    
                            
                    case 18
                        type(Toolkit.createToolkitPath('@Toolkit','phalanx_instructions.txt'))
                    case 0
                        break;
                    otherwise
                        fprintf('\n\tWrong entry\n')
                        continue
                        
                        
                end
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function registerPalm
            
            if ~Toolkit.isToolkitClass('Palm')
                Toolkit.addToolkitClass('Palm')
            end
            map=Toolkit.ModelMap;
            PalmModelMap=map('Palm');
            % initiating data structure fields
            data.Class='Palm';
            data.ModelName=[];            
            data.Tag=[];
            data.FileName=[]; 
            data.DefaultVertices=[0 0 0];
            data.Faces=[1 1 1];
            data.LocalNodes=[];
            data.Frame=eye(4);
            data.Dimensions=[0 0 0];
            data.NewReferenceFrame=eye(4);        
            data.PatchReductionFactor=0;
            data.Visible=true;
            data.Color='b';            
            data.Mass=1;
            data.I=eye(3);
            data.COG=zeros(3,1);
            
            completionArray=zeros(1,3);
            while (true)
                type(Toolkit.createToolkitPath('@Toolkit','palm_options.txt'))
                option=input('Enter option number :  ');
                
                switch option
                    case 1
                        fprintf('\n\tEnter a char array with the Model Name:\n')
                        data.ModelName=input('Entry: ');
                        completionArray(1)=1;
                    case 2
                        fprintf('\n\tEnter a desired value for the Tag:\n')
                        data.Tag=input('Entry: ');
                    case 3
                        fprintf('\n\tLocate File and click "Open"\n')
                        [filename,filenamePath]=uigetfile({'*.stl';'*.STL';'*.wrl';'*.WRL'},'Select STL file');
                        
                        try
                            d=Toolkit.loadGeometryFromFile(Toolkit.createRelativePath(filenamePath,filename));
                            data.DefaultVertices=d(1).DefaultVertices;
                            data.Faces=d(1).Faces;
                            data.Dimensions=getAverageSize(data.DefaultVertices);
                            completionArray(2)=1;                            
                            
                            
                            fprintf('\n\tThe following file: \n\t%s\n\twas successfully read. Geometry data has been stored',...
                                Toolkit.createRelativePath(filenamePath,filename))
                            
                        catch
                            fprintf('\n\tThe following file: \n\t%s\n\tcould not be read. Geometry could no be loaded',...
                                Toolkit.createRelativePath(filenamePath,filename))
                            
                        end
                        
                    case 4
                        fprintf(['\n\tEnter 4 x 4 x n tranformation matrix array indicating the relative\n\t'...
                            'position and orientation of each finger base with respect to the palm '])
               
                        fprintf('\n\thow will the data be entered:')
                        fprintf('\n\t\t%s\n\t\t%s','1 - As a workspace variable','2 - Manually enter each individual Matrix')
                        fprintf('\n\t\t%s\n\t\t%s\n','0 - Cancel entry')
                        option=input('Entry: ');
                        
                        switch option
                            case 1
                                fprintf('\n\tenter name of the workspace variable that contains the data:\n')
                                arg=input('Entry: ');
                                data.LocalNodes=evalin('base',arg);
                            case 2
                                fprintf('\n\tHow many frames will you enter:\n')
                                arg=input('Entry: ');
                                if arg>0
                                    localNodes=zeros(4,4,arg);
                                    for n=1:arg;
                                        fprintf('\n\tEnter 4 x 4 reference frame :\n')
                                        localNodes(:,:,n)=input('Entry: ');
                                    end
                                    data.LocalNodes=localNodes;
                                else
                                    fprintf('\n\tWrong entry')
                                    continue
                                end
                                        
                            case 0
                                continue
                            otherwise
                                continue
                        end
                        
                        completionArray(3)=1;
                                
                       
                    case 5
                        fprintf(['\n\tEnter new 4 x 4 Orientation and Position Transformation Matrices\n\t'...
                            'in relation to the World Frame I 4 x 4:\n'])
                        data.NewReferenceFrame=input('Entry: ');
                        
                    case 6
                        fprintf(['\n\tEnter scalar value between 0 and 1 representative of the reduction \n'...
                            '\tpercentage\n'])
                        data.PatchReductionFactor=abs(input('Entry: '));
                        
                    case 7
                        fprintf('\n\tEnter either a single char character or a 1 x 3 color vector.\n')
                        data.Color=input('Entry: ');
                        
                    case 8
                        fprintf('\n\tEnter a mass value:\n')
                        data.Mass =input('Entry: ');
                        
                    case 9
                        fprintf('\n\tEnter a 3 x 3 Inertia Tensor matrix:\n')
                        data.I =input('Entry: ');
                        
                    case 10
                        fprintf('\n\tEnter a 3 x 1 COG array:\n')
                        data.COG =input('Entry: ');
                        
                    case 11
                        fprintf('\n\tWhich Class would you like to get data from:\n')
                        classNames={'Solid' 'Palm'};
                        for n=1:length(classNames);
                            fprintf('\n\t\t%i- %s',n,classNames{n})
                        end
                        
                        fprintf('\n\t\t0- Exit to main menu\n')
                        option=input('Entry: ');
                        
                        if option<=0 || option>length(classNames)
                            
                            fprintf('\n\tno data was inherited\n')
                            continue
                        end
                        
                        %
                        
                        className=classNames{option};
                        modelNames=Toolkit.getRegisteredModels(classNames{option});
                        
                        while(true)
                            fprintf('\n\n\tSelect one of the following options\n')
                            fprintf('\n\t\t1 - Display registered %s Models',className)
                            fprintf('\n\t\t2 - Add %s Model',className)
                            fprintf('\n\t\t0 - Exit to main menu\n')
                            
                            option=input('Entry: ');
                            
                            switch option
                                case 1
                                    
                                    for n=1:length(modelNames);
                                        fprintf('\n\t\t%i- %s',n,modelNames{n})
                                    end
                                case 2
                                    fprintf('\n\tEnter a valid %s Model Name or a matching index:\n',className)
                                    entry=input('Entry: ');
                                    if isa(entry,'numeric')
                                        retrievedModelName=modelNames(entry(1));
                                        
                                    elseif isa(entry,'char')
                                        if Toolkit.isToolkitModel(className,entry)
                                            retrievedModelName={entry};
                                        else
                                            fprintf('\n\tInvalid model name\n')
                                            continue
                                            
                                        end
                                    end
                                    
                                    idata=Toolkit.loadModelData(className,retrievedModelName{:});
                                    fnames=fieldnames(idata);
                                    
                                    for m=1:length(fnames);
                                        data.(fnames{m})=idata.(fnames{m});
                                    end
                                    data.Class='Palm';
                                    
                                    [filenamePath,filename,ext]=fileparts(data.FileName);
                                    filename=[filename ext];
                                    
                                    switch className
                                        case 'Solid'
                                            completionArray(2)=1;
                                        case 'Palm'
                                            completionArray(2:3)=1;
                                    end
                                    
                                    
                                    
                                case 0
                                    break;
                                    
                            end
                        end
                        
                    case 12
                        fieldNames=fieldnames(data);
                        fprintf('\n\tThe currently saved properties are:\n')
                        
                        d=1;
                        for n=1:length(fieldNames);
                            
                            switch fieldNames{n}
                                case 'Class'
                                    fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                case 'FileName'
                                    fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                    %disp([filenamePath filename])
                                    disp(data.(fieldNames{n}))
                                    
                                    fprintf('\n\tDefaultVertices: %i x %i array',size(data.DefaultVertices,1),...
                                        size(data.DefaultVertices,2))
                                    
                                    fprintf('\n\tFaces:\t\t\t %i x %i array',size(data.Faces,1),...
                                        size(data.Faces,2))
                                    
                                    fprintf('\n\tDimensions:\t\t [%1.2f %1.2f %1.2f]',data.Dimensions(1),...
                                        data.Dimensions(2),data.Dimensions(3))
                                    
                                    d=d+1;
                                case {'Frame' 'Visible' 'DefaultVertices' 'Faces' 'Dimensions'}
                                otherwise
                                    fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                    disp(data.(fieldNames{n}))
                                    
                                    d=d+1;
                            end
                        end
                    case 13
                        if all(completionArray)
                            
                            fieldNames=fieldnames(data);
                            fprintf('\n\tThe following data will be saved:\n')
                            d=1;
                            for n=1:length(fieldNames);
                                
                                switch fieldNames{n}
                                    case 'Class'
                                        fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                    case 'FileName'
                                        fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                        %disp([filenamePath filename])
                                        disp(data.(fieldNames{n}))
                                        
                                        fprintf('\n\tDefaultVertices: %i x %i array',size(data.DefaultVertices,1),...
                                            size(data.DefaultVertices,2))
                                        
                                        fprintf('\n\tFaces:\t\t\t %i x %i array',size(data.Faces,1),...
                                            size(data.Faces,2))
                                        
                                        fprintf('\n\tDimensions:\t\t\t [%1.2f %1.2f %1.2f] array',data.Dimensions(1),...
                                            data.Dimensions(2),data.Dimensions(3))
                                        
                                        d=d+1;
                                    case {'Frame' 'Visible' 'DefaultVertices' 'Faces' 'Dimensions'}
                                    otherwise
                                        fprintf('\n\n\t%1.0f - %s\n',d,fieldNames{n})
                                        disp(data.(fieldNames{n}))
                                        
                                        d=d+1;
                                end
                            end
                            
                            while(true)
                                fprintf('\n\tsave this data?\n\t1 - Yes\n\t2 - No\n')
                                option=input('Enter option number :  ');
                                
                                switch option
                                    case 1                                        
                                        
                                        
                                        % checking if directories exists
                                        directoryName=Toolkit.createToolkitPath(['@' 'Palm'],'ModelFiles',data.ModelName);
                                        if(~isdir(directoryName))
                                            mkdir(Toolkit.createToolkitPath(['@' 'Palm'],'ModelFiles'),data.ModelName);
                                        end
                                        
                                        % copy STL file to Link Class directory
                                        if copyfile([filenamePath filename],Toolkit.createToolkitPath('@Palm','ModelFiles',data.ModelName))
                                            data.FileName=Toolkit.createRelativePath('@Palm','ModelFiles',data.ModelName,filename);
                                            fprintf('\n\tFile was successfully copied to Palm directory')
                                        else
                                            fprintf('\n\tFile could not be copied to class directory')
                                        end
                                        
                                        destination=Toolkit.createRelativePath(['@' 'Palm'],'ModelFiles',data.ModelName,'ModelData');
                                        PalmModelMap(data.ModelName)=destination;
                                        
                                        
                                        Toolkit.saveToolkitFile(destination,'ConstructionData',data);
                                        Toolkit.saveModelMap;
                                        
                                        fprintf('\n\tPalm Model Succesfully saved\n')
                                        fprintf('\tModel Name %s is now registered\n',data.ModelName)
                                        return;                                      
                                                                  
                                        
                                    case 2
                                        fprintf('\n\tModel Data was not saved\n')
                                        break;
                                    otherwise
                                        fprintf('\n\tWrong entry, Model Data was not saved\n')
                                end
                            end
                        else
                            fprintf('\n\tNot all required fields have been filled\n')
                        end
                                    
                            
                    case 14
                        type(Toolkit.createToolkitPath('@Toolkit','palm_instructions.txt'))
                    case 0
                        break;
                    otherwise
                        fprintf('\n\tWrong entry\n')
                        continue
                        
                        
                end
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function registerFinger
            
            if ~Toolkit.isToolkitClass('Finger')
                Toolkit.addToolkitClass('Finger')
            end
            map=Toolkit.ModelMap;
            FingerModelMap=map('Finger');
            % initiating data structure fields
            data.Class='Finger';
            data.ModelName=[];
            data.Tag=[];
            data.LinkModelNames={};
            data.BaseObjectName={};
            data.PatchReductionFactor=0;
            data.Color=-1; 
            
            
            linkModelNames={};
            allLinkModelNames=Toolkit.getRegisteredModels('Link');
            allSolidModelNames=Toolkit.getRegisteredModels('Solid');
            completionArray=zeros(1,2);
            while (true)
                type(Toolkit.createToolkitPath('@Toolkit','finger_options.txt'))
                option=input('Enter option number :  ');
                
                switch option
                    case 1
                        fprintf('\n\tEnter a char array with the Model Name:\n')
                        data.ModelName=input('Entry: ');
                        completionArray(1)=1;
                    case 2
                        fprintf('\n\tEnter a desired value for the Tag:\n')
                        data.Tag=input('Entry: ');
                    case 3
                        
                        
                        while(true)
                            fprintf('\n\tSelect one of the following options\n')
                            fprintf('\n\t\t1 - Display registered Link Models')
                            fprintf('\n\t\t2 - Add Link Model')
                            fprintf('\n\t\t0 - Exit to main menu\n')
                            
                            option=input('Entry: ');
                            
                            switch option
                                case 1
                                    
                                    for n=1:length(allLinkModelNames);
                                        fprintf('\n\t\t%i- %s',n,allLinkModelNames{n})
                                    end
                                case 2
                                    fprintf('\n\tEnter a valid Link Model Name or a matching index:\n')
                                    entry=input('Entry: ');
                                    if isa(entry,'numeric')
                                        addedModelName=allLinkModelNames(entry);
                                        
                                    elseif isa(entry,'char')
                                        if Toolkit.isToolkitModel('Link',entry)
                                            addedModelName={entry};
                                        else
                                            fprintf('\n\tInvalid model name\n')
                                            continue
                                            
                                        end
                                    end
                                    
                                    linkModelNames=[linkModelNames addedModelName{:}];
                                    completionArray(2)=1;
                                    
                                case 0
                                    break;
                                    
                            end
                        end
                        
                        data.LinkModelNames=linkModelNames;
                                
                        
                    case 4

                                                
                        fprintf('\n\tSelect one of the following options\n')
                        fprintf('\n\t\t1 - Display registered Solid Models')
                        fprintf('\n\t\t2 - Add Solid Model')
                        
                        option=input('Entry: ');
                        
                        switch option
                            case 1
                                
                                for n=1:length(allSolidModelNames);
                                    fprintf('\n\t\t%i- %s',n,allSolidModelNames{n})
                                end
                            case 2
                                fprintf('\n\tEnter a valid Solid Model Name or matching indexes:\n')
                                entry=input('Entry: ');
                                if isa(entry,'numeric')
                                    addedModelName=allSolidModelNames{entry};
                                    
                                elseif isa(entry,'char')
                                    if Toolkit.isToolkitModel('Solid',entry)
                                        addedModelName=entry;
                                    else
                                        fprintf('\n\tInvalid model name\n')
                                        continue
                                        
                                    end
                                end
                                
                                data.BaseObjectName=addedModelName;
                            otherwise
                                fprintf('\n\tInvalid entry\n')
                                
                        end
                                                 
                    case 5
                        fprintf(['\n\tEnter scalar value between 0 and 1 representative of the reduction \n'...
                            '\tpercentage\n'])
                        data.PatchReduction=abs(input('Entry: '));
                        
                    case 6
                        fprintf('\n\tEnter either a single char character or a 1 x 3 color vector.\n')
                        data.Color=input('Entry: ');                      

                    case 7
                        fieldNames=fieldnames(data);
                        fprintf('\n\tThe currently saved properties are:\n')
                        
                        for n=1:length(fieldNames);
                            
                            switch fieldNames{n}
                                case 'Class'
                                    fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                case 'LinkModelNames'
                                    
                                    linkModelNames=data.LinkModelNames;
                                    fprintf('\n\n\t%1.0f - %s\n',n-1,fieldNames{n})
                                    for m=1:length(linkModelNames);
                                        fprintf('\n\t%1.0f - %s',m,linkModelNames{m})
                                    end
                                    
                                otherwise
                                    fprintf('\n\n\t%1.0f - %s\n',n-1,fieldNames{n})
                                    disp(data.(fieldNames{n}))
                                    
                            end
                        end
                    case 8
                        if all(completionArray)
                            
                            fieldNames=fieldnames(data);
                            fprintf('\n\tThe currently saved properties are:\n')
                            
                            for n=1:length(fieldNames);
                                
                                switch fieldNames{n}
                                    case 'Class'
                                        fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                    case 'LinkModelNames'
                                        
                                        linkModelNames=data.LinkModelNames;
                                        fprintf('\n\n\t%1.0f - %s\n',n-1,fieldNames{n})
                                        for m=1:length(linkModelNames);
                                            fprintf('\n\t%1.0f - %s',m,linkModelNames{m})
                                        end
                                        
                                    otherwise
                                        fprintf('\n\n\t%1.0f - %s\n',n-1,fieldNames{n})
                                        disp(data.(fieldNames{n}))
                                        
                                end
                            end
                            
                            while(true)
                                fprintf('\n\tsave this data?\n\t1 - Yes\n\t2 - No\n')
                                option=input('Enter option number :  ');
                                
                                switch option
                                    case 1                                        
                                        
                                       
                                        % checking if directories exists
                                        directoryName=Toolkit.createToolkitPath(['@' 'Finger'],'ModelFiles',data.ModelName);
                                        if(~isdir(directoryName))
                                            mkdir(Toolkit.createToolkitPath(['@' 'Finger'],'ModelFiles'),data.ModelName);
                                        end
                                        
                                        
                                        destination=Toolkit.createRelativePath(['@' 'Finger'],'ModelFiles',data.ModelName,'ModelData');
                                        FingerModelMap(data.ModelName)=destination;
                                        
                                        
                                        Toolkit.saveToolkitFile(destination,'ConstructionData',data);
                                        Toolkit.saveModelMap;
                                        
                                        fprintf('\n\tFinger Model Succesfully saved\n')
                                        fprintf('\tModel Name %s is now registered\n',data.ModelName)
                                        return;  

                                    case 2
                                        fprintf('\n\tModel Data was not saved\n')
                                        break;
                                    otherwise
                                        fprintf('\n\tWrong entry, Model Data was not saved\n')
                                end
                            end
                        else
                            fprintf('\n\tNot all required fields have been filled\n')
                        end
                                    
                            
                    case 9
                        type(Toolkit.createToolkitPath('@Toolkit','finger_instructions.txt'))
                    case 0
                        break;
                    otherwise
                        fprintf('\n\tWrong entry\n')
                        continue
                        
                        
                end
            end
        end
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function registerHand
            
            if ~Toolkit.isToolkitClass('Hand')
                Toolkit.addToolkitClass('Hand')
            end
            map=Toolkit.ModelMap;
            HandModelMap=map('Hand');
            % initiating data structure fields
            data.Class='Hand';
            data.ModelName=[];
            data.Tag=[];
            data.FingerModelNames={};
            data.PalmModelName={};
            data.Color=-1;
            data.PatchReductionFactor=0;
            
            
            fingerModelNames={};
            allFingerModelNames=Toolkit.getRegisteredModels('Finger');
            allPalmModelNames=Toolkit.getRegisteredModels('Palm');
            completionArray=zeros(1,3);
            while (true)
                type(Toolkit.createToolkitPath('@Toolkit','hand_options.txt'))
                option=input('Enter option number :  ');
                
                switch option
                    case 1
                        fprintf('\n\tEnter a char array with the Model Name:\n')
                        data.ModelName=input('Entry: ');
                        completionArray(1)=1;
                    case 2
                        fprintf('\n\tEnter a desired value for the Tag:\n')
                        data.Tag=input('Entry: ');
                    case 3
                        
                        
                        while(true)
                            fprintf('\n\n\tSelect one of the following options\n')
                            fprintf('\n\t\t1 - Display registered Finger Models')
                            fprintf('\n\t\t2 - Add Finger Model')
                            fprintf('\n\t\t0 - Exit to main menu\n')
                            
                            option=input('Entry: ');
                            
                            switch option(1)
                                case 1
                                    
                                    for n=1:length(allFingerModelNames);
                                        fprintf('\n\t\t%i- %s',n,allFingerModelNames{n})
                                    end
                                case 2
                                    fprintf('\n\tEnter a valid Finger Model Name or matching indexes:\n')
                                    entry=input('Entry: ');
                                    if isa(entry,'numeric')
                                        addedModelName=allFingerModelNames(entry);
                                        
                                    elseif isa(entry,'char')
                                        if Toolkit.isToolkitModel('Finger',entry)
                                            addedModelName={entry};
                                        else
                                            fprintf('\n\tInvalid model name\n')
                                            continue
                                            
                                        end
                                    end                                   
                                    
                                    
                                    fingerModelNames=[fingerModelNames addedModelName{:}];
                                    completionArray(2)=1;
                                    
                                case 0
                                    break;
                                    
                            end
                        end
                        
                        data.FingerModelNames=fingerModelNames;
                        
                        
                    case 4
                        
                        while(true)
                            fprintf('\n\n\tSelect one of the following options\n')
                            fprintf('\n\t\t1 - Display registered Palm Models')
                            fprintf('\n\t\t2 - Add Palm Model\n')
                            
                            option=input('Entry: ');
                            
                            switch option
                                case 1
                                    
                                    for n=1:length(allPalmModelNames);
                                        fprintf('\n\t\t%i- %s',n,allPalmModelNames{n})
                                    end
                                case 2
                                    fprintf('\n\tEnter a valid Palm Model Name or a matching index:\n')
                                    entry=input('Entry: ');
                                    if isa(entry,'numeric')
                                        addedModelName=allPalmModelNames{entry};
                                        
                                    elseif isa(entry,'char')
                                        if Toolkit.isToolkitModel('Palm',entry)
                                            addedModelName=entry;
                                        else
                                            fprintf('\n\tInvalid model name\n')
                                            continue
                                            
                                        end
                                    end
                                    
                                    data.PalmModelName=addedModelName;
                                    completionArray(3)=1;
                                    break;
                                otherwise
                                    fprintf('\n\tInvalid entry\n')
                                    
                            end
                        end
                    
                    case 5
                        fprintf('\n\tEnter either a single char character or a 1 x 3 color vector.\n')
                        data.Color=input('Entry: ');
                    case 6
                        fprintf(['\n\tEnter scalar value between 0 and 1 representative of the reduction \n'...
                            '\tpercentage\n'])
                        data.PatchReductionFactor=abs(input('Entry: '));
                    case 7
                        fieldNames=fieldnames(data);
                        fprintf('\n\tThe currently saved properties are:\n')
                        
                        for n=1:length(fieldNames);
                            
                            switch fieldNames{n}
                                case 'Class'
                                    fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                case 'FingerModelNames'
                                    
                                    fingerModelNames=data.FingerModelNames;
                                    fprintf('\n\n\t%1.0f - %s\n',n-1,fieldNames{n})
                                    for m=1:length(fingerModelNames);
                                        fprintf('\n\t%1.0f - %s',m,fingerModelNames{m})
                                    end
                                    
                                otherwise
                                    if isa(data.(fieldNames{n}),'char')
                                        fprintf('\n\n\t%1.0f - %s\n',n-1,fieldNames{n})
                                        fprintf('\n\n\t%s\n',data.(fieldNames{n}))
                                    else
                                        fprintf('\n\n\t%1.0f - %s\n',n-1,fieldNames{n})
                                        disp(data.(fieldNames{n}))
                                    end
                                    
                            end
                        end
                    case 8
                        if all(completionArray)
                            
                            fieldNames=fieldnames(data);
                            fprintf('\n\tThe following data will be saved:\n')
                            
                            for n=1:length(fieldNames);
                                
                                switch fieldNames{n}
                                    case 'Class'
                                        fprintf('\n\t--------------%s Model Data-------------',data.(fieldNames{n}))
                                    case 'FingerModelNames'
                                        
                                        fingerModelNames=data.FingerModelNames;
                                        fprintf('\n\n\t%1.0f - %s\n',n-1,fieldNames{n})
                                        for m=1:length(fingerModelNames);
                                            fprintf('\n\t%1.0f - %s',m,fingerModelNames{m})
                                        end
                                        
                                    otherwise
                                        fprintf('\n\n\t%1.0f - %s\n',n-1,fieldNames{n})
                                        disp(data.(fieldNames{n}))
                                        
                                end
                            end
                            
                            while(true)
                                fprintf('\n\tsave this data?\n\t1 - Yes\n\t2 - No\n')
                                option=input('Enter option number :  ');
                                
                                switch option
                                    case 1
                                        
                                        % checking if directories exists
                                        directoryName=Toolkit.createToolkitPath(['@' 'Hand'],'ModelFiles',data.ModelName);
                                        if(~isdir(directoryName))
                                            mkdir(Toolkit.createToolkitPath(['@' 'Hand'],'ModelFiles'),data.ModelName);
                                        end
                                        
                                        
                                        destination=Toolkit.createRelativePath(['@' 'Hand'],'ModelFiles',data.ModelName,'ModelData');
                                        HandModelMap(data.ModelName)=destination;
                                        
                                        
                                        Toolkit.saveToolkitFile(destination,'ConstructionData',data);
                                        Toolkit.saveModelMap;
                                        
                                        fprintf('\n\tHand Model Succesfully saved\n')
                                        fprintf('\tModel Name %s is now registered\n',data.ModelName)
                                        return; 
                                                               
                                    case 2
                                        fprintf('\n\tModel Data was not saved\n')
                                        break;
                                    otherwise
                                        fprintf('\n\tWrong entry, Model Data was not saved\n')
                                end
                            end
                        else
                            fprintf('\n\tNot all required fields have been filled\n')
                        end
                        
                        
                    case 9
                        type(Toolkit.createToolkitPath('@Toolkit','hand_instructions.txt'))
                    case 0
                        break;
                    otherwise
                        fprintf('\n\tWrong entry\n')
                        continue
                        
                        
                end
            end
        end
    end
    
    methods (Static=true,Access=private)        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function map=loadModelMap
            location=Toolkit.createRelativePath('@Toolkit','ToolkitData');
            s=Toolkit.loadToolkitFile(location,'ModelMap');
            map=s.ModelMap;
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function saveModelMap
            location=Toolkit.createRelativePath('@Toolkit','ToolkitData');
            Toolkit.appendToolkitFile(location,'ModelMap',Toolkit.ModelMap)
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function addToolkitClass(className)
            modelMap=Toolkit.ModelMap;
            modelMap(className)=containers.Map;
            Toolkit.saveModelMap;
        end
        
    end
    
    
    
    
end

% This class should also keep track of all of the registered models

 function r=getRootPath
            pathFiles=what(Toolkit.ToolkitName);
            r=pathFiles.path;
 end
 
 function dsize=getAverageSize(vertices)
dsize(1)=abs(max(vertices(:,1))-min(vertices(:,1)));
dsize(2)=abs(max(vertices(:,2))-min(vertices(:,2)));
dsize(3)=abs(max(vertices(:,3))-min(vertices(:,3)));
disp(dsize)
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