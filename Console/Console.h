#ifndef CONSOLE_H
#define CONSOLE_H

#include <vector>

#include <ncurses.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "../Objects/Object.h"
#include "../Objects/Grass.h"
#include "../Objects/Sheep.h"
#include "../Objects/Dog.h"
#include "../Objects/Wolf.h"
#include "../Objects/Lamb.h"
#include "Panel.h"

using namespace std;

class Console{
private:
	int grid_length;
	int panel_length;

	WINDOW * g_win;
	WINDOW * p_win;

	vector< vector<Object*> >* grid;
	Panel* panel;

	int max_grass;
	int max_sheep_lamb;
	int max_wolf;
	int max_dog;	

	int wolf_timer;

public:
	
	Console(int,int);

	void init();
	void init_grid();
	void init_window();

	int count(char);
	int get_round();
	int get_wolf_timer();

	void spawn(char);
	void spawn_multiple(char,int);
	void dec_wolf_timer();

	void draw();

	void update();

	~Console();


};

#endif