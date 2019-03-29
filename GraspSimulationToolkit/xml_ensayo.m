% xml ensayo
% Create a sample XML document.
docNode = com.mathworks.xml.XMLUtils.createDocument...
('root_element')
docRootNode = docNode.getDocumentElement;
for i=1:20
thisElement = docNode.createElement('child_node');
thisElement.appendChild...
(docNode.createTextNode(sprintf('%i',i)));
docRootNode.appendChild(thisElement);
end
docNode.appendChild(docNode.createComment('this is a comment'));

% Save the sample XML document.
tempname = 'testXMLDOC';
xmlFileName = [tempname,'.xml'];
xmlwrite(xmlFileName,docNode);
type(xmlFileName);