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
#include <stdbool.h>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques




void Catalogue::rechercheCombi(const char* depart, const char* arrivee, bool display , Linkedlist* monTrajet) const
// Algorithme :  Méthode simple
{
    
    Cell *parcours = trajets.getCell();
    Cell *parcours2 = trajets.getCell();
    Trajet *t = parcours->getData();
    Trajet *tnext = parcours2->getData();
    while (parcours != nullptr) {
        t = parcours->getData();
        if(::strcmp(t->getvilled(),depart)==0 && ::strcmp(t->getvillea(),arrivee)==0) { //ce if va simuler la fonctionnalité d'une recherche de simple trajets
            monTrajet->Ajouter(t->Clone());
            return;
        }
        if (strcmp(t->getvilled(), depart) == 0) {
            while (parcours2 != nullptr) {
                tnext = parcours2->getData();
                if (strcmp(t->getvillea(), tnext->getvilled()) == 0){

                    if(!display) {
                        monTrajet->Ajouter(t->Clone());
                    }
                    monTrajet->Ajouter(tnext->Clone());
                    if(strcmp(tnext->getvillea(), arrivee) != 0) {
                        rechercheCombi(tnext->getvilled(),arrivee,true,monTrajet); //on déja afficher le trajet tnext
                    }
                    break;
                }
                parcours2 = parcours2->getNext();
            }
        }
        parcours = parcours->getNext();
        parcours2 = trajets.getCell();
    }


}//--Fin-rechercheCombi


bool Catalogue::recherche(const char* depart, const char* arrivee)const
// Algorithme :  Méthode simple
{
    bool b=false;
    Cell* parcours=trajets.getCell();
    Trajet* t=parcours->getData();
    while (parcours->getNext()!= nullptr){
        if(strcmp(depart,t->getvilled())==0 && strcmp(arrivee,t->getvillea())==0){
            t->Afficher();
            b=true;
        }
        parcours=parcours->getNext();
        t=parcours->getData();
    }
    
    if(strcmp(depart,t->getvilled())==0 && strcmp(arrivee,t->getvillea())==0){ //on vérifie si la dernière cellule vérifie nos conditions
        t->Afficher();
        b=true;
    }

    if(!b){
        cout<<"Trajet pas trouver."<<endl;
        cout<<"vous n'avez pas trouvé votre trajet?\n Essayez notre nouvel outils de combinaisons de trajets\n"
              "en faisant une recherche combinatoire\n"<<endl;
    }
    return b;

}


void Catalogue :: Afficher()
// Algorithme :  Méthode simple
{
    trajets.tri();
    if(trajets.getCell()->getData()!=nullptr){
        trajets.Afficher();
    }
} //----- Fin de Méthode

void Catalogue :: AjouterSimple()
// Algorithme : Méthode simple
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
// Algorithme : Méthode simple
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
// Algorithme : Méthode simple
{
    char lecture[100];

    printf("menu:\n");
    printf("\t1: affichage\n");
    printf("\t2: ajouter un trajet simple\n");
    printf("\t3: ajouter un trajet composé\n");
    printf("\t4: recherche de parcours\n");
    printf("\t5: recherche combinatoire\n");
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
            if(trajets.getCell()->getData()!=nullptr){
                printf("veuillez rentrer la ville de départ ainsi que la ville d'arrivée\n");
                char depart[20];
                char arrivee[20];
                fscanf(stdin,"%99s %99s",depart,arrivee);
                recherche(depart,arrivee);
            }else{
                cout << "Aucun trajet ajouté" << endl ;
            }
        }else if (strcmp(lecture,"5")==0) {
            if(trajets.getCell()->getData()!=nullptr){
                printf("veuillez rentrer la ville de départ ainsi que la ville d'arrivée\n");
                char depart[20];
                char arrivee[20];
                fscanf(stdin,"%99s %99s",depart,arrivee);
                Linkedlist* monTrajet=new Linkedlist();
                rechercheCombi(depart,arrivee, false,monTrajet);
                if(strcmp(monTrajet->getVillea(),arrivee)==0 && strcmp(monTrajet->getVilled(),depart)==0 )
                    monTrajet->Afficher();
                delete monTrajet;
            }else{
                cout << "Aucun trajet ajouté" << endl ;
            }

        }else if (strcmp(lecture,"0")==0) {
        }
        printf("menu:\n");
        printf("\t1: affichage\n");
        printf("\t2: ajouter un trajet simple\n");
        printf("\t3: ajouter un trajet composé\n");
        printf("\t4: recherche de parcours\n");
        printf("\t5: recherche combinatoire\n");
        printf("\t0: quitter\n");

        fscanf(stdin,"%99s",lecture);
    }
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Constructeur de copie d'un Catalogue 
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Catalogue>" << endl;
    #endif
    trajets.setCell(unCatalogue.trajets.getCell());
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
// Constructeur d'un Catalogue
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Catalogue>" << endl;
    #endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Destructeur d'un Catalogue
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <Catalogue>" << endl;
    #endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
