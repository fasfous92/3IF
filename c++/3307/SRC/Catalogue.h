/*************************************************************************
                           Catalogue  -  description
                             -------------------
     début                : $21-11-2022$
    copyright            :  (C) $2022$ par $Binôme3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
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
// la mise en place d'une interface userfriendly afin de faciliter la manipulation
// de notre application. Cette Class, stocke les trajets qui composent notre réseaux,
// elle permet aussi à l'utilisateur de raliser des recherhces de parcours et d'afficher
// le contenu du Catalogue 
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