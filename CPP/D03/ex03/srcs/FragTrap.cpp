#include "FragTrap.hpp"

FragTrap::FragTrap(void) :
ClapTrap(100, 100, 100, 100, 30, 20, 5, "FragTrap")
{
  std::cout << "A FragTrap that wants to stay anonymous." << std::endl;
  return;
}


FragTrap::FragTrap(std::string _name) :
ClapTrap(_name, 100, 100, 100, 100, 30, 20, 5, "FragTrap")
{
  std::cout << this->_name << ", a FragTrap." << std::endl;
  return;
}

FragTrap::~FragTrap(void)
{
  std::cout << "The last attack was too much to afford for the poor FragTrap " << this->_name << std::endl;
  return;
}

FragTrap::FragTrap(FragTrap const & src) :
ClapTrap(src)
{
  *this = src;
  return;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
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

unsigned int FragTrap::rangedAttack(std::string const & target)
{
  std::cout << this->_name << " attacks suddenly  " << target << " at range, causing " << this->_rangedDamage << " damages !" << std::endl;
  return this->_rangedDamage;
}

unsigned int FragTrap::meleeAttack(std::string const & target)
{
  std::cout << this->_name << " attacks suddenly  " << target << " at melee, causing " << this->_meleeDamage << " damages !" << std::endl;
  return this->_meleeDamage;
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
