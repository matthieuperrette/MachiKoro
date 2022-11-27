#include "./src/Carte.h"
#include "./src/Paquet.h"
#include "./src/Carte.h"
#include "./src/Pioche.h"

using namespace std;

int main() {

	//test de vecteurs
	//vector<int> vect = { 1, 3 };
	//cout << vect[1] << "\n";

	cout << "test des types d'enum" << "\n";
	//test des types d'énumération
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

	vector<Carte*> cartes = cartesEditionClassique();
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
	//test du dé
	//seed permettant de faire des résultats vraiment aléatoire (on peut pas le mettre dans lancerDe() j'ai tester)
	srand((unsigned)time(NULL));

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


	for (auto n : cartes) {
		delete n;
	}




	return 0;
}

