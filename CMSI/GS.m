function res= GS(a,b,y)
x=zeros(size(a,1),1); 

for n=1:2000
for i=1:size(a,1)
    x(i,1)=b(i,1);
    somme=0;
        for j=1+i:size(a,1)
                somme=somme+(a(i,j)*y(j,1));
        end
     x(i,1)=(x(i,1)-somme);
     
     somme=0;
     if(i>1)
        for j=1:i-1
                somme=somme+(a(i,j)*x(j,1));
        end
     end
     x(i,1)=(x(i,1)-somme);
     x(i,1)=x(i,1)/a(i,i);
     
end
  y=x;
 end
res=x;
end
     

