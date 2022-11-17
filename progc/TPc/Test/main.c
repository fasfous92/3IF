#include <stdio.h>
#include <string.h>
typedef char[100] mot 
int power(int a, int b){
    int i;
    int res=1;
    for(i=0;i<b;i++){
        res*=a;
    }
    return res;
}

float atoi (char* c){
    int i,pow,res;
    int indice=-1;
    int lpow= strlen(c)-2;
    for(i=0;i<strlen(c)-1;i++){
       // if((int) c[i]==
        if((int)c[i]==46){
            indice=i+1;
        }else{
            int pos=(int)c[i]-48;
            res+=pos* power(10,lpow-pow);
            pow++;
        }
    }
    if(indice==-1){
        return (float) res;
    }else{
        float res1;
        pow= strlen(c)-indice;
        res1=(float)res/(float)power(10,pow);
        return res1;
    }

}

int Tp_strcmp(const char* s1, const char* s2){
    if(strlen(s1)> strlen(s2)){
        return 1;
    }else if(strlen(s1)< strlen(s2)){
        return -1;
    }else{
        int i;
        for(i=0;i< strlen(s1);i++){
            if(s1[i]>s2[i]){
                return 1;
            }else if(s1[i]<s2[i]){
                return -1;
            }
        }
        return 0;
    }
}

char* itoa( int a, int* nbelem){
    static char c[20];
    int res=a;
    int reste,i;
    while (res>0){
        reste=res%10;
        res=res/10;
        c[i]=(char) reste+48;
        i++;
    }
    *nbelem=i+1;
    return c;
}
void affiche (unsigned  int valeur){
    int i;
    for(i=0;i<sizeof(valeur);i++){
        printf("%x\n", i);
    }


}


int main (){
    int taille=46;
    affiche(taille);



    return 0;
}