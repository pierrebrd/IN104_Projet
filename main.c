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
    printf("\nBienvenue dans le jeu de Bobail !\n\nLe Bobail se joue à deux joeurs. Choisissez votre mode de jeu.\n1 : Deux joueurs\n2 : Un joueur contre une IA\n3 : Deux IAs\nVotre choix : ");
    int mode_jeu = 0;
    int anticipation = 0;
    scanf("%d", &mode_jeu);
    printf("\n");
    switch (mode_jeu)
    {
    case 1: // 1v1
        jeu1v1();
        break;
    case 2: // 1vIA, on chosisit le niveau de difficulté
        printf("Choisissez le niveau de difficulté de l'IA :\n1 : l'IA joue complétement alétoirement\n2 : L'IA utilise un algorithme MCTS classique pour trouver le meilleur coup\n3 : L'IA utilise MCTS avec récursivité pour jouer plus intelligement\nVotre choix : ");
        int anticipation = 0;
        // Pour l'instant, l'anticipation est au maximum de 2
        scanf("%d", &anticipation);
        printf("\n");
        switch (anticipation)
        {
        case 1: // aléatoire
            jeu1vIA_aleatoire();
            break;
        case 2: // MCTS classique
            jeu1vIA();
            break;
        case 3: // MCTS amélioré
            jeu1vIA_improved();
            break;

        default:
            // jeuIAvIA_improved(anticipation);
            break;
        }
        break;
    case 3: // IA contre IA
        printf("Choisissez le niveau de difficulté de l'IA :\n1: l'IA joue complétement alétoirement\n2 : L'IA utilise un algorithme MCTS classique pour trouver le meilleur coup\n3 : L'IA utilise MCTS avec récursivité pour jouer plus intelligement\nVotre choix : ");
        // Pour l'instant, l'anticipation est au maximum de 2
        scanf("%d", &anticipation);
        printf("\n");
        switch (anticipation)
        {
        case 1: // aléatoire
            jeuIAvIA_aleatoire();
            break;
        case 2: // MCTS classique
            jeuIAvIA();
            break;
        case 3: // MCTS amélioré
            jeuIAvIA_improved();
            break;

        default:
            // jeuIAvIA_improved(anticipation);
            break;
        }
        break;
    default:
        printf("Mode de jeu inconnu\n");
        break;
    }
    return 0;
}
