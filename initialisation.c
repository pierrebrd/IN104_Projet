#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"

jeu_t *initialisation()
{
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

    Initialise aussi le struct jeu_t et les listes des positions des pions, et le renvoie
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
    grille[2][2] = 3;

    int *x_pions = malloc(sizeof(int) * 11);
    int *y_pions = malloc(sizeof(int) * 11);
    for (int i = 0; i < 5; ++i)
    {
        x_pions[i] = i; // joueur 1
        y_pions[i] = 0;
        x_pions[i + 5] = i; // joueur 2
        y_pions[i + 5] = 4;
    }
    x_pions[10] = 2; // bobail
    y_pions[10] = 2;

    jeu_t *jeu = malloc(sizeof(jeu_t)); // on initialise le struct
    jeu->grille = grille;
    jeu->x_pions = x_pions;
    jeu->y_pions = y_pions;

    return jeu;
}

////////// DESTRUCTION  //////////

void destruction(jeu_t *jeu)
{
    /*detruit le struct en libérant l'espace mémoire*/

    for (int k = 0; k < 5; k++)
    {
        free(jeu->grille[k]);
    }
    free(jeu->grille);
    free(jeu->x_pions);
    free(jeu->y_pions);
    free(jeu);
}

////////// COPY STRUCT //////////
void copy_jeu (jeu_t* old_jeu, jeu_t* new_jeu) {
    for (int i = 0 ; i < 5 ; i++) {
        for (int j = 0 ; j < 5 ; j++) {
            new_jeu->grille[i][j] = old_jeu->grille[i][j] ;
        }
    }
    for (int i = 0 ; i < 11 ; i++) {
        new_jeu->x_pions[i] = old_jeu->x_pions[i] ;
        new_jeu->y_pions[i] = old_jeu->y_pions[i] ;
    }
}
