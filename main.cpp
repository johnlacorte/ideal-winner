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
#include <ncurses>//for input and output
#include <cstdlib>//for random
#include <ctime>//for random

int main()
{
    initscr();/* Start curses mode*/

    endwin();/* End curses mode		  */
    return 0;
}
