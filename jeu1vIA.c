#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "jeu1vIA.h"
#include "deplacement.h"
#include "affichage.h"
#include "legit.h"
#include "initialisation.h"
#include "victoire.h"
#include "hasard.h"

void jeu1vIA()
{
    // Demander au joueur s'il est joueur 1 ou joueur 2
    int joueurHumain;
    int joueurIA;
    printf("Voulez vous être le joueur : 1 ou 2 ? : ");
    scanf("%d", &joueurHumain);
    printf("\n");
    joueurIA = joueurHumain % 2 + 1;

    // expliquer l'affichage
    if (joueurHumain == 1)
    {
        printf("Vous avez les pions rouges, l'IA a les pions verts. Le bobail est en violet\n");
    }
    else
    {
        printf("Vous avez les pions verts, l'IA a les pions rouges. Le bobail est en violet\n");
    }

    jeu_t *jeu = initialisation();
    int tour = 0;
    int joueuractuel = 1;
    while (victoire(jeu) == 0) // tant qu'aucun joueur n'a gagné
    {
        ++tour;
        if (tour != 1) // au premier tour, on ne bouge pas le bobail
        {
            if (joueurHumain == joueuractuel)
            {
                afficher(jeu);
                printf("A vous de jouer ! Bougez le Bobail.\n", joueuractuel);
                coup(jeu, 3);
            }
            else
            {
                // COUP DE L'IA
                afficher(jeu);
            }
        }
        if (victoire(jeu) == 0)
        {
            if (joueurHumain == joueuractuel)
            {
                afficher(jeu);
                printf("Bougez un de vos pions.\n", joueuractuel);
                coup(jeu, joueuractuel);
            }
            else
            {
                // COUP DE L'IA
                afficher(jeu);
            }
        }

        joueuractuel = 1 + joueuractuel % 2;
    }
    afficher(jeu);
    printf("Le joueur %d a gagné en %d tours !\n\n\n", victoire(jeu), tour);
}
