CC=gcc
CFLAGS=-Wall -Werror 
LDFLAGS= 

all: main.x 



test_affichage.x: test_affichage.o initialisation.o affichage.o
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
