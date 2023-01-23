/*************************************************************************
                           TraitementLog  -  description
                             -------------------
    début                : 16/01/2023$
    copyright            : (C) 2023$ par ${AUTHOR}$
    e-mail               : ${EMAIL}$
*************************************************************************/

//---------- Réalisation de la classe <${ TraitementLog}> (fichier TraitementLog.cpp.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

#include <iostream>
#include <stdbool.h>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "TraitementLog.h"
#include "Traitement.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TraitementLog::addGraphe(string referer,string cible)
// Algorithme :
//
{
    if(!graphe.count(make_pair(referer,cible))) graphe[make_pair(referer,cible)]=1;
    else graphe[make_pair(referer,cible)]++;
} //Fin addGraphe

void TraitementLog::addHits( string cible)
// Algorithme :
//
{
    if(!hits.count(cible)) hits[cible]=1;
    else hits[cible]++;
} //Fin addGraphe

void TraitementLog::addNodes(string cible,int& ordre)
// Algorithme :
//
{
    if(!nodes.count(cible)) {
        nodes[cible] = ordre;
        ordre++;
    }

}//Fin addNodes

void TraitementLog::makeHitsInverse()
// Algorithme :
//
{
    map<string,int>::iterator it;
    for(it=hits.begin();it!=hits.end();it++){
        hitsInverse.insert(make_pair(it->second,it->first));
    }
}// End afficherHits

void TraitementLog::makeDot(string fileName)
// Algorithme :
//
{
    ofstream file(fileName);
    if(!file){
        cout<<"Erreur ouverture de <"<<fileName<<">"<<endl;
        return;
    }
    file<<"digraph{"<<endl;
    map<string,int>::iterator it1;
    for(it1=nodes.begin();it1!=nodes.end();it1++){
        file<<"node"<<it1->second<<" [label=\""<<it1->first<<"\"];"<<endl;
    }
    map<pair<string,string>,int>::iterator it;
    for(it=graphe.begin();it!=graphe.end();it++){
        file<<"node"<<nodes[it->first.first]<<" -> node"<< nodes[it->first.second]<<" [label=\""<<it->second<<"\"];"<<endl;
    }
    file<<"}"<<endl;
    cout<<"Dot-file "<<fileName<<" generated"<<endl;
    file.close();
}// End afficherGraphe


void TraitementLog::afficherHitsInverse()
// Algorithme :
//
{
    multimap<int,string>::iterator it;
    int nb=0;
    for(it=hitsInverse.begin();it!=hitsInverse.end();it++){
        cout<<it->second<<" ("<<it->first<<" hits)"<<endl ;
        nb++;
        if(nb==10) break;
    }
}// End afficherHits

void TraitementLog::lire()
// Algorithme :
//
{
    ifstream file;
    file.open(fileName);
    if(!file) {
        cout << "erreur ouverture du fichier";
        file.close();
        return;
    }
    string line, offset;
    /*cout<<"veuillez rentrer le offset que vous voulez enlever à l'adresse de la source"<<endl;
    cin>>offset;*/
    offset="http://intranet-if.insa-lyon.fr";
    int ordre=0 ,heureLog;
    string extension  =".html";
    while (!file.eof())
    {
        getline(file, line);
        if(line=="") break;
        Traitement traitementLigne=Traitement(line);
        if(traitementLigne.section.size()<=11) continue;
        if(traitementLigne.section[8]=="200")
        {
            //on mettra dans referer l'adresse de la source en enlevant l'offset porposé par l'utilisateur
            string referer;
            if(traitementLigne.section[10].find(offset)!= std::string::npos)
                referer=traitementLigne.section[10].substr(offset.size(),traitementLigne.section[10].size());
            else
                referer=traitementLigne.section[10];

            string cible=traitementLigne.section[6];
            heureLog = traitementLigne.trouveHeure();

            if(doExclure && cible.find(extension)==std::string::npos) continue;
            
            if(heure==-1 || heureLog==heure) {
                addGraphe(referer, cible); //ajouter dans le graphe
                addHits(cible); //ajouter dans hits
                addNodes(cible, ordre);
                addNodes(referer, ordre);
            }
        }
    }
    file.close();
    makeHitsInverse();
}//Fin lire


void TraitementLog::execute(){
    lire();
    if(doGraphe) makeDot("court.dot");
    afficherHitsInverse();
    cout<<endl;
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
TraitementLog::~TraitementLog()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TraitementLog>" << endl;
#endif
}//----- Fin de ~TraitementLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
