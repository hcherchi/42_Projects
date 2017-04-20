#include "Bonus.hpp"

Bonus::Bonus() : Object(rand() % (WIDTH - 4) + 1, 0, "$$", 'D', 1, "Bonus", 5, 0)
{
    return ;
}

Bonus::Bonus(Bonus const &src)
{
  *this = src;
  return ;
}

Bonus::~Bonus() {
    return ;
}

Bonus		&Bonus::operator=(Bonus const &src)
{
  Object::operator=(src);
	return (*this);
}
