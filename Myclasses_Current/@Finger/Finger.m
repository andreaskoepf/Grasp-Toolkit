classdef Finger < ArticulatedBody
    
    properties(SetAccess=protected)
        ModelName
        Tag
        Dimensions
        Contact
    end
    
    methods 
        function f=Finger(varargin)
            switch nargin
                case 0
                    return
                case 1
                    if isa(varargin{1},'Finger')
                        data=varargin{1}.toStruct;
                        
                        for n=1:length(data)
                            f(n).loadFieldsFromStruct(data(n));
                        end  
                    elseif isa(varargin{1},'char')
                        data=Toolkit.loadModelData('Finger',varargin{1});
                        
                        if ~isempty(data.BaseObjectName)
                           f.BaseObject=Solid(data.BaseObjectName);
                        end
                        
                        for n=1:length(data.LinkModelNames)
                            links(n)=Link(data.LinkModelNames{n});
                            links(n).reducePatch(data.PatchReductionFactor);
                            
                            if all(data.Color~=-1)
                                links(n).Color=data.Color;
                            end
                        end
                        
                        f.Links=links;
                        
                        f.IsDynamic=0;
                        
                        f.ModelName=data.ModelName;
                        f.Tag=data.Tag;
                    elseif isa(varargin{1},'struct')
                        
                        data=varargin{1};
                        
                        for n=1:length(data)
                            f(n).loadFieldsFromStruct(data(n));
                        end
                        
                    elseif isa(varargin{1},'Link') 
                        for n=1:length(varargin{1});
                            links(n)=Link(varargin{1}(n));
                        end
                        f.Links=links;
                    else
                        error('invalid argument')
                        
                    end
                case 2
                    if isa(varargin{1},'Link') && isa(varargin{2},'Solid')
                        for n=1:length(varargin{1});
                            links(n)=Link(varargin{1}(n));
                        end
                        f.Links=links;
                        f.BaseObject=Solid(varargin{2});
                    else
                        error('invalid arguments')
                        
                    end
            end
        end        
       
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFieldsFromStruct(f,data)
            indexes=1:length(data);
            % assigning data to the fields
            for n=indexes;
                
                f(n).loadFieldsFromStruct@ArticulatedBody(data(n));
                f(n).ModelName=data(n).ModelName;
                f(n).Tag=data(n).Tag;
                
            end
        end
    end
                    
        
end