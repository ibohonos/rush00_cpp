#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Objects.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

int main(void)
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	int yMax, xMax;
	int time = 0;
	int msecs = 0;
	nodelay(stdscr, true);
	keypad(stdscr, TRUE);
	//Функция, определяет макс х та у залежно від розміра вікна
	getmaxyx(stdscr, yMax, xMax);

	WINDOW * playerwin = newwin(yMax - 1, xMax - 1, 0, 0);

	//Малюємо рамочку, оновлюємо вікно
	box(playerwin, 0, 0);
	refresh();
	wrefresh(playerwin);

	//Створюємо гравця
	Player *p = new Player(playerwin, yMax - 3, 1, 1, 3, "Player");
	
	Enemy *w = new Enemy(playerwin, 5, 10, 1, 3, "enemy");

	//Ду-вайл, щоб була перша

	//
	int esc;
	while (1)
	{
		mvwprintw(playerwin, 2, 2,"Time: %d\n", time);
		p->display();
		w->display();
		wrefresh(playerwin);
		usleep(50000); //usleep(1000000); - секунда
		msecs++;
		if (!(msecs % 20))
			time++;
		if (p->getmv() == 'x')
			break ;
		while ((esc = getch()) > -1 && esc != 27 && esc != ' ');
	}
	endwin();
	return(0);
}
