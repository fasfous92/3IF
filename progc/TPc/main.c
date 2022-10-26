#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {int value; struct  _elem* next;} elem;

void afficher(void);
void ajouter_en_tete(void);
elem* list = NULL;
void rechercher(void);
void ajouter_en_queue(void);
void supprimer(void);
void dupliquer(void);
void est_triee(void);
void ajouter_en_place(void);




int main(void){
  while(1) {
    printf("menu:\n");
    printf("\t1: ajouter en tete\n");
    printf("\t4: ajouter en queue\n");    
    printf("\t2: afficher la liste\n");
    printf("\t3: chercher un element\n");
    printf("\t5: supprimer un element\n");    
    printf("\t6: dupliquer un element\n");    
    printf("\t7: verifier si liste triee\n");
    printf("\t8: ajouter en place\n"); 
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
    case 3:
    	rechercher();
    	break;
    case 4:
    	ajouter_en_queue();
    	break;
    case 5:
    	supprimer();
    	break;
    case 6:
    	dupliquer();
    	break;
    case 7:
    	est_triee();
    	break;
    case 8:
    	ajouter_en_place();
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
    
    elem* current=list;
    if(current==NULL){
    	printf("liste vide");
    	}
   
    while(current != NULL){
       printf("%d\r\n",(*current).value);
       current=(*current).next;
  }
}
void supprimer(void){
	int n;
	printf("entrer une valeur:\n");
	scanf("%d",&n);
	elem *sup=NULL;
	
if(list!=NULL){

	if((*list).next==n){
		sup=list;
		list=(*list).next;
		free(sup);
	} else {
	
	elem* current=list;
	elem* previous=list;
	
	while((*current).next!=NULL){
		if((*current).value==n){
		sup=current;
		(*previous).next=((*current).next);
		free(sup);			
		}
		previous=current;
		current=(*current).next;		
	}
	if((*current).value==n){
		sup=current;
		free(sup);
		(*previous).next=NULL;
	}
		}
}else {
	printf("liste vide\n0");
  	
 }
}


void ajouter_en_place(void){
	printf("entrer une valuer\n");
	int n;
	scanf("%d",&n);
	elem* current=list;
	elem* suivant=list;
	
	
	
	while(current=NULL){
		suivant=(*current).next;
		if(suivant==NULL){
			printf("veuillez retaper la valeur");
			ajouter_en_queue();
			break;
		}
		if((*suivant).value>n){
		elem* t=malloc(sizeof(elem));
		(*t).value=n;
		(*t).next=suivant;
		(*current).next=t;
		break;
		}
		current=(*current).next;
	}
}

void est_triee(void){
	int i=0;
	elem* current=list;
	elem* suivant=list;
	while((*current).next!=NULL){
		suivant=(*current).next;
		if((*current).value>(*suivant).value){
			i=1;
			break;
		}	
		current=(*current).next;
	}
	
	if(i==0){
	
	printf("oui\n");
	} else if(i==1){
	printf("non\n");
	}
}



void dupliquer(void){
	printf("entrer une valeur\n");
	int n;
	scanf("%d",&n);
	elem * current=list;
	
	while(current!=NULL){
		if((*current).value==n){
			elem* t=malloc(sizeof(elem));
			(*t).value=n;
			(*t).next=(*current).next;
			(*current).next=t;
			current=(*t).next;
		}
		current=(*current).next;
	
	}
}
void ajouter_en_queue(void){
	int n;
	elem *current=list;
	elem *ajout=malloc(sizeof(elem));
	printf("entrer une valeur:\n");
	scanf("%d",&n);
	
	while((*current).next!=NULL){
		current=(*current).next;
	}	
	(*ajout).next=NULL;
	(*ajout).value=n;
	(*current).next=ajout;




}
void ajouter_en_tete(void){
	printf("entrer valeur\n");
	int n;
	elem* t=malloc(sizeof(elem));
        scanf("%d",&n);
    	(*t).next=list;
    	(*t).value=n;
    	list=t;
     	 
}

void rechercher(void){
	int n;
	int out=0;
	elem * t=list;
	printf("entrer une valeur\n");
	scanf("%d",&n);
	
	while((*t).value !=n){
		t=(*t).next;
		out++;
	}
	
	if(out!=0){
	printf("position de %d: %d\n",n,out);
	} else {
	printf("pas trouvé");
	}
}













