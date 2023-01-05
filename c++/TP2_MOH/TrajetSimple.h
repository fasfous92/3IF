/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    d�but                : $21-11-2022$
    copyright            : (C) $2022$ par $Bin�me3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TrajetSimple_H )
#define TrajetSimple_H

//--------------------------------------------------- Interfaces utilis�es
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Cr�er et g�rer un trajet simple d'une ville A vers une ville B en utilisant un moyen de transport d�termin�
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- M�thodes publiques
    virtual void Afficher() const;
    // Mode d'emploi :
    //  Affiche un texte qui r�sume le voyage
    // Contrat :
    //

    const char* getvilled() const;
    // Mode d'emploi :
    //  retourne  la ville de d�part du trajet simple
    // Contrat :
    //

    const char* getvillea() const;
    // Mode d'emploi :
    // retourne  la ville d'arriv�e du trajet simple
    // Contrat :
    //

    const char* getTransport() const;
    // Mode d'emploi :
    //  retourne  le moyen de transport du trajet simple
    // Contrat :
    //

    virtual std::string Decrire(bool forTC=false) const;



//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

    TrajetSimple(const std::string* vDepart, const std::string* vArrivee, const std::string* mTransport);
    // Mode d'emploi :
    //  surcharge du Constructeur d'un trajet simple utile afin de pouvoir importer les trajets d'un fichier
    // Contrat :
    //

    TrajetSimple(const char* vDepart, const char* vArrivee, const char* mTransport);
    // Mode d'emploi :
    //  Constructeur d'un trajet simple � partir d'une ville de d�part, une ville d'arriv�e et un moyen de transport
    // Contrat :
    //

    virtual ~TrajetSimple();
    // Mode d'emploi :
    // Destructeur
    // Contrat :
    //



//------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- M�thodes prot�g�es

    //----------------------------------------------------- Attributs prot�g�s
    char* transport;
};

//-------------------------------- Autres d�finitions d�pendantes de <TrajetSimple>

#endif // TrajetSimple_H