#include "Carte.h"
#include "Effet.h"
#include "Joueur.h"

//*---------------------Enumerations de Type et Couleur---------------------*//

std::initializer_list<Couleur> Couleurs = { Couleur::bleu, Couleur::vert,
Couleur::rouge, Couleur::violet, Couleur::monument };
std::initializer_list<Type> Types = { Type::champ, Type::ferme, Type::cafe, Type::magasin,
Type::tour, Type::industrie, Type::ressource, Type::marche };

string toString(Couleur c) {
    switch (c) {
    case Couleur::bleu: return "bleu";
    case Couleur::vert: return "vert";
    case Couleur::rouge: return "rouge";
    case Couleur::violet: return "violet";
    case Couleur::monument: return "monument";
    default: throw CarteException("Couleur inconnue");
    }
}

string toString(Type t) {
    switch (t) {
    case Type::champ: return "champ";
    case Type::ferme: return "ferme";
    case Type::cafe: return "cafe";
    case Type::magasin: return "magasin";
    case Type::tour: return "tour";
    case Type::industrie: return "industrie";
    case Type::ressource: return "ressource";
    case Type::marche: return "marche";
    case Type::bateau: return "bateau";
    case Type::entreprise: return "entreprise";
    default: throw CarteException("Type inconnue");
    }
}


std::ostream& operator<<(std::ostream& f, Couleur c) { f << toString(c); return f; }
std::ostream& operator<<(std::ostream& f, Type t) { f << toString(t); return f; }


void printCouleurs(std::ostream& f) {
    for (auto c : Couleurs) f << c << " ";
    f << "\n";
}

void printTypes(std::ostream& f) {
    for (auto t : Types) f << t << " ";
    f << "\n";
}

//*---------------------Enumerations de Type et Couleur---------------------*//


//*---------------------Classe Carte---------------------*//

ostream& operator<<(ostream& f, const Carte& c) {
    f << "\n---------" << c.getNom() << "---------\n"
        "Couleur : " << c.getCouleur() << "\n"
        << "Type : " << c.getType() << "\n"
        << "Prix : " << c.getPrix() << "\n"
        << "Effet : " << *c.getEffet() << "\n";
    if (c.getActivation().size() != 0) {
        f << "S'acctive avec les des : ";
        for (int n : c.getActivation()) f << n << "\n";
    }
    return f;
}

int Carte::runEffect(Joueur* j1) {
    int retour;
    string centre = "Centre commercial";
    if ((type == Type::cafe || type == Type::magasin) && j1->getPaquet().getCarteNom(centre).size() != 0) {
        effet->ajouterPiecesEnJeu(1);
        retour = effet->runEffect(j1);
        effet->enleverPiecesEnJeu(1);
    }
    else
        retour = effet->runEffect(j1);
    return retour;
}

int Carte::runEffect(Joueur* j1, Joueur* j2) {
    int retour;
    string centre = "Centre commercial";
    if ((type == Type::cafe || type == Type::magasin) && j1->getPaquet().getCarteNom(centre).size() != 0) {
        effet->ajouterPiecesEnJeu(1);
        retour = effet->runEffect(j1, j2);
        effet->enleverPiecesEnJeu(1);
    }
    else
        retour = effet->runEffect(j1, j2);
    return retour;
}

int Carte::runEffect(Joueur* j1, vector<Joueur*> vectJoueur) {
    int retour;
    string centre = "Centre commercial";
    if ((type == Type::cafe || type == Type::magasin) && j1->getPaquet().getCarteNom(centre).size() != 0) {
        effet->ajouterPiecesEnJeu(1);
        retour = effet->runEffect(j1, vectJoueur);
        effet->enleverPiecesEnJeu(1);
    }
    else
        retour = effet->runEffect(j1, vectJoueur);
    return retour;
}

Effet* Carte::getEffet() const { return effet; }

//*---------------------Classe Carte---------------------*//




