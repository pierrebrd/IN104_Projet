#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> //pour utiliser sleep
#include <time.h>   //pour initialiser le random

#include "jeu1vIA.h"
#include "deplacement.h"
#include "affichage.h"
#include "legit.h"
#include "initialisation.h"
#include "victoire.h"
#include "hasard.h"
#include "UX.h"

void jeu1vIA_aleatoire()
{
    srand(time(NULL)); // initialisation du random
    // Demander au joueur s'il est joueur 1 ou joueur 2
    int joueurHumain;
    printf("Le joueur 1 jouera en premier. Voulez vous être le joueur : 1 ou 2 ? : ");
    scanf("%d", &joueurHumain);
    printf("\n");
    regles();

    // // expliquer l'affichage
    // if (joueurHumain == 1)
    // {
    //     printf("Vous avez les pions rouges, l'IA a les pions verts. Le bobail est en violet\n");
    // }
    // else
    // {
    //     printf("Vous avez les pions verts, l'IA a les pions rouges. Le bobail est en violet\n");
    // }

    jeu_t *jeu = initialisation();
    int tour = 0;
    int joueuractuel = 1;
    afficher(jeu);
    while (victoire(jeu, joueuractuel) == 0) // tant qu'aucun joueur n'a gagné
    {
        ++tour;

        if (joueurHumain == joueuractuel)
        { // L'humain joue
            if (tour != 1)
            { // au premier tour, on ne bouge pas le bobail
                printf("Humain, à vous de jouer ! Bougez le Bobail.\n");
                coup(jeu, 3);
                afficher(jeu);
            }
            if (victoire(jeu, joueuractuel) == 0)
            { // on bouge un pion sauf si la partie est déjà gagnée
                printf("Humain, bougez un de vos pions.\n");
                coup(jeu, joueuractuel);
                afficher(jeu);
            }
        }
        else
        {
            // COUP DE L'IA
            printf("\n\n\n");
            coup_hasard(jeu, joueuractuel, tour);
            sleep(1);
            printf("Coup de l'IA ↓\n");
            afficher(jeu);
        }

        joueuractuel = 1 + joueuractuel % 2;
    }
    printf("Le joueur %d a gagné en %d tours !\n\n\n", victoire(jeu, joueuractuel), tour);
}

void jeu1vIA()
{
    srand(time(NULL)); // initialisation du random
    // Demander au joueur s'il est joueur 1 ou joueur 2
    int joueurHumain;
    printf("Le joueur 1 jouera en premier. Voulez vous être le joueur : 1 ou 2 ? : ");
    scanf("%d", &joueurHumain);
    printf("\n");
    regles();

    // // expliquer l'affichage
    // if (joueurHumain == 1)
    // {
    //     printf("Vous avez les pions rouges, l'IA a les pions verts. Le bobail est en violet\n");
    // }
    // else
    // {
    //     printf("Vous avez les pions verts, l'IA a les pions rouges. Le bobail est en violet\n");
    // }

    jeu_t *jeu = initialisation();
    int tour = 0;
    int joueuractuel = 1;
    afficher(jeu);
    while (victoire(jeu, joueuractuel) == 0) // tant qu'aucun joueur n'a gagné
    {
        ++tour;

        if (joueurHumain == joueuractuel)
        { // L'humain joue
            if (tour != 1)
            { // au premier tour, on ne bouge pas le bobail
                printf("Humain, à vous de jouer ! Bougez le Bobail.\n");
                coup(jeu, 3);
                afficher(jeu);
            }
            if (victoire(jeu, joueuractuel) == 0)
            { // on bouge un pion sauf si la partie est déjà gagnée
                printf("Humain, bougez un de vos pions.\n");
                coup(jeu, joueuractuel);
                afficher(jeu);
            }
        }
        else
        {
            // COUP DE L'IA
            printf("\n\n\n");
            int indice_coup = MCTS(jeu, joueuractuel, tour, 1000000);
            jouer_coup(jeu, joueuractuel, indice_coup);
            printf("Coup de l'IA ↓\n");
            afficher(jeu);
        }

        joueuractuel = 1 + joueuractuel % 2;
    }
    printf("Le joueur %d a gagné en %d tours !\n\n\n", victoire(jeu, joueuractuel), tour);
}

void jeu1vIA_improved()
{
    srand(time(NULL)); // initialisation du random
    // Demander au joueur s'il est joueur 1 ou joueur 2
    int joueurHumain;
    printf("Le joueur 1 jouera en premier. Voulez vous être le joueur : 1 ou 2 ? : ");
    scanf("%d", &joueurHumain);
    printf("\n");
    regles();

    // // expliquer l'affichage
    // if (joueurHumain == 1)
    // {
    //     printf("Vous avez les pions rouges, l'IA a les pions verts. Le bobail est en violet\n");
    // }
    // else
    // {
    //     printf("Vous avez les pions verts, l'IA a les pions rouges. Le bobail est en violet\n");
    // }

    jeu_t *jeu = initialisation();
    int tour = 0;
    int joueuractuel = 1;
    afficher(jeu);
    while (victoire(jeu, joueuractuel) == 0) // tant qu'aucun joueur n'a gagné
    {
        ++tour;

        if (joueurHumain == joueuractuel)
        { // L'humain joue
            if (tour != 1)
            { // au premier tour, on ne bouge pas le bobail
                printf("Humain, à vous de jouer ! Bougez le Bobail.\n");
                coup(jeu, 3);
                afficher(jeu);
            }
            if (victoire(jeu, joueuractuel) == 0)
            { // on bouge un pion sauf si la partie est déjà gagnée
                printf("Humain, bougez un de vos pions.\n");
                coup(jeu, joueuractuel);
                afficher(jeu);
            }
        }
        else
        {
            // COUP DE L'IA
            printf("\n\n\n");
            int indice_coup = MCTS_improved(jeu, joueuractuel, tour);
            jouer_coup(jeu, joueuractuel, indice_coup);
            printf("Coup de l'IA ↓\n");
            afficher(jeu);
        }

        joueuractuel = 1 + joueuractuel % 2;
    }
    printf("Le joueur %d a gagné en %d tours !\n\n\n", victoire(jeu, joueuractuel), tour);
}
