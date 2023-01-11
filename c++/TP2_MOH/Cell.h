/*************************************************************************
                           Cell  -  description
                             -------------------
    d�but                : $21-11-2022$
    copyright            : (C) $2022$ par $Bin�me3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Cell> (fichier Cell.h) ----------------
#if !defined(Cell_H)
#define Cell_H

//--------------------------------------------------- Interfaces utilis�es
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Cell>
// une Cell est un bloc compos� d'un pointeur data qui pointe vers un trjaet
// et un pointeur cell qui pointe vers la racine suivante (afin de simuler une liste chain�e)
//
//------------------------------------------------------------------------

class Cell
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- M�thodes publiques
    Trajet *getData() const;
    // Mode d'emploi :
    // retourne un pointeur vers le trajet contenu dans la racine
    // Contrat :
    // PAS DE CONTRAT

    Cell *getNext() const;
    // Mode d'emploi :
    // retourne un pointeur vers la racine suivante
    // Contrat :
    // PAS DE CONTRAT

    void setNext(const Cell *suivant);
    // Mode d'emploi :
    // change le next d'une racine
    // Contrat :
    //
    void setData(const Trajet *set);
    // Mode d'emploi :
    // cahnge la valeur de data
    // Contrat :
    // PAS DE CONTRAT

    //------------------------------------------------- Surcharge d'op�rateurs

    //-------------------------------------------- Constructeurs - destructeur

    Cell();
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    // PAS DE CONTRAT

    Cell(const Trajet *unTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    // PAS DE CONTRAT

    virtual ~Cell();
    // Mode d'emploi :
    //
    // Contrat :
    // PAS DE CONTRAT

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- M�thodes prot�g�es

    //----------------------------------------------------- Attributs prot�g�s
    Trajet *data;
    Cell *next;
};

//-------------------------------- Autres d�finitions d�pendantes de <Cell>

#endif // Cell_H