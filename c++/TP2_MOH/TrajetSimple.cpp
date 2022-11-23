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

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
///GETTERS, SETTERS
char* TrajetSimple::getvilled()const
{
    return depart;
}
char* TrajetSimple::getvillea()const
{
    return arrivee;

}
//----Fin GETTERS,SETTERS


void TrajetSimple::Afficher() const
// Algorithme :
//
{
    cout << "Trajet Simple = de " << Trajet::depart << " à " << Trajet::arrivee << " en " << transport << endl ;

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
    depart=unTrajetSimple.depart;
    arrivee=unTrajetSimple.arrivee;
    transport=unTrajetSimple.transport;

} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
    depart=new char [30];
    arrivee=new char [30];
    transport=new char [30];
    fscanf(stdin,"%99s %99s %99s",depart,arrivee,transport);

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
    delete [] transport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

