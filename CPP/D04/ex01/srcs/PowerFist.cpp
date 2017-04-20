#include "PowerFist.hpp"

PowerFist::PowerFist(void) :
AWeapon("Power Fist", 8, 50)
{
  return;
}

PowerFist::~PowerFist(void)
{
  return;
}

PowerFist::PowerFist(PowerFist const & src)
{
  *this = src;
  return;
}

PowerFist & PowerFist::operator=(PowerFist const & src)
{
  if (this != &src)
  {
    this->_name = src._name;
    this->_apcost = src._apcost;
    this->_damage = src._damage;
  }
  return *this;
}

void PowerFist::attack(void) const
{
  std::cout << "* pschhh... SBAM! *" << std::endl;
}
