%% adding path to the matlab path
addpath F:\work\Myclasses_Current

%% creating world with default ground object
world = PhysicsWorld;

%% creating object to be added to the world
h(1)=Hand('ThreeFingerHand');
h(1).Frame=Solid. translation('zx',[30 0]);
h(1).IsDynamic=false;
linkLength = 10;
linkWidth = 1;
radius = linkLength*(0.5 + sqrt(2)*0.5) - 0.5*linkWidth;
grabbedSphere=Solid('sphere');
grabbedSphere.scale(2*radius);
grabbedSphere.Mass=10;
grabbedSphere.Position=[0 0 radius]';

%% adding object to the world
world.addBody(h(1).getAllBodies);
world.addBody(grabbedSphere);
%% initializing world
world.initializeSimulation;

%% running simulation
world.startSimulation;
%% resume simulation
world.resumeSimulation;
%% stepping simulation
world.stepSimulation;
%% stopping simulation 
world.stopSimulation;

%% creating joint data
jointvar=linspace(0,pi/4,200)';
joints=[jointvar repmat(jointvar,1,2)];
%joints2=[linspace(0,-pi/12,200)' linspace(0,pi/5,200)' linspace(0,pi/8,200)' jointvar];
%jointsThumb=[linspace(0,pi/9,200)' linspace(0,pi/10,200)' linspace(0,pi/6,200)' jointvar];

%% animating hand descending
for n=linspace(32,2*radius+1,100);
    h(1).Frame=Solid. translation('zx',[n 0]);
    h(1).updateToPhysics;
end

%% animating fingers in external simulator
for n=1:size(joints,1);
    h(1).Fingers(1).JointValues=joints(n,:)';
    h(1).Fingers(2).JointValues=joints(n,:)';
    h(1).Fingers(3).JointValues=joints(n,:)';    
    %h(1).Fingers(5).JointValues=jointsThumb(n,:)';
    %h(1).Fingers(4).JointValues=joints(n,:)';
    h(1).updateToPhysics;
end


%% zero out joint Values
h(1).Fingers(1).JointValues=zeros(h(1).Fingers(1).DOF,1);
h(1).Fingers(2).JointValues=zeros(h(1).Fingers(2).DOF,1);
h(1).Fingers(3).JointValues=zeros(h(1).Fingers(3).DOF,1);    
%h(1).Fingers(5).JointValues=zeros(h(1).Fingers(5).DOF,1);
%h(1).Fingers(4).JointValues=zeros(h(1).Fingers(4).DOF,1);
h(1).updateToPhysics;
%% changing Base
h(1).Frame=Solid. translation('zx',[32 0]);
h(1).updateToPhysics;

%% computing analytical results
contactData = struct('ContactPoints',[],'ContactNormals',[]);

% parameters
objectPos = [0;0;radius];
angle = linspace(0,4*pi/3,3);

p = ones(4,3);

% creating contact points in world coordinates
for n = 1:3;
    p(1:3,1) = [radius*sqrt(2)*0.5;0;radius+radius*sqrt(2)*0.5];
    p(1:3,2) = [radius;0;radius];
    p(1:3,3) = [radius*sqrt(2)*0.5;0;radius-radius*sqrt(2)*0.5];
    
    p = Algorithms.rotation('z',angle(n))*p;
    
    
    contactData(n).ContactPoints(1).LinkData = p(1:3,1);
    contactData(n).ContactPoints(2).LinkData = p(1:3,2);
    contactData(n).ContactPoints(3).LinkData = p(1:3,3);
    
    contactData(n).ContactNormals(1).LinkData = (objectPos - contactData(n).ContactPoints(1).LinkData)/norm(objectPos - contactData(n).ContactPoints(1).LinkData);
    contactData(n).ContactNormals(2).LinkData = (objectPos - contactData(n).ContactPoints(2).LinkData)/norm(objectPos - contactData(n).ContactPoints(2).LinkData);
    contactData(n).ContactNormals(3).LinkData = (objectPos - contactData(n).ContactPoints(3).LinkData)/norm(objectPos - contactData(n).ContactPoints(3).LinkData);
    
end

%% collecting collision data from simulation 
simContactData = struct('ContactPoints',[],'ContactNormals',[],'InterpenetrationDepth',[]);
for n = 1:length(h.Fingers);
    
    f = h.Fingers(n);
    for m = 1:length(f.Links);
        % performing collision test
        l = f.Links(m);
        
        [bool,collisionResult] = l.collisionPairTest(grabbedSphere);
        
        % retrieving link
        numContacts = length(collisionResult);
        contactPoints = zeros(3,numContacts);
        contactNormals = zeros(3,numContacts);
        penetrationDepth = zeros(1,numContacts);
        
        for p = 1:numContacts;
            
            contactPoints(:,p) = collisionResult(p).ContactPointWorldOnB;
            contactNormals(:,p) = collisionResult(p).ContactNormalWorldOnB;
            penetrationDepth(1,p) = collisionResult(p).InterpenetrationDistance;
            
        end
        
        simContactData(n).ContactPoints(m).LinkData = contactPoints;
        simContactData(n).ContactNormals(m).LinkData= contactNormals;
        simContactData(n).InterpenetrationDepth(m).LinkData = penetrationDepth;
        
    end
    
end

%% writing data to files
for  n = 1:length(h.Fingers);
    
    fileName = ['CollisionValidationTest_Finger' num2str(n) '_results.txt'];
    
    fId = fopen(fileName,'w');    
    
    % printing header
    fprintf(fId,'Collision Test Results\nHand Model:\t%s\nFinger Model:\t%s\n',...
        h.ModelName,h.Fingers(n).ModelName);
    
    fprintf(fId,'Finger Index:\t%i\nObject Model:\t%s\n\n',n,grabbedSphere.ModelName);
    
    f = h.Fingers(n);
    
    for m = 1:length(f.Links);
        fprintf(fId,'----------------------------------------------------\n');
        fprintf(fId,'Link %i vs Object Results\nContact Points\n',m);
        
        numDataPoints = length(simContactData(n).ContactPoints(m).LinkData)+1;
        formatStr = repmat('%8.3f',1,numDataPoints);
        
        fprintf(fId,sprintf(['    Theo' repmat('     Exp',1,numDataPoints-1) '\n']))
        
        data = [contactData(n).ContactPoints(m).LinkData, ...
            simContactData(n).ContactPoints(m).LinkData];
        
        fprintf(fId,[formatStr '\n'],data');
        
        fprintf(fId,'\nContact Normals\n');
        
        fprintf(fId,sprintf(['    Theo' repmat('     Exp',1,numDataPoints-1) '\n']))
        
        data(:,:) = [contactData(n).ContactNormals(m).LinkData, ...
            simContactData(n).ContactNormals(m).LinkData];
        
        fprintf(fId,[formatStr '\n'],data');
        
    end
    
    fclose(fId);
    
end
    
    
%% pause simulation
world.pauseSimulation;
%% resume simulation
world.resumeSimulation;
%% stopping simulation 
world.stopSimulation;

%% closing simulation
clear world
