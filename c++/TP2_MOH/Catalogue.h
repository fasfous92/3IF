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
    void AfficherSimples();
    // Mode d'emploi :
    //  Affiche tous les trajets simples dans le catalogue
    // Contrat :
    //

    void AfficherComposes();
    // Mode d'emploi :
    // Affiche tous les trajets composés dans le catalogue
    // Contrat :
    //

    void Afficher();
    // Mode d'emploi :
    // Affiche tous les trajets dans le catalogue
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
    Linkedlist trajetsSimples;
    Linkedlist trajetsComposes;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H