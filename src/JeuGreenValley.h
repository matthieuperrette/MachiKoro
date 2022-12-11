//
// Created by Antoine Sesini on 08/12/2022.
//

#ifndef MINIVILLES_JEUGREENVALLEY_H
#define MINIVILLES_JEUGREENVALLEY_H
#include "Jeu.h"
#include "Plateau.h"
#include "Pioche.h"
#include "Carte.h"
#include "fonctions.h"


//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuGreenValley----------//
class JeuGreenValley : public Jeu{
private:
    Plateau* plateau;
    vector<Carte*> cartes;
    Pioche* pioche;

    //Constructeur et Destructeur//
    JeuGreenValley() {
        // CREATION DES CARTES GREEN VALLEY
        cartes=fonctions::cartesEditionClassique();
        vector<Carte*> cartesGreenValley=fonctions::cartesEditionGreenValley();
        cartes.insert(cartes.end(),cartesGreenValley.begin(),cartesGreenValley.end());

        // CREATION DE LA PIOCHE ET DU PLATEAU
        pioche = new Pioche(cartes,nbJoueurs);
        plateau = new Plateau(cartes, *pioche);
        if (!plateau){throw JeuException("Attention ! allocation de plateau échouée");}

        // AJOUT DES CARTES DE DEPARTS A TOUS LES JOUEURS
        string nomCarteDepart1="Champs de ble";
        Carte* carteDepart1= *(find_if(cartes.begin(),cartes.end(), [&nomCarteDepart1](Carte* c){return c->getNom()==nomCarteDepart1;}));
        string nomCarteDepart2="Boulangerie";
        Carte* carteDepart2=*(find_if(cartes.begin(),cartes.end(), [&nomCarteDepart2](Carte* c){return c->getNom()==nomCarteDepart2;}));
        if (!carteDepart1 || !carteDepart2) {throw JeuException("Attention ! les cartes de départ n'ont pu être sélectionnées");}
        vector<Joueur*> playerList=getJoueursList();
        for (auto j:playerList)
        {
            j->ajouterCarte(carteDepart1);
            j->ajouterCarte(carteDepart2);
        }
    }

    ~JeuGreenValley(){
        vector<Carte*>::iterator it;
        for(it=cartes.begin(); it!=cartes.end();it++) //Destruction des cartes
            delete *it;
        delete plateau;
        delete pioche;
    }

    JeuGreenValley(const JeuGreenValley& j)=delete;
    JeuGreenValley& operator=(const JeuGreenValley& j)=delete;
    //Constructeur et Destructeur//


    //Structure et definition d'un Handler permettant de faire un getJeu
    struct Handler{
        JeuGreenValley* jeu;
        Handler() : jeu(nullptr) {}
        ~Handler() { libererJeu(); }
    };

    static Handler handler;




public:
    static JeuGreenValley& getJeu();
    static void libererJeu();

    //Methodes agissant sur les cartes à l'echelle du jeu
    vector<Carte*> getCartes() const {return cartes;}

    //Methodes agissant sur le plateau à l'echelle du jeu
    Paquet& getPaquetByNomPlateau(string& nom) const override { return plateau->getPaquetByNom(nom); }
    vector<Paquet*> getAllPaquetsPlateau() const override { return plateau->getAllPaquets(); }
    unsigned int getNbPaquetsPlateau() const override { return plateau->getNbPaquets(); }
    vector<Paquet*> getPaquetsNonVidesPlateau() const override { return plateau->getPaquetsNonVides(); }
    Carte* retirerCartePlateau(string& nom) override { return plateau->retirerCarte(nom); }
    void afficherPlateau() const  override { plateau->afficherPlateau(); }
    void ajouterCartePlateau(Carte* carte) const  override { plateau->ajouterCarte(carte); }

};
//------------Classe JeuGreenValley----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//


#endif //MINIVILLES_JEUGREENVALLEY_H
