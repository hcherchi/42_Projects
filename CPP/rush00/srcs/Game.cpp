#include "Game.hpp"
#include "Bird.hpp"
#include "Bonus.hpp"
#include "Heal.hpp"
#include "Star.hpp"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <ncurses.h>

Game::Game(void) :
_plane(0),
_objects(new Squad()),
_timer(0),
_score(0),
_winInfo(0),
_winGame(0),
_ray(1)
{
    return;
}

Game::Game(Plane *player, WINDOW *winInfo, WINDOW *winGame) :
_plane(player),
_objects(new Squad(this->_plane)),
_timer(0),
_score(0),
_winInfo(winInfo),
_winGame(winGame),
_ray(1)
{
    return;
}

Game::Game(Game const &src)
{
    *this = src;
    return;
}

Game::~Game(void)
{
    return;
}

Game		&Game::operator=(Game const &src)
{
	this->_plane = src._plane;
  this->_objects = src._objects;
  this->_score = src._score;
  this->_timer = src._timer;

	return (*this);
}

int Game::getScore(void) const
{
  return this->_score;
}

int Game::getTimer(void) const
{
  return this->_timer;
}

Plane *Game::getPlane(void) const
{
  return this->_plane;
}

Squad *Game::getObjects(void) const
{
  return this->_objects;
}

int Game::getRay(void) const
{
  return this->_ray;
}


void Game::refresh(int count)
{
  Object *tmp;
  int random;

  for (int i = 0; i < this->_objects->getCount(); i++)
  {
    tmp = this->_objects->getUnit(i);
    if (this->_plane != tmp)
    {
      tmp->move(count);
      if (tmp->getType() == "Bird" && (random = rand() % 100) == 1)
          this->_objects->push(((Bird *)tmp)->dropWeapon());
    }
  }
  if (count % 10 == 0)
    this->_objects->push(new Star());
  if (count % 50 == 0)
    this->_objects->push(new Bird());
  if (count == 99)
  {
    if (this->_time % 2)
      this->_objects->push(new Bonus());
    else
      this->_objects->push(new Heal());
  }
}

int Game::listen(void)
{
  int ch = getch();
  switch(ch)
  {
      case KEY_LEFT:
          this->_plane->moveLeft();
          break;
      case KEY_RIGHT:
          this->_plane->moveRight();
          break;
      case KEY_UP:
          this->_plane->moveUp();
          break;
      case KEY_DOWN:
          this->_plane->moveDown();
          break;
	  case KEY_HOME:
	      while ((ch = getch()) != KEY_HOME)
		  ;
	  case KEY_END:
		  return (0);
      case 32:
        this->_objects->push(this->_plane->dropWeapon(0));
        for (int i = 0; i < this->_ray; i++)
        {
          this->_objects->push(this->_plane->dropWeapon(-i));
          this->_objects->push(this->_plane->dropWeapon(i));
        }
      default:
          break;
  }
  return (1);
}

void	Game::refreshBox(void)
{
	box(this->_winGame, 0, 0);
	box(this->_winInfo, 0, 0);
	wrefresh(this->_winGame);
	wrefresh(this->_winInfo);
}

void	Game::displayInfo(void)
{
	std::string info = "HP: " + std::to_string(this->_plane->getHp()) + "/" + std::to_string(this->_plane->getMaxHp());
	mvwprintw(this->_winInfo, 2, 1, info.c_str());
	info = "Score: " + std::to_string(this->_score);
	mvwprintw(this->_winInfo, 4, 1, info.c_str());
	info = "Time: " + std::to_string(this->_time / 1000);
	mvwprintw(this->_winInfo, 6, 1, info.c_str());
}

int		Game::startGame(void)
{
	int ch;
	while ((ch = getch()) != 32) {
		if (ch == 'q')
			return (0);
		mvwprintw(this->_winGame, 1, 1, "Press SPACEBAR for start");
		mvwprintw(this->_winGame, (HEIGHT / 2), ((WIDTH / 2) - 9), "ft_retro / New Game");
		mvwprintw(this->_winGame, (HEIGHT - 2), (WIDTH - 21), "hcherchi x tvisenti");
		this->refreshBox();
	}
	return (1);
}

void	Game::gameOver(void)
{
	int ch;
	while ((ch = getch()) != 'q' && ch != 'r') {
		mvwprintw(this->_winGame, 1, 1, "Press 'q' to quit");
    	mvwprintw(this->_winGame, 2, 1, "Press 'r' to restart");
		mvwprintw(this->_winGame, (HEIGHT / 2), ((WIDTH / 2) - 5), "GAME OVER");
		mvwprintw(this->_winGame, (HEIGHT - 2), (WIDTH - 21), "hcherchi x tvisenti");
		this->refreshBox();
	}
  if (ch == 'r')
  {
    clear();
    Plane *player = new Plane();
    Game *game = new Game(player, this->_winInfo, this->_winGame);
    delete(this);
    game->loop();
  }
}

void Game::checkCollisions(void)
{
  Object *tmp;
  Object *tmp2;

  for (int i = 0; i < this->_objects->getCount(); i++)
  {
    tmp = this->_objects->getUnit(i);
    if (!tmp)
      break;
    if ((tmp->getXPosition() < 0 || tmp->getXPosition() >= WIDTH || tmp->getYPosition() > 0 || tmp->getYPosition() <= -HEIGHT) && tmp->getType() != "Plane")
      this->_objects->deleteUnit(i);
    for (int j = 0; j < this->_objects->getCount(); j++)
    {
      tmp2 = this->_objects->getUnit(j);
      if (tmp != tmp2 && tmp2->doesCollide(tmp) && tmp->getDirection() != tmp2->getDirection())
      {
        if (tmp->getType() == "Plane")
          this->_ray = 1;
        tmp->takeDamage(tmp2->getDamages());
      }
    }
  }
}

void Game::checkDeath(void)
{
  Object *tmp;

  for (int i = 0; i < this->_objects->getCount(); i++)
  {
    tmp = this->_objects->getUnit(i);
    if (!tmp)
      break;
    if (tmp->getHp() == 0 && tmp->getType() != "Plane")
    {
  		if (tmp->getType() == "Bird")
  			this->_score++;
      if (tmp->getType() == "Bonus" && this->_ray <= 3)
        this->_ray++;
      if (tmp->getType() == "Heal" && this->_plane->getHp() < 5)
        this->_plane->setHp(this->_plane->getHp() + 1);
  		this->_objects->deleteUnit(i);
	   }
  }
}

void Game::loop(void)
{
  if (this->startGame() == 0)
  	return;
  int timeSleep = 1000000 / FPS;
  srand(time(NULL));
  int count = 0;
  int diff = 0;

  while (this->_plane->getHp())
  {
  	if (this->listen() == 0) {
		clear();
		this->refreshBox();
		break;
	}
    this->_time = clock();
    count = (count == 100) ? 0 : count + 1;

    if (this->listen() == 0)
    {
      clear();
      this->refreshBox();
      break;
    }
    this->refresh(count);
    this->checkCollisions();
    this->checkDeath();

    clear();
  	this->_objects->print();
  	this->displayInfo();
    this->refreshBox();
    diff = clock() - this->_time;
    if (diff < timeSleep)
      usleep(timeSleep - diff);
  }
  this->gameOver();
}
