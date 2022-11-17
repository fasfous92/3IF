#include <stdio.h>


int main(){
    int i,n;
    scanf("%d", &n);
    int t[n];
    for(i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    int Avg=0;
    int count;
    for(i=0;i<n;i++){
        Avg=Avg+t[i];
    }
    Avg=Avg/n;
    for(i=0;i<n;i++){
        if(t[i]>Avg){
            count++;
        }
    }
    printf("%d\r\n",count);
    return 0;
}