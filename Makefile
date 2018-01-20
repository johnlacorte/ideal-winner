rl: main.o message.o level.o creature.o map.o
	g++ -o rl main.o message.o level.o map.o creature.o -lncurses
main.o: main.cpp
	g++ -c main.cpp
message.o: message.cpp message.h
	g++ -c message.cpp
level.o: level.cpp level.h
	g++ -c level.cpp
creature.o: creature.cpp creature.h
	g++ -c creature.cpp
map.o: map.cpp map.h
	g++ -c map.cpp

