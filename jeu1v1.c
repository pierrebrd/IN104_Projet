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
    jeu_t *jeu = initialisation();
    int tour = 0;
    int joueuractuel = 1;
    while (victoire(jeu) == 0) // tant qu'aucun joueur n'a gagné
    {
        ++tour;
        if (tour != 1) // au premier tour, on ne bouge pas le bobail
        {
            afficher(jeu);
            printf("Joueur %d, à vous de jouer ! Bougez le Bobail.\n", joueuractuel);
            coup(jeu, 3);
        }
        if (victoire(jeu) == 0)
        {
            afficher(jeu);
            printf("Joueur %d, bougez un de vos pions.\n", joueuractuel);
            coup(jeu, joueuractuel);
        }

        joueuractuel = 1 + joueuractuel % 2;
    }
    afficher(jeu);
    printf("Le joueur %d a gagné en %d tours !\n\n\n", victoire(jeu), tour);
}
