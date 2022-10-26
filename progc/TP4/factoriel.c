# include <stdio.h>

int main()
{
	int i, num, j;
	printf ("Entrer le nombre : \n");
	scanf ("%d", &num );
	j=1;

	for (i=1; i<num+1; i++)
		j=j*i;    
	printf("La factorielle de %d est %d\n",num,j);
}

