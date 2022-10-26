#include <stdio.h>



int main(){

int x;
int ligne;
int colonne;
int a;

scanf("%d %d %d %d",&x,&ligne,&colonne,&a); 
int i;
int j;
for(i=0;i<x;i++){ //print the ligne of X
	printf("X");
}
printf("\n"); // force the return of lines
printf("\n");

for(i=0;i<colonne;i++){ //print the ligne of #
	printf("#");
}
printf("\n"); // force the return of lines
if(ligne-2>0){
for(i=0;i<ligne-2;i++){ //print the voided regions of #
	printf("#");
	for(j=0;j<colonne-2;j++){
		printf(" ");
	}
	if(colonne-2>0)
	printf("#\n");
	else
	printf("\n");	
}
}

for(i=0;i<colonne;i++){ //print the last ligne of #
	printf("#");
	
}
printf("\n"); // force the return of lines
printf("\n");
printf("@\n");
printf("@@\n");
if(a-2>0){
for(i=2;i<a-1;i++){
	printf("@");
	for(j=0;j<i-1;j++){
		printf(" ");
	}
	printf("@\n");
}
for(i=0;i<a;i++){ //print the last  ligne of @
	printf("@");
}
printf("\n"); // force the return of lines
}


return 0;
}

