clear ; 
close all ; 
X = zeros (20, 50) ; 

for i = 1 : 50 
    X(1,i) = 300 ; 
    X(20 , i) = 300 ; 
end
for i = 5 : 13 
    X(i ,8) = 100 ; 
    X(i, 9) = 100 ; 
end
for i = 1 : 10
    X(i,1) = 300 ; 
    X(i+10 , 50) = 300 ; 
end
for i = 7 : 9
    for j = 40 : 42
        X(i , j) = 500 ; 
    end
end
x2 = zeros (1000 , 1) ; 
for i = 1: 50
    for j = 1 :20 
        x2((i-1)*20 +j ) = X(j , i) ;
    end
end
A = zeros (1000) ;
B = zeros (1000 , 1) ; 
for i = 1 : 1000
    if i<=11 |  mod(i,20)==1 | mod(i,20)==0 | i>=990
		A(i,i)=1;
		B(i)= 1;
	elseif (145<=i  & i<=153) | (165<=i & i<=173)
		A(i,i)=1;
		B(i) = 1;
	elseif (807<=i  & i<=809) | (827<=i & i<=829) | (847<=i & i<=849) 
		A(i,i)=1;
		B(i)= 1;
	else
		if i<=20
			A(i,i)=-4;
			A(i,970+i)=1;
			A(i,i+20)=1;
			A(i,i+1)=1;
			A(i,i-1)=1;
		elseif i>=980
			A(i,i)=-4;
			A(i,i-20)=1;
			A(i,i-970)=1;
			A(i,i+1)=1;
			A(i,i-1)=1;
		else
			A(i,i)=-4;
			A(i,i-20)=1;
			A(i,i+20)=1;
			A(i,i+1)=1;
			A(i,i-1)=1;
		end
    end


end

   