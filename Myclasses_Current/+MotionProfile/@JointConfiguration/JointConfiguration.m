classdef JointConfiguration < handle
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Partially Public Properties
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties(SetAccess = protected)
        
        DOF
        NumLinks
        DOFPerLink
        JointValues
        
    end    
        
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Constructor 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function jc = JointConfiguration(varargin)
            % JointConfiguration
            %   Contains a particular joint configuration corresponding to
            %   a given articulated body.  It uses the specifics of a
            %   particular articulated body to verify the input joint data
            %   before it can be used on the articulated body.  Only the
            %   joint data property can be modified after the joint
            %   configuration is created
            
            switch nargin
                
                case 0
                    
                    return;
                    
                case 1
                    
                    if isa(varargin{1},'struct')
                    
                        jc.loadFromStruct(varargin{1})
                        return;
                    
                    end
                    
                    if isa(varargin{1},'MotionProfile.JointConfiguration')
                        
                        jc.loadFromStruct(struct(varargin{1}))
                        
                    end                    
                    
                    if ~isa(varargin{1},'ArticulatedBody')
                        
                        error('Input argument must be either a struct or ArticulatedBody')
                        
                    end
                            
                            
                    
                otherwise
                    
                    error('too many input arguments');
                    
            end
            
            articulatedBody = varargin{1};
            
            jc.DOF= articulatedBody.DOF;
            jc.NumLinks = length(articulatedBody.Links);
            
            jc.DOFPerLink = zeros(1,jc.NumLinks);
            
            for n = 1:length(articulatedBody.Links);
                
                jc.DOFPerLink(n) = articulatedBody.Links(n).DOF;
                
            end
            
            jc.JointValues = articulatedBody.JointValues;
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public set methods 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function setJointValues(jc,jointValues)
            
            if all(size(jointValues) == [jc.DOF 1])
                
                jc.JointValues = jointValues;
                
            else
            
                numInputJoints = length(jointValues);
                jointValues = reshape(jointValues,numInputJoints,1);

                if numInputJoints < jc.DOF

                    jc.JointValues = [jointValues;zeros(jc.DOF - numInputJoints,1)];

                elseif numInputJoints > jc.DOF

                    jc.JointValues = jointValues(1:jc.DOF);

                else                

                    jc.JointValues = jointValues;

                end
                
            end
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public get methods 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function out = getJointValues(jc)
            
            out = jc.JointValues;
            
        end
        
    end
        
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % public instance methods 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function loadFromStruct(jc,inputStruct)
            
            try
                
                fieldNames = fieldnames(inputStruct);  
                
                for n = 1:length(fieldNames);
                    
                    jc.(fieldNames{n}) = inputStruct.(fieldNames{n});
                    
                end                
                
            catch
                
                error('input structure does not have the corresponding fields')
                
            end
            
        end
        
    end
    
end
                
    