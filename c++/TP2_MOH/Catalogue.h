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
    void rechercheCombi(const char* depart, const char* arrivee, bool display,  Linkedlist* monTrajet)const;
    // Mode d'emploi :
    // Cette méthode va combiner les trajets afin de subvenir
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

    void Afficher();
    // Mode d'emploi :
    // Affiche tous les trajets triés par ordre alphabétique
    // des villes de départs dans le catalogue.
    // L'affichage indique aussi s'il s'agit de trajet composé ou de
    // trajet simple en utilisant les codess suivant
    // TC: trajet composé
    // TS: trajet simple
    // Contrat :
    //

    void Interface();
    // Mode d'emploi :
    //
    // Contrat :
    // C'est l'interface de notre catalogue qui contient le menu des tâches proposées

    void  AjouterSimple();
    // Mode d'emploi :
    // permet à l'utilisateur de saisir la ville de départ, la ville d'arrivée ainsi que le moyen de transport
    // pour un trajet simple puis crée le trajet simple et le rajoute dans la liste des trajets du catalogue
    // Contrat :
    //

    void  AjouterCompose();
    // Mode d'emploi :
    // crée un trajet composé et le rajoute dans la liste des trajets du catalogue
    // puis affiche le menu spécifique à l'ajout d'un trajet composé qui donne le choix à l'utilisateur
    // soit de rajouter un trajet simple au trajet composé (une étape du trajet composé)
    // soit de mettre fin à la saisie du trajet composé
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
Linkedlist trajets;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H
