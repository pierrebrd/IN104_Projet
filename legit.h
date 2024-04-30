#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"

int legit(jeu_t *jeu, int ia, int ja, int ib, int jb, int type_pion);
/*
Fonction qui permet d'indiquer si un déplacement de (ia,ja) vers (ib,jb) est possible dans la grille actuelle, compte tenu
du type du pion

renvoie 0 si déplacement correct, ou des codes d'erreur de 1 à 6 en fonction du problème si le déplacement est impossible
*/