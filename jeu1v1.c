#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "jeu1v1.h"
#include "deplacement.h"
#include "affichage.h"
#include "legit.h"

void jeu1v1()
{
    prinf("Le joueur 1 a les pions rouge, le joueur 2 a les pions verts, le  bobail est violet. Le joueur 1 commence\n");
    int **grille = initialisation();

    int joueuractuel = 1;
    while (victoire(grille, joueuractuel) == 0)
    {
        afficher(grille);
    }
}