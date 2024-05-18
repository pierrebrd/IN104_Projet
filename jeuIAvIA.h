#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "deplacement.h"
#include "affichage.h"
#include "legit.h"
#include "initialisation.h"
#include "victoire.h"

void jeuIAvIA_aleatoire();
/* permet  de regarder deux ordinateurs jouer, qui jouent des coups complètement aléatoires */

void jeuIAvIA();
/* permet  de regarder deux ordinateurs jouer intelligement, en utilisant l'agorithme MCTS classique */

void jeuIAvIA_improved();
/* permet  de regarder deux ordinateurs jouer encore plus intelligement, avec l'algorithme MCTS récursif */
