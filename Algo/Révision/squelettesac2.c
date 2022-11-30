#include <stdio.h>


int main(){
    int capacity;
    int n;// number of items to scan
    scanf("%d",&capacity);
    scanf("%d",&n);
    int tab[n+1]; //always alocate +1 than numbers as tab[0]=0;
    tab[0]=0;
    int i,j;
    for(i=1;i<n+1;i++){ //get the weights of each item
        scanf("%d",&tab[i]);
    }
    int dp[n+1][capacity+1];
    for(i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(i=1;i<capacity+1;i++){
        dp[0][i]=0;
    }

    for(i=1;i<n+1;i++){
        for(j=1;j<capacity+1;j++){
            if(j-tab[i]>=0 && dp[i-1][j-tab[i]]!=0){
                dp[i][j]=dp[i-1][j-tab[i]]+ // here you add what you want to add either 1 or the weight figure that out
                if(dp[i][j]>dp[i-1][j]) //important to check if you have the most optimised solution
                    dp[i][j]=dp[i-1][j];

            }else
                dp[i][j]=dp[i-1][j]; //if can't do any, just take the value of the previous "solution"
        }
    }

//print sequence necessary for debug
    for(i=0;i<n+1;i++){
        for(j=0;j<capacity+1;j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }



    return 0;
}