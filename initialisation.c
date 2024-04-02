#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"

int **initialisation()
{
    /*crée une matrice 5*5, la remplit et la renvoie
    remplit en place la config initiale de la matrice

    0 : case vide
    1 : case remplie par un pion du joueur 1
    2 : case remplie par un pion du joueur 2
    3 : case remplie par le bobail

    convention coordonnées : comme une matrice mais indices entre 0 et 4
    lignes i croissant de haut en bas
    colonnes j croissant de gauche à droite
    -> le joueur 1 a ses pions dans la colonne j=0, et le joueur 2 dans j=4
    */
    int **grille = malloc(5 * sizeof(int *));
    if (grille == NULL)
    { // check malloc
        printf("Echec malloc.");
    }
    for (int k = 0; k < 5; k++)
    {
        grille[k] = malloc(5 * sizeof(int));
        if (grille[k] == NULL)
        { // check malloc
            printf("Echec malloc.");
        }
    }

    for (int i = 0; i <= 4; i++)
    {
        grille[i][0] = 1;
        grille[i][4] = 2;
        for (int j = 1; j <= 3; j++)
        {
            grille[i][j] = 0;
        }
    }
    grille[3][3] = 3;

    return grille;
}

////////// DESTRUCTION  //////////

void destruction(int **grille)
{
    /*detruit la grille en libérant l'espace mémoire*/

    for (int k = 0; k < 5; k++)
    {
        free(grille[k]);
    }
    free(grille);
}
