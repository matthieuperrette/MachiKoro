#pragma once
#include <vector>
class Carte;
class Joueur;


namespace fonctions {

	//fonction qui renvoie un vecteur avec un pointeur sur chaque carte de l'edition classique
	// ATTENTION IL FAUT DELETE TOUTES LES CARTES CAR L'ALLOCATION EST DYNAMIQUE
	//a terme a integrer a jeu
    std::vector<Carte*> cartesEditionClassique();

    std::vector<Carte*> cartesEditionMarina();

    std::vector<Carte*> cartesEditionGreenValley();

	//recupere la position de j1 dans le vecteur vectJoueur (1er position est 0)
    int recupPositionJoueur(Joueur* j1, std::vector<Joueur*> vectJoueur);

	//fais choisir a un joueur parmis les joueurs les joueurs ne sont pas affiches
    Joueur* choisirJoueur(Joueur* j, std::vector<Joueur*> vectJoueur);

	//fais choisir une carte les ccartes ne sont pas affiches
    Carte* choisirCarte(std::vector <Carte*> cartes);

    Carte* choisirMonumentSauf(Joueur* j, std::string& nom);

    Carte* choisirCarteVioletteSauf(Joueur* j, std::string& nom);

    int recupPositionCarte(std::string& nom, std::vector <Carte*> cartes);

    std::vector<Carte*> cartesEditionGreenValley();

	Type choisirType();

    std::vector<Carte*> cartesEditionMarina();

<<<<<<< HEAD
    void screenInit();
    void screenStop();

    unsigned int lancementDes(Joueur* currentJoueur,bool& doubleDes);


    vector<Carte*> getCartesActivables(vector<Carte*>& vecteur, unsigned int& desResult);

    void interpretation(Joueur* currentJoueur, unsigned int& desResult);

    vector<Carte*> affichageCartesAchetables(Joueur* currentJoueur);

    int transfert(Joueur* currentJoueur);

    void buyingManager(Joueur* currentJoueur);

}
=======
	void screenInit();
	void screenStop();

	unsigned int lancementDes(Joueur* currentJoueur, bool& doubleDes);


    std::vector<Carte*> getCartesActivables(std::vector<Carte*>& vecteur, unsigned int& desResult);

	void interpretation(Joueur* currentJoueur, unsigned int& desResult);

    std::vector<Carte*> affichageCartesAchetables(Joueur* currentJoueur);

	int transfert(Joueur* currentJoueur);

	void buyingManager(Joueur* currentJoueur);

}
>>>>>>> c816a9e (plus d'accent et de namespace std)
