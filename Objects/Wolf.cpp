
#include "Wolf.h"

Wolf::Wolf(){}
Wolf::Wolf(int y, int x, vector< vector<Object*> >* g,Panel* p): Object('W',3,y,x,g,p){
	this->sheep_eaten=0;
	this->lamb_eaten=0;
}

void Wolf::attack(){
	//finds nearest sheep
	Object* nearest_sheep = find_nearest_target('S');
	Object* nearest_lamb = find_nearest_target('L');

	// attack, priority given to attack lamb first
	if (nearest_lamb != NULL && distance_from(nearest_lamb)==1){
		(*grid)[nearest_lamb->get_y()][nearest_lamb->get_x()] = NULL;
		delete nearest_lamb;
		this->set_done(true);
		this->panel->inc_lamb_eaten();
		this->inc_lamb_eaten();
	} else if(nearest_sheep != NULL && distance_from(nearest_sheep)==1){
		(*grid)[nearest_sheep->get_y()][nearest_sheep->get_x()] = NULL;
		delete nearest_sheep;
		this->set_done(true);
		this->panel->inc_sheep_eaten();
		this->inc_sheep_eaten();
	} 

	// wolf leaves after eating 3 lamb/sheep
	if (this->get_lamb_eaten() + this->get_sheep_eaten() >= 3){
		(*grid)[this->get_y()][this->get_x()] = NULL;
		delete this;
	}
}

void Wolf::move(){
	Object* nearest_sheep = find_nearest_target('S');
	Object* nearest_lamb = find_nearest_target('L');

	if (nearest_sheep != NULL && nearest_lamb == NULL){Object::seek(nearest_sheep);}
	else if (nearest_sheep == NULL && nearest_lamb != NULL){Object::seek(nearest_lamb);}
	else if (nearest_sheep != NULL && nearest_lamb != NULL){
		if (distance_from(nearest_sheep) < distance_from(nearest_lamb)){
			Object::seek(nearest_sheep);
		} else {Object::seek(nearest_lamb);}
	} else {
		// no lamb nor sheep, wolf leaves
		(*grid)[this->get_y()][this->get_x()] = NULL;
		delete this;
	}
}

int Wolf::get_lamb_eaten(){return this->lamb_eaten;}
int Wolf::get_sheep_eaten(){return this->sheep_eaten;}

void Wolf::inc_lamb_eaten(){this->lamb_eaten+=1;}
void Wolf::inc_sheep_eaten(){this->sheep_eaten+=1;}

Wolf::~Wolf(){}
