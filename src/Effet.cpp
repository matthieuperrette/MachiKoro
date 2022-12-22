#include "Effet.h"
#include "Joueur.h"
#include "fonctions.h"


//****************class Effet*******************//

void Effet::ajouterPieces(Joueur* j, int nbPieces) {
	j->changerMoney(j->getMoney() + nbPieces);
    std::cout << j->getPseudo() << " a gagne " << nbPieces << " piece(s)" << "\n";
}

void Effet::enleverPieces(Joueur* j, int nbPieces) {
	if (j->getMoney() >= nbPieces) {
		j->changerMoney(j->getMoney() - nbPieces);
        std::cout << j->getPseudo() << " a perdu " << nbPieces << " piece(s)" << "\n";
	}else 
        std::cout << j->getPseudo() << " a perdu 0 piece(s)" << "\n";
}

void Effet::volerPieces(Joueur* j1, Joueur* j2, unsigned int pieces) {
	//vole le nombre de pieces de j2 pour le donner a j1
	int piecesPrises;
	if (j2->getMoney() >= pieces) {
		j1->changerMoney(j1->getMoney() + pieces);
		j2->changerMoney(j2->getMoney() - pieces);
		piecesPrises = pieces;

	}
	else {
		piecesPrises = j2->getMoney();
		j1->changerMoney(j1->getMoney() + piecesPrises);
		j2->changerMoney(0);
	}
    std::cout << j1->getPseudo() << " a pris " << piecesPrises << " piece(s) a " << j2->getPseudo() << "\n";
}

void Effet::echangerCarte(Joueur* j1, std::vector<Joueur*> vectJoueur) {
	if (j1->getPaquet().getCarteType(Type::tour).size() != j1->getPaquet().getContener().size()) {
        std::cout << "Vous pouvez echanger une carte" << "\n";
		bool terminer = false;
		int position = fonctions::recupPositionJoueur(j1, vectJoueur);
		int cpt = 1;
		//potentiel erreurs si vect joueur vide ou s'il y a des paquets vides

		for (auto n : vectJoueur)
			if (j1 != n) {
                std::cout << "Joueur n " << cpt << *n << "\n";
				cpt++;
			}
		Joueur* jChoisi = nullptr;
		while (!terminer) {
			jChoisi = fonctions::choisirJoueur(j1, vectJoueur);
			if (jChoisi->getPaquet().getCarteType(Type::tour).size() != jChoisi->getPaquet().getContener().size())
				terminer = true;
			else
                std::cout << "Erreur " << jChoisi->getPseudo() << " n'a pas de carte a echanger";
		}


		Paquet paquetJChoisi = jChoisi->getPaquet();
		Paquet paquetJ1 = j1->getPaquet();

        std::cout << "\n" << paquetJChoisi << "\n";
        std::cout << "Attention vous ne pouvez pas choisir une carte de type Tour" << "\n";
        std::cout << "Choisissez la carte que vous souhaitez prendre" << "\n";
		Carte* cJChoisi = nullptr;
		terminer = false;
		while (!terminer) {
			cJChoisi = fonctions::choisirCarte(paquetJChoisi.getContener());
			if (cJChoisi->getType() != Type::tour)
				terminer = true;
			else
                std::cout << "Erreur la carte choisi est de type tour" << "\n";
		}

        std::cout << "\n" << paquetJ1 << "\n";
        std::cout << "Attention vous ne pouvez pas choisir une carte de type Tour" << "\n";
        std::cout << "Choisissez la carte que vous souhaitez donner" << "\n";
		Carte* cJ1 = nullptr;
		terminer = false;
		while (!terminer) {
			cJ1 = fonctions::choisirCarte(paquetJ1.getContener());
			if (cJ1->getType() != Type::tour)
				terminer = true;
			else
                std::cout << "Erreur la carte choisi est de type tour" << "\n";
		}

		jChoisi->retirerCarte(cJChoisi);
		jChoisi->ajouterCarte(cJ1);
		j1->ajouterCarte(cJChoisi);
		j1->retirerCarte(cJ1);

		//cout << "\n" << "----------resume-------------" << "\n";
        std::cout << j1->getPseudo() << " a pris la carte " << cJChoisi->getNom()
			<< " a " << jChoisi->getPseudo() << " et lui a donner " << cJ1->getNom() << "\n\n";
	}
	else
        std::cout << "Activation de l'effet impossible " << j1->getPseudo() << " n'a pas de carte a echanger" << "\n";
}

