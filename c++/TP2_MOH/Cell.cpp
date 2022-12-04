/*************************************************************************
                           Cell  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Cell> (fichier Cell.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cell.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//Getters and Setters necessary to deal with our variables from the main
void Cell::setNext(const Cell* suivant)
// Algorithme : Méthode simple
{
    next=(Cell*)suivant;
}
void Cell::setData(const Trajet *set) 
// Algorithme : Méthode simple
{
    data=(Trajet*)set;
}

Trajet* Cell::getData() const
// Algorithme : Méthode simple
//
{
    return data;
} //----- Fin de Méthode

Cell* Cell::getNext() const
// Algorithme : Méthode simple
//
{
    return next;
} //----- Fin de Méthode

//-----End Getters/setters

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Cell::Cell ( const Cell & unCell )
// Algorithme : Méthode simple
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Cell>" << endl;
    #endif
    data=unCell.data;
    next=unCell.next;
} //----- Fin de Cell (constructeur de copie)

Cell::Cell ( const Trajet* unTrajet )
// Algorithme : Méthode simple
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Cell>" << endl;
    #endif
    data=(Trajet*)unTrajet;
    next=nullptr; //le next vers Null car on les pas encore liée cela peut être modifier avec un setter
} //----- Fin de Cell 

Cell::Cell ( Trajet* unTrajet, Cell * nextCell )
// Algorithme : Méthode simple
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Cell>" << endl;
    #endif
    data=unTrajet;
    next=nextCell;
} //----- Fin de Cell 

Cell::Cell()
// Algorithme : Méthode simple
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Cell>" << endl;
    #endif
    data= nullptr;
    next= nullptr;
}//----- Fin de Cell



Cell::~Cell ( )
// Algorithme : Méthode simple
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <Cell>" << endl;
    #endif
    delete data;
    if(next!=nullptr) delete next;
} //----- Fin de ~Cell


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées