/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shot.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 15:48:48 by pzubar            #+#    #+#             */
/*   Updated: 2018/06/24 17:47:12 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOT_HPP
#define SHOT_HPP

#include <iostream>

#include "Objects.hpp"
#include "Enemy.hpp"

class Shot : public Objects
{
  public:
	Shot(void);
	// Enemy(WINDOW *win, int yPos, int xPos, int sizeY, int sizeX, std::string type);
	// Player(Player const &other);
	// ~Player(void);

	void move(void);
	void display(void);
	void deletePath(void);

	void initObject(WINDOW *win);
	void checkCollision(void);

	bool getIsDisp(void);

	static int shotsNum;
	void checkCollision(Enemy *enems);

  private:
	int _xMax;
	int _yMax;
	// static int	_shotsNum;
	bool _isDisp;
	bool _authorPlayer;
};

#endif
