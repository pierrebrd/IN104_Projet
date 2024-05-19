#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef STRUCT_DEJA_INCLUS // On ne recrée pas le struct et l'enum des directions si ils ont déja étés crées lors d'une précendente inclusion de initialisation.h
#define STRUCT_DEJA_INCLUS

typedef struct jeu_t
{
    int **grille;
    int *x_pions; // contient les positions x des pions du joueur 1, puis du joueur 2, puis du bobail (liste de taille 11)
    int *y_pions;
} jeu_t;

typedef enum
{
    NORD,
    SUD,
    OUEST,
    EST,
    NORDOUEST,
    NORDEST,
    SUDOUEST,
    SUDEST,
    RIEN
} direction_t;

#endif

jeu_t *initialisation();
/*crée une matrice 5*5, la remplit
remplit en place la config initiale de la matrice

0 : case vide
1 : case remplie par un pion du joueur 1
2 : case remplie par un pion du joueur 2
3 : case remplie par le bobail

convention coordonnées : comme une matrice mais indices entre 0 et 4
lignes i croissant de haut en bas
colonnes j croissant de gauche à droite
-> le joueur 1 a ses pions dans la colonne j=0, et le joueur 2 dans j=4
Initilialise aussi le struct, et le renvoie
*/

void destruction(jeu_t *jeu);
/*detruit le struct en libérant l'espace mémoire en utilisant free()

ARGUMENTS
jeu_t *jeu : struct qui contient une matrice int** correspondant à l'occupation de chaque case du plateau de jeu (0 si vide, 1 si pion du joueur 1, 2 si pion du joueur 2, 3 si bobail) ; une liste x_pions contenant les absisses des positions des pions ; une liste int* y_pions contenant les ordonnées des positions des pion (indices 0 à 4 pour joueur 1, 5 à 9 pour joueur 2, 10 pour bobail)

VALEURS DE RETOUR
void*/

void copy_jeu(jeu_t *old_jeu, jeu_t *new_jeu);
/*Copie les valeurs de old_jeu dans le strcut new_jeu. On ne peut pas copier directement le struct parce que cela revient juste à créer un second pointeur vers la même adresse

ARGUMENTS
jeu_t* old_jeu : ancien jeu à copier. Il s'agit d'un struct qui contient une matrice int** correspondant à l'occupation de chaque case du plateau de jeu (0 si vide, 1 si pion du joueur 1, 2 si pion du joueur 2, 3 si bobail) ; une liste x_pions contenant les absisses des positions des pions ; une liste int* y_pions contenant les ordonnées des positions des pion (indices 0 à 4 pour joueur 1, 5 à 9 pour joueur 2, 10 pour bobail)

jeu_t* new_jeu : struct vierge dans lequel on va copier les valeurs de old_jeu. Il s'agit d'un struct qui contient une matrice int** correspondant à l'occupation de chaque case du plateau de jeu (0 si vide, 1 si pion du joueur 1, 2 si pion du joueur 2, 3 si bobail) ; une liste x_pions contenant les absisses des positions des pions ; une liste int* y_pions contenant les ordonnées des positions des pion (indices 0 à 4 pour joueur 1, 5 à 9 pour joueur 2, 10 pour bobail)
 */
