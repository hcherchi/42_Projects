#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) :
AWeapon("Plasma Rifle", 5, 21)
{
  return;
}

PlasmaRifle::~PlasmaRifle(void)
{
  return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src)
{
  *this = src;
  return;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & src)
{
  if (this != &src)
  {
    this->_name = src._name;
    this->_apcost = src._apcost;
    this->_damage = src._damage;
  }
  return *this;
}

void PlasmaRifle::attack(void) const
{
  std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
