/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Linkedlist> (fichier Linkedlist.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Linkedlist.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Linkedlist::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode



// GETTERS,SETTERS

Cell* Linkedlist::getCell() const
// Algorithme : Méthode simple
{
    return cellule;
}

const char* Linkedlist::getVillea() const
// Algorithme : Méthode simple
{
    if(cellule->getData()==nullptr) return ""; // si liste vide

    Cell* parcours=cellule;
    while (parcours->getNext()!= nullptr){
        parcours=parcours->getNext();
    }
    return     parcours->getData()->getvillea();
}

const char* Linkedlist::getVilled() const
// Algorithme : Méthode simple
{
    return cellule->getData()->getvilled();
}

void Linkedlist::setCell(Cell* cell)
// Algorithme : Méthode simple
{
    cellule=cell;
}

//--Fin GETTERS,SETTERS

void Linkedlist::Ajouter(const Trajet *t)
// Algorithme : Méthode simple
{
    // cas où la liste est vide
    if(cellule->getData()==nullptr){
        cellule->setData(t);
        return;
    }

    // cas où la liste n'est pas vide : rajouter le nouveau trajet à la fin
    Cell* parcours=cellule;
    while(parcours->getNext()!=nullptr){
        parcours=parcours->getNext();
    }

    Cell* aAjouter = new Cell(t);
    parcours->setNext(aAjouter);

}//--Fin Ajouter

void Linkedlist::tri()
// Algorithme : Tri par selection
{
    Cell* parcours=cellule;
    Cell* parcours2=cellule;
    while(parcours2!=nullptr){
        while (parcours!= nullptr){
            if(strcmp(parcours->getData()->getvilled(),parcours2->getData()->getvilled())<0){
                Trajet* tmp=parcours->getData();
                parcours->setData(parcours2->getData());
                parcours2->setData(tmp);
            }
            parcours=parcours->getNext();
        }
        parcours2=parcours2->getNext();
        parcours=parcours2;

    }

}//----Fin Tri

void Linkedlist::Afficher()const
// Algorithme : Méthode simple
//
{
    if(cellule->getData()==nullptr){
        return;
    }

    if (cellule->getNext() == nullptr) {
        cellule->getData()->Afficher();// si notre Linekdlist n'a qu'une seule cellule on va juste l'afficher
    } else { // sinon on doit afficher chaque cellule de notre liste en parcourant les cellules.
        Cell *parcours = cellule;
        while (parcours->getNext() != nullptr) {
            parcours->getData()->Afficher(); //selon le type du trajet (simple/composé) on aurait une methode afficher qui adaptée (virtual)
            parcours = parcours->getNext();
        }
        parcours->getData()->Afficher(); //on va afficher la dernière cellule
    }
}//----- Fin Afficher


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Linkedlist::Linkedlist(const Linkedlist &unLinkedlist)
// Algorithme :  Méthode simple
//
{
    #ifdef MAP
            cout << "Appel au constructeur de copie de <Xxx>" << endl;
    #endif
    cellule = new Cell;
    cellule->setData(unLinkedlist.cellule->getData());
    cellule->setNext(unLinkedlist.cellule->getNext());

} //----- Fin de Linkedlist (constructeur de copie)


Linkedlist::Linkedlist()
// Algorithme :  Méthode simple
//
{
    #ifdef MAP
            cout << "Appel au destructeur de <Xxx>" << endl;
    #endif
    cellule = new Cell();


} //----- Fin de ~Linkedlist


Linkedlist::~Linkedlist ( )
// Algorithme :  Méthode simple
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <Linkedlist>" << endl;
    #endif
    delete cellule;
} //----- Fin de ~Linkedlist


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

