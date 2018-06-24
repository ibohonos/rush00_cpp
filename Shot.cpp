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

Shot::Shot(void)
{
	shotsNum++;
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

void	Shot::checkCollision(Enemy * enems)
{
	for (int i = 0; i < _enemiesNum; i++)
	{
		if ((enems[i].getXPos() == this->getXPos()) && (enems[i].getYPos() == this->getYPos()))
		{
			enems[i].deletePath();
			enems[i].initObject(getWindow());
			this->initObject(getWindow());
			this->deletePath();
		}

	}
}
