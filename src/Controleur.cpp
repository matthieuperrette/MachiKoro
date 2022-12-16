//
// Created by Antoine Sesini on 08/12/2022.
//
#include "Controleur.h"


//Structures et classes necessaires a la classe principale//
//Structures et classes necessaires a la classe principale//



//*************CLASSE CONTROLEUR*************//

//constructeurs et destructeurs//
Controleur::Controleur(){
    cout << "\n\n";
    unsigned int choix;
    cout << "Veuillez entrer le numero de l'edition que vous souhaitez lancer :"<<endl;
    cout << "(1) Classique (2) Marina (3) GreenValley (4) Deluxe"<<endl;
    while (!(cin >> choix) || (choix!=1 && choix!=2 && choix!=3 && choix!=4)) {
        cout << "Erreur ! Nombre invalide.\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    switch (choix) {
        case 1 :
            edition=Edition::Classique;
            break;
        case 2 :
            edition=Edition::Marina;
            break;
        case 3 :
            edition=Edition::GreenValley;
            break;
        case 4 :
            edition=Edition::Deluxe;
            break;
        default:
            throw ControleurException("Attention, l'edition entree de force n'existe pas");
    }

    string choix_sens;
    cout << "\n\n" << "Souhaitez-vous jouer dans le sens horaire ? (Oui/Non)\n";
    while (!(cin >> choix_sens) || (choix_sens!="Oui" && choix_sens!="Non")) {
        cout << "Erreur ! Input invalide.\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    sens=(choix_sens=="Oui");

    switch (edition) {
        case (Edition::Classique) :
            jeu=&(JeuClassique::getJeu());
            break;
        case (Edition::Marina) :
            jeu=&(JeuMarina::getJeu());
            break;
        case (Edition::GreenValley) :
            jeu=&(JeuGreenValley::getJeu());
            break;
        case (Edition::Deluxe) :
            jeu=&(JeuDeluxe::getJeu());
            break;
        default:
            throw ControleurException("Attention, l'edition n'existe pas");
    }
}

Controleur::~Controleur() {
    //Tout est libéré implicitement
    //Il ne reste qu'à libérer l'unique instance de Jeu selon l'édition
    if (edition==Edition::Classique) JeuClassique::libererJeu();
    else if (edition==Edition::Marina) JeuMarina::libererJeu();
    else if (edition==Edition::GreenValley) JeuGreenValley::libererJeu();
    else if (edition==Edition::Deluxe) JeuDeluxe::libererJeu();
}

//constructeurs et destructeurs//



//methodes publiques//
Controleur& Controleur::getControleur(){
    if (handler.controleur ==nullptr)
        handler.controleur = new Controleur;
    return *handler.controleur;
}

void Controleur::libererControleur() {
    delete handler.controleur;
    handler.controleur = nullptr;
}

Controleur::Handler Controleur::handler = Handler();

int Controleur::runPartie(){
    bool termine=false;
    jeu->getJoueur(0).changerDes(2);
    string carte="Tour radio";
    Carte* test=jeu->retirerCartePlateau(carte);
    jeu->getJoueur(0).ajouterCarte(test);
    while (!termine)
    {
        runTour(&jeu->getJoueur(0), termine); //ATTENTION IL FAUT CHANGER LE 0 ICI
    }
    return 0;
}



void Controleur::afficherJeu() {
    jeu->afficherJeu();
    jeu->afficherPlateau();
}



int Controleur::runTour(Joueur* currentJoueur,bool& termine){

    /*
     * Un tour (dans JeuClassique) c'est :
     * Vérifier les monuments du joueur et savoir comment les activer
     * Lancer les des selon la configuration qui est possible
     * Recuperer la somme des des et faire choix si joueur a la tour radio (garder ou non la combinaison du 1ER LANCER)
        Si on fait un double aussi : attention à vérifier la présence de la carte parc d'attractions dans le paquet du joueur et dans ce cas lui octroyer un tour en +
     * Interpreter le resultat des des et faire les changements par activation des effets
        (On fait d'abord rouge bleu verte puis violette + application des rouges dans le sens inverse de la partie (en fonction de ordre) )
     * Afficher le plateau et proposer au joueur les achats possibles en les differenciant des impossibles (un seul achat possible)
     * Enregistrer les achats et faire les modifications
     * Verifier le score du joueur courant (tous les monuments sont achetés ?) : a faire dans le runPartie et a considerer en tant que condition d'arret
     */
    //afficherJeu();
    unsigned int desResult=fonctions::lancementDes(currentJoueur);
    fonctions::interpretation(currentJoueur, desResult);
    //jeu->afficherPlateau();
    //fonctions::buyingManager(currentJoueur);
    if (currentJoueur->getPaquet().getCarteCouleur(Couleur::monument).size()==jeu->getNbMonuments())
    { //Si le joueur a nb_monuments (attribut de plateau dans Jeu) monuments alors on met termine a true
        termine=true;
    }
    return 0;
}

//methodes publiques//

//*************CLASSE CONTROLEUR*************//




//Autres fonctions non membres//
//Autres fonctions non membres//
