
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
}

Object* Object::get(){return this;}
char Object::get_name(){return name;}

void Object::set_name(char c){name = c;}
void Object::move_u(){y--;}
void Object::move_d(){y++;}
void Object::move_l(){x--;}
void Object::move_r(){x++;}
void Object::move(){
	int prev_x = x;
	int prev_y = y;
	for (int i=0; i<range;i++){
		int dir = rand()%5;
		if (dir==HOLT) continue;
		else if (dir==UP){
			if (y-1<0 || (*grid)[y-1][x]!=NULL) continue;
			else move_u();
		}
		else if (dir==DOWN){
			if (y+1>=20 || (*grid)[y+1][x]!=NULL) continue;
			else move_d();
		}
		else if (dir==LEFT){
			if (x-1<0 || (*grid)[y][x-1]!=NULL) continue;
			else move_l();
		} 
		else if (dir==RIGHT){
			if (x+1>=20 || (*grid)[y][x+1]!=NULL) continue;
			else move_r();
		}
		else return;
	}
	if (prev_x == x && prev_y == y) return;
	else {
		(*grid)[y][x]=(*grid)[prev_y][prev_x];
		(*grid)[prev_y][prev_x]=NULL;	
	}
	
}


Object::~Object(){}