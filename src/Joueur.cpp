//
// Created by Antoine Sesini on 29/11/2022.
//
#include "Joueur.h"


//****************class Joueur*******************//




//Constructeurs et destructeurs//
//ILS SONT TOUS DEJA DEFINIS DE BASE
//Constructeurs et destructeurs//



//Methods de service//
void Joueur::ajouterCarte(Carte* carte) {
    if (carte != nullptr)
        cartes.ajouterCarte(carte);
    else
        throw JoueurException("La carte a ajouter n'existe pas !");
}
Carte* Joueur::retirerCarte(Carte* carte) {
    if (carte != nullptr)
        cartes.retirerCarte(carte);
    else
        throw JoueurException("La carte a retirer n'existe pas !");
    return carte;
}

Carte* Joueur::retirerCarte(string& nom) {
    return cartes.retirerCarte(nom);
}

//Methods de service//


//****************class Joueur*******************//




//********************Fonctions supplementaires**************************//
ostream& operator<<(ostream& f, const Joueur& joueur) {
    f << "**-> PSEUDONYME : " << joueur.getPseudo() << "\n";
    f << "**-> IA         : " << ((joueur.getIa()) ? ("OUI") : ("NON")) << "\n";
    f << "**-> PAQUET     : " << joueur.getPaquet().getNbCartes() << " CARTE(S)\n";
    f << "**-> MONEY      : " << joueur.getMoney() << "\n";
    f << "**-> NB DE DES  : " << joueur.getDes() << "\n";

    return f;
}
//********************Fonctions supplementaires**************************//

