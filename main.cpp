#include "./src/Carte.h"
#include "./src/Paquet.h"
#include "./src/Plateau.h"
#include "./src/Joueur.h"
#include "./src/Jeu.h"


using namespace std;

int main() {

	srand((unsigned)time(NULL));
	//test de vecteurs
	//vector<int> vect = { 1, 3 };
	//cout << vect[1] << "\n";

	cout << "test des types d'enum" << "\n";
	//test des types d'enumeration
	try {
		printCouleurs();
		printTypes();
	}
	catch (CarteException& e) {
		cout << e.getInfo() << "\n";
	}

	cout << "test des cartes" << "\n";
	//test des cartes
	//Effet effet;
	//cout << effet.getDescription() << "\n";
	//Carte c1(effet, Couleur::bleu, 2, vect, "Champ de ble", Type::champ);
	//cout << c1;

	vector<Carte*> cartes = fonctions::cartesEditionClassique();
	for (auto n : cartes) {
		cout << *n << "\n";
	}

	cout << "test des paquets" << "\n";
	//test des paquets
	Paquet paquet;
	for (auto n : cartes) {
		paquet.ajouterCarte(n);
	}

	vector<Carte*> cartas;
	try {
		cartas = paquet.getCarteActive(9);
	}
	catch (PaquetException& e) {
		cout << e.getInfo() << "\n";
	}
	for (auto n : cartas) {
		cout << *n << "\n";
	}


	cout << "test de de" << "\n";
	//test du de
	//seed permettant de faire des resultats vraiment aleatoire (on peut pas le mettre dans lancerDe() j'ai tester)


	De de(1, 6);
	cout << de;
	int random;
	for (size_t i = 0; i < 6; i++) {
		random = de.lancerDe();
		cout << random << "\n";
	}

	cout << "test de Pioche" << "\n";
	int nb_joueurs = 4;
	Pioche pioche(cartes, nb_joueurs);
	cout << "affichage pioche debut" << "\n";
	cout << pioche << "\n";
	Carte* c1 = pioche.piocher();
	cout << "c1 :" << *c1 << "\n";
	cout << "affichage pioche apres avoir piocher" << "\n";
	cout << pioche << "\n";

	Pioche pioche2(cartes, 4);
	try {
		Plateau plateau(cartes);
		plateau.afficherPlateau();
		string str = "Antoine";
		Paquet paquettest;
		Joueur player(str, 0, paquettest, 0, 1);
		player.ajouterCarte(cartes[9]);
		cout << "\n" << player << "\n";
		cout << player.getPaquet();

		string str1 = "Fromagerie";
		cout << *(player.retirerCarte(str1));
		cout << "\n" << player << "\n";
		cout << player.getPaquet();
	}
	catch (PaquetException& e) {
		cout << e.getInfo() << "\n";
	}

	Paquet paquetAntoine;
	paquetAntoine.ajouterCarte(cartes[0]);
	paquetAntoine.ajouterCarte(cartes[0]);
	paquetAntoine.ajouterCarte(cartes[0]);
	paquetAntoine.ajouterCarte(cartes[1]);
	Paquet paquetMatthieu;
	paquetMatthieu.ajouterCarte(cartes[0]);
	paquetMatthieu.ajouterCarte(cartes[1]);
	Paquet paquetHarry;
	paquetHarry.ajouterCarte(cartes[7]);
	//paquetHarry.ajouterCarte(cartes[0]);
	//paquetMatthieu.ajouterCarte(cartes[1]);
	Paquet paquetMathieu;
	paquetMathieu.ajouterCarte(cartes[1]);
	paquetMathieu.ajouterCarte(cartes[0]);
	Joueur player1("Antoine", 0, paquetAntoine, 0, 1);
	Joueur player2("Matthieu", 0, paquetMatthieu, 2, 1);
	Joueur player3("Harry", 0, paquetHarry, 10, 1);
	Joueur player4("Mathieu", 0, paquetMathieu, 0, 1);
	vector <Joueur*> joueurs = { &player1, &player2 , &player3 ,&player4 };
	string chaine = "test";

	cout << "___________test Recevoir____________" << "\n";
	//recevoir fonctionne
	Effet* effetRecevoir = new Effet(chaine, 2, true);
	cout << "___________Joueur avant effet____________" << "\n";
	cout << player1 << "\n";
	effetRecevoir->runEffect(&player1);
	cout << "___________Joueur apres effet____________" << "\n";
	cout << player1 << "\n";

	cout << "___________test voler____________" << "\n";
	//voler
	Effet* effetvoler = new Effet(chaine, 3, false, true);
	cout << "___________Joueur avant effet____________" << "\n";
	cout << player1 << "\n";
	cout << player2 << "\n";
	cout << player3 << "\n";
	effetvoler->runEffect(&player1, &player2);
	effetvoler->runEffect(&player2, &player3);
	cout << "___________Joueur apres effet____________" << "\n";
	cout << player1 << "\n";
	cout << player2 << "\n";
	cout << player3 << "\n";

	cout << "___________test voler tout le monde____________" << "\n";
	//voler
	Effet* effetvolertout = new Effet(chaine, 2, false, false, false, true);
	cout << "___________Joueur avant effet____________" << "\n";
	cout << player1 << "\n";
	cout << player2 << "\n";
	cout << player3 << "\n";
	cout << player4 << "\n";

	effetvolertout->runEffect(&player1, joueurs);
	cout << "___________Joueur apres effet____________" << "\n";
	cout << player1 << "\n";
	cout << player2 << "\n";
	cout << player3 << "\n";
	cout << player4 << "\n";

	int pos = fonctions::recupPosition(&player4, joueurs);
	cout << "position de joueur :" << pos << "\n";

	/*
	//Test de choisir carte
	int cpt = 1;
	for (auto n : cartes) {
		cout << "Carte n" << cpt << ":" << *n << "\n";
		cpt++;
	}
	Carte* c2 = fonctions::choisirCarte(cartes);
	cout << *c2;*/

	/*
	//echanger test fonctionne
	cout << "___________test echnager carte____________" << "\n";
	Effet* effetEchanger = new Effet(chaine, 5, false, false, true);
	cout << "___________Joueur avant effet____________" << "\n";
	cout << player1 << "\n";
	cout << player1.getPaquet() << "\n\n";
	cout << player2 << "\n";
	cout << player2.getPaquet() << "\n\n";
	cout << player3 << "\n";
	cout << player3.getPaquet() << "\n\n";
	cout << player4 << "\n";
	cout << player4.getPaquet() << "\n\n";

	effetEchanger->runEffect(&player1, joueurs);
	cout << "___________Joueur apres effet____________" << "\n";
	cout << player1 << "\n";
	cout << player1.getPaquet() << "\n\n";
	cout << player2 << "\n";
	cout << player2.getPaquet() << "\n\n";
	cout << player3 << "\n";
	cout << player3.getPaquet() << "\n\n";
	cout << player4 << "\n";
	cout << player4.getPaquet() << "\n\n";

	*/

	/*
	cout << "___________voler avec choix____________" << "\n";
	//voler avec choix
	Effet* effetvolerChoix = new Effet(chaine, 5, false, true, false, false, false, true);
	cout << "___________Joueur avant effet____________" << "\n";
	cout << player1 << "\n";
	cout << player2 << "\n";
	cout << player3 << "\n";
	cout << player4 << "\n";

	effetvolerChoix->runEffect(&player1, joueurs);

	cout << "___________Joueur apres effet____________" << "\n";
	cout << player1 << "\n";
	cout << player2 << "\n";
	cout << player3 << "\n";
	cout << player4 << "\n";

*/

	cout << "___________recevoir en fonction d'un type____________" << "\n";
	//recevoir en fct d un type
	Effet* recevoirType = new Effet(chaine, 2, false, false, false, false, true, false, Type::champ);
	cout << "___________Joueur avant effet____________" << "\n";
	cout << player1 << "\n";
	cout << player2 << "\n";
	cout << player3 << "\n";
	cout << player4 << "\n";

	recevoirType->runEffect(&player1);
	cout << recevoirType;
	cout << "___________Joueur apres effet____________" << "\n";
	cout << player1 << "\n";
	cout << player2 << "\n";
	cout << player3 << "\n";
	cout << player4 << "\n";

	cout << "___________Active gare____________" << "\n";
	//mettre deux des a quelqun
	Effet* gare = new EffetClassique(chaine, 0, true);
	cout << "___________Joueur avant effet____________" << "\n";
	cout << player1 << "\n";

	gare->runEffect(&player1);
	cout << "___________Joueur apres effet____________" << "\n";
	cout << player1 << "\n";

	Jeu::getJeu().afficherJeu();
	cout << Jeu::getJeu().lancerDe();
	Jeu::libererJeu();

	for (auto n : cartes) {
		delete n;
	}
	return 0;
}

