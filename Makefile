rl: main.o map.o
	g++ -o rl main.o map.o -lncurses
main.o: main.cpp
	g++ -c main.cpp
map.o: map.cpp map.h
	g++ -c map.cpp
