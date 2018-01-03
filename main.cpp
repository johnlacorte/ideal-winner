/* rl - a roguelike game
 * written by: John LaCorte
 * started: 2017-12-30
*/

//TODO
//I need to store the level
//I need to store individual spaces in the level
//I need to store players
//I need to store monsters
//I need to store guardians
//I need to store items
//messages
//input/output
//editors
//menu()
//are skills going to be an array of function pointers?
#include <ncurses.h>//for input and output
#include <cstdlib>//for random
#include <ctime>//for random
#include "map.h"
//#include <iostream>

int main()
{
    Map levelMap(12, 12);
    //Tile t;
    initscr();/* Start curses mode*/
    //t.setTile(true, true, '#', ' ', ' ');
    //std::cout << t.getSymbol() << std::endl;
    levelMap.fillSquare(1, 1, 10, 10, true, '.');
    levelMap.look(4, 4, 4);
    printw("\n");
    levelMap.insertCreature(4, 4, '@');
    levelMap.look(4, 4, 4);
    getch();
    endwin();/* End curses mode		  */
    return 0;
}
