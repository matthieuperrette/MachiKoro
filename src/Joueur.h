#ifndef JOUEUR_H
#define JOUEUR_H

#include<string>
#include "Paquet.h"

//********************Structures et variables nécessaires*****************//
class JoueurException {
private:
    string info;
public:
    JoueurException(const string& i) :info(i) {}
    string getInfo() const { return info; }
};
//********************Structures et variables nécessaires*****************//

//****************class Paquet*******************//
class Joueur {
private:
    string pseudo;
    bool ia;
    Paquet cartes;
    unsigned int money;
    unsigned int des;
    
public :
    Joueur(string p, unsigned int i=0, const Paquet& c, unsigned int d=1): pseudo(p), ia(i), cartes(c), money(0), des(d){}
    ~Joueur() = default;
     string getPseudo() const { return pseudo; }
     bool getIa() const { return ia; }
     Paquet& getCarte() const { return cartes; }
     unsigned int getMoney() const { return money; }
     unsigned int getNbDes() const { return des; }
};
//****************class Joueur*******************//


//****************Fonctions supplémentaires******************//
ostream& operator<<(ostream& f, const Paquet& p); //Fonction d'affichage d'un paquet
//****************Fonctions supplémentaires******************//

#endif

