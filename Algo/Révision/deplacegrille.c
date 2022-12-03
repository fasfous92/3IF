#include <stdio.h>
int findtraject(int* res,int currenti, int currentj,int n, int dp[n][n]){
    if(currenti==n-1 && currentj==n-1){
        (*res)++;
        return 1;
    }else{
        if(currentj+1<n && dp[currenti][currentj+1]!=-1){
            findtraject(res,currenti,currentj+1,n,dp);
        }
        if(currenti+1<n && dp[currenti+1][currentj]!=-1){
            findtraject(res,currenti+1,currentj,n,dp);
        }
        return 0;
    }
}


int main(){
    int n;// size of grid
    scanf("%d",&n);
    int tab[n][n];
    int i,j;
    int res=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &tab[i][j]);
        }
    }

    int r= findtraject(&res,0,0,n,tab);

    printf("%d\r\n",res);


    return 0;
}