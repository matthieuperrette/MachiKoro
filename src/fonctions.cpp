#include "Carte.h"
#include "Effet.h"
#include "Paquet.h"
#include "De.h"
#include "Pioche.h"
#include "Plateau.h"
#include "Joueur.h"
#include "fonctions.h"
#include <vector>
#include "EffetGreenValley.h"
#include "unistd.h"
#include "Controleur.h"

vector<Carte*> fonctions::cartesEditionClassique() {
    vector<int> v = {  };
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
    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::bleu, 1, v1, "Champs de ble", Type::champ));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::bleu, 1, v2, "Ferme", Type::ferme));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::bleu, 3, v5, "Foret", Type::ressource));

    vect.push_back(new Carte(new Effet("Recevez 5 pieces de la banque", 5, true),
        Couleur::bleu, 6, v9, "Mine", Type::ressource));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque", 3, true),
        Couleur::bleu, 3, v10, "Verger", Type::champ));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces de la banque", 1, true),
        Couleur::vert, 1, v2_3, "Boulangerie", Type::magasin));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque", 3, true),
        Couleur::vert, 2, v4, "Superette", Type::magasin));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque pour chaque etablissement de type ferme que vous possedez", 3, false, false, false, false, true, false, Type::ferme),
        Couleur::vert, 5, v7, "Fromagerie", Type::industrie));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque pour chaque etablissement de type ressource que vous possedez", 3, false, false, false, false, true, false, Type::ressource),
        Couleur::vert, 3, v8, "Fabrique de meubles", Type::industrie));

    vect.push_back(new Carte(new Effet("Recevez 2 pieces de la banque pour chaque etablissement de type champ que vous possedez", 2, false, false, false, false, true, false, Type::champ),
        Couleur::vert, 2, v11_12, "Marche de fruits et legumes", Type::marche));

    vect.push_back(new Carte(new Effet("Recevez 1 pieces du joueur qui a lance les des", 1, false, true),
        Couleur::rouge, 2, v3, "Cafe", Type::cafe));

    vect.push_back(new Carte(new Effet("Recevez 2 pieces du joueur qui a lance les des", 2, false, true),
        Couleur::rouge, 3, v9_10, "Restaurant", Type::cafe));

    vect.push_back(new Carte(new Effet("Recevez 2 pieces de la part de chaque autre joueur", 2, false, false, false, true),
        Couleur::violet, 6, v6, "Stade", Type::tour));

    vect.push_back(new Carte(new Effet("Recevez 5 pieces du joueur de votre choix", 5, false, true, false, false, false, true),
        Couleur::violet, 7, v6, "Chaine de television", Type::tour));

    vect.push_back(new Carte(new Effet("Vous pouvez echanger avec le joueur de votre choix un etablissement qui ne soit pas de type tour", 0, false, false, true),
        Couleur::violet, 8, v6, "Centre d'affaires", Type::tour));

    vect.push_back(new Carte(new EffetClassique("Vous pouvez lancer deux des", 0, true),
        Couleur::monument, 4, v, "Gare", Type::tour));

    vect.push_back(new Carte(new Effet("Vos etablissements de type cafe et magasin rapportent une piece de plus"),
        Couleur::monument, 10, v, "Centre commercial", Type::tour));

    vect.push_back(new Carte(new Effet("Une fois par tour, vous pouvez choisir de relancer vos des"),
        Couleur::monument, 22, v, "Tour radio", Type::tour));

    vect.push_back(new Carte(new Effet("Si votre jet de des est un double, rejouez un tour apres celui-ci"),
        Couleur::monument, 16, v, "Parc d'attractions", Type::tour));

    return vect;
}

