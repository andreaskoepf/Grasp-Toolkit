classdef Phalanx < Link
    properties
%         Contact
%         ContactModelType
    end
    
    %Notes
    % in the future a loadFieldsFromStruct might need to be created in
    % order to initialize the ContactModelType property
    
    methods
        function p=Phalanx(varargin)
            switch nargin
                case 0
                    return
                case 1  
                    
                    if isa(varargin{1},'Phalanx')
                        data=varargin{1}.toStruct;
                        
                        for n=1:length(data)
                            p(n).loadFieldsFromStruct(data(n));
                        end                        
                            
                    elseif isa(varargin{1},'char')
                            
                        % load existing model data file
                        data=Toolkit.loadModelData('Phalanx',varargin{1});                        
                        
                        p.loadFieldsFromStruct(data);
                        p.reducePatch(data.PatchReductionFactor)
                        p.shift(data.NewReferenceFrame\eye(4));
                        p.restore; % This is to ensure that the object is resized
                                                             % properly after shifting
                                         
                        
                    elseif isa(varargin{1},'struct')
                        
                        % this option may required additional checking 
                        % statements
                        data=varargin{1};
                        
                        for n=1:length(data)
                            p(n).loadFieldsFromStruct(data(n));
                        end
                        
                    end
                 
                    
                   
                otherwise
                    error('Wrong Number of Input Arguments')
            end
            

        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFieldsFromStruct(link,data)
            indexes=1:length(data);
            % assigning data to the fields
            for n=indexes;
                link(n).loadFieldsFromStruct@Link(data(n));

            end

        end
        
    end
        
end