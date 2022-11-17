#include <stdio.h>

void afficher(int line, int col, int t[col][line]){
    int i,j;
    for(i=0;i<line;i++){
        for(j=0;j<col;j++){
            printf("%d",t[i][j]);
        }
        printf("\n");
    }




}
int main (){
    int N;
    int n;
    scanf("%d", &N);
    scanf("%d", &n);
    int line=n+1;
    int col=N+1;

    int t[line][col];
    int i,j;
    for(i=0;i<line;i++){
        for(j=0;j<col;j++){
            t[i][j]=0;
        }
    }

    afficher(line,col,t);







    return 0;
}