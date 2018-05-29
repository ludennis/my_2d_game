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

	void set_grass_eaten(int);
	void set_lamb_fed(int);
	void set_sheep_fed(int);
	void set_lamb_eaten(int);
	void set_sheep_eaten(int);
	void set_wolf_eaten(int);
	void set_score(int);
	void inc_round();

	~Panel();
};

#endif