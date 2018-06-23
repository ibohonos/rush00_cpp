#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Objects.hpp"
#include "Player.hpp"

int main(void)
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	int yMax, xMax;

	int time = 0;
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
	Player *w = new Player(playerwin, 5, 10, 1, 3, "ship");

	//Ду-вайл, щоб була перша

	//

	while (1)
	{
		mvwprintw(playerwin, 2, 2,"Time: %d\n",time);
		p->display();
		w->display();
		wrefresh(playerwin);
		usleep(100000);
		time++;
		if (p->getmv() == 'x')
			break ;
	}
	
	// do {
	// 	mvwprintw(playerwin, 2, 2,"Time: %d\n",time);
	// 		p->display();
	// 	wrefresh(playerwin);
	// 	usleep(100000);
	// 	time++;
	// } while(p->getmv()!= 'x');

	// getch();
	endwin();
	return(0);
}
