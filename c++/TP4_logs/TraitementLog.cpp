/*************************************************************************
                           TraitementLog  -  description
                             -------------------
    début                : 16/01/2023$
    copyright            : (C) 2023$ par ${AUTHOR}$
    e-mail               : ${EMAIL}$
*************************************************************************/

//---------- Réalisation de la classe <${ TraitementLog}> (fichier TraitementLog.cpp.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

#include <iostream>
#include <stdbool.h>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "TraitementLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TraitementLog::addGraphe(string referer,string cible)
// Algorithme :
//
{
    if(!graphe.count(make_pair(referer,cible))) graphe[make_pair(referer,cible)]=1;
    else graphe[make_pair(referer,cible)]++;
} //Fin addGraphe

void TraitementLog::addHits( string cible)
// Algorithme :
//
{
    if(!hits.count(cible)) hits[cible]=1;
    else hits[cible]++;
} //Fin addGraphe

void TraitementLog::lire(string filename)
// Algorithme :
//
{
    ifstream file;
    file.open(fileName);
    string line;
    while (!file.eof())
    {
        getline(file, line);
        // je dois la passer à travers Traitement
        // Traitement traitementLigne (line);
        if(traitementLigne.section[13]=="200")
        {
            string referer=traitementLigne.section[15];
            addGraphe(traitementLigne.section[15], traitementLigne.section[11]);
            addHits(traitementLigne.section[11]);
        }
    }
}//Fin lire

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
TraitementLog::~TraitementLog()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TraitementLog>" << endl;
#endif
}//----- Fin de ~TraitementLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
