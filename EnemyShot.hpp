/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyShot.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzubar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 20:22:57 by pzubar            #+#    #+#             */
/*   Updated: 2018/06/24 20:22:59 by pzubar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMSHOT_HPP
#define ENEMSHOT_HPP

#include <iostream>

#include "Player.hpp"
#include "Objects.hpp"
#include "Enemy.hpp"

class EnemyShot : public Objects
{
  public:
    EnemyShot(void);
    EnemyShot(EnemyShot const &other);
    ~EnemyShot(void);

    EnemyShot &operator=(EnemyShot const &rhs);

    void move(void);
    void display(void);
    void deletePath(void);

    void initObject(WINDOW *win);

    bool getIsDisp(void);
    bool checkLine(void);
    bool checkCollision(void);
    
    void setEnemiesPlayer(Enemy * enemies, Player * player);
    
  private:
    int _xMax;
    int _yMax;
    bool _isDisp;
    Enemy * _enemies;
    Player * _player;
};

#endif