vector<Carte*> fonctions::cartesEditionMarina() {
    vector<int> v = {  };
    vector<int> v1 = { 1 };
    vector<int> v4 = { 4 };
    vector<int> v6 = { 6 };
    vector<int> v7 = { 7 };
    vector<int> v8 = { 8 };
    vector<int> v8_9 = { 8, 9 };
    vector<int> v12_13 = { 12, 13 };
    vector<int> v12_13_14 = { 12, 13, 14 };

    vector<Carte*> vect;

    vect.push_back(new Carte(new Effet("Recevez 1 piece de la banque", 1, true),
        Couleur::bleu, 2, v4, "Champ de fleurs", Type::champ));

    vect.push_back(new Carte(new EffetMarina("Si vous avez le Port, recevez 3 pieces de la banque", 3, true),
        Couleur::bleu, 2, v8, "Petit bateau de peche", Type::bateau));

    vect.push_back(new Carte(new EffetMarina("Le joueur dont c'est le tour lance 2 des.Si vous avez le Port, recevez de la banque autant de pieces que le total des 2 des", 0, true),
        Couleur::bleu, 5, v12_13_14, "Chalutier", Type::bateau));

    vect.push_back(new Carte(new Effet("Recevez 2 pieces de la banque pour chaque etablissement de type cafe que vous possedez", 2, false, false, false, false, true, false, Type::cafe),
        Couleur::vert, 2, v12_13, "Halle de marche", Type::industrie));

    vect.push_back(new Carte(new EffetMarina("Recevez 1 piece de la banque pour chaque Champ de fleurs que vous possedez", 1, false, true),
        Couleur::vert, 1, v6, "Fleuriste", Type::magasin));

    vect.push_back(new Carte(new EffetMarina("Si vous avez le Port, recevez 3 pieces du joueur qui a fait le lancer de des", 0, false, false, true),
        Couleur::rouge, 4, v1, "Sushi bar", Type::cafe));

    vect.push_back(new Carte(new Effet("Recevez 1 piece du joueur qui a fait le lancer de des", 0, false, true),
        Couleur::rouge, 1, v7, "Pizzeria", Type::cafe));

    vect.push_back(new Carte(new Effet("Recevez 1 piece du joueur qui a fait le lancer de des", 0, false, true),
        Couleur::rouge, 1, v8, "Moonster burger", Type::cafe));

    vect.push_back(new Carte(new EffetMarina("Recevez 1 piece de chaque joueur pour chaque etablissement de type cafe et magasin qu'il possede.", 0, false, false, false, true),
        Couleur::violet, 5, v7, "Maison d'edition", Type::tour));

    vect.push_back(new Carte(new EffetMarina("Recevez la moitie (arrondie a l'inferieur) des pieces de chaque joueur qui en possede 10 ou plus", 0, false, false, false, false, true),
        Couleur::violet, 4, v8_9, "Centre des impots", Type::tour));

    vect.push_back(new Carte(new Effet("Avant de construire un etablissement ou un monument, si vous n'avez pas de pieces, recevez 1 piece de la banque", 1, true),
        Couleur::monument, 0, v, "Hotel de Ville", Type::tour));

    vect.push_back(new Carte(new Effet("Si le resultat de votre jet de des est de 10 ou plus, vous pouvez ajouter 2 au resultat"), Couleur::monument,
        2, v, "Port", Type::tour));

    vect.push_back(new Carte(new Effet("Si vous n'avez rien construit pendant votre tour, recevez 10 pieces de la banque", 10, true),
        Couleur::monument, 30, v, "Aeroport", Type::tour));

    return vect;
}

