/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    d�but                : $21-11-2022$
    copyright            : (C) $2022$ par $Bin�me3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>



//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

// GETTERS,SETTERS
const char* TrajetCompose::getvillea() const
// Algorithme : M�thode simple
{
    Cell* parcours = compo.getracine();
    while (parcours->getNext() != nullptr)
    {
        parcours = parcours->getNext();
    }

    return parcours->getData()->getvillea();
}

const char* TrajetCompose::getvilled() const
// Algorithme : M�thode simple
{
    Cell* parcours = compo.getracine();
    return parcours->getData()->getvilled();
}

//--Fin GETTERS,SETTERS

int TrajetCompose::AjouterTrajet(const Trajet* t)
// Algorithme : M�thode simple
{

    if (compo.getracine()->getData() == nullptr || strcmp(getvillea(), t->getvilled()) == 0)
    {
        if (compo.getracine()->getData() == nullptr)
            depart = (char*)t->getvilled();
        compo.Ajouter(t); // on utilise la m�thode d'ajout de la Linkedlist
        arrivee = (char*)t->getvillea();
        return 1;
    }
    else
    {
        cout << "Erreur: impossible de rajouter";
        t->Afficher();
        cout << "la ville d'arriv�e ne correspond pas � la ville de depart\n";
        return 0;
    }

} //----- Fin de AjouterTrajet

void TrajetCompose::Afficher() const
// Algorithme : M�thode simple
//
{
    cout << "TC de " << depart << " � " << arrivee << ":" << endl;
    cout << "[\n";
    compo.Afficher();
    cout << "]\n";

} //----- Fin Afficher

string TrajetCompose::Decrire(bool forTC) const 
// Algorithme : M�thode simple
//
{
    string description;
    description.append("2;");
    description.append(depart);
    description.append(";");
    description.append(arrivee);
    description.append(";#\n");

    Cell* parcours = compo.getracine();
    while (parcours->getNext() != nullptr)
    {
        description.append(parcours->getData()->Decrire(true));
        parcours = parcours->getNext();
    }
    description.append(parcours->getData()->Decrire(true));
    return description;
}//----- Fin Decrire

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose()
// Algorithme : Constructeur
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetComposee>" << endl;
#endif

} //----- Fin de TrajeCompose

TrajetCompose::~TrajetCompose()
// Algorithme : Destructeur
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetComposee>" << endl;
#endif

} //----- Fin de ~TrajetComposee

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es