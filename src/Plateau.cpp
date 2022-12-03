//
// Created by Antoine Sesini on 26/11/2022.
//

#include "Plateau.h"



//****************class Plateau*******************//







//**************Structure***************//
Plateau::Plateau(vector<Carte*> cartesJeu) {
    if (cartesJeu.empty())
    {
        throw PlateauException("Création de Plateau impossible, aucune carte n'est fournie");
    }
    /*Regle :
     * On fait des paquets de 6 partout
     * Paquets de nb joueurs violettes
     * Paquets de nb joueurs monuments
     * */
    //Dans l'absence de nbJoueurs on utilise pour le moment :
    int nbJoueurs=4; //ATTENTION ! A MODIFIER
    nb_monuments=0;
    int i=0;
    for(auto c : cartesJeu)
    {
        Paquet* newPaquet=new Paquet;
        if (c->getCouleur()==Couleur::monument || c->getCouleur()==Couleur::violet)
        {
            if(c->getCouleur()==Couleur::monument)
            {
                nb_monuments++;
            }
           for (i=0; i<nbJoueurs; i++)
           {
               newPaquet->ajouterCarte(c);
           }
        }
        else
        {
            for (i=0; i<6; i++)
            {
                newPaquet->ajouterCarte(c);
            }
        }
        cartes.push_back(newPaquet);
    }
}



Plateau::Plateau(vector<Carte*>& cartesJeu, Pioche& p) : pioche(p){
    if (cartesJeu.empty())
    {
        throw PlateauException("Création de Plateau impossible, aucune carte n'est fournie");
    }
    if (p.getContener().empty())
    {
        throw PlateauException("Création de Plateau impossible, aucune carte n'est fournie dans la pioche");
    }
    remplirPlateau(true); //remplir plateau ne gère que le maintient des paquets de cartes achetables mais pas les monuments

    //on doit donc ajouter les monuments avec cartesJeu
    int nbJoueurs=4; //ATTENTION ! A MODIFIER
    nb_monuments=0;
    int i=0;
    for(auto c : cartesJeu)
    {
        if (c->getCouleur()==Couleur::monument)
        {
            nb_monuments++;
            Paquet* newPaquet=new Paquet;
            for (i=0; i<nbJoueurs; i++)
            {
                newPaquet->ajouterCarte(c);
            }
            cartes.push_back(newPaquet);
        }
    }
}

Plateau::~Plateau(){
    for (auto p : cartes)
        delete p;
}
//**************Structure***************//






//Espace de définition des get et autres méthodes d'utilisation//
Paquet& Plateau::getPaquetByNom(string& nom) const{
    for (auto p: cartes)
        if (p->getCarte(0).getNom()==nom) //Si la première carte du paquet a le nom "nom"
        {
            return *p;
        }
}

vector<Paquet*> Plateau::getAllPaquets() const{
    return cartes;
}

vector<Paquet*> Plateau::getPaquetsNonVides() const {
    vector<Paquet*> result;
    for (auto p: cartes)
        if (p->getNbCartes()!=0)
        {
            result.push_back(p);
        }
    return result;
}

unsigned int Plateau::getNbPaquets() const {
    return cartes.size();
}

Carte* Plateau::retirerCarte(string& nom){ //le but est de parvenir à retirer des cartes par nom
    //Si l'utilisateur choisit de récupérer une carte depuis le paquet nommé
    //Alors on enleve la carte (method retirerCarte())
    //Si le paquet dans lequel on pioche devient vide -> on le supprime puis :
    //Si on a remplir = true alors on rerempli
    //Sinon on ne fait rien
    //On la retourne

    //Ici on saisie une carte à prendre
    Paquet* paquet= &getPaquetByNom(nom); //ici on imagine que cette fonction est appelée après que l'on ait affiché les paquets non vides du plateau et saisi une carte sur le plateau
    if (paquet== nullptr){
        throw PlateauException("La carte est demandée dans un paquet inexistant");
    }
    Carte* carte= paquet->retirerCarte();
    if (carte== nullptr){
        throw PlateauException("La carte n'a pas été retirée");
    }
    if (paquet->getNbCartes()==0){
        vector<Paquet*>::iterator it;
        it=find(cartes.begin(),cartes.end(),paquet);
        if (it!=cartes.end())
            cartes.erase(it); //On enlève le paquet vide de notre plateau
        delete paquet;
    }
    remplirPlateau(false);
    return carte;
}


void Plateau::remplirPlateau(bool firstCall) { //Cette fonction est appelée lorsque retirerCarte se retrouve avec un paquetvide et la necéssité de remplir
   //On va piocher et créer des paquets jusqu'à ce que cartes.size==10;
   //A noter : une pioche est un paquet dans lequel on met 6 cartes de chaque + nbJoueurs cartes violettes : on ne met pas les monuments
   if (pioche.getNbCartes()>0) // si il reste des cartes dans la pioche
   {


       while (cartes.size()!=10 && firstCall || cartes.size()!=(10+nb_monuments) && !firstCall){
           Carte* carte=pioche.piocher();
           bool added= false;
           //Si il existe un paquet déjà crée pour l'accueillir -> on l'insère
           //Sinon on créer un paquet puis on l'insère
           for (auto p : cartes){
               if(p->is_In(carte)){
                   p->ajouterCarte(carte);
                   added= true;
                   break;
               }
           }
           if(!added){//Si on a pas trouvé un paquet dans lequel insérer la carte, on le créer et on l'insère
               Paquet* newPaquet=new Paquet; //création
               newPaquet->ajouterCarte(carte); //ajout de la carte
               cartes.push_back(newPaquet); //push dans le contener de paquets du plateau
           }
       }
       //En sortie, on a un plateau avec une size==10 ou size==14 selon l'appel
   }
}


void Plateau::afficherPlateau() const{
    size_t compt=1;
    for (auto p:cartes)
    {
        cout << "Carte n°"<< compt<< ((compt/10!=0) ? "                   " : "                    ") <<p->getNbCartes()<<"-"<<p->getCarte(0).getNom()<<"\n";
        compt++;
    }
}

//Espace de définition des get et autres méthodes d'utilisation//






//****************class Plateau*******************//


ostream& operator<<(ostream& f, const Plateau& p){
    p.afficherPlateau();
    return f;
}