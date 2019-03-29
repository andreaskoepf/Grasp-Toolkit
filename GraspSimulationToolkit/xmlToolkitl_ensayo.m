%% creating paths to java jar files in XML Toolbox

rootDirectory = ['G:\School Documents\work\RoboticHandToolbox\XMLToolbox\lib'];

javaPath{1} = [rootDirectory '\axis.jar'];
javaPath{2} = [rootDirectory '\commons-discovery.jar'];
javaPath{3} = [rootDirectory '\commons-logging.jar'];
javaPath{4} = [rootDirectory '\dom4j.jar'];
javaPath{5} = [rootDirectory '\jakarta-regexp-1.3.jar'];
javaPath{6} = [rootDirectory '\jaxrpc.jar'];
javaPath{7} = [rootDirectory '\jcert.jar'];

javaPath{8} = [rootDirectory '\jnet.jar'];
javaPath{9} = [rootDirectory '\jsr173_1.0_api.jar'];
javaPath{10} = [rootDirectory '\jsr173_1.0_ri.jar'];
javaPath{11} = [rootDirectory '\jsse.jar'];
javaPath{12} = [rootDirectory '\jug.jar'];
javaPath{13} = [rootDirectory '\saaj.jar'];
javaPath{14} = [rootDirectory '\sunjce_provider.jar'];

javaPath{15} = [rootDirectory '\wsdl4j.jar'];
javaPath{16} = [rootDirectory '\xalan.jar'];
javaPath{17} = [rootDirectory '\xercesImpl.jar'];
javaPath{18} = [rootDirectory '\xml-apis.jar'];
javaPath{19} = [rootDirectory '\xmlParserAPIs.jar'];
javaPath{20} = [rootDirectory '\xmlsec.jar'];

matlabPath = ['G:\School Documents\work\RoboticHandToolbox\XMLToolbox'];

%% adding paths
javaclasspath(javaPath);
addpath(matlabPath);

%% creating struct
testStruct = struct('field1',[],'field2',[],'field3',[],'field4',[]);
testStruct.field1 = '[4 5 6 7;2 8 9 26]';
testStruct.field2{1} = 'for_all';
testStruct.field2{2} = 'for_and';
testStruct.field3 = struct('subfield1',[],'subfield2',[]);
testStruct.field3.subfield1 = '[5 6 9 3;8 2 4 8]';
testStruct.field3(1).subfield2 = '[1 1 1]';
testStruct.field3(2).subfield2 = '[2 0 0;0 2 0;0 0 2]';
testStruct.field4 = '28';

%% creating xml string
xmlStr = xml_format(testStruct,'off','MyStruct');

%% creating structure from xml string
returnStruct = xml_parse(xmlStr,'off');

%% saving xml file
xml_save('testXML.xml',testStruct,'off');

%% opening file
fName = 'testXML3.xml';
f = fopen(fName,'w');

comment = sprintf('%s\n','<!-- Instructions go here -->');

% writing to file
fprintf(f,'%s',comment);
fprintf(f,'%s',xmlStr);

fclose(f);

%% retrieving document
xmlDoc = xml_load(fName,'off');
