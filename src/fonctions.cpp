#include "Carte.h"
#include "Effet.h"
#include "Paquet.h"
#include "De.h"
#include "Pioche.h"
#include "Plateau.h"
#include "Joueur.h"
#include "fonctions.h"
#include <vector>

vector<Carte*> fonctions::cartesEditionClassique() {
    vector<int> v = {  };
    vector<int> v1 = { 1 };
    vector<int> v2 = { 2 };
    vector<int> v2_3 = { 2, 3 };
    vector<int> v3 = { 3 };
    vector<int> v4 = { 4 };
    vector<int> v5 = { 5 };
    vector<int> v6 = { 6 };
    vector<int> v7 = { 7 };
    vector<int> v8 = { 8 };
    vector<int> v9 = { 9 };
    vector<int> v9_10 = { 9, 10 };
    vector<int> v10 = { 10 };
    vector<int> v11_12 = { 11, 12 };

    vector<Carte*> vect;
    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::bleu, 1, v1, "Champs de ble", Type::champ));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::bleu, 1, v2, "Ferme", Type::ferme));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::vert, 1, v2_3, "Boulangerie", Type::magasin));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces du joueur qui a lance les des", 1, false, true),
        Couleur::rouge, 2, v3, "Cafe", Type::cafe));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque", 3, true),
        Couleur::vert, 2, v4, "Superette", Type::magasin));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::bleu, 3, v5, "Foret", Type::ressource));

    vect.push_back(new Carte(new Effet("Recevez 2 pieces de la part de chaque autre joueur", 2, false, false, false, true),
        Couleur::violet, 6, v6, "Stade", Type::tour));

    vect.push_back(new Carte(new Effet("Vous pouvez echanger avec le joueur de votre choix un etablissement qui ne soit pas de type tour",
        0, false, false, true),
        Couleur::violet, 8, v6, "Centre d'affaires", Type::tour));

    vect.push_back(new Carte(new Effet("Recevez 5 pieces du joueur de votre choix", 5, false, true, false, false, false, true),
        Couleur::violet, 7, v6, "Chaine de television", Type::tour));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque pour chaque etablissement de type ferme que vous possedez",
        3, false, false, false, false, true, false, Type::ferme),
        Couleur::vert, 5, v7, "Fromagerie", Type::industrie));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque pour chaque etablissement de type ressource que vous possedez",
        3, false, false, false, false, true, false, Type::ressource),
        Couleur::vert, 3, v8, "Fabrique de meubles", Type::industrie));

    vect.push_back(new Carte(new Effet("Recevez 5 pieces de la banque", 5, true),
        Couleur::bleu, 6, v9, "Mine", Type::ressource));

    vect.push_back(new Carte(new Effet("Recevez 2 pieces du joueur qui a lance les des", 2, false, true),
        Couleur::rouge, 3, v9_10, "Restaurant", Type::cafe));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque", 3, true),
        Couleur::bleu, 3, v10, "Verger", Type::champ));

    vect.push_back(new Carte(new Effet("Recevez 2 pieces de la banque pour chaque etablissement de type champ que vous possedez",
        2, false, false, false, false, true, false, Type::champ),
        Couleur::vert, 2, v11_12, "Marche de fruits et legumes", Type::marche));

    vect.push_back(new Carte(new EffetClassique("Vous pouvez lancer deux des", 0, true),
        Couleur::monument, 4, v, "Gare", Type::tour));

    vect.push_back(new Carte(new Effet("Vos etablissements de type cafe et magasin rapportent une piece de plus"),
        Couleur::monument, 10, v, "Centre commercial", Type::tour));

    vect.push_back(new Carte(new Effet("Une fois par tour, vous pouvez choisir de relancer vos des"),
        Couleur::monument, 22, v, "Tour radio", Type::tour));

    vect.push_back(new Carte(new Effet("Si votre jet de des est un double, rejouez un tour apres celui-ci"),
        Couleur::monument, 16, v, "Parc d'attractions", Type::tour));

    return vect;
}

int fonctions::recupPositionJoueur(Joueur* j1, vector<Joueur*> vectJoueur) {

    auto it = find(vectJoueur.begin(), vectJoueur.end(), j1);
    if (it != vectJoueur.end())
        return(it - vectJoueur.begin());
    else
        return -1;
}

int fonctions::recupPositionCarte(string& nom, vector <Carte*> cartes) {
    auto it = cartes.begin();
    while (it != cartes.end()) {
        if ((*it)->getNom() == nom) return it - cartes.begin();
        ++it;
    }
    return -1;
}

Joueur* fonctions::choisirJoueur(Joueur* j, vector<Joueur*> vectJoueur) {
    cout << "\n" << "Choisissez un joueur de" << " 1 a " << vectJoueur.size() - 1 << "\n";
    int choix;
    while (!(cin >> choix) || choix < 1 || choix >(vectJoueur.size() - 1)) {
        cout << "Erreur veuillez choisir de nouveau" << "\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    choix -= 1;
    int position = fonctions::recupPositionJoueur(j, vectJoueur);
    if (choix >= position)
        choix += 1;
    return vectJoueur.at(choix);
}

Carte* fonctions::choisirCarte(vector <Carte*> cartes) {
    bool terminer = false;
    int choix;
    cout << "Choisissez une carte de" << " 1 a " << cartes.size() << "\n";
    while (!(cin >> choix) || choix < 1 || choix > cartes.size()) {
        cout << "Erreur veuillez choisir de nouveau" << "\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    return cartes.at(choix - 1);
}
/*
Type fonctions::choisirType() {
    int i = 1;
    int choix;
    cout << "Choisissez un type de 1 a" << Types.size() << "\n";
    while (!(cin >> choix) || choix < 1 || choix >Types.size()) {
        cout << "Erreur veuillez choisir de nouveau" << "\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    choix--;
    auto it = find(Types.begin(), Types.end(), choix);
    return *it;
}
*/
Carte* fonctions::choisirMonumentSauf(Joueur* j, string& nom) {
    vector<Carte*> monuments = j->getPaquet().getCarteCouleur(Couleur::monument);
    cout << "\n" << "Choisissez un monument de" << " 1 a " << monuments.size() - 1 << "\n";
    int choix;
    while (!(cin >> choix) || choix < 1 || choix >(monuments.size() - 1)) {
        cout << "Erreur veuillez choisir de nouveau" << "\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    choix -= 1;

    int position = fonctions::recupPositionCarte(nom, monuments);
    if (position != -1 && choix >= position)
        choix += 1;
    return monuments.at(choix);
}

Carte* fonctions::choisirCarteVioletteSauf(Joueur* j, string& nom) {
    vector<Carte*> violettes = j->getPaquet().getCarteCouleur(Couleur::violet);
    cout << "\n" << "Choisissez une carte violette de" << " 1 a " << violettes.size() - 1 << "\n";
    int choix;
    while (!(cin >> choix) || choix < 1 || choix >(violettes.size() - 1)) {
        cout << "Erreur veuillez choisir de nouveau" << "\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    choix -= 1;

    int position = fonctions::recupPositionCarte(nom, violettes);
    if (position != -1 && choix >= position)
        choix += 1;
    return violettes.at(choix);
}