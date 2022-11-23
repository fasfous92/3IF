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
        if (strcmp(lecture,"2")==0) {
            char depart[20];
            char arrivee[20];
            char transport[20];

            fscanf(stdin,"%99s %99s %99s",depart,arrivee,transport);
            TrajetSimple testTrajet(depart,arrivee,transport);
            testTrajet.Afficher();
        } else if (strcmp(lecture,"0")==0) {
        }
        fscanf(stdin,"%99s",lecture);
    }


    return 0;
}