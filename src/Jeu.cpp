//
// Created by Harry Broudehoux on 29/11/2022.
//

#include "Jeu.h"
#include <iostream>
using namespace std;


//-----------------------Constructeurs et destructeur-----------------------//
Jeu::Jeu(){                                          //pq erreur?

    //-----------initialisation du dé
    unsigned int min;
    unsigned int max;

    cout << "chiffre minimum du dé?\n";
    cin >> min;

    cout << "chiffre maximum du dé?\n";
    cin >> max;

    de = De(min, max);

    //-----------On demande à l'utilisateur combien de joueurs
    cout << "Combien de joueurs dans la Partie :";
    cin >> nbJoueurs;

    //-----------Variable permettant d'initialiser les joueurs de jeu
    string p;
    bool artificiel;
    string art;
    unsigned int money = 3;
    unsigned int des = 1;


    //---------------L'utilisateur rentre les infos des joueurs
    for (unsigned int i = 0; i<nbJoueurs; i++){
        Paquet* paquet = new Paquet();                   // pointeur?? reference??

        cout << "Pseudo du "<<(i+1)<<"ème joueur :";
        cin>>p;

        cout << "\n Est ce une IA? (oui ou non)";
        cin>>art;

        if (art=="oui") artificiel = true;
        else artificiel = false;

        //----------------création des joueurs
        joueurs.push_back(new Joueur(p, artificiel, *paquet, money, des)) ;
    }
}


Jeu::~Jeu(){
    for (unsigned int i=0; i<nbJoueurs;i++){
        delete joueurs[i];
    }
}
//**-----------------------Constructeur et destructeur-----------------------**//


Jeu& Jeu::getJeu() {
    if (handler.jeu ==nullptr)
    handler.jeu = new Jeu;
    return *handler.jeu;
}

void Jeu::libererJeu()
{
    delete handler.jeu;
    handler.jeu =nullptr;
}

const Joueur& Jeu::getJoueur(size_t i) const {
    if (i>nbJoueurs) throw JeuException("Le joueur n'existe pas");
    return *joueurs[i];
}

Jeu::Handler Jeu::handler = Handler();


//----------------------Fonctions supplémentaires-------------------------//

// Afficher la liste des joueurs
ostream& operator<<(ostream& f, const Jeu& jeu){
    Joueur* c;
    unsigned int i;
    for(i=0; i<jeu.getNbJoueurs(); i++){
        f << "\nJoueur n°" << (i+1) << "\n";
        f << "**-> PSEUDONYME : "<< jeu.getJoueur(i).getPseudo() << "\n";
        f << "**-> IA         : "<< ((jeu.getJoueur(i).getIa()) ? ("OUI"):("NON")) << "\n";
        f << "**-> PAQUET     : "<< jeu.getJoueur(i).getPaquet().getNbCartes() << " CARTE(S)\n";
        f << "**-> MONEY      : "<< jeu.getJoueur(i).getMoney() << "\n";
        f << "**-> NB DE DES  : "<< jeu.getJoueur(i).getDes() << "\n\n";
    }
}
//**------------------Fonctions supplémentaires-------------------------**//