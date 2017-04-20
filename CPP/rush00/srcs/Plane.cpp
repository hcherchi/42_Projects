#include "Plane.hpp"
#include "Header.hpp"

Plane::Plane() : Object(WIDTH / 2, -HEIGHT + 5, "<O>", 'U', 5, "Plane", 1, 1)
{
    return ;
}

Plane::Plane(Plane const &src)
{
  *this = src;
  return ;
}

Plane::~Plane()
{
    return ;
}

Plane		&Plane::operator=(Plane const &src)
{
  Object::operator=(src);
	return (*this);
}

Weapon *Plane::dropWeapon(int offset)
{
  return new Weapon(this->_x + (int)this->_shape.length() / 2 + offset, this->_y, 'U', 2);
}

void Plane::moveLeft(void)
{
  if (this->_x - 2 > 0)
    this->_x -= 2;
}

void Plane::moveRight(void)
{
  if (this->_x + 2 + (int)this->_shape.length() < WIDTH)
    this->_x += 2;
}

void Plane::moveUp(void)
{
  if (this->_y + 1 < 0)
    this->_y++;
}

void Plane::moveDown(void)
{
  if (this->_y - 1 > -HEIGHT + 1)
    this->_y--;
}
