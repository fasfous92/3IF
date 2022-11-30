#include <stdio.h>

/*int concat(char* src, char* file1, char* file2){
    FILE * f= fopen(src,"w");
    FILE * f1= fopen(file1,"r");
    FILE * f2= fopen(file2,"r");

    while (feof(f1)==0){
        fputc(fgetc(f1),f);
    }

    while (feof(f2)==0){
            fputc(fgetc(f2),f);
    }

    fclose(f);
    fclose(f1);
    fclose(f2);


    return 0;

}*/

int ft_print(FILE* file){
    while (feof(file)==0){
        fputc(fgetc(file),stdout);
    }
    return 0;
}


int main(int argc, char**argv ) {

    FILE* fread= fopen(argv[1],"w+");
   // FILE * write= fopen(argv[2],"w");

    int i,j;
    for(i=0;i<20;i++){
        for(j=0;j<40;j++){
            fputc('_',fread);
        }
        fputc('\n',fread);
    }
    fseek(fread,0,SEEK_SET);


    char c;
    int offset;
    ft_print(fread);
    printf("rentrer un caractere\n");
    scanf("%c",&c);
    printf("rentrer un offset\n");
    scanf("%d",&offset);


    fseek(fread,0,SEEK_SET);
    while(c!='q'){
        if (offset<0 && offset> ftell(fread))
            scanf("%d",&offset);
        fseek(fread,offset,SEEK_SET);
        fputc(c,fread);
        rewind(fread);
        ft_print(fread);
        printf("rentrer un caractere\n");
        scanf("%c",&c);
        getc(stdin);
        printf("rentrer un offset\n");
        scanf("%d",&offset);



    }


    fclose(fread);
    //int i= concat("def.txt","colonne1.txt","colonne2.txt");
    return 0;


}
