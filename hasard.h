#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"

int coup_hasard(jeu_t *jeu, int joueur, int tour);
/* Génère un coup aléatoire (avec rand() de la bibliothèque stdlib.h) en vérifiant que le coup est possible, en prenant en compte le joueur qui joue et le tour (on ne bouge pas le bobail au tour 1)

ARGUMENTS
jeu_t *jeu : struct qui contient une matrice int** correspondant à l'occupation de chaque case du plateau de jeu (0 si vide, 1 si pion du joueur 1, 2 si pion du joueur 2, 3 si bobail) ; une liste x_pions contenant les absisses des positions des pions ; une liste int* y_pions contenant les ordonnées des positions des pion (indices 0 à 4 pour joueur 1, 5 à 9 pour joueur 2, 10 pour bobail)

int joueur : 1 si joueur 1, 2 si joueur 2

int tour : nombre de fois qu'on a joué, commence à 1

VALEUR DE RETOUR
indice compris entre à et 359 défini par : Indice d'un coup possible: 40*direction_bobail + 8*nb_pion%5 + direction_pion
Pour retrouver de manière explicite :
direction_bobail = indice_coup / 40;
nb_pion = (indice_coup % 40) / 8 + 5 * (joueur - 1);
direction_pion = indice_coup % 8;

404 si le jeu est bloqué (le joueur ne peut pas bouger)*/
