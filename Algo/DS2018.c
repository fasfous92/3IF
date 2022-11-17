#include <stdio.h>




float Avg(int size ,int * t);

int main (){
    int n,m,i,j;

    scanf("%d", &n);
    scanf("%d",&m);
    int r[n];
    int b[m];
    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }
    for(j=0;j<m;j++){
        scanf("%d",&b[j]);
    }

    if(Avg(n,r)> Avg(m,b)){
        printf("R\r\n");
    }else if(Avg(n,r)<Avg(m,b)){
        printf("N\r\n");
    }else{
        printf("RN\r\n");
    }


    return 0;
}


float Avg(int size,int  t[size]){
    int i=0;
    int sum=0;
    for(i=0;i<size;i++){
        sum=sum+t[i];
    }

    float res=(float )sum/(float )size;
    return res;
}