#include <iostream>
#include "Traitement.h"
#include "TraitementLog.h"
#include <fstream>
#include <regex>

int main(int argc,char* argv[]) {
    if( argc<=1){
        cerr<<"Erreur absence de pramètres"<<endl;
        return 1;
    }

    string aide=argv[1];
    if(aide== "--help") { //on vérifie si l'utilisaeur veut juste avoir accès aux aides liées aux options
        fstream help;
        help.open("help.txt", ios::in);
        if (!help){
            cerr << "erreur d'ouverture du fichier help";
            return 1;
        }else
        {
            while(!help.eof()) {
                string line;
                getline(help, line);
                cout << line<<endl;
            }
        }
        return 0;
    }


    bool nomLogPresent = false;
    string nomLog=argv[argc-1];  //on vérifie si le fichier source existe par la suite
    if(nomLog.find(".log")==std::string::npos){ //if he doesn't find a .log extension there's an error
        cerr<<"Type de fichier en paramètre erroné, veuillez rentrer un fichier.log en paramètre"<<endl;
        return 1;
    }

    bool faireGraphe = false; //implique l'éxistance du -g suivi du nom de fichier destination
    string nomGraphe;

    bool selectionpar_heure = false;
    int heure=-1;

    bool exclusions=false;
    //tout d'abords on commence par vérifier si le fichier log (source) est présent et de format log


    // parcourt le tableau des arguments
    for ( int i = 1 ; i < argc-1; i++ ) // on commence à 1 car ./analog est négligé
    {
        string argCourant = argv[ i ] ;
        if( strlen( argv[i] ) < 1 ) //si l'argument est inférieur à 1 déjà nous remarquons une erreur dans les args
        {
            cerr<< "parametre"<< argCourant <<" non valide "<<endl;
            return 1;
        }
        if( argCourant == "-g" )
        {
                if(i+1 == argc-1) {
                    cerr<<"Paramètre non valide pour l'option -g :aucun paramètre ou confondu avec le fichier.log source"<<endl;
                    return 1;
                }

                nomGraphe = argv [ i+1 ];
                faireGraphe = true;
                i++;

        }
        else if( argCourant == "-t" )
        {
            if( i == argc -2 )
            {
                cerr << "Paramètre non valide pour l'option -t : aucun paramètre" << endl;
                return 1 ;
            }
            else
            {

                try{
                    heure = stoi(argv[i+1]);

                }
                catch(exception &err)
                {
                    cerr<<"Paramètre non valide pour l'option -t "<<endl;
                    return 1;
                }
                if( heure < 0 || heure>23)
                {
                    cerr << "Paramètre non valide pour l'option -t " << endl;
                    return 1;
                }else {
                    selectionpar_heure=true;
                    i++;
                }
            }
        }
        else if( argCourant == "-e" ){
            exclusions= true;
        }
        else{
            cerr<<"option non reconnue veuillez rentrer ./analog --help pour plus d'information sur les";
            cerr<<"options disponible dans notre programme"<<endl;
            return 1;
        }
    }

    TraitementLog t(nomLog,faireGraphe,nomGraphe,exclusions,heure);
    t.execute();

    return 0;
}