#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "initialisation.h"

int coup_hasard(jeu_t *jeu, int joueur, int tour);
/* Génère un coup totalement aléatoire, en prenant en compte le joueur qui joue et le tour (on ne bouge pas le bobail au tour 1)*/
