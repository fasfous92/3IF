#include <stdio.h>
int avg(int* tab, int size){ //real size of table
    int res;
    int i;
    for(i=0;i<size;i++){
        res+=tab[i];
    }
    return res/size; // avg in int so rounded
}

int main(){
    int n;// number fo type 1
    int m;// number of type2
    scanf("%d",&n);
    int tab1[n]; //always alocate as the number moyenne
    int i;
    for(i=1;i<n+1;i++){
        scanf("%d",&tab1[i]);
    }
    scanf("%d",&m); //scan the nbr of type 2
    int tab2[m];
    for(i=1;i<n+1;i++){
        scanf("%d",&tab2[i]);
    }

    int avg1= avg(tab1,n);
    int avg2= avg(tab2,m);
    if(avg1>avg2)
        printf("AVG1\r\n");
    else if(avg2>avg1)
        printf(("AVG2\r\n"));
    else
        printf("AVG1 AVG2\r\n");

    return 0;
}