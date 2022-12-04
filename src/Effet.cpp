#include "Effet.h"
#include "Joueur.h"
#include "fonctions.h"


//****************class Effet*******************//

void Effet::ajouterPieces(Joueur* j, int nbPieces) {
	j->changerMoney(j->getMoney() + nbPieces);
}

void Effet::volerPieces(Joueur* j1, Joueur* j2, unsigned int pieces) {
	//vole le nombre de pieces de j2 pour le donner a j1
	if (j2->getMoney() >= pieces) {
		j1->changerMoney(j1->getMoney() + pieces);
		j2->changerMoney(j2->getMoney() - pieces);

	}
	else {
		j1->changerMoney(j1->getMoney() + j2->getMoney());
		j2->changerMoney(0);
	}
}

void Effet::echangerCarte(Joueur* j1, vector<Joueur*> vectJoueur) {
	if (j1->getPaquet().getCarteType(Type::tour).size() != j1->getPaquet().getContener().size()) {

		bool terminer = false;
		int position = fonctions::recupPosition(j1, vectJoueur);
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


		Paquet paquetJChoisi = jChoisi->getPaquet();
		Paquet paquetJ1 = j1->getPaquet();

		cout << "\n" << paquetJChoisi << "\n";
		cout << "Attention vous ne pouvez pas choisir une carte de type Tour" << "\n";
		cout << "Carte a prendre" << "\n";
		Carte* cJChoisi = nullptr;
		terminer = false;
		while (!terminer) {
			cJChoisi = fonctions::choisirCarte(paquetJChoisi.getContener());
			if (cJChoisi->getType() != Type::tour)
				terminer = true;
			else
				cout << "Erreur la carte choisi est de type tour" << "\n";
		}

		cout << "\n" << paquetJ1 << "\n";
		cout << "Attention vous ne pouvez pas choisir une carte de type Tour" << "\n";
		cout << "Carte a donner" << "\n";
		Carte* cJ1 = nullptr;
		terminer = false;
		while (!terminer) {
			cJ1 = fonctions::choisirCarte(paquetJ1.getContener());
			if (cJ1->getType() != Type::tour)
				terminer = true;
			else
				cout << "Erreur la carte choisi est de type tour" << "\n";
		}

		jChoisi->retirerCarte(cJChoisi);
		jChoisi->ajouterCarte(cJ1);
		j1->ajouterCarte(cJChoisi);
		j1->retirerCarte(cJ1);

		cout << "\n" << "----------resume-------------" << "\n";
		cout << j1->getPseudo() << " a pris la carte " << cJChoisi->getNom()
			<< " a " << jChoisi->getPseudo() << " et lui a donner " << cJ1->getNom() << "\n\n";
	}
	else
		cout << "Activation de l'effet impossible " << j1->getPseudo() << " n'a pas de carte a echanger" << "\n";
}

int Effet::runEffect(Joueur* j1, vector<Joueur*> vectJoueur) {
	//violet
	//retour = 0 effet effectuer, retour = 1 aucun effet fait mais normal, retour = -1 pas d'effet trouver
	if (ferme) {
		ferme = false;
		return 1;
	}
	if (volePiecesChaqueJoueur) {
		cout << "\n" << "------------Voler a tout le monde------------" << "\n";
		//cas ou j1 prend de l'azrgent a tous les joueurs
		for (auto n : vectJoueur)
			if (j1 != n)
				volerPieces(j1, n, piecesEnJeu);
		cout << "\n";
		return 0;
	}
	if (echangeCarte) {
		//cas ou j1 echange un joueur choisi
		cout << "\n" << "------------Echange de carte------------" << "\n";
		echangerCarte(j1, vectJoueur);
		cout << "\n";
		return 0;
	}

	if (volePieces && choixJoueur) {
		//cas ou j1 peut choisir de voler de l'argent a un joueur
		cout << "\n" << "------------Voler au joueur choisi------------" << "\n";
		int cpt = 1;
		for (auto n : vectJoueur)
			if (j1 != n) {
				cout << "Joueur n " << cpt << *n << "\n";
				cpt++;
			}
		Joueur* jChoisi;
		jChoisi = fonctions::choisirJoueur(j1, vectJoueur);
		volerPieces(j1, jChoisi, piecesEnJeu);
		cout << "\n";
		return 0;
	}
	return -1;
}


int Effet::runEffect(Joueur* j1, Joueur* j2) {
	//rouges
	//j1 est le joueur qui est benefique de l'effet

	if (ferme) {
		ferme = false;
		return 1;
	}

	if (volePieces && !choixJoueur) {
		//cas ou j1 prend de l'argent a j2
		cout << "\n" << "------------Voler des Pieces------------" << "\n";
		volerPieces(j1, j2, piecesEnJeu);
		cout << "\n";
		return 0;
	}
    return -1;
}

int Effet::runEffect(Joueur* j1) {
	//bleu et verte

	if (ferme) {
		ferme = false;
		return 1;
	}

	if (recevoirPieces) {
		//cas ou j1 prend de l'argent
		cout << "\n" << "------------Recevoir des pieces------------" << "\n";
		ajouterPieces(j1, piecesEnJeu);
		cout << "\n";
		return 0;
	}
	if (recevoirPiecesNbEtablissement) {
		//cas ou on recoit un certains nombre de pi�ces en fonctions des
		cout << "\n" << "------------Recevoir des pieces en fonction d'un type------------" << "\n";
		ajouterPieces(j1, j1->getPaquet().getCarteType(typeConcerne).size() * piecesEnJeu);
		cout << "\n";
		return 0;

	}
    return -1;
}
//****************class Effet*******************//

//****************class EffetClassique*******************//*

int EffetClassique::runEffect(Joueur* j1, vector<Joueur*> vectJoueur) {
	if (getFerme()) {
		setFerme(false);
		return 1;
	}
	Effet::runEffect(j1, vectJoueur);
	return -1;
}

int EffetClassique::runEffect(Joueur* j1, Joueur* j2) {
	if (getFerme()) {
		setFerme(false);
		return 1;
	}
	Effet::runEffect(j1, j2);
	return -1;
}

int EffetClassique::runEffect(Joueur* j1) {
	if (getFerme()) {
		setFerme(false);
		return 1;
	}
	if (gare) {
		j1->changerDes(2);
		return 0;
	}
	Effet::runEffect(j1);
	return -1;
}
//****************class EffetClassique*******************//

//********************Fonctions supplementaires**************************//
ostream& operator<<(ostream& f, const Effet& e) {
	f << e.getDescription();
	return f;
}
//********************Fonctions supplementaires**************************//

