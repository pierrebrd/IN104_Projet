#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "jeu1vIA.h"
#include "deplacement.h"
#include "affichage.h"
#include "legit.h"
#include "initialisation.h"
#include "victoire.h"

void jeu1vIA()
{
    // Demander au joueur s'il est joueur 1 ou joueur 2
    int joueurHumain ;
    int joueurIA ;
    printf("Voulez vous etre le joueur : 1 ou 2? : ") ;
    scanf("%d",&joueurHumain) ;
    printf("\n") ;
    joueurIA = joueurHumain %2 + 1 ;

    // expliquer l'affichage
    if (joueurHumain == 1 ) {
        printf("Vous avez les pions rouges, l'IA a les pions verts. Le bobail est en violet\n") ;
    }
    else {
       printf("Vous avez les pions verts, l'IA a les pions rouges. Le bobail est en violet\n") ;
    }


    int **grille = initialisation();
    int tour = 0;
    int joueuractuel = 1;
    while (victoire(grille) == 0) // tant qu'aucun joueur n'a gagné
    {
        ++tour;
        if (tour != 1) // au premier tour, on ne bouge pas le bobail
        {
            if(joueurHumain == joueuractuel) {
                afficher(grille);
                printf("A vous de jouer ! Bougez le Bobail.\n", joueuractuel);
                coup(grille, 3);
            }
            else {
                // COUP DE L'IA
                afficher(grille);
            }
            
        }
        if (victoire(grille) == 0)
        {
            if(joueurHumain == joueuractuel) {
                afficher(grille);
                printf("Bougez un de vos pions.\n", joueuractuel);
                coup(grille, joueuractuel);
            }
            else {
                // COUP DE L'IA
                afficher(grille);
            }

        }

        joueuractuel = 1 + joueuractuel % 2;
    }
    afficher(grille);
    printf("Le joueur %d a gagné en %d tours !\n\n\n", victoire(grille), tour);
}
