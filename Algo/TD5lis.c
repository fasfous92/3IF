#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct {
    int valeur;
    struct cellule* suivant;//next cellule to point at
}cellule;

typedef struct {
    cellule * begin;/*cellule to begin with */
    cellule * end;    /* cellule to end with */
} stack;

stack * Init(){
    stack *t;
    t= malloc(sizeof (stack));
    t->begin=NULL;
    t->end=NULL;
    return  t;
}



void Destroy(stack * t)
{
    free(t->end);
    //free(t->begin);
    free(t);
    /* put your destruction code here */
}
void InsertValue(stack * t,int n){
    if(t->begin==NULL){
        t->end= malloc(sizeof (cellule));
        t->begin= malloc(sizeof(cellule));
        t->begin->valeur=n;
        t->begin->suivant=t->end;
    }else {
        t->end->valeur=n;
        cellule * m= malloc(sizeof(cellule));
        m=t->end;
        t->end= malloc(sizeof (cellule));
        m->suivant=t->end;
    }
}

void Delete(stack * t){
    if(t->begin->suivant!=NULL) {
    printf("%d\r\n",t->begin->valeur);
        cellule *p=t->begin->suivant;
        free(t->begin);
        t->begin=p;
    }
}


int main(void)
{
    char lecture[100];
    int val;
    stack * t;
    t = Init();

    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"bye")!=0) {
        if (strcmp(lecture,"queue")==0) {
            fscanf(stdin,"%99s",lecture);
            val = strtol(lecture,NULL,10);
            InsertValue(t,val);
        } else if (strcmp(lecture,"dequeue")==0) {
            Delete(t);
        }
        fscanf(stdin,"%99s",lecture);
    }
    Destroy(t);
    return 0;
}

