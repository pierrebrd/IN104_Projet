#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"

void affichercase(int i, int j, jeu_t *jeu);
/*
affiche dans le terminal la case (i,j) de la grille

int i : numéro de ligne de la case a afficher
int j : numéro de colonne de la case a afficher
 */

void afficher(jeu_t *jeu);
/*affiche dans le terminal l'état actuel du jeu*/
