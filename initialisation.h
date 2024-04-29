#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// On va créer un struct pour gérer l'état actuel du jeu, qui contiendra la grille ainsi que la liste des positions des pions et du bobail

#ifndef STRUCT_DEJA_INCLUS // On ne recrée pas le struct si il a déja été crée lors d'une précendente inclusion de initialisation.h
#define STRUCT_DEJA_INCLUS

typedef struct jeu_t
{
    int **grille;
    int *x_pions; // contient les positions x des pions du joueur 1, puis du joueur 2, puis du bobail (liste de taille 11)
    int *y_pions;
} jeu_t;

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
/*detruit le struct en libérant l'espace mémoire*/
