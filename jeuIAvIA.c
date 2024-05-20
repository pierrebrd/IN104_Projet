#include "jeuIAvIA.h"

int jeuIAvIA_aleatoire()
{
    srand(time(NULL)); // initialisation du random
    jeu_t *jeu = initialisation();
    int tour = 0;
    int joueuractuel = 1;
    afficher(jeu);
    while (victoire(jeu, joueuractuel) == 0) // tant qu'aucun joueur n'a gagné
    {
        ++tour;

        coup_hasard(jeu, joueuractuel, tour); // l'IA jouer
        sleep(1);                             // on attend sinon ça affiche très vite !
        printf("IA %d, tour %d ↓\n", joueuractuel, tour);
        afficher(jeu); // on affiche la grille

        joueuractuel = 1 + joueuractuel % 2;
    }

    printf("L'IA %d a gagné en %d tours !\n\n\n", victoire(jeu, joueuractuel), tour);
    return (victoire(jeu, joueuractuel));
}

int jeuIAvIA()
{
    srand(time(NULL)); // initialisation du random
    jeu_t *jeu = initialisation();
    int tour = 0;
    int joueuractuel = 1;
    afficher(jeu);
    while (victoire(jeu, joueuractuel) == 0) // tant qu'aucun joueur n'a gagné
    {
        ++tour;

        int indice_coup = MCTS(jeu, joueuractuel, tour, 1000000); // l'IA joue choisit le meilleur coup
        // Il faut maintenant jouer le coup
        jouer_coup(jeu, joueuractuel, indice_coup);
        printf("IA %d, tour %d ↓\n", joueuractuel, tour);
        afficher(jeu); // on affiche la grille

        joueuractuel = 1 + joueuractuel % 2;
    }

    printf("L'IA %d a gagné en %d tours !\n\n\n", victoire(jeu, joueuractuel), tour);
    return (victoire(jeu, joueuractuel));
}

int jeuIAvIA_improved()
{
    srand(time(NULL)); // initialisation du random
    jeu_t *jeu = initialisation();
    int tour = 0;
    int joueuractuel = 1;

    afficher(jeu);
    while (victoire(jeu, joueuractuel) == 0) // tant qu'aucun joueur n'a gagné
    {
        if (tour > 100)
        {
            printf("La partie n'est pas finie au bout de 100 tours, on arrête la partie\n");
            return 0;
        }
        ++tour;
        int indice_coup = MCTS_improved(jeu, joueuractuel, tour, 10000); // l'IA joue choisit le meilleur coup
        //  Il faut maintenant jouer le coup
        jouer_coup(jeu, joueuractuel, indice_coup);
        printf("IA %d, tour %d ↓\n", joueuractuel, tour);
        afficher(jeu); // on affiche la grille

        joueuractuel = 1 + joueuractuel % 2;
    }

    printf("L'IA %d a gagné en %d tours !\n\n\n", victoire(jeu, joueuractuel), tour);
    return (victoire(jeu, joueuractuel));
}

int jeuIAvIA_comparaison(int joueurIAclassique)
{
    printf("L'IA classique est l'IA %d, l'IA améliorée avec récursivité est l'IA %d\n", joueurIAclassique, joueurIAclassique % 2 + 1);
    srand(time(NULL)); // initialisation du random
    jeu_t *jeu = initialisation();
    int tour = 0;
    int joueuractuel = 1;

    afficher(jeu);
    while (victoire(jeu, joueuractuel) == 0) // tant qu'aucun joueur n'a gagné
    {
        if (tour > 100)
        {
            printf("La partie n'est pas finie au bout de 100 tours, on arrête la partie\n");
            return 0;
        }
        ++tour;
        int indice_coup;
        if (joueuractuel == joueurIAclassique)
        {
            printf("IA classique ↓\n");
            indice_coup = MCTS(jeu, joueuractuel, tour, 1000000); // l'IA joue choisit le meilleur coup avec l'algorithme classique
        }
        else
        {
            printf("IA améliorée ↓\n");
            indice_coup = MCTS_improved(jeu, joueuractuel, tour, 10000); // l'IA joue choisit le meilleur coup avec l'algorithme récursif
        }
        //  Il faut maintenant jouer le coup
        jouer_coup(jeu, joueuractuel, indice_coup);
        printf("IA %d, tour %d ,coup %d↓\n", joueuractuel, tour, indice_coup);
        afficher(jeu); // on affiche la grille

        joueuractuel = 1 + joueuractuel % 2;
    }

    printf("L'IA %d a gagné en %d tours !\n\n\n", victoire(jeu, joueuractuel), tour);
    return (victoire(jeu, joueuractuel));
}