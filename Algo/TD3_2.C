#include <stdio.h>
#include <stdbool.h>

int chemin(int i, int j);
int n;
int arrGrid[100][100];

int main(){


	scanf("%d", &n);
	char temp;
    int nPosI, nPosJ;
	for (int nPosI = 0; nPosI < n; nPosI++) {
		for (int nPosJ = 0; nPosJ < n; nPosJ++) {
			scanf("%d%c", &arrGrid[nPosI][nPosJ], &temp);
		}
	}
	printf("eeeeee\n");
	int x=chemin(0,0);
	printf("%d\r\n",x);
	return 0;


}

int chemin(int i, int j){
    int p=0;
    if(i==n && j==n){
        p++;
        return p;
    }
    if(arrGrid[i][j+1]==0){
        printf("µµµµµ\n");
    p+=chemin(i,j+1);

    }
    if(arrGrid[i+1][j]==0){
        printf("rrrr\n");
        p+=chemin(i+1,j);
    }
    return p;
}
