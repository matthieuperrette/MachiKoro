#include "Pioche.h"


//****************class Pioche*******************//

Carte* Pioche::piocher() {
	int nb_cartes = getNbCartes();
	//random entre 0 et le nombre de carte - 1
	int random = rand() % (nb_cartes);
	Carte& c = getCarte(random);
	retirerCarte(&c);
	return &c;
};

Pioche::Pioche(vector<Carte*> cartes, int nb_joueurs) {
	Paquet();
	for (auto c : cartes) {
		if (c->getCouleur() == Couleur::violet)
			for (size_t i = 0; i < nb_joueurs; i++)
				ajouterCarte(c);//cartes violettes il y en a une par joueur
		else if (c->getCouleur() != Couleur::monument)
			for (size_t i = 0; i < 6; i++)
				ajouterCarte(c);//autres cartes sauf les monuments il y en a 6 de chaque
	}
}

//****************class Pioche*******************//


//****************Fonctions suppl�mentaires******************//

ostream& operator<<(ostream& f, const Pioche& p)
{
	f << "/**********Affichage Pioche**********/\n";
	int i = 1;
	vector<Carte*>cartes = p.getContener();
	for (auto c : cartes)
	{
		f << "Carte n." << i;
		f << *c << "\n";
		i++;
	}
	f << "/**********Pioche Affiche**********/\n";
	return f;
}

//****************Fonctions suppl�mentaires******************//
