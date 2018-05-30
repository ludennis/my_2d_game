#include <iostream>
#include <ncurses.h>

#include "Objects/Object.h"
#include "Console/Console.h"

#ifdef KEY_ENTER
#undef KEY_ENTER
#define KEY_ENTER 10
#endif

using namespace std;

int main(){

	// initialization for using curses
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	start_color();
	curs_set(0);

	Console *c = new Console(20,10);
	c->init();
	int last_key = 0;
	last_key = getch();

	do {
		c->draw();
		last_key = getch();
		if (last_key == KEY_ENTER){
			while(c->get_round()<100){
				c->update();
				c->draw();
			} 
			last_key = getch();
		}
		c->update();
	} while(last_key == ' ' or last_key == KEY_ENTER);

	//ending curses
	endwin();

	return 0;
}
