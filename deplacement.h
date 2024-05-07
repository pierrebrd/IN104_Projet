#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "legit.h"
#include "initialisation.h"

void changement_position(jeu_t *jeu, int *pos, int type_pion);
/*Change la position d'un pion dans x_pions et y_pions*/

int input(int *pos);
/*Prend en argument un tableau de 4 entiers,
le modifie en place pour representer les coordonnées
de la position initiale (index 0 pour abs, 1 pour ordonnee)
de la position finale (index 2 pour abs, 3 pour ordonnee)

Retourne 0 si tout est ok
Retourne 1 si mauvais format d'input par l'utilisateur
 */

int coup(jeu_t *jeu, int type_pion);
/*Prend en argument un état du plateau de jeu,
demande a l'utilisateur le coup à faire (appel à input),
vérifie qu'il est légal (appel à legit)

Retourne 0 si tout est ok
Retourne 1 si mauvais format d'entrée
Retourne 2 si déplacement illégal*/

void jouer_coup(jeu_t *jeu, int joueur, int indice_coup);
/*Joue un coup indicé entre 0 et 359*/