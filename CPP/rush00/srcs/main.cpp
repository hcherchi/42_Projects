#include "Game.hpp"
#include "Bird.hpp"
#include "Plane.hpp"
#include "Weapon.hpp"
#include "Squad.hpp"
#include <iostream>

#include <ncurses.h>
#include <curses.h>

void	initColor(void)
{
	start_color();
	init_color(COLOR_BLUE, 300, 300, 300);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
}

int main()
{
  	initscr();
  	initColor();
  	WINDOW *winGame, *winInfo;

  	winGame = subwin(stdscr, HEIGHT, WIDTH, 0, 0);
	winInfo = subwin(stdscr, 8, WIDTH / 3, HEIGHT, 0);

	noecho();
	timeout(1);
	curs_set(FALSE);
  	keypad(stdscr, TRUE);
	getch();

	Plane *player = new Plane();
  	Game *game = new Game(player, winInfo, winGame);
  	game->loop();

	delwin(winGame);
	delwin(winInfo);
	endwin();
  	return 0;
}
