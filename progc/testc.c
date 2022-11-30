#include <stdio.h>

int main(){

int tab[]={3,5,7,9,11,13,15,17,19};
int *p;
p=tab;

printf("%p\n",p+(*p+4));
printf("%p\n",p+9);




return 0;
}
