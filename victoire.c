#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"
#include "deplacement.h"
#include "legit.h"

int victoire(int **grille, int joueur)
{
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

    // Cas ou le bobail est dans la 1er ou la denriere colonne
    if (y == 0)
    {
        return 1;
    }
    else if (y == 4)
    {
        return 2;
    }

    // Cas ou le bobail ne peut pas bouger
    int voisins_occupés = 0;
    if (legit(grille, x, y, x, y + 1, 3) != 0)
    {
        voisins_occupés++;
    }
    if (legit(grille, x, y, x, y, 3) != 0)
    {
        voisins_occupés++;
    }
    if (legit(grille, x, y, x, y - 1, 3) != 0)
    {
        voisins_occupés++;
    }
    if (legit(grille, x, y, x - 1, y + 1, 3) != 0)
    {
        voisins_occupés++;
    }
    if (legit(grille, x, y, x - 1, y, 3) != 0)
    {
        voisins_occupés++;
    }
    if (legit(grille, x, y, x - 1, y - 1, 3) != 0)
    {
        voisins_occupés++;
    }
    if (legit(grille, x, y, x + 1, y + 1, 3) != 0)
    {
        voisins_occupés++;
    }
    if (legit(grille, x, y, x + 1, y, 3) != 0)
    {
        voisins_occupés++;
    }
    if (legit(grille, x, y, x - 1, y - 1, 3) != 0)
    {
        voisins_occupés++;
    }

    if (voisins_occupés == 8)
    {
        // joueur qui va jouer a perdu
        return (1 + joueur % 2);
    }

    // cas ou personne a gagné
    return 0;
}
