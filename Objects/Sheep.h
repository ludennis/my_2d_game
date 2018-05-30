#ifndef SHEEP_H
#define SHEEP_H

#include "Object.h"

class Sheep: public Object{
	int grass_eaten;
public:
	Sheep();
	Sheep(int,int,vector< vector<Object*> >*,Panel*);
	
	void move();
	void attack();

	~Sheep();
};

#endif