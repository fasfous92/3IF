function [c,b]=itereet(a)
y=rand(1,size (a,1));
x=1;
while(norm((abs(x)-abs((y/norm(y)))))>0.000001)
 x=y/norm(y);
 y=x*a;
end

 [maxi,i]=max(abs(y));
 c=y(1,i)/x(1,i);
    
    

b=y;
end