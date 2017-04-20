#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
  _hitPoints(100),
  _maxHitPoints(100),
  _energyPoints(50),
  _maxEnergyPoints(50),
  _level(1),
  _name("Anonymous"),
  _meleeDamage(20),
  _rangedDamage(15),
  _armor(3)
{
  std::cout << "A new ScavTrap joins the battle but wants to stay anonymous." << std::endl;
  return;
}


ScavTrap::ScavTrap(std::string _name) :
  _hitPoints(100),
  _maxHitPoints(100),
  _energyPoints(50),
  _maxEnergyPoints(50),
  _level(1),
  _name(_name != "" ? _name : "Anonymous"),
  _meleeDamage(20),
  _rangedDamage(15),
  _armor(3)
{
  std::cout << this->_name << ", a new ScavTrap, joins the battle." << std::endl;
  return;
}

ScavTrap::~ScavTrap(void)
{
  std::cout << "The last attack to much to afford for " << this->_name << ". it dies in real pain." << std::endl;
  return;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
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

unsigned int ScavTrap::rangedAttack(std::string const & target)
{
  std::cout << this->_name << " attacks " << target << " weakly at range, causing " << this->_rangedDamage << " damages !" << std::endl;
  return this->_rangedDamage;
}

unsigned int ScavTrap::meleeAttack(std::string const & target)
{
  std::cout << this->_name << " attacks " << target << " weakly at melee, causing " << this->_meleeDamage << " damages !" << std::endl;
  return this->_meleeDamage;
}

void ScavTrap::takeDamage(unsigned int amount)
{
  int realDamages = amount - this->_armor;
  if ((int)this->_hitPoints <= realDamages)
  {
    realDamages -= realDamages - this->_hitPoints;
    std::cout << this->_name << " use a weak shield to reduce damages still lose " << realDamages << " HP" << std::endl;
    this->_hitPoints -= realDamages;
  }
  else
  {
    std::cout << this->_name << " use a weak shield to reduce damages still lose " << realDamages << " HP" << std::endl;
    this->_hitPoints -= realDamages;
  }
}

void ScavTrap::beRepaired(unsigned int amount)
{
  if (this->_hitPoints + amount >= this->_maxHitPoints)
  {
    amount -= this->_hitPoints + amount - this->_maxHitPoints;
    std::cout << this->_name << " decide to repair itself weakly and recover " << amount << " of HP. He's now full." << std::endl;
    this->_hitPoints += amount;
  }
  else
  {
    std::cout << this->_name << " decide to repair itself weakly and recover " << amount << " HP" << std::endl;
    this->_hitPoints += amount;
  }
}

unsigned int ScavTrap::challengeNewcomer(std::string const & target)
{
  int cast = rand() % 5;
  unsigned int damages = 0;
  std::string challenge = "";

  if (this->_energyPoints < 25)
  {
    std::cout << this->_name << " try to use vaulhunter attack but its energy is too low..." << std::endl;
    return 0;
  }
  switch (cast)
  {
    case 0:
      damages = 100;
      challenge = "0";
      break;
    case 1:
      damages = 10;
      challenge = "1";
      break;
    case 2:
      damages = 20;
      challenge = "2";
      break;
    case 3:
      damages = 30;
      challenge = "3";
      break;
    case 4:
      damages = 40;
      challenge = "4";
      break;
    default:
      challenge = "BUG";
      break;
  }
  std::cout << this->_name << " challenge " << target << " to " << challenge << " causing " << damages << " damages" << std::endl;
  this->_energyPoints -= 25;
  return damages;
}

std::string ScavTrap::getName(void)
{
  return this->_name;
}

unsigned int ScavTrap::getHP(void)
{
  return this->_hitPoints;
}

unsigned int ScavTrap::getMP(void)
{
  return this->_energyPoints;
}
