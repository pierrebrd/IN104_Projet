#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "hasard.h"
#include "IA.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    int n = atoi(argv[1]);
    // jeu_t *jeu = initialisation();
    //  jeu_t *jeu_provisoire = malloc(sizeof(jeu_t));
    int S = 0;

    for (int i = 0; i < n; ++i)
    {
        // jeu_provisoire = jeu; // ne marche pas ! il faut copier, pas renvoyer vers la même adresse !
        jeu_t *jeu_provisoire = initialisation();
        S = S + explore_aleatoire(jeu_provisoire, 1, 1) % 2; // compte les victoires de J1
        destruction(jeu_provisoire);
    }
    printf("%d\n", S);
    return 0;
}