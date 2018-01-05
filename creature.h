//creature base class and player and guardian and monster subclasses
//and creature container
#ifndef CREATURE_H
#define CREATURE_H
#include "map.h"
class Creature
{
    private:
    char symbol;
    int myX, myY;
    //A small array or structure or tuple would let me use it as a return value
    public:
    void setCreature(char sym, int x, int y);
    void move(Map *level, int offset, Creature *me, int x, int y);
    char getSymbol();
    //void turn(Map *level);//Virtual function
};

class Player : Creature
{

};

class Guardian : Creature
{

};

class Monster : Creature
{

};

class CreatureArray
{
    private:
    int creArraySize;
    Creature creArray[10];
    Map *thisLevel;
    public:
    CreatureArray(Map *level);
    Creature *getCrePtr(int n);
    void setCreature(int offset, char sym, int x, int y);
    void move(int offset, int x, int y);
};

#endif

