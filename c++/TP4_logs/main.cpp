#include <iostream>
#include "Traitement.h"
#include "TraitementLog.h"
#include <fstream>
int main() {
    std::cout << "Hello, World!" << std::endl;

    string line="http://intranet-if.insa-lyon.fr/temps/4IF15.html";
    string retrieve="http://intranet-if.insa-lyon.fr";
    string res=line.substr(retrieve.size(),line.length());
    std::cout<<res<<endl;

     return 0;
}
