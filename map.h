#ifndef ITEM_H
#define ITEM_H
#include <item.h>
#endif
#ifndef CREATURE_H
#define CREATURE_H
#include <creature.h>
#endif

class Tile
{
    private:
    bool isPassable;
    bool isMapped;
    char floorSymbol;
    char creatureSymbol;
    char itemSymbol;
    //ItemContainer *tileItems;
    //CreatureContainer *tileCreature;
    //public:
    //The constructor probably should just set pointers to NULL
    //Function to set the values of the tile
    //Function to get tileSymbol
    //Get and drop items
    //Add and remove creature
    //Map tile
    //Some kind of thing for using skills to get resources and change tile
    //Some way to trigger actions
};

class Map
{
    //Map might be a little hard to plan out ahead of time
    //Map needs a structure to hold a bunch of tiles
    //Map might need to handle saving and loading
    //Map might need to have look() and miniMap()
    //Map might need to have functions to build a map from tiles
};


