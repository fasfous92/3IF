/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Une classe abstraite parent de TrajetSimple et TrajetComposé 
//
//------------------------------------------------------------------------

class Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const =0;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
   // virtual void Recherche() const=0;
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual char* getvilled()const=0;
    virtual char* getvillea()const=0;




//------------------------------------------------- Surcharge d'opérateurs
    
//-------------------------------------------- Constructeurs - destructeur
    //virtual Trajet ( const Trajet & unTrajet )=0;
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    //virtual Trajet ( )=0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    //virtual ~Trajet ( )=0;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char* depart;
char* arrivee;
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // Trajet_H

