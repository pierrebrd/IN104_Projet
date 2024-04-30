#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "hasard.h"
#include "legit.h"
#include "victoire.h"
#include "initialisation.h"

typedef enum
{
    RIEN,
    NORD,
    SUD,
    OUEST,
    EST,
    NORDOUEST,
    NORDEST,
    SUDOUEST,
    SUDEST
} direction_t;

void coup_hasard(jeu_t *jeu, int joueur, int tour)
{
    srand(time(NULL));
    if (tour != 1)
    { // on doit bouger le bobail aléatoirement
        // emplacement bobail
        int x = jeu->x_pions[10];
        int y = jeu->y_pions[10];

        // choix d'une direction
        int direction;
        int ii;
        int jj;
        do
        { // on cherche une direction aléatoirement
            direction = rand() % 9;
            ii = 0;
            jj = 0;
            switch (direction)
            {
            case SUD:
                ii = 1;
                break;
            case NORD:
                ii = -1;
                break;
            case EST:
                jj = 1;
                break;
            case OUEST:
                jj = -1;
                break;
            case NORDOUEST:
                ii = -1;
                jj = -1;
                break;
            case NORDEST:
                ii = -1;
                jj = 1;
                break;
            case SUDEST:
                ii = 1;
                jj = 1;
                break;
            case SUDOUEST:
                ii = 1;
                jj = -1;
                break;
            case RIEN:
                break;
            }
        } while (legit(jeu, x, y, x + ii, y + jj, 3) != 0); // on continue à chercher tant que la direction n'est pas valide
        jeu->grille[x][y] = 0;
        jeu->grille[x + ii][y + jj] = 3;
        jeu->x_pions[10] = x + ii;
        jeu->y_pions[10] = y + jj;
    }

    // maintenant, on bouge un pion si l'on n'a pas encore gagné
    if (victoire(jeu) == 0)
    {
        int pas; // Cette variable va nous servir pour savoir si le pion et la direction ne sont pas bloquées, auquel cas il vaudra 0 à la fin de la boucle suivante
        int nb_pion;
        int x;
        int y;
        int direction;
        int ii;
        int jj;
        do
        {
            // On choisit un pion qui va bouger
            nb_pion = rand() % 5 + (joueur - 1) * 5;
            x = jeu->x_pions[nb_pion];
            y = jeu->y_pions[nb_pion];

            // On va maintenant chercher une direction aléatoirement, de la même manière que pour le bobail au dessus
            direction = rand() % 9;
            ii = 0;
            jj = 0;

            switch (direction)
            { // défini les incréments en fonction de la direction
            case SUD:
                ii = 1;
                break;
            case NORD:
                ii = -1;
                break;
            case EST:
                jj = 1;
                break;
            case OUEST:
                jj = -1;
                break;
            case NORDOUEST:
                ii = -1;
                jj = -1;
                break;
            case NORDEST:
                ii = -1;
                jj = 1;
                break;
            case SUDEST:
                ii = 1;
                jj = 1;
                break;
            case SUDOUEST:
                ii = 1;
                jj = -1;
                break;
            case RIEN:
                break;
            }

            // On continue à avancer dans la direction tant qu'on n'est pas au bout
            pas = 1;
            while (x + pas * ii >= 0 && x + pas * ii <= 4 && y + pas * jj >= 0 && y + pas * jj <= 4 && jeu->grille[x + pas * ii][y + pas * jj] == 0)
            { // tant qu'on est sur une cas vide dans la grille, on essaie d'avancer
                ++pas;
            }
            // on a avancé trop loin, on recule
            --pas;

        } while (pas == 0); // la direction ne nous permet pas d'avancer, on va rechercher un nouveau pion et une nouvelle direction

        // Il ne nous reste plus qu'à enregistrer la nouvelle position
        jeu->grille[x][y] = 0;
        jeu->grille[x + pas * ii][y + pas * jj] = joueur;
        jeu->x_pions[(joueur - 1) * 5 + nb_pion] = x + pas * ii;
        jeu->y_pions[(joueur - 1) * 5 + nb_pion] = y + pas * jj;
    }
}

// maybe implémenter le fait que bouger aléatoirement c'est bête ? genre on essate toujours de à peu près déplacer le bobail vers notre coté et pas vers l'adversaire ?

// on reprend beaucoup d'éléments de legit.c, peut etre dans legit.c directement faire une fonction qui prend en argument une direction plutot qu'une position et renvoie si c'est okay