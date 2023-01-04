/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <stdbool.h>
#include <fstream>
#include <vector>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques




bool Catalogue::rechercheCombi(const char* depart, const char* arrivee, bool display) const
//Algorithme:
{

    bool excuse=false;
    if(!display)
        cout << "Trajets combinés possibles:\n";

    int i = 1;
    Cell *parcours = trajets.getracine();
    Cell *parcours2 = trajets.getracine();
    Trajet *t = parcours->getData();
    Trajet *tnext = parcours2->getData();
    while (parcours != nullptr) {
        t = parcours->getData();
        if(::strcmp(t->getvilled(),depart)==0 && ::strcmp(t->getvillea(),arrivee)==0) { //ce if va simuler la fonctionnalité d'une recherche de simple trajets
            t->Afficher();
            return true;
        }
        if(strcmp(t->getvillea(), arrivee) == 0) {
            return excuse;
        }
        if (strcmp(t->getvilled(), depart) == 0) {
            while (parcours2 != nullptr) {
                tnext = parcours2->getData();
                if (strcmp(t->getvillea(), tnext->getvilled()) == 0){
                    if(!display) {
                        cout << "Solution" << i << ":\n";
                        t->Afficher();
                    }
                    tnext->Afficher();
                    if(strcmp(tnext->getvillea(), arrivee) != 0) {
                        rechercheCombi(tnext->getvilled(),arrivee,true); //on déja afficher le trajet tnext

                    }else{
                       excuse=true;
                    }
                    i++;
                    break;
                }
                parcours2 = parcours2->getNext();
            }
        }
        parcours = parcours->getNext();
        parcours2 = trajets.getracine();
    }
    return excuse;


}//--Fin-rechercheCombi





bool Catalogue::recherche(const char* depart, const char* arrivee)const{
    bool b=false;
    Cell* parcours= trajets.getracine();
    Trajet* t=parcours->getData();
    while (parcours->getNext()!= nullptr){
        if(strcmp(depart,t->getvilled())==0 && strcmp(arrivee,t->getvillea())==0){
            t->Afficher();
            b=true;
        }
        parcours=parcours->getNext();
        t=parcours->getData();
    }
    if(strcmp(depart,t->getvilled())==0 && strcmp(arrivee,t->getvillea())==0){ //on vérifie si la dernière racine vérifie nos conditions
        t->Afficher();
        b=true;
    }

    if(!b){
        cout<<"Trajet pas trouver."<<endl;
        cout<<"vous n'avez pas trouver votre trajet, essayez notre nouvel outils de combinaisons de trajets\n"
              "en faisant une recherche combinatoire\n"<<endl;
    }
    return b;

}

void Catalogue:: Importer()
// Algorithme:
{
    //créer un pointeur fichier
    ifstream file;
    //on accède au fichier.csv
    file.open("text.txt");

    if(file) {
        vector<string> row;
        string line,word;
        TrajetCompose *t; // on le crée dans le cas où on en aura besoin
        while (!file.eof()){
            row.clear(); //effacer les données qui sont dans row

            getline(file,line); //récuperer une ligne de file dans la string line
            stringstream  s(line); //on va separer la ligne en plusieurs mots
            while (getline(s,word,';')) //permet de mettre un mot de s dans word
            {
                row.push_back(word); //va stocker la valeur de word dans le vector de string row
            }
            if(strcmp(row[0].c_str(),"Type")==0){
                //afin que la fonction stoi ne déclenche pas d'erreur pour la premièrer ligne
            }else {

                int n = stoi(row[0]);
                switch (n) {
                    case 1: { ; //la ligne représente un trajet simple
                        TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                        trajets.Ajouter(aAjouter);
                        cout << "Ajouté" << endl;
                        break;
                    }
                    case 2: { ; //la ligne représente un trajet composé
                        t = new TrajetCompose(); //on crée un trajet composé et on attends qu'il soit charger par les instructions suivantes
                        trajets.Ajouter(t); // on le rajoute à notre Catalogue
                        break;
                    }
                    case 3: { ;//trajet simple qui compose le trajet composé déjà initié
                        TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                        t->AjouterTrajet(aAjouter);
                        cout << "Ajouté dans composé" << endl;
                        break;
                    }
                    default : {
                        break;
                    }
                }
            }
        }

    }

    else {
        cerr<<"Erreur d'ouverture de <Catalogue.csv>"<<endl;
    }







} //fin--Importer


