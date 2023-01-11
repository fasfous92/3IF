/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined ( ABONNE_H )
#define ABONNE_H


//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "iostream"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct renseignement {
    string prenom;
    string adresse;
    string tel;
    renseignement (string p="", string ad="",string telep=""):
        prenom(p),adresse(ad),tel(telep) {}
}  ;





//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class abonne
{
//----------------------------------------------------------------- PRIVATE
private:
string nom;
renseignement info;


//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    abonne & operator = ( const abonne & unabonne );
    // Mode d'emploi :
    //
    // Contrat :
    //
    abonne & operator >>(istream & is, abonne & a);
    // Mode d'emploi :
    //
    // Contrat :
    //
    abonne & operator <<(ostream & os, abonne & a);
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend istream & operator>>(istream &, abonne &);
    friend ostream & operator<<(ostream &, const abonne &);// just to permit cin and cout to access to the private attributes
    friend class annuaire;


//-------------------------------------------- Constructeurs - destructeur
    abonne ( const abonne & unabonne );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    abonne(string name="", renseignement r=renseignement());
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~abonne( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés



};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // abonne_H
