% contact location
r=[0;-2;3*sqrt(3)/4];

% contact normal
n=[0;sqrt(3)/2;1/2];

% translational and torsional friction coefficients
friction=[0.2 0.2];


%% using eliptical friction cone
% contact model
contact='SFCe';

[w,patchdata]=Algorithms.FrictionConeDiscretization(n,r,contact,friction,[20 20]);

% drawing friction cone
%% using point contact with friction
contact = 'PCF';
friction = 0.2;

w=Algorithms.FrictionConeDiscretization(n,r,contact,friction,8);

%% using point contact with friction
contact = 'PCF';
friction = 0.2;

w=WrenchSpace.frictionConeDiscretization(n,r,contact,friction,8);

%%
figure(9);
patch(patchdata);
view(3),daspect([1 1 1]);
