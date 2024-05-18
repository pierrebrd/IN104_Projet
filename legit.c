#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "deplacement.h"
#include "legit.h"
#include "initialisation.h"

typedef enum
{
    NORD,
    SUD,
    OUEST,
    EST,
    NORDOUEST,
    NORDEST,
    SUDOUEST,
    SUDEST,
    RIEN
} direction_t;

int legit(jeu_t *jeu, int ia, int ja, int ib, int jb, int type_pion)
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
        if (jeu->grille[ia + ii][ja + jj] != 0)
        {
            return 4; // une case est déja occupée sur le chemin
        }
    }
    // on est maintenant arrivé sur la case d'arrivée.On va vérifier qu'elle est compatible

    if (type_pion == 3)
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
        // printf("%d\n", jeu->grille[ia + ii][ja + jj]);
        if (ia + ii < 0 || ja + jj < 0 || ia + ii > 4 || ja + jj > 4)
        {             // la prochaine case est hors grille
            return 0; // déplacement ok !
        }
        else if (jeu->grille[ia + ii][ja + jj] != 0)
        {             // la prochaine case est occupée
            return 0; // déplacement ok !
        }
        else
        {
            return 6; // on n'est pas allé au bout du déplacement !
        }
    }
}


int legit_direction(jeu_t *jeu, int indice_coup) {
    // Extraire les infos de indice_coup
    int direction_bobail = indice_coup / 40;
    int nb_pion = (indice_coup % 40) / 8 + 5 * (joueur - 1);
    int direction_pion = indice_coup % 8;
    // Extraire les positions du bobail et du pion
    int abs_bobail = jeu->x_pions[10] ;
    int ord_bobail = jeu->y_pions[10] ;
    int abs_pion = jeu->x_pions[nb_pion] ;
    int ord_pion = jeu->y_pions[nb_pion] ;

    // Selon la direction, on détermine commment vont changer l'abscisse et l'ordonnée 
    int i_shift = 0;
    int j_shift = 0;
    switch (direction_bobail) {
        case SUD:
            i_shift = 1;
            break;
        case NORD:
            i_shift = -1;
            break;
        case EST:
            j_shift = 1;
            break;
        case OUEST:
            j_shift = -1;
            break;
        case NORDOUEST:
            i_shift = -1;
            j_shift = -1;
            break;
        case NORDEST:
            i_shift = -1;
            j_shift = 1;
            break;
        case SUDEST:
            i_shift = 1;
            j_shift = 1;
            break;
        case SUDOUEST:
            i_shift = 1;
            j_shift = -1;
            break;
        case RIEN:
            break;
        }


    // Check si le déplcament du bobail est valide
    if (abs_bobail + i_shift >= 0 && abs_bobail + i_shift <= 4 && ord_bobail + j_shift >= 0 && ord_bobail + j_shift <= 4 ) { // si le bobail reste dans la grille
        if( jeu->grille[abs_bobail + i_shift][ord_bobail + j_shift] != 0) {
        return 1 ; // si le bobail va dans une case occupée
        }
    }
    // Check si le déplcament du pion est valide
    else if (abs_pion + i_shift >= 0 && abs_pion+ i_shift <= 4 && ord_pion + j_shift >= 0 && ord_pion+ j_shift <= 4 ) { // si le pion reste dans la grille
        if( jeu->grille[abs_pion + i_shift][ord_pion + j_shift] != 0) {
        return 1 ; // si le pion va dans une case occupée
        }
    }
    else { // le bobail ou le pion est sorti de la grille 
        return 1 ; // le bobail ou le pion est sorti de la grille 
    }
    return 0 ; // personne sort de la grille, personne ne va sur une case occupée
}