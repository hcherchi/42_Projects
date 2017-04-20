#include "Object.hpp"
#include <ncurses.h>
#include <curses.h>

Object::Object(void) :
_x(0),
_y(0),
_shape("O"),
_direction('U'),
_hp(0),
_maxHp(0),
_type("None"),
_color(0),
_damages(0)
{
    return;
}

Object::Object(int x, int y, std::string shape, char direction, int maxHp, std::string type, int color, int damages) :
_x(x),
_y(y),
_shape(shape),
_direction(direction),
_hp(maxHp),
_maxHp(maxHp),
_type(type),
_color(color),
_damages(damages)
{
    return;
}

Object::Object(Object const &src)
{
    *this = src;
    return;
}

Object::~Object(void)
{
    return;
}

Object		&Object::operator=(Object const &src)
{
	this->_x = src._x;
	this->_y = src._y;
  this->_shape = src._shape;
  this->_direction = src._direction;
  this->_maxHp = src._maxHp;
  this->_hp = src._hp;
  this->_type = src._type;
	return (*this);
}

void Object::moveLeft(void) { this->_x--; }

void Object::moveRight(void) { this->_x++; }

void Object::moveUp(void) { this->_y++; }

void Object::moveDown(void) { this->_y--; }

void Object::move(int count)
{
  if (count % 10 && (this->_type == "Bird" || this->_type == "Bonus" || this->_type == "Heal"))
    return;
  else if (count % 2 && this->_type == "Weapon")
    return;
  switch (this->_direction)
  {
    case 'U':
      this->moveUp();
      break;
    case 'D':
      this->moveDown();
      break;
    case 'L':
      this->moveLeft();
      break;
    case 'R':
      this->moveRight();
      break;
    default:
      break;
  }
}

void Object::takeDamage(int amount)
{
  if (amount > 0)
  {
    int after = this->_hp - amount;
    this->_hp -= (after < 0) ? amount + after : amount;
  }
}

bool Object::doesCollide(Object *obj)
{
  int i = 0;
  int j = 0;

  while (i < (int)obj->_shape.length())
  {
    j = 0;
    while (j < (int)this->_shape.length())
    {
      if (obj->_x + i == this->_x + j && obj->_y == this->_y)
        return true;
      j++;
    }
    i++;
  }
  return false;
}

void Object::print(void)
{
  attron(COLOR_PAIR(this->_color));
  mvprintw(-this->getYPosition(), this->getXPosition(), this->getShape().c_str());
  attroff(COLOR_PAIR(this->_color));
  refresh();
}

Object* Object::clone() const
{
  return new Object(*this);
}

void Object::setXPosition(int x)
{
	this->_x = x;
    return;
}

void Object::setYPosition(int y)
{
	this->_y = y;
    return;
}

void Object::setHp(int y)
{
	this->_hp = y;
    return;
}

int Object::getXPosition() const
{
    return this->_x;
}

int Object::getYPosition() const
{
    return this->_y;
}

std::string Object::getShape() const
{
    return this->_shape;
}

char Object::getDirection() const
{
    return this->_direction;
}

int Object::getHp() const
{
    return this->_hp;
}

int Object::getDamages() const
{
    return this->_damages;
}

int Object::getMaxHp() const
{
    return this->_maxHp;
}

std::string Object::getType() const
{
    return this->_type;
}

int	Object::getColor() const
{
	return this->_color;
}
