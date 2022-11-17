function res= jacobi(a,b,y)
x=zeros(size(a,1),1); 

for n=1:2000
for i=1:size(a,1)
    x(i,1)=b(i,1);
    somme=0;
        for j=1:size(a,1)
            if(i~=j)
                somme=somme+(a(i,j)*y(j,1));
            end
        end
     x(i,1)=(x(i,1)-somme)/a(i,i);
end
  y=x;
end
res=x;
 
end
     


