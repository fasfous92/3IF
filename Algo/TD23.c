#include <stdio.h>
int op1(int n);
int op2(int n);
int op3(int n);
int Max(int n, int m);
void chemistry(int t[],int s,int v);
int main(){
    int v;
    int s;
    scanf("%d",&v);
    scanf("%d",&s);
    int size=v+1;
    int t[size];
    int i=0;
    t[10]=0;
    int res=0;
   
    chemistry(t,s,v);
  
    
    for(i=0;i<size;i++){
    	if(t[size-1-i]==1){
    	    res=size-i-1;
    	    break;
    	}
    
    }
    printf("%d\r\n",res);

    return 0;
}


int op1(int n){
    return 3*n;
}
int op2(int n){
    return 2*n;
}
int op3(int n){
    return (int)(n/5);
}

int Max(int n, int m){
    if (n>=m){
        return n;
    }else {
        return m;
    }
}

void chemistry(int t[], int s,int v){
    
    if (t[s]!=1){
	    t[s]=1; 
	    if(0<op3(s) && op3(s)<=v){
		    chemistry(t,op3(s),v);
	    }
	    if(op2(s)<=v){
		    chemistry(t,op2(s),v);
	    }
	    if(op1(s)<=v){
		    chemistry(t,op1(s),v);
	    }
    }	
}


