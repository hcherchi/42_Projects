#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) :
Enemy(80, "RadScorpion")
{
  std::cout << "* click click click *" << std::endl;
  return;
}

RadScorpion::~RadScorpion(void)
{
  std::cout << "* SPROTCH *" << std::endl;
  return;
}

RadScorpion::RadScorpion(RadScorpion const & src)
{
  *this = src;
  return;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & src)
{
  if (this != &src)
  {
    this->_type = src._type;
    this->_hp = src._hp;
  }
  return *this;
}
