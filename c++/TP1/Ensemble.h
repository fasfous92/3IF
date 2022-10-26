/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
const int CARD_MAX=5;
enum crduEstInclus{NON_INCLUSION,INCLUSION_LARGE,INCLUSION_STRICTE};
enum crduAjouter{DEJA_PRESENT,PLEIN,AJOUTE};

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class Ensemble 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void tri();
    bool EstEgal(const Ensemble & Ensemble)const ;
    crduEstInclus EstInclus(const Ensemble & unEnsemble)const;
    void Afficher(void);
    crduAjouter Ajouter(int aAjouter);
    unsigned  int Ajuster(int delta);
    bool Retirer(int element);
    unsigned int Retirer(const Ensemble & unEnsemble);
    int Reunir(const Ensemble & unEnsemble);
        // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Ensemble & operator = ( const Ensemble & unEnsemble );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Ensemble ( int *t, unsigned int nbElements);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Ensemble (unsigned int card );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Ensemble ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
int *elem;
unsigned int nbelem;
int nbcurrent;

};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H

