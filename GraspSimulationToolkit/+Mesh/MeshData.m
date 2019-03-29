classdef MeshData < handle
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % internal static properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(Access = protected,Constant = true)
        
        sMeshVertices  = Mesh.MeshData.initializeContainer('entry',eye(3));
                         % holds vertex data of all loaded meshes
                         
        sMeshFaces = Mesh.MeshData.initializeContainer('entry',int32(eye(3)));
                         % holds faces data of all loaded meshes
                         
        sMeshFileNames = Mesh.MeshData.initializeContainer('entry','val');
                         % holds file names of all loaded meshes
                         
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public static methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Static = true)
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function vert = getMeshVertices(modelName)
           
            vert = Mesh.MeshData.sMeshVertices(modelName);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function faces = getMeshFaces(modelName)            
            
            faces = Mesh.MeshData.sMeshFaces(modelName);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function data = getMeshDataStruct(modelName)
            
            import Mesh.*
            
            data = struct('vertices',[],'faces',[],'modelName',modelName);
            
            data.vertices = MeshData.sMeshVertices(modelName);
            data.faces = MeshData.sMeshFaces(modelName);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function bool = isMeshLoaded(modelName)
            
            bool = Mesh.MeshData.sMeshFileNames.isKey(modelName);
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function reduceMeshResolution(modelName,reductionFactor)
            % reduces mesh resolution by eliminating vertices while
            % attempting to mantain the original form
            
            import Mesh.*
            if reductionFactor <= 0
                return
            end
            
            vertices = MeshData.sMeshVertices(modelName);
            faces = MeshData.sMeshFaces(modelName);
            
            newData=reducepatch(faces,vertices,reductionFactor);
            
            % retrieving references to class map containers in order to
            % avoid the matlab parsing errors
            verticesMap = MeshData.sMeshVertices;
            facesMap = MeshData.sMeshFaces;
            
            verticesMap(modelName) = newData.vertices;
            facesMap(modelName) = newData.faces;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function restoreMeshResolution(modelName)
            
            import Mesh.*
            if MeshData.isMeshLoaded(modelName)
                
                loadMeshData(modelName);
                
            else
                
                error(['Model name ',modelName,' is not currently loaded.'])
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadMeshData(modelName)
            
            import Mesh.*
            
            if ~MeshData.isMeshLoaded(modelName)
                
                data = Toolkit.loadModelData('Mesh',modelName,'MeshData');
                
                mapVertices = MeshData.sMeshVertices;
                mapVertices(modelName) = data.Vertices;
                
                mapFaces = MeshData.sMeshFaces;
                mapFaces(modelName) = int32(data.Faces);
                
                mapFileName = MeshData.sMeshFileNames;
                mapFileName(modelName) = data.FileName;
                
            end
            
        end
            
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function releaseMeshData(modelName)
            % releases currently loaded mesh data.  Using this function is
            % not recomended.
            
            import Mesh.*
            
            if MeshData.isMeshLoaded(modelName)
                
                MeshData.sMeshVertices.remove(modelName);
                MeshData.sMeshFaces.remove(modelName);
                MeshData.sMeshFileNames.remove(modelName);
                
            else
                
                error(['Model name ',modelName,' is not currently loaded.'])
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function dispLoadedMeshes
            import Mesh.*
            modelNames = Mesh.MeshData.sMeshFileNames.keys;
            fprintf('\nMeshData:\tCurrently loaded meshes:\n\n')
            
            for n = 1:MeshData.sMeshFileNames.length;
                
                fprintf(['\t- ',modelNames{n},'\n'])
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function modelNames = getLoadedMeshes
            
            modelNames = Mesh.MeshData.sMeshFileNames.keys;
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % protected static methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Access = protected,Static = true)
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function map = initializeContainer(keyType,valType)
            % initializes the map to the corresponing key and value type
            % and returns an empty container
            
            map = containers.Map(keyType,valType);
            map.remove(keyType);
            
        end
        
    end
    
end
    
    
                
            