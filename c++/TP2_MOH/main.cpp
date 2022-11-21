#include <cstring>
#include <iostream>

#include "Trajet.h"
#include "TrajetSimple.h"

int main(){
    char lecture[100];

    printf("menu:\n");
    printf("\t1: affichage\n");
    printf("\t2: ajouter un trajet simple\n");
    printf("\t3: ajouter un trajet composé\n");
    printf("\t4: recherche de parcours\n");
    printf("\t0: quitter\n");

    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"0")!=0) {
        if (strcmp(lecture,"1")==0) {
            TrajetSimple testTrajet ;
        } else if (strcmp(lecture,"0")==0) {
            
        }
        fscanf(stdin,"%99s",lecture);
    }


    return 0;
}