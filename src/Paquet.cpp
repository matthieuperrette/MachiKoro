#include "Paquet.h"

//****************class Paquet*******************//
void Paquet::retirerCarte(Carte* c){
    if (cartes.empty())
    {
        throw PaquetException("Ce paquet ne contient aucune carte");
    }
    else {
        vector<Carte*>::iterator it; //on créer un itérateur fait pour travailler dans un vecteur de pointeurs de Carte
        it= find(cartes.begin(), cartes.end(), c); //on lui affecte l'index de la carte
        if (it!=cartes.end()) //si la carte a été trouvée, on l'efface
            cartes.erase(it);
    }
}

vector<Carte*> Paquet::getCarteCouleur(Couleur couleur)const{
    if (!cartes.empty())
    {
        vector<Carte*> result;
        for (auto c : cartes)
        {
            if (c->getCouleur()==couleur)
                result.push_back(c);
        }
        return result;
    }
    else
        throw PaquetException("Ce paquet ne contient aucune carte");
}
vector<Carte*> Paquet::getCarteType(Type type) const {
    if (!cartes.empty())
    {
        vector<Carte*> result;
        for (auto c : cartes)
        {
            if (c->getType()==type)
                result.push_back(c);
        }
        return result;
    }
    else
        throw PaquetException("Ce paquet ne contient aucune carte");
}

vector<Carte*> Paquet::getCarteActive(int activateur) {
    if (activateur==0)
    {
        throw PaquetException("Activateur 0 non existant");
    }
    else
    {
        if (!cartes.empty())
        {
            vector<Carte*> result;
            for (auto c : cartes)
                for (auto a : c->getActivation())
                    if (a==activateur)
                    {
                        result.push_back(c);
                        break;
                    }
            return result;
        }
        else
            throw PaquetException("Ce paquet ne contient aucune carte");
    }
}
//****************class Paquet*******************//





//****************Fonctions supplémentaires******************//
ostream& operator<<(ostream& f,const Paquet& p){
    f << "/**********Affichage Paquet**********/\n";
    int i=1;
    vector<Carte*>cartes=p.getContener();
    for (auto c : cartes)
    {
        f << "Carte n." << i ;
        f << *c << "\n";
        i++;
    }
    f << "/**********Paquet Affiche**********/\n";
    return f;
}
//****************Fonctions supplémentaires******************//