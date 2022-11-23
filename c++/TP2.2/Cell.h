/*************************************************************************
                           Cell  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Cell> (fichier Cell.h) ----------------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cell>
//
//
//------------------------------------------------------------------------

class Cell : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Cell & operator = (const Cell & unXxx );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Cell (const Cell & unXxx );
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

};

//-------------------------------- Autres définitions dépendantes de <Cell>

#endif // XXX_H
