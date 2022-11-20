#include <iostream>

int main() {
    std::cout << "Bienvenue sur Minivilles les amis !" << std::endl;
    return 0;
}

/*
//main de test de la classe Carte
#include "Carte.h" //je sais pas trop comment faire pour réussir a l'inclure

using namespace std;

int main() {

	//vector<int> vect = { 1, 3 };
	//cout << vect[1] << "\n";
	try {
		printCouleurs();
		printTypes();
	}
	catch (CarteException& e) {
		cout << e.getInfo() << "\n";
	}
	//Effet effet;
	//cout << effet.getDescription() << "\n";
	//Carte c1(effet, Couleur::bleu, 2, vect, "Champ de ble", Type::champ);
	//cout << c1;

	vector<Carte*> cartes = cartesEditionClassique();
	for (auto n : cartes) {
		cout << *n << "\n";
	}
	for (auto n : cartes) {
		delete n;
	}
	return 0;
}





*/