#include "IA.h"

int explore_aleatoire(jeu_t *jeu_provisoire, int joueur, int tour)
{
    int joueur_provisoire = joueur;
    int tour_provisoire = tour;
    int erreur = 0; // si le jeu est bloqué, deviendra 404
    while (victoire(jeu_provisoire, joueur_provisoire) == 0)
    {
        erreur = coup_hasard(jeu_provisoire, joueur_provisoire, tour_provisoire);
        if (erreur == 404)
        {
            // jeu bloqué, on s'arrete là et on renvoie 0 (aucun gagnant)
            return 0;
        }
        joueur_provisoire = joueur_provisoire % 2 + 1;
        tour_provisoire++;
        // afficher(jeu_provisoire);
    }
    return (victoire(jeu_provisoire, joueur_provisoire));
}

int MCTS(jeu_t *jeu, int joueur, int tour, int nbr_simulations)
{
    if (victoire(jeu, joueur) != 0)
    {
        // printf("jeu gagné\n");
        return 404; // le jeu est déja gagné, on renvoie une erreur
    }
    // On cherche la meilleure des actions possibles pour joueur
    // D'abord, on initialise deux listes : une qui compte le nombre de succès par pion et direction possible et par direction du bobail, et une qui compte le nombre de coups tentés dans cette direction.
    // Si la direction est bloquée, on utilise -1 dans la première liste
    int nb_succes[360] = {0}; // Indice d'un coup possible: 40*direction_bobail + 8*nb_pion%5 + direction_pion,
    int nb_total[360] = {0};
    jeu_t *jeu_provisoire = initialisation(); // va nous permetre de tester des coups sans modifier l'état initial du jeu

    // on explore 1000000 fois chaque branche pour voir si "en moyenne", ce coup amène à perdre ou gagner
    // le nombre 1000000 est arbitraire, grand pour que ca soit representatif mais pas trop grand pour limiter le temps d'execution
    for (int i = 0; i < nbr_simulations; i++)
    {                                  // peut etre plutot explorer un certain nombre de fois chaque branche (2000 fois) ?
        copy_jeu(jeu, jeu_provisoire); // on retourne à l'état initial
        int joueur_provisoire = joueur;
        int indice_test = coup_hasard(jeu_provisoire, joueur_provisoire, tour); // on enregistre la position de notre test de départ, et on modifie jeu_provisoire. Pas besoin de vérifier si le coup est bloqué
        joueur_provisoire = joueur_provisoire % 2 + 1;
        int resultat = explore_aleatoire(jeu_provisoire, joueur_provisoire, tour + 1); // 0 si bloqué, 1 si J1 gagne, 2 si J2 gagne
        // maitenant on jouer aléatoirement jusqua la victoire

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
            // printf("indice %d nbr explore %d nbr succes %d ratio %f\n", i, nb_total[i], nb_succes[i], (float)nb_succes[i] / nb_total[i]); // ligne dev, à supprimer dans la version utilisateur
        }
    }

    int ind_max = -1;
    double max = -1;
    for (int i = 0; i < 360; i++)
    {
        if (ratio[i] >= max)
        {
            max = ratio[i];
            ind_max = i;
        }
    }
    // printf("Meilleur coup joueur %d : %d\n", joueur, ind_max); // ligne dev, à supprimer dans la version utilisateur
    destruction(jeu_provisoire);
    return ind_max;
}

int MCTS_improved(jeu_t *jeu, int joueur, int tour, int nb_explorations)
{

    int nb_succes[360] = {0}; // Indice d'un coup possible: 40*direction_bobail + 8*nb_pion%5 + direction_pion,
    jeu_t *jeu_provisoire = initialisation();
    double ratio[360] = {0};
    for (int indice_coup = 0; indice_coup < 360; indice_coup++)
    {
        if (legit_direction(jeu, indice_coup, joueur, tour) == 0)
        { // si le coup est légal

            copy_jeu(jeu, jeu_provisoire);
            jouer_coup(jeu_provisoire, joueur, indice_coup);
            // printf("On cherche le coup de l'adversaire\n");
            int coup_adversaire = MCTS(jeu_provisoire, joueur % 2 + 1, tour + 1, 10 * nb_explorations); // le 10*nb_explorations est arbitraire
            if (coup_adversaire != 404)
            {
                // indice_coup n'est pas gagnant, donc l'adversaire joue et on cherche le meilleur coup ensuite
                jouer_coup(jeu_provisoire, joueur % 2 + 1, coup_adversaire); // l'adversaire joue
                jeu_t *jeu_provisoire2 = initialisation();
                for (int i = 0; i < nb_explorations; i++)
                {
                    copy_jeu(jeu_provisoire, jeu_provisoire2);
                    int gagnant = explore_aleatoire(jeu_provisoire2, joueur, tour + 2);

                    if (gagnant == joueur)
                    {
                        nb_succes[indice_coup]++; // On a gagné !
                    }
                }

                ratio[indice_coup] = (double)nb_succes[indice_coup] / nb_explorations;
            }
            else if (coup_adversaire == 404)
            {
                // indice_coup est pour l'un des deux joueurs ! on vérifie si c'est gagnant nous ou l'adversaire, et on met a jour le ratio
                if (victoire(jeu_provisoire, joueur % 2 + 1) == joueur)
                {
                    ratio[indice_coup] = 1;
                }
                else if (victoire(jeu_provisoire, joueur % 2 + 1) == joueur % 2 + 1)
                {
                    ratio[indice_coup] = 0;
                }
            }
        }

        else
        {
            ratio[indice_coup] = -1; // le coup est illégal ! On mets -1 car si on met 0, on risque de le choisir par erreur si tous les coups légaux sont perdants donc auront un ratio de 0 également
        }
    }
    // On chosit le coup avec le meilleur ratio
    int ind_max = -1;
    double max = -1;
    for (int i = 0; i < 360; i++)
    {
        // printf("ratio coup %d : %f\n", i, ratio[i]);
        if (ratio[i] >= max)
        {
            max = ratio[i];
            ind_max = i;
        }
    }
    // printf("Meilleur coup : %d\n", ind_max); // ligne dev, à supprimer dans la version utilisateur
    return ind_max;
}
