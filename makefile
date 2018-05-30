CFLAGS=-g -O0 -Wall -Wc++11-extensions
LIBS=-lncurses
OBJS=main.o Console.o Object.o Grass.o Sheep.o Dog.o Wolf.o Lamb.o Panel.o

play: $(OBJS)
	g++ $(CFLAGS) $(LIBS) -o play $(OBJS)

main.o: main.cpp
	g++ -g -O0 -c main.cpp

Lamb.o: Objects/Lamb.cpp Objects/Lamb.h
	g++ -g -O0 -c Objects/Lamb.cpp

Wolf.o: Objects/Wolf.cpp Objects/Wolf.h
	g++ -g -O0 -c Objects/Wolf.cpp

Dog.o: Objects/Dog.cpp Objects/Dog.h
	g++ -g -O0 -c Objects/Dog.cpp

Sheep.o: Objects/Sheep.cpp Objects/Sheep.h
	g++ -g -O0 -c Objects/Sheep.cpp

Grass.o: Objects/Grass.cpp Objects/Grass.h
	g++ -g -O0 -c Objects/Grass.cpp

Object.o: Objects/Object.cpp Objects/Object.h
	g++ -g -O0 -c Objects/Object.cpp

Console.o: Console/Console.cpp Console/Console.h
	g++ -g -O0 -c Console/Console.cpp

Panel.o: Console/Panel.cpp Console/Panel.h
	g++ -g -O0 -c Console/Panel.cpp


clean:
	rm -f play *.o 

