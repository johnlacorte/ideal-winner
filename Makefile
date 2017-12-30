rl: main.o
	g++ -o rl main.o -lncurses
main.o: main.cpp
	g++ -c main.cpp

