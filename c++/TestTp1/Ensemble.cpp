/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble) const{
    bool b=true;
    if(EstEgal(unEnsemble)){
        return INCLUSION_LARGE;
    }else if(nbelem>unEnsemble.nbelem){
        return NON_INCLUSION;
    }
    for(int i=0;i<nbelem;i++){
        b=true;
        for(int j=0;j<unEnsemble.nbelem;j++){
            if(elem[i]==unEnsemble.elem[j]){
                b=false;
                break;
            }
        }
        if(b==true){
            return NON_INCLUSION;
        }
    }
    return INCLUSION_STRICTE;


}//----Fin EstInclus

crduAjouter   Ensemble::Ajouter(int aAjouter){
    for(int i=0;i<nbelem;i++){
        if(elem[i]==aAjouter){
            return DEJA_PRESENT;
        }
    }
    if(nbelem==capacity)
        return PLEIN;
    else{
        elem[nbelem]=aAjouter;
        nbelem++;
        return AJOUTE;
    }
}//---Fin aAjouter
unsigned int Ensemble::Ajuster(int delta){
    if(delta==0){
        return capacity;
    }else if(delta>0){
        capacity+=delta;
        return capacity;
    }else{
        if((capacity+delta)>nbelem){
            capacity+=delta;
            return capacity;
        }else {
            capacity = nbelem;
            return capacity;
        }
    }
}//---Fin Ajuster

bool Ensemble::Retirer(int element){
    for(int i=0;i<nbelem;i++){
        if(elem[i]==element){
            elem[i]=elem[nbelem-1];
            nbelem--;
            Ajuster(-capacity);
            return true;
        }
    }
    return false;


}//---Fin Retirer

unsigned int Ensemble::Retirer(const Ensemble & unEnsemble){
    int res=0;
    for(int i=0;i<unEnsemble.nbelem;i++){
        for(int j=0;j<nbelem;j++){
            if(unEnsemble.elem[i]==elem[j]){
                elem[j]=elem[nbelem-1];
                res++;
                nbelem--;
            }
        }
    }
    return res;
}//---Fin Retirer (Methode de copie)

int Ensemble::Reunir (const Ensemble & unEnsemble){
    int toadd; //le nbr de valeur à rajouter
    int oldelem=nbelem;
    bool b=false;
    for(int i=0;i<unEnsemble.nbelem;i++){
        if(Ajouter(unEnsemble.elem[i])==PLEIN){
            Ajuster(1);
            b= true;
            i--;
        }
    }
    if(b){
        return -(nbelem-oldelem);
    } else
        return (nbelem-oldelem);
}//----Fin Reunir



bool Ensemble::EstEgal(const Ensemble & unEnsemble) const {
    bool b=false;
    if(nbelem!=unEnsemble.nbelem){
        return false;
    }
    for(int i=0;i<nbelem;i++){
        b=false;
        for(int j=0;j<nbelem;j++){
            if(elem[i]==unEnsemble.elem[j]){
                b= true;
                break;
            }
        }
        if(b==false){
            return false;
        }
    }
    return true;
}//----Fin EstEgal

unsigned int Ensemble::Intersection (const Ensemble &unEnsemble){
    int res=0;
    bool b=false;
    if(EstEgal(unEnsemble)){
        return 0;
    }
    for(int i=0;i<nbelem;i++){
        b= false;
        for(int j=0;j<unEnsemble.nbelem;j++) {
            if(elem[i]==unEnsemble.elem[j]){
                b=true;
            }
        }
        if(!b){
            res++;
            Retirer(elem[i]);
        }
    }
    Ajuster(-capacity);
    return res;
}//----Fin Intersection

void Ensemble::Afficher(){
    cout<<nbelem<<endl;
    cout<<capacity<<endl;

    for(int i=0;i<nbelem-1;i++){
        for(int j=i+1;j<nbelem;j++){
            if(elem[i]>elem[j]){
                int tmp=elem[j];
                elem[j]=elem[i];
                elem[i]=tmp;
                break;
            }
        }
    }
    cout<<"{";
    for(int i=0;i<nbelem-1;i++){
        cout<<elem[i]<<",";
    }
    cout<<elem[nbelem-1]<<"}"<<endl;
}//-----Fin Afficher





//------------------------------------------------- Surcharge d'opérateurs
/*Ensemble & Ensemble::operator = (const Ensemble & unEnsemble )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble (int t[], unsigned int nbElements): capacity(nbElements)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ensemble>" << endl;
#endif

    if (nbElements == 0)
        Ensemble(0);
    else {
        elem=new int (nbElements);
        for(int i=0;i<nbElements;i++){
            bool b=true;
            for(int j=0;j<nbelem;j++){
                if(t[i]==elem[j]){
                    b=false;
                    break;
                }
            }
            if(b==true){
                elem[nbelem]=t[i];
                nbelem++;
            }
        }
    }
} //----- Fin de Ensemble (constructeur de copie)


Ensemble::Ensemble (unsigned int cardMax=CARD_MAX): capacity(cardMax), nbelem(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
    if(cardMax!=0)
        elem= new int (cardMax);
    else
        elem=NULL;
} //----- Fin de Ensemble



Ensemble::~Ensemble ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
    delete(elem);
} //----- Fin de Ensemble11


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

