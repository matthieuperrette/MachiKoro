//
// Created by Harry Broudehoux on 30/11/2022.
//

#ifndef MINIVILLES_JEUCLASSIQUE_H
#define MINIVILLES_JEUCLASSIQUE_H
#include "Plateau.h"
#include "Carte.h"
#include "Jeu.h"

//-----------------------Exception--------------------------//
class JeuClassiqueException{
public:
    JeuClassiqueException(const string& i) :info(i) {}
    string getInfo() const { return info; }
private:
    string info;
};
//**---------------------Exception----------------------**//



//------------------Classe JeuClassique--------------------//
class JeuClassique : public Jeu {
    // Liste des attributs
    Plateau plateau;
    vector<Carte*> cartes;


    // constructeur et destructeur
    JeuClassique();
    ~JeuClassique();
    JeuClassique(const JeuClassique& j)=delete;
    JeuClassique& operator=(const JeuClassique& j)=delete;


    // structure et definition d'un Handler -> permet un getJeuClassique
    struct Handler{
        JeuClassique* jeuclassique;
        Handler() : jeuclassique(nullptr);
        ~Handler(){delete jeuclassique;}
    };

    static Handler handler;

public:
    vector<Carte*> getAllCartes()const;

};
//**----------------Classe JeuClassique-----------------**//


//----------------------Fonctions supplémentaires-------------------------//
ostream& operator<<(ostream& f, const JeuClassique& jeu);
//**------------------Fonctions supplémentaires-------------------------**//


#endif //MINIVILLES_JEUCLASSIQUE_H
