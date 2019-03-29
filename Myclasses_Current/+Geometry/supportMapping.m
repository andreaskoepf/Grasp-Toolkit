function p = supportMapping(v,P)
    % Support Mapping 
    % This programs computes the support point(s) for a given point v mapped on
    % a set P 
    %   p = SUPPORTMAPPING(v,P)
    %   inputs:
    %       v       :   n x 1 point in n - dimensional space 
    %       P       :   n x m set of m points in n - dimensional space
    %
    %   ouputs:
    %       p      :   n x 1 support point(s) in n dimensional space
    % 


    s=sum(repmat(v,1,size(P,2)).*P,1);
    y=max(s,[],2);
    index=s==y;


    p=P(:,index);

end