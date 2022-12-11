//
// Created by Antoine Sesini on 03/12/2022.
//
#pragma once
#ifndef MINIVILLES_JEUDELUXE_H
#define MINIVILLES_JEUDELUXE_H
#include "Jeu.h"
#include "Plateau.h"
#include "Pioche.h"
#include "Carte.h"
#include "fonctions.h"


//---Structures et variables necessaires---//
//---Structures et variables necessaires---//


//------------Classe JeuDeluxe----------//
class JeuDeluxe : public Jeu{
private:
    Plateau* plateau;
    vector<Carte*> cartes;
    Pioche* pioche;

    //Contructeur et Destructeur//
    JeuDeluxe(){
        // CREATION DES CARTES DELUXE
        cartes=fonctions::cartesEditionClassique();
        vector<Carte*> cartesGreenValley=fonctions::cartesEditionGreenValley();
        cartes.insert(cartes.end(),cartesGreenValley.begin(),cartesGreenValley.end());
        // NE PAS OUBLIER D'ENLEVER LES COMMENTAIRES A L'AJOUT DE JEUMARINA
        //vector<Carte*> cartesMarina=fonctions::cartesEditionMarina();
        //cartes.insert(cartes.end(),cartesMarina.begin(),cartesMarina.end());

        // CREATION DE LA PIOCHE ET DU PLATEAU
        pioche = new Pioche(cartes,nbJoueurs);
        plateau = new Plateau(cartes, *pioche);
        if (!plateau){throw JeuException("Attention ! allocation de plateau échouée");}

        // AJOUT DES CARTES DE DEPARTS A TOUS LES JOUEURS
        string nomCarteDepart1="Champs de ble";
        Carte* carteDepart1= *(find_if(cartes.begin(),cartes.end(), [&nomCarteDepart1](Carte* c){return c->getNom()==nomCarteDepart1;}));
        string nomCarteDepart2="Boulangerie";
        Carte* carteDepart2=*(find_if(cartes.begin(),cartes.end(), [&nomCarteDepart2](Carte* c){return c->getNom()==nomCarteDepart2;}));
        // NE PAS OUBLIER D'ENLEVER LES COMMENTAIRES A L'AJOUT DE CARTESEDITIONMARINA
        //string nomCarteDepart3="Hotel de ville";
        //Carte* carteDepart3= *(find_if(cartes.begin(),cartes.end(), [&nomCarteDepart3](Carte* c){return c->getNom()==nomCarteDepart3;}));
        //ATTENTION RAJOUTER (|| !carteDepart3) DANS LA CONDITION DU IF SUIVANT A L'AJOUT DE CARTESEDITIONMARINA
        if (!carteDepart1 || !carteDepart2) {throw JeuException("Attention ! les cartes de départ n'ont pu être sélectionnées");}
        vector<Joueur*> playerList=getJoueursList();
        for (auto j:playerList)
        {
            j->ajouterCarte(carteDepart1);
            j->ajouterCarte(carteDepart2);
            // NE PAS OUBLIER D'ENLEVER LES COMMENTAIRES A L'AJOUT DE CARTESEDITIONMARINA
            //j->ajouterCarte(carteDepart3);
        }
    }

    ~JeuDeluxe(){
        vector<Carte*>::iterator it;
        for(it=cartes.begin(); it!=cartes.end();it++) //Destruction des cartes
            delete *it;
        delete plateau;
        delete pioche;
    }

    JeuDeluxe(const JeuDeluxe& j)=delete;
    JeuDeluxe& operator=(const JeuDeluxe& j)=delete;
    //Constructeur et Destructeur//


    //Structure et definition d'un Handler permettant de faire un getJeu
    struct Handler{
        JeuDeluxe* jeu;
        Handler() : jeu(nullptr){}
        ~Handler() { libererJeu(); }
    };

    static Handler handler;


//Methodes agissant sur les cartes à l'echelle du jeu
    vector<Carte*> getCartes() const {return cartes;}



public:
    static JeuDeluxe& getJeu();
    static void libererJeu();


    //Methodes agissant sur le plateau à l'echelle du jeu
    Paquet& getPaquetByNomPlateau(string& nom) const override { return plateau->getPaquetByNom(nom); }
    vector<Paquet*> getAllPaquetsPlateau() const override { return plateau->getAllPaquets(); }
    unsigned int getNbPaquetsPlateau() const override { return plateau->getNbPaquets(); }
    vector<Paquet*> getPaquetsNonVidesPlateau() const override { return plateau->getPaquetsNonVides(); }
    Carte* retirerCartePlateau(string& nom) override { return plateau->retirerCarte(nom); }
    void afficherPlateau() const  override { plateau->afficherPlateau(); }
    void ajouterCartePlateau(Carte* carte) const  override { plateau->ajouterCarte(carte); }

};
//------------Classe JeuDeluxe----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//


#endif //MINIVILLES_JEUDELUXE_H

