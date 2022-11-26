#ifndef JOUEUR_H
#define JOUEUR_H

#include<string>
#include "Paquet.h"

class Joueur {

private:
    Paquet cartes;
    string pseudo;
    unsigned int money;
    int des;
    Joueur(const Joueur&) = delete;
    Joueur& operator=(const Joueur&) = delete;

public:
    Joueur(string p): cartes( ), pseudo(p), money(), des(1){}
    void afficher(std::ostream&) const override;
    unsigned int getMoney() const { return money; }
    string getPseudo() const { return pseudo; }
    unsigned int getNbDes() const { return des; }
    unsigned int getNbCarte() const { return cartes.getNbCarte(); }
};

#endif

