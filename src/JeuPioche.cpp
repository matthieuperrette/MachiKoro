#include"JeuPioche.h"

//------------Classe JeuPioche----------//
void JeuPioche::init(vector<Carte*> cartes) {
    pioche = new Pioche(cartes, nbJoueurs);
    JeuPlateau::init(cartes, *pioche);
}
//------------Classe JeuPioche----------//