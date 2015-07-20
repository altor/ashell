CC = gcc
CFLAGS = -Wall -c
LDFLAGS = 
OBJ = ashell.o traitement_signal.o traitement_erreur.o commande.o

ashell: $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o ashell
	mv ashell ../../bin
traitement_signal.o: traitement_signal.c traitement_signal.h 
ashell.o: ashell.c traitement_signal.h 
traitement_erreur.o: traitement_erreur.c traitement_erreur.h
commande.o: commande.c commande.h

clean:
	rm -f *.o ashell
