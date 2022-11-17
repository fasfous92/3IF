function [c,b]=iteree(a)
y=rand(size(a,1),1);
x=1;
while(norm((abs(x)-abs((y/norm(y)))))>0.000001)
 x=y/norm(y);
 y=a*x;
end

   [maxi,i]=max(abs(y));
    c=y(i,1)/x(i,1);
    
b=y;
end


