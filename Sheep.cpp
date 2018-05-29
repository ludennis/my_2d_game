#include "Sheep.h"

Sheep::Sheep(){}
Sheep::Sheep(int y, int x, vector< vector<Object*> >* g,Panel* p):Object('S',2,y,x,g,p){this->grass_eaten=0;}

void Sheep::attack(){
	Object* nearest_grass = Object::find_nearest_target('G');
	if (nearest_grass == NULL){return;}
	else { 
		if (distance_from(nearest_grass) == 1){
			(*grid)[nearest_grass->get_y()][nearest_grass->get_x()] = NULL;
			delete nearest_grass; 
			this->set_done(true);
			if(++grass_eaten%3==0){
				this->panel->inc_sheep_fed();
				this->panel->inc_score(5);
			}
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