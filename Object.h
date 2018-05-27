#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <stdlib.h>

using namespace std;

class Object{
private:
	char name;
	int range;
	int y;
	int x;

public:

	Object();
	Object(char,int,int,int);	

	Object* get();
	char get_name();
	// int get_x();
	// int get_y();
	// int get_range();
	// int distance_from(Object);

	// virtual void move(int,int);
	// void move_u();
	// void move_d();
	// void move_l();
	// void move_r();
	void set_name(char);

	~Object();
};

#endif