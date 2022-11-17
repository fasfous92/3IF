function res=Deflation(a)
[l,v]=iteree(a);
[l,u]=itereet(a);
x=zeros(size(a,1),1);
x(1,1)=l;

for i=2:size(a,1)
    a=a-l*((v*u)/(u*v));
    [l,v]=iteree(a);
    [l,u]=itereet(a);
    x(i,1)=l;
    
    
end
res=x;
end


