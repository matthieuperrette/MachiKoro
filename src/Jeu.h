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
class Jeu {
    //Liste des attributs//
    vector<Joueur*> joueurs;
    unsigned int nbJoueurs;
    De* de;
    //Liste des attributs//



    //Constructeur et Destructeur//
    Jeu();
    ~Jeu();
    Jeu(const Jeu& j)=delete;
    Jeu& operator=(const Jeu& j)=delete;
    //Constructeur et Destructeur//




    //Structure et definition d'un Handler permettant de faire un getJeu
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
    void afficherJeu();
    unsigned int lancerDe() const {return de->lancerDe();}

};
//**--------------------Classe Jeu---------------------**//




//----------------------Fonctions supplementaires-------------------------//
//**------------------Fonctions supplementaires-------------------------**//

#endif //MINIVILLES_JEU_H
