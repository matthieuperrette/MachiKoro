//
// Created by Antoine Sesini on 26/11/2022.
//
#pragma once
#ifndef MINIVILLES_PLATEAU_H
#define MINIVILLES_PLATEAU_H

#include "Paquet.h"
#include "Pioche.h"


//********************Structures et variables nécessaires*****************//
class PlateauException {
private:
    string info;
public:
    PlateauException(const string& i) :info(i) {}
    string getInfo() const { return info; }
};
//********************Structures et variables nécessaires*****************//


//****************class Plateau*******************//
class Plateau {
private :
    vector<Paquet*> cartes;
    bool remplir;
public :
    //Constructeur avec dispatch normal : on identifie les cartes et on les pointe 6 fois dans chaque Paquet (sauf exception)
    explicit Plateau(vector<Carte*> cartesJeu); //cartesJeu=toutes les cartes de l'édition ne nécessitant pas de pioche et de distribution spéciale
    //Constructeur avec un dispatch anormal : on utilise la pioche pour faire des tirages
    Plateau(vector<Carte*> cartesJeu, Pioche p);
    Plateau(const Plateau&) = delete;
    Plateau operator=(const Plateau&) = delete;
    ~Plateau();




    //Espace de définition des get et autres méthodes d'utilisation//
    Paquet& getPaquetByNom(string& nom);
    vector<Paquet*> getAllPaquets();
    unsigned int getNbPaquets();
    Carte* retirerCarte(string& nom);
    void remplirPlateau();
    //Espace de définition des get et autres méthodes d'utilisation//


};
//****************class Plateau*******************//


//****************Fonctions supplémentaires******************//
ostream& operator<<(ostream& f, const Plateau& p);
//****************Fonctions supplémentaires******************//


#endif //MINIVILLES_PLATEAU_H
