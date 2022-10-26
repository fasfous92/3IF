#include <stdio.h>

int somme (int t[],int size){
        int i=0;
        int somme;
        for(i=0;i<size;i++)
                somme+=t[i];
        }
        return somme;
}

int produit (int t[], int size){
        int produit=1;
        int i=0;
        for(i=0;i<size;i++){
                produit=produit*t[i];
        }
        return  produit
}
