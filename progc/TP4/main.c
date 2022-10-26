#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _elem {
    int value;
    struct _elem* next;
} elem;

typedef struct _treenode{
    int value;
    struct _treenode* left;
    struct _treenode* right;
} treenode;

elem* list = NULL;

void afficher(){
    elem* current=list;
    while((void*)current!=NULL){
        printf("%d\n ",(*current).value);
        current=(*current).next;
    }

}

void ajouter_en_queue(){
    int n;
    scanf("%d",&n);
    elem* t=malloc(sizeof(elem));
    (*t).next=NULL;
    (*t).value=n;
    elem* current=list;
    while((void*)current->next!=NULL){
        current=(*current).next;
    }
    (*current).next=t;
}

void ajouter_en_tete(){
    int n;
    scanf("%d",&n);
    elem* t=malloc(sizeof(elem));
    (*t).next=list;
    (*t).value=n;
    list=t;
}

void supprimer(){
    int n;
    scanf("%d",&n);
    elem* current=list;
    int nb=0;
    elem* pere;
    
    while((void*)current!=NULL){
        if(nb==1){
            pere=list;
        }
        if(current->value==n && nb>=1){
            elem* supp=current->next;
            pere->next=current->next;
            current=supp;
            //pere=(*pere).next;
            nb++;
            continue;
        }
        if(current->value==n && nb==0){
            list=list->next;
        }
        if(current->next->value==n && current->next->next==NULL){
            current->next=NULL;
        }
        current=(*current).next;
        pere=(*pere).next;
        nb++;
    }
}

void dupliquer(){
    int n;
    scanf("%d",&n);
    elem* current=list;
    
    while((void*)current!=NULL){
        if(current->value==n){
            elem *t=malloc(sizeof(elem));
            t->value=n;
            t->next=current->next;
            current->next=t;
            current=(*current).next;
        }
        current=(*current).next;
    }
}

void est_triee(){
    int n=1;
    elem* current=list;
    
    while((void*)current->next!=NULL){
        if(current->value>current->next->value){
            n=0;
            break;
        }
        current=(*current).next;
    }

    if(n==1){
        printf("triée\n");
    }else{
        printf("pas triée\n");
    }
}

void ajouter_en_place(){
    int n;
    scanf("%d",&n);
    elem* current=list;
    
    if(n<list->value){
        elem* t=malloc(sizeof(elem));
        (*t).next=list;
        (*t).value=n;
        list=t;
    }else{
        while((void*)current!=NULL){
            if(current->next==NULL && n>current->value){
                elem *t=malloc(sizeof(elem));
                t->value=n;
                t->next=current->next;
                current->next=t;
                break;
            }else if(current->next->value>n){
                elem *t=malloc(sizeof(elem));
                t->value=n;
                t->next=current->next;
                current->next=t;
                break;
            }
            current=(*current).next;
        }
    }
    
}

void rechercher(){
    int n;
    printf("élément à chercher : ");
    scanf("%d",&n);
    elem* current=list;
    int pos=1;
    while((void*)current!=NULL){
        if(current->value==n){
            printf("Trouvé! Position : %d\n",pos);
        }
        pos++;
        current=(*current).next;
    }
    if((void*)current==NULL){
        printf("pas trouvé\n");
    }
}

void retourner(){
    elem *fin=list;
	elem *finbis=list;
	elem *deb=list;
	int nelem=1;
	int i=0;
	while(fin -> next !=NULL){
		fin=fin -> next;
		nelem++;
	} //on a compté le nb de valeurs
	//printf("nelem= %d",nelem);
	int t[nelem];
	while(finbis !=NULL){
		t[i]=finbis->value;
		i++;
		finbis= finbis -> next;
	}//on a recopié les valeurs de la liste dans un tableau

	while((nelem-1)>=0){
		deb -> value = t[nelem-1];	
		deb=deb -> next;
		nelem--;
	}
}

void ajg(elem**inf,int value){
    elem* t=malloc(sizeof(elem));
    t->value=value;
    t->next=*inf;
    *inf=(t);
}

void concat(elem** petit,elem* grand){
    elem*t=*petit;
    if(*petit!=NULL){
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=grand;
    }  else *petit=grand;

}


elem *quicksort(elem *head)
{
elem *inf_p=NULL,*sup_p=NULL,*parcour=NULL;
elem *pptit, *pgrand;
int pivot=0;
if ( head == NULL) return NULL; // liste de taille 0
pivot = (head)->value;
parcour = head ;
while (parcour->next!=NULL){
parcour = parcour->next;
if (parcour -> value < pivot)
ajg(&inf_p,parcour->value);
else
ajg(&sup_p,parcour -> value);
}

pptit = quicksort(inf_p);
pgrand = quicksort(sup_p);
ajg(&pgrand,pivot);
concat(&pptit,pgrand); /*concat(&a,b) rajoute à a tous les éléments de b */
return(pptit); /*en faisant pointer le next de la dernière elemule de a sur b */
}













int main(){
    while(1){
        printf("menu:\n");
        printf("\t1: ajouter en tete\n");
        printf("\t2: afficher la liste\n");
        printf("\t3: recherche\n");
        printf("\t4: ajouter en queue\n");
        printf("\t5: supprimer\n");
        printf("\t6: dupliquer\n");
        printf("\t7: triée\n");
        printf("\t8: ajouter en place\n");
        printf("\t9: retourner\n");
        printf("\t10: quicksort\n");
        printf("\t0: quitter\n");

        int choix;
        scanf("%d",&choix);
        switch(choix){
            case 0: goto fin;
            case 1 : ajouter_en_tete();
                    break;
            case 2 :
                afficher();
                break;
            case 3 :
                rechercher();
                break;
            case 4 :
                ajouter_en_queue();
                break;
            case 5 :
                supprimer();
                break;
            case 6 :
                dupliquer();
                break;
            case 7 :
                est_triee();
                break;
            case 8 :
                ajouter_en_place();
                break;
            case 9 :
                retourner();
                break;
            case 10:
                list=quicksort(list);
                break;
            default:
                printf("choix incorrect\n");
                continue;
            
        }
    }

    fin:
        printf("au revoir\n");

    return 0;
}