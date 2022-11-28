/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//GETTERS,SETTERS
const char* TrajetCompose::getvillea()const
{
    Cell* parcours=compo.getCell();
    while (parcours->getNext()!= nullptr){
        parcours=parcours->getNext();
    }

    return     parcours->getData()->getvillea();

}
const char* TrajetCompose::getvilled()const
{
    Cell* parcours=compo.getCell();
    return     parcours->getData()->getvilled();

}



//--Fin GETTERS,SETTERS


void TrajetCompose::AjouterTrajet(const Trajet* t)
// Algorithme :
{

    if (compo.getCell()->getData() == NULL || getvillea() == t->getvilled()) {
        compo.Ajouter(t); //on utilise la méthode d'ajout de la Linkedlist
    } else {
        cout << "Erreur: impossible de rajouter";
        t->Afficher();
        cout<< "la ville d'arrivée ne correspond pas à la ville de depart\n";
    }

} //----- Fin de AjouterTrajet

void TrajetCompose::Afficher() const
// Algorithme :
//
{
   compo.Afficher();//on utilise la méthode afficher de la Linkedlist
} //----- Fin Afficher



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetComposee>" << endl;
#endif
    compo.setCell(unTrajetCompose.compo.getCell());

} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetComposee>" << endl;
#endif

} //----- Fin de TrajeCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetComposee>" << endl;
#endif

} //----- Fin de ~TrajetComposee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
