function T=translation(axis,r)
% Creates a 4 x 4 traslation matrix along the corresponding axis in axis
% argument.
if length(axis)~=length(r)
    error('number of elements of input arguments not equal')
else
    T=eye(4);
    for n=1:length(axis);
        switch lower(axis(n))
            case 'x'
                T=T*[eye(3),[r(n) 0 0]';0 0 0 1];
            case 'y'
                T=T*[eye(3),[0 r(n) 0]';0 0 0 1];
            case 'z'
                T=T*[eye(3),[0 0 r(n)]';0 0 0 1];
            otherwise
                error('%s not a valid axis',axis(n))
        end
    end
end