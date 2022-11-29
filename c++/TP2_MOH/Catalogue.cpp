/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::recherche(char* depart, char* arrivee)const{
    Cell* parcours=trajets.getCell();
    int find=0; //juste un indicateur de l'affichage
    Trajet* t=parcours->getData();
    while (parcours->getNext()!= nullptr){
        if(strcmp(depart,t->getvilled())==0 && strcmp(arrivee,t->getvillea())==0){
            t->Afficher();
            find++;
        }
        parcours=parcours->getNext();
        t=parcours->getData();
    }
    if(strcmp(depart,t->getvilled())==0 && strcmp(arrivee,t->getvillea())==0){ //on vérifie si la dernière cellule vérifie nos conditions
        t->Afficher();
        find++;
    }

    if(find==0){
        cout<<"Trajet pas trouver\n"<<endl;
    }

}


void Catalogue :: Afficher()
// Algorithme :
{
    trajets.tri();
    if(trajets.getCell()->getData()!=nullptr){
        trajets.Afficher();
    }
} //----- Fin de Méthode

void Catalogue :: AjouterSimple()
// Algorithme :
{
    char depart[20];
    char arrivee[20];
    char transport[20];

    fscanf(stdin,"%99s %99s %99s",depart,arrivee,transport);
    TrajetSimple *aAjouter = new TrajetSimple(depart,arrivee,transport);
    trajets.Ajouter(aAjouter);
    cout<<"Ajouté"<<endl;
} //----- Fin de Méthode

void Catalogue :: AjouterCompose() 
// Algorithme :
{
    char lecture[100];
    TrajetCompose* monTrajet=new TrajetCompose();
    trajets.Ajouter(monTrajet);
    printf("menu ajout trajet composé:\n");
    printf("\t1: ajouter un nouveau trajet simple \n");
    printf("\t0: fin ajout trajet composé\n");

    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"0")!=0) {

        if (strcmp(lecture,"1")==0) {
            char depart[20];
            char arrivee[20];
            char transport[20];

            fscanf(stdin,"%99s %99s %99s",depart,arrivee,transport);
            TrajetSimple *aAjouter = new TrajetSimple(depart,arrivee,transport);
            if(monTrajet->AjouterTrajet(aAjouter)==0){
                delete aAjouter;
            }
        }else if (strcmp(lecture,"0")==0) {

        }
        printf("menu ajout trajet composé:\n");
        printf("\t1: ajouter un nouveau trajet simple \n");
        printf("\t0: fin ajout trajet composé\n");

        fscanf(stdin,"%99s",lecture);
    }
} //----- Fin de Méthode

void Catalogue :: Interface()
// Algorithme :
{
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
            Afficher();
        }else if (strcmp(lecture,"2")==0) {
            AjouterSimple();   
        }else if (strcmp(lecture,"3")==0) {
            AjouterCompose();
        }else if (strcmp(lecture,"4")==0) {
            printf("veuillez rentrer la ville de départ ainsi que la ville d'arrivée\n");
            char depart[20];
            char arrivee[20];
            fscanf(stdin,"%99s %99s",depart,arrivee);
            recherche(depart,arrivee);

        }else if (strcmp(lecture,"0")==0) {
        }
        printf("menu:\n");
        printf("\t1: affichage\n");
        printf("\t2: ajouter un trajet simple\n");
        printf("\t3: ajouter un trajet composé\n");
        printf("\t4: recherche de parcours\n");
        printf("\t0: quitter\n");

        fscanf(stdin,"%99s",lecture);
    }
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Catalogue>" << endl;
    #endif
    trajets.setCell(unCatalogue.trajets.getCell());
    trajets.setCell(unCatalogue.trajets.getCell());
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
// delete trajets;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

