/*************************************************************************
                           Trajet  -  description
                             -------------------
    d�but                : $21-11-2022$
    copyright            : (C) $2022$ par $Bin�me3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------

#if !defined(TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Trajet>
// Une classe abstraite parent de TrajetSimple et TrajetCompos�
//
//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- M�thodes publiques
    virtual void Afficher() const = 0;
    // Mode d'emploi :
    // Affichage des d�tails d'un trajet
    // Contrat :
    // PAS DE CONTRAT

    virtual const char *getvilled() const = 0;
    // Mode d'emploi :
    // retourne la ville de d�part d'un trajet
    // Contrat :
    // PAS DE CONTRAT

    virtual const char *getvillea() const = 0;
    // Mode d'emploi :
    // retourne la ville d'arriv�e d'un trajet
    // Contrat :
    // PAS DE CONTRAT

    virtual std::string Decrire(bool forTC) const = 0;
    // Mode d'emploi :
    // retourne la description d'un trajet
    // Contrat :
    // PAS DE CONTRAT

    //------------------------------------------------- Surcharge d'op�rateurs

    //-------------------------------------------- Constructeurs - destructeur

    virtual ~Trajet();
    // Mode d'emploi :
    // Destructeur d'un trajet
    // Contrat :
    // PAS DE CONTRAT

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- M�thodes prot�g�es

    //----------------------------------------------------- Attributs prot�g�s
    char *depart;
    char *arrivee;
};

//-------------------------------- Autres d�finitions d�pendantes de <Trajet>

#endif // Trajet_H