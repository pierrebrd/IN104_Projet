#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "jeuIAvIA.h"

int main(int argc, char **argv)
{
    // L'IA classique est le premier entier donné en argument
    // Le nombre de parties est le deuxième entier donné en argument
    //  la fonction renvoie le nombre de parties gagnées par l'IA classique et le nombre de parties gagnées par l'IA améliorée
    int joueurIAclassique = atoi(argv[1]);
    int n = atoi(argv[2]);
    int S1 = 0; // nombre de victoires de l'IA classique
    int S2 = 0; // nombre de victoires de l'IA améliorée
    for (int i = 1; i <= n; ++i)
    {
        int resultat = jeuIAvIA_comparaison(joueurIAclassique);
        if (resultat == joueurIAclassique)
        {
            S1++;
        }
        else if (resultat == joueurIAclassique % 2 + 1)
        {
            S2++;
        }
        printf("En %d parties, L'IA classique a gagné %d fois (ratio de %f), l'IA améliorée a gagné %d fois (ratio de %f)\n", i, S1, (double)S1 / i, S2, (double)S2 / i);
    }
    printf("En %d parties, L'IA classique a gagné %d fois (ratio de %f), l'IA améliorée a gagné %d fois (ratio de %f)\n", n, S1, (double)S1 / n, S2, (double)S2 / n);

    return 0;
}