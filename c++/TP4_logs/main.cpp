#include <iostream>
#include "Traitement.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    std::string line="192.168.0.34 - - [08/Sep/2012:12:40:41 +0200] \"GET /stages/FondInsa.jpg HTTP/1.1\" 200 2828 \"http://intranet-if.insa-lyon.fr/stages/style_pfe.css\" \"Mozilla/5.0 (Windows NT 5.1; rv:12.0) Gecko/20100101 Firefox/12.0\"";
    Traitement t1=Traitement(line);
    for(int i=0;i< t1.section.size();i++){
        std::cout<<t1.section[i]<<std::endl;
    }
    //std::cout<<t1.section[0]<<std::endl;


    return 0;
}
