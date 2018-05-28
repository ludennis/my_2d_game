# include "Console.h"

Console::Console(int gl, int pl):grid_length(gl),panel_length(pl){}

void Console::init(){
	init_grid();
	init_window();

	//set the seef for random numbers
	srand(time(NULL));

	for (int i=0; i<5; i++){
		int x = rand()%grid_length;
		int y = rand()%grid_length;	
		spawn_at('G',y,x);
	}

	for (int i=0; i<10; i++){
		int x = rand()%grid_length;
		int y = rand()%grid_length;
		spawn_at('S',y,x);
	}
}

void Console::init_grid(){
	grid = new vector< vector<Object*> >();
	grid->resize(grid_length);
	for(int i=0;i<grid_length;i++){
		(*grid)[i].resize(grid_length);
	}

}

/*
	initialize the displaying windows of grid and panel
*/
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

void Console::spawn_at(char name, int y, int x){
	if(name=='G') {
		Grass* g = new Grass(y,x,grid);
		grass.push_back(g);
		(*grid)[y][x] = grass.back();
	} else if (name=='S'){
		Sheep* s = new Sheep(y,x,grid);
		sheep.push_back(s);
		(*grid)[y][x] = sheep.back();
	}

}


void Console::update(){

	round++;

	for(int y=0;y<grid_length;y++){
		for (int x=0;x<grid_length;x++){
			if ((*grid)[y][x]!=NULL){
				((*grid)[y][x])->set_moved(false);
			}
		}
	}

	for(int y=0;y<grid_length;y++){
		for (int x=0;x<grid_length;x++){
			if ((*grid)[y][x]!=NULL and !((*grid)[y][x])->has_moved()){
				((*grid)[y][x])->move();
			}
		}
	}
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


Console::~Console(){}