//I probably need to include cmath for sqrt() for Map::look()
//look() might be better off in another class of i/o stuff but that will be later
#ifndef MAP_H
#define MAP_H
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
    //Some kind of thing for using skills to get resources and change tile
    //Some way to trigger actions
};

class Map
{
    //Map might need to handle saving and loading
    //Map might need to have look() and miniMap()
    //Map might need to have functions to build a map
    private:
    Tile *mapTiles;
    int mapWidth, mapHeight;
    public:
    Map(int width, int height);
    ~Map();
    void look(int x, int y, int size);
    void fillSquare(int x, int y, int w, int h, bool pass, char floor);
    int index( int x, int y );
    void insertCreature(int x, int y, int cre, char sym);
    void removeCreature(int x, int y);
    int isCreatureHere(int x, int y);
    bool isPassable(int x, int y);
    void insertItem(int x, int y, char sym);
};

#endif
