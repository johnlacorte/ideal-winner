//Tile class and Map class functions
#include <ncurses.h>
#include "map.h"
#include "message.h"

Tile::Tile()
{
    passable = false;
    mapped = false;
    floorSymbol = '#';
    creatureSymbol = ' ';
    itemSymbol = ' ';
    creatureHere = 0;
}

void Tile::setTile(bool pass, char floor)
{
    passable = pass;
    floorSymbol = floor;
}

char Tile::getSymbol()
{
    //returns creature symbol if a creature is on the tile otherwise
    //returns item symbol if there is a loot pile otherwise
    //returns the symbol of the floor.
    mapped = true;//mapped is a flag if has been seen and if it is on minimap.
    if(creatureSymbol != ' ')
    {
        return creatureSymbol;
    }
    else if(itemSymbol != ' ')
    {
        return itemSymbol;
    }
    else
    {
        return floorSymbol;
    }
}

void Tile::insertCreature(int offset, char sym)
{
    //Adds the creature's symbol and place in creature list to map tile.
    creatureSymbol = sym;
    creatureHere = offset;
}

void Tile::removeCreature()
{
    //Clears anything about a creature from a map tile
    creatureSymbol = ' ';
    creatureHere = 0;
}

int Tile::isCreatureHere()
{
    return creatureHere;
}

void Tile::insertItem(char sym)
{
    //At this point I haven't written the item class so this does nothing.
    itemSymbol = sym;
}

bool Tile::isPassable()
{
    return passable;
}

Map::Map(int width, int height, MessageList *ml)
{
    mapWidth = width;
    mapHeight = height;
    mapTiles = new Tile[width * height];
    msgOutput = ml;//Most convenient place to have a pointer to the message object
}

Map::~Map()
{
    delete mapTiles;
}

int Map::index( int x, int y )
{
    //Since there isn't a neat way to dynamically create a two dimensional
    //array, this converts it to the place in a one dimensional array.
    return x + mapWidth * y;
}

void Map::newMessage(char *msg)
{
    //pass a pointer to a c string with a message to be displayed
    msgOutput->newMessage(msg);
}

void Map::look(int x, int y, int radius)
{
    //This displays to the screen at the beginning of players turn
    //I think it needs to take additional parameters for status bar.
    char sym;
    clear();//clear screen
    msgOutput->showMessages();//write messages collected to the top
    for(int j = y - radius; j < y + radius + 1; ++j)//write out map symbols
    {
        for(int i = x - radius; i < x + radius + 1; ++i)
        {
            if(i >= 0 && j >= 0 && i < mapWidth && j < mapHeight)
            {
                sym = mapTiles[index(i, j)].getSymbol();
                printw("%c", sym);
		printw(" ");
            }
	    else
            {
                printw("  ");
            }
        }
	printw("\n");
    }
    refresh();//update terminal to show changes
}

void Map::fillSquare(int x, int y, int w, int h, bool pass, char floor)
{
    //check if x and y are in range, next two ifs
    if(x > 0 && y > 0)
    {
        if(x + w < mapWidth && y + h < mapHeight)
        {
            for(int j = y; j < y + h; ++j)//copy parameters to all tiles in square
            {
                for(int i = x; i < x + w; ++i)
                {
                    mapTiles[index(i, j)].setTile(pass, floor);
                }
            }
        }
    }
}
void Map::insertCreature(int x, int y, int offset, char sym)
{
    //Same as Tile::insertCreature but takes x and why coordinates of tile.
    mapTiles[index(x, y)].insertCreature(offset, sym);
}

void Map::removeCreature(int x, int y)
{
    //Same as Tile::removeCreature but takes x and y coordinates of tile.
    mapTiles[index(x, y)].removeCreature();
}

int Map::isCreatureHere(int x, int y)
{
    //Same as Tile::isCreatureHere. The next couple functions are the same
    //thing as the last two.
    return mapTiles[index(x, y)].isCreatureHere();
}

void Map::insertItem(int x, int y, char sym)
{
    mapTiles[index(x, y)].insertItem(sym);
}

bool Map::isPassable(int x, int y)
{
    mapTiles[index(x, y)].isPassable();
}

void Map::testMap()
{
    //creates a small open area to move around and interact with things
    fillSquare(1, 1, 10, 10, true, '.');
}
