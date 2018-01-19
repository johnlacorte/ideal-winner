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
    Creature *previous, *next;
    Creature();//Probably want to fill in all the data in the constructor
    void insertToMap(Map *levelMap, int offset);
    void removeFromMap(Map *levelMap);
    void setCreature(char sym, int x, int y);
    void moveTo(Map *levelMap, int offset, int x, int y);
    int getX();
    int getY();
    char getSymbol();
    virtual int turn(Map *levelMap, int offset) = 0;//The turn function is probably the biggest thing that differs between types
};

class Player :public Creature
{
    public:
    int turn(Map *levelMap, int offset);
};

class Guardian :public Creature
{
    public:
    int turn(Map *levelMap, int offset);
};

class Monster :public Creature
{
    public:
    int turn(Map *levelMap, int offset);
};

class CreatureList
{
    private:
    Creature *head;
    Map *thisMap;
    public:
    CreatureList();
    void setMap(Map *levelMap);
    void addToList(Creature *cre);
    void removeFromList(Creature *cre);
    int start();//signal why loop ended, maybe bitmasks.
    //void setCreature(int offset, char sym, int x, int y);
    //void moveTo(int offset, int x, int y);
    //void turn(int offset);
};

#endif

