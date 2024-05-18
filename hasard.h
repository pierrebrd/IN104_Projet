#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"

int coup_hasard(jeu_t *jeu, int joueur, int tour);
/* Génère un coup totalement aléatoire en vérifiant que le coup est possible, en prenant en compte le joueur qui joue et le tour (on ne bouge pas le bobail au tour 1)
renvoie l'indice du coup entre 0 et 359, et renvoie 404 si le jeu est bloqué ! (le joueur ne peut pas bouger )*/
