#ifndef MAP_H
#define MAP_H

#include "message.h"

class Tile//I don't know what to do about things like doors
{
    private:
    bool passable;
    bool mapped;
    char floorSymbol;
    char creatureSymbol;
    char itemSymbol;
    int creatureHere;
    //ItemContainer 
    public:
    Tile();
    void setTile(bool pass, char floor);
    char getSymbol();
    void insertCreature(int cre, char sym);
    void removeCreature();
    void insertItem(char sym);
    int isCreatureHere();
    bool isPassable();
    //remove item, show item, take item
    //Some way to trigger actions
};

class Map
{
    private:
    Tile *mapTiles;
    MessageList *msgOutput;
    int mapWidth, mapHeight;
    public:
    Map(int width, int height, MessageList *ml);
    ~Map();
    void newMessage(char *msg);
    void look(int x, int y, int size);
    void fillSquare(int x, int y, int w, int h, bool pass, char floor);
    int index( int x, int y );
    void insertCreature(int x, int y, int cre, char sym);
    void removeCreature(int x, int y);
    int isCreatureHere(int x, int y);
    bool isPassable(int x, int y);
    void insertItem(int x, int y, char sym);
    void testMap();
};

#endif
