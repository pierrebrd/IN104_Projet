#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"

void affichercase(int i, int j, jeu_t *jeu)
{
    if (jeu->grille[i][j] == 1)
    {
        printf("\033[0;91m");
        printf("● ");
        printf("\033[0m");
    }
    else if (jeu->grille[i][j] == 2)
    {
        printf("\033[0;92m");
        printf("● ");
        printf("\033[0m");
    }
    else if (jeu->grille[i][j] == 3)
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

void afficher(jeu_t *jeu)
{
    printf("\n          1   2   3   4   5\n        ┏━━━┯━━━┯━━━┯━━━┯━━━┓\n      A ┃ ");
    for (int j = 0; j < 5; ++j)
    {
        affichercase(0, j, jeu);
        printf("│ ");
    }
    printf("\b\b┃ \n        ┠───┼───┼───┼───┼───┨\n      B ┃ ");
    for (int j = 0; j < 5; ++j)
    {
        affichercase(1, j, jeu);
        printf("│ ");
    }
    printf("\b\b┃ \n        ┠───┼───┼───┼───┼───┨\n      C ┃ ");
    for (int j = 0; j < 5; ++j)
    {
        affichercase(2, j, jeu);
        printf("│ ");
    }
    printf("\b\b┃ \n        ┠───┼───┼───┼───┼───┨\n      D ┃ ");
    for (int j = 0; j < 5; ++j)
    {
        affichercase(3, j, jeu);
        printf("│ ");
    }
    printf("\b\b┃ \n        ┠───┼───┼───┼───┼───┨\n      E ┃ ");
    for (int j = 0; j < 5; ++j)
    {
        affichercase(4, j, jeu);
        printf("│ ");
    }
    printf("\b\b┃ \n        ┗━━━┷━━━┷━━━┷━━━┷━━━┛\n\n");
}