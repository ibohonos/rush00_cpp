/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:48:21 by pzubar            #+#    #+#             */
/*   Updated: 2018/06/23 13:48:22 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STARS_HPP
#define STARS_HPP

#include <iostream>
#include "Objects.hpp"

class Stars : public Objects
{
  public:
	Stars(void);
	Stars(Stars const &other);
	~Stars(void);
	Stars		&operator=( Stars const &rfs );
	
	void mvdown(void);
	void display(void);
	void deletePath(void);
	// void remove(void);

	void initObject(WINDOW *win);

  private:
	int			_xMax;
	int			_yMax;
	static int	_starsNum;
	bool		_isDisp;
};

#endif