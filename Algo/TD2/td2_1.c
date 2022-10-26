#include <stdio.h>

int rand(void);

int main(void){

int A;
int B;
int x=0;
int y=0;

scanf("%d %d",&A, &B);

printf("%d %d ", A,B);

int eq1=(x+y)*(A-(x*y));
int eq2=(x*x*x)+(y*y*y);

while(eq1!=B){
    x= rand();
    y=rand();
}

printf("%d _%d\r\n", x,y);



	



return 0;
}
