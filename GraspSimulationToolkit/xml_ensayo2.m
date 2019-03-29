%% creating dom object that contains and manages xml data

xmlDocument = com.mathworks.xml.XMLUtils.createDocument('testMeshModelDocument');

%% retrieving document root
xmlRoot = xmlDocument.getDocumentElement;

% creating data and tags
xmlDataModelMap = containers.Map;

% inserting elements into data container map
xmlDataModelMap('modelName') ='''meshmodel28''';
xmlDataModelMap('modelColor') =' [0.2 0.1 0.8]';
xmlDataModelMap('modelLocalTransform') = 'eye(4)';

% obtaining data container map keys
keys = xmlDataModelMap.keys;

% storing data into xml document object
for n = 1:xmlDataModelMap.length;
    
    element  = xmlDocument.createElement(keys{n});
    element.appendChild(xmlDocument.createTextNode(xmlDataModelMap(keys{n})));
    %element.setAttribute(xmlDocument.createAttribute('char'));
    
    xmlRoot.appendChild(element);
    
end

%% saving the document
xmlFileName = 'testMeshModelDocument.xml';
xmlwrite(xmlFileName,xmlDocument);
    
