//functions for all of the creatures
#include "map.h"
#include "creature.h"

void Creature::setCreature(char sym, int x, int y)
{
    symbol = sym;
    myX = x;
    myY = y;
}

char Creature::getSymbol()
{
    return symbol;
}

void Creature::move(Map *level, int offset, Creature *me, int x, int y)
{
    //Check if a creature is there, if so get its type and attack
    //Maybe return check value? Attacking is something I need to consider
    int check = level->isCreatureHere(x, y);
    char mySymbol = me->symbol;
    	if(check != 0)
        {
            //attack(check)
        }
        else if(level->isPassable(x, y))//check if it is passable
        {
            //move yourself then
	    level->removeCreature(myX, myY);
	    myX = x;
	    myY = y;
	    level->insertCreature(x, y, offset, mySymbol);
        }
    //Check to keep from going off the map too
}

CreatureArray::CreatureArray(Map *level)
{
    thisLevel = level;
}

Creature *CreatureArray::getCrePtr(int n)
{
    return &creArray[n];
}

void CreatureArray::setCreature(int offset, char sym, int x, int y)
{
    creArray[offset].setCreature(sym, x, y);
}

void CreatureArray::move(int offset, int x, int y)
{
    creArray[offset].move(thisLevel, offset, &creArray[offset], x, y);
}
