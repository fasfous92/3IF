#include <stdio.h>

int main(){
    int capacity;
    int n;// number of items to scan
    scanf("%d",&capacity);
    scanf("%d",&n);
    int tab[n+1]; //always alocate +1 than numbers as tab[0]=0;
    tab[0]=0;
    int i,j;
    for(i=1;i<n+1;i++){
        scanf("%d",&tab[i]);
    }
    int dp[capacity+1];
    dp[0]=1;
    for(i=1;i<n+1;i++){
        for(j=1;j<capacity+1;j++){
            if(j-tab[i]>=0 && dp[j-tab[i]]==1) //here we check if we can that our weight and our solution minus the weight was verfied
                dp[j]=1;// of course to adapt to your example accordingly

        }
    }





    return 0;
}