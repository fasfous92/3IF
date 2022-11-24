#include <stdio.h>

 int Powmodul0(int a, int b,int m){// methode qui donne le résultat de a puissance b modulo m
    int res=1;
    int i;
    for(i=0;i<b;i++){
        res=((res%m)*(a%m))%m;
    }
    return res;
}

int main(){
    int n; //le degré du polynome
    int m;// la valeur du modulo à employer
    int x;// La valeur sur laquelle on doit évaluer
    scanf("%d",&n);
    int coeff[n+1];
    int i;
    for(i=0;i<n+1;i++){
        scanf("%d",&coeff[i]);
    }


    scanf("%d",&m);
    scanf("%d",&x);
    int res=0;
    for(i=0;i<n+1;i++){
        if(coeff[i]!=0) {
            coeff[i] = ((coeff[i] % m) * Powmodul0(x, i, m))%m;
            res = (((res%m)+(coeff[i]%m))%m);
        }
    }

    printf("%d\r\n",res);



    return 0;
}