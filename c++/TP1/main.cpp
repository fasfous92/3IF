#include <iostream>
using namespace std;
#include "Ensemble.h"






int main(){
    int t[]={1,2,7,4};
    int t1[]={1,2,3,5,6};
    Ensemble e=Ensemble(t,4);
    Ensemble e1=Ensemble(t1,5);

    e.Afficher();
    unsigned int m=e.Retirer(e1);
    e.Afficher();
    cout<<m<<endl;


return 0;

}
