/*************************************************************************
                           Catalogue  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if !defined(Catalogue_H)
#define Catalogue_H

//--------------------------------------------------- Interfaces utilis�es
#include "LinkedList.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- M�thodes publiques
    bool rechercheCombi(const char *depart, const char *arrivee, bool display) const;
    // Mode d'emploi :
    // Cette m�thode va combiner aux maximun deux trajets afin de subvenir
    // aux param�tres rentr�s notamment, la ville de d�part et la ville d'arriv�e
    //
    // Contrat :
    //

    bool recherche(const char *depart, const char *arrivee) const;
    // Mode d'emploi :
    // Cette m�thode va nous permettre de rechercher les diff�rents
    // trajets dans notre catalogue en prenant comme param�tre la ville de d�part et la ville d'arriv�e
    //
    // Contrat :
    //

    void Importer_parIntervalle(std::ifstream &file);
    // Mode d'emploi :
    // Importer tous les trajets existant dans le fichier en prenant en
    // compte l'intervalle indiqu� par l'utilisateur
    // Contrat: le fichier doit exister dans le r�pertoire de travail ou le chemin d'acc�es bien
    // structur�
    //

    void Importer();
    // Mode d'emploi :
    // cette m�thode est juste une interface qui permet � l'utilisateur de choisir le type d'importation
    // Contrat: le fichier doit exister dans le r�pertoire de travail ou le chemin d'acc�es bien
    // structur�
    //

    void Importer_parChoix(std::ifstream &file);
    // Mode d'emploi :
    // Importer tous les trajets existant dans le fihcier en prenant en
    // compte les choix de l'utilisateur (la ville de d�part et/ou arriv�e )
    // de choisir le type de chargement qu'il d�sire (trjaets compos�s et/ou simples)
    // Contrat: le fichier doit exister dans le r�pertoire de travail ou le chemin d'acc�es bien
    // structur�
    //

    void Importer_parCritere(std::ifstream &file);
    // Mode d'emploi :
    // Importer tous les trajets existant dans le fihcier
    // et les plac�s dans le Catalogue, cette m�thode permet � l'utilisateur
    // de choisir le type de chargement qu'il d�sire (trjaets compos�s et/ou simples)
    // Contrat: le fichier "Catalogue.csv" doit exister dans le r�pertoire de travail
    //

    void Afficher();
    // Mode d'emploi :
    // Affiche tous les trajets trier par ordre alphab�tique
    // des villes de d�parts dans le catalogue.
    // L'affichage indique aussi d'il s'agit de trajet compos� ou de
    // trajet simple en utilisant les codess suivant
    // TC: trajet compos�
    // TS: trajet simple
    // Contrat :
    //

    void Interface();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjouterCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Exporter();
    // Mode d'emploi :
    // Ouvre le fichier ofstream où on va sauvegarder les trajets
    // Si aucun problème n'est rencontré le menu qui permet à l'utilisateur de choisir le type de sauvegade est affiché
    // Contrat :
    //

    void Exporter_parChoix(std::ofstream &fout);
    // Mode d'emploi :
    // permet à l'utilistaeur de choisir une sauvgarde par ville de départ et/ou ville d'arrivée
    // Contrat :
    //

    void Exporter_parCritere(std::ofstream &fout);
    // Mode d'emploi :
    //  permet à l'utilistaeur de choisir une sauvgarde par trajet simple et/ou trajet commposé
    // Contrat :
    //

    void Exporter_parIntervalle(std::ofstream &fout);
    // Mode d'emploi :
    //  permet à l'utilistaeur de choisir une sauvgarde à partir d'un certain rang jusqu'à un autre rang
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'op�rateurs

    //-------------------------------------------- Constructeurs - destructeur

    Catalogue();
    // Mode d'emploi :
    // Cr�ation de la classe Catalogue
    //
    // Contrat :
    // PAS DE CONTRAT

    virtual ~Catalogue();
    // Mode d'emploi :
    //
    // Contrat :
    // PAS DE CONTRAT

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- M�thodes prot�g�es
    Linkedlist trajets;

    //----------------------------------------------------- Attributs prot�g�s
};

//-------------------------------- Autres d�finitions d�pendantes de <Catalogue>

#endif // Catalogue_H