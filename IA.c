#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "initialisation.h"
#include "IA.h"

int explore_aleatoire(jeu_t *jeu_provisoire, int joueur, int tour)
{
    int joueur_provisoire = joueur;
    int tour_provisoire = tour;
    int erreur = 0; // si le jeu est bloqué, deviendra 404 404
    while (victoire(jeu_provisoire) == 0)
    {
        erreur = coup_hasard(jeu_provisoire, joueur_provisoire, tour_provisoire);
        if (erreur == 404)
        {
            // jeu bloqué, on s'arrete là et on renvoie 0 (aucun gagnant)
            return 0;
        }
        joueur_provisoire = joueur_provisoire % 2 + 1;
        tour_provisoire++;
    }
    return (victoire(jeu_provisoire));
}

int MCTS(jeu_t *jeu, int joueur, int tour)
{
    // On cherche la meilleure des actions possibles pour joueur
    // D'abord, on initialise deux listes : une qui compte le nombre de succès par pion et direction possible et par direction du bobail, et une qui compte le nombre de coups tentés dans cette direction.
    // Si la direction est bloquée, on utilise -1 dans la première liste
    int nb_succes[360] = {0}; // Indice d'un coup possible: 40*direction_bobail + 8*nb_pion%5 + direction_pion,
    int nb_total[360] = {0};
    jeu_t *jeu_provisoire = initialisation(); // va nous permetre de tester des coups sans modifier l'état initial du jeu

    // CETTE PARTIE EST OBSOLETE mais peut etre reutilisée si on améliore MCTS
    // // D'abord, on choisit une direction du bobail, un pion et une direction du pion. Si à ce tour le bobail ne bouge pas, les directions qui ne nous intéresse pas sont les 320 premières, et inversement
    // if (tour == 1)
    // {
    //     for (int i = 0; i < 320; i++)
    //     {
    //         nb_succes[i] = -1;
    //     }
    // }
    // else
    // {
    //     for (int i = 320; i < 360; i++)
    //     {
    //         nb_succes[i] = -1;
    //     }
    // }

    // ensuite, il faut faire des coups au hasard parmi les directions qui ne sont pas à -1. Il va falloir avoir un paramètre pour choisir si on veut vraiment + explorer les pistes avantageuses, et est ce que on se force d'abord a faire genre 10-100 itérations dans chaque direction pour être sur d'avoir à peu près exploré ??
    // en fait j'ai l'impression que c'est trop random, genre il peut y avoir un coup de merde auquel on gagne quand même car l'adversaire n'a pas joué ce qui pouvait le faire gagné direct

    // on explore 2000 fois chaque branche pour voir si "en moyenne", ce coup amène à perdre ou gagner
    // le nombre 2000 est arbitraire, grand pour que ca soit representatif mais pas trop grand pour limiter le temps d'execution
    for (int i = 0; i < 1000000; i++)
    {                                  // peut etre plutot explorer un certain nombre de fois chaque branche (2000 fois) ?
        copy_jeu(jeu, jeu_provisoire); // on retourne à l'état initial
        int joueur_provisoire = joueur;
        int indice_test = coup_hasard(jeu_provisoire, joueur_provisoire, tour); // on enregistre la position de notre test de départ, et on modifie jeu_provisoire. Pas besoin de vérifier si le coup est bloqué
        joueur_provisoire = joueur_provisoire % 2 + 1;
        int resultat = explore_aleatoire(jeu_provisoire, joueur_provisoire, tour + 1); // maitenant on jouer aléatoirement jusqua la victoire

        if (resultat == joueur)
        {
            nb_succes[indice_test]++; // On a gagné !
            nb_total[indice_test]++;
        }
        if (resultat == joueur % 2 + 1)
        {
            nb_total[indice_test]++;
        }
        // sinon, le résultat est 0, le jeu est bloqué, on ne fait rien
    }

    double ratio[360] = {0}; // on va calculer le ratio de succès pour chaque coup possible

    for (int i = 0; i < 360; i++)
    {
        if (nb_total[i] > 0)
        {
            // si on a exploré cette branche

            ratio[i] = (double)nb_succes[i] / nb_total[i];
            printf("indice %d nbr explore %d nbr succes %d ratio %f\n", i, nb_total[i], nb_succes[i], (float)nb_succes[i] / nb_total[i]);
        }
    }

    int ind_max = 0;
    double max = 0;
    for (int i = 0; i < 360; i++)
    {
        if (ratio[i] > max)
        {
            max = ratio[i];
            ind_max = i;
        }
    }
    printf("Meilleur coup : %d\n", ind_max);
    return ind_max;
}

// par construction, un move gagnant du bobail ou d'un pion devrai avoir autant de succes que d'itérations donc sera choisi !!