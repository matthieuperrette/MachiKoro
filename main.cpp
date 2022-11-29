#include "./src/Carte.h"
#include "./src/Paquet.h"
#include "./src/Plateau.h"


using namespace std;

int main() {

	vector<Carte*> cartes = cartesEditionClassique();

    Pioche pioche(cartes, 4);

    try {
        Plateau plateau(cartes,pioche);
        plateau.afficherPlateau();
    }
    catch (PaquetException& e) {
        cout << e.getInfo() << "\n";
    }

    for (auto n : cartes) {
        delete n;
    }
    return 0;
}





