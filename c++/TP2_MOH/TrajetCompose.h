/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    d�but                : $21-11-2022$
    copyright            : (C) $2022$ par $Bin�me3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if !defined(TrajetCompose_H)
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilis�es
#include <string>
#include <cstring>
#include "LinkedList.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TrajetCompose>
// cette Classe va cr�er/g�rer/repertorier les trajets compos�s
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- M�thodes publiques
    // GETTERS,SETTERS
    virtual const char *getvillea() const;
    // Mode d'emploi:
    // Retourne le ville d'arriv�e du trajet compos�
    //
    // Contrat:
    // PAS DE CONTRAT

    virtual const char *getvilled() const;
    // Mode d'emploi:
    // Retourne le ville de d�part du trajet compos�
    //
    // Contrat:
    // PAS DE CONTRAT

    //--Fin GETTERS,SETTERS

    int AjouterTrajet(const Trajet *t);
    // Mode d'emploi:
    // Ajouter un trajet � notre trajet compos� tout en v�rifiant de la faisabilit� de cet ajout:
    // on v�rifie s'il s'agit du premier trajet � rajouter, si c'est le cas on peut ajouter
    // sinon on doit v�rifier la correspondence des villes.
    // cette m�thode retourne 1 si l'ajout a �t� r�aliser sinon 0
    //
    // Contrat:
    // PAS DE CONTRAT

    virtual void Afficher() const;
    // Mode d'emploi :
    // Cette m�thode va afficher la ville de d�part de notre premi�re �tape ainsi
    // que la ville d'arriv�e de la derni�re �tape. Etant donn� que le trajet compos�
    // peut avoir plusieurs moyens de transport on a d�cider de ne pas afficher les modes de
    // transport.
    // Contrat :
    // PAS DE CONTRAT

    virtual std::string Decrire(bool forTC = true) const;
    // Mode d'emploi :
    // 1ere ligne d�crit le trajet compos� en g�n�ral : ville de d�part et ville d'arriv�e (pas de moyen de transport
    //  parcourt la liste des trajets qui composent le trajet compos� et rajoute au string la description de chaque trajet
    // Contrat :
    // PAS DE CONTRAT

    //------------------------------------------------- Surcharge d'op�rateurs

    //-------------------------------------------- Constructeurs - destructeur

    TrajetCompose();
    // Mode d'emploi : cette methode va demander � l'utilisateur:
    // cette m�thode va cr�er un Trajet compos� vide et apr�s
    // on demandera � l'utilisateur de rajouter les �tapes qui composent
    // ce trajet (avec la methode AjouterTrajet).
    // Contrat :
    // PAS DE CONTRAT

    virtual ~TrajetCompose();
    // Mode d'emploi :
    //
    // Contrat :
    // PAS DE CONTRAT

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- M�thodes prot�g�es

    //----------------------------------------------------- Attributs prot�g�s
    Linkedlist compo; // cette Linkedlist va indiquer les diff�rents trajets qui compose notre trajet initial.
};

//-------------------------------- Autres d�finitions d�pendantes de <TrajetCompose>

#endif // TrajetCompose_H