#ifndef WOLF_H
#define WOLF_H

#include "Object.h"

class Wolf: public Object{
public:
	Wolf();
	Wolf(int,int,vector< vector<Object*> >*,Panel*);

	void move();
	void attack();

	~Wolf();
};

#endif