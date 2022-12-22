//
// Created by Antoine Sesini on 08/12/2022.
//
#include "Controleur.h"


//Structures et classes necessaires a la classe principale//
//Structures et classes necessaires a la classe principale//



//*************CLASSE CONTROLEUR*************//

//constructeurs et destructeurs//
Controleur::Controleur() {
    std::cout << "\n\n";
    unsigned int choix;
    std::cout << "Veuillez entrer le numero de l'edition que vous souhaitez lancer :" << std::endl;
    std::cout << "(1) Classique (2) Marina (3) GreenValley (4) Deluxe" << std::endl;
    while (!(std::cin >> choix) || (choix != 1 && choix != 2 && choix != 3 && choix != 4)) {
        std::cout << "Erreur ! Nombre invalide.\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
    switch (choix) {
    case 1:
        edition = Edition::Classique;
        break;
    case 2:
        edition = Edition::Marina;
        break;
    case 3:
        edition = Edition::GreenValley;
        break;
    case 4:
        edition = Edition::Deluxe;
        break;
    default:
        throw ControleurException("Attention, l'edition entree de force n'existe pas");
    }

    std::string choix_sens;
    std::cout << "\n\n" << "Souhaitez-vous jouer dans le sens horaire ? (Oui/Non)\n";
    while (!(std::cin >> choix_sens) || (choix_sens != "Oui" && choix_sens != "Non")) {
        std::cout << "Erreur ! Input invalide.\n";
        std::cin.clear();
        std::cin.ignore(255, '\n');
    }
    sens = (choix_sens == "Oui");

    switch (edition) {
    case (Edition::Classique):
        jeu = &(JeuClassique::getJeu());
        break;
    case (Edition::Marina):
        jeu = &(JeuMarina::getJeu());
        break;
    case (Edition::GreenValley):
        jeu = &(JeuGreenValley::getJeu());
        break;
    case (Edition::Deluxe):
        jeu = &(JeuDeluxe::getJeu());
        break;
    default:
        throw ControleurException("Attention, l'edition n'existe pas");
    }
}

Controleur::~Controleur() {
    //Tout est libere implicitement
    //Il ne reste qu'a liberer l'unique instance de Jeu selon l'edition
    if (edition == Edition::Classique) JeuClassique::libererJeu();
    else if (edition == Edition::Marina) JeuMarina::libererJeu();
    else if (edition == Edition::GreenValley) JeuGreenValley::libererJeu();
    else if (edition == Edition::Deluxe) JeuDeluxe::libererJeu();
}

//constructeurs et destructeurs//



//methodes publiques//
Controleur& Controleur::getControleur() {
    if (handler.controleur == nullptr)
        handler.controleur = new Controleur;
    return *handler.controleur;
}

void Controleur::libererControleur() {
    delete handler.controleur;
    handler.controleur = nullptr;
}

Controleur::Handler Controleur::handler = Handler();

<<<<<<< HEAD
int Controleur::runPartie(){
    bool termine=false;
    bool doubleDes;
    int i=0;
    bool sensUtile=Controleur::getControleur().getSens();
    int nbJoueurs=Controleur::getControleur().getJeu()->getNbJoueurs();
    while (!termine)
    {
        doubleDes= true;
        while (doubleDes)
        {
            doubleDes= false;
=======
int Controleur::runPartie() {
    bool termine = false;
    bool doubleDes;
    int i = 0;
    bool sensUtile = Controleur::getControleur().getSens();
    int nbJoueurs = Controleur::getControleur().getJeu()->getNbJoueurs();
    while (!termine)
    {
        doubleDes = true;
        while (doubleDes)
        {
            doubleDes = false;
>>>>>>> c816a9e (plus d'accent et de namespace std)
            runTour(&jeu->getJoueur(i), termine, doubleDes);
        }
        if (sensUtile) //Si horaire
        {
            i++;
<<<<<<< HEAD
            if (i==nbJoueurs) i-=nbJoueurs;
=======
            if (i == nbJoueurs) i -= nbJoueurs;
>>>>>>> c816a9e (plus d'accent et de namespace std)
        }
        else //Si anti horaire
        {
            i--;
<<<<<<< HEAD
            if (i<0) i+=nbJoueurs;
=======
            if (i < 0) i += nbJoueurs;
>>>>>>> c816a9e (plus d'accent et de namespace std)
        }
    }
    return 0;
}



void Controleur::afficherJeu() {
<<<<<<< HEAD
    cout << "\n//********AFFICHAGE PLATEAU ET JOUEURS********//\n";
=======
    std::cout << "\n//********AFFICHAGE PLATEAU ET JOUEURS********//\n";
>>>>>>> c816a9e (plus d'accent et de namespace std)
    jeu->afficherJeu();
    jeu->afficherPlateau();
}



<<<<<<< HEAD
int Controleur::runTour(Joueur* currentJoueur,bool& termine, bool& doubleDes){

    /*
     * Un tour (dans JeuClassique) c'est :
     * Vérifier les monuments du joueur et savoir comment les activer
     * Lancer les des selon la configuration qui est possible
     * Recuperer la somme des des et faire choix si joueur a la tour radio (garder ou non la combinaison du 1ER LANCER)
        Si on fait un double aussi : attention à vérifier la présence de la carte parc d'attractions dans le paquet du joueur et dans ce cas lui octroyer un tour en +
     * Interpreter le resultat des des et faire les changements par activation des effets
        (On fait d'abord rouge bleu verte puis violette + application des rouges dans le sens inverse de la partie (en fonction de ordre) )
     * Afficher le plateau et proposer au joueur les achats possibles en les differenciant des impossibles (un seul achat possible)
     * Enregistrer les achats et faire les modifications (QUAND ON ACHETE DES MONUMENTS : FAIRE LES VERIFS ET MODIFICATIONS : notamment pour l'augmentation des dès)
     * Verifier le score du joueur courant (tous les monuments sont achetés ?) : a faire dans le runPartie et a considerer en tant que condition d'arret
     */
    afficherJeu();
    cout << "//***********************************************//"<< endl;
    cout << "//************C'EST AU TOUR DE "<< currentJoueur->getPseudo()<< "************//" << endl;
    unsigned int desResult=fonctions::lancementDes(currentJoueur, doubleDes);
    cout << endl;
    fonctions::interpretation(currentJoueur, desResult);
    fonctions::buyingManager(currentJoueur);
    if (currentJoueur->getPaquet().getCarteCouleur(Couleur::monument).size()==jeu->getNbMonuments())
    { //Si le joueur a nb_monuments (attribut de plateau dans Jeu) monuments alors on met termine a true
        termine=true;
=======
int Controleur::runTour(Joueur* currentJoueur, bool& termine, bool& doubleDes) {

    /*
     * Un tour (dans JeuClassique) c'est :
     * Verifier les monuments du joueur et savoir comment les activer
     * Lancer les des selon la configuration qui est possible
     * Recuperer la somme des des et faire choix si joueur a la tour radio (garder ou non la combinaison du 1ER LANCER)
        Si on fait un double aussi : attention a verifier la presence de la carte parc d'attractions dans le paquet du joueur et dans ce cas lui octroyer un tour en +
     * Interpreter le resultat des des et faire les changements par activation des effets
        (On fait d'abord rouge bleu verte puis violette + application des rouges dans le sens inverse de la partie (en fonction de ordre) )
     * Afficher le plateau et proposer au joueur les achats possibles en les differenciant des impossibles (un seul achat possible)
     * Enregistrer les achats et faire les modifications (QUAND ON ACHETE DES MONUMENTS : FAIRE LES VERIFS ET MODIFICATIONS : notamment pour l'augmentation des des)
     * Verifier le score du joueur courant (tous les monuments sont achetes ?) : a faire dans le runPartie et a considerer en tant que condition d'arret
     */
    afficherJeu();
    std::cout << "//***********************************************//" << std::endl;
    std::cout << "//************C'EST AU TOUR DE " << currentJoueur->getPseudo() << "************//" << std::endl;
    unsigned int desResult = fonctions::lancementDes(currentJoueur, doubleDes);
    std::cout << std::endl;
    fonctions::interpretation(currentJoueur, desResult);
    fonctions::buyingManager(currentJoueur);
    if (currentJoueur->getPaquet().getCarteCouleur(Couleur::monument).size() == jeu->getNbMonuments())
    { //Si le joueur a nb_monuments (attribut de plateau dans Jeu) monuments alors on met termine a true
        termine = true;
>>>>>>> c816a9e (plus d'accent et de namespace std)
    }
    return 0;
}

//methodes publiques//

//*************CLASSE CONTROLEUR*************//




//Autres fonctions non membres//
//Autres fonctions non membres//
