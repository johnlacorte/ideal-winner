//Tile class and Map class functions
//Header files
#include <ncurses.h>
//#include <iostream>
#include "map.h"

Tile::Tile()
{
    //std::cout << "creating tile" << std::endl;
    isPassable = false;
    isMapped = false;
    floorSymbol = '#';
    creatureSymbol = ' ';
    itemSymbol = ' ';
}

Tile::~Tile()
{

}

void Tile::setTile(bool pass, char floor)
{
    isPassable = pass;
    floorSymbol = floor;
}

char Tile::getSymbol()
{
    isMapped = true;
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

void Tile::insertCreature(char sym)
{
    creatureSymbol = sym;
}

void Tile::insertItem(char sym)
{
    itemSymbol = sym;
}

Map::Map(int width, int height)
{
    mapWidth = width;
    mapHeight = height;
    mapTiles = new Tile[width * height];
    //Tile mapTiles[width][height];
}

//Map::~Map()//free up memory for tiles, maybe not necessary but hey.
Map::~Map()
{
    delete mapTiles;
}

size_t Map::index( int x, int y )
{
    return x + mapWidth * y;
}

void Map::look(int x, int y, int radius)
{
    //From the center? or top left?
    //if the tile is outside the boundries of the map print a space
    char sym;
    for(int j = y - radius; j < y + radius + 1; ++j)
    {
        for(int i = x - radius; i < x + radius + 1; ++i)
        {
            if(i >= 0 && j >= 0 && i < mapWidth && j < mapHeight)
            {
                sym = mapTiles[index(i, j)].getSymbol();
                printw("%c", sym);
		printw(" ");
		//std::cout << sym << ' ';
            }
	    else
            {
                printw("  ");
		//std::cout << "  ";
            }
        }
	printw("\n");
	//std::cout << std::endl;
    }
    refresh();
}

void Map::fillSquare(int x, int y, int w, int h, bool pass, char floor)
{
    //check if x and y are in range
    for(int j = y; j < y + h; ++j)
    {
        for(int i = x; i < x + w; ++i)
        {
            mapTiles[index(i, j)].setTile(pass, floor);
        }
    }
}
void Map::insertCreature(int x, int y, char sym)
{
    mapTiles[index(x, y)].insertCreature(sym);
}

void Map::insertItem(int x, int y, char sym)
{
    mapTiles[index(x, y)].insertItem(sym);
}

