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
void Cell::setNext(Cell* suivant){
    next=suivant;
}
void Cell::setData(Trajet* set) {
    data=set;
}
Trajet* Cell::getData() const
// Algorithme :
//
{
    return data;
} //----- Fin de Méthode

Cell* Cell::getNext() const
// Algorithme :
//
{
    return next;
} //----- Fin de Méthode

//-----End Getters/setters

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Cell::Cell ( const Cell & unCell )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Cell>" << endl;
    #endif
    data=unCell.data;
    next=unCell.next;
} //----- Fin de Cell (constructeur de copie)

Cell::Cell ( Trajet* unTrajet )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Cell>" << endl;
    #endif
    data=unTrajet;
    next=nullptr; //le next vers Null car on les pas encore liée cela peut être modifier avec un setter
} //----- Fin de Cell 

Cell::Cell ( Trajet* unTrajet, Cell nextCell )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Cell>" << endl;
    #endif
    data=unTrajet;
    next=&nextCell;
} //----- Fin de Cell 

Cell::Cell()
//ALgoritme
{

#ifdef MAP
    cout << "Appel au constructeur de copie de <Cell>" << endl;
#endif
    data= nullptr;
    next= nullptr;
}



Cell::~Cell ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <Cell>" << endl;
    #endif
    delete[] next;
    delete[] data;
} //----- Fin de ~Cell


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

