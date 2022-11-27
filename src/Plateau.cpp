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

Carte* Plateau::retirerCarte(string& nom){ //le but est de parvenir à retirer des cartes par nom
    //Si l'utilisateur choisit de récupérer une carte depuis le paquet nommé
    //Alors on enleve la carte (method retirerCarte())
    //On la retourne
    //Si le paquet dans lequel on pioche devient vide -> on le supprime puis :
    //Si on a remplir = true alors on rerempli en utilisant la pioche de départ
    //Sinon on ne fait rien
}

void Plateau::remplirPlateau() { //Cette fonction est appelée lorsque retirerCarte se retrouve avec un paquetvide et la necéssité de remplir
   //On va piocher et créer des paquets jusqu'à ce que cartes.size==10;
}


//Espace de définition des get et autres méthodes d'utilisation//


//****************class Plateau*******************//





ostream& operator<<(ostream& f, const Plateau& p){
    //On rentre dansn une boucle sur p.getAllPaquets
    //On affiche chaque paquet
    //Si on veut afficher peu de choses, on règle l'affichage de manière à ce qu'il soit minimal
}