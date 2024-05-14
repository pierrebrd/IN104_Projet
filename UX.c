#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

void regles()
{
    // explication affichagfe
    printf("Amusez vous bien avec le bobail !\nVous jouerez sur une grille de 5x5, ou les lignes sont numérotées de A a E et les colonnes de 1 à 5.\nJoueur 1, vous aurez 5 pions rouges ");
    printf("\033[0;91m");
    printf("● ");
    printf("\033[0m");
    printf("initialement dans la colonne 1.\nJoueur 2, vous aurez 5 pions verts ");
    printf("\033[0;92m");
    printf("● ");
    printf("\033[0m");
    printf("initialement dans la colonne 5.\nLe bobail est le pion violet ");
    printf("\033[0;95m");
    printf("● ");
    printf("\033[0m");
    printf("au centre de la grille.\n\n");

    sleep(2);
    // explication comment gagner
    //  PISTE AMELIORATION : afficher des exemples
    printf("Votre mission, si vous l'acceptez, est de ramener le bobail dans votre colonne, ou de l'encercler afin que votre adversaire ne puisse le deplacer.\n\n");
    sleep(2);

    // déplacement
    printf("A chaque tour, le joueur déplace d'abord le bobail puis un de ses pions.\nLe bobail peut se déplacer d'une case verticalement, horizontalement ou en diagonale.\nLes autres pions se déplacent verticalement, horizontalement ou en diagonale jusqu'à heurter un obstacle.\n");
}
