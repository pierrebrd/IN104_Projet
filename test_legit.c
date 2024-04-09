#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"
#include "legit.h"

int main()
{
    int **grille = initialisation();
    afficher(grille);
    printf("%d\n", legit(grille, 2, 2, 0, 2, 3));
    return 0;
}