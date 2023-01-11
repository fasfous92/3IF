/*************************************************************************
                           Linkedlist  -  description
                             -------------------
    d�but                : $21-11-2022$
    copyright            : (C) $2022$ par $Bin�me3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Linkedlist> (fichier Linkedlist.h) ----------------
#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H

//--------------------------------------------------- Interfaces utilis�es
#include "Cell.h"

//------------------------------------------------------------- Constantes
const int INIT = 2;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Linkedlist>
// Linkedlist est une liste chainee qui pointe vers la premi�re racine
// celle-ci peut contenir des trajets
//
//------------------------------------------------------------------------

class Linkedlist
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- M�thodes publiques

    // GETTERS,SETTERS
    Cell *getracine() const;
    // Mode d'emploi :
    // retourne la premi�re racine de la liste
    // Contrat :
    // PAS DE CONTRAT
    //
    const char *getVillea() const;
    // Mode d'emploi :
    // retourne la ville d'arriv�e du dernier trajet de la liste
    // on l'utilise dans la recherche combin�e dans Catalogue
    // Contrat :
    // PAS DE CONTRAT
    //
    const char *getVilled() const;
    // Mode d'emploi :
    // retourne la ville de de d�part du premier trajet de la liste
    // on l'utilise dans la recherche combin�e dans Catalogue
    // Contrat :
    // PAS DE CONTRAT
    //
    void setracine(Cell *cell);
    // Mode d'emploi :
    // change la valeur de la premi�re racine de la liste
    // Contrat :
    // PAS DE CONTRAT
    //

    //----Fin GETERS,SETTERS

    void Ajouter(const Trajet *t);
    // Mode d'emploi :
    // cette methode va ajouter un trajet � la liste
    // Contrat :
    // PAS DE CONTRAT
    //

    void tri();
    // Mode d'emploi :
    // cette methode va trier les cellules selon un ordre alphab�tique croissant
    // des villes de d�part afin de simplifier la lecture de l'affichage
    // pour l'utilisateur.
    // Contrat :
    // PAS DE CONTRAT
    //

    void Afficher() const;
    // Mode d'emploi :
    // cette m�thode va afficher les diff�rents trajets qui composent la liste
    // pour chaque racine elle va faire appel � la m�thode Afficher li�e � chaque type de trajet (simple ou compos�).
    // Contrat :
    // PAS DE CONTRAT
    //

    std::string Decrire() const;
    // Mode d'emploi :
    // cette m�thode va cr�er un string qui content une description des trajets contenus dans une LinkedList selon
    // la convention qu'on a choisi :
    // {1,2,3};ville de d�part;ville d'arriv�e;moyen de transport
    // 1 si trajetSimple
    // 2 si trajetCompos�
    // 3 si trajetSimple qui constitue un trajetCompos�
    // Contrat :
    // PAS DE CONTRAT
    //

    //------------------------------------------------- Surcharge d'op�rateurs

    //-------------------------------------------- Constructeurs - destructeur

    Linkedlist();
    // Mode d'emploi :
    // Constructeur de Linkedlist
    // Contrat :
    //

    virtual ~Linkedlist();
    // Mode d'emploi :
    // Desructeur de Linkedlist
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- M�thodes prot�g�es

    //----------------------------------------------------- Attributs prot�g�s
    Cell *racine;
};

//-------------------------------- Autres d�finitions d�pendantes de <Xxx>

#endif // Linkedlist_H