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
#include "Grass.h"
#include "Sheep.h"
#include "Dog.h"

using namespace std;

class Console{
private:
	int grid_length;
	int panel_length;

	WINDOW * g_win;
	WINDOW * p_win;

	int round;

	vector< vector<Object*> >* grid;

	// vector<Grass*> grass;
	// vector<Sheep*> sheep;
	// vector<Dog*> dogs;
	

public:
	
	Console(int,int);

	void init();
	void init_grid();
	void init_window();

	void spawn_at(char name, int row, int col);

	void draw();

	void update();

	~Console();


};

#endif