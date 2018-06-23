#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"

int main(void)
{
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    int yMax, xMax;

    //Функция, определяет макс х та у залежно від розміра вікна
    getmaxyx(stdscr, yMax, xMax);

    WINDOW * playerwin = newwin(yMax - 1, xMax - 1, 0, 0);
    
    //Малюємо рамочку, оновлюємо вікно
    box(playerwin, 0, 0);
    refresh();
    wrefresh(playerwin);

    //Створюємо гравця
    Player * p = new Player(playerwin, yMax - 3, 1, 0);
    
    //Ду-вайл, щоб була перша
    do {
        //умова отрисовки
            p->display();
        wrefresh(playerwin);
    } while(p->getmv()!= 'x');

    // getch();
    endwin();
    return(0);
}