#pragma once
#include <iostream>
#include <string>
#include <initializer_list>
#include <cstdlib>
#include "Effet.h"
#include <vector>
using namespace std;


//*---------------------Classe pour les exceptions---------------------*//

class CarteException {
public:
	CarteException(const string& i) :info(i) {}
	string getInfo() const { return info; }
private:
	string info;
};

//*---------------------Classe pour les exceptions---------------------*//


//*---------------------Enumerations de Type et Couleur---------------------*//

// class d'enumeration
enum class Couleur { bleu, vert, rouge, violet, monument };
enum class Type { champ, ferme, cafe, magasin, tour, industrie, ressource, marche };

// conversion en string
string toString(Couleur c);
string toString(Type t);

// ecriture d'une caract�ristique sur un flux ostream
ostream& operator<<(ostream& f, Couleur c);
ostream& operator<<(ostream& f, Type t);

// listes contenant les valeurs possibles pour chacune des caract�ristiques
extern std::initializer_list<Couleur> Couleurs;
extern std::initializer_list<Type> Types;

// affichage des valeurs possibles pour chaque caract�ristiques
void printCouleurs(std::ostream& f = cout);
void printTypes(std::ostream& f = cout);

//*---------------------Enumerations de Type et Couleur---------------------*//



//*---------------------Classe Carte---------------------*//

class Carte {
private:
	Effet effet;
	Couleur couleur;
	unsigned int prix;
	vector<int> activation;
	string nom;
	Type type;
	Carte(const Carte&) = delete;
	Carte operator=(const Carte&) = delete;
public:
	Carte(Effet f, Couleur c, unsigned int p, vector<int> a, string n, Type t) : effet(f),
		couleur(c), prix(p), activation(a), nom(n), type(t) {}
	Couleur getCouleur() const { return couleur; }
	Effet getEffet() const { return effet; }
	unsigned int getPrix() const { return prix; }
	vector<int> getActivation() const { return activation; }
	string getNom() const { return nom; }
	Type getType() const { return type; }
};
ostream& operator<<(ostream& f, const Carte& c);

//*---------------------Classe Carte---------------------*//

//fonction qui renvoie un vecteur avec un pointeur sur chaque carte de l'edition classique
// ATTENTION IL FAUT DELETE TOUTES LES CARTES CAR L'ALLOCATION EST DYNAMIQUE
//a terme a integrer a jeu
vector<Carte*> cartesEditionClassique();
