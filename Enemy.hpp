/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:48:21 by pzubar            #+#    #+#             */
/*   Updated: 2018/06/23 13:48:22 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include "Objects.hpp"


class Enemy : public Objects
{
  public:
	Enemy(void);
	// Enemy(WINDOW *win, int yPos, int xPos, int sizeY, int sizeX, std::string type);
	Enemy(Enemy const &other);
	~Enemy(void);
	void mvdown(void);
	void display(void);
	void deletePath(void);
	// void remove(void);

	// void shot(Shot * shots);

	void initObject(WINDOW *win);
	Enemy		&operator=( Enemy const &rfs );

  private:
	int _xMax;
	int _yMax;
	static int _enemiesNum;
	bool _isDisp;
};

#endif