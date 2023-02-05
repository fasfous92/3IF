#include <iostream>
#include "point.h"


class endule{ //endl manipulator

    friend std::ostream & operator<<(std::ostream & cout, endule & e){
        cout.width(24);
        cout<<std::right;
    }
};
 template <typename T>
 T Minimum(const T &x, const T &y) {
  return x < y ? x : y;
}

template<>
point  Minimum (const  point & P1, const point & P2){

    point p;
    p.x=P1.x;
    p.y=P2.y;
    return p;
}

template <typename T>
class cellule {
public:
    friend class linkedlist;

    friend std::ostream &operator<<(std::ostream & cout, const cellule <T> & cell){
        cout<<"la cellule contient "<<cell.data<<" et elle pointe vers→ "<<cell.next<<std::endl;
    }

        cellule(T donnee=0, cellule<T> * suivant= nullptr):data(donnee),next(suivant){

    }

    T data;
    cellule <T> * next;
};

template <typename T>
 class Linkedlist{
 public:
     /*friend std::ostream &operator<<(std::ostream & cout, const Linkedlist & list){
         cellule<T>* parcours=list.suivant;
         while (parcours!= nullptr){
             cout<<*parcours;
             parcours=parcours->next;
         }
            cout<<*parcours;

     }*/
     void append(cellule <T> unecellule){
         cellule<T>* parcours=suivant;
         while (parcours!= nullptr){
             parcours=suivant->next;
         }
         parcours->next=&unecellule;

     }

     Linkedlist(const cellule <T> unecellule):inside(unecellule){

     }



     cellule <T> inside;
     cellule<T>* suivant;


 };


int main() {
    cellule <int> c1(5);
    cellule <int> c2(10);
    Linkedlist <int> list(c1);
    list.append(c2);
    cellule<int> * parcours=&list.inside;
    while (parcours!= nullptr){
        std::cout<<*parcours;
        parcours=parcours->next;
    }
    std::cout<<*parcours;

    return 0;
}
