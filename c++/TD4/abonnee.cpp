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
#include "abonne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
abonne & abonne::operator = ( const abonne & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =

abonne & abonne::operator <<(ostream & os,abonne & a){
    os<<nom<<"|"<<info.prenom<<"|"
        <<info.adresse
        <<"|"<<info.tel<<endl;
    return os;
}
abonne & abonne::operator >>(istream & is,abonne & a){
    getline(is,a.nom,"|");
    getline(is,a.info.prenom,"|");
    getline(is,a.info.adresse,"|");
    getline(is,a.info.tel,"|");
    return is;
}

//-------------------------------------------- Constructeurs - destructeur
abonne::abonne(const abonne &unabonne)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)


abonne::abonne(string name="", renseignement r=renseignement()): nom(name), info(r)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
} //----- Fin de Xxx


abonne::~abonne()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
