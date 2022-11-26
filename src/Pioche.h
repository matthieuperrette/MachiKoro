#pragma once
#include "Paquet.h"

//****************class Pioche*******************//

class Pioche : public Paquet {
public:
	Carte* piocher();
	Pioche(vector<Carte*> cartes, int nb_joueurs);

};

//****************class Pioche*******************//

//****************Fonctions supplémentaires******************//
ostream& operator<<(ostream& f, const Pioche& p);
//****************Fonctions supplémentaires******************//
