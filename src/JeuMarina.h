//
// Created by Antoine Sesini on 03/12/2022.
//
#pragma once
#ifndef MINIVILLES_JEUMARINA_H
#define MINIVILLES_JEUMARINA_H
#include "Jeu.h"
#include "Plateau.h"
#include "Pioche.h"
#include "Carte.h"

//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuMarina----------//
class JeuMarina : public Jeu {
private:
    Plateau* plateau;
    Pioche* pioche;
    vector<Carte*> cartes;

    //Constructeur et Destructeur//
    JeuMarina();
    ~JeuMarina();
    JeuMarina(const JeuMarina& j) = delete;
    JeuMarina& operator=(const JeuMarina& j) = delete;
    //Constructeur et Destructeur//


    //Structure et definition d'un Handler permettant de faire un getJeu
    struct Handler {
        JeuMarina* jeu;
        Handler() : jeu(nullptr) {}
        ~Handler() { libererJeu(); }
    };

    static Handler handler;

public:
    static JeuMarina& getJeu();
    static void libererJeu();

    //Methodes agissant sur les cartes a l'echelle du jeu
    vector<Carte*> getCartes() const { return cartes; }

    //Methodes agissant sur le plateau a l'echelle du jeu
    const Plateau& getPlateau() const { return *plateau; }
    Paquet& getPaquetByNomPlateau(string& nom) const { return plateau->getPaquetByNom(nom); }
    vector<Paquet*> getAllPaquetsPlateau() const { return plateau->getAllPaquets(); }
    unsigned int getNbPaquetsPlateau() const { return plateau->getNbPaquets(); }
    vector<Paquet*> getPaquetsNonVidesPlateau() const { return plateau->getPaquetsNonVides(); }
    Carte* retirerCartePlateau(string& nom) { return plateau->retirerCarte(nom); }
    void afficherPlateau() const { plateau->afficherPlateau(); }

    //Methodes agissant sur la pioche a l'echelle du jeu
    const Pioche& getPioche() const { return *pioche; }
    vector<Carte*> getPaquetPioche() const { vector <Carte*> pack = pioche->getContener(); return pack; }
    Carte* retirerCartePioche(string& nom) { return pioche->retirerCarte(nom); }
    void ajouterCartePlateau(Carte* carte) const  override { plateau->ajouterCarte(carte); }
};
//------------Classe JeuMarina----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//

#endif //MINIVILLES_JEUMARINA_H