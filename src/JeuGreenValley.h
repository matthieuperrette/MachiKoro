//
// Created by Antoine Sesini on 08/12/2022.
//

#ifndef MINIVILLES_JEUGREENVALLEY_H
#define MINIVILLES_JEUGREENVALLEY_H
#include "JeuPioche.h"
#include "Carte.h"
#include "fonctions.h"


//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuGreenValley----------//
class JeuGreenValley : public JeuPioche {
private:
    vector<Carte*> cartes;

    //Constructeur et Destructeur//
    JeuGreenValley();
    ~JeuGreenValley();

    JeuGreenValley(const JeuGreenValley& j) = delete;
    JeuGreenValley& operator=(const JeuGreenValley& j) = delete;
    //Constructeur et Destructeur//


    //Structure et definition d'un Handler permettant de faire un getJeu
    struct Handler {
        JeuGreenValley* jeu;
        Handler() : jeu(nullptr) {}
        ~Handler() { libererJeu(); }
    };

    static Handler handler;




public:
    static JeuGreenValley& getJeu();
    static void libererJeu();

    //Methodes agissant sur les cartes à l'echelle du jeu
    vector<Carte*> getCartes() const { return cartes; }

};
//------------Classe JeuGreenValley----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//


#endif //MINIVILLES_JEUGREENVALLEY_H
