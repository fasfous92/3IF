#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {int value; struct  _elem* next;} elem;

void afficher(void);
void ajouter_en_tete(void);
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
    printf("%p****\r\n",list);
    printf("%pµµµ\r\n",(*list).next);
    elem* current=list;
    printf("****%p\r\n",current);
    printf("µµµ%p\r\n",(*current).next);
    int i=0;
    while(i<3){
       printf("the print is: %d\r\n",(*current).value);
       current=(elem*)(*list).next;
       printf("****%p\r\n",current);
	i++;
  }
}

void ajouter_en_tete(void){
    elem* t;
    t=malloc(sizeof(elem));
    printf("entrer valeur\n");
    scanf("%d",&((*t).value));
    //printf("%d", ((*t).value));
    printf("%p\r\n",t);
    printf("1%p****\r\n",list);    
    (*t).next=(elem*)list;
    list=t;
    
   
    
  printf("%p****\r\n",list);
  printf("****%p\r\n",(*list).next);
    
    //printf("%p****\r\n",list);

    
    //free(t);
}













