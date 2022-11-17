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

void afficher100(int N,int n,int t[N+1][n+1]){
    int i;

        for(i=0;i<n+1;i++){
            printf("%d ", t[N][i]);
            printf("\n");
        }

}
void afficher1D(int n, int * t){
    int i;
    for(i=0;i<n+1;i++){
        printf("%d ",t[i]);
    }
    printf("\n");

}




int main (){
    int N;
    int n;

    scanf("%d",&N);
    scanf("%d",&n);
    int line=n+1;
    int col=N+1;
    int type[line] ;
    int time[line];
    int i,j;
    type[0]=0;
    time[0]=0;
    for(i=1;i<n+1;i++) {
        int p,l;
        scanf("%d %d", &p, &l);
        type[i]=p;
        time[i]=l;
    }
    afficher1D(n,time);
    afficher1D(n,type);


    int t[line][col];
    for(j=0;j<line;j++){
        for(i=0;i<col;i++){
                t[j][i]=0;
        }
    }
    printf("************\n");


    afficher(col,line,t);
    printf("************\n");

    for(i=0;i<line;i++){
        t[i][0]=1;
    }
    for(i=1;i<col;i++){
        //t[1][-1]=2;
        t[0][i]=0;
    }
    afficher(col,line,t);
    printf("************\n");
    for(i=1;i<line;i++){
        for(j=1;j<col;j++){
            if(j-time[i]>=0){
                t[i][j]=t[j-time[i]][j-1]+ t[i][j-1];
                printf("%d**%d**%d\n",time[i],i,j);
            }
            if(t[i][j]>1){
                t[i][j]=1;
            }
        }

    }


    /*for(i=1;i<col;i++){
        for(j=1;j<line;j++){
            if(i-time[j]>=0){
                t[i][j]=t[i][j-1]+t[i-time[j]][j-1];
                printf("%d**%d",i,j);
            }
            if(t[i][j]>1){
                t[i][j]=1;
            }
        }
    }*/
    printf(("eeee\n"));
    afficher(col,line,t);

    //afficher100(N,n,t);
    if(t[N][n]==1){
        printf("rrrr");
    }else {
        printf("ttttt");
    }

    return 0;
}
