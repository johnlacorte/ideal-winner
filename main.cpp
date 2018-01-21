/* rl - a roguelike game
 * written by: John LaCorte
 * started: 2017-12-30
*/

//TODO
//editors
//menu()
//items
#include <ncurses.h>//for input and output
#include <cstdlib>//for random
#include <ctime>//for random
#include "level.h"
#include "creature.h"
#include "message.h"

int main()
{
    Player hero;
    MessageList msgList;
    Level testLevel(&hero, &msgList);
    initscr();// Start curses mode
    raw();//set raw mode in curses
    noecho();//set no echo in curses
    hero.setCreature('@', 4, 4);
    testLevel.test();
    testLevel.start();
    endwin();// End curses mode
    return 0;
}
