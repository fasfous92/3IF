/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//GETTERS,SETTERS
char* TrajetCompose::getvillea()const
{
    Cell* c=compo.getCell();
    return     c[compo.getnbcurrent()].getData()->getvillea();

}
char* TrajetCompose::getvilled()const
{
    Cell* c=compo.getCell();
    return     c[0].getData()->getvilled();

}



//--Fin GETTERS,SETTERS
void TrajetCompose::AjouterTrajet(const Trajet* t)
// Algorithme :
{
        compo.Ajouter(t);
        Cell* c=compo.getCell();
        depart=c[0].getData()->getvilled();
        arrivee=c[compo.getnbcurrent()].getData()->getvillea();
} //----- Fin de AjouterTrajet

void TrajetCompose::Afficher() const
// Algorithme :
//
{
    int i=0;
    while(compo.getCell()->getNext()!=NULL){
        compo.getCell()->getData()->Afficher(); //on va afficher le trajet (simple ou composé)
       i++;
    }
} //----- Fin Afficher



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetComposee>" << endl;
#endif
    compo=unTrajetCompose.compo;

} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetComposee>" << endl;
#endif
    compo=Linkedlist(); // on va juste initiliser la liste puis après selon le nombre d'étapes à rajoutées on va appeler la méthode ajouter.
} //----- Fin de TrajeCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetComposee>" << endl;
#endif
} //----- Fin de ~TrajetComposee


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
