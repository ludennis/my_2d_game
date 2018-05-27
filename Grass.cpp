
#include "Grass.h"

Grass::Grass(int y, int x,vector< vector<Object*> >* g):Object('G',0,y,x,g){}

void Grass::move(){return;}

Grass::~Grass(){}