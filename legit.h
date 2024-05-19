#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"

int legit(jeu_t *jeu, int ia, int ja, int ib, int jb, int type_pion);
/*
Fonction qui permet d'indiquer si un déplacement de (ia,ja) vers (ib,jb) est possible dans la grille actuelle, compte tenu
du type du pion

ARGUMENTS
jeu_t* jeu : contient une matrice int** correspondant à l'occupation de chaque case du plateau de jeu (0 si vide, 1 si pion du joueur 1, 2 si pion du joueur 2, 3 si bobail) ; une liste x_pions contenant les absisses des positions des pions ; une liste int* y_pions contenant les ordonnées des positions des pion (indices 0 à 4 pour joueur 1, 5 à 9 pour joueur 2, 10 pour bobail)

ia : abscisse initiale
ja : ordonnée initiale
ib : abscissse finale
jb : abscisse finale

VALEUR DE RETOUR
0 si déplacement correct
1 le bobail bouge au 1er tour, ou reste immobile à un coup qui n'est pas le 1er
2 pas de déplacement (initial = final)
3 direction n'est pas une diagonale, une verticale ou une horizontale
4 une case est déja occupée sur le chemin
5 bobail déplacé de plus de 1 case
6 on n'est pas allé au bout du déplacement (ie jusqu'à rencontrer un obstacle)
*/

int legit_direction(jeu_t *jeu, int indice_coup, int joueur, int tour);
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
1 si le coup est illégal

*/