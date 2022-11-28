#pragma once
#include "Paquet.h"

//****************class Pioche*******************//

class Pioche : public Paquet {
public:
	Carte* piocher();
	Pioche(vector<Carte*> cartes, int nb_joueurs);
    Pioche(){Paquet();}
};

//****************class Pioche*******************//

//****************Fonctions suppl�mentaires******************//
ostream& operator<<(ostream& f, const Pioche& p);
//****************Fonctions suppl�mentaires******************//
