#include "hasard.h"

int coup_hasard(jeu_t *jeu, int joueur, int tour)
{
    int direction_bobail = 8; // si il ne bouge pas, sa direction est 8
    if (tour != 1)
    { // on doit bouger le bobail aléatoirement
        // on récupère l'emplacement bobail
        int x = jeu->x_pions[10];
        int y = jeu->y_pions[10];

        // choix d'une direction

        int ii; // initialisation des incréments pour la direction
        int jj;
        do
        { // on cherche une direction aléatoirement
            direction_bobail = rand() % 8;
            ii = 0;
            jj = 0;
            switch (direction_bobail)
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

        } while (legit(jeu, x, y, x + ii, y + jj, 3) != 0); // on continue à chercher tant que la direction n'est pas valide, c'est-à-dire tant que la case ou se déplace le bobail n'est pas vide
        jeu->grille[x][y] = 0;
        jeu->grille[x + ii][y + jj] = 3;
        jeu->x_pions[10] = x + ii;
        jeu->y_pions[10] = y + jj;
    }

    // maintenant, on bouge un pion si l'on n'a pas encore gagné
    int nb_pion = 0; // initialisation avant de rentrer dans la boucle
    int direction = 0;
    if (victoire(jeu, joueur) == 0)
    {
        int nb_recherches = 0; // on ne veut pas boucler à l'infini
        int pas;               // Cette variable va nous servir pour savoir si le pion et la direction ne sont pas bloquées, auquel cas il vaudra 0 à la fin de la boucle suivante
        int x;
        int y;
        int ii;
        int jj;
        do
        {
            ++nb_recherches;

            // On choisit un pion qui va bouger
            nb_pion = rand() % 5 + (joueur - 1) * 5;
            x = jeu->x_pions[nb_pion];
            y = jeu->y_pions[nb_pion];

            // On va maintenant chercher une direction aléatoirement, de la même manière que pour le bobail au dessus
            direction = rand() % 8;
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

            if (nb_recherches > 10000)
            { // on abandonne la branche, le jeu est bloqué
                // afficher(jeu);
                return 404; // code qui est renvoyé lorsque le jeu est bloqué
            }

        } while (pas == 0); // si pas==0, c'est que la direction ne nous permet pas d'avancer, on va rechercher un nouveau pion et une nouvelle direction

        // Il ne nous reste plus qu'à enregistrer la nouvelle position
        jeu->grille[x][y] = 0;
        jeu->grille[x + pas * ii][y + pas * jj] = joueur;
        jeu->x_pions[nb_pion] = x + pas * ii;
        jeu->y_pions[nb_pion] = y + pas * jj;
    }

    // printf("%d\n", 40 * direction_bobail + 8 * (nb_pion % 5) + direction);
    return (40 * direction_bobail + 8 * (nb_pion % 5) + direction); // On en a besoin dans l'implémentation de MCTS
}