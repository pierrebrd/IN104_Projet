#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"
#include "deplacement.h"
#include "legit.h"

int victoire(jeu_t *jeu, int joueur);
/*
Retourne 0 si personne n'a gagné
1 si le joueur 1 gagne
2 si le joueur 2 gagne

int joueur est le joueur qui s'apprête à jouer. Si le bobail est bloqué, int joueur a perdu
*/