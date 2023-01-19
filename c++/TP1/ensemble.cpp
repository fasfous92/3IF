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
unsigned int Ensemble:: Intersection(const Ensemble & unEnsemble){
    int i,j;
    int retirer;
    unsigned int count=0;
       if(EstInclus(unEnsemble)==INCLUSION_LARGE || EstInclus(unEnsemble)==INCLUSION_STRICTE) {
           Ajuster(-nbelem);
           return 0;
       }else{
           for(j=0;j<nbcurrent;j++){
                for(i=0;i<unEnsemble.nbcurrent;i++){
                    if(unEnsemble.elem[i]==elem[j]){
                        count++;
                    }
                }
            }
           retirer=nbcurrent-count;
           for(j=0;j<nbcurrent;j++) {
               bool b=false;
               for (i = 0; i < unEnsemble.nbcurrent; i++) {

                   if(elem[j]==unEnsemble.elem[i]){
                       b=true;
                   }
               }
               if(!b){
                   Retirer(elem[j]);
                   j--;
               }
           }
       }
    return retirer;
}

int Ensemble:: Reunir(const Ensemble & unEnsemble) {
    if (EstInclus(unEnsemble) == INCLUSION_LARGE) {
        return 0;
    }
    int i, j;
    int count=0;
    int add=0;
    for(i=0;i<unEnsemble.nbcurrent;i++){
        for(j=0;j<nbcurrent;j++){
            if(unEnsemble.elem[i]==elem[j]){
                count++;
            }
        }
    }
    add=unEnsemble.nbcurrent-count;
    int ncapacity=nbcurrent+add;
    if(ncapacity<=nbelem){
        for(i=0;i<unEnsemble.nbcurrent;i++){
            if(Ajouter(unEnsemble.elem[i])) {
            }
        }
        return add;
    } else{
        Ajuster(ncapacity-nbelem);
        for(i=0;i<unEnsemble.nbcurrent;i++){
            if(Ajouter(unEnsemble.elem[i])) {

            }
        }

        return -add;
    }


}
unsigned int Ensemble:: Retirer(const Ensemble & unEnsemble){
    int stock=nbelem;
    int i;
    unsigned int res=0;

    for(i=0;i<unEnsemble.nbcurrent;i++){
            if(Retirer(unEnsemble.elem[i])){
                res++;
                i--;
            }

    }
    Ajuster(stock-nbelem);
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

