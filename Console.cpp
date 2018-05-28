# include "Console.h"

Console::Console(int gl, int pl):grid_length(gl),panel_length(pl){}

void Console::init(){
	init_grid();
	init_window();

	max_grass=15;
	max_sheep_lamb=20;
	max_wolf=1;
	max_dog=1;

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

/* initialize the displaying windows of grid and panel */
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
		(*grid)[y][x] = new Grass(y,x,grid);
	} else if (name=='S' && count('S')<max_sheep_lamb){
		(*grid)[y][x] = new Sheep(y,x,grid);
	} else if (name=='D' && count('D')<max_dog){
		(*grid)[y][x] = new Dog(y,x,grid);
	} else if (name=='W' && count('W')<max_wolf){
		(*grid)[y][x] = new Wolf(y,x,grid);
	}

}


void Console::update(){

	round++;

	// reset all objects
	for(int y=0;y<grid_length;y++){
		for (int x=0;x<grid_length;x++){
			if ((*grid)[y][x]!=NULL){
				((*grid)[y][x])->set_done(false);
			}
		}
	}

	// attack or move
	for(int y=0;y<grid_length;y++){
		for (int x=0;x<grid_length;x++){
			if ((*grid)[y][x]!=NULL && !((*grid)[y][x])->is_done()){
				((*grid)[y][x])->attack();
			}
			if ((*grid)[y][x]!=NULL && !((*grid)[y][x])->is_done()){
				((*grid)[y][x])->move();
			}
		}
	}

	// allocating more objects
	//if (count('S')<10){spawn_multiple('G',5);}
	//else {spawn_multiple('G',3);}

	if(round==6){spawn('W');}

}

void Console::draw(){
	
	// draws border around g_win and p_win
	// check man wborder for detail
	wborder(g_win,0,0,0,0,0,0,0,0);
	wborder(p_win,0,0,0,0,0,0,0,0);

	// draws the grid	
	for (int y = 0; y < grid_length; y++){
		wmove(g_win,y+1,1);
		for (int x = 0; x < grid_length; x++){
			if ((*grid)[y][x]!=NULL){
				waddch(g_win,((*grid)[y][x])->get_name());	
			} else {
				waddch(g_win,'_');
			}
			
			if (x!=grid_length-1) {waddch(g_win,' ');}
		}
	}

	// draws the panel
	wmove(p_win,1,1);
	wprintw(p_win,"Round: %d",round);

	//refresh window to show modification
	wrefresh(g_win);
	wrefresh(p_win);

}

int Console::get_round(){return this->round;}
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