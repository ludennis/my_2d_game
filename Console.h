#ifndef CONSOLE_H
#define CONSOLE_H

#include <vector>

#include <ncurses.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "Object.h"

using namespace std;

class Console{
private:
	int grid_length;
	int panel_length;

	WINDOW * g_win;
	WINDOW * p_win;

	vector< vector<Object*> > grid;

	int round;

public:
	
	Console(int,int);

	void init();
	void init_grid();
	// void init_panel();
	void init_window();

	// void spawn_multiple(char name, int num);
	// void spawn_at(char name, int row, int col);

	void draw();

	// void update();
	// void update_round();
	// void update_objects();

	~Console();


};

#endif