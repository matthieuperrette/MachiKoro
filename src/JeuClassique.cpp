//
// Created by Antoine Sesini on 03/12/2022.
//
#include "JeuClassique.h"

//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuClassique----------//
JeuClassique& JeuClassique::getJeu() {
    if (handler.jeu == nullptr)
        handler.jeu = new JeuClassique;
    return *handler.jeu;
}

void JeuClassique::libererJeu()
{
    delete handler.jeu;
    handler.jeu = nullptr;
}

JeuClassique::Handler JeuClassique::handler = Handler();
//------------Classe JeuClassique----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//