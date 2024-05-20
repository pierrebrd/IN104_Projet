#include "deplacement.h"

void changement_position(jeu_t *jeu, int *pos, int type_pion)

{
    if (type_pion == 3)
    {
        // Facile, on sait déja que le bobail est le 11ème pion
        jeu->x_pions[10] = pos[2];
        jeu->y_pions[10] = pos[3];
    }
    else
    {
        int nb_pion = (type_pion - 1) * 5; // on commence la recherche à 0 pour le joueur 1, à 5 pour le joueur 2
        while (jeu->x_pions[nb_pion] != pos[0] && jeu->y_pions[nb_pion] != pos[1])
        {
            // tant qu'on n'a pas trouvé le bon pion
            ++nb_pion;
            // on passe au pion suivant
        }
        // nb_pion correspond maintenant au pion que nous sommes en train de bouger, il suffit de changer sa position
        jeu->x_pions[nb_pion] = pos[2];
        jeu->y_pions[nb_pion] = pos[3];
    }
}

int input(int *pos)
{

    // VALID vaut 0 si l'input est bon, 1 sinon
    int VALID = 0;

    // Prendre l'input sous forme de string
    char x_a;
    char y_a;
    char x_b;
    char y_b;
    printf("Donner les coordonnées en LettreMajusculeChiffre sans espace.\n\n");
    // Position du pion avant deplacement
    // x_a y_a est par exemple A1
    printf("\x1b[APosition initiale : "); // \x1b[A permet de remonter d'une ligne dans le terminal pour que l'affichage de "Position finale" ne décale pas la grille
    scanf(" %c%c", &x_a, &y_a);
    // Position du pion après deplacement
    // x_b y_b est par exemple A1
    printf("Position finale :   ");
    scanf(" %c%c", &x_b, &y_b);
    printf("\n");

    // Check la validité de la lettre
    switch (x_a)
    {
    case 'A':
        pos[0] = 0;
        break;
    case 'B':
        pos[0] = 1;
        break;
    case 'C':
        pos[0] = 2;
        break;
    case 'D':
        pos[0] = 3;
        break;
    case 'E':
        pos[0] = 4;
        break;
    default:
        VALID = 1;
        break;
    }

    switch (x_b)
    {
    case 'A':
        pos[2] = 0;
        break;
    case 'B':
        pos[2] = 1;
        break;
    case 'C':
        pos[2] = 2;
        break;
    case 'D':
        pos[2] = 3;
        break;
    case 'E':
        pos[2] = 4;
        break;
    default:
        VALID = 1;
        break;
    }

    // Check la validité du chiffre
    switch (y_a)
    {
    case '1':
        pos[1] = 0;
        break;
    case '2':
        pos[1] = 1;
        break;
    case '3':
        pos[1] = 2;
        break;
    case '4':
        pos[1] = 3;
        break;
    case '5':
        pos[1] = 4;
        break;
    default:
        VALID = 1;
        break;
    }

    switch (y_b)
    {
    case '1':
        pos[3] = 0;
        break;
    case '2':
        pos[3] = 1;
        break;
    case '3':
        pos[3] = 2;
        break;
    case '4':
        pos[3] = 3;
        break;
    case '5':
        pos[3] = 4;
        break;
    default:
        VALID = 1;
        break;
    }

    if (VALID == 0)
    {
        return 0;
    }
    else
    {
        printf("Format attendu : LettreChiffre en majuscule sans espace.\n");
        input(pos);
        return 1;
    }
}

/**********
COUP
***********/

int coup(jeu_t *jeu, int type_pion)
{
    int pos[4];
    int check_input = input(pos);

    if (check_input == 1)
    {
        coup(jeu, type_pion); // peut etre que ca pose problème et que ca va lancer 2 fois le truc
        return 1;             // entrée au mauvais format
    }

    else if (jeu->grille[pos[0]][pos[1]] != type_pion)
    {
        printf("Vous ne pouvez pas bougez ce pion !\n");
        coup(jeu, type_pion);
        return 2;
    }
    else
    {
        int check_legit = legit(jeu, pos[0], pos[1], pos[2], pos[3], type_pion);

        switch (check_legit)
        {
        case 0:
            // vider la case dont le pion part
            jeu->grille[pos[0]][pos[1]] = 0;
            // remplir la case d'arrivée
            jeu->grille[pos[2]][pos[3]] = type_pion;
            // changer la position du pion dans x_pions et y_pions
            changement_position(jeu, pos, type_pion);
            return 0;
        case 1:
            printf("Déplacement invalide : case choisie hors-grille. Erreur 1\n");
            coup(jeu, type_pion);
            return 2;
        case 5:
            printf("Le bobail ne peut se déplacer que d'une case. Erreur 5\n");
            coup(jeu, type_pion);
            return 2;
        case 3:
            printf("Les pions se déplacent horizontalement, verticalement ou diagonalement jusqu'à rencontrer un obstacle. Erreur 3\n");
            coup(jeu, type_pion);
            return 2;
        case 6:
            printf("Les pions se déplacent horizontalement, verticalement ou diagonalement jusqu'à rencontrer un obstacle.Erreur 6\n");
            coup(jeu, type_pion);
            return 2;
        case 4:
            printf("Les pions se déplacent horizontalement, verticalement ou diagonalement jusqu'à rencontrer un obstacle. Erreur 4\n");
            coup(jeu, type_pion);
            return 2;
        case 2:
            printf("Veuillez déplacer le pion. Erreur 2\n");
            coup(jeu, type_pion);
            return 2;
        }
    }
    return 0;
}

void jouer_coup(jeu_t *jeu, int joueur, int indice_coup)
{
    if (indice_coup < 0 || indice_coup > 359)
    {
        printf("Coup %d invalide\n", indice_coup);
        return;
    }
    int direction_bobail = indice_coup / 40;
    int nb_pion = (indice_coup % 40) / 8 + 5 * (joueur - 1);
    int direction_pion = indice_coup % 8;

    // On commence par bouger le bobail
    int x = jeu->x_pions[10];
    int y = jeu->y_pions[10];
    int ii = 0;
    int jj = 0;

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
    jeu->grille[x][y] = 0;
    jeu->grille[x + ii][y + jj] = 3;
    jeu->x_pions[10] = x + ii;
    jeu->y_pions[10] = y + jj;

    // on bouge maitenant le pion, si la partie n'est pas gagnée
    if (victoire(jeu, joueur) == 0)
    {
        ii = 0;
        jj = 0;
        x = jeu->x_pions[nb_pion];
        y = jeu->y_pions[nb_pion];

        switch (direction_pion)
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
        int pas = 1;
        while (x + pas * ii >= 0 && x + pas * ii <= 4 && y + pas * jj >= 0 && y + pas * jj <= 4 && jeu->grille[x + pas * ii][y + pas * jj] == 0)
        { // tant qu'on est sur une cas vide dans la grille, on essaie d'avancer
            ++pas;
        }

        // on a avancé trop loin, on recule
        --pas;

        // Il ne nous reste plus qu'à enregistrer la nouvelle position
        jeu->grille[x][y] = 0;
        jeu->grille[x + pas * ii][y + pas * jj] = joueur;
        jeu->x_pions[nb_pion] = x + pas * ii;
        jeu->y_pions[nb_pion] = y + pas * jj;
    }
}
