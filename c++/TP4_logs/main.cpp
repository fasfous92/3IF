#include <iostream>
#include "Traitement.h"
#include "TraitementLog.h"
#include <fstream>

int main() {
    /*string lineTest="192.168.0.0 - - [08/Sep/2012:11:16:02 +0200] \"GET /temps/4IF16.html HTTP/1.1\" 200 12106 \"http://intranet-if.insa-lyon.fr/temps/4IF15.html\" \"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1";
    Traitement te(lineTest);
    te.afficherVecteur();
    */
    /*
    string line="http://intranet-if.insa-lyon.fr/temps/4IF15.html";
    string retrieve="http://intranet-if.insa-lyon.fr";
    string res=line.substr(retrieve.size(),line.length());
    std::cout<<res<<endl;

    Traitement test=Traitement(lineTest);*/

    string filename;
    cout<<"veuillez rentrer nom du fichier"<<endl;
    cin>>filename;
    TraitementLog t (filename);
    t.execute();

    return 0;
}
