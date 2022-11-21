/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>

//------------------------------------------------------------- Constantes
const int CARD_MAX=5;
enum crduEstInclus{ NON_INCLUSION,INCLUSION_LARGE,INCLUSION_STRICTE};
enum crduAjouter{DEJA_PRESENT, PLEIN, AJOUTE};

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
// la classe ensemble est un ensemble  de nombre dans la défintion mathématiques du termes
// (pas de doublons et pas d'odre).
//
//------------------------------------------------------------------------

class Ensemble
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher();
//Methode d'emploi:
// on ne met pas const car on va modifier l'ensemble avant de
// l'affihcer
//contrat:
//
    bool EstEgal(const Ensemble & unEnsemble) const ;
//Methode d'emploi:
// Methode const qui reçoit un const et renvoie vrai
// si les deux élements sont égaux
//
//contrat:
//
    crduEstInclus EstInclus(const Ensemble & unEnsemble) const;
    unsigned int Ajuster(int delta);
    crduAjouter   Ajouter(int aAjouter);
    bool Retirer(int element);
    unsigned int Retirer(const Ensemble & unEnsemble);
    int Reunir (const Ensemble & unEnsemble);
    unsigned int Intersection (const Ensemble &unEnsemble);
//------------------------------------------------- Surcharge d'opérateurs
    Ensemble & operator = (const Ensemble & unEnsemble );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Ensemble (int t[], unsigned int nbElements);
    // Mode d'emploi (constructeur de copie) :
    //on doit transformer un tableau en un ensemble (pas de doublons)
    // Contrat :
    //

    Ensemble (unsigned int cardMax);
    // Mode d'emploi :
    //on va créer un tableau de la taille demendée en paramétre (si pas de paramètre, on met CARDMAX)
    //et on intilize les autres attributs
    // Contrat :
    // le paramètre rentré doit être >=0 (d'où unsigned int)
    //

    virtual ~Ensemble ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
unsigned int capacity; //capacity maximal
int nbelem; //nombre d'element présent dans l'ensemble
int* elem; // tableau où on stocke les nombres
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H

