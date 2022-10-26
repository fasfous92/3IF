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
void Ensemble:: tri(){

    int p;
    for(int i=0;i<nbcurrent;i++){
        p=i;
        for(int j=0;j<nbcurrent;j++){
            if(elem[j]>elem[p]){
                p=j;
            }
            int m=elem[p];
            elem[p]=elem[i];
            elem[i]=m;
        }
        
    }

}

bool Ensemble::EstEgal(const Ensemble & unEnsemble)const  {
	int j;
	int i;
	bool b;
if(unEnsemble.nbcurrent==0 && nbcurrent==0){
	return true;
    }
    if(nbcurrent!= unEnsemble.nbcurrent){
        return false;
    }    

    for(i=0;i<nbcurrent;i++){
        b=false;
        for(j=0;j<nbcurrent;j++){
            if(elem[i]==unEnsemble.elem[j]){
                b=true;
            }  
        }
        if(b==false){
        	return false;
        }
    }
    return true;

}

crduEstInclus Ensemble:: EstInclus(const Ensemble & unEnsemble)const
{
    int i,j;


    if(EstEgal(unEnsemble)){
        return INCLUSION_LARGE ;
    }

    if(nbcurrent>unEnsemble.nbcurrent){
        return NON_INCLUSION;
    }else{
            for(i=0;i<nbcurrent;i++){
                bool b=false;
                for(j=0;j<unEnsemble.nbcurrent;j++){
                    if(elem[i]==unEnsemble.elem[j]){
                    b=true;
                    }
                }
                if(!b){
                    return NON_INCLUSION;
                }
            }
    }
    return INCLUSION_STRICTE;
}


crduAjouter Ensemble:: Ajouter(int aAjouter){
    int i;
    for(i=0;i<nbcurrent;i++){
        if(elem[i]==aAjouter){
            return DEJA_PRESENT;
        }
    }

    if(nbcurrent+1>nbelem){
        return PLEIN;
    }else{
        elem[nbcurrent]=aAjouter;
        nbcurrent++;
        return AJOUTE;
    }
}

unsigned  int Ensemble:: Ajuster(int delta){
    int i;
    int *t;
    if(delta==0){
        return nbelem;
    }else if(delta>0){
        t=new int[nbelem+delta];
        for(i=0;i<nbcurrent;i++){
            t[i]=elem[i];
        }
        delete elem;
        elem=t;
        nbelem=nbelem+delta;
        return nbelem;
    }
    if(delta<0){
        if(nbelem+delta>=nbcurrent){
            t=new int[nbelem+delta];
            for(i=0;i<nbcurrent;i++){
                t[i]=elem[i];
            }
            delete elem;
            elem=t;
            nbelem=nbelem+delta;
            return nbelem;
        }else if(nbelem+delta>=0 && (nbelem+delta)<nbcurrent){
            t=new int[nbcurrent];
            for(i=0;i<nbcurrent;i++){
                t[i]=elem[i];
            }
            delete elem;
            elem=t;
            nbelem=nbcurrent;
            return  nbelem;
        }
    }
    return nbelem;
}
int Ensemble:: Reunir(const Ensemble & unEnsemble){
    if(EstInclus(unEnsemble)==INCLUSION_LARGE){
        return 0;
    }
    int i,j;
    int count;
    int add;
    for(i=0;i<nbcurrent;i++){
        for(j=0;j<unEnsemble.nbcurrent;j++){
            if(elem[i]==unEnsemble.elem[j]){
                count;
            }
        }
    }
    add=unEnsemble.nbcurrent-count;
    if(add==0){
        return 0;
    }
    if((nbcurrent+add)>nbelem){
        Ajuster((nbcurrent+add)-nbelem);
        int indice=nbcurrent;
        for(j=0;j<unEnsemble.nbcurrent;j++){
            if(Retirer(unEnsemble.elem[j])==false){
                    elem[indice]=unEnsemble.elem[j];
                    indice++;
            }
        }
        nbcurrent=nbcurrent+indice;
        return (-add);
    } else {
        int indice=nbcurrent;
        for (i = 0; i < nbcurrent; i++) {
            for (j = 0; j < unEnsemble.nbcurrent; j++) {
                if (elem[i] == unEnsemble.elem[j]) {
                    elem[indice] = unEnsemble.elem[j];
                    indice++;
                }
            }
        }
        nbcurrent=nbcurrent+indice;
        return add;
    }




}
unsigned int Ensemble:: Retirer(const Ensemble & unEnsemble){
    int stock=nbelem;
    int stock2=unEnsemble.nbelem;
    int i;
    unsigned int res=0;
    int nb[unEnsemble.nbelem];

    for(i=0;i<stock2;i++){
        nb[i]=unEnsemble.elem[i];
    }



    for(i=0;i<unEnsemble.nbcurrent;i++){
            if(Retirer(nb[i])== true){
                res++;
            }

    }
    nbelem=stock;
    return res;
}

bool Ensemble::Retirer(int element) {
    int i;
    int indice=0;
    for(i=0;i<nbcurrent;i++){
        if(elem[i]==element){
            int a=elem[i];
            elem[i]=elem[nbcurrent-1];
            elem[nbcurrent-1]=a;
            nbcurrent--;
            Ajuster((-nbelem));
            return true;
        }
    }
    Ajuster((-nbelem));
    return false;
}









void Ensemble :: Afficher()
//Algorithme:
//
{   
        
    tri();

    cout<<nbcurrent;
    cout<<"\r\n";
    cout<<nbelem;
    cout<<"\r\n";
    cout<<"{";
    for(int i=0;i<nbcurrent;i++){
        cout<<*(elem+i);
        if(i!=nbcurrent-1){
        cout<<",";
        }
    }
    cout<<"}\r\n";



      
} //-----Fin de Afficher


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble ( int *t , unsigned int nbelems){
    elem=new int[nbelems];
    nbelem=nbelems;
    bool b=true;
    int nb=0;
    int j;
    unsigned int i;
    
    for(i=0;i<nbelems;i++){
        for(int j=0;j<nb;j++){
            if(*(elem+j)==t[i]){
                b=false;
            }
        }
        if(b){
            *(elem+nb)=t[i];
            nb++;
        }else{
            b=true;
        }
    }
    nbcurrent=nb;

}




Ensemble::Ensemble ( unsigned int cardMax= CARD_MAX):nbcurrent(0), nbelem(cardMax)
// Algorithme :
//
{   if(cardMax!=0){
    elem=new int[cardMax];
   
} else {
    elem=NULL;
}
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
} //----- Fin de EnsembleFin de Ensemble


Ensemble::~Ensemble ( )
// Algorithme :
//
{
        delete elem;
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

