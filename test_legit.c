#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"
#include "legit.h"

int main()
{
    jeu_t *jeu = initialisation();
    afficher(jeu);
    printf("%d\n", legit(jeu, 2, 2, 0, 2, 3));
    return 0;
}