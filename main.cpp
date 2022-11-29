#include "./src/Carte.h"
#include "./src/Paquet.h"
#include "./src/Plateau.h"
#include "./src/Joueur.h"


using namespace std;

int main() {

	vector<Carte*> cartes = cartesEditionClassique();

    Pioche pioche(cartes, 4);

    try {
        Plateau plateau(cartes);
        plateau.afficherPlateau();
        string str="Antoine";
        Paquet paquettest;
        Joueur player(str, 0, paquettest, 0, 1);
        player.ajouterCarte(cartes[9]);
        cout << "\n" << player << "\n";
        cout << player.getPaquet();

        string str1="Fromagerie";
        cout << *(player.retirerCarte(str1));
        cout << "\n" << player << "\n";
        cout << player.getPaquet();
    }
    catch (PaquetException& e) {
        cout << e.getInfo() << "\n";
    }


    for (auto n : cartes) {
        delete n;
    }

    return 0;
}





