#include <stdio.h>
#include <malloc.h>

int concat(char* f, char* f1, char* f2){
    FILE * src= fopen(f,"w");
    FILE * s1= fopen(f1,"r");
    FILE * s2= fopen(f2,"r");

    char * res=malloc(sizeof (char)*37);
    while (!feof(s1)){ // gets every word and the copy it
        char buff= fgetc(s1);
        fputc(buff,src);
    }
    free(res);

    fclose(src);
    fclose(s1);




}



int main (){

    int i= concat("f.txt","f1.txt","f2.txt");



    return 0;
}
