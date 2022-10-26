#include <stdio.h>
int op1(int n);
int op2(int n);
int op3(int n);
int Max(int n, int m);
int check(int s, int v);
int main(){
    int V;
    int S;
    scanf("%d",&V);
    scanf("%d",&S);
    int check1= check(op1(S),V);
    int check2= check(op2(S),V);
    int check3= check(op3(S),V);
    
    printf("%d\r\n", Max(Max(check1,check2),check3));

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

int Max(int n, int m){
    if (n>=m){
        return n;
    }else {
        return m;
    }
}

int check(int s, int v){
    int max=s;
    int i=0;
    if (s>v){
        return 0;
    } else {
        while (i < 2) {
            if (op1(s) > v) {
                if (op2(s) > v) {
                    s = op3(s);
                    max = Max(max, s);
                } else {
                    s = op2(s);
                    max = Max(max, s);
                }
            } else {
                s = op1(s);
                max = Max(max, s);
            }
            i++;
        }
    }
    return max;
}
