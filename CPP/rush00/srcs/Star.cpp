#include "Star.hpp"

Star::Star() : Object(rand() % (WIDTH - 4) + 1, 0, "*", 'D', 1, "Star", 6, 0)
{
    return ;
}

Star::Star(Star const &src)
{
  *this = src;
  return ;
}

Star::~Star() {
    return ;
}

Star		&Star::operator=(Star const &src)
{
  Object::operator=(src);
	return (*this);
}
