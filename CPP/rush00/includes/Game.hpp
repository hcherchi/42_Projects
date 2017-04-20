# ifndef GAME_HPP
# define GAME_HPP

#include "Plane.hpp"
#include "Squad.hpp"
#include "Header.hpp"
#include <ncurses.h>
#include <ctime>

class Game
{
  protected:
    Plane   *_plane;
    Squad   *_objects;
    int     _timer;
    int     _score;
    WINDOW  *_winInfo;
    WINDOW  *_winGame;
    int     _ray;

  public:
    Game(void);
    Game(Plane *player, WINDOW  *winInfo, WINDOW  *winGame);
    ~Game(void);
    Game(const Game & src);
    Game & operator = (const Game & src);

    Plane *getPlane() const;
    int getFPS() const;
    int getTimer() const;
    int getScore() const;
    Squad *getObjects() const;
    int getRay() const;

    void loop(void);
    int listen(void);
	void refreshBox(void);
    void refresh(int count);
	void displayInfo(void);
	int startGame(void);
	void gameOver(void);
  void checkCollisions(void);
  void checkDeath(void);

  private:
	clock_t _time;
};

#endif
