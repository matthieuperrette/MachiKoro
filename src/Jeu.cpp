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

    //-----------On demande a l'utilisateur combien de joueurs
    unsigned int nb=0;
    cout << "Veuillez entrer le nombre de joueurs pour cette partie :\n";
    while (!(cin >> nb) || nb<2) {
        cout << "Erreur ! Nombre invalide.\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
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

    cout << "Valeur minimale du de?\n";
    while (!(cin >> min) || min<1) {
        cout << "Erreur ! Valeur invalide.\n";
        cin.clear();
        cin.ignore(255, '\n');
    }


    cout << "Valeur maximale du de?\n";
    while (!(cin >> max) || max<1 || max<min) {
        cout << "Erreur ! Valeur invalide.\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    de=new De(min,max);

}


Jeu::~Jeu(){
    for (auto j :joueurs){
        delete j;
    }
    delete de;
}
//**-----------------------Constructeur et destructeur-----------------------**//



const Joueur& Jeu::getJoueur(size_t i) const {
    if (i>nbJoueurs) throw JeuException("Le joueur n'existe pas");
    return *joueurs[i];
}

void Jeu::ajouterCarteJoueur(size_t i,Carte* carte){
    if (i>nbJoueurs) throw JeuException("Le joueur n'existe pas");
    joueurs[i]->ajouterCarte(carte);
}
Carte* Jeu::retirerCarteJoueur(size_t i,Carte* c){
    if (i>nbJoueurs) throw JeuException("Le joueur n'existe pas");
    joueurs[i]->retirerCarte(c);
}
Carte* Jeu::retirerCarteJoueur(size_t i,string& nom){
    if (i>nbJoueurs) throw JeuException("Le joueur n'existe pas");
    joueurs[i]->retirerCarte(nom);
}

void Jeu::changerMoneyJoueur(size_t i,int n){
    if (i>nbJoueurs) throw JeuException("Le joueur n'existe pas");
    joueurs[i]->changerMoney(n);
}
void Jeu::changerDesJoueur(size_t i,int n){
    if (i>nbJoueurs) throw JeuException("Le joueur n'existe pas");
    joueurs[i]->changerDes(n);
}

void Jeu::afficherJeu() {
    if (joueurs.size()==0) throw JeuException("Aucun joueur, rien a afficher");
    vector<Joueur*>::iterator it;
    for (it=joueurs.begin();it!=joueurs.end();it++)
    {
        cout << **it;
    }
}



//**--------------------Classe Jeu---------------------**//


//----------------------Fonctions supplementaires-------------------------//
//**------------------Fonctions supplementaires-------------------------**//
