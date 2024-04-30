#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"

int main()
{
    jeu_t *jeu = initialisation();
    afficher(jeu);
    return 0;
}