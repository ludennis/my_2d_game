#include "Sheep.h"

Sheep::Sheep(){}

Sheep::Sheep(int y, int x, vector< vector<Object*> >* g):Object('S',2,y,x,g){}

void Sheep::move(){
	// finds nearest grass
	Object* nearest_grass = Object::find_nearest_target('G');

	// if no grass then idle
	// else moves toward it
	if (nearest_grass == NULL){
		return;
	} else {
		this->seek(nearest_grass);
	}
	

	
}

Sheep::~Sheep(){}