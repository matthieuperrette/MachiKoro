//
// Created by Antoine Sesini on 29/11/2022.
//
#ifndef MINIVILLES_JOUEUR_H
#define MINIVILLES_JOUEUR_H
#include <string>
#include "../src/Paquet.h"


//********************Structures et variables nécessaires*****************//
//********************Structures et variables nécessaires*****************//


//****************class Joueur*******************//
class Joueur {
private:
    string pseudo;
    bool ia;
    Paquet cartes;
    unsigned int money;
    unsigned int des;
public:
    //Constructeurs et destructeurs//
    Joueur()=delete;
    Joueur(string& p, unsigned int i = 0, Paquet& c,  unsigned int d = 1):pseudo(p),ia(i),cartes(c),money(0),des(d);
    Joueur(const Joueur&)=delete;
    Joueur& operator=(const Joueur&)=delete;
    ~Joueur();
    //Constructeurs et destructeurs//

    //Methodes de service//

    //Methodes de service//
};
//****************class Joueur*******************//


//********************Fonctions supplémentaires**************************//
//********************Fonctions supplémentaires**************************//



#endif //MINIVILLES_JOUEUR_H