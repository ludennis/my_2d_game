#ifndef SHEEP_H
#define SHEEP_H

#include "Object.h"

class Sheep: public Object{
public:
	Sheep();
	Sheep(int,int,vector< vector<Object*> >*);
	
	~Sheep();
};

#endif