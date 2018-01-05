rl: main.o creature.o map.o
	g++ -o rl main.o map.o creature.o -lncurses
main.o: main.cpp
	g++ -c main.cpp
creature.o: creature.cpp creature.h
	g++ -c creature.cpp
map.o: map.cpp map.h
	g++ -c map.cpp

