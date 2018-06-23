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
		Objects(std::string type, WINDOW *win);
		Objects(Objects const &rfs);
		~Objects(void);

		Objects			&operator=( Objects const &rfs );
		int				getXPos(void);
		int				getYPos(void);
		int				getSizeX(void);
		int				getSizeY(void);
		std::string		getType(void);
		std::string		getColor(void);
		WINDOW			*getWindow(void);
		void			setXPos(int n);
		void			setYPos(int n);
		void			setSizeX(int n);
		void			setSizeY(int n);
		void			setColor(std::string str);

	protected:
		std::string		_type;
		WINDOW			*_win;
		int				_xPos;
		int				_yPos;
		int				_sizeX;
		int				_sizeY;
		std::string		_color;
};

#endif
