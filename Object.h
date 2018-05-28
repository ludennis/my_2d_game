#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <stdlib.h>

using namespace std;

class Object{
protected:
	char name;
	int range;
	int y;
	int x;

	bool moved;

	vector< vector<Object*> >* grid;

public:

	Object();
	Object(char,int,int,int,vector< vector<Object*> >*);	

	Object* get();
	char get_name();
	bool has_moved();
	int distance_from(Object*);
	Object* find_nearest_target(char);
	int get_x();
	int get_y();
	vector< vector<Object*> >* get_grid();
	// int get_range();
	

	virtual void move();
	void seek(Object*);
	void set_moved(bool);
	void move_u();
	void move_d();
	void move_l();
	void move_r();
	void set_name(char);

	~Object();
};

#endif