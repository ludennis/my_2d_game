
#include "Lamb.h"

Lamb::Lamb(){}
Lamb::Lamb(int y, int x, vector< vector<Object*> >* g,Panel* p):Object('L',1,y,x,g,p){this->grass_eaten=0;}

void Lamb::attack(){
	Object* nearest_grass = Object::find_nearest_target('G');
	if (nearest_grass == NULL){return;}
	else { 
		if (distance_from(nearest_grass) == 1){
			(*grid)[nearest_grass->get_y()][nearest_grass->get_x()] = NULL;
			delete nearest_grass; 
			this->set_done(true);
			this->panel->inc_grass_eaten();
			if(++grass_eaten%3==0){
				this->panel->inc_lamb_fed();
				this->panel->inc_score(10);

				//upgrade to sheep
				(*grid)[this->get_y()][this->get_x()] = new Sheep(this->get_y(),this->get_x(),this->grid,this->panel);
				((*grid)[this->get_y()][this->get_x()])->set_done(true);
				delete this;
			}
		}
	}
}

/* implements virtual void Object::move() 
   finds and seeks after the nearest grass */
void Lamb::move(){
	Object* nearest_grass = Object::find_nearest_target('G');
	if (nearest_grass == NULL){return;} 
	else {this->seek(nearest_grass);}
}

Lamb::~Lamb(){}
