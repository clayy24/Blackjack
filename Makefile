OBJS = Card.o Deck.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
EXE = blackjack

$(EXE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXE)

Card.o: Card.hpp
	$(CC) $(CFLAGS) main.cpp

Deck.o: Deck.hpp Card.hpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o $(EXE) -v
	