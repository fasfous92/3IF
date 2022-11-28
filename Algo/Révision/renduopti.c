#include <stdio.h>


int main(){
    /* in this exercice we have a limited ressources with the respect to
     * the weights we can use→ can be assimilated to knapsack 1*/

    int n,N;// n representing the number of bills we will have and N the value to give back
    scanf("%d",&n);
    int bi[n+1];
    bi[0]=0;
    int i,j;
    for(i=1;i<n+1;i++){
        scanf("%d", &bi[i]);
    }
    scanf("%d",&N);

    int dp[N+1];
    dp[0]=1;
    for(j=1;j<N+1;j++){
        for(i=1;i<n+1;i++){
            if(j-bi[i]>=0 && dp[j-bi[i]]!=0){
                if(dp[j]>dp[j-bi[i]]+1 || dp[j]==0) {
                    dp[j] = dp[j - bi[i]] + 1;
                }
            }
        }
    }



    printf("%d\n",dp[N]-1);

    return 0;
}