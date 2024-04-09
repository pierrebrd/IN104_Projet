#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "legit.h"

int input(int* pos) {

    // VALID vaut 0 si l'input est bon, 1 sinon
    int VALID = 0 ;

    // Prendre l'input sous forme de string
    char x_a ;
    char y_a ;
    char x_b ;
    char y_b ;
    printf("Donner les coordonnées en LettreMajusculeChiffre sans espace\n") ;
    // Position du pion avant deplacement
    // x_a y_a est par exemple A1
    printf("Position initiale : ") ;
    scanf(" %c%c",&x_a,&y_a) ;
    // Position du pion après deplacement
    // x_b y_b est par exemple A1
    printf("\nPosition finale : ") ;
    scanf(" %c%c",&x_b,&y_b) ;
    printf("\n");

    // Check la validité de la lettre
    switch(x_a) {
        case 'A' :
            pos[0] = 0 ;
            break;
        case 'B' :
            pos[0] = 1 ;
            break;
        case 'C' :
            pos[0] = 2 ;
            break;
        case 'D' :
            pos[0] = 3 ;
            break;
        case 'E' :
            pos[0] = 4 ;
            break;
        default :
            printf("Format attendu : LettreChiffre en majuscule sans espace\n") ;
            VALID = 1 ;
            break ;
    }

    switch(x_b) {
        case 'A' :
            pos[2] = 0 ;
            break;
        case 'B' :
            pos[2] = 1 ;
            break;
        case 'C' :
            pos[2] = 2 ;
            break;
        case 'D' :
            pos[2] = 3 ;
            break;
        case 'E' :
            pos[2] = 4 ;
            break;
        default :
            printf("Format attendu : LettreChiffre en majuscule sans espace\n") ;
            VALID = 1 ;
            break ;
    }

    // Check la validité du chiffre
    switch(y_a) {
        case '1' :
            pos[1] = 0 ;
            break;
        case '2' :
            pos[1] = 1 ;
            break;
        case '3' :
            pos[1] = 2 ;
            break;
        case '4' :
            pos[1] = 3 ;
            break;
        case '5' :
            pos[1] = 4 ;
            break;
        default :
            printf("Format attendu : LettreChiffre en majuscule sans espace\n") ;
            VALID = 1 ;
            break ;
    }

    switch(y_b) {
        case '1' :
            pos[3] = 0 ;
            break;
        case '2' :
            pos[3] = 1 ;
            break;
        case '3' :
            pos[3] = 2 ;
            break;
        case '4' :
            pos[3] = 3 ;
            break;
        case '5' :
            pos[3] = 4 ;
            break;
        default :
            printf("Format attendu : LettreChiffre en majuscule sans espace\n") ;
            VALID = 1 ;
            break ;
    }

    if(VALID == 0) {
        return 0;
    }
    else {
        input(pos) ;
        return 1 ;
    }
    
}

/**********
COUP
***********/

int coup(int** grille) {
    int pos [4] ;
    int check_input = input(pos) ;

    if (check_input == 1) {
        coup(grille) ; //peut etre que ca pose problème et que ca va lancer 2 fois le truc
        return 1 ; // entrée au mauvais format
        }
    else {
        int type_pion = grille[pos[0]][pos[1]] ;
        int check_legit = legit(grille,pos[0],pos[1],pos[2],pos[3],type_pion) ;

        switch(check_legit) {
            case 0 :
            // vider la case dont le pion part
                grille[pos[0]][pos[1]] = 0 ;
            // remplir la case d'arrivée
                grille[pos[2]][pos[3]] = type_pion ;
                return 0;
            case 1 :
                printf("Déplacement invalide : case choisie hors-grille\n") ;
                coup(grille) ;
                return 2 ;
            case 5 :
                printf("Le bobail ne peut se déplacer que d'une case\n") ;
                coup(grille) ;
                return 2 ;
            case 3:
                printf("Les pions se déplacent horizontalement, verticalement ou diagonalement jusqu'à rencontrer un obstacle\n") ;
                coup(grille) ;
                return  2 ;
            case 6 :
                printf("Les pions se déplacent horizontalement, verticalement ou diagonalement jusqu'à rencontrer un obstacle\n") ;
                coup(grille) ;
                return  2 ;
            case 4 :
                printf("Les pions se déplacent horizontalement, verticalement ou diagonalement jusqu'à rencontrer un obstacle\n") ;
                coup(grille) ;
                return  2 ;
            case 2 :
                printf("Veuillez déplacer le pion.\n") ;
                coup(grille) ;
                return  2 ;
            }
        }
    return 0;
}
