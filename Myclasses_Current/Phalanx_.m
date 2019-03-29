            %PHALANX Create Phalanx Object. This class extends the solid
            %        superclass.
            %
            %   CONSTRUCTOR 1:
            %   phalanx = Phalanx(type,style,psize,ldivision,frame)
            %       
            %   -   type:   Phalanx type which could be either:
            %               
            %           *   dof:    Degree of freedom (Doesn't display a
            %                       graphical representation)
            %           *   distal:
            %           *   middle:
            %           *   proximal:
            %           *   proximalaa:
            %           *   base:
            %           *   baseaa:
            %           *   tmetacarpal:
            %           *   tproximal:
            %           *   tdistal:
            %           *   tbase:
            %           *   tbaseaa:
            %
            %   -   style:  Integer representing the style to be used.
            %               Currently only style 1 is available.(Defaults
            %               to 1).
            %   -   psize:  Phalanx size represented by a 1 x 3 vector
            %               which contains [length height width].(Defaults
            %               to predefined value)
            %
            %   -   ldivisions:     Redistributes the phalanx segments
            %               along the phalanx length.(Defaults to
            %               predefined value)
            %   -   frame:  Reassigns phalanx frame of reference.(Defaults
            %               to eye(4))
            %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
            %   CONSTRUCTOR 2
            %   phalanx = Phalanx(type,style,scale,frame)
            %   
            %   -   type:   
            %   -   style:
            %   -   scale:
            %   -   frame:
            
            
            
