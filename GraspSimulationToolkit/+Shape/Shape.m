classdef Shape < BaseClasses.Node
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % identification attributes
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(SetAccess = protected)
        
        mModelName = 'undefined';
        mGeometryID = Shape.Shape.SHAPE_EMPTY;
        mTag
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Shape type constant attributes
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(Constant)
        
        SHAPE_EMPTY = int32(0);
        SHAPE_POINT = int32(1);
        SHAPE_PLANE = int32(2);
        SHAPE_BOX = int32(3);
        SHAPE_SPHERE = int32(4);
        SHAPE_COMPOUND = int32(5);
        SHAPE_CYLINDER = int32(6);
        SHAPE_CAPSULE = int32(7);
        SHAPE_TERRAINMESH = int32(8);
        SHAPE_TRIMESH = int32(9);
        
    end      
   
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % constructor and initialization methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function shape = Shape(varargin)
            % this method should load data from model and add the
            % corresponding mesh objects
            
            if nargin == 0
                
                return;
                
            else
                
                arg = varargin{1};
                
            end
            
            switch class(arg)
                case 'char'
                    
                    shape.loadFromModel(arg);
                    
                case 'struct'
                    
                    shape.loadFromStruct(arg);
                    
                otherwise
                    
                    error('Invalid input argument type')
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFromModel(shape,modelName)
            
            shape.loadFromStruct(Toolkit.loadModelData('Shape',modelName,'ConstructionInfo'));
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFromStruct(shape,constructionInfoStruct)
            
            % destroying previous data
            shape.removeAllChildNodes;
            
            % entering new data
            shape.mModelName = constructionInfoStruct.ModelName;
            shape.mTag = constructionInfoStruct.Tag;
            shape.mGeometryID = constructionInfoStruct.GeometryID;
            shape.mScale = constructionInfoStruct.Scale;
            
            % creating meshes
            numMeshes = length(constructionInfoStruct.Meshes);
            
            for n = 1:numMeshes;
                
                mesh = Mesh.Mesh(constructionInfoStruct.Meshes(n).ModelName);                
                shape.addChildNode(mesh);
                mesh.setTransform(constructionInfoStruct.Meshes(n).Transform,...
                    Transform.PARENT_SPACE);
                mesh.setScale(constructionInfoStruct.Meshes(n).Scale);
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function consInfo = getConstructionInfoStruct(shape)
            
            consInfo = struct('ModelName',[],'Tag',[],'GeometryID',[],'Meshes',[]);
            
            consInfo.ModelName = shape.mModelName;
            consInfo.Tag = shape.mTag;
            consInfo.GeometryID = shape.mGeometryID;
            consInfo.Scale = shape.getScale;
            consInfo.Transform = shape.getUnscaledLocalTransform;
            
            % creating empty mesh
            %m = Mesh.Mesh('BoxMesh');
            
            numMeshes = shape.getNumOfChildNodes;
            %fieldNames = fieldnames(m.getConstructionInfoStruct);
            %meshes(numMeshes) = cell2struct(fieldNames,cell(size(fieldNames)));
            
            for n = 1:numMeshes;
                
                mesh = shape.getChildNode(n);
                meshes(n) = mesh.getConstructionInfoStruct;
                %meshes(n).Transform = mesh.getUnscaledTransform;
                %meshes(n).Scale = mesh.getScale;
                
            end
            
            consInfo.Meshes = meshes;           
            
        end
        
    end
         
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Static registration utility methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Static = true)
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function createXMLRegistrationTemplate(modelName)
            % creates an XML file corresponding the the structure of the
            % shape model to be registered.  Once the data has been entered
            % accordingly, save the xml and call the
            % Toolkit.registerModel('Shape',xmlFileName) method and choose 
            % the xml file just saved
            
            % creating xml tags and default values
            xmlStruct.ModelName = modelName;
            xmlStruct.Tag = ' ';
            xmlStruct.GeometryID = 'Shape.SHAPE_TRIMESH';
            xmlStruct.Scale = '[1 1 1]';
            %xmlStruct.NumOfMeshes = 1;
            
            meshStruct.ModelName = 'undefined';
            meshStruct.Transform = 'eye(4)';
            meshStruct.Scale = '[1 1 1]';
            
            xmlStruct.Meshes = meshStruct;
            
            % converting xml document specifications to string data
            xmlStr = xml_format(xmlStruct,'off','ShapeModel');
            
            % creating xml file
            fName = [modelName,'.xml'];
            
            % document header
            headerStr = sprintf('%s\n','<!-- Shape Model Registration File -->');
            
            % document instructions
            instructionStr = cell(3);
            instructionStr(1) = {sprintf('%s\n','<!-- Instructions -->')};
            instructionStr(2) = {sprintf(['<!-- Additional Options for GeometryID are: -->',...
                '\n<!--\tSHAPE_EMPTY\t-->','\n<!--\tSHAPE_POINT\t-->','\n<!--\tSHAPE_PLANE\t-->','\n<!--\tSHAPE_BOX\t-->','\n<!--\tSHAPE_SPHERE\t-->',...
                '\n<!--\tSHAPE_COMPOUND\t-->','\n<!--\tSHAPE_CYLINDER\t-->','\n<!--\tSHAPE_CAPSULE\t-->','\n<!--\tSHAPE_TERRAINMESH\t-->\n'])};
            instructionStr(3) = {sprintf('%s\n','<!-- End Of Instructions -->')};
            
            % opening file for writing
            file = fopen(fName,'w');
            
            % writing xml header as a comment entry
            fprintf(file,'%s',headerStr);
            
            % writing xml instructions as comment entries
            for n = 1:length(instructionStr);
                fprintf(file,'%s',instructionStr{n});
            end
            
            % writing xml contents
            fprintf(file,'%s',xmlStr);
            
            % closing file
            fclose(file);
            
            % opening file
            open(fName);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function [modelName,modelDataFiles,modelDocuments] = parseXMLRegistrationDocument(xmlFileName)
            % parseXMLRegistrationDocument
            %   [modelName,modelDataFiles,modeDocuments] = parseXMLRegistrationDocument(xmlFileName)
            %   Parses a xml document and returns the corresponding data.
            %   The results and the contents of each output variable are
            %   different for every class. The input argument must contain
            %   an absolute path to a xml document.
            fprintf('\nStarting xml document parsing for shape object')
            
            import Shape.*
            
            xmlStruct = xml_load(xmlFileName,'off');
            
            % retrieving model name
            modelName = xmlStruct.ModelName;
            
            
            try
                
                % retrieving construction Info
                constructionInfo.ModelName = xmlStruct.ModelName;
                constructionInfo.Tag = xmlStruct.Tag;
                constructionInfo.GeometryID = eval(xmlStruct.GeometryID);
                constructionInfo.Scale = eval(xmlStruct.Scale);

                numMeshes = length(xmlStruct.Meshes);
                meshes(numMeshes) = struct('ModelName',[],...
                    'Transform',[]);

                for n = 1:numMeshes;

                    meshes(n).ModelName = xmlStruct.Meshes(n).ModelName;
                    meshes(n).Transform = eval(xmlStruct.Meshes(n).Transform);
                    meshes(n).Scale = eval(xmlStruct.Meshes(n).Scale);

                end
            
            catch
                
                error('Expresion entered in xml document is incorrect')
                
            end
            
            constructionInfo.Meshes = meshes;
            
            % collecting model data files into struct
            modelDataFiles.ConstructionInfo = constructionInfo;
            
            % collecting model documents into cell array
            modelDocuments{1} = xmlFileName;   
            
            fprintf('\nCompleted xml document parsing for shape object')
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % overloaded node management methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function addChildNode(shape,mesh)
            import BaseClasses.Node
            import Mesh.*
            
            if isa(mesh,'Mesh')
                
                shape.addChildNode@BaseClasses.Node(mesh);
                
            else
                
                error('Only objects of the mesh class can be added to a shape object')
                
            end
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public get methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods 
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getModelName(shape)
            
            val = shape.mModelName;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function val = getGeometryID(shape)
            
            val = shape.mGeometryID;
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % mesh data manipulation methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function reduceMeshResolution(shape,reductionFactor,index)
            % reduces mesh resolution by the given factor.  the
            % reductionFactor argument should be a number between 0 and 1
            
            if shape.mNumOfChildNodes == int32(0)                
                
                return
                
            end
            
            switch nargin
                
                case 1 
                    error('Must provide a value for the reduction Factor')
                case 2
                    
                    index = int32(1):shape.mNumOfChildShapes;
                    
            end
            
            for n = index;
                
                mesh = shape.getChildNode(n);
                mesh.reduceMeshResolution(reductionFactor);
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function restoreMeshResolution(shape,index)
            % restores mesh resolution to the original state and cancels
            % the effect of previous mesh resolution reductions.
            
            if shape.mNumOfChildNodes == int32(0)                
                
                return
                
            end
            
            switch nargin
                
                case 1 
                    index = int32(1):shape.mNumOfChildShapes;
                    
            end
            
            for n = index;
                
                mesh = shape.getChildNode(n);
                mesh.restoreMeshResolution;
                
            end
            
        end
        
    end      
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % graphics manipulation inherited protected methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Access = protected)
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%         function displayWindow(shape)
%             
%             if shape.mNumOfChildNodes > int32(0)
%                 
%                 mesh = shape.getChildNode(int32(1));
%                 mesh.displayWindow;
%                 
%             end
%             
%         end
        
    end 
        
end


