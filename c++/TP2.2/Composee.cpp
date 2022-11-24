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
#include "Composee.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Composee::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Composee & Composee::operator = ( const Composee & unComposee )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Composee::Composee ( const Composee & unComposee )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cell>" << endl;
#endif
} //----- Fin de Cell (constructeur de copie)


Composee::Composee ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cell>" << endl;
#endif
} //----- Fin de Cell


Composee::~Composee ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Composee>" << endl;
#endif
} //----- Fin de ~Composee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
