/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:48:15 by pzubar            #+#    #+#             */
/*   Updated: 2018/06/23 13:48:16 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

int Enemy::_enemiesNum = 0;

Enemy::Enemy(void)
{
	std::srand(std::time(0));
	setEnemsN(getEnemsN() + 1);
}

Enemy::Enemy(Enemy const &other)
{
	*this = other;
}

Enemy::~Enemy(void) {}

bool Enemy::getIsDisp(void)
{
	return _isDisp;
}

Enemy	&Enemy::operator=( Enemy const &rfs ) {
	this->_xMax = rfs._xMax;
	this->_yMax = rfs._yMax;
	this->_enemiesNum = rfs._enemiesNum;
	this->_isDisp = rfs._isDisp;
	return *this;
}

void Enemy::deletePath(void)
{
	mvwaddstr(getWindow(), getYPos(), getXPos(), " ");
}

void Enemy::display(void)
{
	start_color();
	init_pair(2, COLOR_RED, COLOR_WHITE);
	wattron(getWindow(), A_REVERSE);
	wattron(getWindow(), COLOR_PAIR(2));
	mvwaddstr(getWindow(), getYPos(), getXPos(), "|");
	wattroff(getWindow(), COLOR_PAIR(2));
	wattroff(getWindow(), A_REVERSE);
	_isDisp = 1;
}

void Enemy::mvdown(void)
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

void Enemy::initObject(WINDOW *win)
{
	_win = win;
	_isDisp = 0;
	getmaxyx(getWindow(), this->_yMax, this->_xMax);
	setXPos(rand() % this->_xMax + 2);
	setYPos(1);
	setSizeX(1);
	setSizeY(1);
}
