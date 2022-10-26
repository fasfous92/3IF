#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <math.h>


int pui(int n,int m){
	int r=1;
	int i;
	for(i=0;i<m;i++){
	r=r*n;
	}
return r;

}
int  octal(int indice){

	int res=0;
	int i=0;
	while(indice/8!=0){
	int modulo=indice%8;
	res+=(pui(10.0,i)*modulo);
	indice=(indice-modulo)/8;
	i++;
	}
	res+=(pui(10.0,i)*indice);
	return res;
}







int main(){
	const char * filename="colonne1.txt";
	struct stat fs;
	int r;

	r=stat(filename,&fs);
	int p=octal(fs.st_mode-S_IFREG)/100;
	switch(p){
		case 0:
			printf("owner has no permissions\n");
			break;
		case 1:
			printf("owner has permission to execute\n");
			break;
		case 2:
			printf("owner has permission to write\n");
			break;
		case 3:
			printf("owner has permission to execute and write\n");
			break;
		case 4:
			printf("owner has permission to read\n");
			break;
		case 5:
			printf("owner has permission to execute and read\n");
			break;
		case 6:
			printf("owner has permission to read and write\n");
			break;
		case 7:
			printf("owner has permission to execute, read and write\n");
			break;
	
	}
	
	
	
	
	




return 0;
}
