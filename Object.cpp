
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
	this->done = false;
}

Object* Object::get(){return this;}
char Object::get_name(){return this->name;}
bool Object::is_done(){return this->done;}
int Object::get_x(){return this->x;}
int Object::get_y(){return this->y;}
vector< vector<Object*> >* Object::get_grid(){return this->grid;}
int Object::distance_from(Object* target){return abs(this->y - target->y) + abs(this->x - target->x);}

Object* Object::find_nearest_target(char target_name){
	int shortest_distance = grid->size() * 2;
	Object* target = NULL;
	for (int yy=0; yy<grid->size();++yy){
		for (int xx=0; xx<(*grid)[0].size();++xx){
			if((*grid)[yy][xx]!=NULL && ((*grid)[yy][xx])->get_name()==target_name){
				int distance = this->distance_from((*grid)[yy][xx]);
				if (distance < shortest_distance) {
					shortest_distance = distance;
					target=(*grid)[yy][xx];
				}
			}
		}
	}
	return target;
}

void Object::set_name(char c){this->name = c;}
void Object::set_done(bool d){this->done = d;}
void Object::move_u(){--y;}
void Object::move_d(){++y;}
void Object::move_l(){--x;}
void Object::move_r(){++x;}

/* moves in random direction within range */
void Object::move(){
	int prev_x = x;
	int prev_y = y;
	int dir;
	for (int i=0; i<range;++i){
		dir = rand()%5;
		if (dir==UP){if (y-1>=0 && (*grid)[y-1][x]==NULL) move_u();}
		else if (dir==DOWN){if (y+1<20 && (*grid)[y+1][x]==NULL) move_d();}
		else if (dir==LEFT){if (x-1>=0 && (*grid)[y][x-1]==NULL) move_l();} 
		else if (dir==RIGHT){if (x+1<20 and (*grid)[y][x+1]==NULL) move_r();}
	}
	if (prev_x == x && prev_y == y) return;
	else {
		(*grid)[y][x]=(*grid)[prev_y][prev_x];
		(*grid)[prev_y][prev_x]=NULL;	
	}
	this->done = true;
}

void Object::seek(Object* target){
	int prev_x = x;
	int prev_y = y;

	for (int i=0; i<range;++i){
		if (y > target->get_y()){if (y-1>=0 && (*grid)[y-1][x]==NULL) move_u();}
		else if (y < target->get_y()){if (y+1<20 && (*grid)[y+1][x]==NULL) move_d();}
		else if (x > target->get_x()){if (x-1>=0 && (*grid)[y][x-1]==NULL) move_l();} 
		else if (x < target->get_x()){if (x+1<20 and (*grid)[y][x+1]==NULL) move_r();}
	}
	if (prev_x == x && prev_y == y) return;
	else {
		(*grid)[y][x]=(*grid)[prev_y][prev_x];
		(*grid)[prev_y][prev_x]=NULL;	
	}
	this->done = true;
}

void Object::attack(){return;}


Object::~Object(){}