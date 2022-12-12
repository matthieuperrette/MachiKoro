#pragma once
#ifndef EFFET_H
#define EFFET_H
#include <vector>
#include <iostream>
#include "Carte.h"

using namespace std;
class Joueur;


class EffetException {
public:
	EffetException(const string& i) :info(i) {}
	string getInfo() const { return info; }
private:
	string info;
};

class Effet {
protected:
	//bool ferme;
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
		bool choixJoueur = false, Type typeConcerne = Type::champ) :
		description(description), piecesEnJeu(piecesEnJeu), recevoirPieces(recevoirPieces),
		volePieces(volePieces), echangeCarte(echangeCarte),
		volePiecesChaqueJoueur(volePiecesChaqueJoueur),
		recevoirPiecesNbEtablissement(recevoirPiecesNbEtablissement),
		choixJoueur(choixJoueur), typeConcerne(typeConcerne) {}
	virtual ~Effet() = default;

	void ajouterPiecesEnJeu(unsigned int n) { piecesEnJeu += n; }
	void enleverPiecesEnJeu(unsigned int n) { piecesEnJeu -= n; }

	virtual int runEffect(Joueur* j1, vector<Joueur*> vectJoueur);
	virtual int runEffect(Joueur* j1);
	virtual int runEffect(Joueur* j1, Joueur* j2);
	void enleverPieces(Joueur* j, int nbPieces);
	void ajouterPieces(Joueur* j, int nbPieces);
	void volerPieces(Joueur* j1, Joueur* j2, unsigned int pieces);//vole le nombre de pieces de j2 pour le donner a j1
	void echangerCarte(Joueur* j1, vector<Joueur*> vectJoueur);
	int getNbmonumentSaufHotelDeVille(Joueur* j);
};

class EffetClassique : public Effet {
protected:
	bool gare;
public:
	EffetClassique(string description, unsigned int piecesEnJeu = 0, bool gare = false, bool recevoirPieces = false,
		bool volePieces = false, bool echangeCarte = false, bool volePiecesChaqueJoueur = false,
		bool recevoirPiecesNbEtablissement = false, bool choixJoueur = false, Type typeConcerne = Type::champ)
		: gare(gare),
		Effet(description, piecesEnJeu, recevoirPieces, volePieces, echangeCarte, volePiecesChaqueJoueur, recevoirPiecesNbEtablissement, choixJoueur, typeConcerne) {}
	~EffetClassique() = default;

	int runEffect(Joueur* j1, vector<Joueur*> vectJoueur) override;
	int runEffect(Joueur* j1) override;
	int runEffect(Joueur* j1, Joueur* j2) override;

};

//****************class Effet*******************//

//********************Fonctions supplementaires**************************//
ostream& operator<<(ostream& f, const Effet& e);
//********************Fonctions supplementaires**************************//


#endif 