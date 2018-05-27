CFLAGS=-g -O0 -Wall -Wc++11-extensions
LIBS=-lncurses
OBJS=main.o Console.o Object.o Grass.o Sheep.o

play: $(OBJS)
	g++ $(CFLAGS) $(LIBS) -o play $(OBJS)

main.o: main.cpp
	g++ -g -O0 -c main.cpp

Sheep.o: Sheep.cpp Sheep.h
	g++ -g -O0 -c Sheep.cpp

Grass.o: Grass.cpp Grass.h
	g++ -g -O0 -c Grass.cpp

Object.o: Object.cpp Object.h
	g++ -g -O0 -c Object.cpp

Console.o: Console.cpp Console.h
	g++ -g -O0 -c Console.cpp

clean:
	rm -f play *.o 

