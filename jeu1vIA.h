#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> //pour utiliser sleep
#include <time.h>   //pour initialiser le random

#include "deplacement.h"
#include "affichage.h"
#include "legit.h"
#include "initialisation.h"
#include "victoire.h"
#include "hasard.h"
#include "UX.h"
#include "IA.h"

void jeu1vIA_aleatoire();
/* permet  de joueur contre un ordinateur, qui joue des coups aléatoires */

void jeu1vIA();
/* permet de joueur contre un ordinateur, qui joue des coups en utilisant l'algorithme MCTS */

void jeu1vIA_improved();
/* permet de joueur contre un ordinateur, qui joue des coups en utilisant l'algorithme MCTS modifié comme décrit dans le fichier "IA.h" */