#include "Sheep.h"

Sheep::Sheep(){}

Sheep::Sheep(int y, int x, vector< vector<Object*> >* g):Object('S',2,y,x,g){}

Sheep::~Sheep(){}