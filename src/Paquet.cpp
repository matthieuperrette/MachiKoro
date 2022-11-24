#include "Paquet.h"

//****************class Paquet*******************//
void Paquet::retirerCarte(const Carte& c){
    vector<Carte*>::iterator it; //on créer un itérateur fait pour travailler dans un vecteur de pointeurs de Carte
    it= find(cartes.begin(), cartes.end(), &c); //on lui affecte l'index de la carte
    if (it!=cartes.end()) //si la carte a été trouvée, on l'efface
        cartes.erase(it);
}

vector<Carte*> Paquet::getCarteCouleur(Couleur couleur)const{
    vector<Carte*> result;
    for (auto c : cartes)
    {
        if (c->getCouleur()==couleur)
            result.push_back(c);
    }
    return result;
}
vector<Carte*> Paquet::getCarteType(Type type) const {
    vector<Carte*> result;
    for (auto c : cartes)
    {
        if (c->getType()==type)
            result.push_back(c);
    }
    return result;
}
//****************class Paquet*******************//





//****************Fonctions supplémentaires******************//
ostream& operator<<(ostream& f,const Paquet& p){
    f << "/**********Affichage Paquet**********/\n";
    int i=1;
    for (auto c : p.getContenu())
    {
        f << "Carte n." << i << "\n";
        f << *c << "\n";
        i++;
    }
    f << "/**********Paquet Affiche**********/\n";
    return f;
}

Paquet operator+(const Paquet& p1, const Paquet& p2){

}
//****************Fonctions supplémentaires******************//