/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const
// Algorithme :
//
{
    cout << "TS de " << depart << " à " << arrivee << " en " << transport << endl ;
}

const char* TrajetSimple::getvilled() const
// Algorithme :
//
{
    return depart;
}

const char* TrajetSimple::getvillea() const
// Algorithme :
//
{
    return arrivee;
}

const char* TrajetSimple::getTransport() const
// Algorithme :
//
{
    return transport;
}


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    #endif
    depart=new char[strlen(unTrajetSimple.depart)+1];
    arrivee=new char[strlen(unTrajetSimple.arrivee)+1];
    transport=new char[strlen(unTrajetSimple.transport)+1];
    strcpy(depart,unTrajetSimple.depart);
    strcpy(arrivee,unTrajetSimple.arrivee);
    strcpy(transport,unTrajetSimple.transport);

} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple (const char * vDepart ,const char * vArrivee ,const  char * mTransport )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
    depart=new char[strlen(vDepart)+1];
    arrivee=new char[strlen(vArrivee)+1];
    transport=new char[strlen(mTransport)+1];
    strcpy(depart,vDepart);
    strcpy(arrivee,vArrivee);
    strcpy(transport,mTransport); 
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
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

//----------------------------------------------------- Méthodes protégées

