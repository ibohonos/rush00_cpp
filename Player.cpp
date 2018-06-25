
#include "Player.hpp"

Player::Player(void) {
	setLives(3);
}

Player::Player(WINDOW *win, Enemy *enemies, Asteroids *aster, Stars *star)
{
	_win = win;
	_enems = enemies;
	_aster = aster;
	_star = star;
	getmaxyx(getWindow(), this->_yMax, this->_xMax);
	setXPos(_xMax / 2 - 2);
	setYPos(_yMax / 1.5);

	setSizeX(3);
	setSizeY(1);
	keypad(getWindow(), true);
	setLives(3);
}

Player::Player(Player const &rfs) {
	*this = rfs;
}

Player::~Player(void) {}

Player		&Player::operator=( Player const &rfs )
{
	this->_xMax = rfs._xMax;
	this->_yMax = rfs._yMax;
	this->_enems = rfs._enems;
	this->_star = rfs._star;
	this->_shots = rfs._shots;
	this->_lives = rfs._lives;
	return *this;
}


void		Player::deletePath(void)
{
	mvwaddstr(getWindow(), getYPos(), getXPos(), "     ");
}

void Player::display(void)
{
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	// wattron(getWindow(), A_REVERSE);
	wattron(getWindow(), COLOR_PAIR(1));
	wattron(getWindow(), A_BOLD);
	mvwaddstr(getWindow(), getYPos(), getXPos(), "\\M/");
	wattroff(getWindow(), A_BOLD);
	wattroff(getWindow(), COLOR_PAIR(1));
	// wattroff(getWindow(), A_REVERSE);
	checkCollision();
}

void Player::mvup()
{
	this->deletePath();
	int y = getYPos();
	y -= 1;
	if (y < 1)
		y = 1;
	setYPos(y);
}

void Player::mvdown()
{
	this->deletePath();
	int y = getYPos();
	y += 1;
	if (y > this->_yMax - 2)
		y = this->_yMax - 2;
	setYPos(y);
}

void Player::mvleft()
{
	this->deletePath();
	int x = getXPos();
	x -= 1;
	if (x < 1)
		x = 1;
	setXPos(x);
}

void Player::mvright()
{
	this->deletePath();
	int x = getXPos();
	x += 1;
	if (x > this->_xMax - _sizeX - 1)
		x = this->_xMax - _sizeX - 1;
	setXPos(x);
}

void Player::checkCollision(void)
{
	for (int i = 0; i < _enemiesNum; i++)
	{
		if ((_enems[i].getXPos() == this->getXPos()) && (_enems[i].getYPos() == this->getYPos()))
		{
			_enems[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_enems[i].getXPos() == this->getXPos() + 1) && (_enems[i].getYPos() == this->getYPos()))
		{
			_enems[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_enems[i].getXPos() == this->getXPos() + 2) && (_enems[i].getYPos() == this->getYPos()))
		{
			_enems[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
	}
	for (int i = 0; i < _asteroidsNum; i++)
	{
		if ((_aster[i].getXPos() == this->getXPos()) && (_aster[i].getYPos() == this->getYPos()))
		{
			_aster[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_aster[i].getXPos() == this->getXPos() + 1) && (_aster[i].getYPos() == this->getYPos()))
		{
			_aster[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_aster[i].getXPos() == this->getXPos() + 2) && (_aster[i].getYPos() == this->getYPos()))
		{
			_aster[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_aster[i].getXPos() + 1 == this->getXPos()) && (_aster[i].getYPos() == this->getYPos()))
		{
			_aster[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_aster[i].getXPos() + 1 == this->getXPos() + 1) && (_aster[i].getYPos() == this->getYPos()))
		{
			_aster[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_aster[i].getXPos() + 1 == this->getXPos() + 2) && (_aster[i].getYPos() == this->getYPos()))
		{
			_aster[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_aster[i].getXPos() + 2 == this->getXPos()) && (_aster[i].getYPos() == this->getYPos()))
		{
			_aster[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_aster[i].getXPos() + 2 == this->getXPos() + 1) && (_aster[i].getYPos() == this->getYPos()))
		{
			_aster[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_aster[i].getXPos() + 2 == this->getXPos() + 2) && (_aster[i].getYPos() == this->getYPos()))
		{
			_aster[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
	}
	for (int i = 0; i < _shots->shotsNum; i++)
	{
		if ((_shots[i].getXPos() == this->getXPos()) && (_shots[i].getYPos() == this->getYPos()))
		{
			_shots[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_shots[i].getXPos() == this->getXPos() + 1) && (_shots[i].getYPos() == this->getYPos()))
		{
			_shots[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
		if ((_shots[i].getXPos() == this->getXPos() + 2) && (_shots[i].getYPos() == this->getYPos()))
		{
			_shots[i].initObject(getWindow());
			setLives(getLives() - 1);
			break;
		}
	}
}

int Player::getmv()
{
	int choice = wgetch(stdscr);
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
	case 27:
		exit(1);
		break;
	default:
		break;
	}
	return (choice);
}

int Player::getLives(void)
{
	return this->_lives;
}

void Player::setLives(int n)
{
	this->_lives = n;
}

void Player::shot(void)
{
	int guns;

	guns = 1;
	// system("pkill afplay");
	// system("afplay ~/Desktop/laser.aiff");
	for (int i = 0; i < _shots->shotsNum; i++)
	{
		if (guns)
		{
			if (!_shots[i].getIsDisp())
			{
				_shots[i].setXPos(getXPos());
				_shots[i].setYPos(getYPos() - 1);
				_shots[i].display();
				guns--;
			}
		}
		else
		{
			_shots[i].setXPos(getXPos() + 2);
			_shots[i].setYPos(getYPos() - 1);
			_shots[i].display();
			break;
		}
	}
}

void Player::setShots(Shot *shots)
{
	_shots = shots;
}

bool Player::isAlive(void)
{
	if (this->_lives <= 0)
		return(false);
	return(true);
}

int Player::getHP(void)
{
	return this->_hp;
}


