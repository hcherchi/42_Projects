#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) :
Enemy(170, "Super Mutant")
{
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
  return;
}

SuperMutant::~SuperMutant(void)
{
  std::cout << "Aaargh ..." << std::endl;
  return;
}

SuperMutant::SuperMutant(SuperMutant const & src)
{
  *this = src;
  return;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & src)
{
  if (this != &src)
  {
    this->_type = src._type;
    this->_hp = src._hp;
  }
  return *this;
}

void SuperMutant::takeDamage(int damages)
{
  damages -= 3;
  if (damages >= 0)
    this->_hp -= damages;
}
