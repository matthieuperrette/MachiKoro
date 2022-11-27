#include "Joueur.h"

//****************Fonctions supplémentaires******************//
ostream& operator<<(ostream& f, const Joueur& j) {
    f << "/**********Affichage Joueur**********/\n";
    f << "Pseudonyme: " << j.getPseudo() << "\n";
    f << "Est-ce une IA? (0 pour non, 1 pour oui): " << j.getIa() << "\n";
    f << "Paquet: " << j.getPaquet() << "\n";
    f << "Argent disponible: " << j.getMoney() << "\n";
    f <<"Nombre de dés jouables: "<< j.getNbDes()<<"\n";
    f << "/**********Joueur Affiche**********/\n";
    return f;
}
//****************Fonctions supplémentaires******************//

