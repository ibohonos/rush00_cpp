#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <ncurses.h>

class Player
{
  public:
	Player(WINDOW *win, int yc, int xc, char c);

	void mvup();
	void mvdown();
	void mvleft();
	void mvright();
	int getmv();
	void display();

  private:
	int x, y, xMax, yMax;
	char character;
	WINDOW *curwin;
	void _deletePath();
};

Player::Player(WINDOW *win, int yc, int xc, char c)
{
	curwin = win;
	y = yc;
	x = xc;
	getmaxyx(curwin, yMax, xMax);
	keypad(curwin, true);
	character = c;
}

void Player::mvup()
{
	_deletePath();
	y -= 1;
	if (y < 1)
		y = 1;
}

void Player::mvdown()
{
	_deletePath();
	y += 1;
	if (y > yMax - 2)
		y = yMax - 2;
}

void Player::mvleft()
{
	_deletePath();
	x -= 1;
	if (x < 1)
		x = 1;
}

void Player::mvright()
{
	_deletePath();
	x += 1;
	if (x > xMax - 1)
		x = xMax - 1;
}

int Player::getmv()
{
	int choice = wgetch(stdscr);
	// if (choice)
		// mvprintw(y/2, x/2, "Keycode: %d, and the character %c", choice, choice);
        // mvprintw(y/2, x/2, "Keycode: %d, and the character %c", c, c);
	// 
	switch (choice)
	{
	case KEY_UP:
		mvup();
		break;
	case KEY_DOWN:
		mvdown();
		break;
	case KEY_LEFT:
		mvleft();
		break;
	case KEY_RIGHT:
		mvright();
		break;
	// case KEY_ESCAPE:
	// 	mvright();
	// 	break;
	case 32: //probel
		mvup();
		break;
	default:
		break;
	}
	// // nodelay(stdscr,false);
	return (choice);
}

void Player::_deletePath(void) //можна заюзать, коли попадаєш
{
	mvwaddstr(curwin, y, x, "   ");
}

void Player::display()
{
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_WHITE);
	wattron(curwin, A_REVERSE);
	wattron(curwin, COLOR_PAIR(1));
	mvwaddstr(curwin, y, x, " M ");
	wattroff(curwin, COLOR_PAIR(1));
	wattroff(curwin, A_REVERSE);
}

	/*
display::Shot
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	wattron(curwin, COLOR_PAIR(1));
	mvwaddstr(curwin, y, x, "-");
	wattroff(curwin, COLOR_PAIR(1));
}

display::Enemy
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	wattron(curwin, A_REVERSE);
	wattron(curwin, COLOR_PAIR(1));
	mvwaddstr(curwin, y, x, " ");
	wattroff(curwin, COLOR_PAIR(1));
	wattroff(curwin, A_REVERSE);
}
*/

#endif