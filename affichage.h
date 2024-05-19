#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"

void affichercase(int i, int j, jeu_t *jeu);
/*
affiche dans le terminal la case (i,j) de la grille

ARGUMENTS
int i : numéro de ligne de la case a afficher
int j : numéro de colonne de la case a afficher

VALEUR DE RETOUR
void
 */

void afficher(jeu_t *jeu);
/*affiche dans le terminal l'état actuel du jeu

ARGUMENT
jeu_t* jeu : struct qui contient une matrice int** correspondant à l'occupation de chaque case du plateau de jeu (0 si vide, 1 si pion du joueur 1, 2 si pion du joueur 2, 3 si bobail) ; une liste x_pions contenant les absisses des positions des pions ; une liste int* y_pions contenant les ordonnées des positions des pion (indices 0 à 4 pour joueur 1, 5 à 9 pour joueur 2, 10 pour bobail)

VALEUR DE RETOUR
void
*/
