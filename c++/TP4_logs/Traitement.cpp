/*************************************************************************
                           Traitement  -  description
                             -------------------
    début                : 16/01/23$
    copyright            : (C) 2023$ par ${AUTHOR}$
    e-mail               : ${EMAIL}$
*************************************************************************/

//---------- Réalisation de la classe <${ Traitement}> (fichier Traitement.cpp.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Traitement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Traitement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Traitement::Decomposition(const string & line)
// Algorithme :
//
{
    string word;
    stringstream s(line);         // on va séparer la ligne en plusieurs mots
    while (getline(s, word, ' ')) // permet de mettre un mot de s dans word
    {
        section.push_back(word);// va stocker la valeur de word dans le vector de string row
    }


} //----- Fin de Decomposition


//------------------------------------------------- Surcharge d'opérateurs
Traitement &Traitement::operator=(const Traitement &unTraitement)
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Traitement::Traitement(const Traitement &unTraitement)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Traitement>" << endl;
#endif
} //----- Fin de Traitement (constructeur de copie)


Traitement::Traitement(const string & line)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Traitement>" << endl;
#endif
    Decomposition(line);


} //----- Fin de Traitement


Traitement::~Traitement()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Traitement>" << endl;
#endif
} //----- Fin de ~Traitement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
