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
#include "Wolf.h"

using namespace std;

class Console{
private:
	int grid_length;
	int panel_length;

	WINDOW * g_win;
	WINDOW * p_win;

	int round;

	vector< vector<Object*> >* grid;

	int max_grass;
	int max_sheep_lamb;
	int max_wolf;
	int max_dog;	

public:
	
	Console(int,int);

	void init();
	void init_grid();
	void init_window();

	int count(char);
	int get_round();

	void spawn(char);
	void spawn_multiple(char,int);

	void draw();

	void update();

	~Console();


};

#endif