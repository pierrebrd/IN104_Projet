#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"

void affichercase(int i, int j, int **grille)
{
    if (grille[i][j] == 1)
    {
        printf("\033[0;91m");
        printf("● ");
        printf("\033[0m");
    }
    else if (grille[i][j] == 2)
    {
        printf("\033[0;92m");
        printf("● ");
        printf("\033[0m");
    }
    else if (grille[i][j] == 3)
    {
        printf("\033[0;95m");
        printf("● ");
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
    }
    printf("┃\n  ┣━━━╋━━━╋━━━╋━━━╋━━━┫\nB ");
    for (int j = 0; j < 5; ++j)
    {
        printf("┃ ");
        affichercase(1, j, grille);
    }
    printf("┃\n  ┣━━━╋━━━╋━━━╋━━━╋━━━┫\nC ");
    for (int j = 0; j < 5; ++j)
    {
        printf("┃ ");
        affichercase(2, j, grille);
    }
    printf("┃\n  ┣━━━╋━━━╋━━━╋━━━╋━━━┫\nD ");
    for (int j = 0; j < 5; ++j)
    {
        printf("┃ ");
        affichercase(3, j, grille);
    }
    printf("┃\n  ┣━━━╋━━━╋━━━╋━━━╋━━━┫\nE ");
    for (int j = 0; j < 5; ++j)
    {
        printf("┃ ");
        affichercase(4, j, grille);
    }
    printf("┃\n  ┗━━━┻━━━┻━━━┻━━━┻━━━┛\n");
}