#include "Heal.hpp"

Heal::Heal() : Object(rand() % (WIDTH - 4) + 1, 0, "##", 'D', 1, "Heal", 5, 0)
{
    return ;
}

Heal::Heal(Heal const &src)
{
  *this = src;
  return ;
}

Heal::~Heal() {
    return ;
}

Heal		&Heal::operator=(Heal const &src)
{
  Object::operator=(src);
	return (*this);
}
