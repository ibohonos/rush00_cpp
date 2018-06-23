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

class Enemy: public Objects {
	public:
		Enemy(void);
		Enemy(WINDOW *win, int yPos, int xPos, int sizeY, int sizeX, std::string type);
		// Player(Player const &rfs);
		// ~Player(void);

		void	mvup(void);
		void	mvdown(void);
		void	mvleft(void);
		void	mvright(void);
		int		getmv(void);
		void			display(void);
		void			deletePath(void);

	private:
		int		_xMax;
		int		_yMax;
		// Objects	*object;
};

#endif