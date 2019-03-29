import GST.BaseClasses.*
addpath 'G:\School Documents\work\Myclasses_Current'

%% creating node objects
node = Node;
node2 = Node;
node3 = Node;

%% attaching nodes
node.addChildNode(node2);
node2.addChildNode(node3);

%% setting parent node position
node.setTransform(Algorithms.translation('x',5),0);
node2.setTransform(Algorithms.rotation('x',pi/3),1);
node3.setTransform(Algorithms.translation('x',3)*Algorithms.rotation('x',pi/4),0);

%% setting child node position in world
node3.setPosition([4 6 2]',0);

%% setting child node orientation in world
t = Algorithms.rotation('x',pi/3);


node3.setOrientation(t(1:3,1:3),0);
