//
// Created by Antoine Sesini on 08/12/2022.
//

#ifndef MINIVILLES_JEUPLATEAU_H
#define MINIVILLES_JEUPLATEAU_H
#include "Jeu.h"
#include "Plateau.h"
#include "fonctions.h"



//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuPlateau----------//
class JeuPlateau : public Jeu {
//classe abstraite
protected:
    Plateau* plateau;
    

public:
    //CONSTRUCTEUR ET DESTRUCTEUR
    JeuPlateau() { plateau = nullptr; }
    ~JeuPlateau();

    //impératif d'initialise plateau
    void init(vector<Carte*>& cartes);
    void init(vector<Carte*>& cartes, Pioche& pioche);


    //Methodes agissant sur le plateau à l'echelle du jeu
    Paquet& getPaquetByNomPlateau(string& nom) const override { return plateau->getPaquetByNom(nom); }
    vector<Paquet*> getAllPaquetsPlateau() const override { return plateau->getAllPaquets(); }
    unsigned int getNbPaquetsPlateau() const override { return plateau->getNbPaquets(); }
    vector<Paquet*> getPaquetsNonVidesPlateau() const override { return plateau->getPaquetsNonVides(); }
    Carte* retirerCartePlateau(string& nom) override { return plateau->retirerCarte(nom); }
    void afficherPlateau() const  override { plateau->afficherPlateau(); }
    void ajouterCartePlateau(Carte* carte) const  override { plateau->ajouterCarte(carte); }

};
//------------Classe JeuPlateau----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//


#endif //MINIVILLES_JEUPLATEAU_H
