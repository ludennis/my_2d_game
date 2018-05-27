
#include "Lamb.h"

Lamb::Lamb(int y, int x, vector< vector<char> >* g):Object('L',1,y,x,g){}

void Lamb::move(vector<Grass> grass, int max_y, int max_x){
	//find nearest grass
	vector<Grass>::iterator shortest = grass.begin();
	for (vector<Grass>::iterator itr = grass.begin(); itr!=grass.end();itr++){
		if (this->distance_from(*itr) < this->distance_from(*shortest)){
			shortest = itr;
		}
	}

	Grass nearest_obj = *shortest;
	for (int i=0 ; i < this->get_range(); i++){
		if (this->distance_from(nearest_obj) == 1) {break;}
		else if (nearest_obj.get_x() - this->get_x() > 0){
			this->move_r();
		} else if (nearest_obj.get_x() - this->get_x() < 0){
			this->move_l();
		} else if (nearest_obj.get_y() - this->get_y() < 0){
			this->move_u();
		} else if (nearest_obj.get_y() - this->get_y() > 0){
			this->move_d();
		}
	}
}

Lamb::~Lamb(){}
