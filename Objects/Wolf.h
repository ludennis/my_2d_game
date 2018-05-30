#ifndef WOLF_H
#define WOLF_H

#include "Object.h"

class Wolf: public Object{
	int lamb_eaten;
	int sheep_eaten;
public:
	Wolf();
	Wolf(int,int,vector< vector<Object*> >*,Panel*);

	void move();
	void attack();

	void inc_lamb_eaten();
	void inc_sheep_eaten();

	int get_lamb_eaten();
	int get_sheep_eaten();

	~Wolf();
};

#endif