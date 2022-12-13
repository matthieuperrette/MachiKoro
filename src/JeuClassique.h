//
// Created by Antoine Sesini on 03/12/2022.
//
#pragma once
#ifndef MINIVILLES_JEUCLASSIQUE_H
#define MINIVILLES_JEUCLASSIQUE_H
#include "Jeu.h"
#include "Plateau.h"
#include "Pioche.h"
#include "Carte.h"
#include "fonctions.h"


//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuClassique----------//
class JeuClassique : public Jeu {
private:
    Plateau* plateau;
    vector<Carte*> cartes;

    //Constructeur et Destructeur//
    JeuClassique() : cartes(fonctions::cartesEditionClassique()) {
        plateau = new Plateau(cartes);
        if (!plateau) { throw JeuException("Attention ! allocation de plateau echouee"); }
        //Ensuite, pas besoin d'appeler le constructeur sans argument, la partie Jeu de JeuClassique est appelee directement
        string nomCarteDepart1 = "Champs de ble";
        Carte* carteDepart1 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart1](Carte* c) {return c->getNom() == nomCarteDepart1; }));
        string nomCarteDepart2 = "Boulangerie";
        Carte* carteDepart2 = *(find_if(cartes.begin(), cartes.end(), [&nomCarteDepart2](Carte* c) {return c->getNom() == nomCarteDepart2; }));
        if (!carteDepart1 || !carteDepart2) { throw JeuException("Attention ! les cartes de depart n'ont pu être selectionnees"); }
        vector<Joueur*> playerList = getJoueursList();
        for (auto j : playerList)
        {
            j->ajouterCarte(carteDepart1);
            j->ajouterCarte(carteDepart2);
        }

    }
    ~JeuClassique() {
        //On detruit les cartes crees par fonctions::cartesEditionClassique()
        //Pas besoin de detruire le plateau, sa destruction est automatique
        vector<Carte*>::iterator it;
        delete plateau;
        for (it = cartes.begin(); it != cartes.end(); it++) //Destruction des cartes
            delete (*it)->getEffet();
        delete* it;
    }
    JeuClassique(const JeuClassique& j) = delete;
    JeuClassique& operator=(const JeuClassique& j) = delete;
    //Constructeur et Destructeur//



    //Structure et definition d'un Handler permettant de faire un getJeu
    struct Handler {
        JeuClassique* jeu;
        Handler() : jeu(nullptr) {}
        ~Handler() { libererJeu(); }
    };

    static Handler handler;

public:
    static JeuClassique& getJeu();
    static void libererJeu();

    //Methodes agissant sur les cartes a l'echelle du jeu
    vector<Carte*> getCartes() const override { return cartes; }

    //Methodes agissant sur le plateau a l'echelle du jeu
    Plateau* getPlateau() const { return plateau; }

    Paquet& getPaquetByNomPlateau(string& nom) const override { return plateau->getPaquetByNom(nom); }
    vector<Paquet*> getAllPaquetsPlateau() const override { return plateau->getAllPaquets(); }
    unsigned int getNbPaquetsPlateau() const override { return plateau->getNbPaquets(); }
    vector<Paquet*> getPaquetsNonVidesPlateau() const override { return plateau->getPaquetsNonVides(); }
    Carte* retirerCartePlateau(string& nom) override { return plateau->retirerCarte(nom); }
    void afficherPlateau() const  override { plateau->afficherPlateau(); }
    void ajouterCartePlateau(Carte* carte) const  override { plateau->ajouterCarte(carte); }





};
//------------Classe JeuClassique----------//





//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//

#endif //MINIVILLES_JEUCLASSIQUE_H
