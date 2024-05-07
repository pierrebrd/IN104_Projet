#include "initialisation.h"

jeu_t* jeu = initialisation ;
int k = 1 ;
for (int i = 0 ; i < 5 ; i++) {
    coup_hasard(jeu, k%2 + 1, i+1)
}

jeu_t *jeu_test = initialisation ;

copy_jeu(jeu, jeu_test) ;
