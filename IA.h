#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"
#include "hasard.h"
#include "victoire.h"
#include "legit.h"

int explore_aleatoire(jeu_t *jeu_provisoire, int joueur, int tour);
/* effectue plusieurs coups aléatoire jusqu'à arriver à la fin du jeu, renvoie 1 ou 2 en fonction du gagnant et 0 si le jeu est bloqué */

int MCTS(jeu_t *jeu, int joueur, int tour, int nbr_simulations);
/* Renvoie un coup à jouer en utilisant la méthode de MCTS
Le coup est repéré par la méthode d'indiciation suivante :
Indice d'un coup possible: 40*direction_bobail + 8*nb_pion%5 + direction_pion
Pour retrouver de manière explicite : 
direction_bobail = indice_coup / 40;
nb_pion = (indice_coup % 40) / 8 + 5 * (joueur - 1);
direction_pion = indice_coup % 8;*/

int MCTS_improved_marche_pas(jeu_t *jeu, int joueur, int tour, int anticipation);
/* Renvoie un coup à jouer basé sur la méthode de MCTS modifiée
L'IA évite maintenant de faire des coups qui mènent à une défaite rapide
Le coup est repéré par la méthode d'indiciation expliquée A TEL ENDROIT */

int MCTS_improved(jeu_t *jeu, int joueur, int tour) ;