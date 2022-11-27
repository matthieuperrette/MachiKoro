#pragma once
#ifndef MINIVILLES_PAQUET_H
#define MINIVILLES_PAQUET_H
#include "Carte.h"


//********************Structures et variables nécessaires*****************//
class PaquetException {
private:
    string info;
public:
    PaquetException(const string& i) :info(i) {}
    string getInfo() const { return info; }
};
//********************Structures et variables nécessaires*****************//



//****************class Paquet*******************//
class Paquet {
private:
    vector<Carte*> cartes;
public:
    Paquet() = default;
    ~Paquet() = default;
    Paquet(const Paquet& p) = delete; //On ne doit pas pouvoir créer un paquet par recopie d'un autre
    Paquet& operator=(const Paquet&) = delete; //On ne doit pas pouvoir créer un paquet par affectation

    unsigned int getNbCartes() const { return cartes.size(); }
    void ajouterCarte(Carte* c) { cartes.push_back(c); }
    void retirerCarte(Carte* c);
    Carte* retirerCarte();
    Carte& getCarte(size_t i) const { if (!cartes.empty())return *(cartes[i]); else throw PaquetException("Aucune carte contenue dans ce paquet"); } //à voir si on garde/change
    vector<Carte*> getContener() const { return cartes; } //retourne le conteneur entier de cartes
    vector<Carte*> getCarteCouleur(Couleur couleur) const;
    vector<Carte*> getCarteType(Type type) const;
    vector<Carte*> getCarteActive(int activateur);
};
//****************class Paquet*******************//



//****************Fonctions supplémentaires******************//
ostream& operator<<(ostream& f, const Paquet& p); //Fonction d'affichage d'un paquet
//****************Fonctions supplémentaires******************//


#endif //MINIVILLES_PAQUET_H
