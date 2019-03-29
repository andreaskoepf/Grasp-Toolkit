classdef CollisionPairResult < handle
    % CollisionPairResult
    %   Creates a Collision Pair Result Object that contains the
    %   resulting data for a collision test between a pair of
    %   objects A and B.  The accessible properties of this object
    %   are:            
    %       - ObjectA
    %       - ObjectB
    %       - TOC
    %       - TOC_TransformA
    %       - TOC_TransformB
    %       - TOC_JointValues
    %       - CollisionFlag
    %       - NumContacts
    %       - ContactPoints
    %       - QueryTime
    %       - TestIndex
    %
    %   cr = CollisionPairResult(inputStruct)
    %   Inputs:
    %       inputStruct : 1 x 1 structure containing the same
    %       fields as the collision pair result object.
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Partially Public Properties 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    properties%(SetAccess = protected)
        
        ObjectA
        ObjectB
        TOC
        TOC_TransformA
        TOC_TransformB
        TOC_JointValues % used when testing an articulated body
        CollisionFlag = CollisionDetection.ContinuousCollisionDetection.COLLISION_FREE
        NumContacts = 0;
        ContactPoints = [];
        QueryTime = 0;
        TestIndex = 0;
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Constructor 
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
        
        % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function cr = CollisionPairResult(varargin)
            % CollisionPairResult
            %   Creates a Collision Pair Result Object that contains the
            %   resulting data for a collision test between a pair of
            %   objects A and B.  The accessible properties of this object
            %   are:            
            %       - ObjectA
            %       - ObjectB
            %       - TOC
            %       - TOC_TransformA
            %       - TOC_TransformB
            %       - TOC_JointValues
            %       - CollisionFlag
            %       - NumContacts
            %       - ContactPoints
            %       - QueryTime
            %       - TestIndex
            %
            %   cr = CollisionPairResult(inputStruct)
            %   Inputs:
            %       inputStruct : 1 x 1 structure containing the same
            %       fields as the collision pair result object.
            
            
            
            import CollisionDetection.*
            switch nargin
                case 0
                    
                    return
                    
                case 1
                    
                    if ~isa(varargin{1},'struct')
                        
                        error('must provide a 1 x 1  structure array')
                        
                    end
                    
                otherwise
                    
                    error('too many input arguments')
                    
            end
            
            
            try
                
                fieldNames = fieldnames(varargin{1});  
                
                % eliminating the "ContactPoints" field since this has to
                % be treated differently
                fieldNames(strcmpi('ContactPoints',fieldNames)) = [];
                
                inputStruct = varargin{1};
                for n = 1:length(fieldNames);                    
                    
                    cr.(fieldNames{n}) = inputStruct.(fieldNames{n});
                    
                end
                
                if inputStruct.('NumContacts') ~= 0
                    
                    cpArray = ContactPoint.filterContactPoints(inputStruct.('ContactPoints'));                    
                    cr.ContactPoints = cpArray;
                    cr.NumContacts = length(cpArray);
                    
                end
                
            catch
                
                error('input structure does not have the corresponding fields')
                
            end
            
        end
        
    end
    
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Wrench Space related methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    methods
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function ws = createWrenchSet(cr,resolution)
            
            if nargin == 1
                
                resolution  = 8;
                
            end
            
            
            % counting total number of wrench sets
            numWrenchSets = cr.NumContacts;
            
            ws(numWrenchSets) = WrenchSpace.WrenchSet;
            
            index = 1;
            numContactPoints = cr.NumContacts;
            
            for m = 1:numContactPoints;
                
                ws(index) = WrenchSpace.WrenchSet(cr.ContactPoints(m),resolution);
                index = index+1;
                
            end
   
            
        end
        
    end
    
end
                
    