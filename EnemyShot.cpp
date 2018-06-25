/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyShot.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 20:22:49 by pzubar            #+#    #+#             */
/*   Updated: 2018/06/24 20:22:50 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyShot.hpp"

EnemyShot::EnemyShot(){}
EnemyShot::~EnemyShot(){}

void EnemyShot::deletePath(void)
{
    mvwaddstr(getWindow(), getYPos(), getXPos(), " ");
}

void EnemyShot::display(void)
{
    start_color();
    init_pair(99, COLOR_MAGENTA, COLOR_BLACK);
    wattron(getWindow(), COLOR_PAIR(99));
    mvwaddstr(getWindow(), getYPos(), getXPos(), "-");
    wattroff(getWindow(), COLOR_PAIR(99));
    _isDisp = 1;
}

void EnemyShot::setEnemiesPlayer(Enemy * enemies, Player * player)
{
    _enemies = enemies;
    _player = player;
}

EnemyShot::EnemyShot(EnemyShot const &other)
{
    *this = other;
}

EnemyShot &EnemyShot::operator=(EnemyShot const &rhs)
{
	_xMax = rhs._xMax;
    _yMax = rhs._yMax;
    _isDisp = rhs._isDisp;
    _enemies = rhs._enemies;
    _player = rhs._player;
	return *this;
}

void EnemyShot::move(void)
{
    if (!_isDisp)
        return;
    this->deletePath();
    int y = getYPos();
    y += 1;
    if (y > this->_yMax - 2)
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

void EnemyShot::initObject(WINDOW *win)
{
    _win = win;
    _isDisp = false;
    getmaxyx(getWindow(), this->_yMax, this->_xMax);
    // setXPos(rand() % this->_xMax + 3);
    // setYPos(3);
    setSizeX(1);
    setSizeY(1);
}

bool EnemyShot::getIsDisp(void)
{
    return _isDisp;
}

bool EnemyShot::checkCollision(void)
{
    if ((_player->getXPos() == this->getXPos()) && (_player->getYPos() == this->getYPos()))
    {
        this->initObject(getWindow());
        this->deletePath();
        return(true);
    }
    if ((_player->getXPos() + 1 == this->getXPos()) && (_player->getYPos() == this->getYPos()))
    {
        this->initObject(getWindow());
        this->deletePath();
        return(true);
    }
    if ((_player->getXPos() + 2 == this->getXPos()) && (_player->getYPos() == this->getYPos()))
    {
        this->initObject(getWindow());
        this->deletePath();
        return(true);
    }
    return(false);
}

bool EnemyShot::checkLine(void)
{
    for (int i = 0; i < _enemiesNum; i++)
    {
        if ((_enemies[i].getXPos()) == (_player->getXPos()))
        {
            if (!this->getIsDisp())
            {
                setXPos(_enemies->getXPos());
                setYPos(_enemies->getYPos() + 1);
                display();
            }
        }
    }
    return (false);
}