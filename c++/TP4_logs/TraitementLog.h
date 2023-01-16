/*************************************************************************
                           TraitementLog  -  description
                             -------------------
    début                : 16/01/2023
    copyright            : (C) 2023$ par FAYALA Mohamed
    e-mail               : fayalla.mohamed@gmail.com
*************************************************************************/

//---------- Interface de la classe <TraitementLog> (fichier TraitementLog.h) ----------------
#ifndef TraitementLog_H
#define  TraitementLog_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <cstring>
#include <stdbool.h>
#include <fstream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TraitementLog>
//
//
//------------------------------------------------------------------------



class TraitementLog  {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void addGraphe(string referer,string cible);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void addHits(string cible);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void lire(string filename);
    // Mode d'emploi :
    //
    // Contrat :
    //



    //------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
    TraitementLog(string name,bool g=false,bool e=false,bool h=false):fileName(name),doGraphe(g),doExclure(e),doHeure(h){};
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TraitementLog();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
map<pair<string,string>,int> graphe;
map<string,int> hits;
multimap<int,string> hitsInverse;
bool doGraphe,doExclure,doHeure;
string fileName;

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TraitementLog_H
