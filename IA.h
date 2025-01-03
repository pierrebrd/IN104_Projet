#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"
#include "hasard.h"
#include "victoire.h"
#include "legit.h"
#include "deplacement.h"

int explore_aleatoire(jeu_t *jeu_provisoire, int joueur, int tour);
/* effectue plusieurs coups aléatoire jusqu'à arriver à la fin du jeu, renvoie 1 ou 2 en fonction du gagnant et 0 si le jeu est bloqué */

int MCTS(jeu_t *jeu, int joueur, int tour, int nbr_simulations);
/* Applique l'algorithme Monte-Carlo Tree Search pour choisir un coup

ARGUMENTS
jeu_t *jeu : struct qui contient une matrice int** correspondant à l'occupation de chaque case du plateau de jeu (0 si vide, 1 si pion du joueur 1, 2 si pion du joueur 2, 3 si bobail) ; une liste x_pions contenant les absisses des positions des pions ; une liste int* y_pions contenant les ordonnées des positions des pion (indices 0 à 4 pour joueur 1, 5 à 9 pour joueur 2, 10 pour bobail)

int joueur : vaut 1 si c'est au joueur 1, 2 si c'est au joueur 2, de jouer

int nbr_simulations : MCTS simule nbr_simulations parties aléatoires, nombre qu'on fait varier afin d'avoir un controle sur le temps d'execution. Plus il est élevé, plus le coup choisi sera pertinent

VALEURS DE RETOUR
indice du coup à jouer défini par : 40*direction_bobail + 8*nb_pion%5 + direction_pion
Pour retrouver de manière explicite :
direction_bobail = indice_coup / 40;
nb_pion = (indice_coup % 40) / 8 + 5 * (joueur - 1);
direction_pion = indice_coup % 8;
*/

int MCTS_improved(jeu_t *jeu, int joueur, int tour, int nbr_simulations);
/* Renvoie un coup à jouer basé sur la méthode de MCTS que nous avons modifié. Lorsqu'on simule les parties pour déterminer le meilleur coup possible, le premier coup de l'adversaire est lui-meme déterminé par MCTS et non pas randomisé. Cela permet à l'IA d'éviter de faire des coups qui mènent à une défaite rapide

ARGUMENTS
jeu_t *jeu : struct qui contient une matrice int** correspondant à l'occupation de chaque case du plateau de jeu (0 si vide, 1 si pion du joueur 1, 2 si pion du joueur 2, 3 si bobail) ; une liste x_pions contenant les absisses des positions des pions ; une liste int* y_pions contenant les ordonnées des positions des pion (indices 0 à 4 pour joueur 1, 5 à 9 pour joueur 2, 10 pour bobail)

int joueur : vaut 1 si c'est au joueur 1, 2 si c'est au joueur 2, de jouer

int nbr_simulations : MCTS simule nbr_simulations parties aléatoires, nombre qu'on fait varier afin d'avoir un controle sur le temps d'execution. Plus il est élevé, plus le coup choisi sera pertinent

VALEURS DE RETOUR
indice du coup à jouer défini par : 40*direction_bobail + 8*nb_pion%5 + direction_pion
Pour retrouver de manière explicite :
direction_bobail = indice_coup / 40;
nb_pion = (indice_coup % 40) / 8 + 5 * (joueur - 1);
direction_pion = indice_coup % 8;*/
