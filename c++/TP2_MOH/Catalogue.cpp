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
    string namefile;
    printf("\tVeuillez rentrer le nom du fichier\n");
    cin>>namefile;
    string typeimport;
    printf("\tVeuillez choisir le type d'importation\n");
    printf("\t1:Import_parChoix (nom des villes)\n");
    printf("\t2:Import_parCritere (type de trajet)\n");
    printf("\t3:Import_parIntervalle (choix d'intervalle)\n");
    cin>>typeimport;

    if (strcmp(typeimport.c_str(),"1")==0) {
        Importer_parChoix(namefile);
    }else if (strcmp(typeimport.c_str(),"2")==0) {
        Importer_parCritere(namefile);
    }else if (strcmp(typeimport.c_str(),"3")==0) {
        Importer_parIntervalle(namefile);
    }
}//--Fin- Importer
void Catalogue:: Importer_parIntervalle(const string namefile)
// Algorithme:
{
    int min;
    int max;
    int rownumber=0;
    printf("\tVeuillez préciser l'intervalle à choisir\n");
    printf("\tpour un intervalle [a,b] rentrer→ a b\n");
    cin>>min;
    cin>>max;

    ifstream file;
    //on accède au fichier.csv
    file.open(namefile);

    if(file) {
        vector<string> row;
        string line,word;
        TrajetCompose *t; // on le crée dans le cas où on en aura besoin
        while (!file.eof()){
            row.clear(); //effacer les données qui sont dans row

            getline(file,line); //récuperer une ligne de file dans la string line
            stringstream  s(line); //on va séparer la ligne en plusieurs mots
            while (getline(s,word,';')) //permet de mettre un mot de s dans word
            {
                row.push_back(word); //va stocker la valeur de word dans le vector de string row
            }
            if(stoi(row[0])!=3 || (::strcmp(line.c_str(),"")==0) ){
                rownumber++;
            }
            if(::strcmp(line.c_str(),"")==0 || (rownumber>max && rownumber<min)){
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
                            t = new TrajetCompose(); //on crée un trajet composé et on attend qu'il soit charger par les instructions suivantes
                            trajets.Ajouter(t); // on le rajoute à notre Catalogue
                            break;
                    }
                    case 3: {;//trajet simple qui compose le trajet composé déjà initié
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
        cerr<<"Erreur d'ouverture de <"<<namefile<<">"<<endl;
    }




}//--Fin-Importer_parIntervalle
void Catalogue:: Importer_parChoix(const string namefile)
// Algorithme:
{
    string typeimport;
    string villed;
    string villea;

    bool composing= false; //boolean nécessaire pour indiquer si le trajet simple qui compose un trajet composé, mais n'a pas la même ville de départ doit être charger


    printf("\tVeuillez préciser le type d'import que vous voulez\n");
    printf("\t1: Importer par ville de dpart \n");
    printf("\t2: Importer par ville d'arrivée \n");
    printf("\t3: Importer par ville de départ et ville d'arrivée\n");
    cin>>typeimport;
    //on va vérifier
    if (strcmp(typeimport.c_str(),"1")==0) {
        cin>>villed; //ville départ
    }else if (strcmp(typeimport.c_str(),"2")==0) {
        cin>>villea; //ville arrivée
    }else if (strcmp(typeimport.c_str(),"3")==0) {
        cout<<"veuillez rentrer les villesr"<<endl;
        cin>>villed;
        cin>>villea;
    }

    ifstream file;
    //on accède au fichier.csv
    file.open(namefile);

    if(file) {
        vector <string> row;
        string line, word;
        TrajetCompose *t; // on le crée dans le cas où on en aura besoin
        while (!file.eof()) {
            row.clear(); //effacer les données qui sont dans row

            getline(file, line); //récuperer une ligne de file dans la string line
            stringstream s(line); //on va séparer la ligne en plusieurs mots
            while (getline(s, word, ';')) //permet de mettre un mot de s dans word
            {
                row.push_back(word); //va stocker la valeur de word dans le vector de string row
            }
            if (::strcmp(line.c_str(), "") == 0) {
                //afin que la fonction stoi ne déclenche pas d'erreur pour la premièrer ligne
            } else {

                int n = stoi(row[0]);
                switch (n) {
                    //pour certain
                    case 1: { ; //la ligne représente un trajet simple
                            if (stoi(typeimport) == 1 && row[1] == villed) {
                                TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                                trajets.Ajouter(aAjouter);
                                cout << "Ajouté" << endl;
                                break;
                            } else if (stoi(typeimport) == 2 && row[2] == villea) {
                                TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                                trajets.Ajouter(aAjouter);
                                cout << "Ajouté" << endl;
                                break;
                            } else if (stoi(typeimport) == 2 && row[2] == villea && row[1] == villed) {
                                TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                                trajets.Ajouter(aAjouter);
                                cout << "Ajouté" << endl;
                                break;
                            } else {
                                break;
                            }
                    }

                        case 2: { ; //la ligne représente un trajet composé
                            if (stoi(typeimport) == 1 && row[1] == villed) {
                                t = new TrajetCompose(); //on crée un trajet composé et on attend qu'il soit charger par les instructions suivantes
                                trajets.Ajouter(t); // on le rajoute à notre Catalogue
                                composing = true;
                                break;
                            } else if (stoi(typeimport) == 2 && row[2] == villea) {
                                t = new TrajetCompose(); //on crée un trajet composé et on attend qu'il soit charger par les instructions suivantes
                                trajets.Ajouter(t); // on le rajoute à notre Catalogue
                                composing = true;
                                break;
                            } else if (stoi(typeimport) == 3 && row[2] == villea && row[1] == villed) {
                                t = new TrajetCompose(); //on crée un trajet composé et on attend qu'il soit charger par les instructions suivantes
                                trajets.Ajouter(t); // on le rajoute à notre Catalogue
                                composing = true;
                                break;
                            } else {
                                composing = false;
                                break;
                            }
                        }
                        case 3: { ;//trajet simple qui compose le trajet composé déjà initié
                                if (composing == true) {
                                    TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                                    t->AjouterTrajet(aAjouter);
                                    cout << "Ajouté dans composé" << endl;
                                }
                                break;
                            }
                        }
                    }
                }
            }else {
        cerr<<"Erreur d'ouverture de <"<<namefile<<">"<<endl;
    }
}//fin-Import_parChoix()
void Catalogue:: Importer_parCritere(string namefile)
// Algorithme:
{
    string typeimport;
    bool simple= false; //bolean pour indiquer si l'utilisatuer voudrait que des trajets simples
    bool compose=false; //bolean pour indiquer si l'utilisatuer voudrait que des trajets composé

    printf("\tVeuillez préciser le type d'import que vous voulez\n");
    printf("\t1: Importer tout Catalogue \n");
    printf("\t2: Importer seulement les trajets simples\n");
    printf("\t3: Importer seulement les trajets composés\n");
    cin>>typeimport;
    //on va vérifier
    if (strcmp(typeimport.c_str(),"1")==0) {
        //on fait rien les booleans restent false
    }else if (strcmp(typeimport.c_str(),"2")==0) {
        simple=true;
    }else if (strcmp(typeimport.c_str(),"3")==0) {
        compose=true;
    }


    cout<<"Veuillez rentrer le nom du fichier"<<endl;
   // cin>>namefile;
    //créer un pointeur fichier
    ifstream file;
    //on accède au fichier.csv
    file.open(namefile);

    if(file) {
        vector<string> row;
        string line,word;
        TrajetCompose *t; // on le crée dans le cas où on en aura besoin
        while (!file.eof()){
            row.clear(); //effacer les données qui sont dans row

            getline(file,line); //récuperer une ligne de file dans la string line
            stringstream  s(line); //on va séparer la ligne en plusieurs mots
            while (getline(s,word,';')) //permet de mettre un mot de s dans word
            {
                row.push_back(word); //va stocker la valeur de word dans le vector de string row
            }
            if(::strcmp(line.c_str(),"")==0){
                //afin que la fonction stoi ne déclenche pas d'erreur pour la premièrer ligne
            }else {

                int n = stoi(row[0]);
                switch (n) {
                    case 1: { ; //la ligne représente un trajet simple
                        if(compose== false) {
                            TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                            trajets.Ajouter(aAjouter);
                            cout << "Ajouté" << endl;
                        }
                        break;
                    }
                    case 2: { ; //la ligne représente un trajet composé
                        if(simple==false) {
                            t = new TrajetCompose(); //on crée un trajet composé et on attend qu'il soit charger par les instructions suivantes
                            trajets.Ajouter(t); // on le rajoute à notre Catalogue
                        }
                        break;
                    }
                    case 3: {;//trajet simple qui compose le trajet composé déjà initié
                        if(simple== false) {
                            TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                            t->AjouterTrajet(aAjouter);
                            cout << "Ajouté dans composé" << endl;
                        }
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
        cerr<<"Erreur d'ouverture de <"<<namefile<<">"<<endl;
    }
} //fin--Importer_parCritere


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
            if (trajets.getracine()->getData() == nullptr) {
                cout << "Catalogue vide" << endl;
            }else
            Afficher();
        }else if (strcmp(lecture,"2")==0) {
            AjouterSimple();
        }else if (strcmp(lecture,"6")==0) {
            Importer();
        }else if (strcmp(lecture,"3")==0) {
            AjouterCompose();
        }else if (strcmp(lecture,"4")==0) {
            if (trajets.getracine()->getData() == nullptr) {
                cout << "Catalogue vide" << endl;
            }else{
              printf("veuillez rentrer la ville de départ ainsi que la ville d'arrivée\n");
              char depart[20];
              char arrivee[20];
              fscanf(stdin,"%99s %99s",depart,arrivee);
              recherche(depart,arrivee);
            }
        }else if (strcmp(lecture,"5")==0) {
          if (trajets.getracine()->getData() == nullptr) {
                cout << "Catalogue vide" << endl;
            }else{
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
