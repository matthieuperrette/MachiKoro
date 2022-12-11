#include "Effet.h"
#include "EffetMarina.h"
#include "Joueur.h"
#include "fonctions.h"



int EffetMarina::runEffect(Joueur* j1, vector<Joueur*> vectJoueur) {

	if (maisonEdition) {
		//cout << "\n" << "------------Recevoir une piece de chaque joueur pour chaque carte de type cafe et magasin------------" << "\n";
		for (auto joueur : vectJoueur) {
			if (joueur != j1) {
				int nbCafe = joueur->getPaquet().getCarteType(Type::cafe).size();
				int nbMagasin = joueur->getPaquet().getCarteType(Type::magasin).size();
				cout << "nb cafe " << nbCafe << "\n";
				cout << "nb magasin " << nbMagasin << "\n";
				if (nbCafe > 0 || nbMagasin > 0)
					volerPieces(j1, joueur, nbCafe + nbMagasin);
			}
		}
		return 0;
	}
	if (tax) {
		//cout << "\n" << "------------Voler la moitie des pieces de chaque joueur ayant plus de 10 pieces------------" << "\n";
		for (auto joueur : vectJoueur) {
			if (joueur != j1) {
				int argentJoueur = joueur->getMoney();
				if (argentJoueur >= 10) {
					volerPieces(j1, joueur, argentJoueur / 2);
				}


			}
		}
		return 0;
	}
	int retour = EffetClassique::runEffect(j1, vectJoueur);
	return retour;
}

int EffetMarina::runEffect(Joueur* j1, Joueur* j2) {

	if (volerAvecPort) {
		//cas ou j1 prend de l'argent a j2
		//cout << "\n" << "------------Voler des Pieces si le joueur a un port------------" << "\n";
		string port = "Port";
		if (j1->getPaquet().is_In(port)) {
			//cout << "dans le if \n";
			volerPieces(j1, j2, piecesEnJeu);
		}
		return 0;
	}
	int retour = EffetClassique::runEffect(j1, j2);
	return retour;
}

int EffetMarina::runEffect(Joueur* j1) {
	if (recevoirAvecPort) {
		//cout << "\n" << "------------Recevoir des pieces si le joueur a le port------------" << "\n";
		string port = "Port";
		if (j1->getPaquet().is_In(port))
			ajouterPieces(j1, piecesEnJeu);
		return 0;
	}
	if (recevoirPieceChaqueChampDeFleurs) {
		//cout << "\n" << "------------Recevoir des pieces nb champ de fleurs------------" << "\n";
		string champDeFleurs = "Champ de fleurs";
		int nbChampDeFleurs = j1->getPaquet().getCarteNom(champDeFleurs).size();
		//cout << "nb champ de fleurs " << nbChampDeFleurs << "\n";
		if (nbChampDeFleurs > 0)
			ajouterPieces(j1, nbChampDeFleurs * piecesEnJeu);
		return 0;
	}
	int retour = EffetClassique::runEffect(j1);
	return retour;
}
//****************class EffetClassique*******************//