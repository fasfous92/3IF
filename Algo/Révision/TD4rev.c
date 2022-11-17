#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int allocated; /* current allcoation of array */
    int filled;    /* number of items present in the binheap */
    int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
 * also the membre array with the given size
 * it also fill allocated (size) and intializes
 * filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);


int main(void)
{
    char lecture[100];
    int val;
    BinaryHeap * heap;
    heap = Init(10);

    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"bye")!=0) {
        if (strcmp(lecture,"insert")==0) {
            fscanf(stdin,"%99s",lecture);
            val = strtol(lecture,NULL,10);
            InsertValue(heap,val);
        } else if (strcmp(lecture,"extract")==0) {
            if(ExtractMax(heap,&val))
            {
                printf("%d\r\n",val);
            }
        }
        fscanf(stdin,"%99s",lecture);
    }
    Destroy(heap);
    return 0;
}

BinaryHeap * Init(int size)
{
    BinaryHeap * heap;
    heap=(BinaryHeap*) malloc(sizeof(BinaryHeap));
    heap->allocated=size;
    heap->filled=0;
    heap->array=(int*)malloc(sizeof(int)*size);
    /* put your init code here */
    return heap;
}

void InsertValue(BinaryHeap * heap, int value)
{
    int indice, pere, tmp;
    if(heap->filled==heap->allocated){
        heap->allocated++;
        heap->array=(int*)realloc(heap->array,sizeof(int*)*heap->allocated);
    }
    heap->array[heap->filled]=value;
    indice=heap->filled;
    heap->filled++;
    pere=(int)((indice-1)/2);
    while(indice>0 && heap->array[pere]<heap->array[indice]){
        tmp=heap->array[pere];
        heap->array[pere]=heap->array[indice];
        heap->array[indice]=tmp;
        indice=pere;
        pere=(int)((indice-1)/2);
    }


}

int ExtractMax(BinaryHeap * heap, int *res)
{
    int droite,gauche,tmp,indice;
    if(heap->filled==0){
        return 0;
    } else {
        *res=heap->array[0];
        heap->array[0]=heap->array[heap->filled];
        //heap->array[heap->filled]=NULL;
        heap->filled--;
        indice=0;
        droite=(indice+1)*2;
        gauche=(indice*2)+1;
        while(heap->array[indice]<heap->array[droite] || heap->array[indice]<heap->array[gauche]){
            if(heap->array[droite]>heap->array[gauche]){
                tmp=heap->array[droite];
                heap->array[droite]=heap->array[indice];
                heap->array[indice]=tmp;
                indice=droite;
                droite=(indice+1)*2;
                gauche=(indice*2)+1;
            } else {
                tmp=heap->array[gauche];
                heap->array[gauche]=heap->array[indice];
                heap->array[indice]=tmp;
                indice=gauche;
                gauche=(indice+1)*2;
                droite=(indice+1)*2;
            }

        }
        return 1;

    }
    /* put your extraction code here */
}

void Destroy(BinaryHeap * heap)
{
    free(heap->array);
    free(heap);
    /* put your destruction code here */
}