int Effet::getNbmonumentSaufHotelDeVille(Joueur* j) {
    std::vector <Carte*> monuments = j->getPaquet().getCarteCouleur(Couleur::monument);
	for (auto monument : monuments) {
		if (monument->getNom() == "Hotel de Ville")
			return monuments.size() - 1;
	}
	return monuments.size();
}




int Effet::runEffect(Joueur* j1, std::vector<Joueur*> vectJoueur) {
	//violet
	//retour = 0 effet effectuer, retour = 1 aucun effet fait et on ne veut pas en faire, retour = -1 pas d'effet trouver
	if (volePiecesChaqueJoueur) {
		//cout << "\n" << "------------Voler a tout le monde------------" << "\n";
		//cas ou j1 prend de l'azrgent a tous les joueurs
		for (auto n : vectJoueur)
			if (j1 != n)
				volerPieces(j1, n, piecesEnJeu);
		return 0;
	}
	if (echangeCarte) {
		//cas ou j1 echange un joueur choisi
		//cout << "\n" << "------------Echange de carte------------" << "\n";
		echangerCarte(j1, vectJoueur);
		return 0;
	}

	if (volePieces && choixJoueur) {
		//cas ou j1 peut choisir de voler de l'argent a un joueur
		//cout << "\n" << "------------Voler au joueur choisi------------" << "\n";
		int cpt = 1;
		for (auto n : vectJoueur)
			if (j1 != n) {
                std::cout << "Joueur n " << cpt << *n << "\n";
				cpt++;
			}
		Joueur* jChoisi;
		jChoisi = fonctions::choisirJoueur(j1, vectJoueur);
		volerPieces(j1, jChoisi, piecesEnJeu);
		return 0;
	}
	return -1;
}


int Effet::runEffect(Joueur* j1, Joueur* j2) {
	//rouges
	//j1 est le joueur qui est benefique de l'effet
	if (volePieces && !choixJoueur) {
		//cas ou j1 prend de l'argent a j2
		//cout << "\n" << "------------Voler des Pieces------------" << "\n";
		volerPieces(j1, j2, piecesEnJeu);
		return 0;
	}
	return -1;
}

int Effet::runEffect(Joueur* j1) {
	//bleu et verte
	if (recevoirPieces) {
		//cas ou j1 prend de l'argent
		//cout << "\n" << "------------Recevoir des pieces------------" << "\n";
		ajouterPieces(j1, piecesEnJeu);
		return 0;
	}
	if (recevoirPiecesNbEtablissement) {
		//cas ou on recoit un certains nombre de pieces en fonctions des
		//cout << "\n" << "------------Recevoir des pieces en fonction d'un type------------" << "\n";
		ajouterPieces(j1, j1->getPaquet().getCarteType(typeConcerne).size() * piecesEnJeu);
		return 0;

	}
	return -1;
}
//****************class Effet*******************//

//****************class EffetClassique*******************//*

int EffetClassique::runEffect(Joueur* j1, std::vector<Joueur*> vectJoueur) {
	int retour= Effet::runEffect(j1, vectJoueur);
	return retour;
}

int EffetClassique::runEffect(Joueur* j1, Joueur* j2) {
	int retour = Effet::runEffect(j1, j2);
	return retour;
}

int EffetClassique::runEffect(Joueur* j1) {
	if (gare) {
		j1->changerDes(2);
		return 0;
	}
	int retour = Effet::runEffect(j1);
	return retour;
}
//****************class EffetClassique*******************//

//********************Fonctions supplementaires**************************//
std::ostream& operator<<(std::ostream& f, const Effet& e) {
	f << e.getDescription();
	return f;
}
//********************Fonctions supplementaires**************************//

