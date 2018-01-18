//I need to pass in the player creature
#ifndef LEVEL_H
#include "map.h"
#include "creature.h"

class Level
{
    private:
    Map *levelMap;
    CreatureList creatures;
    Creature *player;
    //loot piles
    public:
    Level(Creature *pl);//second version for generating the level
    char *start();
    void test();
}
