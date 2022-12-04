#pragma once
#ifndef EFFET_H
#define EFFET_H
#include <vector>
#include <iostream>
#include "Carte.h"

using namespace std;
class Joueur;


class Effet {
private:
	bool ferme;
	string description;
	unsigned int piecesEnJeu;
	bool recevoirPieces;
	bool volePieces;
	bool echangeCarte;
	bool volePiecesChaqueJoueur;
	bool recevoirPiecesNbEtablissement;
	Type typeConcerne;
	bool choixJoueur;
public:
	string getDescription() const { return description; }

	Effet(string description, unsigned int piecesEnJeu = 0, bool recevoirPieces = false, bool volePieces = false,
		bool echangeCarte = false, bool volePiecesChaqueJoueur = false, bool recevoirPiecesNbEtablissement = false,
		bool choixJoueur = false, Type typeConcerne = Type::champ, bool ferme = false) :
		description(description), piecesEnJeu(piecesEnJeu), recevoirPieces(recevoirPieces),
		volePieces(volePieces), echangeCarte(echangeCarte),
		volePiecesChaqueJoueur(volePiecesChaqueJoueur),
		recevoirPiecesNbEtablissement(recevoirPiecesNbEtablissement),
		choixJoueur(choixJoueur), typeConcerne(typeConcerne), ferme(ferme) {}
	virtual ~Effet() = default;

	bool getFerme() const { return ferme; }
	void setFerme(bool b) { ferme = b; }
	void ajouterPiecesEnJeu(unsigned int n) { piecesEnJeu += n; }
	void enleverPiecesEnJeu(unsigned int n) { piecesEnJeu -= n; }

	virtual int runEffect(Joueur* j1, vector<Joueur*> vectJoueur);
	virtual int runEffect(Joueur* j1);
	virtual int runEffect(Joueur* j1, Joueur* j2);
	void ajouterPieces(Joueur* j, int nbPieces);
	void volerPieces(Joueur* j1, Joueur* j2, unsigned int pieces);//vole le nombre de pieces de j2 pour le donner a j1
	void echangerCarte(Joueur* j1, vector<Joueur*> vectJoueur);
};

class EffetClassique : public Effet {
private:
	bool gare;
public:
	EffetClassique(string description, unsigned int piecesEnJeu = 0, bool gare = false, bool recevoirPieces = false,
		bool volePieces = false, bool echangeCarte = false, bool volePiecesChaqueJoueur = false,
		bool recevoirPiecesNbEtablissement = false, bool choixJoueur = false, Type typeConcerne = Type::champ,
		bool ferme = false) : gare(gare),
		Effet(description, piecesEnJeu, recevoirPieces, volePieces, echangeCarte, volePiecesChaqueJoueur, recevoirPiecesNbEtablissement, choixJoueur, typeConcerne, ferme) {}
	~EffetClassique() = default;

	int runEffect(Joueur* j1, vector<Joueur*> vectJoueur);
	int runEffect(Joueur* j1);
	int runEffect(Joueur* j1, Joueur* j2);

};

//****************class Effet*******************//

//********************Fonctions supplementaires**************************//
ostream& operator<<(ostream& f, const Effet& e);
//********************Fonctions supplementaires**************************//


#endif 