/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:48:15 by pzubar            #+#    #+#             */
/*   Updated: 2018/06/23 13:48:16 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroids.hpp"

int Asteroids::_asteroidsNum = 0;

Asteroids::Asteroids(void)
{
	std::srand(std::time(0));
	setAsterN(getAsterN() + 1);
}

Asteroids::Asteroids(Asteroids const &other)
{
	*this = other;
}

Asteroids::~Asteroids(void) {}

Asteroids	&Asteroids::operator=( Asteroids const &rfs ) {
	this->_xMax = rfs._xMax;
	this->_yMax = rfs._yMax;
	this->_asteroidsNum = rfs._asteroidsNum;
	this->_isDisp = rfs._isDisp;
	return *this;
}

void Asteroids::deletePath(void)
{
	mvwaddstr(getWindow(), getYPos(), getXPos(), "   ");
}

void Asteroids::display(void)
{
	start_color();
	init_pair(10, COLOR_BLUE, COLOR_WHITE);
	wattron(getWindow(), A_REVERSE);
	wattron(getWindow(), COLOR_PAIR(10));
	mvwaddstr(getWindow(), getYPos(), getXPos(), " @ ");
	wattroff(getWindow(), COLOR_PAIR(10));
	wattroff(getWindow(), A_REVERSE);
	_isDisp = 1;
}

void Asteroids::mvdown(void)
{
	if (!_isDisp)
		return;
	this->deletePath();
	int y = getYPos();
	y += 1;
	if (y > this->_yMax - 2)
	{
		this->deletePath();
		this->initObject(getWindow());
		return;
	}
	setYPos(y);
	this->display();
}

void Asteroids::initObject(WINDOW *win)
{
	_win = win;
	_isDisp = 0;
	getmaxyx(getWindow(), this->_yMax, this->_xMax);
	setXPos(rand() % this->_xMax + 2);
	setYPos(3);
	setSizeX(3);
	setSizeY(1);
}
