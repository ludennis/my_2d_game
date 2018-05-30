
#include "Panel.h"

Panel::Panel(){
	this->round=0;
	this->grass_eaten=0;
	this->lamb_fed=0;
	this->sheep_fed=0;
	this->lamb_eaten=0;
	this->sheep_eaten=0;
	this->wolf_eaten=0;
	this->score=0;
}

int Panel::get_grass_eaten(){return this->grass_eaten;}
int Panel::get_lamb_fed(){return this->lamb_fed;}
int Panel::get_sheep_fed(){return this->sheep_fed;}
int Panel::get_lamb_eaten(){return this->lamb_eaten;}
int Panel::get_sheep_eaten(){return this->sheep_eaten;}
int Panel::get_wolf_eaten(){return this->wolf_eaten;}
int Panel::get_score(){return this->score;}
int Panel::get_round(){return this->round;}

void Panel::inc_grass_eaten(){++grass_eaten;}
void Panel::inc_lamb_fed(){++lamb_fed;}
void Panel::inc_sheep_fed(){++sheep_fed;}
void Panel::inc_lamb_eaten(){++lamb_eaten;}
void Panel::inc_sheep_eaten(){++sheep_eaten;}
void Panel::inc_wolf_eaten(){++wolf_eaten;}
void Panel::inc_score(int s){this->score+=s;}
void Panel::inc_round(){++round;}

Panel::~Panel(){}