vector<Carte*> fonctions::cartesEditionGreenValley() {
    vector<int> v2 = { 2 };
    vector<int> v3_4 = { 3,4 };
    vector<int> v4 = { 4 };
    vector<int> v5 = { 5 };
    vector<int> v5_6 = { 5,6 };
    vector<int> v7 = { 7 };
    vector<int> v8 = { 8 };
    vector<int> v9 = { 9 };
    vector<int> v9_10 = { 9,10 };
    vector<int> v10 = { 10 };
    vector<int> v11 = { 11 };
    vector<int> v11_12_13 = { 11,12,13 };
    vector<int> v12_13_14 = { 12,13,14 };

    vector<Carte*> vect;
    vect.push_back(new Carte(new EffetGreenValley("Si vous avez moins de 2 monuments, recevez 1 piece de la banque", 1, true, false, false, 2),
        Couleur::bleu, 2, v3_4, "Champ de mais", Type::champ));

    vect.push_back(new Carte(new Effet("Recevez 3 pieces de la banque", 3, true),
        Couleur::bleu, 3, v7, "Vignoble", Type::champ));

    vect.push_back(new Carte(new EffetGreenValley("Si vous avez moins de 2 monuments, recevez 2 piece de la banque", 2, true, false, false, 2),
        Couleur::vert, 0, v2, "Epicerie", Type::magasin));

    vect.push_back(new Carte(new EffetGreenValley("Vous devez donner une carte de type non-tour a un autre joueur et recevez 4 pieces de la banque", 4, false, false, false, 0, true),
        Couleur::vert, 2, v2, "Entreprise de demenagement", Type::entreprise));

    vect.push_back(new Carte(new EffetGreenValley("Recevez 5 pieces a la construction. Quand cette carte est active, payez 2 pieces a la banque", 2, false, false, false, 0, false, true),
        Couleur::vert, 0, v5_6, "Banque de minivilles", Type::entreprise));

    vect.push_back(new Carte(new EffetGreenValley("Recevez 6 pieces pour chaque champ de raisin en votre possession, puis fermer cette etablissement", 6, false, false, false, 0, false, false, true),
        Couleur::vert, 3, v9, "Cave a vin", Type::industrie));

    vect.push_back(new Carte(new EffetGreenValley("Si possible, vous devez demolir l'un de vos monuments (hors hotel de ville). Recevez alors 8 pieces de la banque", 8, false, false, false, 0, false, false, false, true),
        Couleur::vert, 2, v4, "Entreprise de travaux publics", Type::entreprise));

    vect.push_back(new Carte(new EffetGreenValley("Recevez 1 pieces pour tous les etablissements de type cafe de tous les joueurs", 1, false, false, false, 0, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false, Type::cafe),
        Couleur::vert, 5, v11, "Moonster soda", Type::industrie));
    //la traduction est bizarre

    vect.push_back(new Carte(new EffetGreenValley("Si le joueur ayant lancer les des a au moins 2 monuments (hors hotel de ville), recevez 5 pieces de sa part", 5, false, true, false, 2),
        Couleur::rouge, 3, v5, "Restaurant 5 etoiles", Type::cafe));

    vect.push_back(new Carte(new EffetGreenValley("Si le joueur qui a obtenu ce nombre a au moins 3 monuments construits (hors hotel de ville), recuperez toutes ses pieces.", 0, false, false, true, 3),
        Couleur::rouge, 4, v12_13_14, "Club prive", Type::cafe));

    vect.push_back(new Carte(new EffetGreenValley("Redistribuez les pieces equitablement entre tous les joueurs. S'il y a une quantite inegale de pieces, prenez des pieces a la banque pour combler la difference.", 0, false, false, false, 0, false, false, false, false, false, true),
        Couleur::violet, 3, v11_12_13, "Parc", Type::tour));

    vect.push_back(new Carte(new EffetGreenValley("Choisissez un etablissement de type non-tour. Tous les batiments de ce type sont ferme pour renovation. Recevez une piece de chaque joueur pour chaque etablissement ferme", 1, false, false, false, 0, false, false, false, false, false, false, true),
        Couleur::violet, 4, v8, "Entreprise de renovation", Type::tour));

    vect.push_back(new Carte(new EffetGreenValley("A votre tour, vous pouvez placer une piece sur cette carte. Quand l'etablissement est active, recevez le total investit par tous les joueurs", 0, false, false, false, 0, false, false, false, false, false, false, false, true),
        Couleur::violet, 1, v10, "Tech Startup", Type::tour));

    vect.push_back(new Carte(new EffetGreenValley("Vous pouvez choisir d'activer un autre etablissement (bleu ou vert) qu vous possedez. Si vous le faites, renvoyez cette carte au marche", 0, false, false, false, 0, false, false, false, false, false, false, false, false, true),
        Couleur::violet, 7, v10, "Salle d'exposition internationale", Type::tour));
    return vect;
}

