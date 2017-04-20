#include "FragTrap.hpp"

FragTrap::FragTrap(void) :
  _hitPoints(100),
  _maxHitPoints(100),
  _energyPoints(100),
  _maxEnergyPoints(100),
  _level(1),
  _name("Anonymous"),
  _meleeDamage(30),
  _rangedDamage(20),
  _armor(5)
{
  std::cout << "A new FragTrap joins the battle but wants to stay anonymous." << std::endl;
  return;
}


FragTrap::FragTrap(std::string _name) :
  _hitPoints(100),
  _maxHitPoints(100),
  _energyPoints(100),
  _maxEnergyPoints(100),
  _level(1),
  _name(_name != "" ? _name : "Anonymous"),
  _meleeDamage(30),
  _rangedDamage(20),
  _armor(5)
{
  std::cout << this->_name << ", a new FragTrap, joins the battle." << std::endl;
  return;
}

FragTrap::~FragTrap(void)
{
  std::cout << "The last attack to much to afford for " << this->_name << ". it dies in real pain." << std::endl;
  return;
}

FragTrap::FragTrap(FragTrap const & src)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
  std::cout << "Assignation operator called" << std::endl;
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

unsigned int FragTrap::rangedAttack(std::string const & target)
{
  std::cout << this->_name << " attacks suddenly " << target << " at range, causing " << this->_rangedDamage << " damages !" << std::endl;
  return this->_rangedDamage;
}

unsigned int FragTrap::meleeAttack(std::string const & target)
{
  std::cout << this->_name << " attacks suddenly " << target << " at melee, causing " << this->_meleeDamage << " damages !" << std::endl;
  return this->_meleeDamage;
}

void FragTrap::takeDamage(unsigned int amount)
{
  int realDamages = amount - this->_armor;
  if (amount == 0)
    return;
  else if ((int)this->_hitPoints <= realDamages)
  {
    realDamages -= realDamages - this->_hitPoints;
    std::cout << this->_name << " use a shield to reduce damages still lose " << realDamages << " HP" << std::endl;
    this->_hitPoints -= realDamages;
    this->~FragTrap();
  }
  else
  {
    std::cout << this->_name << " use a shield to reduce damages still lose " << realDamages << " HP" << std::endl;
    this->_hitPoints -= realDamages;
  }
}

void FragTrap::beRepaired(unsigned int amount)
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

unsigned int FragTrap::vaulthunter_dot_exe(std::string const & target)
{
  int cast = rand() % 5;
  unsigned int damages = 0;
  std::string attack = "";

  if (this->_energyPoints < 25)
  {
    std::cout << this->_name << " try to use vaulhunter attack but its energy is too low..." << std::endl;
    return 0;
  }
  switch (cast)
  {
    case 0:
      damages = 10;
      attack = "Magnitude 1... :()";
      break;
    case 1:
      damages = 20;
      attack = "Magnitude 2";
      break;
    case 2:
      damages = 30;
      attack = "Magnitude 3";
      break;
    case 3:
      damages = 40;
      attack = "Magnitude 4!";
      break;
    case 4:
      damages = 50;
      attack = "Magnitude 5!!";
      break;
    default:
      attack = "BUG";
      break;
  }
  std::cout << this->_name << " use " << attack << " on " << target << " causing " << damages << " damages" << std::endl;
  this->_energyPoints -= 25;
  return damages;
}

std::string FragTrap::getName(void)
{
  return this->_name;
}

unsigned int FragTrap::getHP(void)
{
  return this->_hitPoints;
}

unsigned int FragTrap::getMP(void)
{
  return this->_energyPoints;
}
