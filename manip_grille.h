#include <stdlib.h>
#include <stdio.h>

void afficher(int **grille);

void affichercase(int i, int j, int **grille);

int **initialisation();
/*crée une matrice 5*5, la remplit et la renvoie
remplit en place la config initiale de la matrice

0 : case vide
1 : case remplie par un pion du joueur 1
2 : case remplie par un pion du joueur 2
3 : case remplie par le bobail

convention coordonnées : comme une matrice mais indices entre 0 et 4
lignes i croissant de haut en bas
colonnes j croissant de gauche à droite
-> le joueur 1 a ses pions dans la colonne j=0, et le joueur 2 dans j=4
*/

void destruction(int **grille);
/*detruit la grille en libérant l'espace mémoire*/
