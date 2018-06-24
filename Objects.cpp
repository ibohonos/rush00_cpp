#include "Objects.hpp"

int Objects::_enemiesNum = 0;
int Objects::_asteroidsNum = 0;
int Objects::_shotsNum = 0;
int Objects::_starsNum = 0;

Objects::Objects(void) {}

Objects::Objects(WINDOW *win) : _win(win), _xPos(0), _yPos(0),
		_sizeX(0), _sizeY(0), _color("") {}

Objects::Objects(Objects const &rfs) {
	*this = rfs;
}

Objects::~Objects(void) {}

Objects		&Objects::operator=( Objects const &rfs ) {
	this->_xPos = rfs._xPos;
	this->_yPos = rfs._yPos;
	this->_sizeX = rfs._sizeX;
	this->_sizeY = rfs._sizeY;
	this->_color = rfs._color;
	this->_win = rfs._win;
	this->_enemiesNum = rfs._enemiesNum;
	this->_asteroidsNum = rfs._asteroidsNum;
	this->_starsNum = rfs._starsNum;
	this->_shotsNum = rfs._shotsNum;
	return *this;
}

int			Objects::getXPos(void) {
	return this->_xPos;
}

int			Objects::getYPos(void) {
	return this->_yPos;
}

int			Objects::getSizeX(void) {
	return this->_sizeX;
}

int			Objects::getSizeY(void) {
	return this->_sizeY;
}

int			Objects::getEnemsN(void) {
	return this->_enemiesNum;
}

int			Objects::getAsterN(void) {
	return this->_asteroidsNum;
}

int			Objects::getStarN(void) {
	return this->_starsNum;
}

int				Objects::getShotNum(void) {
	return this->_shotsNum;
}

std::string	Objects::getColor(void) {
	return this->_color;
}

WINDOW		*Objects::getWindow(void) {
	return this->_win;
}

void		Objects::setXPos(int n) {
	this->_xPos = n;
}

void		Objects::setYPos(int n) {
	this->_yPos = n;
}

void		Objects::setSizeX(int n) {
	this->_sizeX = n;
}

void		Objects::setSizeY(int n) {
	this->_sizeY = n;
}

void		Objects::setEnemsN(int n) {
	this->_enemiesNum = n;
}

void		Objects::setAsterN(int n) {
	this->_asteroidsNum = n;
}

void		Objects::setStarN(int n) {
	this->_starsNum = n;
}

void		Objects::setColor(std::string str) {
	this->_color = str;
}

void		Objects::setShotNum(int n) {
	this->_color = n;
}
