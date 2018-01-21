//functions for all of the happy creatures in the dungeons.
#include "map.h"
#include "creature.h"
#include <ncurses.h>//For input
#include <cstring>//To construct messages to display with ncurses

Creature::Creature()//Probably want to fill in all the data in the constructor
{
    previous = NULL;
    next = NULL;
}

void Creature::insertToMap(Map *levelMap, int offset)
{
    levelMap->insertCreature(myX, myY, offset, symbol);
}

void Creature::removeFromMap(Map *levelMap)
{
    levelMap->removeCreature(myX, myY);
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

void Creature::moveTo(Map *levelMap, int offset, int x, int y)
{
    //Check if a creature is there, if so get its type and attack
    int check = levelMap->isCreatureHere(x, y);
    char *msg;
    if(check != 0)
    {
        //walkthrough list and attack()
        msg = new char[30];
	strcpy(msg, "Attack");
	levelMap->newMessage(msg);
    }
    else if(levelMap->isPassable(x, y))//check if you can move onto tile.
    {
        //move yourself then
        levelMap->removeCreature(myX, myY);
        myX = x;
        myY = y;
        levelMap->insertCreature(x, y, offset, symbol);
    }
    //Check to keep from going off the map too
}

int Player::turn(Map *levelMap, int offset)
{
    //Plan is to return some value to signal to keep looping through
    //creatures turns or to quit or change level.
    char input;
    bool getInput = true;
    int moveToX, moveToY;
    levelMap->look(getX(), getY(), 4);
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
            moveTo(levelMap, offset, moveToX, moveToY);
            return 1;
        }
        else if(input == 'q')
        {
            return 0;
        }
    }
}

int Guardian::turn(Map *levelMap, int offset)
{
    //A guardian will follow around player and attack monsters.
    return 1;
}

int Monster::turn(Map *levelMap, int offset)
{
    //A monster will move towards guardians and players that it sees and attack.
    return 1;
}

CreatureList::CreatureList()
{
    //Set thisMap with constructor.
    thisMap = NULL;
    head = NULL;
}

//Temporary code used to test everything works.
void CreatureList::setMap(Map *levelMap)
{
    thisMap = levelMap;
}

void CreatureList::addToList(Creature *cre)
{
    //Linked list pointer stuff. I might replace with Standard Library list
    //now that I know I want to use a linked list.
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
    //Loop through creatures in creature list and give them each a turn until
    //one of them returns a value that != 1. Return values and what they mean
    //are going to be different in the future.
    Creature *selected = head;
    int offsetCounter = 1;
    int ret;
    //check if head is NULL first
    ret = selected->turn(thisMap, offsetCounter);
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
        ret = selected->turn(thisMap, offsetCounter);
    }
    return ret;
}

