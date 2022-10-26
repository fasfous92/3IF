#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void afficher(char* flot){
	int i;
	for(i=0;i<strlen(flot);i++){
 	printf("%c",*(flot+i));
	}
	
}
int afficherf(FILE* flot){
	while(feof(flot)==0){
 	fputc(fgetc(flot),stdout);
	}
	return 0;
}


int replace(char* flot,char input, int offset){
	int size=strlen(flot);
	if(!flot){
		printf("invalid stream\n");
		return 0;
	}	
	
	if(offset >= size || offset<0){
		printf("offset out of size!\n");
		return 0;
	}

	*(flot+offset)=input;
	
	return 0;
}

void Q10(char* flot, char input){
    afficher(flot);
    int offset;
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

char* Q12(FILE* flot){
	char* buff;
	int i;
	for(i=0;i<strlen(buff);i++){
 	*(buff+i)=fgetc(flot);
	i++;
	}
	return buff;
}





int main(int argc, char **argv){


FILE * fout;
fout=fopen(argv[1],"w+");
int i;
char input;



Q9(fout);
afficherf(fout);
char* buff=Q12(fout);
for(i=0;i<strlen(buff);i++){
 	printf("%c",*(buff+i));
 	i++;
}
printf("tapez un caractère:\n");
scanf("%c",&input);
Q10(buff,input);

for(i=0;i<strlen(buff);i++){
 	fputc(*(buff+i),fout);
 	i++;
}
fclose(fout);
free(buff);




return 0;
}
