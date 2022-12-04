/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined ( LINKEDLIST_H )
#define LINKEDLIST_H

//--------------------------------------------------- Interfaces utilisées
#include "Cell.h"

//------------------------------------------------------------- Constantes
const int INIT=2;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Linkedlist
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //GETTERS,SETTERS
    Cell* getCell()const;
    // Mode d'emploi :
    // retourne la première cellule de la liste
    // Contrat :
    //
    const char* getVillea() const;
    // Mode d'emploi :
    // retourne la ville d'arrivée du dernier trajet de la liste
    // on l'utilise dans la recherche combinée dans Catalogue
    // Contrat :
    //
    const char* getVilled() const;
    // Mode d'emploi :
    // retourne la ville de de départ du premier trajet de la liste
    // on l'utilise dans la recherche combinée dans Catalogue
    // Contrat :
    //
    void setCell(Cell* cell);
    // Mode d'emploi :
    // change la valeur de la première cellule de la liste
    // Contrat :
    //

    //----Fin GETERS,SETTERS

    void Ajouter(const Trajet* t);
    // Mode d'emploi :
    // cette methode va ajouterun trajet à la liste
    // Contrat :
    //

    void tri();
    // Mode d'emploi :
    // cette methode va trier les cellules selon un ordre alphabétique croissant
    // des villes de départ afin de simplifier la lecture de l'affichage
    // pour l'utilisateur.
    // Contrat :
    //

    void Afficher()const;
    // Mode d'emploi :
    // cette méthode va afficher les différents trajets qui composent la liste
    // pour chaque cellule elle va faire appel à la méthode Afficher liée à chaque type de trajet (simple ou composé).
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
    Linkedlist ( const Linkedlist & unLinkedlist );
    // Mode d'emploi (constructeur de copie) :
    // comme Linkedlist est simplement une vue des trajets on copie juste le pointeur
    // pas de copie en profondeur
    // Contrat :
    //

    Linkedlist ();
    // Mode d'emploi :
    // Constructeur de Linkedlist
    // Contrat :
    //

    virtual ~Linkedlist ( );
    // Mode d'emploi :
    // Desructeur de Linkedlist
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Cell *cellule;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // Linkedlist_H