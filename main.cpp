#include "./src/Carte.h"
#include "./src/Paquet.h"
#include "./src/Plateau.h"


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

    Pioche pioche(cartes, 4);

    try {
        Plateau plateau(cartes,pioche);
        cout << plateau.getNbPaquets() << "\n";
        vector<Paquet*> test=plateau.getAllPaquets();
        for (auto p:test)
            cout << *p;
    }
    catch (PaquetException& e) {
        cout << e.getInfo() << "\n";
    }









    for (auto n : cartes) {
        delete n;
    }
    return 0;
}





