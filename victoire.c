#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"
#include "deplacement.h"
#include "legit.h"

int victoire(jeu_t *jeu, int joueur)
{
    // emplacement bobail
    int x = jeu->x_pions[10];
    int y = jeu->y_pions[10];

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
    if (y + 1 > 4 || legit(jeu, x, y, x, y + 1, 3) != 0)
    {
        voisins_occupés++;
    }
    if (y - 1 < 0 || legit(jeu, x, y, x, y - 1, 3) != 0)
    {
        voisins_occupés++;
    }
    if (x + 1 > 4 || y + 1 > 4 || legit(jeu, x, y, x + 1, y + 1, 3) != 0)
    {
        voisins_occupés++;
    }
    if (x + 1 > 4 || legit(jeu, x, y, x + 1, y, 3) != 0)
    {
        voisins_occupés++;
    }
    if (x + 1 > 4 || y - 1 < 0 || legit(jeu, x, y, x + 1, y - 1, 3) != 0)
    {
        voisins_occupés++;
    }
    if (x - 1 < 0 || y + 1 > 4 || legit(jeu, x, y, x - 1, y + 1, 3) != 0)
    {
        voisins_occupés++;
    }
    if (x - 1 < 0 || legit(jeu, x, y, x - 1, y, 3) != 0)
    {
        voisins_occupés++;
    }
    if (x - 1 < 0 || y - 1 < 0 || legit(jeu, x, y, x - 1, y - 1, 3) != 0)
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
