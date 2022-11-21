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
Trajet Cell::getData() const
// Algorithme :
//
{
} //----- Fin de Méthode

Cell getNext() const
// Algorithme :
//
{
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Cell::Cell ( const Cell & unCell )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Cell>" << endl;
    #endif
    next=new Cell[1];
    data=unCell.data;
    next=unCell.next;
} //----- Fin de Cell (constructeur de copie)

Cell::Cell ( Trajet unTrajet )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Cell>" << endl;
    #endif
    next=new Cell[1];
    data=unTrajet;
    next=nullptr;
} //----- Fin de Cell 

Cell::Cell ( Trajet unTrajet, Cell nextCell )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Cell>" << endl;
    #endif
    next=new Cell[1];
    data=unTrajet;
    next=nextCell;
} //----- Fin de Cell 


Cell::Cell ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Cell>" << endl;
    #endif
    data=nullptr;
    next = new Cell[1];
    next=nullptr;
} //----- Fin de Cell


Cell::~Cell ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <Cell>" << endl;
    #endif
    delete[] next;
} //----- Fin de ~Cell


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

