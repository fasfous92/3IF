#include <stdio.h>


int min(int a, int b){
    if(a>b)
        return b;
    else
        return a;
}
int findcomb(int capacity, int* types, int sizefiole, int* cap, int type){
    int i,j;
    int dp[sizefiole+1][capacity+1];
    for(i=0;i<capacity+1;i++){
        dp[0][i]=0;
    }
    for(i=0;i<sizefiole+1;i++){
        dp[i][0]=1;
    }

    for(i=1;i<sizefiole+1;i++){
        for(j=1;j<capacity+1;j++){
            if((types[i]!=type) && (j-cap[i]>=0)){//} && (dp[j-cap[i]][i-1]!=0)){
                dp[i][j]=(dp[i-1][j-cap[i]]-(dp[i-1][j-cap[i]]%10))+cap[i];
                if(dp[i][j]<dp[i-1][j]){
                    dp[i][j]=dp[i-1][j];
                }
            } else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

   /* for(i=0;i<sizefiole+1;i++){
        for(j=30;j<capacity+1;j++){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/

    return dp[sizefiole][capacity];



}

int main() {
    int c, f; // c being the capacity of the recipient and f the number of tubes
    scanf("%d", &c);
    scanf("%d", &f);
    int types[f + 1]; // store the type fo each capacity stored in the next array called cap
    int cap[f + 1];
    types[0] = 0;
    cap[0] = 0;
    int i, j;
    for (i = 1; i < f + 1; i++) {
        scanf("%d%d", &cap[i], &types[i]);
    }
    int dp[f + 1][c + 1];
    for (i = 0; i < c + 1; i++) {
        dp[0][i] = 0;
    }
    for (i = 0; i < f + 1; i++) {
        dp[i][0] = 1;
    }

    for (i = 1; i < f + 1; i++) {
        for (j = 1; j < c + 1; j++) {
            if (j - cap[i] >= 0) {
                int comb = findcomb(j - cap[i], types, f, cap, types[i]);
                int mini = min(cap[i], comb);
                dp[i][j] = 2 * mini;
                if(dp[i][j]<dp[i-1][j]){
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    for (i = 0; i < f + 1; i++) {
        for (j = 0; j < c + 1; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}