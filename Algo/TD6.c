#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
/* mettez ici vos déclarations de fonctions et types */

typedef char * Key;
typedef char * Value;
enum STATE{EMPTY,SET,REMOVED};
const char * Labels[]={"EMPTY","SET","REMOVED"};

typedef  struct {
    Key key;
    enum STATE status;
    Value  val;
}Data ;

typedef struct {
    Data * tab;
    int size;
}HashTable;

void error(void);
unsigned int shift_rotate(unsigned int val, unsigned int n);
unsigned int Encode(Key key);
unsigned int hash(unsigned int val, unsigned int size);
unsigned int HashFunction(Key key, unsigned int size);




HashTable* Initialiser(int size){
    HashTable* t= malloc(sizeof (HashTable));
    t->tab= malloc(sizeof(Data)*size);
    t->size=size;
    int i;
    for(i=0;i<t->size;i++){
        t->tab[i].status=EMPTY;
        /*t.tab[i].key= malloc(sizeof(Key));
        t.tab[i].val=malloc(sizeof(Value));*/
    }
    return t;
}

bool findpos(HashTable* t,Key key, int * index){
    int pos= HashFunction(key,t->size);
    int i=0;
    int possibleindex=-1;
    if(t->tab[pos].status==EMPTY){
        *(index)=pos;
        return true;
    }
    for(i=pos;i<t->size;i++){
        if(t->tab[i].status==EMPTY){
            *index=i;
            return true;
        }else if (strcmp(t->tab[i].key,key)==0){
            *index=i;
            return true;
        }

        if(t->tab[i].status==REMOVED){
            possibleindex=i;
        }
    }
    for(i=0;i<pos;i++){
        if(t->tab[i].status==REMOVED){
            possibleindex=i;
        }
    }
    *index=possibleindex;
    return false;
}

void Inserer(HashTable* t,Key key,Value valeur){
    int indice=0;
    //printf("**%d\n", HashFunction(key,t->size));
    bool b= findpos(t,key,&indice);
    if(!b && indice!=-1){
        t->tab[indice].key=key;
        t->tab[indice].val=valeur;
        t->tab[indice].status=SET;
    }else if(b){
        t->tab[indice].key=key;
        t->tab[indice].val=valeur;
        t->tab[indice].status=SET;
    }
}
void query(HashTable* t, Key key){
    unsigned int pos= HashFunction(key,t->size);
    if(t->tab[pos].status==SET && strcmp(t->tab[pos].key,key)==0){
            printf("%s\r\n",t->tab[pos].val);

    }else{
        printf("Not found\r\n");
    }
}
void destroy(HashTable* t){
    int i;
    for(i=0;i<t->size;i++){
        if(t->tab[i].status==SET) {
            free(t->tab[i].key);
            free(t->tab[i].val);
        }
    }
    free(t->tab);
    free(t);
}
void Supprimer(HashTable* t,Key key){
    int i;
    for(i=0;i<t->size;i++){
        if(t->tab[i].status==SET){
            if(strcmp(t->tab[i].key,key)==0) {
                t->tab[i].status = REMOVED;
                free(t->tab[i].key);
                free(t->tab[i].val);
                break;
            }
        }
    }


}
void stats(HashTable* t){
    int size=t->size;
    int i;
    int sup=0;
    int vide=0;
    int used=0;
    for(i=0;i<t->size;i++) {
        switch (t->tab[i].status) {
            case SET:
                used++;
                break;
            case EMPTY:
                vide++;
                break;
            case REMOVED:
                sup++;
                break;
        }
    }
    printf("size    : %d\r\n",size);
    printf("empty   : %d\r\n",vide);
    printf("deleted : %d\r\n",sup);
    printf("used    : %d\r\n",used);



}







/* fonction de décalage de bit circulaire */
unsigned int shift_rotate(unsigned int val, unsigned int n)
{
    n = n%(sizeof(unsigned int)*8);
    return (val<<n) | (val>> (sizeof(unsigned int)*8-n));
}

/* fonction d'encodage d'une chaîne de caractères */
unsigned int Encode(Key key)
{
    unsigned int i;
    unsigned int val = 0;
    unsigned int power = 0;
    for (i=0;i<strlen(key);i++)
    {
        val += shift_rotate(key[i],power*7);
        power++;
    }
    return val;
}

/* fonction de hachage simple qui prend le modulo */
unsigned int hash(unsigned int val, unsigned int size)
{
    return val%size;
}

/* fonction de hachage complète à utiliser */
unsigned int HashFunction(Key key, unsigned int size)
{
    return hash(Encode(key),size);
}

/* placer ici vos définitions (implémentations) de fonctions ou procédures */

void error(void)
{
    printf("input error\r\n");
    exit(0);
}

int main(void)
{
    int size;
    char lecture[100];
    char * key;
    char * val;
    HashTable * t= malloc(sizeof (HashTable));
    if (fscanf(stdin,"%99s",lecture)!=1)
        error();
    while (strcmp(lecture,"bye")!=0)
    {
        if (strcmp(lecture,"init")==0)
        {
            if (fscanf(stdin,"%99s",lecture)!=1)
                error();
            size = atoi(lecture);
            /* mettre le code d'initialisation ici */
            free(t);
            t= Initialiser(size);
        }
        else if (strcmp(lecture,"insert")==0)
        {
            if (fscanf(stdin,"%99s",lecture)!=1)
                error();
            key = strdup(lecture);
            if (fscanf(stdin,"%99s",lecture)!=1)
                error();
            val = strdup(lecture);
            /* mettre ici le code d'insertion */
            Inserer(t,key,val);
        }
        else if (strcmp(lecture,"delete")==0)
        {
            if (fscanf(stdin,"%99s",lecture)!=1)
                error();
            key = strdup(lecture);
            /* mettre ici le code de suppression */
            Supprimer(t,key);
        }
        else if (strcmp(lecture,"query")==0)
        {
            if (fscanf(stdin,"%99s",lecture)!=1)
                error();
            key = strdup(lecture);
            /* mettre ici le code de recherche et traitement/affichage du résultat */
            query(t,key);
        }
        else if (strcmp(lecture,"destroy")==0)
        {
            /* mettre ici le code de destruction */
            destroy(t);
        }
        else if (strcmp(lecture,"stats")==0)
        {
            /* mettre ici le code de statistiques */
            stats(t);
        }

        if (fscanf(stdin,"%99s",lecture)!=1)
            error();
    }
    return 0;
}