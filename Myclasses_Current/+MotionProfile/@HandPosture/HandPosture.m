classdef HandPosture < handle
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Partially Public Properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(SetAccess = protected)
        
        NumOfArticulatedBodies               
        BaseTransform 
        JointConfigurations
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Constructor 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
       
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function hp = HandPosture(varargin)
            % HandPosture
            %   Creates a hand configuration corresponding to a given hand
            %   object.

            switch nargin

                case 0

                    return;

                case 1

                    if isa(varargin{1},'struct')

                        hp.loadFromStruct(varargin{1});
                        return;

                    end

                    if ~isa(varargin{1},'Hand')

                        error('Input argument must be either a struct or Hand')

                    end

                otherwise

                    error('too many input arguments')

            end
            
            h = varargin{1};
            
            hp.NumOfArticulatedBodies = length(h.Fingers);
            hp.BaseTransform = h.Frame;
            
            jointConfigurations(hp.NumOfArticulatedBodies) = MotionProfile.JointConfiguration;
            for n = 1:hp.NumOfArticulatedBodies;
                
                jointConfigurations(n) = MotionProfile.JointConfiguration(h.Fingers(n));
                
            end
            
            hp.JointConfigurations = jointConfigurations;
            
        end
        
    end
        
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public set methods 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setJointConfigurations(hp,jcArray)
            
            if ~isa(jcArray,'MotionProfile.JointConfiguration')
                error('input argument must be a joint configuration')
            end
            
            if length(jcArray) > jp.NumOfArticulatedBodies
                
                numJointConfig = jp.NumOfArticulatedBodies;
                
            else
                
                numJointConfig = length(jcArray);
                
            end
            
            for n = 1:numJointConfig;
                
                hp.JointConfigurations(n).setJointValues(jcArray(n).JointValues);
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setBaseTransform(hp,transform)
            
            if ~all(size(transform) == [4 4])
                
                error('input argument must be a 4 x 4 double')
                
            end
            
           hp.BaseTransform = transform;
           
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public instance methods 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFromStruct(hp,inputStruct)
            
            try
                
                fieldNames = fieldnames(inputStruct);  
                
                for n = 1:length(fieldNames);
                    
                    hp.(fieldNames{n}) = inputStruct.(fieldNames{n});
                    
                end                
                
            catch
                
                error('input structure does not have the corresponding fields')
                
            end
            
        end
        
    end
    
end
    
    
            
                