#include <stdio.h>




int combi(int capacity, int* weight, int size){
    int i,j;
    int dp[size+1][capacity+1];
    for(i=0;i<capacity+1;i++){
        dp[0][i]=0;
    }
    for(i=0;i<size+1;i++){
        dp[i][0]=1;
    }

    for(i=1;i<size+1;i++) {
        for (j = 1; j < capacity + 1; j++) {
            if(j-weight[i]>=0 && dp[i-1][j-weight[i]]!=0){
                dp[i][j]=dp[i-1][j-weight[i]]+dp[i-1][j];
                if(dp[i][j]>1)
                    dp[i][j]=1;
            }else
                dp[i][j]=dp[i-1][j];
        }
    }

    for(i=0;i<size+1;i++) {
        for (j = 0; j < capacity + 1; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("*************\n");

    for(i=capacity;i>=0;i--){
        if(dp[size][i]!=0){
            return i;
        }
    }



}


int main(){
    int n,m; //cpacity of each boat
    int pa,po; //respectively the nbr of object silver + gold
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&pa);
    scanf("%d",&po);

    int i;
    int silver[pa+1];
    int gold[po+1];
    silver[0]=0;
    gold[0]=0;
    for(i=1;i<pa+1;i++){
        scanf("%d",&silver[i]);
    }
    for(i=1;i<po+1;i++){
        scanf("%d", &gold[i]);
    }

    int b1a= combi(n,silver,pa);
    int b1o= combi(n,gold,po);
    int b2a= combi(m,silver,pa);
    int b2o= combi(m,gold,po);


    int res= ((b1a+b2o)>(b2a+b1o)) ? (b1a+b2o) : (b2a+b1o);

    printf("%d\r\n",res);
    return 0;
}