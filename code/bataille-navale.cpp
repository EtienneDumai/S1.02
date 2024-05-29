/**
 * @file bataille-navale.cpp
 * @author Dumai Etienne
 * @brief Corps du module bataille-navale
 * @date 2024-01-18
 */
#include <iostream>
#include "game-tools.h"
#include "bataille-navale.h"
using namespace std;

Touche bateau1 = ZERO_FOIS;
Touche bateau2 = ZERO_FOIS;

string pseudoJ1 = "";
string pseudoJ2 = "";
string gagnantDeLaPartie = "";

char tableauDeJeu[NB_CASES][NB_CASES]; // Tableau dans lequel va se dérouler la partie
                                       // Taille du tableau a l'horizontale et à la verticale (plateau de jeu carré)

Bateau bateaux[NB_BATEAUX]; // tableau de Bateaux

bool abandonJ1;
bool abandonJ2;
string msgErreurCo = "Veuillez entre une lettre entre A et I (en majuscule) et un chifre entre 1 et 9";
// message d'erreur pour etre affiché en couleur

void afficherBateau()
{
    // Parcours des 2 bateaux du tableau Bateaux
    for (int indiceBateau = 0; indiceBateau < NB_BATEAUX; indiceBateau++)
    {
        // Afficher l'en-tête de la ligne
        cout << "Bateau " << (indiceBateau + 1) << (indiceBateau == 0 ? " (O) " : " (X) ") << " = ";
        // Afficher les coordonnées de tous les points du bateau
        for (int coordBateau = 0; coordBateau < NB_CASES_BATEAU; coordBateau++)
        {
            cout << " (" << char(bateaux[indiceBateau].pos[coordBateau].y + 64) << "," << bateaux[indiceBateau].pos[coordBateau].x << ")";
        }
        cout << endl;
    }
}
// procédure permettant de verifier que les bateau ne se croisent pas sans se toucher
bool verifCroisBateau(Bateau Bateaux[NB_BATEAUX])
{
    int Bateaux1 = 0;
    int Bateaux2 = 1;
    bool aucunCroisement = true;
    // parcours des cases des bateaux
    for (int indiceBateau1 = 0; indiceBateau1 < NB_CASES_BATEAU; indiceBateau1++)
    {
        for (int indiceBateau2 = 0; indiceBateau2 < NB_CASES_BATEAU; indiceBateau2++)
        {
            /*verification pour la 2eme case du bateau 1 si les 8 case autour de
            correspondes pas au coordonnées d'un des cases du bateau2*/
            if (indiceBateau1 == 1)
            {
                if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
            }
            /*verification pour la 3eme case du bateau 1 si les 8 case autour de
            correspondes pas au coordonnées d'un des cases du bateau2*/
            else if (indiceBateau1 == 2)
            {
                if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x + 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y - 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
                else if (Bateaux[Bateaux1].pos[indiceBateau1].x - 1 == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y + 1 == Bateaux[Bateaux2].pos[indiceBateau2].y)
                {
                    aucunCroisement = false;
                }
            }
        }
    }
    return aucunCroisement;
}
// verification du croisement des bateaux si ils ont une case en commun
bool verifierCroisementBateaux(Bateau Bateaux[NB_BATEAUX])
{

    int Bateaux1 = 0;
    int Bateaux2 = 1;
    bool aucunCroisement = true;
    // parcours des cases des bateaux
    for (int indiceBateau1 = 0; indiceBateau1 < NB_CASES_BATEAU; indiceBateau1++)
    {
        for (int indiceBateau2 = 0; indiceBateau2 < NB_CASES_BATEAU; indiceBateau2++)
        {
            // comparaison  de chaque case pour voir si il y en a une en commun
            if (Bateaux[Bateaux1].pos[indiceBateau1].x == Bateaux[Bateaux2].pos[indiceBateau2].x && Bateaux[Bateaux1].pos[indiceBateau1].y == Bateaux[Bateaux2].pos[indiceBateau2].y)
            {
                aucunCroisement = false;
            }
        }
    }
    return aucunCroisement;
}
// Définition de la procédure permttant de choisir un pseudo
void choisirPseudoDesJoueurs(string &joueur1, string &joueur2)
{
    bool pseudoOk = false;
    while (!pseudoOk) // boucle permttant de verifier si les pseudo sont différents
    {
        effacer();
        cout << "Quel est le pseudo du joueur1 ?" << endl;
        cin >> joueur1;
        effacer();
        cout << "Quel est le pseudo du joueur 2 ?" << endl;
        cin >> joueur2;
        effacer();
        if (joueur1 != joueur2)
        {
            pseudoOk = true;
        }
        else
        {
            pseudoOk = false;
            cout << "Veuillez entrer des pseudo differents pour les 2 joueurs" << endl;
            pause(3);
        }
    }
}

