#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "jeuIAvIA.h"
#include "deplacement.h"
#include "affichage.h"
#include "legit.h"
#include "initialisation.h"
#include "victoire.h"
#include "hasard.h"

void jeuIAvIA()
{
    jeu_t *jeu = initialisation();
    int tour = 0;
    int joueuractuel = 1;
    while (victoire(jeu) == 0) // tant qu'aucun joueur n'a gagné
    {
        ++tour;
        if (tour != 1) // au premier tour, on ne bouge pas le bobail
        {
            // coup ia
            afficher(jeu);
        }
        if (victoire(jeu) == 0)
        {
            // coup ia
            afficher(jeu);
        }

        joueuractuel = 1 + joueuractuel % 2;
    }
    afficher(jeu);
    printf("Le joueur %d a gagné en %d tours !\n\n\n", victoire(jeu), tour);
}
