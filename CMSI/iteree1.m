function [c,b]=iteree1(a)
y=rand(size(a,1),1);
x=rand(size(a,1),1);
while(norm((abs(x)-abs((y/norm(y)))))>0.000001)
 x=y/norm(y);
 y=a*x;
end
c=0;
for i=1:size(a,1)
    if x(i,1)~=0
    c=y(i,1)/x(i,1);
     break;
    end
   
end
b=y;
end


