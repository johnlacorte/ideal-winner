/* rl - a roguelike game
 * written by: John LaCorte
 * started: 2017-12-30
*/

//TODO
//messages
//input/output in a neat package
//editors
//menu()
#include <ncurses.h>//for input and output
#include <cstdlib>//for random
#include <ctime>//for random
#include "map.h"
#include "creature.h"

int main()
{
    Map levelMap(12, 12);
    Player hero;
    Monster enemy;
    Creature *selected;
    int counter = 1;
    initscr();/* Start curses mode*/
    raw();
    noecho();
    levelMap.testMap();
    hero.setCreature('@', 4, 4);
    hero.insertToMap(&levelMap, 2);
    enemy.setCreature('g', 6, 6);
    enemy.insertToMap(&levelMap, 1);
    enemy.next = &hero;
    hero.previous = &enemy;
    selected = &enemy;
    while(selected->turn(&levelMap, counter) == 1)
    {
        if(selected->next != NULL)
        {
            selected = selected->next;
            ++counter;
        }
	else
        {
            selected = &enemy;//temporary creatureArrayHead
	    counter = 1;
        }

    }
    endwin();/* End curses mode		  */
    return 0;
}
