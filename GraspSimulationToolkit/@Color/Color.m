classdef Color < handle
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Constant color flags
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(Constant = true)
        
        % source: http://web.njit.edu/~kevin/rgb.txt.html
        
        AQUA = [0 1 1];
        AQUAMARINE = [127 255 212]/255;
        BLACK = [0 0 0];
        BLUE = [0 0 1];
        BLUE4 = [0 0 139]/255;
        BLUE_VIOLET = [138 43 266]/255;
        BROWN = [165 42 42]/255;
        CYAN = [0 1 1];
        DARK_BROWN = [92 64 51]/255;
        DARK_GREEN = [47 79 47]/255;
        DARK_GREEN_COPPER = [74 118 110]/255;
        DARK_ORANGE = [255 140 0]/255;
        DARK_PURPLE = [135 31 120]/255;
        DARK_SALMON = [233 150 122]/255;
        DARK_SEA_GREEN3 = [155 205 155]/255
        DARK_SLATE_BLUE= [36 24 130]/255;
        DARK_SLATE_GREY = [47 79 79]/255;
        DARK_VIOLET = [148 0 211]/255;
        DARK_WOOD = [133 94 66]/255;
        DIM_GRAY = [84 84 84]/255;
        FOREST_GREEN = [34 139 105]/255;
        GRAY33 = [84 84 84]/255;
        GREEN = [0 1 0];
        GREEN_YELLOW = [173 255 47]/255;
        GOLD = [255 215 0]/255;
        LIGHT_GRAY = [211 211 211]/255;
        LIGHT_SLATE_GRAY = [119 136 153]/255;
        MAGENTA = [1 0 1];
        MAROON = [128 0 0]/255;
        MEDIUM_BLUE = [0 0 205]/255;
        MEDIUM_PURPLE = [147 112 219]/255;
        MIDNIGHT_BLUE = [0 0 156]/255;
        NAVY_BLUE = [0 0 128]/255;
        PURPLE = [160 32 240]/255;
        ORANGE = [255 165 0]/255;
        ORANGE_RED = [255 36 0]/255;
        QUARTZ = [217 217 243]/255;
        RED = [1 0 0];
        ROYAL_BLUE = [65 105 225]/255;
        ROYAL_BLUE5 = [0 34 102]/255;
        SALMON = [250 128 114]/255;
        SEA_GREEN = [46 139 87]/255;
        SIENNA = [142 107 35]/255;
        SADDLE_BROWN = [139 69 19]/255;
        SILVER = [192 192 192]/255;
        SKY_BLUE = [135 206 235]/255;
        SLATE_BLUE = [106 90 205]/255;
        SLATE_GRAY = [112 128 144]/255;
        STEEL_BLUE = [70 130 180]/255;        
        TEAL = [0 128 128]/255;
        TURQUOISE = [64 244 208]/255;
        VERY_DARK_BROWN = [92 64 51]/255;
        VIOLET = [238 130 238]/255;
        WHEAT = [216 216 191]/255;
        WHITE = [1 1 1];
        YELLOW = [1 1 0];
                
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public static methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Static = true)
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function color = validateColor(inputColor)
            
            switch class(inputColor)
                case 'char'
                    
                    color = Color.convertCharToRGB(inputColor);
                    
                case {'int32' 'uint32' 'single' 'double'}
                    
                    if any(inputColor>[1 1 1])
                        
                        color = double(inputColor)/255;
                        
                    else
                        
                        color = inputColor;
                        
                    end
                    
                otherwise
                    
                    color = Color.BLUE;
                    
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function color = convertCharToRGB(colorCharacter)
            
            switch lower(colorCharacter(1))
                case 'b'
                    
                    color = Color.BLUE;
                    
                case 'g'
                    
                    color = Color.GREEN;
                    
                case 'r'
                    
                    color = Color.RED;
                    
                case 'c'
                    
                    color = Color.CYAN;
                    
                case 'm'
                    
                    color = Color.MAGENTA;
                    
                case 'y'
                    
                    color = Color.YELLOW;
                    
                case 'k'
                    
                    color = Color.BLACK;
                    
                case 'w'
                    
                    color = Color.WHITE;
                    
                otherwise
                    
                    color = Color.BLUE;
                    
            end
            
        end
        
    end
    
end
    
    
    
    
    
    
    
        
                    
        
        
        
    