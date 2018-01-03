//I probably need to include cmath for sqrt() for Map::look()
//look() might be better off in another class of i/o stuff but that will be later
//insertCreature() and insertItem() should probably take a pointer or offset
//#include <item.h>
//#include <creature.h>
#ifndef MAP_H
#define MAP_H
class Tile//I don't know what to do about things like doors
{
    private:
    bool isPassable;
    bool isMapped;
    char floorSymbol;
    char creatureSymbol;
    char itemSymbol;
    //ItemContainer *tileItems;//These probably should be offsets to array 
    //CreatureContainer *tileCreature;//to make saving and loading easier
    public:
    Tile();
    ~Tile();
    //Function to set the values of the tile
    void setTile(bool pass, char floor);
    //Function to get tileSymbol and set isMapped
    char getSymbol();
    void insertCreature(char sym);
    void insertItem(char sym);
    //remove item, show item, take item
    //remove creature
    //Some kind of thing for using skills to get resources and change tile
    //Some way to trigger actions
};

class Map
{
    //Map might be a little hard to plan out ahead of time
    //Map needs a structure to hold a bunch of tiles
    //A pointer to creature and item containers
    //Map might need to handle saving and loading
    //Map might need to have look() and miniMap()
    //Map might need to have functions to build a map from tiles
    private:
    Tile *mapTiles;
    int mapWidth, mapHeight;
    public:
    Map(int width, int height);
    ~Map();
    void look(int x, int y, int size);
    void fillSquare(int x, int y, int w, int h, bool pass, char floor);
    size_t index( int x, int y );
    void insertCreature(int x, int y, char sym);
    void insertItem(int x, int y, char sym);
};

#endif
