#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NB_FILES 4
#define FILE_1 "colonne1.txt"
#define FILE_2 "colonne2.txt"
#define FILE_3 "colonne3.txt"
#define FILE_4 "colonne4.txt"

#define BUFFER_SIZE 256

void liberer(char** src,int size);
char** resize(char** lines,int old, int new);

void liberer(char** src, int size){
	int i;
	for(i=0;i<size;i++){
		free(src[i]);	
	}
}

char** resize(char** lines,int old, int new){
	char** buff=malloc(sizeof(char*)*new);
	int i=0;
	for(i=0;i<old;i++){
		buff[i]=lines[i];
	}
	free(lines);
	return buff;

}

int main (void){
	char* files[NB_FILES];
	files[0] = FILE_1;
	files[1] = FILE_2;
	files[2] = FILE_3;
	files[3] = FILE_4;
	
	FILE* stream;
	int rnd;
	int max_lines = 4;
	int current_lines = 0;
	char buffer[BUFFER_SIZE];
	char** lines;

	srandom(time(NULL));
	
	for (int i=0; i<NB_FILES; i++)
	{
		
		lines = malloc(max_lines * sizeof(char*));
		stream = fopen(files[i], "r");
	while(!feof(stream)){
		fgets(buffer,BUFFER_SIZE,stream);
		lines[current_lines]=malloc(BUFFER_SIZE*sizeof(char));
		strcpy(lines[current_lines],buffer);
		current_lines++;
		if(current_lines==max_lines){
			lines=resize(lines,max_lines,max_lines*2);
			max_lines*=2;
		}
		
		
	}
	
	rnd=random()%current_lines;	
	printf("%s",lines[rnd]);
	
	liberer(lines,current_lines);
	free(lines);
	max_lines=4;
	current_lines=0;

	fclose(stream);
	}

return 0;
}
		
	








