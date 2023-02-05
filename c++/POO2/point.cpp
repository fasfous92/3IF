/*************************************************************************
                           point  -  description
                             -------------------
    début                : 24/01/23$
    copyright            : (C) 2023$ par ${AUTHOR}$
    e-mail               : ${EMAIL}$
*************************************************************************/

//---------- Réalisation de la classe <${ point}> (fichier point.cpp.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

#include <iostream>

//------------------------------------------------------ Include personnel
#include "point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type point::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
point::point(const point &unpoint)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <point>" << endl;
#endif
} //----- Fin de point (constructeur de copie)


// Algorithme :
//


point::~point()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <point>" << endl;
#endif
} //----- Fin de ~point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
