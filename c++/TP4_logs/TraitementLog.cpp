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
#include "Traitement.h"
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
    string line, offset;
    cout<<"veuillez rentrer le offset que vous voulez enlever à l'adresse de la source"<<endl;
    cin>>offset
    while (!file.eof())
    {
        getline(file, line);
        Traitement traitementLigne=Traitement(line);
        if(traitementLigne.section[8]=="200")
        {
            //on mettra dans referer l'adresse de la source en enlevant l'offset porposé par l'utilisateur
            string referer=traitementLigne.section[10].substr(offset.size(),traitementLigne.section[10].size());
            addGraphe(referer, traitementLigne.section[6]);
            addHits(traitementLigne.section[6]);
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
