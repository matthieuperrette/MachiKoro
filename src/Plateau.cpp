//
// Created by Antoine Sesini on 26/11/2022.
//

#include "Plateau.h"



//****************class Plateau*******************//

//**************Structure***************//
Plateau::Plateau(vector<Carte*> cartesJeu) {
    /*Regle :
     * On fait des paquets de 6 partout
     * Paquets de nb joueurs violettes
     * Paquets de nb joueurs monuments
     * */
    //Dans l'absence de nbJoueurs on utilise pour le moment :
    int nbJoueurs=4; //ATTENTION ! A MODIFIER
    remplir=false; //car nous n'aurons pas à remplir le plateau par la suite quand des paquets seront supprimés car vides

    int i=0;
    for(auto c : cartesJeu)
    {
        Paquet* newPaquet=new Paquet;
        if (c->getCouleur()==Couleur::monument || c->getCouleur()==Couleur::violet)
        {
           for (i=0; i<nbJoueurs; i++)
           {
               newPaquet->ajouterCarte(c);
           }
        }
        else
        {
            for (i=0; i<6; i++)
            {
                newPaquet->ajouterCarte(c);
            }
        }
        cartes.push_back(newPaquet);
    }
}



Plateau::Plateau(vector<Carte*> cartesJeu, Pioche p){

}

Plateau::~Plateau(){
    for (auto p : cartes)
        delete p;
}
//**************Structure***************//






//Espace de définition des get et autres méthodes d'utilisation//

Paquet& Plateau::getPaquetByNom(string& nom){
    for (auto p: cartes)
        if (p->getCarte(0).getNom()==nom) //Si la première carte du paquet a le nom "nom"
        {
            return *p;
        }
}

vector<Paquet*> Plateau::getAllPaquets(){
    return cartes;
}

unsigned int Plateau::getNbPaquets(){
    return cartes.size();
}

Carte* Plateau::retirerCarte(string nom){

}

Carte* ajouterCarte(Carte*){

}
//Espace de définition des get et autres méthodes d'utilisation//


//****************class Plateau*******************//





ostream& operator<<(ostream& f, const Plateau& p){

}