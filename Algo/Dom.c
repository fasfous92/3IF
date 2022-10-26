#include <stdio.h>

int palindromes (int tab[], int Size );


int main(){
    int i=0;
    int size=0;
    int t[1000];

    while (i<1000 && t[i-1]!=(-1)){

        scanf("%d", &t[i]);
        size=i;
        i++;
    }

    printf("%d\r\n", palindromes(t,size));

    return 0;
}


int palindromes (int tab [], int size ){
	int i;
    for ( i=0; i<(size-1)/2;i++){
        if(tab[i]!=tab[size-(1+i)]){
            return 0;
        } 
    }
	return 1;
}
