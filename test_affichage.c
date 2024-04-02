#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"

int main()
{
    int **grille = initialisation();
    afficher(grille);
    return 0;
}