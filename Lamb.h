#ifndef LAMB_H
#define LAMB_H

#include "Sheep.h"

class Lamb: public Sheep{
public:
	Lamb();
	Lamb(int,int,vector< vector<Object*> >*);
	~Lamb();
};

#endif