
#include "Wolf.h"

Wolf::Wolf(){}
Wolf::Wolf(int y, int x, vector< vector<Object*> >* g): Object('W',3,y,x,g){}

void Wolf::attack(){
	//finds nearest sheep
	Object* nearest_sheep = find_nearest_target('S');
	Object* nearest_lamb = find_nearest_target('L');

	if(nearest_sheep != NULL && distance_from(nearest_sheep)==1){
		(*grid)[nearest_sheep->get_y()][nearest_sheep->get_x()] = NULL;
		delete nearest_sheep;
		this->set_done(true);
	} else if (nearest_lamb != NULL && distance_from(nearest_lamb)==1){
		(*grid)[nearest_lamb->get_y()][nearest_lamb->get_x()] = NULL;
		delete nearest_lamb;
		this->set_done(true);
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
	}
}

Wolf::~Wolf(){}
