#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "affichage.h"
#include "initialisation.h"
#include "legit.h"
#include "deplacement.h"

int main() {
    int** grille = initialisation() ;

    coup(grille) ;

    destruction(grille) ;

    return 0;


}