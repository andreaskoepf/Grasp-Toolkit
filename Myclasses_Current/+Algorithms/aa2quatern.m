function q=aa2quatern(K,theta)
q=zeros(1,4);
q(1:3)=K(1:3)*sin(theta/2);
q(4)=cos(theta/2);
end