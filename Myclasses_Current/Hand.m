classdef Hand < handle
    properties (SetAccess = protected)
        
        Nodes
        PalmObject
        Fingers
        Type
        
    end
    
    properties
        
        Base=eye(4);
        
    end
    
    events
        UpdateElements
    end
    
    methods
        function h=Hand(varargin)
            %   TYPE 1 CONSTRUCTOR
            %
            %   hand=Hand(fingers,metacarpal,separation,palmstyle) % 
            %   fingers     :   Array of finger objects ( A thumb finger
            %                   must be in the array.
            %
            %   metacarpal  :   1 x n numerical array which contains 
            %                   Vertical distances that indicate the
            %                   location of each finger base from the
            %                   thumb's base. n is the number of fingers in
            %                   the array - 1.
            %
            %   separation  :   1 x n numerical array which contains 
            %                   horizontal distances that indicate the
            %                   location of each finger base from the
            %                   thumb's base. n is the number of fingers in
            %                   the array - 1.
            %
            %   palmstyle   :   Numerical integer that corresponds the type
            %                   of palm to be used. Defaults to 1.
            %                   (Currently only style 1 is available).
            %
            %
            %   TYPE 2 CONSTRUCTOR
            %
            %   hand=(scale,htype);
            %   scale       :
            %   htype       :
            %
            %
            %
            %
            switch nargin
                case 0
                    % initialize properties of default hand
                case 1
                    
                    if isa(varargin{1}(1),'Finger')  % flexible styles cases
                        fingers=copyArray(varargin{1});
                        metacarpal=Hand.getDefault_yOffset(fingers);
                        separation=Hand.getDefault_xOffset(fingers);
                        style=1;
                        
                        palm=Palm(fingers,metacarpal,separation,style);
                        
                        
                    elseif isa(varargin{1},'numeric')   % fixed style cases
                        scale=varargin{1};
                        htype='Prototype1';
                        
                        template=HandTemplate(htype);
                        
                        % building finger array
                        for n=1:length(template.FingersTypes);
                            fingers(n)=Finger(scale,template.FingersTypes{n},template.FingersStyle);
                        end
                        
                        % building palm object
                        palm=Palm(scale,template.PalmType,template.PalmStyle);
                    elseif isa(varargin{1},'Hand')
                        
                        
                    end
                    
                case 2
                    if isa(varargin{1}(1),'Finger')  % flexible styles cases
                        fingers=copyArray(varargin{1});
                        metacarpal=varargin{2};
                        separation=Hand.getDefault_xOffset(fingers);
                        style=1;
                        
                        palm=Palm(fingers,metacarpal,separation,style);
                        fingers=palm.FingerArray;
                        
                    elseif isa(varargin{1},'numeric')   % fixed style cases
                        scale=varargin{1};
                        htype=varargin{2};
                        
                        template=HandTemplate(htype);
                        
                        % building finger array
                        for n=1:length(template.FingersTypes);
                            fingers(n)=Finger(scale,template.FingersTypes{n},template.FingersStyle);
                        end
                        
                        % building palm object
                        palm=Palm(scale,template.PalmType,template.PalmStyle);
                    end
                    
                case 3
                    
                    fingers=copyArray(varargin{1});
                    metacarpal=varargin{2};
                    separation=varargin{3};
                    style=1;

                    palm=Palm(fingers,metacarpal,separation,style);
                    fingers=palm.FingerArray;
                case 4

                    fingers=copyArray(varargin{1});
                    metacarpal=varargin{2};
                    separation=varargin{3};
                    style=varargin{4};

                    palm=Palm(fingers,metacarpal,separation,style);
                    fingers=palm.FingerArray;
                otherwise
                    error('\n%s','wrong number of arguments')

            end
            
            
            
            
            h.Fingers=fingers;
            
            % creating listener for Update Finger event
            for n=1:length(h.Fingers);
                addlistener(h,'UpdateElements',@(src,evnt)update(h.Fingers(n)));
            end
            
            h.PalmObject=palm;
            % creating listener for palm
            addlistener(h,'UpdateElements',@(src,evnt)update(h.PalmObject));
            
            h.Nodes=palm.Nodes;
            h.Base=eye(4);
            %h.Style=style;
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.Base(h,base)
            h.Base=base;
            h.PalmObject.Frame=base;
            h.Nodes=h.PalmObject.Nodes;
            for n=1:length(h.Fingers);
                %h.Nodes(:,:,n)=base*h.PalmObject.Nodes(:,:,n);
                h.Fingers(n).BaseFrame=h.Nodes(:,:,n);
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function h=ctranspose(h)
            h.Fingers.setHandles;
            h.PalmObject.setHandles;            
            h.update;
            grid on
            drawnow
            figure(h.PalmObject.FigureHandle);
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function drive(h,inputCell,selection)
            
            h';
            
            fingerIndexes=num2cell(1:length(h.Fingers));
            d=1;
            %bool=true;
            
            while(true)
                
                for n=1:length(selection);
                    
                    
                    switch selection(n)
                        case 0
                            
                            try
                                h.Base=inputCell{n}(:,:,d);
                            catch ME
                                selection(n)=nan;
                            end

                        case fingerIndexes
                            
                            try
                                h.Fingers(selection(n)).CurrentJoints=inputCell{n}(d,:);
                            catch ME
                                selection(n)=nan;
                            end
                            
                        otherwise
                            
                            
                           
                    end                    
                end
                
                
                if all(isnan(selection))
                    break
                else
                    selection(isnan(selection))=[];
                end
                
                
                
                h.update;
                drawnow
                d=d+1;
            end       
            
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function update(h)
            %notify(h,'UpdateElements');
            h.PalmObject.update;
            for n=1:length(h.Fingers);
                h.Fingers(n).update;
            end
        end
    end
    
    methods (Static)
        function xOffset=getDefault_xOffset(fingers)
            % separating thumb from other fingers

            [t,f]=getThumb(fingers);

            % allocating space
            xOffset=zeros(1,length(f));

            % storing thumb width
            W_t=t(end).Size(3);

            % creating first xOffset element
            xOffset(1)=-W_t/2 + f(1).Size(3)/2;

            for n=2:length(f);
                xOffset(n)=xOffset(n-1) + f(n-1).Size(3)/2 + f(n).Size(3)/2 + W_t/8;
            end
        end        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function yOffset=getDefault_yOffset(fingers)
            % separating thumb from other fingers

            [t,f]=getThumb(fingers);


            % allocating space
            yOffset=zeros(1,length(f));

            for n=1:length(f);
                yOffset(n)=(-3/4)*f(n).Size(1);
            end
        end
    end
    
    
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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


        
          