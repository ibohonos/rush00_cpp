#ifndef OBJECTS_HPP
#define OBJECTS_HPP

#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class Objects {
	public:
		Objects(void);
		Objects(WINDOW *win);
		Objects(Objects const &rfs);
		~Objects(void);

		Objects			&operator=( Objects const &rfs );
		int				getXPos(void);
		int				getYPos(void);
		int				getSizeX(void);
		int				getSizeY(void);
		std::string		getColor(void);
		WINDOW			*getWindow(void);
		int				getEnemsN(void);
		int				getAsterN(void);
		int				getStarN(void);
		int				getShotNum(void);

		void			setXPos(int n);
		void			setYPos(int n);
		void			setSizeX(int n);
		void			setSizeY(int n);
		void			setColor(std::string str);
		void			setEnemsN(int n);
		void			setAsterN(int n);
		void			setStarN(int n);
		void			setShotNum(int n);
		void			initObject(WINDOW *win);

	protected:
		WINDOW			*_win;

		int				_xPos;
		int				_yPos;
		int				_sizeX;
		int				_sizeY;
		std::string		_color;
		static int	_enemiesNum;
		static int	_asteroidsNum;
		static int	_starsNum;
		static int	_shotsNum;
};

#endif
