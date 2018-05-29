
#include "Grass.h"

Grass::Grass(int y, int x,vector< vector<Object*> >* g,Panel* p):Object('G',0,y,x,g,p){}

void Grass::move(){return;}

Grass::~Grass(){
	this->panel->inc_grass_eaten();
}