#pragma once
#include <iostream>
#include <string>
#include <initializer_list>
#include <cstdlib>
//#include "Effet.h"
#include <vector>
using namespace std;

class Effet;
class Joueur;

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
enum class Type { champ, ferme, cafe, magasin, tour, industrie, ressource, marche, bateau, entreprise };

// conversion en string
string toString(Couleur c);
string toString(Type t);

// ecriture d'une caracteristique sur un flux ostream
ostream& operator<<(ostream& f, Couleur c);
ostream& operator<<(ostream& f, Type t);

// listes contenant les valeurs possibles pour chacune des caracteristiques
extern std::initializer_list<Couleur> Couleurs;
extern std::initializer_list<Type> Types;

// affichage des valeurs possibles pour chaque caracteristiques
void printCouleurs(std::ostream& f = cout);
void printTypes(std::ostream& f = cout);
//*---------------------Enumerations de Type et Couleur---------------------*//



//*---------------------Classe Carte---------------------*//

class Carte {
private:
	Effet* effet;
	Couleur couleur;
	unsigned int prix;
	vector<int> activation;
	string nom;
	Type type;
	Carte(const Carte&) = delete;
	Carte operator=(const Carte&) = delete;
public:
	Carte(Effet* effet, Couleur couleur, unsigned int prix, vector<int> activation, string nom, Type type) : effet(effet),
		couleur(couleur), prix(prix), activation(activation), nom(nom), type(type) {}
	~Carte()=default;
	Couleur getCouleur() const { return couleur; }
	Effet* getEffet() const;
	unsigned int getPrix() const { return prix; }
	vector<int> getActivation() const { return activation; }
	string getNom() const { return nom; }
	Type getType() const { return type; }

	int runEffect(Joueur* j1);
	int runEffect(Joueur* j1, Joueur* j2);
	int runEffect(Joueur* j1, vector<Joueur*> vectJoueur);
};
ostream& operator<<(ostream& f, const Carte& c);

//*---------------------Classe Carte---------------------*//

