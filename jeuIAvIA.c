#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> //pour utiliser sleep

#include "jeuIAvIA.h"
#include "deplacement.h"
#include "affichage.h"
#include "legit.h"
#include "initialisation.h"
#include "victoire.h"
#include "hasard.h"

void jeuIAvIA_aleatoire()
{
    jeu_t *jeu = initialisation();
    int tour = 0;
    int joueuractuel = 1;
    afficher(jeu);
    while (victoire(jeu) == 0) // tant qu'aucun joueur n'a gagné
    {
        ++tour;

        coup_hasard(jeu, joueuractuel, tour); // l'IA jouer
        sleep(1);                             // on attend sinon ça affiche très vite !
        printf("IA %d, tour %d ↓\n", joueuractuel, tour);
        afficher(jeu); // on affiche la grille

        joueuractuel = 1 + joueuractuel % 2;
    }

    printf("L'IA %d a gagné en %d tours !\n\n\n", victoire(jeu), tour);
}
