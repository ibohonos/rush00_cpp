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

#include "Objects.hpp"
#include "Enemy.hpp"

Enemy::Enemy(void) {}

Enemy::Enemy(WINDOW *win, int yPos, int xPos, int sizeY, int sizeX, std::string type) {
	_win = win;
	_type = type;
	setXPos(xPos);
	setYPos(yPos);
	setSizeX(sizeX);
	setSizeY(sizeY);
	getmaxyx(getWindow(), this->_yMax, this->_xMax);
	keypad(getWindow(), true); 
}

void		Enemy::deletePath(void)
{
	mvwaddstr(getWindow(), getYPos(), getXPos(), "   ");
}

void		Enemy::display(void)
{
	start_color();
	init_pair(2, COLOR_RED, COLOR_WHITE);
	wattron(getWindow(), A_REVERSE);
	wattron(getWindow(), COLOR_PAIR(2));
	mvwaddstr(getWindow(), getYPos(), getXPos(), " M ");
	wattroff(getWindow(), COLOR_PAIR(2));
	wattroff(getWindow(), A_REVERSE);
}

void		Enemy::mvup()
{
	this->deletePath();
	int y = getYPos();
	y -= 1;
	if (y < 1)
		y = 1;
	setYPos(y);
}

void		Enemy::mvdown()
{
	this->deletePath();
	int y = getYPos();
	y += 1;
	if (y > this->_yMax - 2)
		y = this->_yMax - 2;
	setYPos(y);
}

void		Enemy::mvleft()
{
	this->deletePath();
	int x = getXPos();
	x -= 1;
	if (x < 1)
		x = 1;
	setXPos(x);
}

void		Enemy::mvright()
{
	this->deletePath();
	int x = getXPos();
	x += 1;
	if (x > this->_xMax - 1)
		x = this->_xMax - 1;
	setXPos(x);
}

int			Enemy::getmv()
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

