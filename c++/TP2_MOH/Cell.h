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
    Trajet getData() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    Cell getNext() const;
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    

//-------------------------------------------- Constructeurs - destructeur
    Cell ( const Cell & unCell );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cell ( Trajet unTrajet, Cell nextCell )
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cell::Cell ( Trajet unTrajet )
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cell ( );
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
Trajet data;
Cell * next;
};

//-------------------------------- Autres définitions dépendantes de <Cell>

#endif // Cell_H

