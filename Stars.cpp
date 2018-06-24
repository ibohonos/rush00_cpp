/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:48:15 by pzubar            #+#    #+#             */
/*   Updated: 2018/06/23 13:48:16 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stars.hpp"

int Stars::_starsNum = 0;

Stars::Stars(void)
{
	std::srand(std::time(0));
	setStarN(getStarN() + 1);
}


Stars::Stars(Stars const &other) {
	*this = other;
}

Stars::~Stars(void) {}

Stars		&Stars::operator=( Stars const &rfs ) {
	this->_xMax = rfs._xMax;
	this->_yMax = rfs._yMax;
	this->_isDisp = rfs._isDisp;
	this->_starsNum = rfs._starsNum;
	return *this;
}

void Stars::deletePath(void)
{
	mvwaddstr(getWindow(), getYPos(), getXPos(), " ");
}

void Stars::display(void)
{
	start_color();
	init_pair(7, COLOR_BLACK, COLOR_YELLOW);
	wattron(getWindow(), A_REVERSE);
	wattron(getWindow(), COLOR_PAIR(7));
	mvwaddstr(getWindow(), getYPos(), getXPos(), ".");
	wattroff(getWindow(), COLOR_PAIR(7));
	wattroff(getWindow(), A_REVERSE);
	_isDisp = 1;
}

void Stars::mvdown(void)
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

void Stars::initObject(WINDOW *win)
{
	_win = win;
	_isDisp = 0;
	getmaxyx(getWindow(), this->_yMax, this->_xMax);
	setXPos(rand() % this->_xMax + 2);
	setYPos(rand() % this->_yMax + 2);
	setSizeX(1);
	setSizeY(1);
}
