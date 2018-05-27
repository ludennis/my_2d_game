#include <iostream>
#include <ncurses.h>

#include "Object.h"
#include "Console.h"

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

	Console *c = new Console(20,10);
	c->init();
	int last_key = 0;

	do {
		c->draw();

		last_key = getch();

		c->update();

	} while(last_key == ' ' or last_key == KEY_ENTER);

	//ending curses
	endwin();

	return 0;
}
