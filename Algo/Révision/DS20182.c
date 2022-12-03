#include <stdio.h>
int pow2(int i){
    return i*i;
}

int main(){
    int x0,y0,r,res;
    scanf("%d %d",&x0,&y0);
    scanf("%d",&r);
    int i,j;
    for(i=x0-r;i<=r+x0;i++){
        for(j=y0-r;j<=r+y0;j++){
            int f= pow2((i-x0))+ pow2((j-y0));
            if(f== pow2(r)){
                res++;
            }
        }
    }

    printf("%d\r\n",res);




    return 0;
}
