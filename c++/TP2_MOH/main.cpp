#include <cstring>
#include <iostream>

#include "Trajet.h"
#include "TrajetSimple.h"
#include "Linkedlist.h"
#include "TrajetCompose.h"

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
            TrajetSimple testTrajet ;
            testTrajet.Afficher();

        }else if(strcmp(lecture,"3")==0) {
            std::cout<<"veuillez rentrer la ville de départ, la ville d'arrivée ainsi que le nombre détapes\n"
                  "en suivant le modèle:\n"
                  "villedepart villearrivée nombred'etapes\n"<<std::endl;
            char* debut;
            char * arrivee;
            int n;
            scanf("%99s %99s %d", debut,arrivee,n);
            TrajetCompose T=TrajetComposee(debut, arrivee, n);

        }
        fscanf(stdin,"%99s",lecture);
    }


    return 0;
}