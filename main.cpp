#include "./src/Carte.h"
#include "./src/Paquet.h"
#include "./src/Carte.h"

using namespace std;

int main() {
/*
    //test de vecteurs
	//vector<int> vect = { 1, 3 };
	//cout << vect[1] << "\n";


	//test des types d'énumération
	try {
		printCouleurs();
		printTypes();
	}
	catch (CarteException& e) {
		cout << e.getInfo() << "\n";
	}


	//test des cartes
	//Effet effet;
	//cout << effet.getDescription() << "\n";
	//Carte c1(effet, Couleur::bleu, 2, vect, "Champ de ble", Type::champ);
	//cout << c1;

	vector<Carte*> cartes = cartesEditionClassique();
	for (auto n : cartes) {
		cout << *n << "\n";
	}


	//test des paquets
    Paquet paquet;
    for (auto n : cartes) {
        paquet.ajouterCarte(n);
    }

    vector<Carte*> cartas;
    try {
        cartas=paquet.getCarteActive(9);
    }
    catch (PaquetException& e) {
        cout << e.getInfo() << "\n";
    }
    for (auto n : cartas) {
        cout << *n << "\n";
    }


	//test du dé
	//seed permettant de faire des résultats vraiment aléatoire (on peut pas le mettre dans lancerDe() j'ai tester)
	srand((unsigned)time(NULL));

	De de(1,6);
	cout << de;
	int random;
	for (size_t i = 0; i < 6; i++) {
		random = de.lancerDe();
		cout << random << "\n";
	}


    for (auto n : cartes) {
        delete n;
    }
*/
    return 0;
}

