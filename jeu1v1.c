#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "jeu1v1.h"
#include "deplacement.h"
#include "affichage.h"
#include "legit.h"
#include "initialisation.h"
#include "victoire.h"

void jeu1v1()
{
    printf("Le joueur 1 a les pions rouge, le joueur 2 a les pions verts, le  bobail est violet. Le joueur 1 commence\n");
    int **grille = initialisation();
    int tour = 0;
    int joueuractuel = 1;
    while (victoire(grille) == 0) // tant qu'aucun joueur n'a gagné
    {
        ++tour;
        if (tour != 1) // au premier tour, on ne bouge pas le bobail
        {
            afficher(grille);
            printf("Joueur %d, à vous de jouer ! Bougez le Bobail.\n", joueuractuel);
            coup(grille, 3);
        }
        if (victoire(grille) == 0)
        {
            afficher(grille);
            printf("Joueur %d, bougez un de vos pions.\n", joueuractuel);
            coup(grille, joueuractuel);
        }

        joueuractuel = 1 + joueuractuel % 2;
    }
    afficher(grille);
    printf("Le joueur %d a gagné en %d tours !\n\n\n", victoire(grille), tour);
}
