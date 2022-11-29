//
// Created by Antoine Sesini on 29/11/2022.
//
#ifndef MINIVILLES_JOUEUR_H
#define MINIVILLES_JOUEUR_H
#include <string>
#include "../src/Paquet.h"


//********************Structures et variables nécessaires*****************//
class JoueurException {
public:
    JoueurException(const string& i) :info(i) {}
    string getInfo() const { return info; }
private:
    string info;
};
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
    Joueur(string& pseudo, bool ia, Paquet& c,unsigned int argent, unsigned int des):pseudo(pseudo),ia(ia),cartes(c),money(argent),des(des){}
    Joueur(const Joueur&)=delete;
    Joueur& operator=(const Joueur&)=delete;
    ~Joueur()=default;
    //Constructeurs et destructeurs//




    //Méthods de service//
    string getPseudo() const {return pseudo;}
    bool getIa() const {return ia;}
    const Paquet& getPaquet() const {return cartes;}
    unsigned int getMoney() const {return money;}
    unsigned int getDes() const {return des;}

    void ajouterCarte(Carte* carte); //Ajoute une carte dans le paquet du joueur
    Carte* retirerCarte(Carte* c); //Retire une carte dans le paquet du joueur et la retourne sous forme de pointeur
    Carte* retirerCarte(string& nom);
    //Méthodes de service//
};
//****************class Joueur*******************//


//********************Fonctions supplémentaires**************************//
ostream& operator<<(ostream& f, const Joueur& joueur);
//********************Fonctions supplémentaires**************************//



#endif //MINIVILLES_JOUEUR_H