function [res,y]=Tambour(a)
c=inv(a);

[l,v]=iteree(a);
[l,u]=itereet(a);
x=zeros(105,1);
x(1,1)=l;
y=zeros(size(a,1),105);
y(:,1)=v;

for i=2:25
    a=a-l*((v*u)/(u*v));
    [l,v]=iteree(a);
    [l,u]=itereet(a);
    x(i,1)=l;
    y(:,i)=v;
    
end

[l,v]=iteree(c);
[l,u]=itereet(c);
x(26,1)=1/l;
y(:,26)=v;

for i=27:105
    
    c=c-l*((v*u)/(u*v));
    [l,v]=iteree(c);
    [l,u]=itereet(c);
    x(i,1)=1/l;
    y(:,i)=v;
    
end
res=x;
end