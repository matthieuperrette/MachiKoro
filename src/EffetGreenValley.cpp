#include "Effet.h"
#include "JeuClassique.h"
#include "EffetGreenValley.h"
#include "Joueur.h"
#include "fonctions.h"
#include "Controleur.h"


void EffetGreenValley::donnerCarte(Joueur* j1) {
	vector <Joueur*> vectJoueur = Controleur::getControleur().getJeu()->getJoueursList();
	if (j1->getPaquet().getCarteType(Type::tour).size() != j1->getPaquet().getContener().size()) {
		cout << "Vous devez donner une carte" << "\n";
		bool terminer = false;
		int position = fonctions::recupPositionJoueur(j1, vectJoueur);
		int cpt = 1;
		//potentiel erreurs si vect joueur vide ou s'il y a des paquets vides

		for (auto n : vectJoueur)
			if (j1 != n) {
				cout << "Joueur n " << cpt << *n << "\n";
				cpt++;
			}
		Joueur* jChoisi = nullptr;
		while (!terminer) {
			jChoisi = fonctions::choisirJoueur(j1, vectJoueur);
			if (jChoisi->getPaquet().getCarteType(Type::tour).size() != jChoisi->getPaquet().getContener().size())
				terminer = true;
			else
				cout << "Erreur " << jChoisi->getPseudo() << " n'a pas de carte a echanger";
		}


		Paquet paquetJ1 = j1->getPaquet();


		cout << "\n" << paquetJ1 << "\n";
		cout << "Attention vous ne pouvez pas choisir une carte de type Tour" << "\n";
		cout << "Choisissez la carte que vous souhaitez donner" << "\n";
		Carte* cJ1 = nullptr;
		terminer = false;
		while (!terminer) {
			cJ1 = fonctions::choisirCarte(paquetJ1.getContener());
			if (cJ1->getType() != Type::tour)
				terminer = true;
			else
				cout << "Erreur la carte choisi est de type tour" << "\n";
		}

		jChoisi->ajouterCarte(cJ1);
		j1->retirerCarte(cJ1);

		//cout << "\n" << "----------resume-------------" << "\n";
		cout << j1->getPseudo() << " a donner la carte " << cJ1->getNom()
			<< " a " << jChoisi->getPseudo();
	}
	else
		cout << "Activation de l'effet impossible " << j1->getPseudo() << " n'a pas de carte a echanger" << "\n";
}

void EffetGreenValley::equilibrerPieces(vector<Joueur*> joueurs) {
	int ToutesLesPieces = 0;
	for (auto joueur : joueurs) {
		ToutesLesPieces += joueur->getMoney();
		joueur->changerMoney(0);
	}
	int division = ToutesLesPieces / joueurs.size();
	if (division * joueurs.size() < ToutesLesPieces)
		division++;
	for (auto joueur : joueurs)
		joueur->changerMoney(division);

	//resume
	cout << "Tous les joueurs possèdent maintenant " << division << "piece(s)\n";
}


int EffetGreenValley::demolir(Joueur* j1) {

	int nbMonuments = j1->getPaquet().getCarteCouleur(Couleur::monument).size();
	string hdv = "Hotel de Ville";
	int nbHdv = j1->getPaquet().getCarteNom(hdv).size();
	if (nbMonuments == nbHdv) {
		cout << "impossible de detruire un monument" << "\n";
		return -1;
	}
	string hotel = "Hotel de Ville";
	Carte* choix = fonctions::choisirMonumentSauf(j1, hotel);
	j1->retirerCarte(choix);
	Controleur::getControleur().getJeu()->ajouterCartePlateau(choix);
	cout << choix->getNom() << " a ete demoli " << "\n";
	return 0;
}

