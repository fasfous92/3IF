/*************************************************************************
                           Xxx  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Linkedlist> (fichier Linkedlist.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Linkedlist.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type Linkedlist::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

// GETTERS,SETTERS

Cell *Linkedlist::getracine() const
// Algorithme : M�thode simple
{
    return racine;
}

const char *Linkedlist::getVillea() const
// Algorithme : M�thode simple
{
    if (racine->getData() == nullptr)
        return ""; // si liste vide

    Cell *parcours = racine;
    while (parcours->getNext() != nullptr)
    {
        parcours = parcours->getNext();
    }
    return parcours->getData()->getvillea();
}

const char *Linkedlist::getVilled() const
// Algorithme : M�thode simple
{
    return racine->getData()->getvilled();
}

void Linkedlist::setracine(Cell *cell)
// Algorithme : M�thode simple
{
    racine = cell;
}

//--Fin GETTERS,SETTERS

void Linkedlist::Ajouter(const Trajet *t)
// Algorithme : M�thode simple
{
    // cas o� la liste est vide
    if (racine->getData() == nullptr)
    {
        racine->setData(t);
        return;
    }

    // cas o� la liste n'est pas vide : rajouter le nouveau trajet � la fin
    Cell *parcours = racine;
    while (parcours->getNext() != nullptr)
    {
        parcours = parcours->getNext();
    }

    Cell *aAjouter = new Cell(t);
    parcours->setNext(aAjouter);

} //--Fin Ajouter

void Linkedlist::tri()
// Algorithme : Tri par selection
{
    Cell *parcours = racine;
    Cell *parcours2 = racine;
    while (parcours2 != nullptr)
    {
        while (parcours != nullptr)
        {
            if (strcmp(parcours->getData()->getvilled(), parcours2->getData()->getvilled()) < 0)
            {
                Trajet *tmp = parcours->getData();
                parcours->setData(parcours2->getData());
                parcours2->setData(tmp);
            }
            parcours = parcours->getNext();
        }
        parcours2 = parcours2->getNext();
        parcours = parcours2;
    }

} //----Fin Tri

void Linkedlist::Afficher() const
// Algorithme : M�thode simple
//
{
    if (racine->getData() == nullptr)
    {
        return;
    }

    if (racine->getNext() == nullptr)
    {
        racine->getData()->Afficher(); // si notre Linekdlist n'a qu'une seule racine on va juste l'afficher
    }
    else
    { // sinon on doit afficher chaque racine de notre liste en parcourant les cellules.
        Cell *parcours = racine;
        while (parcours->getNext() != nullptr)
        {
            parcours->getData()->Afficher(); // selon le type du trajet (simple/compos�) on aurait une methode afficher qui adapt�e (virtual)
            parcours = parcours->getNext();
        }
        parcours->getData()->Afficher(); // on va afficher la derni�re racine
    }
} //----- Fin Afficher

std::string Linkedlist::Decrire() const
// Algorithme : M�thode simple
//
{
    string res;
    if (racine->getData() == nullptr)
    {
        return res;
    }

    if (racine->getNext() == nullptr)
    {
        res.append(racine->getData()->Decrire(false)); // si notre Linekdlist n'a qu'une seule racine
    }
    else
    {
        Cell *parcours = racine;
        while (parcours->getNext() != nullptr)
        {
            res.append(parcours->getData()->Decrire(false)); // selon le type du trajet (simple/compos�) on aurait une methode decrire qui adapt�e (virtual)
            parcours = parcours->getNext();
        }
        res.append(parcours->getData()->Decrire(false)); // on va ajouter la description de la derni�re racine
    }
} //----- Fin Decrire

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

Linkedlist::Linkedlist()
// Algorithme :  M�thode simple
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Linkedlist>" << endl;
#endif
    racine = new Cell();

} //----- Fin de ~Linkedlist

Linkedlist::~Linkedlist()
// Algorithme :  M�thode simple
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Linkedlist>" << endl;
#endif
    delete racine;
} //----- Fin de ~Linkedlist

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