void tirBateau(Bateau Bateaux[NB_BATEAUX], char tableau[NB_CASES][NB_CASES], string joueur1, string joueur2, bool &abanJ1, bool &abanJ2)
{
    bool coValide = false;
    bool coDansIntervale = true;
    string reponse;
    char tirJoueurx;
    char tirJoueury;
    bool dansLeTableau = false;
    affichage();
    cout << " Au tour de : " << joueur1 << " dans" << endl;
    while (coValide != true)
    {
        coDansIntervale = true;
        effacer();
        affichage();
        cout << "Au tour de " << joueur1 << endl;
        cout << "Quelles sont les coordonnees de votre tir (ou abandonner @@) ?" << endl;
        cin >> reponse;
        effacer();
        for (int i = 0; reponse[i] != '\0'; i++) // parcours de la réponse
        {
            if (i == 0)
            {
                tirJoueury = reponse[i]; // assignation du premier caractère de la réponse à tirJoueury
            }
            else if (i == 1)
            {
                tirJoueurx = reponse[i]; // assignation du premier caractère de la réponse à tirJoueurx
            }
            else if (i > 1)
            {
                coDansIntervale = false;
            }
        }
        if (tirJoueurx == '@' && tirJoueury == '@') // verification si les coordonnées entrées ne correspondent pas à un abandon
        {
            if (joueur1 == pseudoJ1)
            {
                coDansIntervale = true;
                coValide = true;
                gagnantDeLaPartie = joueur2;
                abanJ1 = true;
            }
            else if (joueur1 == pseudoJ2)
            {
                coDansIntervale = true;
                coValide = true;
                gagnantDeLaPartie = joueur1;
                abanJ2 = true;
            }
        }
        // verification si les coordonnées entrées sont entre A et I et entre 1 et 9
        if ((int(tirJoueury) - 64 >= 0 && int(tirJoueury) - 64 <= 10) && ((int(tirJoueurx) - 48) >= 0 && (int(tirJoueurx) - 48) <= 10) && coDansIntervale == true)
        {
            coValide = true;
            break;
        }
        else if (coValide != true)
        {
            affichage();
            afficherTexteEnCouleur(msgErreurCo, rouge, true);
            pause(3);
            coValide = false;
            reponse = "";
        }
    }
    // parcours des coordonnées des bateaux pour voir si les coordonnées entrées correspondes à un des 2 bateaux
    for (int indiceBateau = 0; indiceBateau < NB_BATEAUX; indiceBateau++)
    {
        for (int indiceCase = 0; indiceCase < NB_CASES_BATEAU; indiceCase++)
        {
            if (Bateaux[indiceBateau].pos[indiceCase].x == (int(tirJoueurx) - 48) && Bateaux[indiceBateau].pos[indiceCase].y == int(tirJoueury) - 64)
            {
                dansLeTableau = true;
                if (dansLeTableau == true && indiceBateau == 0)
                {
                    tableau[int(tirJoueurx) - 49][int(tirJoueury) - 65] = 'O';
                }
                else if (dansLeTableau == true && indiceBateau == 1)
                {
                    tableau[int(tirJoueurx) - 49][int(tirJoueury) - 65] = 'X';
                }
                // mise à jour de l'etat du bateau 1
                if (indiceBateau == 0)
                {
                    switch (bateau1)
                    {
                    case ZERO_FOIS:
                        bateau1 = UNE_FOIS;
                        break;
                    case UNE_FOIS:
                        bateau1 = DEUX_FOIS;
                        break;
                    case DEUX_FOIS:
                        bateau1 = TROIS_FOIS;
                        break;
                    case TROIS_FOIS:
                        bateau1 = COULE;
                        break;
                    default:
                        break;
                    }
                }
                // mise à jour de l'etat du bateau 1
                if (indiceBateau == 1)
                {
                    switch (bateau2)
                    {
                    case ZERO_FOIS:
                        bateau2 = UNE_FOIS;
                        break;
                    case UNE_FOIS:
                        bateau2 = DEUX_FOIS;
                        break;
                    case DEUX_FOIS:
                        bateau2 = TROIS_FOIS;
                        break;
                    case TROIS_FOIS:
                        bateau2 = COULE;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
    // Affichage d'un point si la coordonnées entré est entre A et I et 1 et 9 et si elle n'a pas touché de bateau
    if (dansLeTableau == false)
    {
        tableau[int(tirJoueurx) - 49][int(tirJoueury) - 65] = '.';
    }
}
void initialiserLaPartie()
{

    // Appel de la procédure pour générer le tableau
    genererTableau(tableauDeJeu);
    // Appel de la procédure pour le choix des pseudos
    choisirPseudoDesJoueurs(pseudoJ1, pseudoJ2);
    // Appel de la procédure pour afficher le tableau
    afficherTableau(tableauDeJeu);
    // Boucle permettant de ré-générer des bateaux tant qu'il ne se croise pas
    while ((!verifierCroisementBateaux(bateaux)) || (!verifCroisBateau(bateaux)))
    {
        genererPositionBateaux(bateaux);
    }
    // appel de la procédure permettant d'afficher les bateaux
    afficherBateau();
}
// Procédure regroupant toutes les procédure essentielles pour l'affichage
void affichage()
{
    // Appel de la procédure affichageEnTete
    affichageEnTete();
    // Appel de la procédure afficherTableau
    afficherTableau(tableauDeJeu);
    // Appel de la procédure afficherBateau
    afficherBateau();
}

// définition de la procédure permettant l'affichage de l'en-tête
void affichageEnTete()
{
    // En-tête de l'interface demandée
    string titre = "B A T A I L L E  N A V A L E";
    cout << titre << endl;
    cout << endl;
    cout << "Chaque joueur doit couler un bateau de 4 cases " << endl
         << "(Vertical ou Horizontal ou Diagonale)" << endl;
    cout << endl;
}
// Définition de la procédure permettant de jouer la partie
void jouerLaPartie()
{
    // Boucle permettant de jouer la partie tant qu'un gagnant n' pas été détérminé
    while (gagnantDeLaPartie == "")
    {
        tirBateau(bateaux, tableauDeJeu, pseudoJ1, pseudoJ2, abandonJ1, abandonJ2);
        if (gagnantDeLaPartie == "") // verification si le joueur1 n'a pas abandonné ou coulé le bateau1
        {
            tirBateau(bateaux, tableauDeJeu, pseudoJ2, pseudoJ1, abandonJ1, abandonJ2);
        }
        if (gagnantDeLaPartie == "") // verification si le joueur2 n'a pas abandonné ou coulé le bateau2
        {
            // affectation de la valeur retourné par definirGagnant a la variable gagnantDeLaPartie
            gagnantDeLaPartie = definirGagnant(pseudoJ1, pseudoJ2, gagnantDeLaPartie);
            dernierTirApresGagnant(pseudoJ1, pseudoJ2, gagnantDeLaPartie);
        }
    }
}
// Definition de la procédure finaliserLaPartie
void finaliserLaPartie()
{
    // Appel de la procédure permettant d'afficher le gagnant
    afficherGagnant(gagnantDeLaPartie, abandonJ1, abandonJ2);
}
// Definition de la focntion definirGagnant
string definirGagnant(string joueur1, string joueur2, string &gagnantPartie)
{
    if (bateau1 == COULE)
    {
        gagnantPartie = joueur1;
    }
    else if (bateau2 == COULE)
    {
        gagnantPartie = joueur2;
    }
    else if (bateau1 == COULE && bateau2 == COULE)
    {
        gagnantPartie = joueur1 + " et " + joueur2;
    }
    return gagnantPartie;
}

void dernierTirApresGagnant(string joueur1, string joueur2, string gagnantPartie)
{
    if (gagnantPartie == pseudoJ1)
    {
        affichage();
        cout << pseudoJ2 << " tu a le droit de faire un dernier tir" << endl;
        pause(3); // pause pour laisser le temps a l'utilisateur de lire car la procédure effacer() est présente au début de tir bateau
        tirBateau(bateaux, tableauDeJeu, pseudoJ2, pseudoJ1, abandonJ1, abandonJ2);
        definirGagnant(joueur1, joueur2, gagnantDeLaPartie);
    }
    else if (gagnantPartie == pseudoJ2)
    {
        affichage();
        cout << pseudoJ1 << " tu a le droit de faire un dernier tir" << endl;
        pause(3); // pause pour laisser le temps a l'utilisateur de lire car la procédure effacer() est présente au début de tir bateau
        tirBateau(bateaux, tableauDeJeu, pseudoJ1, pseudoJ2, abandonJ1, abandonJ2);
        definirGagnant(joueur1, joueur2, gagnantDeLaPartie);
    }
}

void afficherGagnant(string gagnantPartie, bool abanJ1, bool abanJ2)
{
    if (gagnantPartie != pseudoJ1 && gagnantPartie != pseudoJ2)
    {
        cout << "Il ya a egalite bien jouer a tout les deux" << endl;
    }
    else if (abanJ1 == true)
    {
        cout << "Bien joue " << pseudoJ2 << ", " << pseudoJ1 << " a abandonne la partie" << endl;
    }
    else if (abanJ2 == true)
    {
        cout << "Bien joue " << pseudoJ1 << ", " << pseudoJ2 << " a abandonne la partie" << endl;
    }
    else
    {
        cout << "Bien jouer " << gagnantPartie << " tu as remporte cette partie";
    }
}

// Définition de la procédure pour générer un tableau de 9x9 vide
void genererTableau(char tableau[NB_CASES][NB_CASES])
{
    for (int indiceTableau1 = 0; indiceTableau1 < 9; indiceTableau1++)
    {
        for (int indiceTableau2 = 0; indiceTableau2 < 9; indiceTableau2++)
        {
            // Remplissage du tableau avec un caractère vide
            tableau[indiceTableau1][indiceTableau2] = ' ';
        }
    }
}
// définition de la procédure permettant de générer les bateaux
void genererPositionBateaux(Bateau Bateaux[NB_BATEAUX])
{
    for (unsigned short int indiceBateau = 0; indiceBateau < NB_BATEAUX; indiceBateau++)
    {

        int nbDirBateau = random(0, 7); // tirage aléatoire de la direction des 2 bateaux
        bool diagOK = false;
        Bateaux[indiceBateau].pos[0].x = random(1, 9); // tirage aléatoire de la première coordonnée x du bateau
        Bateaux[indiceBateau].pos[0].y = random(1, 9); // tirage aléatoire de la première coordonnée y du bateau

        switch (nbDirBateau)
        {
        case DIR_HORIZONTALE_DROITE:                      // génération des bateaux vers la droite
            if ((Bateaux[indiceBateau].pos[0].x + 3) > 9) // condition pour voir si la dernière coordonnée x générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if ((Bateaux[indiceBateau].pos[0].y + 3) > 9) // condition pour voir si la dernière coordonnée y générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            for (int i = 1; i <= 3; i++)
            {
                Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y + i;
                Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x;
            }
            break;
        case DIR_HORIZONTALE_GAUCHE:                      // génération des bateaux vers la gauche
            if ((Bateaux[indiceBateau].pos[0].x + 3) > 9) // condition pour voir si la dernière coordonnée x générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if ((Bateaux[indiceBateau].pos[0].y - 3) < 1) // condition pour voir si la dernière coordonnée y générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            for (int i = 1; i <= 3; i++)
            {
                Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y - i;
                Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x;
            }

            break;
        case DIR_VERTICALE_HAUT:                          // génération des bateaux vers le haut
            if ((Bateaux[indiceBateau].pos[0].x + 3) > 9) // condition pour voir si la dernière coordonnée x générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if ((Bateaux[indiceBateau].pos[0].y + 3) > 9) // condition pour voir si la dernière coordonnée y générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            for (int i = 1; i <= 3; i++)
            {
                Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x + i;
                Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y;
            }

            break;
        case DIR_VERTICALE_BAS:                           // génération des bateaux vers le bas
            if ((Bateaux[indiceBateau].pos[0].x - 3) < 1) // condition pour voir si la dernière coordonnée x générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if ((Bateaux[indiceBateau].pos[0].y + 3) > 9) // condition pour voir si la dernière coordonnée y générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
            }
            for (int i = 1; i <= 3; i++)
            {
                Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x - i;
                Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y;
            }
            break;
        case DIR_DIAGONALE_NO: // génération des bateaux vers le Nord-Ouest
            diagOK = false;
            if (((Bateaux[indiceBateau].pos[0].x) + 3) > 9) // condition pour voir si la dernière coordonnée x générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if (((Bateaux[indiceBateau].pos[0].y) - 3) < 1) // condition pour voir si la dernière coordonnée y générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            while (diagOK != true) // boucle permettant de générer des bateaux dans la diagonales tant que le bateau n'a pas les bonnes coordonnées
            {

                for (int i = 1; i <= 3; i++) // génération des bateaux dans le sens de leur diagonale
                {
                    Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x + i;
                    Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y - i;
                }
                // verification si les coordonnées sont dans le même intervalle que celui du tableau
                if ((Bateaux[indiceBateau].pos[3].x > 9) || (Bateaux[indiceBateau].pos[3].y > 9) || (Bateaux[indiceBateau].pos[3].y < 1) || (Bateaux[indiceBateau].pos[3].x < 1))
                {
                    genererPositionBateaux(bateaux);
                    return;
                }
                if (Bateaux[indiceBateau].pos[3].x <= 9 || Bateaux[indiceBateau].pos[3].y >= 1)
                {
                    diagOK = true;
                }
            }

            break;
        case DIR_DIAGONALE_NE: // génération des bateaux vers le Nord-Est
            diagOK = false;
            if (((Bateaux[indiceBateau].pos[0].x) + 3) > 9) // condition pour voir si la dernière coordonnée x générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if (((Bateaux[indiceBateau].pos[0].y) + 3) > 9) // condition pour voir si la dernière coordonnée y générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            while (diagOK != true) // boucle permettant de générer des bateaux dans la diagonales tant que le bateau n'a pas les bonnes coordonnées
            {

                for (int i = 1; i <= 3; i++) // génération des bateaux dans le sens de leur diagonale
                {
                    Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x + i;
                    Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y + i;
                }
                // verification si les coordonnées sont dans le même intervalle que celui du tableau
                if ((Bateaux[indiceBateau].pos[3].x > 9) || (Bateaux[indiceBateau].pos[3].y > 9) || (Bateaux[indiceBateau].pos[3].y < 1) || (Bateaux[indiceBateau].pos[3].x < 1))
                {
                    genererPositionBateaux(bateaux);
                    return;
                }
                if (Bateaux[indiceBateau].pos[3].x <= 9 && Bateaux[indiceBateau].pos[3].y <= 9)
                {
                    diagOK = true;
                }
            }

            break;
        case DIR_DIAGONALE_SE: // génération des bateaux vers le Sud-Est
            diagOK = false;
            if (((Bateaux[indiceBateau].pos[0].x) - 3) < 1) // condition pour voir si la dernière coordonnée x générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if (((Bateaux[indiceBateau].pos[0].y) + 3) > 9) // condition pour voir si la dernière coordonnée y générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            while (diagOK != true) // boucle permettant de générer des bateaux dans la diagonales tant que le bateau n'a pas les bonnes coordonnées
            {

                for (int i = 1; i <= 3; i++) // génération des bateaux dans le sens de leur diagonale
                {
                    Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x - i;
                    Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y + i;
                }
                // verification si les coordonnées sont dans le même intervalle que celui du tableau
                if ((Bateaux[indiceBateau].pos[3].x > 9) || (Bateaux[indiceBateau].pos[3].y > 9) || (Bateaux[indiceBateau].pos[3].y < 1) || (Bateaux[indiceBateau].pos[3].x < 1))
                {
                    genererPositionBateaux(bateaux);
                    return;
                }
                if (Bateaux[indiceBateau].pos[3].x >= 1 || Bateaux[indiceBateau].pos[3].y <= 9)
                {
                    diagOK = true;
                }
            }

            break;
        case DIR_DIAGONALE_SO: // génération des bateaux vers le Sud-Ouest
            diagOK = false;
            if (((Bateaux[indiceBateau].pos[0].x) - 3) < 1) // condition pour voir si la dernière coordonnée x générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            if (((Bateaux[indiceBateau].pos[0].y) - 3) < 1) // condition pour voir si la dernière coordonnée y générée sera hors du tableauDeJeu
            {
                genererPositionBateaux(bateaux);
                return;
            }
            while (diagOK != true) // boucle permettant de générer des bateaux dans la diagonales tant que le bateau n'a pas les bonnes coordonnées
            {

                for (int i = 1; i <= 3; i++) // génération des bateaux dans le sens de leur diagonale
                {
                    Bateaux[indiceBateau].pos[i].x = Bateaux[indiceBateau].pos[0].x - i;
                    Bateaux[indiceBateau].pos[i].y = Bateaux[indiceBateau].pos[0].y - i;
                }
                // verification si les coordonnées sont dans le même intervalle que celui du tableau
                if ((Bateaux[indiceBateau].pos[3].x > 9) || (Bateaux[indiceBateau].pos[3].y > 9) || (Bateaux[indiceBateau].pos[3].y < 1) || (Bateaux[indiceBateau].pos[3].x < 1))
                {
                    genererPositionBateaux(bateaux);
                    return;
                }
                if (Bateaux[indiceBateau].pos[3].x >= 1 || Bateaux[indiceBateau].pos[3].y >= 1)
                {
                    diagOK = true;
                }
            }

            break;

        default:
            break;
        }
    }
}
// Procédure pour afficher le tableau
void afficherTableau(char tableau[NB_CASES][NB_CASES])
{
    // Affichage de la ligne supérieure avec des lettres de A à I
    cout << "  "; // Deux espaces initiaux pour l'alignement
    for (char lettre = 'A'; lettre < 'A' + NB_CASES; lettre++)
    {
        cout << lettre << " "; // Un espace après chaque lettre pour les séparer
    }
    cout << endl;

    for (int indiceTableau1 = 0; indiceTableau1 < NB_CASES; indiceTableau1++)
    {
        // Affichage des chiffres sur le côté gauche
        cout << indiceTableau1 + 1 << " "; // Espace après le chiffre pour l'alignement des cases

        for (int indiceTableau2 = 0; indiceTableau2 < NB_CASES; indiceTableau2++)
        {
            // Affichage du contenu de la case
            if (indiceTableau2 < NB_CASES - 1)
            {
                cout << tableau[indiceTableau1][indiceTableau2] << ' ';
            }
            else
            {
                cout << tableau[indiceTableau1][indiceTableau2]; // Un espace après chaque caractère pour les séparer
            }
        }

        // Affichage des chiffres sur le côté droit après un espace supplémentaire pour l'aligner après la lettre I
        cout << " " << indiceTableau1 + 1 << endl; // Un espace avant le chiffre de droite pour l'alignement
    }

    // Affichage de la ligne inférieure avec des lettres de A à I
    cout << "  "; // Deux espaces initiaux pour l'alignement
    for (char lettre = 'A'; lettre < 'A' + NB_CASES; lettre++)
    {
        cout << lettre << " "; // Un espace après chaque lettre pour les séparer
    }
    cout << endl;
}
