//
// Created by Antoine Sesini on 08/12/2022.
//

#include "JeuGreenValley.h"



//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuGreenValley----------//

 //Constructeur et Destructeur//
JeuGreenValley::JeuGreenValley() {
    // CREATION DES CARTES GREEN VALLEY
    cartes = fonctions::cartesEditionClassique();
    vector<Carte*> cartesGreenValley = fonctions::cartesEditionGreenValley();
    cartes.insert(cartes.end(), cartesGreenValley.begin(), cartesGreenValley.end());

    // CREATION DE LA PIOCHE ET DU PLATEAU
    JeuPioche::init(cartes);

    // AJOUT DES CARTES DE DEPARTS A TOUS LES JOUEURS
    string nomCarteDepart1 = "Champs de ble";
    Carte* carteDepart1 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart1](Carte* c) {return c->getNom() == nomCarteDepart1; }));
    string nomCarteDepart2 = "Boulangerie";
    Carte* carteDepart2 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart2](Carte* c) {return c->getNom() == nomCarteDepart2; }));
    if (!carteDepart1 || !carteDepart2) { throw JeuException("Attention ! les cartes de départ n'ont pu être sélectionnées"); }
    vector<Joueur*> playerList = getJoueursList();
    for (auto j : playerList)
    {
        j->ajouterCarte(carteDepart1);
        j->ajouterCarte(carteDepart2);
    }
}

JeuGreenValley::~JeuGreenValley() {
    vector<Carte*>::iterator it;
    for (it = cartes.begin(); it != cartes.end(); it++) //Destruction des cartes
    {
        delete (*it)->getEffet();
        delete* it;
    }

}



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