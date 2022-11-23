/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Simple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Simple & Simple::operator = ( const Simple & unSimple )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Simple::Simple ( const Simple & unSimple )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)


Simple::Simple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
} //----- Fin de Simple


Simple::~Simple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Simple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
