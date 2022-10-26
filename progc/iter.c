#include <stdio.h>
int main() {
int tab[] = {1, 7, 4, 5, 9, 3, 5, 11, 6, 3, 4};
int i = 0;
while (i < 10) {
/* suite du code */
	if (tab[i]<=10){
		printf("%d\n", tab[i]);
	}
	i++;
}
return 0;
}
