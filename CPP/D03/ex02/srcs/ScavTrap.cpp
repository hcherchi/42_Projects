#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
ClapTrap(100, 100, 50, 50, 20, 15, 3, "ScavTrap")
{
  std::cout << "A ScavTrap that wants to stay anonymous." << std::endl;
  return;
}


ScavTrap::ScavTrap(std::string _name) :
ClapTrap(_name, 100, 100, 50, 50, 20, 15, 3, "ScavTrap")
{
  std::cout << this->_name << ", a ScavTrap." << std::endl;
  return;
}

ScavTrap::~ScavTrap(void)
{
  std::cout << "The last attack was too much to afford for the poor ScavTrap" << this->_name << ". it dies in real pain." << std::endl;
  return;
}

ScavTrap::ScavTrap(ScavTrap const & src) :
ClapTrap(src)
{
  *this = src;
  return;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
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

unsigned int ScavTrap::challengeNewcomer(std::string const & target)
{
  int cast = rand() % 4;
  unsigned int damages = 0;
  std::string challenge = "";

  if (this->_energyPoints < 25)
  {
    std::cout << this->_name << " try to challenge " << target << " but its energy is too low..." << std::endl;
    return 0;
  }
  switch (cast)
  {
    case 0:
      damages = 40;
      challenge = "move like Jagger";
      break;
    case 1:
      damages = 100;
      challenge = "watch 10 hours of Nyan Cat";
      break;
    case 2:
      damages = 0;
      challenge = "jump, but that was too easy...";
      break;
    case 3:
      damages = 0;
      challenge = "Meet its mother but it then remember its just a machine...";
      break;
    default:
      challenge = "BUG";
      break;
  }
  std::cout << this->_name << " challenge " << target << " to " << challenge << " causing " << damages << " damages" << std::endl;
  this->_energyPoints -= 25;
  return damages;
}
