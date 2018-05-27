# include "Console.h"

Console::Console(int gl, int pl):grid_length(gl),panel_length(pl){}

void Console::init(){
	init_grid();
	init_window();
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

void Console::init_grid(){
	Object* dummy = new Object('_',0,0,0);
	grid = vector< vector<Object*> >(grid_length, vector<Object*>(grid_length,dummy));
}

void Console::draw(){
	
	// draws border around g_win and p_win
	// check man wborder for detail
	wborder(g_win,0,0,0,0,0,0,0,0);
	wborder(p_win,0,0,0,0,0,0,0,0);

	// draws the grid	
	for (int y = 0; y < grid_length; y++){
		// moves cursor to within the border before drawing
		wmove(g_win,y+1,1);
		//draws the grid within border
		for (int x = 0; x < grid_length; x++){
			waddch(g_win,(grid[y][x])->get_name());
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