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
    //


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

    TrajetCompose (char* depart, char* arrivee);
    // Mode d'emploi : cette methode va demander à l'utilisateur:
    // "veuillez rentrer le nombre de trajet qui compose votre trajet"
    // "pour le trajet n à ajouter:
    //   1 trajet simple
    //   2 trajet composé"
    // et après on va implémenter le constructeur selon le type choisi
    // cette implémentation va être répeter pour chaque trajet censé être rajouté
    // Contrat :
    //

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
