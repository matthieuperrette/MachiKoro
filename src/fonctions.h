#pragma once
#include <vector>
class Carte;
class Joueur;
class Controleur;

namespace fonctions {

	//fonction qui renvoie un vecteur avec un pointeur sur chaque carte de l'edition classique
	// ATTENTION IL FAUT DELETE TOUTES LES CARTES CAR L'ALLOCATION EST DYNAMIQUE
	//a terme a integrer a jeu
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

	vector<Carte*> cartesEditionGreenValley();

	Type choisirType();

	vector<Carte*> cartesEditionMarina();

    void screenInit();
    void screenStop();

    unsigned int lancementDes(Joueur* currentJoueur);

    vector<Carte*> getCartesActivables(vector<Carte*>& vecteur, unsigned int& desResult);

    void interpretation(unsigned int& desResult);

    void buyingManager(Joueur* currentJoueur);
}