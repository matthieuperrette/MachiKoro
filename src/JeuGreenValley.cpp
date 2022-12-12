//
// Created by Antoine Sesini on 08/12/2022.
//

#include "JeuGreenValley.h"



//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuGreenValley----------//
JeuGreenValley& JeuGreenValley::getJeu() {
    if (handler.jeu == nullptr)
        handler.jeu = new JeuGreenValley;
    return *handler.jeu;
}

void JeuGreenValley::libererJeu()
{
    delete handler.jeu;
    handler.jeu = nullptr;
}

JeuGreenValley::Handler JeuGreenValley::handler = Handler();
//------------Classe JeuGreenValley----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//