#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {int value; struct elem* next;}elem;



elem* list = NULL;

int main(void){
  while(1) {
    printf("menu:\n");
    printf("\t1: ajouter en tete\n");
    printf("\t2: afficher la liste\n");
    printf("\t0: quitter\n");
    int choix;
    scanf("%d", &choix);
    
    switch(choix){
      
    case 0:
      goto fin;
    case 1:
      ajouter_en_tete();
      break;
    case 2:
      afficher();
      break;
    default:
      printf("choix incorrect\n");
      continue ; // revenir au menu
    }
}
  
fin:
  printf("au revoir\n");
  return 0;
}

void afficher(void){
  while(list.next!= NULL){
    printf("%d\r\n",list.value);
  }
    
    





}
