#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "deplacement.h"
#include "legit.h"

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

int legit(int **grille, int ia, int ja, int ib, int jb, int typepion)
{
    direction_t direction = RIEN;
    if (ia < 0 || ib < 0 || ja < 0 || jb < 0 || ia > 4 || ib > 4 || ja > 4 || jb > 4)
    {
        return 1; // une des position est hors-grille
    }
    if (ia == ib)
    { // déplacement en ligne
        if (ja == jb)
        {
            return 2; // pas de déplacement
        }
        else if (ja < jb)
        {
            direction = EST;
        }
        else
        {
            direction = OUEST;
        }
    }
    else if (ja == jb)
    { // déplacement en colonne
        if (ia < ib)
        {
            direction = SUD;
        }
        else
        {
            direction = NORD;
        }
    }
    else if (ib - ia == jb - ja)
    { // première diagonale
        if (ib > ia)
        {
            direction = SUDEST;
        }
        else
        {
            direction = NORDOUEST;
        }
    }
    else if (ib - ia == ja - jb)
    { // deuxième diagonale
        if (ib > ia)
        {
            direction = SUDOUEST;
        }
        else
        {
            direction = NORDEST;
        }
    }
    else
    {
        return 3; // direction inexistante
    }

    // printf("direction : %d\n", direction);
    //  on a maintenant la direction , vérifions que l'on ne rencontre pas d'obstacle
    int ii = 0; // incrément sur i
    int jj = 0; // incrément sur j

    while (ia + ii != ib || ja + jj != jb)
    {

        switch (direction)
        {
        case SUD:
            ii++;
            break;
        case NORD:
            ii--;
            break;
        case EST:
            jj++;
            break;
        case OUEST:
            jj--;
            break;
        case NORDOUEST:
            ii--;
            jj--;
            break;
        case NORDEST:
            ii--;
            jj++;
            break;
        case SUDEST:
            ii++;
            jj++;
            break;
        case SUDOUEST:
            ii++;
            jj--;
            break;
        case RIEN:
            break;
        }
        if (grille[ia + ii][ja + jj] != 0)
        {
            return 4; // une case est déja occupée sur le chemin
        }
    }
    // on est maintenant arrivé sur la case d'arrivée.On va vérifier qu'elle est compatible

    if (typepion == 3)
    {
        if (ii > 1 || jj > 1 || ii < -1 || jj < -1)
        {
            return 5; // bobail déplacé de plus de 1 case
        }
        else
        {
            return 0; // déplacement correct du bobail !
        }
    }
    else
    { // Si on est allé "au bout" du déplacement, alors la case suivante est soit hors grille, soit occupée.
        // D'abord, alons à la case suivante
        switch (direction)
        {
        case SUD:
            ii++;
            break;
        case NORD:
            ii--;
            break;
        case EST:
            jj++;
            break;
        case OUEST:
            jj--;
            break;
        case NORDOUEST:
            ii--;
            jj--;
            break;
        case NORDEST:
            ii--;
            jj++;
            break;
        case SUDEST:
            ii++;
            jj++;
            break;
        case SUDOUEST:
            ii++;
            jj--;
            break;
        case RIEN:
            break;
        }
        // printf("ii jj %d %d\n", ii, jj);
        // printf("ii+ia ..%d %d\n", ia + ii, ja + jj);
        // printf("%d\n", grille[ia + ii][ja + jj]);
        if (ia + ii < 0 || ja + jj < 0 || ia + ii > 4 || ib + jj > 4)
        {             // la prochaine case est hors grille
            return 0; // déplacement ok !
        }
        else if (grille[ia + ii][ja + jj] != 0)
        {             // la prochaine case est occupée
            return 0; // déplacement ok !
        }
        else
        {
            return 6; // on n'est pas allé au bout du déplacement !
        }
    }
}
