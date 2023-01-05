/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "Linkedlist.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool rechercheCombi(const char* depart, const char* arrivee, bool display)const;
    // Mode d'emploi :
    // Cette méthode va combiner aux maximun deux trajets afin de subvenir
    // aux paramètres rentrés notamment, la ville de départ et la ville d'arrivée
    //
    // Contrat :
    //


    bool recherche(const char* depart, const char* arrivee)const;
    // Mode d'emploi :
    // Cette méthode va nous permettre de rechercher les différents
    // trajets dans notre catalogue en prenant comme paramètre la ville de départ et la ville d'arrivée
    //
    // Contrat :
    //
    void Importer_parIntervalle(const string namefile);
    // Mode d'emploi :
    // Importer tous les trajets existant dans le fichier en prenant en
    //compte l'intervalle indiqué par l'utilisateur
    // Contrat: le fichier doit exister dans le répertoire de travail ou le chemin d'accèes bien
    //structuré
    //

    void Importer();
    // Mode d'emploi :
    // cette méthode est juste une interface qui permet à l'utilisateur de choisir le type d'importation
    // Contrat: le fichier doit exister dans le répertoire de travail ou le chemin d'accèes bien
    //structuré
    //

    void Importer_parChoix(string namefile);
    // Mode d'emploi :
    // Importer tous les trajets existant dans le fihcier en prenant en
    //compte les choix de l'utilisateur (la ville de départ et/ou arrivée )
    //de choisir le type de chargement qu'il désire (trjaets composés et/ou simples)
    // Contrat: le fichier doit exister dans le répertoire de travail ou le chemin d'accèes bien
    //structuré
    //

    void Importer_parCritere(string namefile);
    // Mode d'emploi :
    // Importer tous les trajets existant dans le fihcier CSV
    //et les placés dans le Catalogue, cette méthode permet à l'utilisateur
    //de choisir le type de chargement qu'il désire (trjaets composés et/ou simples)
    // Contrat: le fichier "Catalogue.csv" doit exister dans le répertoire de travail
    //

    void Afficher();
    // Mode d'emploi :
    // Affiche tous les trajets trier par ordre alphabétique
    // des villes de départs dans le catalogue.
    //L'affichage indique aussi d'il s'agit de trajet composé ou de
    //trajet simple en utilisant les codess suivant
    // TC: trajet composé
    // TS: trajet simple
    // Contrat :
    //

    void Interface();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void  AjouterSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void  AjouterCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    Catalogue ( );
    // Mode d'emploi :
    // Création de la classe Catalogue
    //
    // Contrat :
    //PAS DE CONTRAT

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //PAS DE CONTRAT


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    Linkedlist trajets;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H