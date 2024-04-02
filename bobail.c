#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

enum DIRECTION = {NORD, NORD - EST, EST, SUD - EST, SUD, SUD - OUEST, OUEST, NORD - OUEST};

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
    grille[2][2] = 3;

    return grille;
}

void destruction(int **grille)
{
    /*detruit la grille en libérant l'espace mémoire*/

    for (int k = 0; k < 5; k++)
    {
        free(grille[k]);
    }
    free(grille);
}

void affichercase(int i, int j, int **grille)
{
    if (grille[i][j] == 1)
    {
        printf("\033[0;31m");
        printf("⭕ ");
        printf("\033[0m");
    }
    else if (grille[i][j] == 2)
    {
        printf("\033[0;32m");
        printf("\033[1m");
        printf("◯ ");
        printf("\033[0m");
    }
    else if (grille[i][j] == 3)
    {
        printf("\033[0;35m");
        printf("➊ ");
        printf("\033[0m");
    }
    else
    {
        printf("  ");
    }
}

void afficher(int **grille)
{
    printf("\n    1   2   3   4   5\n  ┏━━━┳━━━┳━━━┳━━━┳━━━┓\nA ");
    for (int j = 0; j < 5; ++j)
    {
        printf("┃ ");
        affichercase(0, j, grille);
        printf("\033[0m");
    }
    printf("┃\n  ┣━━━╋━━━╋━━━╋━━━╋━━━┫\nB ");
    for (int j = 0; j < 5; ++j)
    {
        printf("┃ ");
        affichercase(1, j, grille);
        printf("\033[0m");
    }
    printf("┃\n  ┣━━━╋━━━╋━━━╋━━━╋━━━┫\nC ");
    for (int j = 0; j < 5; ++j)
    {
        printf("┃ ");
        affichercase(2, j, grille);
        printf("\033[0m");
    }
    printf("┃\n  ┣━━━╋━━━╋━━━╋━━━╋━━━┫\nD ");
    for (int j = 0; j < 5; ++j)
    {
        printf("┃ ");
        affichercase(3, j, grille);
        printf("\033[0m");
    }
    printf("┃\n  ┣━━━╋━━━╋━━━╋━━━╋━━━┫\nE ");
    for (int j = 0; j < 5; ++j)
    {
        printf("┃ ");
        affichercase(4, j, grille);
        printf("\033[0m");
    }
    printf("┃\n  ┗━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}

int main()
{
    int **grille = initialisation();
    afficher(grille);
    return 0;
}

void coup()
{
    /* Demande le coup, vérifie qu'il est légal, et met à jour la grille*/

    // Demande au joueur

    printf("Emplacement du pion à déplacer (LettreChiffre sans espace): ");
    char *depart;
    scanf("%s", depart);

    printf("Direction (Nord, Nord-Ouest...): ");
    char *dir_string;
    scanf("%s", dir_string);

    // Vérifie que l'entrée est correcte, convertir dir_string en enum
    // A FAIRE, ca va etre un gros morceau :(

    // Voir si on peut se déplacer dans cette direction

    // déplacer dans cette direction
    // on peut définit suivant=i+1,j dans la dir sud, i-1,j+1 dans le dir nord-est...
}
