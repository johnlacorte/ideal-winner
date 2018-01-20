//I need to pass in the player creature
#ifndef LEVEL_H
#include "map.h"
#include "creature.h"
#include "message.h"

class Level
{
    private:
    Map *levelMap;
    MessageList *msgOutput;
    CreatureList creatures;
    Creature *player;
    //loot piles
    public:
    Level(Creature *pl, MessageList *ml);//second version for generating the level
    int start();
    void test();
};
#endif
