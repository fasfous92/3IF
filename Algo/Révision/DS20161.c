#include <stdio.h>

void tri(int* tab, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i; j < size; j++) {
            if (tab[i] > tab[j]) {
                int tmp = tab[j];
                tab[j] = tab[i];
                tab[i] = tmp;
            }
        }
    }
}

int main() {
    int n;// number of items to scan
    scanf("%d",&n);
    int tab[n]; //always alocate +1 than numbers as tab[0]=0;
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&tab[i]);
    }
    tri(tab,n);

    printf("%d",tab[n-2]-tab[1]);

    return 0;
}