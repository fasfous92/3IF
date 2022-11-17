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

void table(int lineA,int colb1,int bateau1A[lineA][colb1],int argent[lineA]){ //fixes the table according to the set of weights
    int i,j;
    for(j=0;j<lineA;j++){
        for(i=0;i<colb1;i++){
            bateau1A[j][i]=0;
        }
    }
    for(i=0;i<lineA;i++){
        bateau1A[i][0]=1;
    }
    for(i=1;i<colb1;i++){
        bateau1A[0][i]=0;
    }

    for(i=1;i<lineA;i++){
        for(j=1;j<colb1;j++){
            if(j-argent[i]>=0  && bateau1A[i-1][j-argent[i]]!=0){
                bateau1A[i][j]=bateau1A[i-1][j-argent[i]];//+argent[i];
                if (bateau1A[i-1][j]!=0 && bateau1A[i][j]>bateau1A[i-1][j]){
                    bateau1A[i][j]=bateau1A[i-1][j];
                }
            }else {
                bateau1A[i][j]=bateau1A[i-1][j];
            }
        }

    }
}

int find(int line, int col, int t[line][col]){ //finds the maximum weight you can attain
    int i;
    for(i=0;i<col;i++){
        if(t[line-1][col-1-i]==1){
            return col-1-i;
        }
    }
    return 0;
}
/* here tA represents the max weight you get from argent on bateau 1
here tO represents the max weight you get from Or on bateau 1
here hA represents the max weight you get from argent on bateau 2
here hO represents the max weight you get from Or on bateau 2
*/

int combination(int tA, int tO, int hA, int hO){
    int combi1=tA+hO;
    int combi2=tO+hA;
    if(combi1>combi2){
        return combi1;
    }else {
        return combi2;
    }
}





int main (){
    int n;
    int m;

    scanf("%d",&n);
    scanf("%d",&m);
    int colb1=n+1;
    int colb2=m+1;
    int lineA;
    int lineO;
    scanf("%d",&lineA);
    scanf("%d",&lineO);
    lineA++;
    lineO++;
    int argent[lineA] ;
    int or[lineO];
    int i,j;
    argent[0]=0;
    or[0]=0;
    for(i=1;i<lineA;i++) {
        int p;
        scanf("%d", &p);
        argent[i]=p;
    }
    for(i=1;i<lineO;i++) {
        int p;
        scanf("%d", &p);
        or[i]=p;
    }

    int bateau1A[lineA][colb1];
    int bateau1O[lineO][colb1];
    int bateau2A[lineA][colb2];
    int bateau2O[lineO][colb1];

    table(lineA,colb1,bateau1A,argent); //fix bateau1 avec poids argent
    table(lineA,colb2,bateau2A,argent);  //fixer bateau2 avec poids argent
    table(lineO,colb1,bateau1O,or);// fixer bateau1 avec poids or
    table(lineO,colb2,bateau2O,or); //fixer bateau2 avec poids argent

    int tA=find(lineA,colb1,bateau1A);
    int tO=find(lineO,colb1,bateau1O);
    int hA=find(lineA,colb2,bateau2A);
    int hO=find(lineO,colb2,bateau2O);

    int max= combination(tA,tO,hA,hO);

    printf("%d\r\n", max);

    return 0;
}
