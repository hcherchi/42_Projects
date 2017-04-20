#include "Weapon.hpp"

Weapon::Weapon() : Object(0, 0, "|", 'U', 1, "Weapon", 0, 1)
{
    return ;
}

Weapon::Weapon(int x, int y, char direction, int color) : Object(x, y, "|", direction, 1, "Weapon", color, 1)
{
    return ;
}

Weapon::Weapon(Weapon const &src)
{
  *this = src;
  return ;
}

Weapon::~Weapon() {
    return ;
}

Weapon		&Weapon::operator=(Weapon const &src)
{
  Object::operator=(src);
	return (*this);
}
