#include "Object.h"

Object::Object(){}

Object::Object(char n, int r, int y, int x):name(n),range(r),y(y),x(x){
	this->name = n;
	this->range = r;
	this->y = y;
	this->x = x;
}

char Object::get_name(){return name;}

void Object::set_name(char c){name = c;}

Object* Object::get(){return this;}

Object::~Object(){}