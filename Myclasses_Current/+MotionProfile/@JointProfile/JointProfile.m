classdef JointProfile < handle
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Partially Public Properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(SetAccess = protected)
        
        NumSteps = 1
        TimeValues = 0
        TimeStep = 1
        DOF
        NumLinks
        DOFPerLink
        JointValues
        JointVelocities
        JointAccelerations
        
        JointConfigurations % array of JointConfigurations objects that 
                            % were used to generate the joint profile
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Constructor 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function jp = JointProfile(varargin)
            
            import MotionProfile.*
            
            switch nargin
                
                case 0
                    
                    return;
                    
                case 1
                    
                    if isa(varargin{1},'struct')
                        
                        jp.loadFromStruct(varargin{1})
                        return;
                        
                    end
                    
                    if isa(varargin{1},'ArticulatedBody')
                        
                        jp = JointProfile(JointConfiguration(varargin{1}));
                        return;
                        
                    end
                    
                    if ~isa(varargin{1},'MotionProfile.JointConfiguration')
                        
                        error('Input argument must be either a struct, Articulated body or JointConfiguration')
                        
                    end
                    
                case 2
                    
                    if isa(varargin{1},'JointConfiguration') && isa(varargin{2},'JointConfiguration')
                        
                        jp = JointProfile(varargin{1});
                        jp.NumSteps = 2;
                        jp.generateJointProfile(varargin{1},varargin{2});
                        return;
                        
                    else                       
                        
                        error('Both input arguments must be joint configurations')
                        
                    end
                    
                otherwise
                    
                    error('too many input arguments')
                    
            end         
            
            jointConfiguration = varargin{1}; 
            jp.JointConfigurations = jointConfiguration(1);
            jp.DOF = jointConfiguration(1).DOF;
            jp.NumLinks = jointConfiguration(1).NumLinks;
            jp.DOFPerLink = jointConfiguration(1).DOFPerLink;
            jp.JointValues = jointConfiguration(1).JointValues;
            jp.JointVelocities = zeros(jointConfiguration(1).DOF,1);
            jp.JointAccelerations = zeros(jointConfiguration(1).DOF,1);
            
            jp.generateJointProfile(jointConfiguration);
                
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public set methods 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setNumSteps(jp,steps)
            
            jp.NumSteps = steps;
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setTimeStep(jp,timeStep)
            
            jp.TimeStep = timeStep;
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public instance methods 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFromStruct(jp,inputStruct)
                        
            try
                
                fieldNames = fieldnames(inputStruct);  
                
                for n = 1:length(fieldNames);
                    
                    jp.(fieldNames{n}) = inputStruct.(fieldNames{n});
                    
                end                
                
            catch
                
                error('input structure does not have the corresponding fields')
                
            end
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function generateJointProfile(jp,varargin)
            
            if ~isa(varargin{1},'MotionProfile.JointConfiguration')
                
                error('Input argument must be a Joint Configuration')
                
            end
            
            % creating joint configuration array            
            switch nargin
                case 2
                    
                    if length(varargin{1}) > 1 
                        
                        jcArray = varargin{1};
                        
                    else
                        
                        % only one element, reset trajectory
                        jointConfiguration(1) = varargin{1};
                        jp.JointConfigurations = jointConfiguration;
                        jp.JointValues = jointConfiguration(1).JointValues;
                        jp.JointVelocities = zeros(jointConfiguration(1).DOF,1);
                        jp.JointAccelerations = zeros(jointConfiguration(1).DOF,1);
                        return
                        
                    end
                    
                case 3
                    
                    jcArray = [varargin{1} varargin{2}];
                    
                otherwise
                    
                    error('too many input arguments')
                    
            end
            
            if ~all(jp.validateJointConfiguration(jcArray))
                
                error('Joint Configuration is not valid')
                
            end
            
            jp.JointConfigurations = jcArray;
                
            % code that generates actual trajectory
            
        end
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function bool = validateJointConfiguration(jp,jc)
            
            bool = false(zeros(1,length(jc)));
            
            if isempty(jp.JointConfigurations)
                
                return;
                
            end            
            
            for n = 1:length(jc);
                
                jcObj = jc(n);
                
                bool(n) = (jp.DOF == jcObj.DOF) && (jp.NumLinks == jcObj.NumLinks);
                
               
            end
            
        end
                    
                    
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % protected instance methods 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods(Access = protected)        

        
    end
    
end
    
            
            
                        