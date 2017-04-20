#include "ClapTrap.hpp"

ClapTrap::ClapTrap(int _hitPoints, int _maxHitPoints, int _energyPoints, int _maxEnergyPoints, int _meleeDamage, int _rangedDamage, int _armor, std::string _type) :
_hitPoints(_hitPoints),
_maxHitPoints(_maxHitPoints),
_energyPoints(_energyPoints),
_maxEnergyPoints(_maxEnergyPoints),
_level(1),
_name("Anonymous"),
_meleeDamage(_meleeDamage),
_rangedDamage(_rangedDamage),
_armor(_armor),
_type(_type)
{
  std::cout << "New ClapTrap has been created: ";
  return;
}

ClapTrap::ClapTrap(std::string _name, int _hitPoints, int _maxHitPoints, int _energyPoints, int _maxEnergyPoints, int _meleeDamage, int _rangedDamage, int _armor, std::string _type) :
_hitPoints(_hitPoints),
_maxHitPoints(_maxHitPoints),
_energyPoints(_energyPoints),
_maxEnergyPoints(_maxEnergyPoints),
_level(1),
_name(_name != "" ? _name : "Anonymous"),
_meleeDamage(_meleeDamage),
_rangedDamage(_rangedDamage),
_armor(_armor),
_type(_type)
{
  std::cout << "New ClapTrap has been created: ";
  return;
}


ClapTrap::~ClapTrap(void)
{
  std::cout << "It dies in real pain." << std::endl;
  return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
  *this = src;
  return;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
  if (this != &src)
  {
    this->_hitPoints = src._hitPoints;
    this->_maxHitPoints = src._maxHitPoints;
    this->_energyPoints = src._energyPoints;
    this->_maxEnergyPoints = src._maxEnergyPoints;
    this->_level = src._level;
    this->_name = src._name;
    this->_meleeDamage = src._meleeDamage;
    this->_rangedDamage = src._rangedDamage;
    this->_armor = src._armor;
  }
  return *this;
}

void ClapTrap::takeDamage(unsigned int amount)
{
  int realDamages = amount - this->_armor;
  if (amount == 0)
    return;
  else if ((int)this->_hitPoints <= realDamages)
  {
    realDamages -= realDamages - this->_hitPoints;
    std::cout << this->_name << " use a shield to reduce damages still lose " << realDamages << " HP" << std::endl;
    this->_hitPoints -= realDamages;
  }
  else
  {
    std::cout << this->_name << " use a shield to reduce damages still lose " << realDamages << " HP" << std::endl;
    this->_hitPoints -= realDamages;
  }
}

void ClapTrap::beRepaired(unsigned int amount)
{
  if (this->_hitPoints + amount >= this->_maxHitPoints)
  {
    amount -= this->_hitPoints + amount - this->_maxHitPoints;
    std::cout << this->_name << " decide to repair itself and recover " << amount << " of HP. He's now full." << std::endl;
    this->_hitPoints += amount;
  }
  else
  {
    std::cout << this->_name << " decide to repair itself and recover " << amount << " HP" << std::endl;
    this->_hitPoints += amount;
  }
}

unsigned int ClapTrap::rangedAttack(std::string const & target)
{
  std::cout << this->_name << " attacks " << target << " at range, causing " << this->_rangedDamage << " damages !" << std::endl;
  return this->_rangedDamage;
}

unsigned int ClapTrap::meleeAttack(std::string const & target)
{
  std::cout << this->_name << " attacks " << target << " at melee, causing " << this->_meleeDamage << " damages !" << std::endl;
  return this->_meleeDamage;
}

std::string ClapTrap::getName(void)
{
  return this->_name;
}

unsigned int ClapTrap::getHP(void)
{
  return this->_hitPoints;
}

unsigned int ClapTrap::getMP(void)
{
  return this->_energyPoints;
}

std::string ClapTrap::getType(void)
{
  return this->_type;
}
