#include <stdio.h>
int min(int a, int b){
    int res=(a<b) ? a:b;
    return res;
}

int findcombi(int nfiole, int* weight, int* types, int type, int capacity){
    int dp[nfiole+1][capacity+1];
    int i,j;
    for(i=0;i<nfiole+1;i++){
        dp[i][0]=1;
    }
    for(i=1;i<capacity+1;i++){
        dp[0][i]=0;
    }

    for(i=1;i<nfiole+1;i++){
        for(j=1;j<capacity+1;j++) {
            if(j-weight[i]>=0 && types[i]!=type && dp[i-1][j-weight[i]]!=0) {
                dp[i][j] = dp[i - 1][j - weight[i]] +1;
                if (dp[i][j] >1)
                    dp[i][j]=1;
            }else
                dp[i][j]=dp[i-1][j];

        }

    }
   /* for(i=0;i<nfiole+1;i++) {
        for (j =0; j < capacity + 1; j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    for(i=capacity;i>=0;i++){
        if(dp[nfiole][i]==1){
            return i;
        }
    }

}


int main(){
    int capacity;
    int n;// number of items to scan
    scanf("%d",&capacity);
    scanf("%d",&n);
    int types[n+1];//always alocate +1 than numbers as tab[0]=0;
    int weight[n+1];
    weight[0]=0;
    types[0]=0;
    int i,j;
    for(i=1;i<n+1;i++){ //get the weights of each item
        scanf("%d %d",&weight[i],&types[i]);
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
            if(j-weight[i]>=0 ){
               dp[i][j]=2*min(weight[i], findcombi(n,weight,types,types[i],j-weight[i]));//here using the left capacity we will try to find the best combination possible of the other type to fill the left capacity
                if(dp[i][j]<dp[i-1][j]) //important to check if you have the most optimised solution
                    dp[i][j]=dp[i-1][j];

            }else
                dp[i][j]=dp[i-1][j]; //if can't do any, just take the value of the previous "solution"
        }
    }

//print sequence necessary for debug
    /*for(i=0;i<n+1;i++){
        for(j=0;j<capacity+1;j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/

    printf("%d\r\n",dp[n][capacity]);

    return 0;
}