void Catalogue :: Afficher()
// Algorithme :
{
    trajets.tri();
    if(trajets.getracine()->getData() != nullptr){
        trajets.Afficher();
    }
} //----- Fin de Méthode

void Catalogue :: AjouterSimple()
// Algorithme :
{
    char depart[20];
    char arrivee[20];
    char transport[20];

    fscanf(stdin,"%99s %99s %99s",depart,arrivee,transport);
    TrajetSimple *aAjouter = new TrajetSimple(depart,arrivee,transport);
    trajets.Ajouter(aAjouter);
    cout<<"Ajouté"<<endl;
} //----- Fin de Méthode

void Catalogue :: AjouterCompose()
// Algorithme :
{
    char lecture[100];
    TrajetCompose* monTrajet=new TrajetCompose();
    trajets.Ajouter(monTrajet);
    printf("menu ajout trajet composé:\n");
    printf("\t1: ajouter un nouveau trajet simple \n");
    printf("\t0: fin ajout trajet composé\n");

    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"0")!=0) {

        if (strcmp(lecture,"1")==0) {
            char depart[20];
            char arrivee[20];
            char transport[20];

            fscanf(stdin,"%99s %99s %99s",depart,arrivee,transport);
            TrajetSimple *aAjouter = new TrajetSimple(depart,arrivee,transport);
            if(monTrajet->AjouterTrajet(aAjouter)==0){
                delete aAjouter;
            }
        }else if (strcmp(lecture,"0")==0) {

        }
        printf("menu ajout trajet composé:\n");
        printf("\t1: ajouter un nouveau trajet simple \n");
        printf("\t0: fin ajout trajet composé\n");

        fscanf(stdin,"%99s",lecture);
    }
} //----- Fin de Méthode

void Catalogue :: Interface()
// Algorithme :
{
    char lecture[100];

    printf("menu:\n");
    printf("\t1: affichage\n");
    printf("\t2: ajouter un trajet simple\n");
    printf("\t3: ajouter un trajet composé\n");
    printf("\t4: recherche de parcours\n");
    printf("\t5: recherche combinatoire\n");
    printf("\t6: Importer le Catalogue \n");
    printf("\t0: quitter\n");

    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"0")!=0) {


        if (strcmp(lecture,"1")==0) {
            Afficher();
        }else if (strcmp(lecture,"2")==0) {
            AjouterSimple();
        }else if (strcmp(lecture,"6")==0) {
            Importer();
        }else if (strcmp(lecture,"3")==0) {
            AjouterCompose();
        }else if (strcmp(lecture,"4")==0) {
            printf("veuillez rentrer la ville de départ ainsi que la ville d'arrivée\n");
            char depart[20];
            char arrivee[20];
            fscanf(stdin,"%99s %99s",depart,arrivee);
            recherche(depart,arrivee);
        }else if (strcmp(lecture,"5")==0) {
            printf("veuillez rentrer la ville de départ ainsi que la ville d'arrivée\n");
            char depart[20];
            char arrivee[20];
            fscanf(stdin,"%99s %99s",depart,arrivee);
            if(!rechercheCombi(depart,arrivee, false)) {
                cout<<"On essaie de trouver une solution\n";
                for(int i=0;i<10;i++) {
                    cout<<"----------\n";
                }
                cout << "Combinaisons de trajets pas disponible dans notre réseaux, cependant vous pouvez\n";
                cout << "voir les propositions ci-dessus afin de vous rapprocher de votre destination\n ";
            }

        }else if (strcmp(lecture,"0")==0) {
        }
        printf("menu:\n");
        printf("\t1: affichage\n");
        printf("\t2: ajouter un trajet simple\n");
        printf("\t3: ajouter un trajet composé\n");
        printf("\t4: recherche de parcours\n");
        printf("\t5: recherche combinatoire\n");
        printf("\t6: Importer le Catalogue \n");
        printf("\t0: quitter\n");

        fscanf(stdin,"%99s",lecture);
    }
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
// delete trajets;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
