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
    cout << "Veuillez entrer le nom de l'edition que vous souhaitez lancer :\n";
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
        /*case (Edition::Marina) :
            jeu=&(JeuMarina::getJeu());
            break;
        case (Edition::GreenValley) :
            jeu=&(JeuGreenValley::getJeu());
            break;
        case (Edition::Deluxe) :
            jeu=&(JeuGreenDeluxe::getJeu());
            break;
        */
        default:
            throw ControleurException("Attention, l'edition n'existe pas");
    }
}

Controleur::~Controleur() {
    //Tout est libéré implicitement
    //Il ne reste qu'à libérer l'unique instance de Jeu selon l'édition
    if (edition==Edition::Classique) JeuClassique::libererJeu();
    /*
    else if (edition==Edition::Marina) JeuMarina::libererJeu();
    else if (edition==Edition::GreenValley) JeuGreenValley::libererJeu();
    else if (edition==Edition::Deluxe) JeuDeluxe::libererJeu();
    */
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

int runPartie(){

    return 0;
}

int runTour(){

    return 0;
}

void afficherPartie(){

}
//methodes publiques//

//*************CLASSE CONTROLEUR*************//




//Autres fonctions non membres//
//Autres fonctions non membres//