int fonctions::recupPositionJoueur(Joueur* j1, vector<Joueur*> vectJoueur) {

    auto it = find(vectJoueur.begin(), vectJoueur.end(), j1);
    if (it != vectJoueur.end())
        return(it - vectJoueur.begin());
    else
        return -1;
}

int fonctions::recupPositionCarte(string& nom, vector <Carte*> cartes) {
    auto it = cartes.begin();
    while (it != cartes.end()) {
        if ((*it)->getNom() == nom) return it - cartes.begin();
        ++it;
    }
    return -1;
}

Joueur* fonctions::choisirJoueur(Joueur* j, vector<Joueur*> vectJoueur) {
    cout << "\n" << "Choisissez un joueur de" << " 1 a " << vectJoueur.size() - 1 << "\n";
    int choix;
    while (!(cin >> choix) || choix < 1 || choix >(vectJoueur.size() - 1)) {
        cout << "Erreur veuillez choisir de nouveau" << "\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    choix -= 1;
    int position = fonctions::recupPositionJoueur(j, vectJoueur);
    if (choix >= position)
        choix += 1;
    return vectJoueur.at(choix);
}

Carte* fonctions::choisirCarte(vector <Carte*> cartes) {
    bool terminer = false;
    int choix;
    cout << "Choisissez une carte de" << " 1 a " << cartes.size() << "\n";
    while (!(cin >> choix) || choix < 1 || choix > cartes.size()) {
        cout << "Erreur veuillez choisir de nouveau" << "\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    return cartes.at(choix - 1);
}

Type fonctions::choisirType() {
    int i = 1;
    int choix;
    cout << "Choisissez un type de 1 a " << Types.size() << "\n";
    while (!(cin >> choix) || choix < 1 || choix >Types.size()) {
        cout << "Erreur veuillez choisir de nouveau" << "\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    choix--;
    //auto it = find(Types.begin(), Types.end(), choix);
    return *(Types.begin() + choix);
}

Carte* fonctions::choisirMonumentSauf(Joueur* j, string& nom) {
    vector<Carte*> monuments = j->getPaquet().getCarteCouleur(Couleur::monument);
    cout << "\n" << "Choisissez un monument de" << " 1 a " << monuments.size() - 1 << "\n";
    int choix;
    while (!(cin >> choix) || choix < 1 || choix >(monuments.size() - 1)) {
        cout << "Erreur veuillez choisir de nouveau" << "\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    choix -= 1;

    int position = fonctions::recupPositionCarte(nom, monuments);
    if (position != -1 && choix >= position)
        choix += 1;
    return monuments.at(choix);
}

Carte* fonctions::choisirCarteVioletteSauf(Joueur* j, string& nom) {
    vector<Carte*> violettes = j->getPaquet().getCarteCouleur(Couleur::violet);
    cout << "\n" << "Choisissez une carte violette de" << " 1 a " << violettes.size() - 1 << "\n";
    int choix;
    while (!(cin >> choix) || choix < 1 || choix >(violettes.size() - 1)) {
        cout << "Erreur veuillez choisir de nouveau" << "\n";
        cin.clear();
        cin.ignore(255, '\n');
    }
    choix -= 1;

    int position = fonctions::recupPositionCarte(nom, violettes);
    if (position != -1 && choix >= position)
        choix += 1;
    return violettes.at(choix);
}

/*void print_machi_koro()
{
    cout << "\n\n\n\n";
    const char* machi_koro_pattern[] =
    {
            "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -",
            "|                                                                                                                   |",
            "|          #   #     #####     #####     #   #     #####               #   #     #####     #####     #####          |",
            "|          ## ##     #   #     #         #   #       #                 #  #      #   #     #   #     #   #          |",
            "|          # # #     #####     #         #####       #                 ####      #   #     ####      #   #          |",
            "|          #   #     #   #     #         #   #       #                 #  #      #   #     #  #      #   #          |",
            "|          #   #     #   #     #####     #   #     #####               #   #     #####     #   #     #####          |",
            "|                                                                                                                   |",
            "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
    };
    for (int i = 0; i < 9; i++)
        cout << machi_koro_pattern[i] << endl;
    cout << "\n          Made with 💙BY Antoine SESINI, Matthieu PERETTE, Harry BROUDEHOUX and Mathieu BOUSQUET";
    cout << "\n\n\n\n";
}*/


void print_machi_koro(){
    cout << "\n\n\n\n" << R"(
 MMMMMMMM               MMMMMMMM               AAA                   CCCCCCCCCCCCCHHHHHHHHH     HHHHHHHHHIIIIIIIIII
M:::::::M             M:::::::M              A:::A                 CCC::::::::::::CH:::::::H     H:::::::HI::::::::I
M::::::::M           M::::::::M             A:::::A              CC:::::::::::::::CH:::::::H     H:::::::HI::::::::I
M:::::::::M         M:::::::::M            A:::::::A            C:::::CCCCCCCC::::CHH::::::H     H::::::HHII::::::II
M::::::::::M       M::::::::::M           A:::::::::A          C:::::C       CCCCCC  H:::::H     H:::::H    I::::I
M:::::::::::M     M:::::::::::M          A:::::A:::::A        C:::::C                H:::::H     H:::::H    I::::I
M:::::::M::::M   M::::M:::::::M         A:::::A A:::::A       C:::::C                H::::::HHHHH::::::H    I::::I
M::::::M M::::M M::::M M::::::M        A:::::A   A:::::A      C:::::C                H:::::::::::::::::H    I::::I
M::::::M  M::::M::::M  M::::::M       A:::::A     A:::::A     C:::::C                H:::::::::::::::::H    I::::I
M::::::M   M:::::::M   M::::::M      A:::::AAAAAAAAA:::::A    C:::::C                H::::::HHHHH::::::H    I::::I
M::::::M    M:::::M    M::::::M     A:::::::::::::::::::::A   C:::::C                H:::::H     H:::::H    I::::I
M::::::M     MMMMM     M::::::M    A:::::AAAAAAAAAAAAA:::::A   C:::::C       CCCCCC  H:::::H     H:::::H    I::::I
M::::::M               M::::::M   A:::::A             A:::::A   C:::::CCCCCCCC::::CHH::::::H     H::::::HHII::::::II
M::::::M               M::::::M  A:::::A               A:::::A   CC:::::::::::::::CH:::::::H     H:::::::HI::::::::I
M::::::M               M::::::M A:::::A                 A:::::A    CCC::::::::::::CH:::::::H     H:::::::HI::::::::I
MMMMMMMM               MMMMMMMMAAAAAAA                   AAAAAAA      CCCCCCCCCCCCCHHHHHHHHH     HHHHHHHHHIIIIIIIIII

                         KKKKKKKKK    KKKKKKK     OOOOOOOOO     RRRRRRRRRRRRRRRRR        OOOOOOOOO
                         K:::::::K    K:::::K   OO:::::::::OO   R::::::::::::::::R     OO:::::::::OO
                         K:::::::K    K:::::K OO:::::::::::::OO R::::::RRRRRR:::::R  OO:::::::::::::OO
                         K:::::::K   K::::::KO:::::::OOO:::::::ORR:::::R     R:::::RO:::::::OOO:::::::O
                         KK::::::K  K:::::KKKO::::::O   O::::::O  R::::R     R:::::RO::::::O   O::::::O
                           K:::::K K:::::K   O:::::O     O:::::O  R::::R     R:::::RO:::::O     O:::::O
                           K::::::K:::::K    O:::::O     O:::::O  R::::RRRRRR:::::R O:::::O     O:::::O
                           K:::::::::::K     O:::::O     O:::::O  R:::::::::::::RR  O:::::O     O:::::O
                           K:::::::::::K     O:::::O     O:::::O  R::::RRRRRR:::::R O:::::O     O:::::O
                           K::::::K:::::K    O:::::O     O:::::O  R::::R     R:::::RO:::::O     O:::::O
                           K:::::K K:::::K   O:::::O     O:::::O  R::::R     R:::::RO:::::O     O:::::O
                         KK::::::K  K:::::KKKO::::::O   O::::::O  R::::R     R:::::RO::::::O   O::::::O
                         K:::::::K   K::::::KO:::::::OOO:::::::ORR:::::R     R:::::RO:::::::OOO:::::::O
                         K:::::::K    K:::::K OO:::::::::::::OO R::::::R     R:::::R OO:::::::::::::OO
                         K:::::::K    K:::::K   OO:::::::::OO   R::::::R     R:::::R   OO:::::::::OO
                         KKKKKKKKK    KKKKKKK     OOOOOOOOO     RRRRRRRR     RRRRRRR     OOOOOOOOO
)" << '\n';
}

void fonctions::screenInit() {
    print_machi_koro();
}

void fonctions::screenStop() {
    print_machi_koro();
}



unsigned int fonctions::lancementDes(Joueur* currentJoueur, bool& doubleDes){
    //Verifier si carte gare alors proposer 1 ou 2 dès
    //Sinon proposer de lancer juste
    //Lancer le nombre de des choisi
    //Mettre un peu de suspense et d'attente
    //Additionner
    //Si le joueur a la carte tour radio alors afficher l'addition et proposer de relancer 1 fois
    //Sinon afficher l'addition simplement
    //retourner l'addition
    unsigned int addition=0;
    if (!currentJoueur) throw ControleurException("La carte a retirer n'existe pas !");
    string carte;
    string carte2="Parc d'attractions";
    bool aParcAttractions=currentJoueur->getPaquet().is_In(carte2);
    string choix;
    int choix2=0;
    vector<unsigned int> historique;
    vector<unsigned int>::iterator finder;





    if (currentJoueur->getDes()==1) //Si le joueur n'a pas la carte Gare
    {
        cout << "\n\n" << "Entrez L puis ENTREE pour lancer le des...\n";
        while (!(cin >> choix) || choix!="L") {
            cout << "Entrez L puis ENTREE pour lancer le des...\n";
            cin.clear();
            cin.ignore(255, '\n');
        }
        addition=Controleur::getControleur().getJeu()->lancerDe();
    }
    else //Si le joueur a la carte gare (ou toute autre carte qui lui a permis d'augmenter son nombre de des), on lui propose de lancer 1 ou 2 ou getDes des
    {
        cout << "\n\n" << "Combien de des desirez vous lancer ? Vous en avez "<< currentJoueur->getDes()<<" :\n";
        while (!(cin >> choix2) || choix2<1 || choix2>currentJoueur->getDes()) {
            cout << "Erreur ! Votre choix doit etre compris entre 1 et "<<currentJoueur->getDes();
            cin.clear();
            cin.ignore(255, '\n');
        }
        cout << "\n\n" << "Entrez L puis ENTREE pour lancer le(s) des...\n";
        while (!(cin >> choix) || choix!="L") {
            cout << "Entrez L puis ENTREE pour lancer le des...\n";
            cin.clear();
            cin.ignore(255, '\n');
        }
        for (int i=0; i!=choix2; i++) //On lance le nombre de des choisi
        {
            unsigned int result=Controleur::getControleur().getJeu()->lancerDe();
            finder= find(historique.begin(),historique.end(),result);
            if (finder!=historique.end() && aParcAttractions)
                doubleDes=true;
            historique.push_back(result);
            addition+=result;
        }
    }
    sleep(3);
    cout << "SCORE OBTENU : " << addition <<endl;
    cout << ((doubleDes && aParcAttractions) ? "Vous avez fait un double !\n":"");
    carte="Tour radio";
    string choix3;
    if (currentJoueur->getPaquet().is_In(carte)) //Si le joueur a la tour radio alors on lui propose de rejouer, sinon on arrête et on renvoie le score
    {
        cout << "\n\n" << "Voulez vous relancer le(s) des ? (Oui/Non)\n";
        while (!(cin >> choix3) || (choix3!="Oui" && choix3!="Non")) {
            cout << "Erreur ! Votre choix doit etre 'Oui' ou 'Non' !\n";
            cin.clear();
            cin.ignore(255, '\n');
        }
        if (choix3=="Oui")
        {
            addition=0;
            cout << "\n\n" << "Entrez L puis ENTREE pour lancer le des...\n";
            while (!(cin >> choix) || choix!="L") {
                cout << "Entrez L puis ENTREE pour lancer le des...\n";
                cin.clear();
                cin.ignore(255, '\n');
            }
            if (currentJoueur->getDes()==1)
            {
                addition=Controleur::getControleur().getJeu()->lancerDe();
            }
            else
            {
                for (int i=0; i!=choix2; i++) //On lance le nombre de des choisi
                {
                    unsigned int result=Controleur::getControleur().getJeu()->lancerDe();
                    finder= find(historique.begin(),historique.end(),result);
                    if (finder!=historique.end() && aParcAttractions)
                        doubleDes=true;
                    historique.push_back(result);
                    addition+=result;
                }
            }
            sleep(3);
            cout << "SCORE OBTENU : " << addition;
            cout << ((doubleDes && aParcAttractions) ? "Vous avez fait un double !\n":"");
        }
    }
    return addition;
}




vector<Carte*> fonctions::getCartesActivables(vector<Carte*>& vecteur, unsigned int& desResult){
    //retourne toutes les cartes activables avec desResult
    vector<Carte*> result;
    vector<Carte*>::iterator it;
    for (it=vecteur.begin();it!=vecteur.end();it++) //Pour chaque carte dans le vecteur donne, on regarde si la carte est activable avec desResult
    {
        if(it.operator*()->isActivable(desResult))
        {
            result.push_back(*it); //Si la carte est activable, on la push
        }
    }
    return result;
}





void fonctions::interpretation(Joueur* currentJoueur, unsigned int& desResult){ //interprete le resultat du de et active les cartes de la bonne maniere
    //pour les cartes rouges : faire le tour des joueurs dans le sens inverse de ordre et pour chaque joueur, on prendre ses cartes rouges activables et on les active
    //pour les cartes bleues : faire le tour des joueurs dans le sens ordre courant et pour chaque joueur, on recupere ses cartes bleues activables et on les active
    //pour les cartes vertes : le joueur courant subit une recherche de cartesActivables sur ses cartes de couleur verte et les cartes activables sont activees
    //pour les cartes violettes : le joueur courant subit une recherche de cartesActivables sur ses cartes de couleur violette et les cartes activables sont activees




    vector<Joueur*>::iterator it;
    vector<Joueur*> joueursList=Controleur::getControleur().getJeu()->getJoueursList();
    it=find(joueursList.begin(), joueursList.end(),currentJoueur);
    int place=-1;
    if (it==joueursList.end())
    {
        throw ControleurException("Joueur impossible a indexer !");
    }
    else //On récupère sa place relative
    {
        place=it-joueursList.begin();
    }
    int nbJoueurs=Controleur::getControleur().getJeu()->getNbJoueurs();
    bool sens=Controleur::getControleur().getSens();
    vector<Carte*> beforeFiltre;
    int i;





    //cartes rouges
    if (sens) //Si on est dans le sens horaire, on part dans le sens antihoraire à partir du joueur en cours
    {
        i=place-1;
        if(i<0) i+=nbJoueurs;
        //On ne run que pour les autres joueurs et non le courant
        while (i!=place)
        {
            //operations sur les cartes rouges du joueur i
            beforeFiltre=Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::rouge);
            for (auto j : getCartesActivables(beforeFiltre,desResult))
            {
                cout << j->getNom() << "\n";
                j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)),currentJoueur);
            }
            i--;
            if(i<0) i+=nbJoueurs;
        }
    }
    else //Sinon l'inverse
    {
        i=place+1;
        if(i>nbJoueurs-1) i-=nbJoueurs;
        //On ne run que pour les autres joueurs et non le courant
        while (i!=place)
        {
            //operations sur les cartes rouges du joueur i
            beforeFiltre=Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::rouge);
            for (auto j : getCartesActivables(beforeFiltre,desResult))
            {
                cout << j->getNom() << "\n";
                j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)),currentJoueur);
            }
            i++;
            if(i>nbJoueurs-1) i-=nbJoueurs;
        }
    }




    //cartes bleues
    if (sens)
    {
        i=place+1;
        if(i>nbJoueurs-1) i-=nbJoueurs;
        //On run pour tous les autres joueurs
        while (i!=place)
        {
            //operations sur les cartes bleues du joueur i
            beforeFiltre=Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::bleu);
            for (auto j : getCartesActivables(beforeFiltre,desResult))
            {
                cout << j->getNom() << "\n";
                j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)));
            }
            i++;
            if(i>nbJoueurs-1) i-=nbJoueurs;
        }
        //On run aussi pour notre joueur courant
        beforeFiltre=Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::bleu);
        for (auto j : getCartesActivables(beforeFiltre,desResult))
        {
            cout << j->getNom() << "\n";
            j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)));
        }
    }
    else
    {
        i=place-1;
        if(i<0) i+=nbJoueurs;
        //On run pour tous les autres joueurs
        while (i!=place)
        {
            //operations sur les cartes bleues du joueur i
            beforeFiltre=Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::bleu);
            for (auto j : getCartesActivables(beforeFiltre,desResult))
            {
                cout << j->getNom() << "\n";
                j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)));
            }
            i--;
            if(i<0) i+=nbJoueurs;
        }
        //On run aussi pour notre joueur courant
        beforeFiltre=Controleur::getControleur().getJeu()->getJoueur(i).getPaquet().getCarteCouleur(Couleur::bleu);
        for (auto j : getCartesActivables(beforeFiltre,desResult))
        {
            cout << j->getNom() << "\n";
            j->runEffect(&(Controleur::getControleur().getJeu()->getJoueur(i)));
        }
    }





    //cartes vertes
    beforeFiltre=Controleur::getControleur().getJeu()->getJoueur(place).getPaquet().getCarteCouleur(Couleur::vert);
    for (auto j : getCartesActivables(beforeFiltre,desResult))
    {
        cout << j->getNom() << "\n";
        j->runEffect(currentJoueur);
    }


    //cartes violettes
    beforeFiltre=Controleur::getControleur().getJeu()->getJoueur(place).getPaquet().getCarteCouleur(Couleur::violet);
    for (auto j : getCartesActivables(beforeFiltre,desResult))
    {
        cout << j->getNom() << "\n";
        j->runEffect(currentJoueur, Controleur::getControleur().getJeu()->getJoueursList());
    }
}



/*
void fonctions::buyingManager(Joueur* currentJoueur){
    //Avec le budget du joueur, buyingManager gere les entrees sorties permettant l'achat des etablissements
    //Il se charge ensuite d'effectuer le transfert des cartes depuis le plateau vers le paquet du joueur (faire attention aux editions hasardeuses : des transferts dans l'autre sens sont possibles)
    //ATTENTION QUAND ON ACHETE GARE ON AUGMENTE SIMPLEMENT LE GETDES DU JOUEUR
}

 */