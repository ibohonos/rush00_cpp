/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shot.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:48:43 by pzubar            #+#    #+#             */
/*   Updated: 2018/06/24 15:48:45 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shot.hpp"

int Shot::shotsNum = 0;
int Shot::_score = 0;

Shot::Shot(void)
{
	shotsNum++;
}

Shot::Shot(Shot const &other) {
	*this = other;
}

Shot::~Shot(void) {}

Shot		&Shot::operator=( Shot const &rfs )
{
	this->_xMax = rfs._xMax;
	this->_yMax = rfs._yMax;
	this->_isDisp = rfs._isDisp;
	return *this;
}

int 	Shot::getScore(void)
{
	return Shot::_score; 
}

void		Shot::setScore(int n)
{
	Shot::_score = n;
}


void Shot::deletePath(void)
{
	mvwaddstr(getWindow(), getYPos(), getXPos(), " ");
}

void Shot::display(void)
{
	start_color();
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	wattron(getWindow(), COLOR_PAIR(4));
	mvwaddstr(getWindow(), getYPos(), getXPos(), "-");
	wattroff(getWindow(), COLOR_PAIR(4));
	_isDisp = 1;
}

void Shot::move(void)
{
	if (!_isDisp)
	 	return;
	this->deletePath();
	int y = getYPos();
	y -= 1;
	if (y < 2)
	{
		setYPos(0);
		setXPos(0);
		this->display();
		this->initObject(getWindow());
		return;
	}
	setYPos(y);
	this->display();
}

void Shot::initObject(WINDOW *win)
{
	_win = win;
	_isDisp = 0;
	getmaxyx(getWindow(), this->_yMax, this->_xMax);
	// setXPos(rand() % this->_xMax + 3);
	// setYPos(3);
	setSizeX(1);
	setSizeY(1);
}

bool Shot::getIsDisp(void)
{
	return _isDisp;
}


void	Shot::checkCollision(Enemy *enems, Asteroids *aster)
{
	for (int i = 0; i < _enemiesNum; i++)
	{
		if ((enems[i].getXPos() == this->getXPos()) && (enems[i].getYPos() == this->getYPos()))
		{
			enems[i].deletePath();
			enems[i].initObject(getWindow());
			this->initObject(getWindow());
			this->deletePath();
			setScore(getScore() + 5);
		}
	}
	for (int i = 0; i < _asteroidsNum; i++)
	{
		if ((aster[i].getXPos() == this->getXPos()) && (aster[i].getYPos() == this->getYPos()))
		{
			aster[i].deletePath();
			aster[i].initObject(getWindow());
			this->initObject(getWindow());
			this->deletePath();
		}
		if ((aster[i].getXPos() + 1 == this->getXPos()) && (aster[i].getYPos() == this->getYPos()))
		{
			aster[i].deletePath();
			aster[i].initObject(getWindow());
			this->initObject(getWindow());
			this->deletePath();
		}
		if ((aster[i].getXPos() + 2 == this->getXPos()) && (aster[i].getYPos() == this->getYPos()))
		{
			aster[i].deletePath();
			aster[i].initObject(getWindow());
			this->initObject(getWindow());
			this->deletePath();
		}
	}
}
