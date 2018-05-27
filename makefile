CFLAGS=-Wall -Wc++11-extensions
LIBS=-lncurses
OBJS=main.o Console.o Object.o 

play: $(OBJS)
	g++ $(CFLAGS) $(LIBS) -o play $(OBJS)

main.o: main.cpp
	g++ -c main.cpp

Object.o: Object.cpp Object.h
	g++ -c Object.cpp

Console.o: Console.cpp Console.h
	g++ -c Console.cpp

clean:
	rm -f play *.o 

