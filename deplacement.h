#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "legit.h"
#include "initialisation.h"

void changement_position(jeu_t *jeu, int *pos, int type_pion);
/*Change la position d'un pion dans x_pions et y_pions à partir de son ancienne et sa nouvelle posistion, représentées dans la liste de 4 entiers pos*/

int input(int *pos);
/*Prend en argument un tableau de 4 entiers,
le modifie en place pour representer les coordonnées
de la position initiale (index 0 pour abs, 1 pour ordonnee)
de la position finale (index 2 pour abs, 3 pour ordonnee)

Retourne 0 si tout est ok
Retourne 1 si mauvais format d'input par l'utilisateur
 */

int coup(jeu_t *jeu, int type_pion);
/*Demande a l'utilisateur via la ligne de commande le coup qu'il veut jouer (appel à input de deplacement.h),
vérifie qu'il est légal (appel à legit de legit.h)

ARGUMENT
jeu_t *jeu : état actuel du jeu
int type_pion : type du pion à deplacer, 1 si appartient à joueur 1, 2 si appartient à joueur 2, 3 si bobail

RETURN VALUES
0 si tout est ok
1 si mauvais format d'entrée
2 si déplacement illégal*/

void jouer_coup(jeu_t *jeu, int joueur, int indice_coup);
/*Joue un coup indicé de la manière suivante comprise entre 0 et 360:
40*direction_bobail + 8*nb_pion%5 + direction_pion
La fonction ne vérifie pas si le coup est légal

Pour retrouver de manière explicite :
direction_bobail = indice_coup / 40;
nb_pion = (indice_coup % 40) / 8 + 5 * (joueur - 1);
direction_pion = indice_coup % 8;

ARGUMENT
jeu_t *jeu : état actuel du jeu
int joueur : numéro du joueur, 1 ou 2
int indice_coup : indice repérant le coup à jouer, décrit ci dessus

*/