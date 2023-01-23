//
// Created by ysidhom on 11/01/23.
//

#ifndef ANNUAIRE_H
#define ANNUAIRE_H
#include "abonne.h"
#include "map"
#include "list"

class annuaire {
private:

    typedef multimap<string ,renseignement> Tdico;
    Tdico pageblanche;

public:
    void ajouter(const abonne & a);
    void ajouter(const string & nomfichier);
    void ajouter(const string nom="", ostream & f=cout);

    list <abonne> RechercheInv(const string & tel)const;
    void sauvegarder(const string & nomfichier);
    annuaire(const string & nomfichier="");
    void Afficher(const string & nom,ostream & f)const;






};


#endif //TD4_ANNUAIRE_H
