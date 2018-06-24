#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "Objects.hpp"
#include "Enemy.hpp"
#include "Shot.hpp"


class Player : public Objects
{
  public:
	Player(void);
	Player(WINDOW *win, Enemy *enemies);
	// Player(Player const &rfs);
	// ~Player(void);

	void mvup(void);
	void mvdown(void);
	void mvleft(void);
	void mvright(void);
	int getmv(void);
	void display(void);
	void deletePath(void);

	void setLives(int n);

	void setShots(Shot * shots);

	// void setScore(int);

	int getLives(void);
	// int getScore(void);

	void checkCollision(void);
	bool checkLife(void);
	void shot(void);

  private:
	int _xMax;
	int _yMax;
	Enemy *_enems;
	Shot * _shots;
	int _lives;
	// int _score;
};

#endif
