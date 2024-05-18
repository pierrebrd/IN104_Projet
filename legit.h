#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"

int legit(jeu_t *jeu, int ia, int ja, int ib, int jb, int type_pion);
/*
Fonction qui permet d'indiquer si un déplacement de (ia,ja) vers (ib,jb) est possible dans la grille actuelle, compte tenu
du type du pion

renvoie 0 si déplacement correct, ou des codes d'erreur de 1 à 6 en fonction du problème si le déplacement est impossible
*/

int legit_direction(jeu_t *jeu, int indice_coup);
/*
Détermine s'il est possible de jouer le coup, ie si le bobail peut se dépacer d'une case selon direction_bobail et si le pion peut se déplacer d'au moins une case selon direction_pion.

ARGUMENTS
jeu_t* jeu : contient une matrice int** correspondant à l'occupation de chaque case du plateau de jeu (0 si vide, 1 si pion du joueur 1, 2 si pion du joueur 2, 3 si bobail) ; une liste x_pions contenant les absisses des positions des pions ; une liste int* y_pions contenant les ordonnées des positions des pion (indices 0 à 4 pour joueur 1, 5 à 9 pour joueur 2, 10 pour bobail)

int indice_coup : entier qui code un coup possible d'un ds deux joueurs. 40*direction_bobail + 8*nb_pion%5 + direction_pion
Pour retrouver de manière explicite : 
direction_bobail = indice_coup / 40;
nb_pion = (indice_coup % 40) / 8 + 5 * (joueur - 1);
direction_pion = indice_coup % 8;

VALEURS DE RETOUR 
0 si le coup est légal
1 si le coup est illégal à cause du bobail
2 si le coup est illégal à cause du pion

*/