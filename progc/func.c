#include <stdio.h>
void f(int n) {
/* code de la fonction */
	if (n>10){
		printf("n est grand \n");
	}
}




int main() {
int tab[] = { 1, 11, 2, 22, 3, 33 };
int i;
for (i = 0; i < 6; i++) {
f(tab[i]);
}
return 0;
}
