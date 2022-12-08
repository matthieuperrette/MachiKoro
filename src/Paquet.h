#pragma once
#ifndef MINIVILLES_PAQUET_H
#define MINIVILLES_PAQUET_H
#include "Carte.h"


//********************Structures et variables necessaires*****************//
class PaquetException {
private:
    string info;
public:
    PaquetException(const string& i) :info(i) {}
    string getInfo() const { return info; }
};
//********************Structures et variables necessaires*****************//



//****************class Paquet*******************//
class Paquet {
private:
    vector<Carte*> cartes;
public:
    Paquet() = default;
    virtual ~Paquet() = default;
    Paquet(const Paquet& p)=default;
    Paquet& operator=(const Paquet&) = delete; //On ne doit pas pouvoir creer un paquet par affectation

    unsigned int getNbCartes() const { return cartes.size(); }
    bool is_In(Carte*);
    void ajouterCarte(Carte* c) { cartes.push_back(c); }
    Carte* retirerCarte(string& nom);
    Carte* retirerCarte(Carte* c); //retirer la carte passe en parametre
    Carte* retirerCarte(); //retirer la derniere carte (sur le paquet)
    Carte& getCarte(size_t i) const { if (!cartes.empty())return *(cartes[i]); else throw PaquetException("Aucune carte contenue dans ce paquet"); } //a voir si on garde/change
    vector<Carte*> getContener() const { return cartes; } //retourne le conteneur entier de cartes
    vector<Carte*> getCarteCouleur(Couleur couleur) const;
    vector<Carte*> getCarteType(Type type) const;
    vector<Carte*> getCarteActive(int activateur);
};
//****************class Paquet*******************//



//****************Fonctions supplementaires******************//
ostream& operator<<(ostream& f, const Paquet& p); //Fonction d'affichage d'un paquet
//****************Fonctions supplementaires******************//


#endif //MINIVILLES_PAQUET_H
