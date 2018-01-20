#include "level.h"
#include "map.h"
#include "creature.h"
#include "message.h"
#include <cstddef>

Level::Level(Creature *pl, MessageList *ml)
{
    player = pl;
    levelMap = NULL;
    msgOutput = ml;
}

int Level::start()
{
    int ret;
    creatures.addToList(player);
    player->insertToMap(levelMap, 2);
    ret = creatures.start();
    //remove everything from the map when done
    return ret;
}

void Level::test()
{
    Monster *goblin;
    levelMap = new Map(12, 12, msgOutput);
    levelMap->testMap();
    creatures.setMap(levelMap);
    goblin = new Monster;
    goblin->setCreature('g', 6, 6);
    creatures.addToList(goblin);
    goblin->insertToMap(levelMap, 1);//This done in CreatureList at start()
}

