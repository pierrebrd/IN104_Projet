#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "jeuIAvIA.h"

int main(int argc, char **argv)
{
    // Le nombre de parties est donné en argument
    //  la fonction renvoie le nombre de parties gagnées par l'IA 1 et par l'IA 2
    int n = atoi(argv[1]);
    int S1 = 0; // nombre de victoires de l'IA 1
    int S2 = 0; // nombre de victoires de l'IA 2
    for (int i = 1; i <= n; ++i)
    {
        int resultat = jeuIAvIA_improved();
        if (resultat == 1)
        {
            S1++;
        }
        else if (resultat == 2)
        {
            S2++;
        }
        printf("En %d parties, L'IA 1 a gagné %d fois (ratio de %f), l'IA 2 a gagné %d fois (ratio de %f)\n", i, S1, (double)S1 / i, S2, (double)S2 / i);
    }

    return 0;
}