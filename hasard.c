#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "hasard.h"
#include "legit.h"
#include "victoire.h"

typedef enum
{
    RIEN,
    NORD,
    SUD,
    OUEST,
    EST,
    NORDOUEST,
    NORDEST,
    SUDOUEST,
    SUDEST
} direction_t;

void coup_hasard(int **grille, int joueur, int tour)
{
    srand(time(NULL));
    if (tour != 1)
    { // on doit bouger le bobail aléatoirement
        // emplacement bobail
        int x;
        int y;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                // si la case contient le bobail (encodé par un 3)
                if (grille[i][j] == 3)
                {
                    x = i;
                    y = j;
                }
            }
        }

        // choix d'une direction
        int direction;
        int ii;
        int jj;
        do
        { // on cherche une direction
            direction = rand() % 9;
            ii = 0;
            jj = 0;
            switch (direction)
            {
            case SUD:
                ii++;
                break;
            case NORD:
                ii--;
                break;
            case EST:
                jj++;
                break;
            case OUEST:
                jj--;
                break;
            case NORDOUEST:
                ii--;
                jj--;
                break;
            case NORDEST:
                ii--;
                jj++;
                break;
            case SUDEST:
                ii++;
                jj++;
                break;
            case SUDOUEST:
                ii++;
                jj--;
                break;
            case RIEN:
                break;
            }
        } while (legit(grille, x, y, x + ii, y + jj, 3) != 0);
        grille[x][y] = 0;
        grille[x + ii][y + jj] = 3;
    }

    // maintenant, on bouge un pion si l'on n'a pas encore gagné
    if (victoire(grille) == 0)
    {
    }
}

// maybe implémenter le fait que bouger aléatoirement c'est bête ? genre on essate toujours de à peu près déplacer le bobail vers notre coté et pas vers l'adversaire ?

// on reprend beaucoup d'éléments de legit.c, peut etre dans legit.c directement faire une fonction qui prend en argument une direction plutot qu'une position et renvoie si c'est okay