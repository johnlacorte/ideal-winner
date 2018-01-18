//Tile class and Map class functions

#include <ncurses.h>
#include "map.h"

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
    mapped = true;
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
    creatureSymbol = sym;
    creatureHere = offset;
}

void Tile::removeCreature()
{
    creatureSymbol = ' ';
    creatureHere = 0;
}

int Tile::isCreatureHere()
{
    return creatureHere;
}

void Tile::insertItem(char sym)
{
    itemSymbol = sym;
}

bool Tile::isPassable()
{
    return passable;
}
Map::Map(int width, int height)
{
    mapWidth = width;
    mapHeight = height;
    mapTiles = new Tile[width * height];
}

Map::~Map()
{
    delete mapTiles;
}

int Map::index( int x, int y )
{
    return x + mapWidth * y;
}

void Map::look(int x, int y, int radius)
{
    //From the center? or top left?
    //if the tile is outside the boundries of the map print a space
    char sym;
    move(4,0);
    for(int j = y - radius; j < y + radius + 1; ++j)
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
    refresh();
}

void Map::fillSquare(int x, int y, int w, int h, bool pass, char floor)
{
    //check if x and y are in range
    if(x > 0 && y > 0)
    {
        if(x + w < mapWidth && y + h < mapHeight)
        {
            for(int j = y; j < y + h; ++j)
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
    mapTiles[index(x, y)].insertCreature(offset, sym);
}

void Map::removeCreature(int x, int y)
{
    mapTiles[index(x, y)].removeCreature();
}

int Map::isCreatureHere(int x, int y)
{
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
    fillSquare(1, 1, 10, 10, true, '.');
}
