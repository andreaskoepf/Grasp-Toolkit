function q=transform2quatern(T)
q=zeros(1,4);
q(4)=0.5*(sqrt(1+trace(T(1:3,1:3))));
q(1)=(T(3,2)-T(2,3))/(4*q(4));
q(2)=(T(1,3)-T(3,1))/(4*q(4));
q(3)=(T(2,1)-T(1,2))/(4*q(4));
end