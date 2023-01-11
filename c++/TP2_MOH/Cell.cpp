/*************************************************************************
                           Cell  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Cell> (fichier Cell.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cell.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

// Getters and Setters necessary to deal with our variables from the main
void Cell::setNext(const Cell *suivant)
// Algorithme : M�thode simple
{
    next = (Cell *)suivant;
}
void Cell::setData(const Trajet *set)
// Algorithme : M�thode simple
{
    data = (Trajet *)set;
}

Trajet *Cell::getData() const
// Algorithme : M�thode simple
//
{
    return data;
} //----- Fin de M�thode

Cell *Cell::getNext() const
// Algorithme : M�thode simple
//
{
    return next;
} //----- Fin de M�thode

//-----End Getters/setters

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

Cell::Cell(const Trajet *unTrajet)
// Algorithme : M�thode simple
//
{
#ifdef MAP
    cout << "Appel au constructeur de de <Cell> avec Trajet en param�tre" << endl;
#endif
    data = (Trajet *)unTrajet;
    next = nullptr; // le next vers Null car on les pas encore li�e cela peut �tre modifier avec un setter
} //----- Fin de Cell

Cell::Cell()
// Algorithme : M�thode simple
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif
    data = nullptr;
    next = nullptr;
} //----- Fin de Cell

Cell::~Cell()
// Algorithme : M�thode simple
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cell>" << endl;
#endif
    delete data;
    if (next != nullptr)
        delete next;
} //----- Fin de ~Cell

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es