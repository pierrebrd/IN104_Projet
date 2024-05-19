#include "victoire.h"

int victoire(jeu_t *jeu, int joueur)
{
    // printf("victoireIN\n");
    //  emplacement bobail
    int x = jeu->x_pions[10];
    int y = jeu->y_pions[10];

    // Cas ou le bobail est dans la 1er ou la denriere colonne
    if (y == 0)
    {
        return 1;
    }
    if (y == 4)
    {
        return 2;
    }

    // Cas ou le bobail ne peut pas bouger
    int voisins_occupes = 0;
    if (y + 1 > 4 || legit(jeu, x, y, x, y + 1, 3) != 0)
    {
        voisins_occupes++;
    }
    if (y - 1 < 0 || legit(jeu, x, y, x, y - 1, 3) != 0)
    {
        voisins_occupes++;
    }
    if (x + 1 > 4 || y + 1 > 4 || legit(jeu, x, y, x + 1, y + 1, 3) != 0)
    {
        voisins_occupes++;
    }
    if (x + 1 > 4 || legit(jeu, x, y, x + 1, y, 3) != 0)
    {
        voisins_occupes++;
    }
    if (x + 1 > 4 || y - 1 < 0 || legit(jeu, x, y, x + 1, y - 1, 3) != 0)
    {
        voisins_occupes++;
    }
    if (x - 1 < 0 || y + 1 > 4 || legit(jeu, x, y, x - 1, y + 1, 3) != 0)
    {
        voisins_occupes++;
    }
    if (x - 1 < 0 || legit(jeu, x, y, x - 1, y, 3) != 0)
    {
        voisins_occupes++;
    }
    if (x - 1 < 0 || y - 1 < 0 || legit(jeu, x, y, x - 1, y - 1, 3) != 0)
    {
        voisins_occupes++;
    }

    if (voisins_occupes == 8)
    {
        // joueur qui va jouer a perdu
        return (1 + joueur % 2); // c'est donc l'autre joueur qui a gagné
    }

    // cas ou personne a gagné
    return 0;
}
