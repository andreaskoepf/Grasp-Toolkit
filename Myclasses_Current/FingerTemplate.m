classdef FingerTemplate
    properties (SetAccess=private)
        Type
        DH
        DefaultBase
        Style
        PhalanxDetails
        FingerSize
        DefaultFingerTip=eye(4);
        IsOposableThumb
    end
    
    methods
        function template=FingerTemplate(varargin)
            %FINGER TEMPLATE
            %       Create FingerTemplate object which is used in the
            %       construction of Finger objects.  This class offers two
            %       types of constructors.  This class is called from
            %       within the Finger class constructor whenever a finger
            %       object is instantiated.  After Finger instantiation no
            %       instances of the FingerTemplate object remain.
            %
            %   CONSTRUCTOR 1
            %   template=FingerTemplate(lengths,type,style)
            %
            %
            %
            %   CONSTRUCTOR 2
            %   template=FingerTemplate(scale,type,stype)
            
            
            style=varargin{3};
                       
            % --------------------------- Flexible Styles -----------------
            if isa(style,'numeric')
                
                % p -  Desired lengths of phalanxes
                % Transforming p into a row vector 
                lengths=varargin{1};
                p=varargin{1}(1,:)';
                type=varargin{2};                
                switch ['Template' num2str(style)]
                    case 'Template1'
                        switch type
                            case 'index1'
                                % 4 DOF finger
                                dh=[[0;p],[pi/2 0 0;-pi/2 0 0;zeros(size(p,1)-1,3)]];
                                Base=rotation('yz',[pi/2 -pi/2]);

                                temp=repmat({'middle'},1,length(p)-2);
                                phalanxTypes={'base' 'knuckle' 'proximalaa' temp{:} 'distal'};
                                isOposableThumb=false;
                            case 'index2'
                                % 3 DOF finger , allows motion on one plane only
                                dh=[p,zeros(size(p,1),3)];
                                Base=rotation('yz',[pi/2 -pi/2]);

                                temp=repmat({'middle'},1,length(p)-2);
                                phalanxTypes={'base' 'proximal' temp{:} 'distal'};
                                isOposableThumb=false;
                            case 'index3'
                                % 4 DOF finger
                                % AB/AD FL/EX FL/EX FL/EX FL/EX
                                dh=[[0;p],[-pi/2 0 0;zeros(size(p,1),3)]];
                                Base=rotation('z',-pi/2);

                                temp=repmat({'middle'},1,length(p)-2);
                                phalanxTypes={'baseaa' 'knuckle' 'proximal' temp{:} 'distal'};
                                isOposableThumb=false;
                            case 'thumb1'
                                % 4 DOF oposable thumb
                                % AB/AD FL/EX 45FL/EX FL/EX
                                dh=[[0;p],[pi/2 0 0;-pi/4 0 0;zeros(size(p,1)-1,3)]];
                                Base=rotation('z',-pi/2);

                                temp=repmat({'tproximal'},1,length(p)-2);
                                phalanxTypes={'tbaseaa' 'knuckle' 'tmetacarpal' temp{:} 'tdistal'};
                                isOposableThumb=true;
                            case 'thumb2'
                                % Consider revision
                                % create knuckle45
                                
                                % 4 DOF oposable thumb
                                dh=[[0;p],[pi/2 0 0;-pi/4 0 0;zeros(size(p,1)-1,3)]];
                                Base=rotation('z',-pi/2);

                                temp=repmat({'middle'},1,length(p)-2);
                                phalanxTypes={'none' 'proximal' temp{:} 'distal'};
                                isOposableThumb=true;
                            case 'thumb3'
                                % 4 DOF oposable thumb
                                % AB/AD FL/EX FL/EX FL/EX
                                dh=[[0;p],[pi/2 0 0;0 0 0;zeros(size(p,1)-1,3)]];
                                Base=rotation('z',-pi/2);

                                temp=repmat({'middle'},1,length(p)-2);
                                phalanxTypes={'baseaa' 'knuckle' 'proximal' temp{:} 'distal'};
                                isOposableThumb=true;
                            case 'thumb4'
                                % Consider revision
                                
                                % 5 DOF oposable thumb
                                % AN/RE AB/AD FL/EX FL/EX FL/EX
                                dh=[0 -pi/2 0 0;0 -pi/2 0 -pi/2;[p,zeros(size(p,1),3)]];
                                Base=rotation('yx',[pi pi/2]);

                                temp=repmat({'middle'},1,length(p)-2);
                                phalanxTypes={'none' 'none' 'proximal' temp{:} 'distal'};
                                isOposableThumb=true;
                            otherwise
                                error([type ' is not a valid finger type'])
                                
                        end
                        [dimensions,pDetails]=getPhalanxDetails(phalanxTypes,dh,lengths,style);
                        
                        
                    otherwise
                        error(['template' num2str(style) ' has not been implemented or is not defined'])
                end
                
                
                
                template.Type=type;
                template.DH=dh;
                template.DefaultBase=Base;
                template.Style=style;
                template.PhalanxDetails=pDetails;
                template.FingerSize=dimensions;
                template.IsOposableThumb=isOposableThumb;
             % ---------------------------- Fixed Styles -------------------------------   
            elseif isa(style,'char')
                
                scale=varargin{1};
                type=varargin{2};
                
                % Constructing directory path
                dirPath=Toolkit.createToolkitPath('Finger',style,type,'FingerDetails');
                %dirPath=['Finger\' style '\' type '\FingerDetails'];
                
                % loading template
                try
                    s=load(dirPath,'template');
                catch
                    error(['This combination of type and style has not been defined yet'])
                end
                
                % instantiating template
               
                %template.DH=s.template.DH;
                
                [dimensions,dh,pDetails]=getPhalanxDetails2(s.template,scale);
                
                template.Type=type;
                template.DH=dh;
                template.DefaultBase=s.template.Base;
                template.Style=style;             
                template.PhalanxDetails=pDetails;
                template.FingerSize=dimensions;
                template.IsOposableThumb=s.template.IsOposableThumb;
                template.DefaultFingerTip=s.template.DefaultFingerTip;
                
                
            else
                error(['first argument is not a valid type'])
            end
            
            
            
        end
        
        
    end   
    
    methods (Static)
        function addTemplate(ftype,style)
            
            % creating directory
            dirPath=Toolkit.createToolkitPath('Finger',style,ftype);
            %dirPath=['Finger\' style '\' ftype];
            
%             % verify if directory exist
%             if ~isdir(dirPath)
%                 
%                 % make directory if it does not exist
%                 mkdir(dirPath)
%                 
%             end
            
            template.Type=ftype;
            template.Style=style;
            
            
                        %%%%%%%%%%%%%%% Prompt user for finger specifics %%%%%%%%%
            
            fprintf('\n----------- Finger Details Specification File Creation ----------\n\n')
            fprintf(['\t\tThe following prompts will query for information which will be stored\n '...
                '\t\tand utilized in the construction of Finger objects that match the specified\n'...
                '\t\tcharacteristics.\tA total of 6 steps must be completed in order to ensure\n'...
                '\t\tsuccessful creation of the Finger definition file.  This step must be performed\n'...
                '\t\tonly after the corresponding Phalanx objects required by the specified Finger\n'...
                '\t\tobject.\t\n\n'])
            
            
            while(true)
                % prompt user for default phalans dimensions
                fprintf('\n\n\t- Step 1: Denavit-Hartenberg Parameters\n\t\t')
                fprintf('Enter D-H parameters as a n x 4 matrix [a(i) alpha(i) d(i) theta(i)]:\n\t');
                arg=input('Entry:');
                template.DH=arg;
                
                % prompt user for defaults division of the length of the phalanx
                fprintf('\n\n\t- Step 2: Phalanx Types\n\t\t')
                fprintf(['Enter phalanx types as a cell array of strings containing the type\n'...
                    '\t\t definition of each phalanx.  Start from the base (left) until the\n'...
                    '\t\t the last link (right). For example {''virtualbase'' ''proximal'' ...\n'...
                    '\t\t distal''}.\n\t']);
                arg=input('Entry:');
                
                template.PhalanxTypes=arg;
                
                % setting Base frame
                fprintf('\n\n\t- Step 3: Base Transform Frame\n\t\t')
                fprintf(['Enter a 4 x 4 transformation matrix for the finger base\n'...
                    '\t']);
                arg=input('Entry:');
                template.Base=arg;
                
                fprintf('\n\n\t- Step 4: FingerTip Transform Frame\n\t\t')
                fprintf(['Enter a 4 x 4 transformation matrix for the FingerTip\n'...
                    '\t']);
                arg=input('Entry:');
                template.DefaultFingerTip=arg;
                
                fprintf('\n\n\t- Step 5: Oposable Thumb\n\t\t')
                fprintf(['Will the current Finger object be used as an Oposable thumb?\n'...
                    '\t\t1-\tYes\n\t\t2-\tNo\n\t']);
                arg=input('Entry:');
                
                switch arg
                    case 1                        
                        template.IsOposableThumb=true;
                    case 2
                        template.IsOposableThumb=false;
                    otherwise
                        template.IsOposableThumb=false;
                end
                
                % Displaying the entries
                fprintf('\n\n\t- Step 6: Confirmation \n\t\t')
                fprintf('The following data has been entered for the configuration file\n\t\t')
                fprintf('Type:\t%s\n\t\tStyle:\t%s\n',ftype,style)
                fprintf('\n\t\t1 - Finger DH Parameters:\n')
                fprintf('\n\t\t\t%1.2f\t%1.2f\t%1.2f\t%1.2f',template.DH')
                
                fprintf('\n\n\t\t2 - Phalanx Types:\n')
                for n=1:length(template.PhalanxTypes);
                    fprintf('\n\t\t\t%s',template.PhalanxTypes{n})
                end
                
                fprintf('\n\n\t\t3 - Base Frame:\n\n')
                fprintf('\t\t\t\t%1.2f\t%1.2f\t%1.2f\t%1.2f\n',template.Base')
                
                fprintf('\n\n\t\t4 - FingerTip Frame:\n\n')
                fprintf('\t\t\t\t%1.2f\t%1.2f\t%1.2f\t%1.2f\n',template.DefaultFingerTip')
                
                fprintf('\n\n\t\t5 - Oposable Thumb:\n\n')
                if(template.IsOposableThumb)
                    fprintf('\t\t\tYes')
                else
                    fprintf('\t\t\tNo')
                end
                
                fprintf('\n\n\t\tSave Configuration file?:\n\t\t\t1 - %s\n\t\t\t2 - %s\n\t\t\t3 - %s\n\t\t','save','reenter data',...
                    'quit without saving')
                s=input('Entry: ');
                
                switch s
                    case 1
                        break;
                    case 2;
                        continue;
                    case 3
                        fprintf('\n\t\tConfiguration file was not saved\n')
                        return;
                end
                
            end
            
            
            % verify if directory exist
            if ~isdir(dirPath)
                
                % make directory if it does not exist
                mkdir(dirPath)
                
            end
            
            % saving file in the corresponding directory
            save([dirPath '\FingerDetails'],'template')
            
            fprintf(['\n\n\tCreation of Specification File Finished\n'...
                '\t---------------------------------------\n\n'])
            
            
        end
    end
    
    
    
end

function [dimensions,phalanxDetails]=getPhalanxDetails(types,dh,lengths,style)

% obtaining smallest phalanx whose size ratio will be used for all the
% elements in the finger
refL=min(lengths(1,:));

refPhalanx=types(length(types)-length(lengths(1,:))+1:end);
index=find(refL==lengths(1,:));
refPhalanx=refPhalanx(index(1)); % reference phalanx type

% constructing template of reference phalanx
template=PhalanxTemplate(refPhalanx{:},style);



% obtain reference ratio to be used for the construction of all finger
% elements
ratio=refL(1)/template.DefaultDimensions(1);
ratio=repmat(ratio,1,3);
if size(lengths,1)==2 % adjust ratio to specified widths and heigth
    ratio(2)=lengths(2,index(1))/template.DefaultDimensions(2);
elseif size(lengths,1)==3
    ratio(2)=lengths(2,index(1))/template.DefaultDimensions(2);
    ratio(3)=lengths(3,index(1))/template.DefaultDimensions(3);
end





% defining finger width and heigth
Len=sum(sum(dh(:,1)));
Hei=ratio(2)*template.DefaultDimensions(2);
Wid=ratio(3)*template.DefaultDimensions(3);

dimensions=[Len Hei Wid];

% determining size and length divisions for each element in the finger

template=PhalanxTemplate(types{1},style);
sizes=ratio.*template.DefaultDimensions;

phalanxDetails(1).Type=types{1};
phalanxDetails(1).Sizes=sizes;
phalanxDetails(1).Divisions=template.getCustomDivisions(sizes,ratio(1));
phalanxDetails(1).FunctionHandle=@(x)eye(4);

% Allocating space for phalanx Details
phalanxDetails(size(dh,1)+1)=struct('Type',[],'Sizes',[],'Divisions',[],'FunctionHandle',[]);
for n=1:size(dh,1);

    template=PhalanxTemplate(types{n+1},style);
    sizes=ratio.*template.DefaultDimensions;

    % Adjusting to lengths as specified in the DH parameters
    if ~dh(n,1)==0
        sizes(1)=dh(n,1);
    end

    phalanxDetails(n+1).Type=types{n+1};
    phalanxDetails(n+1).Sizes=sizes;
    phalanxDetails(n+1).Divisions=template.getCustomDivisions(sizes,ratio(1));
    
    % assigning homogeneous transformation matrix function ( frame )
    
    switch template.Action
        case 'revolute'
            phalanxDetails(n+1).FunctionHandle=@(x)revoluteTransform(dh(n,1),dh(n,2),dh(n,3),x+dh(n,4));
        case 'prismatic'
            phalanxDetails(n+1).FunctionHandle=@(x)prismaticTransform(dh(n,1),dh(n,2),x+dh(n,3),dn(n,4));
        case 'none'
            phalanxDetails(n+1).FunctionHandle=@(x)eye(4);
        otherwise
            phalanxDetails(n+1).FunctionHandle=@(x)eye(4);
    end
    
    

end

end

function [dimensions,dh,phalanxDetails]=getPhalanxDetails2(tfile,scale)
    
    % Rescaling the DH 
    dh=tfile.DH;
    dh(:,[1 3])=scale*dh(:,[1 3]);

    % Constucting base details
    phalanxDetails(1).Type=[tfile.Type '\' tfile.PhalanxTypes{1}];
    phalanxDetails(1).Scale=scale;
    phalanxDetails(1).FunctionHandle=eye(4);
    
    % Allocating space for phalanxDetails
    phalanxDetails(size(dh,1)+1)=struct('Type',[],'Scale',[],'FunctionHandle',[]);
    
    for n=1:size(dh,1);


        phalanxDetails(n+1).Type=[tfile.Type '\' tfile.PhalanxTypes{n+1}];
        phalanxDetails(n+1).Scale=scale;

        template=PhalanxTemplate(phalanxDetails(n+1).Type,tfile.Style);

        switch template.Action
            
            case 'revolute'
                phalanxDetails(n+1).FunctionHandle=@(x)revoluteTransform(dh(n,1),dh(n,2),dh(n,3),x+dh(n,4));
            case 'prismatic'
                phalanxDetails(n+1).FunctionHandle=@(x)prismaticTransform(dh(n,1),dh(n,2),x+dh(n,3),dn(n,4));
            case 'none'
                phalanxDetails(n+1).FunctionHandle=@(x)eye(4);
            otherwise
                phalanxDetails(n+1).FunctionHandle=@(x)eye(4);
        end

    end
    
    dimensions=[sum(abs(dh(:,1))) scale*template.DefaultDimensions(2:3)];
    
    
    
    
    
end


function T=revoluteTransform(L,alpha,D,theta)

% theta is the variable and the other arguments are constant

T=[cos(theta) -sin(theta)*cos(alpha) sin(theta)*sin(alpha) L*cos(theta)
    sin(theta) cos(theta)*cos(alpha) -cos(theta)*sin(alpha) L*sin(theta)
    0 sin(alpha) cos(alpha) D
    0 0 0 1];
end

function T=prismaticTransform(L,alpha,D,theta)

% D is the variable and the other arguments are constant

    T=[cos(theta) -sin(theta)*cos(alpha) sin(theta)*sin(alpha) L*cos(theta)
    sin(theta) cos(theta)*cos(alpha) -cos(theta)*sin(alpha) L*sin(theta)
    0 sin(alpha) cos(alpha) D
    0 0 0 1];
end


                        