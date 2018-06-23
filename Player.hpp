#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Objects.hpp"

class Player : public Objects {
	public:
		Player(void);
		Player(WINDOW *win, int yPos, int xPos, int sizeY, int sizeX, std::string type);
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
		Objects	*object;
};

#endif
