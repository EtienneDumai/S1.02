/**
 * @file main.cpp
 * @author Dumai Etienne
 * @brief Fichier d'execution du jeu de la Bataille Navale
 * @date 2024-01-08
 */

#include <iostream>
#include "game-tools.h"
#include "bataille-navale.h"
using namespace std;
int main()
{
    initialiserLaPartie();
    jouerLaPartie();
    finaliserLaPartie();
    return 0;
}

