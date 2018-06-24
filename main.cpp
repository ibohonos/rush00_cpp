#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "Objects.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Shot.hpp"
#include "Asteroids.hpp"
#include "Stars.hpp"

static int ENEM_NUM = 150;
static int ASTEROIDS_NUM = 50;
static int SHOTS_NUM = 100;
static int STARS_NUM = 500;

void draw_borders(WINDOW *win)
{
	int x, y, i;

	getmaxyx(win, y, x);

	start_color();
	init_pair(3, COLOR_WHITE, COLOR_WHITE);
	wattron(win, A_REVERSE);
	wattron(win, COLOR_PAIR(3));
	for (i = 0; i < (y); i++)
	{
		mvwprintw(win, i, 0, " ");
		mvwprintw(win, i, x - 1, " ");
	}
	for (i = 0; i < (x); i++)
	{
		mvwprintw(win, 0, i, " ");
		mvwprintw(win, y - 1, i, " ");
	}
	wattroff(win, COLOR_PAIR(3));
	wattroff(win, A_REVERSE);
}

int main(void)
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	int yMax, xMax;
	int time = 0;
	int phase = 0;
	int ahase = 0;
	int sthase = 0;
	int msecs = 0;
	nodelay(stdscr, true);
	keypad(stdscr, true);
	getmaxyx(stdscr, yMax, xMax);

	WINDOW * playerwin = newwin(yMax - 1, xMax - (xMax*0.3), 0, 0);
	Enemy w[ENEM_NUM];
	Asteroids a[ASTEROIDS_NUM];
	Stars star[STARS_NUM];
	Shot s[SHOTS_NUM];
	Player p(playerwin, w, a, star);
	for(int i = 0; i < ENEM_NUM; i++)
		w[i].initObject(playerwin);
	for(int i = 0; i < ASTEROIDS_NUM; i++)
		a[i].initObject(playerwin);
	for(int i = 0; i < SHOTS_NUM; i++)
		s[i].initObject(playerwin);
	for(int i = 0; i < STARS_NUM; i++)
		star[i].initObject(playerwin);
	
	p.setShots(s);
	int esc;

	int button;

	while (42)
	{
		draw_borders(playerwin);
		// mvwprintw(playerwin, 2, 2,"Time: %d\n", time);
		mvprintw(2, xMax*0.7 + 2, "Time: %d\n", time);
		mvprintw(3, xMax*0.7 + 2, "Lives: %d\n", p.getLives());
		
		p.display();
		
		wrefresh(playerwin);
		//usleep(1000000); - секунда
		
		if (!(msecs % 2)) {
			for (int i = 0; i < SHOTS_NUM; i++)
					s[i].move();
			// for (int i = 0; i < (STARS_NUM / (yMax / 2)); i++)
			// {
			// 	// mvwprintw(playerwin, 2, 2,"Time: %d\n", i);
			// 	int l = sthase + i;
			// 	star[l].display();
			// }
			// sthase += STARS_NUM / (yMax / 2);
			// if (sthase >= STARS_NUM)
			// 	sthase = 0;
		}
		if (!(msecs % 25))
		{
			for (int i = 0; i < (ENEM_NUM / (yMax / 2)); i++)
			{
				// mvwprintw(playerwin, 2, 2,"Time: %d\n", i);
				int n = phase + i;
				w[n].display();
			}
			phase += ENEM_NUM / (yMax / 2);
			if (phase >= ENEM_NUM)
				phase = 0;
			
		}
		if (!(msecs % 5))
		{
			for (int i = 0; i < ENEM_NUM; i++)
				w[i].mvdown();
			for (int i = 0; i < ASTEROIDS_NUM; i++)
				a[i].mvdown();
		}
		for (int i = 0; i < STARS_NUM; i++)
				star[i].mvdown();
		if (!(msecs % 15)) {
			for (int i = 0; i < (ASTEROIDS_NUM / (yMax / 2)); i++)
			{
				// mvwprintw(playerwin, 2, 2,"Time: %d\n", i);
				int k = ahase + i;
				a[k].display();
			}
			ahase += ASTEROIDS_NUM / (yMax / 2);
			if (ahase >= ASTEROIDS_NUM)
				ahase = 0;
		}
		if (!(msecs % 20))
		{
			time++;
		}
		if (!(msecs % 40))
		{
			for (int i = 0; i < (STARS_NUM / (yMax / 2)); i++)
			{
				// mvwprintw(playerwin, 2, 2,"Time: %d\n", i);
				int l = sthase + i;
				star[l].display();
			}
			sthase += STARS_NUM / (yMax / 2);
			if (sthase >= STARS_NUM)
				sthase = 0;
			msecs = 0;
		}
		
		button = p.getmv();
		if (button == (int)'x')
			break ;
		else if (button == 32)
			p.shot();
		for(int i = 0; i < SHOTS_NUM; i++)
			s[i].checkCollision(w, a);
		msecs++;
		while ((esc = getch()) > -1 && esc != 27 && esc != ' ');
		usleep(50000);
	}
	endwin();
	return(0);
}
