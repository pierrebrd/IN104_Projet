#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "hasard.h"
#include "legit.h"
#include "victoire.h"
#include "initialisation.h"

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

void coup_hasard(jeu_t *jeu, int joueur, int tour)
{
    srand(time(NULL));
    if (tour != 1)
    { // on doit bouger le bobail aléatoirement
        // emplacement bobail
        int x = jeu->x_pions[10];
        int y = jeu->y_pions[10];

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
        } while (legit(jeu, x, y, x + ii, y + jj, 3) != 0);
        jeu->grille[x][y] = 0;
        jeu->grille[x + ii][y + jj] = 3;
        jeu->x_pions[10] = x + ii;
        jeu->y_pions[10] = y + jj;
    }

    // maintenant, on bouge un pion si l'on n'a pas encore gagné
    if (victoire(jeu) == 0)
    {
    }
}

// maybe implémenter le fait que bouger aléatoirement c'est bête ? genre on essate toujours de à peu près déplacer le bobail vers notre coté et pas vers l'adversaire ?

// on reprend beaucoup d'éléments de legit.c, peut etre dans legit.c directement faire une fonction qui prend en argument une direction plutot qu'une position et renvoie si c'est okay