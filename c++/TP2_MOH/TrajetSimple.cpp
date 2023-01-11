/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    d�but                : $21-11-2022$
    copyright            : (C) $2022$ par $Bin�me3307$
    e-mail               : youssef.sidhom@insa-lyon.fr/mohamed.fayala@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <cstring>
#include <string>

#pragma warning(disable : 4996)

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

void TrajetSimple::Afficher() const
// Algorithme : M�thode simple
//
{
    cout << "TS de " << depart << " � " << arrivee << " en " << transport << endl;
}

const char *TrajetSimple::getvilled() const
// Algorithme : M�thode simple
//
{
    return depart;
}

const char *TrajetSimple::getvillea() const
// Algorithme : M�thode simple
//
{
    return arrivee;
}

const char *TrajetSimple::getTransport() const
// Algorithme : M�thode simple
//
{
    return transport;
}

string TrajetSimple::Decrire(bool forTC) const
// Algorithme : M�thode simple
//
{
    string description;
    if (!forTC)
        description.append("1;"); // on met 1 si c'est un trajet simple ind�pendant
    else
        description.append("3;"); // on met 3 si c'est un trajet simple qui est une �tape d'un trajet compos�
    description.append(depart);
    description.append(";");
    description.append(arrivee);
    description.append(";");
    description.append(transport);
    description.append("\n");
    return description;
}

//------------------------------------------------- Surcharge d'op�rateurs

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char *vDepart, const char *vArrivee, const char *mTransport)
// Algorithme : M�thode simple
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    depart = new char[strlen(vDepart) + 1];
    arrivee = new char[strlen(vArrivee) + 1];
    transport = new char[strlen(mTransport) + 1];
    strcpy(depart, vDepart);
    strcpy(arrivee, vArrivee);
    strcpy(transport, mTransport);
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple(const string *vDepart, const string *vArrivee, const string *mTransport)
// Algorithme : M�thode simple
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    depart = new char[vDepart->length() + 1];
    arrivee = new char[vArrivee->length() + 1];
    transport = new char[mTransport->length() + 1];
    strcpy(depart, vDepart->c_str());
    strcpy(arrivee, vArrivee->c_str());
    strcpy(transport, mTransport->c_str());
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
// Algorithme : M�thode simple
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete[] arrivee;
    delete[] depart;
    delete[] transport;
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es