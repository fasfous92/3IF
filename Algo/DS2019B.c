#include <stdio.h>

void afficher(int col,int line,int t[line][col]){
    int i,j;
    for(j=0;j<line;j++){
        for(i=0;i<col;i++){
            printf("%d ", t[j][i]);
        }
        printf("\n");
    }
}


void afficher1D(int n, int * t){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",t[i]);
    }
    printf("\n");

}




int main (){
    int N;
    int n;
    scanf("%d",&n);
    int line=n+1;
    int bi[line] ;
    bi[0]=0;
    int i,j;
    for(i=1;i<line;i++) {
        int p;
        scanf("%d", &p);
        bi[i]=p;
    }
    scanf("%d",&N);
    int col=N+1;

    int t[line][col];

    for(j=0;j<line;j++){
        for(i=0;i<col;i++){
            t[j][i]=0;
        }
    }

    for(i=0;i<line;i++){
        t[i][0]=1;
    }
    for(i=1;i<col;i++){
        t[0][i]=0;
    }
    for(i=1;i<line;i++){
        for(j=1;j<col;j++){
            if(j-bi[i]>=0  && t[i][j-bi[i]]!=0){
                t[i][j]=t[i][j-bi[i]]+1;
                if (t[i-1][j]!=0 && t[i][j]>t[i-1][j]){
                    t[i][j]=t[i-1][j];
                }
            }else {
                t[i][j]=t[i-1][j];
            }
        }
    }

    printf("%d\r\n", t[line-1][col-1]-1);

    return 0;
}
