#include "Sheep.h"

Sheep::Sheep(){}

Sheep::Sheep(int y, int x, vector< vector<Object*> >* g):Object('S',2,y,x,g){}

void Sheep::move(){
	// finds nearest grass
	int shortest_distance = grid->size() * 2;
	int grass_y = -1;
	int grass_x = -1;

	for (int yy=0; yy<grid->size();++yy){
		for (int xx=0; xx<(*grid)[0].size();++xx){
			if((*grid)[yy][xx]!=NULL && ((*grid)[yy][xx])->get_name()=='G'){
				int distance = this->distance_from((*grid)[yy][xx]);
				if (distance < shortest_distance) {
					shortest_distance = distance;
					grass_y = yy;
					grass_x = xx;
				}
			}
		}
	}

	// if no grass then idle
	// else moves toward it
	if (grass_y < 0 || grass_x < 0){
		return;
	} else {
		int prev_x = x;
		int prev_y = y;

		for (int i=0; i<range;++i){
			if (y > grass_y){
				if (y-1>=0 && (*grid)[y-1][x]==NULL) move_u();
			}
			else if (y < grass_y){
				if (y+1<20 && (*grid)[y+1][x]==NULL) move_d();
			}
			else if (x > grass_x){
				if (x-1>=0 && (*grid)[y][x-1]==NULL) move_l();
			} 
			else if (x < grass_x){
				if (x+1<20 and (*grid)[y][x+1]==NULL) move_r();
			}
		}
		if (prev_x == x && prev_y == y) return;
		else {
			(*grid)[y][x]=(*grid)[prev_y][prev_x];
			(*grid)[prev_y][prev_x]=NULL;	
		}
		this->moved = true;
	}
	

	
}

Sheep::~Sheep(){}