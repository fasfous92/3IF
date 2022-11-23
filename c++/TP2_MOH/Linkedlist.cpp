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
void Linkedlist::tri()
// Algorithme :
{
    int indice;
    char* min;
    for(int i=0;i<nbcurrent;i++) {
        min = cellule[i].getData()->getvilled();
        indice = i;
        for (int j = i + 1; j < 6; j++) {
            char *current = cellule[j].getData()->getvilled();
            if (min > current) {
                min = current;
                indice = j;
            }
        }
        if (indice != i) {
            Cell tmp = cellule[i];
            cellule[indice] = cellule[i];
            cellule[i] = tmp;
        }
    }

}//----Fin Tri

void Linkedlist::Afficher()const
// Algorithme :
//
{
    int i=0;
    while (cellule[i].getNext()!=NULL){
        cellule[i].getData()->Afficher(); //selon le type du trajet (simple/composé) on aurait une methode afficher qui adaptée (virtual)
        i++;
    }
} //----- Fin Afficher

Cell* Linkedlist::getCell() const
//Algorithme :
{
 return cellule;
}







//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Linkedlist::Linkedlist ( const Linkedlist & unLinkedlist )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
    nbmax=unLinkedlist.nbmax;
    cellule=unLinkedlist.cellule;

} //----- Fin de Linkedlist (constructeur de copie)



Linkedlist::Linkedlist ( unsigned int init=INIT): nbmax(INIT), nbcurrent(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
    cellule=new Cell * [nbmax];


} //----- Fin de ~Linkedlist


Linkedlist::~Linkedlist ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Linkedlist>" << endl;
#endif
    delete[] cellule;
} //----- Fin de ~Linkedlist




//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Linkedlist::Ajustertaille(){
    nbmax=nbmax*2;
    realloc(cellule,nbmax);
}

