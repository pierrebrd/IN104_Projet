#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"
#include "deplacement.h"
#include "legit.h"
#include "hasard.h"
#include "victoire.h"
#include "IA.h"
#include "jeuIAvIA.h"
#include "jeu1v1.h"
#include "jeu1vIA.h"
#include "UX.h"

int main()
{
    printf("\nBienvenue dans le jeu de Bobail !\n\nLe Bobail se joue à deux joeurs. Choisissez votre mode de jeu.\nDeux joueurs : 1\nUn joueur contre une IA: 2\nDeux IA : 3\nVotre choix : ");
    int mode_jeu = 0;
    scanf("%d", &mode_jeu);
    printf("\n");
    switch (mode_jeu)
    {
    case 1: // 1v1
        jeu1v1();
        break;
    case 2: // 1vIA, on chosisit le niveau de difficulté
        // à compléter
        break;
    case 3: // IA contre IA
        printf("Choisissez le niveau de difficulté de l'IA :\n0: l'IA joue complétement alétoirement\n1 : L'IA utilise un algorithme MCTS classique pour trouver le meilleur coup\n2 et + : L'IA utilise MCTS avec récursivité pour jouer plus intelligement\nVotre choix : ");
        int anticipation = 0;
        scanf("%d", &anticipation);
        printf("\n");
        switch (anticipation)
        {
        case 0: // aléatoire
            jeuIAvIA_aleatoire();
            break;
        case 1: // MCTS classique
            jeuIAvIA();
            break;

        default: // MCTS amélioré avec choix du degré d'anticipation
            jeuIAvIA_improved(anticipation);
            break;
        }
        break;
    default:
        printf("Mode de jeu inconnu\n");
        break;
    }
    return 0;
}
