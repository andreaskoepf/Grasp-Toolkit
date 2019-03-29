

function CCDResultMap = findFingerTOCPosture(f,obj)
import CollisionDetection.*

% declaring result structure
resultStruct = struct('ObjectA',[],'ObjectB',[],'TOC_TransformA',[],'TOC_TransformB',...
    [],'NumContacts',0,'CollisionFlag',0,'TOC',1,'QueryTime',0,'ContactResultStruct',...
    [],'TOC_JointValues',[],'TestIndex',[]);

% % declaring finger object
% f = Finger('Prototype1_Index_3DOF');
% f.BaseFrame = Algorithms.rotation('xz',[-pi/2 -pi/2]);
% 
% f.JointValues = zeros(size(f.JointValues));

% retrieving links
l = f.Links;

% % setting joint limits
% for n = 1: size(f.Links,2)
%     jsize = size(l(n).JointLimits,1);
%     l(n).JointLimits = repmat([-pi/2 pi/2],jsize,1);
% end
% 
% % declaring object 
% obj = Box([2 2 2]);
% obj.Frame = Algorithms.translation('xz',[2.5 4]);

% creating viewing window
figure(1)
axis([-8 8 -8 8 -6 10])
f';
obj';

% creating mex instance of each link and object
%f.setPhysicsHandle;
%obj.setPhysicsHandle;

% declaring tracking variables
TestNo = int32(1);

%j_ = 1; % joint Index
%J = size(f.JointValues,1); % number of joints

%i_ = 1; % link index
I = size(f.Links,2);  % number of links

%k_ = 1; % step index
K = 10; % number of joint values to iterate through 

% storing joint Limits
jointLimits = containers.Map(0,[1 1 1]);

% populating joint limits container
for n = 1:I;
    jointLimits(n) = f.Links(n).JointLimits;
end

% creating result containter
dummyStruct = struct('field1','field2');
testResultMap = containers.Map(0,dummyStruct);
CCDResultMap = containers.Map(int32(0),testResultMap);
CCDResultMap.remove(int32(0));

% creating ccd objects
ccd(I) = ContinuousCollisionDetection;

offsetTransform = zeros(4,4,I);
for n = 1:I;
    
    ccd(n)= ContinuousCollisionDetection;
    ccd(n).createMexInstance;
    offsetTransform(:,:,n) = [eye(3) l(n).Transform(1:3,4);0 0 0 1];
    ccd(n).setObjectA(l(n),offsetTransform(:,:,n));
    ccd(n).setObjectB(obj,eye(4));
    
end

% starting recursive search
% ccdObj = ContinuousCollisionDetection;
% ccdObj.createMexInstance;

findContactPoints(1,1)  

% destroying ccd objects
for n = 1:I;
    
    ccd(n).destroyMexInstance;
    
    
end



    function collisionFlag = findContactPoints(i_,j_)
        J = size(l(i_).JointValues,1);
        
        % retrieving joint angle limits
        jointL = jointLimits(i_);
        theta0 = jointL(j_,1);
        thetaf = jointL(j_,2);
        
        jointValues =l(i_).JointValues;
        jointValues(j_) = theta0;        
        l(i_).JointValues=jointValues;
        
        f.updateAllFrames;
        objectATransform0=l(i_).Frame;
        
        % updating graphics
        %l(i_)';
        f';
        fprintf('\nStart Joint Values for link %i \n',i_)
        disp(jointValues)
        pause(1);
        
        jointValues(j_) = thetaf;        
        l(i_).JointValues=jointValues;

        f.updateAllFrames;
        objectATransformf=l(i_).Frame;
        
        % updating graphics
        %l(i_)';
        f';
        fprintf('\nEnd Joint Values for link %i \n',i_)
        disp(jointValues)
        pause(1);
        
        
        objectBTransform0 = obj.Frame;
        objectBTransformf = obj.Frame;
        
%         ccdObj.setObjectA(l(i_),offsetTransform(:,:,i_));
%         ccdObj.setObjectB(obj,eye(4));
        
        
        
        [collisionFlag,ccdResult] = ccd(i_).mexPerformCCDTest(objectATransform0,objectATransformf,...
            objectBTransform0,objectBTransformf);
        
%         [collisionFlag,ccdResult] = ccdObj.mexPerformCCDTest(objectATransform0,objectATransformf,...
%             objectBTransform0,objectBTransformf);
        
        % selecting collision test outcome
        fprintf('\nResulting collision Flag = %i\n',collisionFlag)
        
        switch collisionFlag
            
            case int32(-1) % collision found at toc = 0
                
                fprintf('\nCollision found at toc = 0 for link %i for joint %i\n',i_,j_)
                
                return;
                
            case int32(0) % collision free
                
                fprintf('\nCollision free for link %i for joint %i\n',i_,j_)
                
