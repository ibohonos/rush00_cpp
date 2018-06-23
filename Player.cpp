#include "Objects.hpp"
#include "Player.hpp"

Player::Player(void) {}

Player::Player(WINDOW *win, int yPos, int xPos, int sizeY, int sizeX, std::string type) {
	Objects		*player = new Objects(type, win);

	this->object = player;
	this->object->setXPos(xPos);
	this->object->setYPos(yPos);
	this->object->setSizeX(sizeX);
	this->object->setSizeY(sizeY);
	getmaxyx(this->object->getWindow(), this->_yMax, this->_xMax);
	keypad(this->object->getWindow(), true); 
}

void		Player::deletePath(void) {
	mvwaddstr(this->object->getWindow(), this->object->getYPos(), this->object->getXPos(), "   ");
}

void		Player::display(void)
{
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_WHITE);
	wattron(this->object->getWindow(), A_REVERSE);
	wattron(this->object->getWindow(), COLOR_PAIR(1));
	mvwaddstr(this->object->getWindow(), this->object->getYPos(), this->object->getXPos(), " M ");
	wattroff(this->object->getWindow(), COLOR_PAIR(1));
	wattroff(this->object->getWindow(), A_REVERSE);
}

void		Player::mvup()
{
	this->deletePath();
	int y = this->object->getYPos();
	y -= 1;
	if (y < 1)
		y = 1;
	this->object->setYPos(y);
}

void		Player::mvdown()
{
	this->deletePath();
	int y = this->object->getYPos();
	y += 1;
	if (y > this->_yMax - 2)
		y = this->_yMax - 2;
	this->object->setYPos(y);
}

void		Player::mvleft()
{
	this->deletePath();
	int x = this->object->getXPos();
	x -= 1;
	if (x < 1)
		x = 1;
	this->object->setXPos(x);
}

void		Player::mvright()
{
	this->deletePath();
	int x = this->object->getXPos();
	x += 1;
	if (x > this->_xMax - 1)
		x = this->_xMax - 1;
	this->object->setXPos(x);
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
