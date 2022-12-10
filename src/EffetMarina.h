#pragma once

#include <vector>
#include <iostream>
#include "Effet.h"
#include "Carte.h"
using namespace std;
class Joueur;


class EffetMarina : public EffetClassique {
protected:
	bool recevoirAvecPort;
	bool recevoirPieceChaqueChampDeFleurs;
	bool volerAvecPort;
	bool maisonEdition;
	bool tax;


public:
	EffetMarina(string description, unsigned int piecesEnJeu = 0, bool recevoirAvecPort = false,
		bool recevoirPieceChaqueChampDeFleurs = false, bool volerAvecPort = false,
		bool maisonEdition = false, bool tax = false, bool recevoirPieces = false,
		bool volePieces = false, bool echangeCarte = false, bool volePiecesChaqueJoueur = false,
		bool recevoirPiecesNbEtablissement = false, bool choixJoueur = false, Type typeConcerne = Type::champ,
		bool ferme = false, bool gare = false) : recevoirAvecPort(recevoirAvecPort),
		recevoirPieceChaqueChampDeFleurs(recevoirPieceChaqueChampDeFleurs), volerAvecPort(volerAvecPort),
		maisonEdition(maisonEdition), tax(tax),
		EffetClassique(description, piecesEnJeu, gare, recevoirPieces, volePieces, echangeCarte, volePiecesChaqueJoueur, recevoirPiecesNbEtablissement, choixJoueur, typeConcerne, ferme) {}
	~EffetMarina() = default;



	int runEffect(Joueur* j1, vector<Joueur*> vectJoueur) override;
	int runEffect(Joueur* j1) override;
	int runEffect(Joueur* j1, Joueur* j2) override;

};

//****************class Effet*******************//

//********************Fonctions supplementaires**************************//
ostream& operator<<(ostream& f, const Effet& e);
//********************Fonctions supplementaires**************************//


