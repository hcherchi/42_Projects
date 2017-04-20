#include "Bird.hpp"
#include "Header.hpp"

Bird::Bird() : Object(rand() % (WIDTH - 4) + 1, 0, ">*<", 'D', 1, "Bird", 3, 1) {
    return ;
}

Bird::Bird(Bird const &src) {
  *this = src;
  return ;
}

Bird::~Bird() {
  return ;
}

Bird		&Bird::operator=(Bird const &src) {
  Object::operator=(src);
	return (*this);
}

Weapon *Bird::dropWeapon(void)
{
  return new Weapon(this->_x + (int)this->_shape.length() / 2, this->_y - 1, 'D', 4);
}
