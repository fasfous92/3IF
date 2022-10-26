#include <stdio.h>
#include <stdlib.h>

int Q9(FILE* flot){
    int i;
    int j;
    int count;
    fseek(flot,0,SEEK_SET);
    for(i=0;i<20;i++){
        for(j=0;j<40;j++){
           count+=fputc(95,flot);
        }           
        fseek(flot,0,SEEK_END);
        fputc(10,flot);
        fputc(13,flot);

    }
	rewind(flot);
	return count;

}
int afficher(FILE* flot){
	while(feof(flot)==0){
 	fputc(fgetc(flot),stdout);
	}
	return 0;
}


int replace(FILE* flot,char input, int offset){
	int size;
	if(!flot){
		printf("invalid stream\n");
		return 0;
	}	
	fseek(flot,0,SEEK_END);
	size=ftell(flot);
	rewind(flot);
	
	if(offset >= size || offset<0){
		printf("offset out of size!\n");
		return 0;
	}
	fseek(flot,offset,SEEK_SET);
	int buff=fputc(input,flot);
	rewind(flot);
	return buff;
}

void Q10(FILE* flot, char input){
    afficher(flot);
    int offset;
    fseek(flot,0,SEEK_END);
    int size=ftell(flot);
    rewind(flot);
    while(input !='q'){
    printf("entrer votre offset:\n");
    scanf("%d",&offset);
    replace(flot,input,offset);    
    afficher(flot);
    printf("entrer un caractere:\n");
    scanf("%c",&input);
    scanf("%c",&input);
    }
}





int main(int argc, char **argv){

FILE * fin;
FILE * fout;
fout=fopen(argv[2],"r");
fin=fopen(argv[1],"r");
char input;



Q9(fout);
afficher(fout);
printf("tapez un caractère:\n");
scanf("%c",&input);
Q10(fout,input);


fclose(fout);
//fclose(fin);


return 0;
}
