//
// Created by Antoine Sesini on 03/12/2022.
//
#include "JeuMarina.h"
#include "EffetMarina.h"
#include "fonctions.h"

//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuMarina----------//


JeuMarina::JeuMarina() {
    cartes = fonctions::cartesEditionClassique();
    vector<Carte*> cartesMarina = fonctions::cartesEditionMarina();
    cartes.insert(cartes.end(), cartesMarina.begin(), cartesMarina.end());

    plateau = new Plateau(cartes, nbJoueurs);
    pioche = new Pioche(cartes, getNbJoueurs());
    //Ensuite, pas besoin de faire appel au constructeur sans argument, il y a un appel de la partie Jeu de JeuMarina directement
    string nomCarteDepart1 = "Champs de ble";
    Carte* carteDepart1 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart1](Carte* c) {return c->getNom() == nomCarteDepart1; }));
    string nomCarteDepart2 = "Boulangerie";
    Carte* carteDepart2 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart2](Carte* c) {return c->getNom() == nomCarteDepart2; }));
    string nomCarteDepart3 = "Hotel de Ville";
    Carte* carteDepart3 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart3](Carte* c) {return c->getNom() == nomCarteDepart3; }));
    if (!carteDepart1 || !carteDepart2 || !carteDepart3) { throw JeuException("Attention ! les cartes de d�part n'ont pu �tre s�lectionn�es"); }
    vector<Joueur*> playerList = getJoueursList();
    for (auto j : playerList)
    {
        j->ajouterCarte(carteDepart1);
        j->ajouterCarte(carteDepart2);
        j->ajouterCarte(carteDepart3);
    }
}

JeuMarina::~JeuMarina() {
    //On detruit les cartes crees par fonctions::cartesEditionClassique()
    //Pas besoin de detruire ni plateau ni pioche, leur destruction est automatique
    vector<Carte*>::iterator it;
    for (it = cartes.begin(); it != cartes.end(); it++) //Destruction des cartes
    {
        delete (*it)->getEffet();
        delete* it;
    }
    delete pioche;
    delete plateau;

}

JeuMarina& JeuMarina::getJeu() {
    if (handler.jeu == nullptr)
        handler.jeu = new JeuMarina;
    return *handler.jeu;
}

void JeuMarina::libererJeu()
{
    delete handler.jeu;
    handler.jeu = nullptr;
}

JeuMarina::Handler JeuMarina::handler = Handler();
//------------Classe JeuMarina----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//