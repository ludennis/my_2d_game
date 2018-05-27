#ifndef GRASS_H
#define GRASS_H

#include "Object.h"

class Grass: public Object{
public:
	Grass(int,int,vector< vector<Object*> >*);

	void move();

	~Grass();
};

#endif