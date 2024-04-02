# Jeu Bobail - Julie Aubry et Pierre Bordeau

description du bobail et une belle intro

##### AFFICHAGE DE LA GRILLE #####

Nous avons choisi de représenter la grille de jeu comme une matrice 5x5, implémentée avec un int**.
Cela permet de modéliser facilement quelle case est occupée par quoi, en représentant par :
    0 : case vide
    1 : case remplie par un pion du joueur 1
    2 : case remplie par un pion du joueur 2
    3 : case remplie par le bobail
Un autre avantage est la simplicité de la manipulation de l'objet, surtout par rapport à un suivi de chaque pion individuellement.

Convention de l'indexation de la grille : 
    lignes i croissant de haut en bas
    colonnes j croissant de gauche à droite

# a pierre de parler de l'affichage en lui même

##### DEPLACEMENT #####

On nomme les cases avec :
    une lettre entre A et E pour la ligne
    un chiffre entre 1 et 5 pour la colonne
Ainsi (i=2,j=4) est représenté par C5.

