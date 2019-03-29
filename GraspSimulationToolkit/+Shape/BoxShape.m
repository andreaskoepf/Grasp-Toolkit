classdef BoxShape < Shape.Shape
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Box shape protected attributes
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(SetAccess = protected)
        
        mSideLengths = [1 1 1];
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % constructor
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function shape = BoxShape(varargin)
            %BoxShape
            %   shape = BoxShape
            %       creates box shape with default side lengths of [1 1 1]
            %
            %   shape =BoxShape(sideLengths)
            %       creates box shape with specified side lengths.
            %   Inputs:
            %       sideLengths: 1 x 3 double
            %
            %   Outputs
            %       shape: 1 x 1 shape object
            %
            
            switch nargin
                case 0
                    
                    sideLengths = [1 1 1];
                    
                case 1
                    
                    sideLengths = varargin{1};
                    
                otherwise
                    
                    error('too many input arguments')
                    
            end
            
            shape.loadFromModel('BoxShape');
            
            shape.setSideLengths(sideLengths);
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public set methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setSideLengths(box,sideLengths)
            
            box.setScale(sideLengths);
            box.mSideLengths = sideLengths;
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public get methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function sideLengths = getSideLengths(box)
            
            sideLengths = box.mSideLengths;
            
        end
        
    end
    
end