
#include "Object.h"

#define HOLT 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

Object::Object(){}

Object::Object(char n, int r, int y, int x, vector< vector<Object*> >* g){
	this->name = n;
	this->range = r;
	this->y = y;
	this->x = x;
	this->grid = g;
	this->moved = false;
}

Object* Object::get(){return this;}
char Object::get_name(){return this->name;}
bool Object::has_moved(){return this->moved;}

void Object::set_name(char c){this->name = c;}
void Object::set_moved(bool m){this->moved = m;}
void Object::move_u(){--y;}
void Object::move_d(){++y;}
void Object::move_l(){--x;}
void Object::move_r(){++x;}
void Object::move(){
	int prev_x = x;
	int prev_y = y;
	int dir;
	for (int i=0; i<range;++i){
		dir = rand()%5;
		if (dir==UP){
			if (y-1>=0 && (*grid)[y-1][x]==NULL) move_u();
		}
		else if (dir==DOWN){
			if (y+1<20 && (*grid)[y+1][x]==NULL) move_d();
		}
		else if (dir==LEFT){
			if (x-1>=0 && (*grid)[y][x-1]==NULL) move_l();
		} 
		else if (dir==RIGHT){
			if (x+1<20 and (*grid)[y][x+1]==NULL) move_r();
		}
	}
	if (prev_x == x && prev_y == y) return;
	else {
		(*grid)[y][x]=(*grid)[prev_y][prev_x];
		(*grid)[prev_y][prev_x]=NULL;	
	}
	this->moved = true;
}


Object::~Object(){}