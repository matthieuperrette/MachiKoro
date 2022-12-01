//
// Created by Harry Broudehoux on 29/11/2022.
//

#ifndef MINIVILLES_JEU_H
#define MINIVILLES_JEU_H

#include "Joueur.h"
#include "De.h"


//-----------------------Exception--------------------------//
class JeuException {
public:
    JeuException(const string& i) :info(i) {}
    string getInfo() const { return info; }
private:
    string info;
};
//**---------------------Exception----------------------**//




//----------------------Classe Jeu------------------------//
class Jeu{
    // liste des attributs
    vector<Joueur*> joueurs;
    De de;
    unsigned int nbJoueurs;

    // constructeur et destructeur
    Jeu();
    ~Jeu();
    Jeu(const Jeu& j)=delete;
    Jeu& operator=(const Jeu& j)=delete;

    // structure et definition d'un Handler permettant de faire un getJeu
    struct Handler{
        Jeu* jeu;
        Handler() : jeu(nullptr){}
        ~Handler() { delete jeu; }
    };

    static Handler handler;

public:
    static Jeu& getJeu();
    static void libererJeu();

    const Joueur& getJoueur(size_t i) const;

    unsigned int getNbJoueurs() const { return nbJoueurs; }

};
//**--------------------Classe Jeu---------------------**//




//----------------------Fonctions supplémentaires-------------------------//
ostream& operator<<(ostream& f, const Jeu& jeu);
//**------------------Fonctions supplémentaires-------------------------**//

#endif //MINIVILLES_JEU_H
