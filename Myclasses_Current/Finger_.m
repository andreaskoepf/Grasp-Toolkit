classdef Finger < handle
    properties (SetAccess = private)        
        Phalanges
        Size     
        DH
        DefaultBase=eye(4);
        Type
        Style        
        
        IsOposableThumb;
    end
    
    properties
        
        OffsetJoints
        DefaultFingerTip=eye(4);
        CurrentJoints
        Base=eye(4);
        
        
    end
    
    properties (Dependent=true,SetAccess=private)
        FingerTip
    end
    
    events(NotifyAccess = protected)
        UpdateElements
    end
    
    methods
        function finger=Finger(varargin)
            
            %FINGER Create Finger Object. This class is composed of
            %        multiple Phalanx objects.
            %
            %   CONSTRUCTOR 1: Flexible styles
            %   Finger(lengths,type,style,base)
            %
            %
            %   -   lengths:
            %           Array of length values for each link in the Finger
            %           Object.  The length value are assigned in
            %           accordance to the DH parameters of the selected
            %           finger type.
            %                   
            %   -   type:   Finger type which could be either:
            %               
            %           *   index1:
            %           *   index2:
            %           *   middle:
            %           *   thumb1:
            %           *   thumb2:
            %           *   thumb3:
            %
            %           Each finger type contains a predefined kinematic
            %           definition.  When not specified this argument 
            %           defaults to index1.
            %
            %   -   style:  Integer representing the style to be used.
            %               Currently only style 1 is available.(Defaults
            %               to 1).
            %   -   base:  Base of the created Finger Object
            %
            %            %FINGER Create Finger Object. This class is composed of
            %        multiple Phalanx objects.
            %
            %   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %  
            %   CONSTRUCTOR 2: Fixed styles
            %   Phalanx(scale,type,style,base)
            %
            %
            %   -   lengths:
            %           Array of length values for each link in the Finger
            %           Object.  The length value are assigned in
            %           accordance to the DH parameters of the selected
            %           finger type.
            %                   
            %   -   type:   Finger type which could be either:
            %               
            %           *   index1:
            %           *   index2:
            %           *   middle:
            %           *   thumb1:
            %           *   thumb2:
            %           *   thumb3:
            %
            %           Each finger type contains a predefined kinematic
            %           definition.  When not specified this argument 
            %           defaults to index1.
            %
            %   -   style:  Integer representing the style to be used.
            %               Currently only style 1 is available.(Defaults
            %               to 1).
            %   -   frame:  Base of the created Finger Object
            %
            %
            
            % initializing variables
            switch nargin
                case 0
                    lengths=[5 4 3];
                    type='index1';
                    style=1;
                    ftemplate=FingerTemplate(lengths,type,style);
                    base=eye(4);

                case 1

                    if isa(varargin{1},'Finger')
                        
                        % %%%%%%%%%%%% copy property values %%%%%%%%%%%%%%%
                        
                        % copying phalanges
                        
                        % allocating space
                        phalanges(length(varargin{1}.Phalanges))=Phalanx;
                        
                        for n=1:length(varargin{1}.Phalanges);
                            
                            phalanges(n)=Phalanx(varargin{1}.Phalanges(n));
                            
                            % Creating callback
                            addlistener(finger,'UpdateElements',@(src,evnt)update(finger.Phalanges(n)));
                        end                        
                        
                        
                        finger.Phalanges=phalanges;
                        
                        % copying properties
                        propNames=fieldnames(varargin{1});
                        
                        for n=2:length(propNames)-1;
                            finger.(propNames{n})=varargin{1}.(propNames{n});
                        end
                        
                        finger.Base=varargin{1}.Base*inv(varargin{1}.DefaultBase);
                        
                        return                  
                        
                    else
                        lengths=varargin{1};
                        type='index1';
                        style=1;                        
                        ftemplate=FingerTemplate(lengths,type,style);
                        base=eye(4);
                        
                    end
                    
                case 2
                    lengths=varargin{1};
                    type=varargin{2};
                    style=1;
                    
                    ftemplate=FingerTemplate(lengths,type,style);
                    base=eye(4);
                    
                case 3
                    lengths=varargin{1};
                    type=varargin{2};
                    style=varargin{3};
                    base=eye(4);
                    ftemplate=FingerTemplate(lengths,type,style);
                case 4
                    lengths=varargin{1};
                    type=varargin{2};
                    style=varargin{3};
                    base=varargin{4};
                    ftemplate=FingerTemplate(lengths,type,style);
            end
    
            
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%             
%             
            pDetails=ftemplate.PhalanxDetails;

            if isa(style,'numeric')
                
                % allocating
                phalanges(length(pDetails))=Phalanx;
                
                for n=1:length(pDetails);
                    phalanges(n)=Phalanx(pDetails(n).Type,style,pDetails(n).Sizes...
                        ,pDetails(n).Divisions,eye(4));
                    phalanges(n).TransformFunction=pDetails(n).FunctionHandle;

                    % Creating callback
                    addlistener(finger,'UpdateElements',@(src,evnt)update(finger.Phalanges(n)));
                end
                
            elseif isa(style,'char')
                
                % allocating
                phalanges(length(pDetails))=Phalanx;
                
                for n=1:length(pDetails);
                    phalanges(n)=Phalanx(pDetails(n).Type,style,pDetails(n).Scale);
                    phalanges(n).TransformFunction=pDetails(n).FunctionHandle;
                    
                    addlistener(finger,'UpdateElements',@(src,evnt)update(finger.Phalanges(n)));
                end
                
                
                 
            end

            finger.Phalanges=phalanges;            
            finger.DefaultBase=ftemplate.DefaultBase;
            finger.OffsetJoints=zeros(1,size(ftemplate.DH,1));            
            finger.CurrentJoints=zeros(1,size(ftemplate.DH,1));
            finger.Base=base;            
            finger.Size=ftemplate.FingerSize;            
            finger.DH=ftemplate.DH;            
            finger.Type=type;
            finger.Style=style;
            finger.IsOposableThumb=ftemplate.IsOposableThumb;
            finger.DefaultFingerTip=ftemplate.DefaultFingerTip;
                                 
            
            
            
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.CurrentJoints(finger,joints)            
            finger.CurrentJoints=[joints zeros(1,size(finger.Phalanges,2)-1-...
                length(joints))];
                    
        end
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function set.Base(finger,base)
            finger.Base=base;
            finger.Phalanges(1).Frame=finger.Base*finger.DefaultBase;            
            
            
        end
        
        
        function frame=get.FingerTip(finger)
            frame=finger.Phalanges(end).Frame*finger.DefaultFingerTip;
        end
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function finger=ctranspose(finger)

            
            for n=1:length(finger);                
                finger(n).setHandles;
                finger(n).update;                
            end
            
            grid on
            drawnow            
            figure(finger(1).Phalanges(1).FigureHandle);
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setHandles(finger)
            
            for n=1:length(finger)
                finger(n).Phalanges.setHandles;
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function update(finger)
            
            T=finger.Phalanges(1).Frame;
            index=2:1:size(finger.Phalanges,2);
            
            finger.Phalanges(1).update; % updating base
            
            
            for n=index;
                T=T*finger.Phalanges(n).TransformFunction(finger.CurrentJoints(n-1)+...
                    finger.OffsetJoints(n-1));
                finger.Phalanges(n).Frame=T;
                finger.Phalanges(n).update;

            end
            
            %notify(finger,'UpdateElements');
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function drive(finger,joints)
            finger';
            for n=1:size(joints,1);
                finger.CurrentJoints=joints(n,:);
                update(finger);
                drawnow;
            end


        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function bool=isThumb(finger)

            bool=false(1,length(finger));

            for n=1:length(finger);

                if (finger(n).IsOposableThumb)
                    bool(n)=true;
                end

            end

        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function finger=setColors(finger,colors,selection)
            %this methods sets the color of all contained phalanx objects
            
            switch nargin
                case 2
                    if(length(colors)>size(finger.Phalanges,2))
                        selection=1:size(finger.Phalanges,2);
                    else
                        selection=1:length(colors);
                    end
                case 3
                    
            
                    % verifying input arguments
                    if strcmpi(selection,'all')
                        selection=1:size(finger.Phalanges,2);
                        colors=repmat(colors(1),1,length(selection));
                    end
                    
            end
                    
            
            if isa(colors,'cell')
                for n=1:length(selection);
                    finger.Phalanges(selection(n)).Color=colors{n};
                end
            else
                error('color arguments must be entered as a cell array')
            end
        end
                
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function T=getFrames(finger)
        % obtains current tranformation frame of each phalanx and fingertip
        
            % allocating spaces
            T=zeros(4,4,size(finger.Phalanges,2));
            
            T(:,:,1)=finger.Phalanges(1).Frame;
            index=2:1:size(finger.Phalanges,2);
            for n=index;
                T(:,:,n)=T(:,:,n-1)*finger.Phalanges(n).TransformFunction(finger.CurrentJoints(n-1)+...
                    finger.OffsetJoints(n-1));
                finger.Phalanges(n).Frame=T(:,:,n);

            end
            
            T(:,:,1)=[];
            T(:,:,end+1)=finger.FingerTip;
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function newfingers=copyArray(fingers)
            
            newfingers(length(fingers))=Finger(fingers(end));
            
            for n=1:length(fingers)-1;
                newfingers(n)=Finger(fingers(n));
            end
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function finger=reducePatch(finger,reduction)
            for n=1:size(finger.Phalanges,2);
                finger.Phalanges(n).reducePatch(reduction);
            end
        end
        

        
        
        
        
    end
    
    methods (Static)
        function [fingers,thumb]=getThumb(fingers)
            % verifying that thumb is provided with the finger array
            if ~any(isThumb(fingers))
                error('A thumb Type finger must be provided in the array')
            end
            
            % extracting thumb
            thumb=fingers(isThumb(fingers));
            %thumb=thumb(end);
            
            fingers=fingers(~isThumb(fingers));
        end
    end
    
end


            
                
            
            
            
            
            
        