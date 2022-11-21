#include <iostream>
#include "Ensemble.h"
using namespace std;


int main(){
    int t[5]={4,4,4,2,5};
    int t1[3]={2,5,1};
    Ensemble p=Ensemble(t, 5);
    Ensemble m=Ensemble(t1, 3);
   //p.Afficher();
    m.Afficher();
    cout<<m.Intersection(p)<<endl;
    m.Afficher();



    return 0;
}