#include <stdio.h>


void bouger(int n,int (*t)[n],int i, int j, int* res);

int main(){
int n;
scanf("%d", &n);
int arrGrid[100][100];
char temp;
int (*p)[n];
p=arrGrid;
int* res;
int nPosI=0;
int nPosJ=0;
int c=0;
res=&c;
for (nPosI = 0; nPosI < n; nPosI++) {
	for (nPosJ = 0; nPosJ < n; nPosJ++) {
		scanf("%d%c", &arrGrid[nPosI][nPosJ], &temp);
		*(*(p+nPosI)+nPosJ)=arrGrid[nPosI][nPosJ];

	}
}
bouger(n,p,0,0,res);
printf("%d\r\n",c);

return 0;
}


void bouger(int n,int (*t)[n],int i,int j, int* res){	
	
	if(i==n-1 && j==n-1){
		(*res) ++;	
	} else {
		if ((*(*(t+i)+j+1))==0 && j+1<n){
		bouger(n,t,i,j+1,res);	
		}
		
		if ((*(*(t+i+1)+j))==0 && i+1<n){
		bouger(n,t,i+1,j,res);
		
		}
	}
}

