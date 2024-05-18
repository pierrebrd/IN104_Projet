CC=gcc
CFLAGS= -Wall -O2 # -O2 permet d'optimiser le code, et surtout de trouver des erreurs qu'on ne trouve pas sans
LDFLAGS=
FILES=initialisation.o affichage.o deplacement.o legit.o jeu1v1.o jeuIAvIA.o jeu1vIA.o victoire.o hasard.o IA.o UX.o
# FILESs contient tous les fichiers .o nécessaires pour compiler l'ensemble des programmes

all: main.x #Si on ne précise pas que l'on veut un fichier précis (comme test_jeu1v1.x), on compile main.x

%.x: %.o $(FILES) # Permet de créer les fichiers .x à partir de tous les fichiers .o
	$(CC) $(CFLAGS) $^ -o $@  $(LDFLAGS)

%.o : %.c # Permet de créer les fichiers .o à partir des fichiers .c
	$(CC) $(CFLAGS) -c $<


.PRECIOUS: %.o #indique que les fichiers .o intermédiaires ne doivent pas être supprimés


clean:
	rm -f *~ *.o

realclean: clean
	rm -f *.x

.PHONY: clean realclean
