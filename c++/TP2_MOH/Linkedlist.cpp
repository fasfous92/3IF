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
{
    return cellule;
}


void Linkedlist::setCell(Cell* cell)
{
    cellule=cell;
}

//--Fin GETTERS,SETTERS

void Linkedlist::Ajouter(const Trajet *t)
{

    if(cellule->getData()==nullptr){
        cellule->setData(t);
        return;
    }


    Cell* parcours=cellule;
    while(parcours->getNext()!=nullptr){
        parcours=parcours->getNext();
    }

    Cell* aAjouter = new Cell(t);
    parcours->setNext(aAjouter);

}//--Fin Ajouter

void Linkedlist::tri()
// Algorithme :
{
    Cell* parcours=cellule;
    while (parcours->getNext()!= nullptr){
        Cell* next=parcours->getNext();
        if(strcmp(parcours->getData()->getvilled(),next->getData()->getvilled())>0){
            Trajet* tmp=parcours->getData();
            parcours->setData(next->getData());
            next->setData(tmp);
        }
        parcours=next;
    }

}//----Fin Tri

void Linkedlist::Afficher()const
// Algorithme :
//
{
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
// Algorithme :
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
// Algorithme :
//
{
#ifdef MAP
        cout << "Appel au destructeur de <Xxx>" << endl;
#endif
        cellule = new Cell();


} //----- Fin de ~Linkedlist


    Linkedlist::~Linkedlist ( )
// Algorithme :
//
    {
#ifdef MAP
        cout << "Appel au destructeur de <Linkedlist>" << endl;
#endif
        delete cellule;
      /*if(cellule->getNext()== nullptr){
          delete cellule;
      } else {
          Cell *parcours = cellule;
          Cell *parcours2 = cellule->getNext();
          while (parcours2 != nullptr) {
              delete parcours;
              parcours=parcours2;
              parcours2=parcours2->getNext();
          }
          delete parcours;
      }*/
    } //----- Fin de ~Linkedlist




//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


