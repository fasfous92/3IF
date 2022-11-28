#include <stdio.h>


int main(){
    int N,n; //N the time capacity and n the number of tasks to choose from
    scanf("%d",&N);
    scanf("%d",&n);
    int i,j;
    int time[n+1];
    int type[n+1];
    time[0]=0;
    type[0]=0;
    for(i=1;i<n+1;i++){
        int cat;
        scanf("%d %d", &cat,&time[i]);
        type[i]=cat%2; // we chose modulo 2 to have type 2 task nullified→→easier to work with
    }

    int dp[n+1][N+1];

    for(i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(i=1;i<N+1;i++){
        dp[0][i]=0;
    }

    /* in this case we will use a simple knapsak type 2 problem:
     * so we will check if the duration can fit in the actual time j-time[i]
     * then we check if the Time-duration is different from 0 (feasible or not)
     * furthermore if the value optained is bigger than the previous line (different from 0)
     * we will switch */

    for(i=1;i<n+1;i++){
        for(j=1;j<N+1;j++){
            if(j-time[i]>=0 && dp[i-1][j-time[i]]!=0){
                dp[i][j]=dp[i-1][j-time[i]]+type[i];
                if(dp[i][j]>dp[i-1][j] && dp[i-1][j]!=0)
                    dp[i][j]=dp[i-1][j];
            }else
                dp[i][j]=dp[i-1][j];
        }
    }



    // now in order to print the result we need to print the value od dp[n][N]-1 (because of the
    // offset of 1 added by the O collumn.
    printf("%d\r\n",dp[n][N]-1);


    return 0;
}