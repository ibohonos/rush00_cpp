/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:48:21 by pzubar            #+#    #+#             */
/*   Updated: 2018/06/23 13:48:22 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROIDS_HPP
#define ASTEROIDS_HPP

#include <iostream>
#include "Objects.hpp"

class Asteroids : public Objects
{
  public:
	Asteroids(void);
	Asteroids(Asteroids const &other);
	~Asteroids(void);
	void mvdown(void);
	void display(void);
	void deletePath(void);
	// void remove(void);

	void initObject(WINDOW *win);
	Asteroids	&operator=( Asteroids const &rfs );

  private:
	int			_xMax;
	int			_yMax;
	static int	_asteroidsNum;
	bool		_isDisp;
};

#endif