#include "Objects.hpp"

Objects::Objects(void) {}

Objects::Objects(std::string type, WINDOW *win) : _type(type), _win(win), _xPos(0), _yPos(0),
		_sizeX(0), _sizeY(0), _color("") {}

Objects::Objects(Objects const &rfs) {
	*this = rfs;
}

Objects::~Objects(void) {
	// delete this->_win;
}

Objects		&Objects::operator=( Objects const &rfs ) {
	this->_xPos = rfs._xPos;
	this->_yPos = rfs._yPos;
	this->_sizeX = rfs._sizeX;
	this->_sizeY = rfs._sizeY;
	this->_color = rfs._color;
	this->_type = rfs._type;
	this->_win = rfs._win;
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

std::string	Objects::getType(void) {
	return this->_type;
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

void		Objects::setColor(std::string str) {
	this->_color = str;
}
