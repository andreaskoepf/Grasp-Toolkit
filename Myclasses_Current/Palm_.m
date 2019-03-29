classdef Palm < Solid
    % Pending List
    % Include Default Generating methods in the Hand classdef file for the
    % following variables: defaultMetacarpal, default_xOffset
    
    
    
    properties ( SetAccess=protected )
        DefaultNodes
        Type
        Style
        FingerArray
    end
    
    properties (Dependent=true,SetAccess=private)
        Nodes
    end
    

    
    
    methods
        function p=Palm(varargin)
            % p=Palm(arg1,arg2,xOffset,style)
            % PALM  Construct palm objects
            %
            %   Constructor 1
            %   p = Palm(fingers,metacarpal,xOffset,style)
            %       fingers     = Finger Array
            %       metacarpal  = Distance from the thumb base along the z
            %                     axis
            %       xOffset     = Distance from the thumb base along the x
            %                     axis
            %       base        = Palm base frame
            %       style       = Template style
            %
            %   Constructor 2
            %   p = Palm(scale,type,style,)
            %       scale       = Scaling factor
            %       type        = Palm type within specified style (fixeds
            %                     styles only).
            %       style       = Style of specified palm
            %
            
            if isa(varargin{3},'numeric') % flexible styles
                
                
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                % Step 1    : Inspecting initial data                     %
                % Relevant Variables:                                     %
                %           - fingers                                     %
                %           - thumb                                       %
                %           - xOffset                                     %
                %           - base                                        %
                %           - metacarpal                                  %
                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
                
                
                
                fingers=varargin{1};
                metacarpal=varargin{2};
                xOffset=varargin{3}; 
                style=varargin{4};
                if ~isa(style,'numeric')
                    error('not a valid style for flexible style, use numeric value 1')
                end
                
                                              
                
                
                [thumb,fingers]=getThumb(fingers);
                [xOffset,fingers]=check_xOffset(fingers,xOffset);
                yOffset=check_yOffset(fingers,metacarpal);
                
                template=PalmTemplate(fingers,thumb(end),style,xOffset,yOffset);
                
                % building each individual part
                
                palmDetails=template.PalmDetails;
                for n=1:length(palmDetails);
                    disp(['constructing part ' palmDetails(n).FileName])
                    part(n)=Solid(palmDetails(n).FileName);
                    part(n).shift(palmDetails(n).MoveToOrigin);
                    part(n).DefaultDimensions=palmDetails(n).OriginalSize;
                    part(n).resize(palmDetails(n).Dimensions);
                    part(n).shift(palmDetails(n).Relocate);
                end
                
                gap=template.Gaps;
                index=length(part);
                for n=index+1:index+length(template.Gaps);
                    part(n)=Solid;
                    part(n).Vertices=gap(n-index).Vertices;
                    part(n).DefaultVertices=gap(n-index).Vertices;
                    part(n).Faces=gap(n-index).Faces;
                end
                
                
                % constructing finger array
                fArray=[fingers thumb];
                scale=1;
                type='none';
                
                
            elseif isa(varargin{3},'char')
                % fixed styles
                
                scale=varargin{1};
                type=varargin{2};
                style=varargin{3};
                
                
                template=PalmTemplate(scale,type,style);
                
                palmDetails=template.PalmDetails;
                disp(['constructing part ' palmDetails.FileDirectory])
                part=Solid(palmDetails.FileDirectory);
                part.DefaultDimensions=palmDetails.DefaultDimensions;
                part.shift(palmDetails.Relocate);
                part.resize(palmDetails.Dimensions);
                part.reducePatch(palmDetails.ReductionRatio);
                
                fArray=[];
            end
            
            
            
            
            
            
            
            % Object instantiation goes here
            p=p@Solid(sum(part));
            p.Type=type;
            p.Style=style;
            p.Color=template.Color;
            p.DefaultNodes=template.Nodes;
            p.FingerArray=fArray;
            p.scale(scale);
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function p=resize(p,dimensions)
            p.resize@Solid(dimensions);
            

            for n=1:size(p.Nodes,3);
                p.DefaultNodes(1:3,4,n)=(dimensions./p.DefaultDimensions)'.*p.DefaultNodes(1:3,4,n);
            end
            
        end
        
        function p=scale(p,f)
            p.scale@Solid(f);
            
            for n=1:size(p.Nodes,3);
                p.DefaultNodes(1:3,4,n)=f*p.DefaultNodes(1:3,4,n);
            end
            
        end
                
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function nodes=get.Nodes(p)
            nodes=zeros(4,4,size(p.DefaultNodes,3));
            
            for n=1:size(p.DefaultNodes,3);
                nodes(:,:,n)=p.Frame*p.DefaultNodes(:,:,n);
            end
            
        end
                
    end

    
end

function [thumb,fingers]=getThumb(fingers)
% verifying that thumb is provided with the finger array
if ~any(isThumb(fingers))
    error('A thumb Type finger must be provided in the array')
end

% extracting thumb
thumb=fingers(isThumb(fingers));
%thumb=thumb(end);

fingers=fingers(~isThumb(fingers));

end


function [xOffset,fingers]=check_xOffset(fingers,xOffset)
% verifying number of elements of xOffset
if length(xOffset)~=length(fingers)  % consider completing elements
    error('%s\n%s','Number of elements of xOffset argument must equal',...
        'number of fingers (without thumb) provided in the finger array argument')
end

% rearranging xOffset Data
[xOffset,index]=sort(reshape(xOffset,1,length(xOffset)),2,'ascend');

% rearranging finger Elements
fingers=fingers(index);

% inspecting xOffset Data
for n=1:length(xOffset)-1;
    
    xOffsetMin=fingers(n).Size(3)/2+fingers(n+1).Size(3)/2; %minimum allowed
    
    if xOffset(n+1)-xOffset(n)<xOffsetMin; % resized if less than minimum allowed
        
        xOffset(n+1:end)=xOffset(n+1:end)+xOffsetMin-(xOffset(n+1)-xOffset(n));
        
    end
    
end

end


% * - check method so that minimum limits do not go over the thumb area
function yOffset=check_yOffset(fingers,metacarpal)

if ~(length(metacarpal)==length(fingers))  % consider completing elements
    error('%s\n%s','Number of elements in metacarpal argument must equal the',...
        'the number of fingers located in the upper part of the palm')
end


yOffset=-abs(metacarpal);


end

