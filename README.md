# Jeu Bobail - Julie Aubry et Pierre Bordeau

## MODE D'EMPLOI

Pour jouer en 1v1, il faut pour l'instant éxécuter `make test_jeu1v1.x` pour compiler, puis lancer le jeu avec `./test_jeu1v1.x`

## AFFICHAGE DE LA GRILLE

Nous représentons l'état du jeu par un `struct jeu_t` qui contient la grille et la liste des abscisses et des ordonnées de tous les pions, afin de ne pas avoir à les rechercher en parcourant la grille quand on en a besoin

Nous avons choisi de représenter la grille de jeu comme une matrice 5x5, implémentée avec un `int** grille`
Cela permet de modéliser facilement quelle case est occupée par quoi, en représentant par : 
- 0 : case vide
- 1 : case remplie par un pion du joueur 1
- 2 : case remplie par un pion du joueur 2
- 3 : case remplie par le bobail
  
Convention de l'indexation de la grille :
lignes i croissant de haut en bas
colonnes j croissant de gauche à droite

Les listes `int* x_pions` et `int* y_pions` enregistre les positions des pions : les 5 premiers éléments sont les pions du joueur 1, les 5 suivants ceux du joueur 2, et le dixième élément correspond au bobail.
  
L'avantage de cette double représentation de l'état du jeu qu'on profite à la fois de la simplicité de la manipulation de la grille et de la liste des positions des pions, ce qui évite de rechercher les pions dans la grille quand on en a besoin (pour l'IA notamment).



Pour avoir un affichage intuitif et visuellement plaisant en utilisant seulement le terminal, on utilise des caractères Unicode pour faire la grille (catégorie "Box Drawing, https://en.wikipedia.org/wiki/List_of_Unicode_characters)
Pour afficher les pion, on utilise des cercles dont on change la couleur.

## DEPLACEMENT

On nomme les cases avec :
une lettre entre A et E pour la ligne
un chiffre entre 1 et 5 pour la colonne
Ainsi `(i=2,j=4)` est représenté par C5, et on demande un tel input à l'utilisateur via la ligne de commande. Si l'utilisateur différe de ce format, il recoit un message d'erreur. Il nous a semblé trop fastidieux de comprendre les inputs incorrects mais compréhensibles tels que "C 5" ou "c5".

On déplace le pion en changeant la valeur des cases de départ et d'arrivée dans la matrice `grille`, et en changeant sa position dans les listes `x_pions` et `y_pions`.

Les fonctions liées au déplacement se situent dans deplacements.h

## IA

Nous travaillons maintenant sur l'implémentation d'une IA, les fichiers sont dans la branche IA. Nous nous intéressons à la méthode de Monte Carlo tree search.
