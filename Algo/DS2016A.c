#include <stdio.h>
#include <stdlib.h>

int main (){
    int i,n;
   scanf("%d", &n);
    int tab[]={-4,12,3,6};
    for(i=0;i<n;i++){
        scanf("%d",&tab[i]);
    }
    // we will search in the beginning for the max value and then for the min value
    int max,min;
    max=tab[0];
    min=tab[0];
    for(i=0;i<n;i++){
        if(tab[i]>max){
            max=tab[i];
        }else if(tab[i]<min){
            min=tab[i];
        }
    }

    // using max and min we will find max2 and min2
    int max2,min2;
    max2=min;
    min2=max;
    for(i=0;i<n;i++){
        if(tab[i]>max2 && tab[i]<max){
            max2=tab[i];
        }
        if(tab[i]<min2 && tab[i]>min){
            min2=tab[i];
        }
    }

    printf("%d\r\n",max2-min2);


    return 0;
}