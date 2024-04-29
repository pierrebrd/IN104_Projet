#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"
#include "deplacement.h"
#include "legit.h"

int victoire(jeu_t *jeu);
/*
Retourne 0 si personne a gagné
1 si le joueur 1 gagne
2 si le joueur 2 gagne
*/