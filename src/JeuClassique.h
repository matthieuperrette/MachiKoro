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
class JeuClassique : public Jeu{
private:
    Plateau* plateau;
    vector<Carte*> cartes;

    //Constructeur et Destructeur//
    JeuClassique(): cartes(fonctions::cartesEditionClassique()){
        plateau=new Plateau(cartes);
        if (!plateau){throw JeuException("Attention ! allocation de plateau échouée");}
        //Ensuite, pas besoin d'appeler le constructeur sans argument, la partie Jeu de JeuClassique est appelée directement
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
    ~JeuClassique(){
        //On détruit les cartes crées par fonctions::cartesEditionClassique()
        //Pas besoin de détruire le plateau, sa destruction est automatique
        vector<Carte*>::iterator it;
        for(it=cartes.begin(); it!=cartes.end();it++) //Destruction des cartes
            delete *it;
    }
    JeuClassique(const JeuClassique& j)=delete;
    JeuClassique& operator=(const JeuClassique& j)=delete;
    //Constructeur et Destructeur//



    //Structure et definition d'un Handler permettant de faire un getJeu
    struct Handler{
        JeuClassique* jeu;
        Handler() : jeu(nullptr){}
        ~Handler() { delete jeu; }
    };

    static Handler handler;

public:
    static JeuClassique& getJeu();
    static void libererJeu();

    //Méthodes agissant sur les cartes à l'échelle du jeu
    vector<Carte*> getCartes() const {return cartes;}

    //Méthodes agissant sur le plateau à l'échelle du jeu
    const Plateau& getPlateau() const {return *plateau;}
    Paquet& getPaquetByNomPlateau(string& nom) const{return plateau->getPaquetByNom(nom);}
    vector<Paquet*> getAllPaquetsPlateau() const{return plateau->getAllPaquets();}
    unsigned int getNbPaquetsPlateau() const{return plateau->getNbPaquets();}
    vector<Paquet*> getPaquetsNonVidesPlateau() const{return plateau->getPaquetsNonVides();}
    Carte* retirerCartePlateau(string& nom) {return plateau->retirerCarte(nom);}
    void afficherPlateau() const {plateau->afficherPlateau();}
};
//------------Classe JeuClassique----------//

//---------Fonctions supplementaires-------//
//---------Fonctions supplementaires-------//

#endif //MINIVILLES_JEUCLASSIQUE_H
