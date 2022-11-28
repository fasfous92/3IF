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
void Catalogue :: AfficherSimples()
// Algorithme :
{
    trajetsSimples.Afficher();
} //----- Fin de Méthode

void Catalogue :: AfficherComposes()
// Algorithme :
{
    trajetsComposes.Afficher();
} //----- Fin de Méthode

void Catalogue :: Afficher()
// Algorithme :
{
    if(trajetsSimples.getCell()->getData()!= nullptr) {
        cout << "Trajets simples : " << endl;
        trajetsSimples.Afficher();
    }
    if(trajetsComposes.getCell()->getData()!= nullptr) {
        cout << "Trajets composés : " << endl;
        trajetsComposes.Afficher();
    }
} //----- Fin de Méthode

void Catalogue :: AjouterSimple()
// Algorithme :
{
    char depart[20];
    char arrivee[20];
    char transport[20];

    fscanf(stdin,"%99s %99s %99s",depart,arrivee,transport);
    TrajetSimple *aAjouter= new TrajetSimple(depart,arrivee,transport); //on crée un trajet simple à partir des données
    trajetsSimples.Ajouter(aAjouter); //on l'ajoute à la linked list
} //----- Fin de Méthode

void Catalogue :: AjouterCompose()
// Algorithme :
{
    char lecture[100];

    printf("menu ajout trajet composé:\n");
    printf("\t1: ajouter un trajet simple existant\n");
    printf("\t2: ajouter un trajet composé existant\n");
    printf("\t3: ajouter un nouveau trajet simple \n");
    printf("\t4: ajouter un nouveau trajet composé \n");
    printf("\t0: fin ajout trajet composé\n");

    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"0")!=0) {
        if (strcmp(lecture,"1")==0) {
            AfficherSimples();
        }else if (strcmp(lecture,"2")==0) {
            AfficherComposes();
        }else if (strcmp(lecture,"3")==0) {


        } else if (strcmp(lecture,"0")==0) {
        }
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


        } else if (strcmp(lecture,"0")==0) {
        }
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
    trajetsComposes.setCell(unCatalogue.trajetsComposes.getCell());
    trajetsSimples.setCell(unCatalogue.trajetsSimples.getCell());
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
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
