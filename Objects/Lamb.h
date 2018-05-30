#ifndef LAMB_H
#define LAMB_H

#include "Object.h"
#include "Sheep.h"

class Lamb: public Object{
	int grass_eaten;
public:
	Lamb();
	Lamb(int,int,vector< vector<Object*> >*,Panel*);

	void attack();
	void move();

	~Lamb();
};

#endif