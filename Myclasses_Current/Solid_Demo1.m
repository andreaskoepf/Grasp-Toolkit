%% creating and moving "Solid" object
s(1)=Solid('flange');
s(1).scale(50);
s(1).Position=[0 4 0]';
s(1).Quaternion=Solid.transform2quatern(Solid.rotation('x',-pi/3));

%% instantiating second "Solid" object
s(2)=Solid('Sprocket.STL');
s(2).Position=[0 -4 0]';
s(2).Quaternion=Algorithms.transform2quatern(Solid.rotation('x',-pi/3));

%% creating Box 
s(3) = Box([2 2 2]);
s(3).Position = [0 4 4]';

%% creating sphere
radius = 2.5;
s(4) = Sphere(radius);
s(4).Position = [4 3 4]';
s(4).Color = [0 1 1];

%% displaying objects on drawing panel
figure(1);
s';
grid on



