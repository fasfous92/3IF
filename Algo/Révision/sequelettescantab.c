#include <stdio.h>

int main(){
    int n;// number of items to scan
    scanf("%d",&n);
    int tab[n+1]; //always alocate +1 than numbers as tab[0]=0;
    tab[0]=0;
    int i;
    for(i=1;i<n+1;i++){
        scanf("%d",&tab[i]);
    }





    return 0;
}