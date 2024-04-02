
#include <stdlib.h>
#include <stdio.h>

void coup(){
    /* Demande le coup, vérifie qu'il est légal, et met à jour la grille*/

    // Demande au joueur 

    printf("Emplacement du pion à déplacer (LettreChiffre sans espace): ") ;
    //char* depart ;
    //scanf("%s", depart) ;

    printf("Direction (Nord, Nord-Ouest...): ") ;
    //char* dir_string;
    //scanf("%s", dir_string) ;

    // Vérifie que l'entrée est correcte, convertir dir_string en enum
    // A FAIRE, ca va etre un gros morceau :(

    //Voir si on peut se déplacer dans cette direction

    // déplacer dans cette direction
    // on peut définit suivant=i+1,j dans la dir sud, i-1,j+1 dans le dir nord-est...
}


int main() {
    return 0 ;
}