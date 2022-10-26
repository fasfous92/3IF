#include <stdio.h>

int somme(int t[], int size){
	int i=0;
	int res=0;
	for(i=0;i<size;i++){
	res+=t[i];
	}
	return res;
}

double produit(int t[], int size){
	int i=0;
	double res=1;
	for(i=0;i<size;i++){
	res=res*t[i];
	}
	return res;
}

int avg(int t[],int size){
	double  m=(double)somme(t,size);
	double avg=m/(double)(size);
	return (int)avg;

}
int min(int t[],int size){
	int min=t[0];;
	int i=0;
	for(i=0;i<size;i++){
		if(min>t[i]){
		min=t[i];
		}
	}
	return min;
}
int max(int* t,int size){
        int max=t[0];
        int i=0;
        for(i=0;i<size;i++){
                if(max<t[i]){
                max=t[i];
                }
        }
        return max;
}



