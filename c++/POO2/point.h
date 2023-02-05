/*************************************************************************
                           point  -  description
                             -------------------
    début                : 24/01/23
    copyright            : (C) 2023$ par ${AUTHOR}$
    e-mail               : ${EMAIL}$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#ifndef point_H
#define  point_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <point>
//
//
//------------------------------------------------------------------------

class point{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    template<typename T>
    friend T  Minimum  (const  T & P1, const T & P2);



    //------------------------------------------------- Surcharge d'opérateurs
point &operator=(const point &unpoint){
        x=unpoint.x;
        y=unpoint.y;
        return *this;
}
    // Mode d'emploi :
    //
    // Contrat :
    //
    friend std::ostream & operator<<(std::ostream & out,const point &unpoint);
    friend std::ostream & operator<<(std::ostream & out,const point &unpoint){
        out<<"corrdinates of this points are("<<unpoint.x<<","<<unpoint.y<<")";
        return out;
    }



    //-------------------------------------------- Constructeurs - destructeur
    point(const point &unpoint);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    point(int xpos=0, int ypos=0): x(xpos),y(ypos){}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~point();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
int x;
int y;

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // point_H
