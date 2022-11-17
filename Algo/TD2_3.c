#include <stdio.h>
int op1(int n);
int op2(int n);
int op3(int n);
int find(int n, int t[n]);

int main(){
    int V;
    int S;
    scanf("%d",&V);
    scanf("%d",&S);
    int i=1;
    int t[V+1];
    for(i=0;i<V+1;i++){
        t[i]=0;
    }

    t[0]=1;
   t[S]=1;
   while(t[i]!=1 && i!=S){
       if(op1(S)<=V){
           t[op1(S)]=1;
           S= op1(S);
       }else if(op2(S)<=V){
           t[op2(S)]=1;
           S=op2(S);
       }else if(op3(S)>0){
           t[op3(S)]=1;
           S=op3(S);
       }
       i++;
   }
   /*for(i=0;i<V+1;i++){
       printf("%d ", t[i]);
   }*/

    int k= find(V+1,t);

    printf("%d\r\n",k);
    return 0;
}


int op1(int n){
    return 3*n;
}
int op2(int n){
    return 2*n;
}
int op3(int n){
    return (int)(n/5);
}


int find(int n,int t[n]){
    int i;
    for(i=0;i<n;i++){
        if(t[n-1-i]==1){
            return n-1-i;
        }
    }
    return 0;
}
