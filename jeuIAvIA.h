#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> //pour utiliser sleep
#include <time.h>   //pour initialiser le random

#include "deplacement.h"
#include "affichage.h"
#include "legit.h"
#include "initialisation.h"
#include "victoire.h"
#include "hasard.h"
#include "IA.h"

int jeuIAvIA_aleatoire();
/* permet  de regarder deux ordinateurs jouer, qui jouent des coups complètement aléatoires */

int jeuIAvIA();
/* permet  de regarder deux ordinateurs jouer intelligement, en utilisant l'agorithme MCTS classique */

int jeuIAvIA_improved();
/* permet  de regarder deux ordinateurs jouer encore plus intelligement, avec l'algorithme MCTS que nous avons modifié */

int jeuIAvIA_comparaison(int joueurIAclassique);
/* permet de comparer les performances des deux algorithmes MCTS. le joueur joueurIAclassique joue avec MCTS et l'autre joue avec MCTS récursif
la fonction renvoie le gagnant de la partie, et stoppe la partie au bout de 100 itérations si elle n'est pas finie (elle renvoie alors 0)
*/
