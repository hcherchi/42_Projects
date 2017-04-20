# ifndef OBJECT_HPP
# define OBJECT_HPP
# include <iostream>
# include <ncurses.h>
class Object
{
  protected:
    int _x;
    int _y;
    std::string _shape;
    char _direction;
    int _hp;
    int _maxHp;
    std::string _type;
	int _color;
  int _damages;

  public:
    Object(void);
    Object(int x, int y, std::string shape, char direction, int maxHp, std::string type, int color, int damages);
    virtual ~Object(void);
    Object(const Object & src);
    Object & operator = (const Object & src);

    virtual void moveLeft(void);
    virtual void moveRight(void);
    virtual void moveUp(void);
    virtual void moveDown(void);
    void move(int count);
    bool doesCollide(Object *);
    virtual void takeDamage(int amount);
    Object* clone() const;

	void print(void);

	void	setXPosition(int);
	void	setYPosition(int);
  void setHp(int);

    int getHp() const;
    int getMaxHp() const;
    int getXPosition() const;
    int getYPosition() const;
    std::string getShape() const;
    char getDirection() const;
    std::string getType() const;
	int	getColor() const;
  int getDamages() const;
};

#endif
