#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "jeu1v1.h"
#include "deplacement.h"
#include "affichage.h"
#include "legit.h"
#include "initialisation.h"
// #include "victore.h"

void jeu1v1()
{
    printf("Le joueur 1 a les pions rouge, le joueur 2 a les pions verts, le  bobail est violet. Le joueur 1 commence\n");
    int **grille = initialisation();

    int joueuractuel = 1;
    // while (victoire(grille, joueuractuel) == 0)
    for (int i = 0; i < 5; ++i)
    {
        afficher(grille);
        printf("Joueur %d, à vous de jouer ! Bougez le Bobail.\n", joueuractuel);
        coup(grille, 3);
        afficher(grille);
        printf("Joueur %d, bougez un de vos pions.\n", joueuractuel);
        coup(grille, joueuractuel);

        joueuractuel = 1 + joueuractuel % 2;
    }
}

// il faut : implémenter le fait qu'on doive d'abord bouger le bobailpuis un de nos pions, et qu'on ne peut pas bouger les pions de l'autre... donc maybe modifier legit ?! en tout cas typepion doit correspondre au jouer qui joue/au bobail
// il faudrait faire en sorte de ne pas bouger l'affichage de la grille : position initiale et finale sur la même ligne ? supprimer la ligne position initiale ? mettre le curseru apres la réponse du joueru?

// Quand problème d'input ou de coup, refaire un afficher(grille)