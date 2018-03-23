CC=g++ 
CPPFLAGS=-g 
LDFLAGS=-g
LDLIBS=

main: deck.o main.o
	$(CC) $(LDFLAGS) -o main Deck.o main.o $(LDLIBS) 

main.o:
	$(CC) $(CPPFLAGS) -c -o main.o main.cpp

deck.o:
	$(CC) $(CPPFLAGS) -c -o Deck.o Deck.cpp

clean:
	rm *.o main