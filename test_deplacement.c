#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"
#include "legit.h"
#include "deplacement.h"

int main()
{
    jeu_t *jeu = initialisation();

    coup(jeu, 1);

    destruction(jeu);

    return 0;
}