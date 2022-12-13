//
// Created by Antoine Sesini on 03/12/2022.
//
#include "JeuDeluxe.h"

//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuDeluxe----------//

//Contructeur et Destructeur//
JeuDeluxe::JeuDeluxe() {
    // CREATION DES CARTES DELUXE
    cartes = fonctions::cartesEditionClassique();
    vector<Carte*> cartesGreenValley = fonctions::cartesEditionGreenValley();
    cartes.insert(cartes.end(), cartesGreenValley.begin(), cartesGreenValley.end());
    vector<Carte*> cartesMarina = fonctions::cartesEditionMarina();
    cartes.insert(cartes.end(), cartesMarina.begin(), cartesMarina.end());

    // CREATION DE LA PIOCHE ET DU PLATEAU
    JeuPioche::init(cartes);

    // AJOUT DES CARTES DE DEPARTS A TOUS LES JOUEURS
    string nomCarteDepart1 = "Champs de ble";
    Carte* carteDepart1 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart1](Carte* c) {return c->getNom() == nomCarteDepart1; }));
    string nomCarteDepart2 = "Boulangerie";
    Carte* carteDepart2 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart2](Carte* c) {return c->getNom() == nomCarteDepart2; }));
    string nomCarteDepart3 = "Hotel de Ville";
    Carte* carteDepart3 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart3](Carte* c) {return c->getNom() == nomCarteDepart3; }));
    if (!carteDepart1 || !carteDepart2 || !carteDepart3) { throw JeuException("Attention ! les cartes de départ n'ont pu être sélectionnées"); }
    vector<Joueur*> playerList = getJoueursList();
    for (auto j : playerList)
    {
        j->ajouterCarte(carteDepart1);
        j->ajouterCarte(carteDepart2);
        j->ajouterCarte(carteDepart3);
    }
}

JeuDeluxe::~JeuDeluxe() {
    vector<Carte*>::iterator it;
    for (it = cartes.begin(); it != cartes.end(); it++) //Destruction des cartes et des effets
    {
        delete (*it)->getEffet();
        delete* it;
    }
}


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