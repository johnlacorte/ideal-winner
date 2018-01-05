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
//#include <iostream>

int main()
{
    Map levelMap(12, 12);
    CreatureArray cArray(&levelMap);
    initscr();/* Start curses mode*/
    levelMap.fillSquare(1, 1, 10, 10, true, '.');
    levelMap.look(4, 4, 4);
    printw("\n");
    cArray.setCreature(1, '@', 4, 4);
    levelMap.insertCreature(4, 4, 1, '@');
    levelMap.look(4, 4, 4);
    cArray.move(1, 5, 4);
    levelMap.look(4, 4, 4);
    getch();
    endwin();/* End curses mode		  */
    return 0;
}
