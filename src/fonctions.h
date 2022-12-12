#pragma once
#include <vector>
class Carte;
class Joueur;

namespace fonctions {

	vector<Carte*> cartesEditionClassique();

	vector<Carte*> cartesEditionMarina();

	vector<Carte*> cartesEditionGreenValley();

	//recupere la position de j1 dans le vecteur vectJoueur (1er position est 0)
	int recupPositionJoueur(Joueur* j1, vector<Joueur*> vectJoueur);

	//fais choisir a un joueur parmis les joueurs les joueurs ne sont pas affiches
	Joueur* choisirJoueur(Joueur* j, vector<Joueur*> vectJoueur);

	//fais choisir une carte les ccartes ne sont pas affiches
	Carte* choisirCarte(vector <Carte*> cartes);

	Carte* choisirMonumentSauf(Joueur* j, string& nom);

	Carte* choisirCarteVioletteSauf(Joueur* j, string& nom);

	int recupPositionCarte(string& nom, vector <Carte*> cartes);

	Type choisirType();

}