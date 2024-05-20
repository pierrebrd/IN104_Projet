#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"
#include "legit.h"

int victoire(jeu_t *jeu, int joueur);
/* Dis si le joueur qui s'apprete a jouer a gagné. Si le bobail est bloqué, ce joueur a perdu. Si le bobail est dans la 1er colonne, joueur 1 gagne. SI dans la dernire colonne, joueur 2 gagne

ARGUMENTS
int joueur : le joueur qui s'apprête à jouer.

VALEURS DE RETOUR
0 si personne n'a gagné
1 si le joueur 1 gagne
2 si le joueur 2 gagne
*/