//
// Created by Harry Broudehoux on 29/11/2022.
//

#include "Jeu.h"
#include <iostream>
#include <cmath>
using namespace std;



//**--------------------Classe Jeu---------------------**//
//-----------------------Constructeurs et destructeur-----------------------//
Jeu::Jeu(){

    //-----------On demande à l'utilisateur combien de joueurs
    unsigned int nb=0;
    do{
        cout << "Veuillez entrer le nombre de joueurs pour cette partie :\n";
        cin >> nb;
    } while (nb<1); //On s'assure que le nombre entre est bien un entier strictement positif

    nbJoueurs=nb;

    //-----------Variable permettant d'initialiser les joueurs de jeu
    string p;
    bool Ia;
    string art;
    unsigned int money = 3;
    unsigned int des = 1;

    Paquet paquet;

    //---------------L'utilisateur rentre les infos des joueurs
    for (unsigned int i = 0; i<nb; i++){

        cout << "\n\n";
        cout << "Pseudo du "<<(i+1)<<((i==0) ? "er joueur :":"ème joueur : \n");
        cin>>p;

        cout << "\nEst ce une IA? (Oui/Non)\n";
        cin>>art;

        Ia = (art=="Oui" || art=="oui");

        //----------------creation du joueur
        joueurs.push_back(new Joueur(p, Ia, paquet, money, des)) ;
    }

    //-----------initialisation du de
    unsigned int min;
    unsigned int max;

    do {
        cout << "\n\n";
        cout << "Valeur minimale du dé?\n";
        cin >> min;
    }
    while (min<1);

    do {
        cout << "\n\n";
        cout << "Valeur maximale du dé?\n";
        cin >> max;
    }
    while (max<1 || max <min);


    de=new De(min,max);

}


Jeu::~Jeu(){
    for (auto j :joueurs){
        delete j;
    }
    delete de;
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

void Jeu::afficherJeu() {
    if (joueurs.size()==0) throw JeuException("Aucun joueur, rien a afficher");
    vector<Joueur*>::iterator it;
    for (it=joueurs.begin();it!=joueurs.end();it++)
    {
        cout << **it;
    }
}



//**--------------------Classe Jeu---------------------**//


//----------------------Fonctions supplémentaires-------------------------//
//**------------------Fonctions supplémentaires-------------------------**//
