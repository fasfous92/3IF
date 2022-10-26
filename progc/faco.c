#include <stdio.h>
int main() {
int tab[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
/* utiliser une boucle for pour calculer la factorielle de 10 */
double facto=1;
for(int i=0; i<10;i++){
	facto=facto*((double)tab[i]);
}

printf("10! = %f",facto);
return 0;
}

