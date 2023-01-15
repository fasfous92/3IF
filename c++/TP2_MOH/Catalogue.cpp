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
#include <algorithm>
#include <ios>    //used to get stream size
#include <limits> //used to get numeric limits

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

#pragma warning(disable : 4996)
#pragma warning(disable : 4703)

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Catalogue::rechercheCombi(const char *depart, const char *arrivee, bool display) const
// Algorithme:
{

    bool excuse = false;
    if (!display)
        cout << "Trajets combinés possibles:\n";

    int i = 1;
    Cell *parcours = trajets.getracine();
    Cell *parcours2 = trajets.getracine();
    Trajet *t = parcours->getData();
    Trajet *tnext = parcours2->getData();
    while (parcours != nullptr)
    {
        t = parcours->getData();
        if (::strcmp(t->getvilled(), depart) == 0 && ::strcmp(t->getvillea(), arrivee) == 0)
        { // ce if va simuler la fonctionnalité d'une recherche de simple trajets
            t->Afficher();
            return true;
        }
        if (strcmp(t->getvillea(), arrivee) == 0)
        {
            return excuse;
        }
        if (strcmp(t->getvilled(), depart) == 0)
        {
            while (parcours2 != nullptr)
            {
                tnext = parcours2->getData();
                if (strcmp(t->getvillea(), tnext->getvilled()) == 0)
                {
                    if (!display)
                    {
                        cout << "Solution" << i << ":\n";
                        t->Afficher();
                    }
                    tnext->Afficher();
                    if (strcmp(tnext->getvillea(), arrivee) != 0)
                    {
                        rechercheCombi(tnext->getvilled(), arrivee, true); // on déja afficher le trajet tnext
                    }
                    else
                    {
                        excuse = true;
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

} //--Fin-rechercheCombi

bool Catalogue::recherche(const char *depart, const char *arrivee) const
{
    bool b = false;
    Cell *parcours = trajets.getracine();
    Trajet *t = parcours->getData();
    while (parcours->getNext() != nullptr)
    {
        if (strcmp(depart, t->getvilled()) == 0 && strcmp(arrivee, t->getvillea()) == 0)
        {
            t->Afficher();
            b = true;
        }
        parcours = parcours->getNext();
        t = parcours->getData();
    }
    if (strcmp(depart, t->getvilled()) == 0 && strcmp(arrivee, t->getvillea()) == 0)
    { // on vérifie si la dernière racine vérifie nos conditions
        t->Afficher();
        b = true;
    }

    if (!b)
    {
        cout << "Trajet pas trouver." << endl;
        cout << "vous n'avez pas trouver votre trajet, essayez notre nouvel outils de combinaisons de trajets\n"
                "en faisant une recherche combinatoire\n"
             << endl;
    }
    return b;
}

void Catalogue::Importer()
// Algorithme:
{
    string namefile;
    printf("\tVeuillez rentrer le nom du fichier\n");
    cin >> namefile;

    ifstream file;
    // on accède au fichier
    file.open(namefile);

    if (!file)
    {
        cout << "Erreur d'ouverture de <" << namefile << ">" << endl;
        file.close();
        return;
    }

    int typeimport;
    printf("\tVeuillez choisir le type d'importation\n");
    printf("\t1:Import_parChoix (nom des villes)\n");
    printf("\t2:Import_parCritere (type de trajet)\n");
    printf("\t3:Import_parIntervalle (choix d'intervalle)\n");

    while (!(cin >> typeimport) | typeimport > 3 | typeimport < 1)
    {
        cerr << "Veuillez rentrer une numéro entier de 1 à 3" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        printf("\tVeuillez choisir le type d'importation\n");
        printf("\t1:Import_parChoix (nom des villes)\n");
        printf("\t2:Import_parCritere (type de trajet)\n");
        printf("\t3:Import_parIntervalle (choix d'intervalle)\n");
    }
    switch (typeimport)
    {

    case 1:
        // if (typeimport.c_str(), "1") == 0)
        {
            Importer_parChoix(file);
            break;
        }
    case 2:
        // else if (strcmp(typeimport.c_str(), "2") == 0)
        {
            Importer_parCritere(file);
            break;
        }
    case 3:
        // else if (strcmp(typeimport.c_str(), "3") == 0)
        {
            Importer_parIntervalle(file);
            break;
        }
    }
    cout << "Catalogue impporter!!" << endl;
    file.close();

} //--Fin- Importer

void Catalogue::Importer_parIntervalle(ifstream &file)
// Algorithme:
{
    int min;
    int max;
    int rownumber = 0;

    printf("\tVeuillez préciser l'intervalle à choisir\n");
    printf("\tpour un intervalle [a,b] rentrer→ a b\n");
    while (max <= min)
    {
        while (!(cin >> min))
        {
            cerr << "Veuillez rentrer une numéro entier pour la valeur minimale" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
        while (!(cin >> max))
        {
            cerr << "Veuillez rentrer une numéro entier pour la valeur maximale" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        };
        if (min >= max)
            cerr << "veuillez entrer encore une fois vos valeurs tel que a>b" << endl;
    }
    vector<string> row;
    string line, word;
    TrajetCompose *t; // on le crée dans le cas où on en aura besoin
    while (!file.eof())
    {
        row.clear(); // effacer les données qui sont dans row

        getline(file, line);          // récuperer une ligne de file dans la string line
        stringstream s(line);         // on va séparer la ligne en plusieurs mots
        while (getline(s, word, ';')) // permet de mettre un mot de s dans word
        {
            row.push_back(word); // va stocker la valeur de word dans le vector de string row
        }
        if (stoi(row[0]) != 3 || (::strcmp(line.c_str(), "") == 0))
        {
            rownumber++;
        }
        if (::strcmp(line.c_str(), "") == 0 || (rownumber > max || rownumber < min))
        {
            // afin que la fonction stoi ne déclenche pas d'erreur pour la premièrer ligne
        }
        else
        {

            int n = stoi(row[0]);
            switch (n)
            {
            case 1:
            {
                ; // la ligne représente un trajet simple
                TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                trajets.Ajouter(aAjouter);
                cout << "Ajouté" << endl;
                break;
            }
            case 2:
            {
                ;                        // la ligne représente un trajet composé
                t = new TrajetCompose(); // on crée un trajet composé et on attend qu'il soit charger par les instructions suivantes
                trajets.Ajouter(t);      // on le rajoute à notre Catalogue
                break;
            }
            case 3:
            {
                ; // trajet simple qui compose le trajet composé déjà initié
                TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                t->AjouterTrajet(aAjouter);
                cout << "Ajouté dans composé" << endl;
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }

} //--Fin-Importer_parIntervalle

void Catalogue::Importer_parChoix(std::ifstream &file)
// Algorithme:
{
    int typeimport;
    string villed;
    string villea;

    bool composing = false; // boolean nécessaire pour indiquer si le trajet simple qui compose un trajet composé, mais n'a pas la même ville de départ doit être charger

    printf("\tVeuillez préciser le type d'import que vous voulez\n");
    printf("\t1: Importer par ville de départ \n");
    printf("\t2: Importer par ville d'arrivée \n");
    printf("\t3: Importer par ville de départ et ville d'arrivée\n");
    while (!(cin >> typeimport) | typeimport > 3 | typeimport < 1)
    {
        cerr << "Veuillez rentrer une numéro entier de 1 à 3" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        printf("\tVeuillez préciser le type d'import que vous voulez\n");
        printf("\t1: Importer par ville de départ \n");
        printf("\t2: Importer par ville d'arrivée \n");
        printf("\t3: Importer par ville de départ et ville d'arrivée\n");
    }

    switch (typeimport)
    {
        // on va vérifier
    case 1:
        // if (strcmp(typeimport.c_str(), "1") == 0)
        {
            printf("\tveuillez rentrer la ville de départ \n");
            cin >> villed; // ville départ
            break;
        }
    case 2:
        // else if (strcmp(typeimport.c_str(), "2") == 0)
        {
            printf("\tveuillez rentrer la ville d'arrivée' \n");
            cin >> villea; // ville arrivée
            break;
        }
    case 3:
        // else if (strcmp(typeimport.c_str(), "3") == 0)
        {
            printf("\tveuillez rentrer la  ville de départ et la vil0le d'arrivée\n");
            cin >> villed;
            cin >> villea;
            break;
        }
    }
    transform(villed.begin(), villed.end(), villed.begin(), ::tolower);
    transform(villed.begin(), villed.end(), villed.begin(), ::tolower);
    vector<string> row;
    string line, word;
    TrajetCompose *t; // on le crée dans le cas où on en aura besoin
    while (!file.eof())
    {
        row.clear(); // effacer les données qui sont dans row

        getline(file, line);          // récuperer une ligne de file dans la string line
        stringstream s(line);         // on va séparer la ligne en plusieurs mots
        while (getline(s, word, ';')) // permet de mettre un mot de s dans word
        {
            row.push_back(word); // va stocker la valeur de word dans le vector de string row
        }

        string villedImport = row[1], villeaImport = row[2];
        transform(villeaImport.begin(), villeaImport.end(), villeaImport.begin(), ::tolower);
        transform(villedImport.begin(), villedImport.end(), villedImport.begin(), ::tolower);

        if (::strcmp(line.c_str(), "") == 0)
        {
            // afin que la fonction stoi ne déclenche pas d'erreur pour la premièrer ligne
        }

        else
        {

            int n = stoi(row[0]);
            switch (n)
            {
            // pour certain
            case 1:
            {
                ; // la ligne représente un trajet simple

                if ((typeimport) == 1 && villedImport == villed)
                {
                    TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                    trajets.Ajouter(aAjouter);
                    cout << "Ajouté" << endl;
                    break;
                }
                else if ((typeimport) == 2 && villeaImport == villea)
                {
                    TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                    trajets.Ajouter(aAjouter);
                    cout << "Ajouté" << endl;
                    break;
                }
                else if ((typeimport) == 3 && villeaImport == villea && villedImport == villed)
                {
                    TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                    trajets.Ajouter(aAjouter);
                    cout << "Ajouté" << endl;
                    break;
                }
                else
                {
                    break;
                }
            }

            case 2:
            {
                ; // la ligne représente un trajet composé
                if ((typeimport) == 1 && villedImport == villed)
                {
                    t = new TrajetCompose(); // on crée un trajet composé et on attend qu'il soit charger par les instructions suivantes
                    trajets.Ajouter(t);      // on le rajoute à notre Catalogue
                    composing = true;
                    break;
                }
                else if ((typeimport) == 2 && villeaImport == villea)
                {
                    t = new TrajetCompose(); // on crée un trajet composé et on attend qu'il soit charger par les instructions suivantes
                    trajets.Ajouter(t);      // on le rajoute à notre Catalogue
                    composing = true;
                    break;
                }
                else if ((typeimport) == 3 && villeaImport == villea && villedImport == villed)
                {
                    t = new TrajetCompose(); // on crée un trajet composé et on attend qu'il soit charger par les instructions suivantes
                    trajets.Ajouter(t);      // on le rajoute à notre Catalogue
                    composing = true;
                    break;
                }
                else
                {
                    composing = false;
                    break;
                }
            }
            case 3:
            {
                ; // trajet simple qui compose le trajet composé déjà initié
                if (composing == true)
                {
                    TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                    t->AjouterTrajet(aAjouter);
                    cout << "Ajouté dans composé" << endl;
                }
                break;
            }
            }
        }
    }

} // fin-Import_parChoix()

void Catalogue::Importer_parCritere(std::ifstream &file)
// Algorithme:
{
    int typeimport;
    bool simple = false;  // bolean pour indiquer si l'utilisatuer voudrait que des trajets simples
    bool compose = false; // bolean pour indiquer si l'utilisatuer voudrait que des trajets composé

    printf("\tVeuillez préciser le type d'import que vous voulez\n");
    printf("\t1: Importer tout Catalogue \n");
    printf("\t2: Importer seulement les trajets simples\n");
    printf("\t3: Importer seulement les trajets composés\n");
    while (!(cin >> typeimport) | typeimport > 3 | typeimport < 1)
    {
        cerr << "Veuillez rentrer une numéro entier de 1 à 3" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        printf("\tVeuillez préciser le type d'import que vous voulez\n");
        printf("\t1: Importer tout Catalogue \n");
        printf("\t2: Importer seulement les trajets simples\n");
        printf("\t3: Importer seulement les trajets composés\n");
    }
    // on va vérifier
    switch (typeimport)
    {

    case 1:
        // if (strcmp(typeimport.c_str(), "1") == 0)
        {
            break; // on fait rien les booleans restent false
        }
    case 2:
        // else if (strcmp(typeimport.c_str(), "2") == 0)
        {
            simple = true;
            break;
        }
    case 3:
        // else if (strcmp(typeimport.c_str(), "3") == 0)
        {
            compose = true;
            break;
        }
    }
    vector<string> row;
    string line, word;
    TrajetCompose *t; // on le crée dans le cas où on en aura besoin
    while (!file.eof())
    {
        row.clear(); // effacer les données qui sont dans row

        getline(file, line);          // récuperer une ligne de file dans la string line
        stringstream s(line);         // on va séparer la ligne en plusieurs mots
        while (getline(s, word, ';')) // permet de mettre un mot de s dans word
        {
            row.push_back(word); // va stocker la valeur de word dans le vector de string row
        }
        if (::strcmp(line.c_str(), "") == 0)
        {
            // afin que la fonction stoi ne déclenche pas d'erreur pour la premièrer ligne
        }
        else
        {

            int n = stoi(row[0]);
            switch (n)
            {
            case 1:
            {
                ; // la ligne représente un trajet simple
                if (compose == false)
                {
                    TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                    trajets.Ajouter(aAjouter);
                    cout << "Ajouté" << endl;
                }
                break;
            }
            case 2:
            {
                ; // la ligne représente un trajet composé
                if (simple == false)
                {
                    t = new TrajetCompose(); // on crée un trajet composé et on attend qu'il soit charger par les instructions suivantes
                    trajets.Ajouter(t);      // on le rajoute à notre Catalogue
                }
                break;
            }
            case 3:
            {
                ; // trajet simple qui compose le trajet composé déjà initié
                if (simple == false)
                {
                    TrajetSimple *aAjouter = new TrajetSimple(&row[1], &row[2], &row[3]);
                    t->AjouterTrajet(aAjouter);
                    cout << "Ajouté dans composé" << endl;
                }
                break;
            }
            default:
            {
                break;
            }
            }
        }
    }

} // fin--Importer_parCritere

void Catalogue::Afficher()
// Algorithme :
{
    trajets.tri();
    if (trajets.getracine()->getData() != nullptr)
    {
        trajets.Afficher();
    }
} //----- Fin de Méthode

void Catalogue::AjouterSimple()
// Algorithme :
{
    char depart[20];
    char arrivee[20];
    char transport[20];

    fscanf(stdin, "%99s %99s %99s", depart, arrivee, transport);
    TrajetSimple *aAjouter = new TrajetSimple(depart, arrivee, transport);
    trajets.Ajouter(aAjouter);
    cout << "Ajouté" << endl;
} //----- Fin de Méthode

void Catalogue::AjouterCompose()
// Algorithme :
{
    char lecture[100];
    TrajetCompose *monTrajet = new TrajetCompose();
    trajets.Ajouter(monTrajet);
    printf("menu ajout trajet composé:\n");
    printf("\t1: ajouter un nouveau trajet simple \n");
    printf("\t0: fin ajout trajet composé\n");

    fscanf(stdin, "%99s", lecture);
    while (strcmp(lecture, "0") != 0)
    {

        if (strcmp(lecture, "1") == 0)
        {
            char depart[20];
            char arrivee[20];
            char transport[20];

            fscanf(stdin, "%99s %99s %99s", depart, arrivee, transport);
            TrajetSimple *aAjouter = new TrajetSimple(depart, arrivee, transport);
            if (monTrajet->AjouterTrajet(aAjouter) == 0)
            {
                delete aAjouter;
            }
        }
        else if (strcmp(lecture, "0") == 0)
        {
        }
        printf("menu ajout trajet composé:\n");
        printf("\t1: ajouter un nouveau trajet simple \n");
        printf("\t0: fin ajout trajet composé\n");

        fscanf(stdin, "%99s", lecture);
    }
} //----- Fin de Méthode

void Catalogue::Exporter()
// Algorithme :
{
    // Saisie du nom du fichier
    printf("veuillez rentrer le nom du fichier \n");
    string nomFichier;
    cin >> nomFichier;
    ofstream fout;
    fout.open(nomFichier, fstream::out); // ouverture du fichier en écriture

    if (!fout.is_open())
    { // cas où il y a eu une erreur d'ouverture
        printf("erreur ouverture du fichier\n");
        fout.close();
        return;
    }

    int typeimport;
    printf("\tVeuillez choisir le type d'importation\n");
    printf("\t1:Export du Catalogue complet\n");
    printf("\t2:Export_parChoix (nom des villes)\n");
    printf("\t3:Export_parCritere (type de trajet)\n");
    printf("\t4:Export_parIntervalle (choix d'intervalle)\n");

    while (!(cin >> typeimport) | typeimport > 4 | typeimport < 1)
    {
        cerr << "Veuillez rentrer une numéro entier de 1 à 4" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        printf("\tVeuillez choisir le type d'importation\n");
        printf("\t1:Export du Catalogue complet\n");
        printf("\t2:Export_parChoix (nom des villes)\n");
        printf("\t3:Export_parCritere (type de trajet)\n");
        printf("\t4:Export_parIntervalle (choix d'intervalle)\n");
    }
    switch (typeimport)
    {

    case 1:
        // if (strcmp(typeExport.c_str(), "1") == 0)
        {
            fout << trajets.Decrire();
            break;
        }
    case 2:
        // else if (strcmp(typeExport.c_str(), "2") == 0)
        {
            Exporter_parChoix(fout);
            break;
        }
    case 3:
        // else if (strcmp(typeExport.c_str(), "3") == 0)
        {
            Exporter_parCritere(fout);
            break;
        }
    case 4:
        // else if (strcmp(typeExport.c_str(), "4") == 0)
        {
            Exporter_parIntervalle(fout);
            break;
        }
    }
    fout.close();
    cout << "Catalogue exporter!!" << endl;
}

void Catalogue::Exporter_parChoix(ofstream &fout)
// Algorithme :
{
    string villea, villed, res;
    int typeimport;
    printf("\tVeuillez préciser le type d'import que vous voulez\n");
    printf("\t1: Exporter par ville de départ \n");
    printf("\t2: Exporter par ville d'arrivée \n");
    printf("\t3: EXporter par ville de départ et ville d'arrivée\n");
    // cin >> typeimport;
    while (!(cin >> typeimport) | typeimport > 3 | typeimport < 1)
    {
        cerr << "Veuillez rentrer une numéro entier de 1 à 3" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        printf("\tVeuillez préciser le type d'import que vous voulez\n");
        printf("\t1: Exporter par ville de départ \n");
        printf("\t2: Exporter par ville d'arrivée \n");
        printf("\t3: EXporter par ville de départ et ville d'arrivée\n");
    }
    // on va vérifier
    switch (typeimport)
    {

    case 1:
        // if (strcmp(typeExport.c_str(), "1") == 0)
        {
            cin >> villed; // ville départ
            Cell *parcours = trajets.getracine();
            while (parcours != nullptr)
            {
                if (strcmp(parcours->getData()->getvilled(), villed.c_str()) == 0)
                {
                    // parcourir le catalogue et rajouter à la description des trajets qu'on va exporter
                    // la description du trajet en cours de lecture s'il vérifie les conditions
                    res.append(parcours->getData()->Decrire(false));
                }
                parcours = parcours->getNext();
            }
            break;
        }
    case 2:
        // else if (strcmp(typeExport.c_str(), "2") == 0)
        {
            cin >> villea; // ville arrivée
            Cell *parcours = trajets.getracine();
            while (parcours != nullptr)
            {
                if (strcmp(parcours->getData()->getvillea(), villea.c_str()) == 0)
                {
                    // parcourir le catalogue et rajouter à la description des trajets qu'on va exporter
                    // la description du trajet en cours de lecture s'il vérifie les conditions
                    res.append(parcours->getData()->Decrire(false));
                }
                parcours = parcours->getNext();
            }
            break;
        }
    case 3:
        // else if (strcmp(typeExport.c_str(), "3") == 0)
        {
            cout << "veuillez rentrer les villes" << endl;
            cin >> villed;
            cin >> villea;
            Cell *parcours = trajets.getracine();
            while (parcours != nullptr)
            {
                if (strcmp(parcours->getData()->getvillea(), villea.c_str()) == 0 &&
                    strcmp(parcours->getData()->getvilled(), villed.c_str()) == 0)
                {
                    // parcourir le catalogue et rajouter à la description des trajets qu'on va exporter
                    // la description du trajet en cours de lecture s'il vérifie les conditions
                    res.append(parcours->getData()->Decrire(false));
                }
                parcours = parcours->getNext();
            }
            break;
        }
    }

    fout << res;
}

void Catalogue::Exporter_parCritere(std::ofstream &fout)
// Algorithme :
{
    int typeimport;
    string res;

    printf("\tVeuillez préciser le type d'import que vous voulez\n");
    printf("\t1: Exporter tout Catalogue \n");
    printf("\t2: Exporter seulement les trajets simples\n");
    printf("\t3: Exporter seulement les trajets composés\n");
    // cin >> typeimport;
    // on va vérifier
    while (!(cin >> typeimport) | typeimport > 3 | typeimport < 1)
    {
        cerr << "Veuillez rentrer une numéro entier de 1 à 3" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    }
    switch (typeimport)
    {

    case 1:
        // if (strcmp(typeimport.c_str(), "1") == 0)
        {
            Cell *parcours = trajets.getracine();
            while (parcours != nullptr)
            {
                // parcourir le catalogue et rajouter à la description des trajets qu'on va exporter
                // la description du trajet en cours de lecture
                res.append(parcours->getData()->Decrire(false));
                parcours = parcours->getNext();
            }
            break;
        }
    case 2:
        // else if (strcmp(typeimport.c_str(), "2") == 0)
        {
            Cell *parcours = trajets.getracine();
            while (parcours != nullptr)
            {
                // parcourir le catalogue et rajouter à la description des trajets qu'on va exporter
                // la description du trajet en cours de lecture s'il est un TrajetSimple
                if (dynamic_cast<TrajetSimple *>(parcours->getData()))
                    res.append(parcours->getData()->Decrire(false));
                parcours = parcours->getNext();
            }
            break;
        }
    case 3:
        // else if (strcmp(typeimport.c_str(), "3") == 0)
        {
            Cell *parcours = trajets.getracine();
            while (parcours != nullptr)
            {
                // parcourir le catalogue et rajouter à la description des trajets qu'on va exporter
                // la description du trajet en cours de lecture s'il est un TrajetCompose
                if (dynamic_cast<TrajetCompose *>(parcours->getData()))
                    res.append(parcours->getData()->Decrire(false));
                parcours = parcours->getNext();
            }
            break;
        }
    }

    fout << res;
}

void Catalogue::Exporter_parIntervalle(std::ofstream &fout)
// Algorithme :
{
    int min = 0, max = 0, count = 0;
    string res;
    printf("\tVeuillez préciser l'intervalle à choisir\n");
    printf("\tpour un intervalle [a,b] rentrer→ a b\n");
    while (max <= min)
    {
        while (!(cin >> min))
        {
            cerr << "Veuillez rentrer une numéro entier pour la valeur minimale" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        }
        while (!(cin >> max))
        {
            cerr << "Veuillez rentrer une numéro entier pour la valeur maximale" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        };
        if (min >= max)
            cerr << "veuillez entrer encore une fois vos valeurs tel que a>b" << endl;
    }
    Cell *parcours = trajets.getracine();
    while (parcours != nullptr)
    {
        count++;
        if (count >= min && count <= max)
            res.append(parcours->getData()->Decrire(false));
        parcours = parcours->getNext();
    }

    fout << res;
}

void Catalogue::Interface()
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
    printf("\t7: Exporter le Catalogue \n");
    printf("\t0: quitter\n");

    fscanf(stdin, "%99s", lecture);
    while (strcmp(lecture, "0") != 0)
    {

        if (strcmp(lecture, "1") == 0)
        {
            if (trajets.getracine()->getData() == nullptr)
            {
                cout << "Catalogue vide" << endl;
            }
            else
                Afficher();
        }
        else if (strcmp(lecture, "2") == 0)
        {
            AjouterSimple();
        }
        else if (strcmp(lecture, "3") == 0)
        {
            AjouterCompose();
        }
        else if (strcmp(lecture, "4") == 0)
        {
            if (trajets.getracine()->getData() == nullptr)
            {
                cout << "Catalogue vide" << endl;
            }
            else
            {
                printf("veuillez rentrer la ville de départ ainsi que la ville d'arrivée\n");
                char depart[20];
                char arrivee[20];
                fscanf(stdin, "%99s %99s", depart, arrivee);
                recherche(depart, arrivee);
            }
        }
        else if (strcmp(lecture, "5") == 0)
        {
            if (trajets.getracine()->getData() == nullptr)
            {
                cout << "Catalogue vide" << endl;
            }
            else
            {
                printf("veuillez rentrer la ville de départ ainsi que la ville d'arrivée\n");
                char depart[20];
                char arrivee[20];
                fscanf(stdin, "%99s %99s", depart, arrivee);
                if (!rechercheCombi(depart, arrivee, false))
                {
                    cout << "On essaie de trouver une solution\n";
                    for (int i = 0; i < 10; i++)
                    {
                        cout << "----------\n";
                    }
                    cout << "Combinaisons de trajets pas disponible dans notre réseaux, cependant vous pouvez\n";
                    cout << "voir les propositions ci-dessus afin de vous rapprocher de votre destination\n ";
                }
            }
        }
        else if (strcmp(lecture, "6") == 0)
        {
            Importer();
        }
        else if (strcmp(lecture, "7") == 0)
        {
            Exporter();
        }
        else if (strcmp(lecture, "0") == 0)
        {
        }
        printf("menu:\n");
        printf("\t1: affichage\n");
        printf("\t2: ajouter un trajet simple\n");
        printf("\t3: ajouter un trajet composé\n");
        printf("\t4: recherche de parcours\n");
        printf("\t5: recherche combinatoire\n");
        printf("\t6: Importer le Catalogue \n");
        printf("\t7: Exporter le Catalogue \n");
        printf("\t0: quitter\n");

        fscanf(stdin, "%99s", lecture);
    }
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::~Catalogue()
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