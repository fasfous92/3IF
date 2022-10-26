#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 101




typedef struct {
    int begin; /* the begnning of our table */
    int  end ;    /* the end of the filled values */
    int *tab;/* circular array of values */
} CircTable;

CircTable * Init(){
    CircTable *t;
    t= (CircTable *)malloc(sizeof (CircTable));
    t->begin=10;
    t->end=10;
    t->tab= malloc(sizeof(int)*SIZE);
    return t;
}

void Destroy(CircTable* t)
{
    free(t->tab);
    free(t);
    /* put your destruction code here */
}
void InsertValue(CircTable* t,int n){
    t->tab[t->end]=n;
    if(t->end==100){
        t->end=0;
    }else {
        t->end++;
    }
}

void Delete(CircTable* t){
    if(t->begin!=t->end) {
        printf("%d\r\n", t->tab[t->begin]);
        if(t->begin==100){
            t->begin=0;
        }else {
            t->begin++;
        }
    }
}


int main(void)
{
    char lecture[100];
    int val;
    CircTable * t;
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






