#include "Carte.h"
#include "Effet.h"

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
		<< "Effet : " << c.getEffet().getDescription() << "\n"
		<< "S'acctive avec les des : ";
	for (int n : c.getActivation()) f << n << " ";
	f << "\n";
	return f;
}

//*---------------------Classe Carte---------------------*//

//fonction qui renvoie un vecteur avec un pointeur sur chaque carte de l'edition classique
// ATTENTION IL FAUT DELETE TOUTES LES CARTES CAR L'ALLOCATION EST DYNAMIQUE
//a terme a integrer à jeu
vector<Carte*> cartesEditionClassique() {

	Effet effet;
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
	vect.push_back(new Carte(effet, Couleur::bleu, 1, v1, "Champs de ble", Type::champ));
	vect.push_back(new Carte(effet, Couleur::bleu, 1, v2, "Ferme", Type::ferme));
	vect.push_back(new Carte(effet, Couleur::vert, 1, v2_3, "Boulangerie", Type::magasin));
	vect.push_back(new Carte(effet, Couleur::rouge, 2, v3, "Cafe", Type::cafe));
	vect.push_back(new Carte(effet, Couleur::vert, 2, v4, "Superette", Type::magasin));
	vect.push_back(new Carte(effet, Couleur::bleu, 3, v5, "Foret", Type::ressource));
	vect.push_back(new Carte(effet, Couleur::violet, 6, v6, "Stade", Type::tour));
	vect.push_back(new Carte(effet, Couleur::violet, 8, v6, "Centre d'affaires", Type::tour));
	vect.push_back(new Carte(effet, Couleur::violet, 7, v6, "Chaine de television", Type::tour));
	vect.push_back(new Carte(effet, Couleur::vert, 5, v7, "Fromagerie", Type::industrie));
	vect.push_back(new Carte(effet, Couleur::vert, 3, v8, "Fabrique de meubles", Type::industrie));
	vect.push_back(new Carte(effet, Couleur::bleu, 6, v9, "Mine", Type::ressource));
	vect.push_back(new Carte(effet, Couleur::rouge, 3, v9_10, "Restaurant", Type::cafe));
	vect.push_back(new Carte(effet, Couleur::bleu, 3, v10, "Verger", Type::champ));
	vect.push_back(new Carte(effet, Couleur::vert, 2, v11_12, "Marche de fruits et legumes", Type::marche));

	return vect;
}