int EffetGreenValley::runEffect(Joueur* j1, vector<Joueur*> vectJoueur) {
	int retour = EffetMarina::runEffect(j1, vectJoueur);

	//la cvarte est ferme on ne fait pas d'effet
	if (retour == 1) {
		return 1;
	}
	//l'effet a deja ete declencher on peut renvoyer 0
	if (retour == 0) {
		return 0;
	}
	if (equilibrePieces) {
		equilibrerPieces(vectJoueur);
	}
	if (renovation) {
		int nbFerme = 0;
		int i = 1;
		for (auto type : Types)
		{
			cout << "Type n" << i << " : " << "type" << "\n";
		}
		//Type type = fonctions::choisirType();
		Type type = Type::ressource;
		for (auto joueur : vectJoueur) {
			if (joueur != j1)
				nbFerme += j1->fermerOuvrirEtablissement(type, true);
		}
		ajouterPieces(j1, nbFerme * piecesEnJeu);
		cout << "Et a ferme les etablisssements de type " << type << "\n";
	}

	if (recevoirInvestissement) {
		for (auto joueur : vectJoueur) {
			if (joueur != j1)
				volerPieces(j1, joueur, j1->getInvestissement());
		}

		return 0;
	}
	if (activerAutreBatimentViolet) {
		string expo = "Salle d'exposition internationale";
		Carte* choix = fonctions::choisirCarteVioletteSauf(j1, expo);
		vector<Carte*> cartes = j1->getPaquet().getCarteNom(expo);
		j1->retirerCarte(cartes.at(0));
		Controleur::getControleur().getJeu()->ajouterCartePlateau(cartes.at(0));
		cout << expo << " a ete retourne au marche " << "\n";
		choix->runEffect(j1, vectJoueur);
		return 0;
	}

	return -1;
}

int EffetGreenValley::runEffect(Joueur* j1, Joueur* j2) {
	int retour = EffetMarina::runEffect(j1, j2);
	//la cvarte est ferme on ne fait pas d'effet
	if (retour == 1) {
		return 1;
	}
	//l'effet a deja ete declencher on peut renvoyer 0
	if (retour == 0) {
		return 0;
	}

	if (volerAvecPlusDeNMonuments) {
		if (getNbmonumentSaufHotelDeVille(j1) >= nMonuments)
			volerPieces(j1, j2, piecesEnJeu);
		return 0;
	}
	if (volerToutAvecPlusDeNMonuments) {
		if (getNbmonumentSaufHotelDeVille(j1) >= nMonuments)
			volerPieces(j1, j2, j2->getMoney());
		return 0;
	}

	return -1;
}

int EffetGreenValley::runEffect(Joueur* j1) {
	int retour = EffetMarina::runEffect(j1);

	//la cvarte est ferme on ne fait pas d'effet
	if (retour == 1) {
		return 1;
	}
	//l'effet a deja ete declencher on peut renvoyer 0
	if (retour == 0) {
		return 0;
	}

	if (recevoirAvecMoinsDeNMonuments) {
		if (getNbmonumentSaufHotelDeVille(j1) < nMonuments)
			ajouterPieces(j1, piecesEnJeu);
		return 0;
	}

	if (donnerCarteEtRecevoir) {
		donnerCarte(j1);
		ajouterPieces(j1, piecesEnJeu);
		return 0;
	}

	if (payerPieces) {
		enleverPieces(j1, piecesEnJeu);
		return 0;
	}

	if (recevoirPieceChaqueVignoblePuisFermer) {
		string vignoble = "Vignoble";
		int nbVignobles = j1->getPaquet().getCarteNom(vignoble).size();
		//cout << "nb champ de fleurs " << nbChampDeFleurs << "\n";
		if (nbVignobles > 0)
			ajouterPieces(j1, nbVignobles * piecesEnJeu);
		for (int i = 0; i < nbVignobles; i++)
			j1->fermerOuvrirEtablissement(vignoble, true);
		return 0;
	}

	if (demolirMonumentPuisRecevoir) {
		demolir(j1);
		ajouterPieces(j1, piecesEnJeu);
		return 0;
	}

	if (pourChaqueTypePourTousLesJoueursRecevoir) {
		vector<Joueur*> joueurs = Controleur::getControleur().getJeu()->getJoueursList();
		int nbCafe = 0;
		for (auto joueur : joueurs) {
			nbCafe += joueur->getPaquet().getCarteType(typeConcerne).size();
		}
		ajouterPieces(j1, piecesEnJeu * nbCafe);
		return 0;
	}


	return -1;
}
//****************class EffetClassique*******************//