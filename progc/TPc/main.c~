#include <stdio.h>
#include <stdlib.h>
#include "personne.h"
#include <string.h>


int main(){
personne repertoire[10];
int i=0;

for (i=0;i<10;i++){
  scanf("%s",&repertoire[i].numero);  
	char nom[100];
	scanf("%s",&nom);
	repertoire[i].nom=malloc(sizeof(char)*strlen(nom));
	int p;
	for(p=0;p<strlen(nom);p++){
	  repertoire[i].nom[p]=nom[p];
	}

	}
for(i=0;i<10;i++){
	printf("nom: %s, numero: %s\r\n",repertoire[i].nom,repertoire[i].numero);
	free(repertoire[i].nom);

	}
return 0;
}
