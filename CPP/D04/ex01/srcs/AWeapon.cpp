#include "AWeapon.hpp"

AWeapon::AWeapon(void) :
_name("Anonymous"),
_apcost(0),
_damage(0)
{
  return;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
_name(name),
_apcost(apcost),
_damage(damage)
{
  return;
}


AWeapon::~AWeapon(void)
{
  return;
}

AWeapon::AWeapon(AWeapon const & src)
{
  *this = src;
  return;
}

AWeapon & AWeapon::operator=(AWeapon const & src)
{
  if (this != &src)
  {
    this->_name = src._name;
    this->_apcost = src._apcost;
    this->_damage = src._damage;
  }
  return *this;
}

std::string const & AWeapon::getName(void) const
{
  return this->_name;
}

int AWeapon::getApcost(void) const
{
  return this->_apcost;
}

int AWeapon::getDamage(void) const
{
  return this->_damage;
}