classdef Phalanx < Solid
    properties (SetAccess=private)
        Type
        Style
    end

    properties
        TransformFunction
    end
    methods


        function phalanx = Phalanx(varargin)
            %PHALANX Create Phalanx Object. This class extends the solid
            %        superclass.
            %
            %   CONSTRUCTOR 1:
            %   Phalanx(type,style,psize,ldivision,frame)
            %       
            %   -   type:   Phalanx type which could be either:
            %               
            %           *   dof:    Degree of freedom (Doesn't display a
            %                       graphical representation)
            %           *   distal:
            %           *   middle:
            %           *   proximal:
            %           *   proximalaa:
            %           *   base:
            %           *   baseaa:
            %           *   tmetacarpal:
            %           *   tproximal:
            %           *   tdistal:
            %           *   tbase:
            %           *   tbaseaa:
            %               When not specified this argument defaults to
            %               dof.
            %
            %   -   style:  Integer representing the style to be used.
            %               Currently only style 1 is available.(Defaults
            %               to 1).
            %   -   psize:  Phalanx size represented by a 1 x 3 vector
            %               which contains [length height width].(Defaults
            %               to predefined value)
            %
            %   -   ldivisions:     Redistributes the phalanx segments
            %               along the phalanx length.(Defaults to
            %               predefined value)
            %   -   frame:  Reassigns phalanx frame of reference.(Defaults
            %               to eye(4))
            %
            
            

            noSkip = true;

            switch nargin
                case 0
                    type='dof';
                    style=1;
                    template=PhalanxTemplate(type,style);
                    psize=template.DefaultDimensions;
                    ldivisions=template.DefaultDivisions;
                    frame=eye(4);
                case 1
                    if isa(varargin{1},'Phalanx')

                        % skip buid process
                        noSkip=false;

                        % converting to solid
                        part=phalanx2Solid(varargin{1});
                        % copy properties
                        %psize=varargin{1}.Dimensions;
                        frame=varargin{1}.Frame;
                        style=varargin{1}.Style;
                        color=varargin{1}.Color;
                        transformFunction=varargin{1}.TransformFunction;
                        type=varargin{1}.Type;



                    else
                        type=varargin{1};
                        style=1;
                        template=PhalanxTemplate(type,style);
                        psize=template.DefaultDimensions;
                        ldivisions=template.DefaultDivisions;
                        frame=eye(4);

                    end
                case 2
                    type=varargin{1};
                    style=varargin{2};
                    template=PhalanxTemplate(type,style);
                    psize=template.DefaultDimensions;
                    if isa(style,'numeric')
                        ldivisions=template.DefaultDivisions;
                    elseif isa(style,'char')
                        scale=1;
                    
                    else
                        error('wrong argument type')
                    end
                    frame=eye(4);

                case 3
                    
                    type=varargin{1};
                    style=varargin{2};
                    
                    template=PhalanxTemplate(type,style);
                    if isa(style,'numeric')
                        psize=varargin{3};
                        ldivisions=getActualDivisions(template,psize);
                    elseif isa(style,'char')
                        scale=varargin{3};
                    else
                        error('wrong argument type')                        
                    end
                    
                    frame=eye(4);

                case 4
                    
                    type=varargin{1};
                    style=varargin{2};
                    
                    template=PhalanxTemplate(type,style);
                    if isa(style,'numeric')
                        psize=varargin{3};
                        ldivisions=varargin{4};
                        frame=eye(4);
                    elseif isa(style,'char')
                        scale=varargin{3};
                        frame=varargin{4};
                    else
                        error('wrong argument type')
                    end

                case 5
                    
                    type=varargin{1};
                    style=varargin{2};
                    
                    template=PhalanxTemplate(type,style);
                    
                    if isa(style,'numeric')
                        psize=varargin{3};
                        ldivisions=varargin{4};
                        frame=varargin{5};
                    elseif isa(style,'char')
                        error('not a valid number of arguments for Phalanx fixed styles')
                    else
                        error('wrong argument type')
                    end
            end

            % -----------------------------flexible styles-----------------
            if isnumeric(style) && noSkip

                
                part=Solid(template.FileDirectory);
                part.DefaultDimensions=template.DefaultDimensions;
                part.shift(template.AdjustmentFrame);
                part.resize(psize);
                %part.resizeSegment(ldivisions,template.getActualDivisions(psize));


                color=template.Color;
                transformFunction=eye(4);
                
                % reducing patches if required
                if template.ReductionRatio~=0;
                    part.reducePatch(template.ReductionRatio);
                end

                % ------------------------------fixed styles-------------------
            elseif ischar(style)&& noSkip 
                
                part=Solid(template.FileDirectory);
                part.DefaultDimensions=template.DefaultDimensions;
                part.shift(template.AdjustmentFrame);
                part.resize(scale*template.DefaultDimensions);
                color=template.Color;
                transformFunction=eye(4);
                
                 % reducing patches if required
                if template.ReductionRatio~=0;
                    part.reducePatch(template.ReductionRatio);
                end               


            end



            phalanx=phalanx@Solid(part);
            
            % resizing segments of phalanx if it is of a flexible type
            if isnumeric(style) && noSkip
                phalanx.resizeSegment(ldivisions,template.getActualDivisions(psize));
            end
            
            phalanx.Frame=frame;
            phalanx.Type=type;
            phalanx.Style=style;
            phalanx.Color=color;
            phalanx.TransformFunction=transformFunction;
            
            







        end

        function newphalanx=copyArray(phalanges)
            newphalanx(length(phalanges))=Phalanx;
            for n=1:length(phalanges);
                newphalanx(n)=Phalanx(phalanges(n));
            end
        end


        %         function updatePhalanx(phalanx)
        %             update(phalanx);
        %         end

        function newsolid=phalanx2Solid(phalanx)
            newsolid=toSolid(phalanx);
        end





    end
    
    methods (Access=protected)
        function p=resizeSegment(p,ndivisions,odivisions)
            %resizeSegment(solid,ndivisions,odivisions)
            %   p       :   Reference to Phalanx objects
            %   ndivisions  :   new segment lengths
            %   odivisions  :   original segment lengths
            %   This method resizes segments of the Phalanx object along the x axis
            %   while mantaining the current overall ratio of length, width
            %   and height.
            
            
            % initializing vertices matrix
            v=p.Vertices;
            
            % initializing segment bounds
            bounds=[-inf -sum(odivisions(2:end))];
            
            
            for n=1:length(ndivisions);
                indexes=(p.Vertices(1,:)>bounds(1))==(p.Vertices(1,:)<=bounds(2));
                
                % moving sector back to origin
                v(:,indexes)=Solid.translation('x',sum(odivisions)-sum(odivisions(1:n)))*v(:,indexes);
                
                % resizing sector
                v(1,indexes)=(ndivisions(n)/odivisions(n)).*v(1,indexes);
                
                % moving sector back to the location as designated by
                % ndivisions
                
                v(:,indexes)=Solid.translation('x',-sum(ndivisions)+sum(ndivisions(1:n)))*v(:,indexes);
                
                % constructing bounds for next iteration
                if ~(n==length(odivisions))
                    bounds=[bounds(2) -sum(odivisions)+sum(odivisions(1:n+1))];
                else
                    bounds=[bounds(2) inf];
                end
            end
            
            acdim=p.Dimensions;
            dfdim=p.DefaultDimensions;
            p.Vertices=v(1:3,:)';
            
            % adjusting default vertices
            p.DefaultVertices(:,1)=((dfdim(1)/acdim(1))*v(1,:))';
            p.DefaultVertices(:,2)=((dfdim(2)/acdim(2))*v(2,:))';
            p.DefaultVertices(:,3)=((dfdim(3)/acdim(3))*v(3,:))';
            
        end
    end



end


