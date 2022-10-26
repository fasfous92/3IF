#include <stdio.h>

int a(int n, int i);
int f(int n);

int main()
{
    int n;
    int i=0;

    scanf("%d", &n);
    
     while(a(n,i)!=1){
        i++; 
        printf("%d\r\n",a(n,i));
        
    } 

    return 0;
}

int a(int n, int i){

    if (i==0){
        return n;
    } else if (i>0){
        return f(a(n,(i-1)));
    }
}

int f(int n){
    if (n % 2 ==0){
        return n/2;
    } else if (n % 2 ==1){
        return 3*n+1;
    }
}




