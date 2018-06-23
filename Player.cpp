#include "Objects.hpp"
#include "Player.hpp"

Player::Player(void) {}

Player::Player(WINDOW *win, int yPos, int xPos, int sizeY, int sizeX, std::string type) {
	// Objects		*player = new Objects(type, win);

	// this->object = player;
	_win = win;
	_type = type;
	setXPos(xPos);
	setYPos(yPos);
	setSizeX(sizeX);
	setSizeY(sizeY);
	getmaxyx(getWindow(), this->_yMax, this->_xMax);
	keypad(getWindow(), true); 
}

void		Player::deletePath(void)
{
	mvwaddstr(getWindow(), getYPos(), getXPos(), "   ");
}

void		Player::display(void)
{
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_WHITE);
	wattron(getWindow(), A_REVERSE);
	wattron(getWindow(), COLOR_PAIR(1));
	mvwaddstr(getWindow(), getYPos(), getXPos(), " M ");
	wattroff(getWindow(), COLOR_PAIR(1));
	wattroff(getWindow(), A_REVERSE);
}

void		Player::mvup()
{
	this->deletePath();
	int y = getYPos();
	y -= 1;
	if (y < 1)
		y = 1;
	setYPos(y);
}

void		Player::mvdown()
{
	this->deletePath();
	int y = getYPos();
	y += 1;
	if (y > this->_yMax - 2)
		y = this->_yMax - 2;
	setYPos(y);
}

void		Player::mvleft()
{
	this->deletePath();
	int x = getXPos();
	x -= 1;
	if (x < 1)
		x = 1;
	setXPos(x);
}

void		Player::mvright()
{
	this->deletePath();
	int x = getXPos();
	x += 1;
	if (x > this->_xMax - 1)
		x = this->_xMax - 1;
	setXPos(x);
}

int			Player::getmv()
{
	int choice = wgetch(stdscr);
	// if (choice)
		// mvprintw(y/2, x/2, "Keycode: %d, and the character %c", choice, choice);
		// mvprintw(y/2, x/2, "Keycode: %d, and the character %c", c, c);
	// 
	switch (choice)
	{
		case KEY_UP:
			this->mvup();
			break;
		case KEY_DOWN:
			this->mvdown();
			break;
		case KEY_LEFT:
			this->mvleft();
			break;
		case KEY_RIGHT:
			this->mvright();
			break;
		// case KEY_ESCAPE:
		// 	this->mvright();
		// 	break;
		case 32: //probel
			this->mvup();
			break;
		default:
			break;
	}
	// // nodelay(stdscr,false);
	return (choice);
}
