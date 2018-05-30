#ifndef PANEL_H
#define PANEL_H

class Panel {
	int round;
	int grass_eaten;
	int lamb_fed;
	int sheep_fed;
	int lamb_eaten;
	int sheep_eaten;
	int wolf_eaten;
	int score;

public:
	Panel();

	int get_grass_eaten();
	int get_lamb_fed();
	int get_sheep_fed();
	int get_lamb_eaten();
	int get_sheep_eaten();
	int get_wolf_eaten();
	int get_score();
	int get_round();

	void inc_grass_eaten();
	void inc_lamb_fed();
	void inc_sheep_fed();
	void inc_lamb_eaten();
	void inc_sheep_eaten();
	void inc_wolf_eaten();
	void inc_round();
	void inc_score(int);

	~Panel();
};

#endif