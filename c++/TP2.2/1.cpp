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
#include "1.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Trajet & Trajet::operator = ( const Trajet & unTrajet )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cell>" << endl;
#endif
} //----- Fin de Cell (constructeur de copie)


Trajet::Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif
} //----- Fin de Cell


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cell>" << endl;
#endif
} //----- Fin de Celll


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
