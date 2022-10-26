#include <iostream>
using namespace std;
#include "Ensemble.h"






int main(){
    int t[]={1,2,4,5,6,6,6};
    int t1[]={7,8};
    Ensemble e=Ensemble(t,7);
    Ensemble e1=Ensemble(t1,2);

    e.Afficher();
    int m=e.Reunir(e1);
    e.Afficher();
    cout<<m<<endl;


return 0;

}
