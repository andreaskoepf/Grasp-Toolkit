% Restructure Toolkit Data Program

%% loading data
s=load(Toolkit.createToolkitPath('@Toolkit','ToolkitData'));

ModelMap=s.ModelMap;

%% retrieving keys

ClassNames=keys(ModelMap);

%% looping through every class and storing each model into individual data
%% files
for n=1:length(ClassNames);
    ClassContainer=ModelMap(ClassNames{n});
    
    % retrieving model names
    ModelNames=keys(ClassContainer);
    
    for m=1:length(ModelNames)
        
        % retrieving structure data
        ConstructionData=ClassContainer(ModelNames{m});
        
        % checking if directories exists
        directoryName=Toolkit.createToolkitPath(['@' ClassNames{n}],'ModelFiles',ModelNames{m});
        if(~isdir(directoryName))
            mkdir(Toolkit.createToolkitPath(['@' ClassNames{n}],'ModelFiles'),ModelNames{m});
        end
        
        destination=Toolkit.createRelativePath(['@' ClassNames{n}],'ModelFiles',ModelNames{m},'ModelData');
        
        % saving data structure in the corresponding folder
        Toolkit.saveToolkitFile(destination,'ConstructionData',ConstructionData);
        
        
        % storing path to data in the class map container
        ClassContainer(ModelNames{m})=destination;
        
        
        
        % save data structure on in a mat file
        
        % save the string containing the file path and name in the value
        % corresponding to the key 
        
        
    end
end


%% saving model Map
location=Toolkit.createRelativePath('@Toolkit','ToolkitData');
Toolkit.saveToolkitFile(location,'ModelMap',ModelMap)
            
            
            