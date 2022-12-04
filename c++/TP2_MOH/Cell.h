/*************************************************************************
                           Cell  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Cell> (fichier Cell.h) ----------------
#if ! defined ( Cell_H )
#define Cell_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cell>
//
//
//------------------------------------------------------------------------

class Cell
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Trajet* getData() const;
    // Mode d'emploi :
    // retourne un pointeur vers le trajet contenu dans la cellule
    // Contrat :
    //

    Cell* getNext() const;
    // Mode d'emploi :
    // retourne un pointeur vers la cellule suivante
    // Contrat :
    //

    void setNext(const Cell* suivant);
    // Mode d'emploi :
    // change le next d'une cellule
    // Contrat :
    //
    void setData(const Trajet *set);
    // Mode d'emploi :
    // cahnge la valeur de data
    // Contrat :
    //



//------------------------------------------------- Surcharge d'opérateurs
    

//-------------------------------------------- Constructeurs - destructeur
    Cell ( const Cell & unCell );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cell ( Trajet* unTrajet, Cell * nextCell );
    // Mode d'emploi (constructeur de copie) :
    // ce constructeur est utile afin de rajouter une cellule en un endroit
    // precis (il faut que le nextCell soit donné en paramètre). on opter pour le cell
    // Contrat :
    //

    Cell ( );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cell ( const Trajet* unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cell ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
Trajet* data;
Cell * next;
};

//-------------------------------- Autres définitions dépendantes de <Cell>

#endif // Cell_H