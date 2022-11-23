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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Cell::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Cell & Cell::operator = ( const Cell & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Cell::Cell (const Cell & unXxx )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cell>" << endl;
#endif
} //----- Fin de Cell (constructeur de copie)


Cell::Cell ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif
} //----- Fin de Cell


Cell::~Cell ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cell>" << endl;
#endif
} //----- Fin de ~Cell


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
