#include <stdio.h>

int sousseq(int t[],int n);
int sommetab (int t[], int begin, int end);

int main(){
    int n;
    scanf("%d",&n);
    
    int t[n];

    for(int i=0;i<n;i++){
        scanf("%d", &t[i]);
    }

    /* while (i<1000 && t[i-1]!=(-1)){

        scanf("%d", &t[i]);
        size=i;
        i++;
    } */
    printf("%d\r\n", sousseq(t,n));
    /*for (int i=0;i<8;i++){
    printf("%d\r\n",sommetab(t,i,7));
    }*/
    return 0;
}

int sousseq(int t[], int n){
    int size=n ;
    int begin;
    int end;
    int max1=0;
    int max2=0;
    for (int i=0;i< size;i++){
        int somme=0;
        somme=sommetab(t,i,(size-1));
        if (somme>max1){
            max1=somme;
            begin=i;

        } 
    }

    for (int i=0;i< size;i++){

        int somme=0;
        somme=sommetab(t,0,(size-(1+i)));
        if (somme>max2){
            max2=somme;
            end=size-(1+i);
        } 
    }
    return sommetab(t,begin,end);


}

int sommetab (int t[], int begin, int end){
    int somme=0;
    for(int i=begin;i<=end;i++){
        somme=somme+t[i];
    }
    return somme;
}
