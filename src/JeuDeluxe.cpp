//
// Created by Antoine Sesini on 03/12/2022.
//
#include "JeuDeluxe.h"

//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuDeluxe----------//
JeuDeluxe& JeuDeluxe::getJeu() {
    if (handler.jeu == nullptr)
        handler.jeu = new JeuDeluxe;
    return *handler.jeu;
}

void JeuDeluxe::libererJeu()
{
    delete handler.jeu;
    handler.jeu = nullptr;
}

JeuDeluxe::Handler JeuDeluxe::handler = Handler();
//------------Classe JeuDeluxe----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//