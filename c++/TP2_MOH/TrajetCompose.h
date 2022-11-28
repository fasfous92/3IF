/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées
#include "Linkedlist.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//cette Classe va créer/gérer/repertorier les trajets composés
//
//------------------------------------------------------------------------

class TrajetCompose: public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :

    //GETTERS,SETTERS
    virtual const char* getvillea()const;
    virtual const char* getvilled()const;




    //--Fin GETTERS,SETTERS
    void AjouterTrajet(const Trajet* t);
    // Mode d'emploi:
    //Ajouter un trajet à notre trajet composé tout en vérifiant de la faisabilité de cet ajout:
    // on vérifie s'il s'agit du premier trajet à rajouter, si c'est le cas on peut ajouter
    // sinon on doit vérifier la correspondence des villes.
    //
    //Contrat:
    //pas de contrat


    virtual void Afficher()const ;
    // Mode d'emploi :
    //cette méthode va afficher les différentes qui compose le trajet composé
    // Contrat :
    //



//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose (const TrajetCompose & unTrajetComposee );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TrajetCompose ();
    // Mode d'emploi : cette methode va demander à l'utilisateur:
    // cette méthode va créer un Trajet composé vide et après
    // on demandera à l'utilisateur de rajouter les étapes qui compose
    // ce trajet (avec la methode AjouterTrajet).
    // Contrat :
    // Aucun

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Linkedlist compo; // cette Linkedlist va indiquer les différents trajets qui compose notre trajet initial.

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H