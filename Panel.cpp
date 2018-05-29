
#include "Panel.h"

Panel::Panel(){}

int Panel::get_grass_eaten(){return this->grass_eaten;}
int Panel::get_lamb_fed(){return this->lamb_fed;}
int Panel::get_sheep_fed(){return this->sheep_fed;}
int Panel::get_lamb_eaten(){return this->lamb_eaten;}
int Panel::get_sheep_eaten(){return this->sheep_eaten;}
int Panel::get_wolf_eaten(){return this->wolf_eaten;}
int Panel::get_score(){return this->score;}
int Panel::get_round(){return this->round;}

void Panel::set_grass_eaten(int ge){this->grass_eaten=ge;}
void Panel::set_lamb_fed(int lf){this->lamb_fed=lf;}
void Panel::set_sheep_fed(int sf){this->sheep_fed=sf;}
void Panel::set_lamb_eaten(int le){this->lamb_eaten=le;}
void Panel::set_sheep_eaten(int se){this->sheep_eaten=se;}
void Panel::set_wolf_eaten(int we){this->wolf_eaten=we;}
void Panel::set_score(int s){this->score=s;}
void Panel::inc_round(){this->round+=1;}

Panel::~Panel(){}
