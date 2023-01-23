
#include "annuaire.h"
void annuaire::ajouter(const abonne &a)
{

    if(!a.nom.empty()) {
        pageblanche.insert(make_pair(a.nom, a.info));
    }

}//----FIN AJOUTER

void annuaire::ajouter(const string &nomfichier) {

    ifstream file(nomfichier.c_str());
    abonne a;
    if(file){
        while (file>>a){
            ajouter(a);
        }
    }else{
        cerr<<"erreur accès"<<endl;
    }


}

void annuaire::Afficher(const string & nom,ostream & f)const{
    Tdico :: const_iterator debut,fin;
    debut=(nom.empty()) ? pageblanche.begin(): pageblanche.lower_bound(nom);
    fin=(nom.empty()) ? pageblanche.end() : pageblanche.upper_bound(nom);

    while(debut!=fin) {
        f << abonne(debut->first, debut->second );
        debut++;
    }
}



}
