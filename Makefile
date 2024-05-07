CC=gcc
CFLAGS=-Wall -Werror 
LDFLAGS= 

all: main.x 

test_jeu1v1.x: test_jeu1v1.o initialisation.o affichage.o deplacement.o legit.o jeu1v1.o victoire.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_jeuIAvIA.x: test_jeuIAvIA.o initialisation.o affichage.o deplacement.o legit.o jeuIAvIA.o victoire.o hasard.o IA.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_jeu1vIA.x: test_jeu1vIA.o initialisation.o affichage.o deplacement.o legit.o jeu1vIA.o victoire.o hasard.o IA.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_vitesseIA.x: test_vitesseIA.o initialisation.o affichage.o legit.o victoire.o hasard.o IA.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_affichage.x: test_affichage.o initialisation.o affichage.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_legit.x: test_legit.o legit.o initialisation.o affichage.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

test_IA.x : test_IA.o IA.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


%.x: %.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean: # PHONY recipe
	rm -f *~ *.o

realclean: clean
	rm -f *.x

.PHONY: clean
