#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"
#include "hasard.h"
#include "victoire.h"

int explore_aleatoire(jeu_t *jeu_provisoire, int joueur, int tour);
/* effectue plusieurs coups aléatoire jusqu'à arriver à la fin du jeu, renvoie 1 ou 2 en fonction du gagnant et 0 si le jeu est bloqué */

int MCTS(jeu_t *jeu, int joueur, int tour);
/* Effectue un coup en utilisant la méthode de MCTS */