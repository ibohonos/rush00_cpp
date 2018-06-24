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
#include "Asteroids.hpp"

class Shot : public Objects
{
  public:
	Shot(void);
	Shot(Shot const &other);
	~Shot(void);
	Shot		&operator=( Shot const &rfs );

	void move(void);
	void display(void);
	void deletePath(void);
	void setScore(int n);
	int getScore(void);
	void initObject(WINDOW *win);

	bool getIsDisp(void);
	static int shotsNum;
	void checkCollision(Enemy *enems, Asteroids *aster);

  private:
	int _xMax;
	int _yMax;
	bool _isDisp;
	static int _score;
};

#endif
