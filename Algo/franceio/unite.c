#include <stdio.h>




int main(){
int n;
scanf("%d", &n);
char c[n];
float v[n];
int i=0;
for(i=0;i<n;i++){
	scanf("%f %c", &v[i], &c[i]);
}


for(i=0;i<n;i++){
	switch(c[i]){
		case 'm':
			v[i]=v[i]*((float)1/(float)0.3048);
			c[i]='p';
			break;
		case 'g':
			v[i]=v[i]*((float)0.002205);
			c[i]='l';
			break;
		case 'c':
			v[i]=32+(v[i]*1.8);
			c[i]='f';
			break;
		}
}

for(i=0;i<n;i++){
	printf("%f %c\r\n", v[i], c[i]);
}










return 0;
}
