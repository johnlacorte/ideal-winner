//functions for all of the creatures
#include "map.h"
#include "creature.h"
#include <ncurses.h>

Creature::Creature()//Probably want to fill in all the data in the constructor
{
    previous = NULL;
    next = NULL;
}

void Creature::insertToMap(Map *level, int offset)
{
    level->insertCreature(myX, myY, offset, symbol);
}

void Creature::removeFromMap(Map *level)
{
    level->removeCreature(myX, myY);
}

void Creature::setCreature(char sym, int x, int y)
{
    symbol = sym;
    myX = x;
    myY = y;
}

int Creature::getX()
{
    return myX;
}

int Creature:: getY()
{
    return myY;
}

char Creature::getSymbol()
{
    return symbol;
}

//I might not actually NEED cArray if there are pointers
void Creature::moveTo(Map *level, int offset, int x, int y)
{
    //Check if a creature is there, if so get its type and attack
    //Maybe return check value? Attacking is something I need to consider
    int check = level->isCreatureHere(x, y);
    //char mySymbol = cArray[offset].getSymbol();
    	if(check != 0)
        {
            //walkthrough list and attack()
	    //move(1,1);
        }
        else if(level->isPassable(x, y))//check if it is passable
        {
            //move yourself then
	        level->removeCreature(myX, myY);
	        myX = x;
	        myY = y;
	        level->insertCreature(x, y, offset, symbol);
        }
    //Check to keep from going off the map too
}

int Player::turn(Map *level, int offset)
{
    char input;
    bool getInput = true;
    int moveToX, moveToY;
    level->look(getX(), getY(), 4);
    while(getInput)
    {
        input = getch();
	    //Temporary code to move around map with number pad
	    if(input > '0' && input <= '9')
        {
            getInput = false;
            if(input > '6')
            {
                moveToY = getY() - 1; 
            }
	        else if(input < '4')
            {
                moveToY = getY() + 1;
            }
	        else
	        {
                moveToY = getY();
	        }
	        if(input == '1' || input == '4' || input == '7')
	        {
                moveToX = getX() - 1;
	        }
	        else if(input == '3' || input == '6' || input == '9')
	        {
                moveToX = getX() + 1;
	        }
	        else
	        {
                moveToX = getX();
	        }
	        //I think this means a '5' moves back to original place
	        moveTo(level, offset, moveToX, moveToY);
            return 1;
        }
        else if(input == 'q')
        {
            return 0;
        }
    }
}

int Guardian::turn(Map *level, int offset)
{
    return 1;
}

int Monster::turn(Map *level, int offset)
{
    return 1;
}

CreatureList::CreatureList(Map *level)
{
    thisLevel = level;
    head = NULL;
}

//add new creature

void CreatureList::addToList(Creature *cre)
{
    Creature *selected;
    if(head == NULL)
    {
        head = cre;
    }
    else
    {
        selected = head;
	while(selected->next != NULL)
        {
            selected = selected->next;
        }
	selected->next = cre;
	cre->previous = selected;
    }
}

void CreatureList::removeFromList(Creature *cre)
{
    //This is to remove player or things where it isn't necessary to free memory.
    Creature *selected;
    if(cre == head)
    {
        head = cre->next;
    }
    if(cre->previous != NULL)
    {
        selected = cre->previous;
	selected->next = cre->next;
    }
    if(cre->next != NULL)
    {
        selected = cre->next;
	selected->previous = cre->previous;
    }
    cre->previous = NULL;
    cre->next = NULL;
}

int CreatureList::start()
{
    Creature *selected = head;
    int offsetCounter = 1;
    int ret;
    //check if head is NULL first
    ret = selected->turn(thisLevel, offsetCounter);
    while(ret == 1)
    {
        if(selected->next != NULL)
        {
            selected = selected->next;
	    ++offsetCounter;
        }
        else
        {
            selected = head;
	    offsetCounter = 1;
        }
        ret = selected->turn(thisLevel, offsetCounter);
    }
    return ret;
}

