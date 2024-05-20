#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "legit.h"
#include "initialisation.h"
#include "victoire.h"

void changement_position(jeu_t *jeu, int *pos, int type_pion);
/*Change la position d'un pion dans x_pions et y_pions à partir de son ancienne et sa nouvelle position, représentées dans la liste de 4 entiers pos

ARGUMENTS
jeu_t* jeu : struct qui contient une matrice int** correspondant à l'occupation de chaque case du plateau de jeu (0 si vide, 1 si pion du joueur 1, 2 si pion du joueur 2, 3 si bobail) ; une liste x_pions contenant les absisses des positions des pions ; une liste int* y_pions contenant les ordonnées des positions des pion (indices 0 à 4 pour joueur 1, 5 à 9 pour joueur 2, 10 pour bobail)

int* pos : liste de 4 entiers correspond (dans l'ordre) à ancienne absisse, ancienne ordonnée, nouvelle absisse, nouvelle ordonnée

int type_pion : 1 pour pion du joueur 1, 2 pour pion du joueur 2, 3 pour bobail

VALEUR DE RETOUR
void*/

int input(int *pos);
/*Demande à l'utilisateur (via la ligne de commande) la position avant déplacement et la position après déplacement de son pion. Ces valeurs sont stockées dans int* pos qui est modifié en place

ARGUMENT
int* pos : liste de 4 chiffres qui est modifié en place pour stocker les coordonnées avant (indice 0 pour absisse, 1 pour ordonnée) et après deplacement (indice 2 pour absisse, 3 pour ordonnée)


VALEUR DE RETOUR
0 si tout est ok
1 si mauvais format d'input par l'utilisateur
 */

int coup(jeu_t *jeu, int type_pion);
/*Demande a l'utilisateur via la ligne de commande le coup qu'il veut jouer (appel à input de deplacement.h),
vérifie qu'il est légal (appel à legit de legit.h)

ARGUMENT
jeu_t *jeu : struct qui contient une matrice int** correspondant à l'occupation de chaque case du plateau de jeu (0 si vide, 1 si pion du joueur 1, 2 si pion du joueur 2, 3 si bobail) ; une liste x_pions contenant les absisses des positions des pions ; une liste int* y_pions contenant les ordonnées des positions des pion (indices 0 à 4 pour joueur 1, 5 à 9 pour joueur 2, 10 pour bobail)

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


VALEUR DE RETOUR
void
*/