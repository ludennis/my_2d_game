# include "Console.h"

#define GRASS_COLOR 1
#define SHEEP_COLOR 2
#define LAMB_COLOR 3
#define DOG_COLOR 4
#define WOLF_COLOR 5

Console::Console(int gl, int pl):grid_length(gl),panel_length(pl){}

void Console::init(){
	init_grid();
	init_window();

	panel = new Panel();

	max_grass=15;
	max_sheep_lamb=20;
	max_wolf=1;
	max_dog=1;

	wolf_timer=5;

	//set the seef for random numbers
	srand(time(NULL));

	spawn_multiple('G',5);
	spawn_multiple('S',10);
	spawn_multiple('D',1);

}

void Console::init_grid(){
	grid = new vector< vector<Object*> >();
	grid->resize(grid_length);
	for(int i=0;i<grid_length;i++){
		(*grid)[i].resize(grid_length);
	}

}

void Console::init_window(){
	// get the size of terminal with ioctl
	// terminal line = w.ws_row = y
	// terminal column = w.ws_col = x
	struct winsize w;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&w);

	// initialize curses' windows to be centered according to terminal size
	// g_win should stack on top of p_win
	g_win = newwin(grid_length+2,grid_length*2+1,\
		           (w.ws_row-grid_length)/2-5,(w.ws_col-grid_length*2)/2);
	p_win = newwin(panel_length+2,grid_length*2+1,\
				   (w.ws_row+panel_length)/2+2,(w.ws_col-grid_length*2)/2);
}

void Console::spawn_multiple(char name, int n) {for(int i=0;i<n;i++){spawn(name);}}

void Console::spawn(char name){

	int y = rand()%grid_length;
	int x = rand()%grid_length;

	if ((*grid)[y][x] != NULL){
		y = rand()%grid_length;
		x = rand()%grid_length;
	}

	if(name=='G' && count('G')<max_grass) {
		(*grid)[y][x] = new Grass(y,x,grid,panel);
	} else if (name=='S' && count('S')+count('L')<max_sheep_lamb){
		(*grid)[y][x] = new Sheep(y,x,grid,panel);
	} else if (name=='D' && count('D')<max_dog){
		(*grid)[y][x] = new Dog(y,x,grid,panel);
	} else if (name=='W' && count('W')<max_wolf){
		(*grid)[y][x] = new Wolf(y,x,grid,panel);
	} else if (name=='L' && count('S')+count('L')<max_sheep_lamb){
		(*grid)[y][x] = new Lamb(y,x,grid,panel);
	}

}


void Console::update(){

	panel->inc_round();

	// reset all objects
	for(int y=0;y<grid_length;y++){
		for (int x=0;x<grid_length;x++){
			if ((*grid)[y][x]!=NULL){
				((*grid)[y][x])->set_done(false);
			}
		}
	}

	// attack
	for(int y=0;y<grid_length;y++){
		for (int x=0;x<grid_length;x++){
			if ((*grid)[y][x]!=NULL && !((*grid)[y][x])->is_done()){
				((*grid)[y][x])->attack();
				draw();
			}
		}
	}

	// move
	for(int y=0;y<grid_length;y++){
		for (int x=0;x<grid_length;x++){
			if ((*grid)[y][x]!=NULL && !((*grid)[y][x])->is_done()){
				((*grid)[y][x])->move();
				draw();
			}
		}
	}

	// spawns 5 grass or 3 grass
	if (count('S')+count('L')<10){spawn_multiple('G',5);}
	else {spawn_multiple('G',3);}

	// spawns 2 lamb or 1 lamb
	if (count('S')+count('L')<=10){spawn_multiple('L',2);}
	else {spawn('L');}

	// spawns a wolf at round 6 and every 6-10 round
	if (get_wolf_timer() == 0){
		spawn('W');
		wolf_timer=rand()%5+6;
	} else if (count('W') == 0){
		dec_wolf_timer();
	}
}

void Console::draw(){
	
	//initialize color
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	init_pair(3,COLOR_CYAN,COLOR_BLACK);
	init_pair(4,COLOR_BLUE,COLOR_BLACK);
	init_pair(5,COLOR_RED,COLOR_BLACK);

	// draws border around g_win and p_win
	// check man wborder for detail
	wborder(g_win,0,0,0,0,0,0,0,0);
	wborder(p_win,0,0,0,0,0,0,0,0);

	// draws the grid	
	for (int y = 0; y < grid_length; y++){
		wmove(g_win,y+1,1);
		for (int x = 0; x < grid_length; x++){
			if ((*grid)[y][x]!=NULL){
				char name =((*grid)[y][x])->get_name();
				if (name == 'G') {waddch(g_win, name | COLOR_PAIR(GRASS_COLOR));}
				else if (name == 'L') {waddch(g_win, name | COLOR_PAIR(LAMB_COLOR));}
				else if (name == 'S') {waddch(g_win, name | COLOR_PAIR(SHEEP_COLOR));}
				else if (name == 'D') {waddch(g_win, name | COLOR_PAIR(DOG_COLOR));}
				else if (name == 'W') {waddch(g_win, name | COLOR_PAIR(WOLF_COLOR));}
			} else {
				waddch(g_win,'_');
			}
			
			if (x!=grid_length-1) {waddch(g_win,' ');}
		}
	}

	// draws the panel
	mvwprintw(p_win,1,1,"Round: %d",panel->get_round());
	mvwprintw(p_win,2,1,"Grass Eaten: %d",panel->get_grass_eaten());
	mvwprintw(p_win,3,1,"Lamb Fed: %d",panel->get_lamb_fed());
	mvwprintw(p_win,4,1,"Sheep Fed: %d",panel->get_sheep_fed());
	mvwprintw(p_win,5,1,"Lamb Eaten: %d",panel->get_lamb_eaten());
	mvwprintw(p_win,6,1,"Sheep Eaten: %d",panel->get_sheep_eaten());
	mvwprintw(p_win,7,1,"Wolf Eaten: %d",panel->get_wolf_eaten());
	mvwprintw(p_win,8,1,"Score: %d",panel->get_score());

	//shows other info on the left side
	mvwprintw(stdscr,10,10,"Number of Grass: %d (max: %d)",count('G'),max_grass);
	mvwprintw(stdscr,11,10,"Number of Sheep: %d (max: %d)",count('S'),max_sheep_lamb);
	mvwprintw(stdscr,12,10,"Number of Lamb:  %d (max: %d)",count('L'),max_sheep_lamb);
	mvwprintw(stdscr,13,10,"Number of Dog:   %d (max: %d)",count('D'),max_dog);
	mvwprintw(stdscr,14,10,"Number of Wolf:  %d (max: %d)",count('W'),max_wolf);
	mvwprintw(stdscr,15,10,"Wolf timer: %d ", get_wolf_timer());

	//refresh window to show modification
	wrefresh(g_win);
	wrefresh(p_win);

}


int Console::get_round(){return this->panel->get_round();}
int Console::get_wolf_timer(){return this->wolf_timer;}
void Console::dec_wolf_timer(){this->wolf_timer-=1;}

int Console::count(char name){
	int n = 0;
	for (int y=0; y<grid_length;y++){
		for (int x=0; x<grid_length;x++){
			if ((*grid)[y][x]!=NULL && ((*grid)[y][x])->get_name()==name) n++;
		}
	}
	return n;
}

Console::~Console(){}