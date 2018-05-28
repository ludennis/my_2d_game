#ifndef DOG_H
#define DOG_H

#include "Object.h"

class Dog: public Object{
public:
	Dog();
	Dog(int,int,vector< vector<Object*> >*);

	void move();
	void attack();

	~Dog();
};

#endif