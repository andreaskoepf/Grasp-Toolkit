classdef Palm < Solid
   properties (SetAccess=protected)
       LocalNodes=eye(4);
   end
   
   properties (Dependent=true,SetAccess=protected)
       Nodes
   end
   
   methods
       function p=Palm(varargin)
            switch nargin
                case 0
                    return
                case 1
                    if isa(varargin{1},'Palm')
                        data=varargin{1}.toStruct;
                        
                        for n=1:length(data)
                            p(n).loadFieldsFromStruct(data(n));
                        end  
                    elseif isa(varargin{1},'char')
                        data=Toolkit.loadModelData('Palm',varargin{1});


                        p.loadFieldsFromStruct(data);
                        p.reducePatch(data.PatchReductionFactor);
                        p.shift(data.NewReferenceFrame\eye(4));
                        p.restore;
                        p.LocalNodes=data.LocalNodes;
                        
                    elseif isa(varargin{1},'struct')
                        
                        data=varargin{1};
                        
                        for n=1:length(data)
                            p(n).loadFieldsFromStruct(data(n));
                        end
                    end
            end
       end
       
       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function loadFieldsFromStruct(p,data)
           indexes=1:length(data);
           
           for n=indexes;
               p(n).loadFieldsFromStruct@Solid(data);
               p(n).LocalNodes=data.LocalNodes;
           end
        
       end
       
       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function nodes=get.Nodes(p)
           % returns the current configuration of the frames of the finger
           % bases relative 
           indexes=1:size(p.LocalNodes,3);
           
           nodes=zeros(4,4,size(p.LocalNodes,3));
           for n=indexes;
               nodes(:,:,n)=p.Frame*p.LocalNodes(:,:,n);
           end

       end
       
       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       function scale(p,f)
            p.scale@Solid(f);
            
            for n=1:size(p.Nodes,3);
                p.LocalNodes(1:3,4,n)=f*p.LocalNodes(1:3,4,n);
            end
            
        end
   end
end