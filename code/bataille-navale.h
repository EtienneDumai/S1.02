/**
 * @file bataille-navale.h
 * @author Dumai Etienne
 * @brief Fichier d'entête du module bataille navale
 * @date 2024-01-18
 */

#ifndef BATAILLE_NAVALE_H
#define BATAILLE_NAVALE_H

#include "game-tools.h"
#include <iostream>
using namespace std;

/**
 * @brief Liste des directions dans lesquelles vont se générer les bateaux
 */
enum Direction
{
    /** La direction horizontale gauche a pour code direction 0*/
    DIR_HORIZONTALE_GAUCHE = 0,
    /** La direction horizontale droite a pour code direction 1*/
    DIR_HORIZONTALE_DROITE = 1,
    /** La direction verticale haut a pour code direction 2*/
    DIR_VERTICALE_HAUT = 2,
    /** La direction verticale bas a pour code direction 3*/
    DIR_VERTICALE_BAS = 3,
    /** La direction diagonale nord-ouest a pour code direction 4*/
    DIR_DIAGONALE_NO = 4,
    /** La direction diagonale nord-est a pour code direction 5*/
    DIR_DIAGONALE_NE = 5,
    /** La direction diagonale sud-ouest a pour code direction 6*/
    DIR_DIAGONALE_SO = 6,
    /** La direction diagonale sud-est a pour code direction 7*/
    DIR_DIAGONALE_SE = 7,
};

/**
 * @brief Liste du nombre de fois un bateau est touché
 */
enum Touche
{
    /** Le nombre de fois zero fois a pour code touche 0*/
    ZERO_FOIS = 0,
    /** Le nombre de fois une fois a pour code touche 1*/
    UNE_FOIS = 1,
    /** Le nombre de fois deux fois a pour code touche 2*/
    DEUX_FOIS = 2,
    /** Le nombre de fois trois fois a pour code touche 3*/
    TROIS_FOIS = 3,
    /** Le nombre de fois coule a pour code touche 4*/
    COULE = 4,
};
/**
 * @brief Enregistrement de type Coordonnees avec les valeurs x et y qui sont des int
 */
struct Coordonnees
{
    int x = 0; // Abscisse de la coordonnée
    int y = 0; // Ordonnée de la coordonnée
};
/**
 * @brief Enregistrement de type Bateau avec un tableau qui est de type Coorodnnees
 */
const unsigned short int NB_CASES_BATEAU = 4;
struct Bateau
{
    Coordonnees pos[NB_CASES_BATEAU]; // un bateau du jeu aura NB_CASES_BATEAU coordonnees
};
const unsigned short int NB_CASES = 9; // Nombre de cases présente dans le tableau du jeux
const unsigned short int NB_BATEAUX = 2; // Nombre de bateau qui seront présent dans le jeu

void genererTableau(char tableau[NB_CASES][NB_CASES]);
// BUT : générer un tableau de caractère de NB_CASES de large et de long

void afficherTableau(char tableau[NB_CASES][NB_CASES]);
// BUT : Afficher le tableau entré en paramètre

void genererPositionBateaux(Bateau Bateaux[NB_BATEAUX]);
// BUT : générer aléatoirement les coordonnées des bateaux dans le tableau bateaux de type bateau

void afficherBateau();
// BUT : afficher les coordonées des bateaux

bool verifierCroisementBateaux(Bateau Bateaux[NB_BATEAUX]);
/*BUT : verifier dans le tableau Bateaux de longueur NB_BATEAU si entre les 2 bateaux
il n'y a pas de croisement (coordonnée exacte dans les 2 bateaux)*/

bool verifCroisBateau(Bateau Bateaux[NB_BATEAUX]);
// BUT : verifier si 2 bateaux ne se croise pas en ayant aucun points en commun

void choisirPseudoDesJoueurs(string &joueur1, string &joueur2);
/* BUT : assigner des pseudo au joueur avec les chaines de caractère
qui seront passées en paramètre*/

void tirBateau(Bateau Bateaux[NB_BATEAUX], char tableau[NB_CASES][NB_CASES], string joueur1, string joueur2, bool &abanJ1, bool &abanJ2);
/* BUT : réaliser des tirs entre joueur1 et joueur2 chacun leurs tours en visant les
bateaux qui ont leurs coordonées dans le tableau Bateaux de longeur NB_BATEAUX*/

void initialiserLaPartie();
// BTU: regrouper tout les sous-programmes nécessaires à l'initialisation de la partie

void affichage();
// BUT: regrouper tout les sous-programmes nécessaire à l'affichage escompté et décris dans les spécifications externes

void affichageEnTete();
// BUT: affichage de l'entête du jeu, procédure dans le sous programme affichage()

void jouerLaPartie();
// BUT regrouper tout les sous-programmes nécessaire pour jouer le jeu et veiller à son bon déroulement

void finaliserLaPartie();
// BUT: regrouper tout les sous-programmes nécessaire a la finalisation de la partie

string definirGagnant(string joueur1, string joueur2, string &gagnantPartie);
/* BUT : définir le gagnant de la parti entre joueur1 et joueur2 et la chaine de
caractère gagnant prendra son pseudo comme valeur*/

void dernierTirApresGagnant(string joueur1, string joueur2, string gagnantPartie);
// BUT: permettre au joueur qui a perdu de faire un dernier tir avant la fin de la partie

void afficherGagnant(string gagnantPartie, bool abanJ1, bool abanJ2);
/* BUT : afficher le pseudo du gagnant de la partie qui est contenu dans la variable
gagnantPartie*/

#endif