%                 if (i_==I && j_ == J)
%                     
%                     fprintf('\nExited routine at collision free\n')
%                     
%                    return;
%                 end

                %jointValues(j_) = theta0;
                
                l(i_).JointValues = jointValues;

                
                
            case int32(1) % TOC found
                
                fprintf('\nTOC found for link %i at TOC = %1.2f for joint %i\n',...
                    i_,ccdResult.TOC,j_);
                
                % computing theta at TOC
                theta_TOC = (thetaf - theta0)*ccdResult.TOC + theta0;
                
                % updating joint limits
                thetaf = theta_TOC;
                
                % updating joint values
                jointValues(j_)=theta_TOC;
                
                l(i_).JointValues = jointValues;
                
                f.updateAllFrames;
                %l(i_).Frame = ccdResult.TOC_TransformA;
                %obj.Frame = ccdResult.TOC_TransformB;
                
                % updating graphics
                %l(i_)';
                f';
                obj';
                pause(1);
                
            otherwise
                fprintf('\nUnknown flag was passed collsion Flag = %i \n',collisionFlag)
                
                return;
                
        end
        
        %ccdResult.ObjectA = l(i_);
        %ccdResult.ObjectB = obj;
        ccdResult.TOC_JointValues = jointValues;
        %ccdResult.TestIndex = TestNo;
        testResultMap(i_) = ccdResult;
        
        
        index = 1;
        
        % setting collision flag of next body to collision free
        collisionFlagNext = CollisionDetection.ContinuousCollisionDetection.COLLISION_FREE;
        %if i_ ~= I
        if abs(thetaf-theta0)<1e-2
            
            steps = 0;
            
        else
            
            steps = K;
            
        end
            
        for theta = linspace(thetaf,theta0,steps);

            if index == 1
                %index = index + 1;
                
                fprintf('\nEntered first iteration in Link %i joint %i\n',i_,j_)
                

            else
                
                % updating collision flag 
                %collisionFlag = ContinuousCollisionDetection.COLLISION_FREE;
                
                % create new result structure with updated joint data
                jointValues(j_) = theta;
                l(i_).JointValues = jointValues;
                f.updateAllFrames;

                resultStruct.TOC_TransformA = l(i_).Frame;
                resultStruct.TOC_TransformB = obj.Frame;
                resultStruct.TOC_JointValues = jointValues;

                % store current result structure in container map
                testResultMap(i_) = resultStruct;

            end

            % updating graphics
            f';
            pause(1);

            if j_ ~= J

                collisionFlagNext = findContactPoints(i_,j_+1);

            else

                if i_ ~= I

                    collisionFlagNext = findContactPoints(i_+1,1);

                else
                    
                    % this case is only valid when the last joint of the
                    % last link is reached.
                    
                    fprintf(['\nLast joint of the last link reached, exiting loop'...
                        '\nindex value = %i\n'],index) 
                    break;
                    
                end
                
                

            end

            % combine both collision flags
            % terminate iteration if no collision is detected by the
            % next link.
            if collisionFlagNext == CollisionDetection.ContinuousCollisionDetection.COLLISION_FREE
                
                fprintf('\nNo further collisions occur, link %i joint %i breaking loop\n',...
                    i_,j_)
                
                collisionFlag = collisionFlag||collisionFlagNext;
                
                if index == 1
                    
                    break;
                    
                else
                    
                    return;
                    
                end
                    
            end
            
            index = index + 1;

        end

        % storing result
        if (collisionFlagNext == CollisionDetection.ContinuousCollisionDetection.COLLISION_FREE && ...
                collisionFlag == CollisionDetection.ContinuousCollisionDetection.TOC_FOUND)

           % creating new result container
            structs = cell(1,I);
            indices = cell(1,I);
            for n2 = 1:I;

                structs{n2} = testResultMap(n2);
                indices{n2} = n2;
            end

            newResultMap = containers.Map(indices,structs);

            % adding new result map to result container map
            CCDResultMap(TestNo) = newResultMap;

            fprintf('\nLink %i joint %i storing data',i_,j_)
            fprintf('\nIncreasing test number by one, Current Test no = %i\n',TestNo)
            TestNo = int32(1) + TestNo;


            pause(1)
            % updating graphics
            f.updateAllFrames;
            f.update;
            obj.update;
            drawnow;

        end
                
                
            
%         else
%             
%             if j_ ~= J
%                 
%                 
%                 for theta = linspace(thetaf,theta0,K);                    
%                     
%                     if index == 1
%                         index = index + 1;
% 
%                     else
%                         % create new result structure with updated joint data
%                         jointValues(j_) = theta;
%                         l(i_).JointValues = jointValues;
%                         f.updateAllFrames;
% 
%                         resultStruct.TOC_TransformA = l(i_).Frame;
%                         resultStruct.TOC_TransformB = obj.Frame;
%                         resultStruct.TOC_JointValues = jointValues;
% 
%                         % store current result structure in container map
%                         testResultMap(i_) = resultStruct;
% 
%                     end
%                     
%                     collisionFlagNext = findContactPoints(i_,j_+1);
%                     
%                     if collisionFlagNext ~= ContinuousCollisionDetection.TOC_FOUND
%                         
%                         break;
%                     
%                     end
%                     
%                 end
%                 
%             else
%                 
%                 % creating new result container
%                 structs = cell(1,I);
%                 indices = cell(1,I);
%                 for n2 = 1:I;
%                     
%                     structs{n2} = testResultMap(n2);
%                     indices{n2} = n2;
%                 end
%                 
%                 newResultMap = containers.Map(indices,structs);
%                 
%                 % adding new result map to result container map
%                 CCDResultMap(TestNo) = newResultMap;
%                 
%                 
%                 fprintf('\nIncreasing test number by one, Current Test no = %i\n',TestNo)
%                 TestNo = int32(1) + TestNo;
%                 
%                 
%                 pause(2)
%                 % updating graphics
%                 f.updateAllFrames;
%                 f.update;
%                 obj.update;
%                 drawnow
%                 
%                 
%                 
%             end
            
        
                


    end

end
