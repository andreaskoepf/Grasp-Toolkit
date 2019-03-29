classdef HandTemplate
    properties
        FingersStyle
        FingersTypes
        PalmStyle
        PalmType
    end
    
    
    
    methods 
        function template=HandTemplate(htype)
            
            % Loading full Path Directory and storing it 
            %pathFiles=what('MyClasses');
            dirPath=Toolkit.createToolkitPath('Hand',htype,'HandDetails');
            %dirPath=fullfile(pathFiles.path,'Hand',htype,'HandDetails');
            
            
            
            % loading template
            try
                s=load(dirPath,'template');
            catch
                error(['This Hand type has not been defined yet'])
            end
            
            template.FingersStyle=s.template.FingersStyle;
            template.FingersTypes=s.template.FingersTypes;
            template.PalmStyle=s.template.PalmStyle;
            template.PalmType=s.template.PalmType;
                
        end
        
        
    end
    
    
    methods (Static)
        function addTemplate(htype)
            
            
            % ADDTEMPLATE
            %
            %   addTemplate(htype)
            %       Static function of the PalmTemplate class that creates a
            %       structure file containing the details of construction
            %       of a Palm object.  It propmts the user for
            %       information to be entered, the information is then
            %       stored.  The MAT file is saved in the same directory
            %       where the STL file for the corresponding file exist.
            %       
            %       ptype: 
            %           String array containing the name of Palm type
            %
            %       style:
            %           String array containing the name of style.
            %          

       
            

            % creating directory name
            dirPath=Toolkit.createToolkitPath('Hand',htype);
            %dirPath=['Hand\' htype];



            % verifying that path exists
            if ~isdir(dirPath)

                % make directory if it doesn't exist
                mkdir(dirPath)

            end



            %%%%%%%%%%%%%%% Prompt user for phalanx specifics %%%%%%%%%
            
            fprintf('\n----------- Hand Details Specification File Creation ----------\n\n')
            fprintf(['\t\tThe following prompts will query for information which will be stored\n '...
                '\t\tand utilized in the construction of hand objects that match the specified\n'...
                '\t\tcharacteristics.\tA total of 5 steps must be completed in order to ensure\n'...
                '\t\tsuccessful creation of the Phalanx definition file.\n\n'])
            
            
            while(true)
                % prompt user for fingers Style
                fprintf('\n\n\t- Step 1: Fingers Style\n\t\t')
                fprintf('Enter the style for the Finger objects (as a string) to be used with this hand type:\n\t');
                arg=input('Entry:');

                template.FingersStyle=arg;



                % propmt user for finger types
                fprintf('\n\n\t- Step 2: Fingers Types\n\t\t')
                fprintf(['Enter the types of each Finger object as a cell array of strings as\n\t\t'...
                    '{''index'' ''middle'' ''ring'' ... ''pinky'' ''thumb''}\n\t']);
                arg=input('Entry:');
                template.FingersTypes=arg;



                % prompt user for palm Style
                fprintf('\n\n\t- Step 3: Palm Style\n\t\t')
                fprintf('Enter the style for the Palm object  as a string:\n\t');
                arg=input('Entry:');
                template.PalmStyle=arg;


                % prompt user for palm type
                fprintf('\n\n\t- Step 4: Palm Type\n\t\t')
                fprintf('Enter the type for the Palm object as a string:\n\t');
                arg=input('Entry:');
                template.PalmType=arg;

                
                % Displaying the entries
                fprintf('\n\n\t- Step 5: Confirmation \n\t\t')
                fprintf('The following data has been entered for the configuration file\n\t\t')
                fprintf('Hand Type:\t%s\n',htype)
                fprintf('\n\t\t1 - Fingers Style:\n\t\t\t%s',template.FingersStyle)
                
                fprintf('\n\n\t\t2 - Fingers Types:\n')
                for n=1:length(template.FingersTypes);
                    fprintf('\n\t\t\t- Finger %1.0f:\t%s',n,template.FingersTypes{n})
                end
                
                fprintf('\n\n\t\t3 - Palm Style:\n\n')
                fprintf('\t\t\t%s',template.PalmStyle')
                
                
                fprintf('\n\n\t\t4 - Palm Type:\n\n')
                    fprintf('\t\t\t%s',template.PalmType)
                
                
                fprintf('\n\n\t\tSave Configuration file?:\n\t\t\t1 - %s\n\t\t\t2 - %s\n\t\t\t3 - %s\n\t\t','save','reenter data',...
                    'quit without saving')
                s=input('Entry: ');
                
                switch s
                    case 1
                        break;
                    case 2;
                        continue;
                    case 3
                        fprintf('\n\t\tConfiguration file was not saved\n')
                        return;
                end                
                

            end
            
            
            % saving structure
            save([dirPath '\HandDetails'],'template')
            
            fprintf(['\n\n\tCreation of Specification File Finished\n'...
                '\t---------------------------------------\n\n'])
        
        end
    end
end
