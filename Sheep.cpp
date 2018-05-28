#include "Sheep.h"

Sheep::Sheep(){}
Sheep::Sheep(int y, int x, vector< vector<Object*> >* g):Object('S',2,y,x,g){}

void Sheep::attack(){
	Object* nearest_grass = Object::find_nearest_target('G');
	if (nearest_grass == NULL){return;}
	else { 
		if (distance_from(nearest_grass) == 1){
			(*grid)[nearest_grass->get_y()][nearest_grass->get_x()] = NULL;
			delete nearest_grass; 
			this->set_done(true);
		}
	}
}

/* implements virtual void Object::move() 
   finds and seeks after the nearest grass */
void Sheep::move(){
	Object* nearest_grass = Object::find_nearest_target('G');
	if (nearest_grass == NULL){return;} 
	else {this->seek(nearest_grass);}
}

Sheep::~Sheep(){}