#pragma once
#ifndef MINIVILLES_PAQUET_H
#define MINIVILLES_PAQUET_H
#include "Carte.h"


//********************Structures et variables nécessaires*****************//

//********************Structures et variables nécessaires*****************//



//****************class Paquet*******************//
class Paquet {
private :
    vector<Carte*> cartes;
public :
    Paquet(const Paquet& p)=delete; //On ne doit pas pouvoir créer un paquet par recopie d'un autre
    Paquet& operator=(const Paquet&)=delete; //On ne doit pas pouvoir créer un paquet par affectation
    unsigned int getNbCartes() const {return cartes.size();}
    void ajouterCarte(Carte c) {cartes.push_back(&c);}
    void retirerCarte(const Carte& c);
    const Carte& getCarte(size_t i) const {return *(cartes[i]);} //à voir si on garde
    vector<Carte*> getContenu() const {return cartes;} //retourne le conteneur entier de cartes
    vector<Carte*> getCarteCouleur(Couleur couleur) const;
    vector<Carte*> getCarteType(Type type) const;
};
//****************class Paquet*******************//


//****************Fonctions supplémentaires******************//
ostream& operator<<(ostream& f,const Paquet& p); //Fonction d'affichage d'un paquet
Paquet operator+(const Paquet& p1, const Paquet& p2); //Fonction de fusion de 2 paquets
//****************Fonctions supplémentaires******************//


#endif //MINIVILLES_PAQUET_H
