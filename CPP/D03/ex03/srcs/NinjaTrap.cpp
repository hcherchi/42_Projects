#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) :
ClapTrap(60, 60, 120, 120, 60, 5, 0, "NinjaTrap")
{
  std::cout << "A NinjaTrap that wants to stay anonymous." << std::endl;
  return;
}


NinjaTrap::NinjaTrap(std::string _name) :
ClapTrap(_name, 60, 60, 120, 120, 60, 5, 0, "NinjaTrap")
{
  std::cout << this->_name << ", a NinjaTrap." << std::endl;
  return;
}

NinjaTrap::~NinjaTrap(void)
{
  std::cout << "The last attack was too much to afford for the poor NinjaTrap" << this->_name << std::endl;
  return;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) :
ClapTrap(src)
{
  *this = src;
  return;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & src)
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

unsigned int NinjaTrap::rangedAttack(std::string const & target)
{
  std::cout << this->_name << " attacks " << target << " furtively at range, causing " << this->_rangedDamage << " damages !" << std::endl;
  return this->_rangedDamage;
}

unsigned int NinjaTrap::meleeAttack(std::string const & target)
{
  std::cout << this->_name << " attacks " << target << " furtively at melee, causing " << this->_meleeDamage << " damages !" << std::endl;
  return this->_meleeDamage;
}

unsigned int NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
  unsigned int damages = 10;

  if (this->_energyPoints < 20)
  {
    std::cout << this->_name << " try to use its special ninja power on the NinjaTrap " << target.getName() << " but its energy is too low..." << std::endl;
    return 0;
  }
  std::cout << this->_name << " use its special ninja power on the NinjaTrap " << target.getName() << " causing " << damages << " damages" << std::endl;
  this->_energyPoints -= 20;
  return damages;
}

unsigned int NinjaTrap::ninjaShoebox(ScavTrap & target)
{
  unsigned int damages = 50;

  if (this->_energyPoints < 20)
  {
    std::cout << this->_name << " try to use its special ninja power on the ScavTrap " << target.getName() << " but its energy is too low..." << std::endl;
    return 0;
  }
  std::cout << this->_name << " use its special ninja power on the ScavTrap " << target.getName() << " causing " << damages << " damages" << std::endl;
  this->_energyPoints -= 20;
  return damages;
}

unsigned int NinjaTrap::ninjaShoebox(FragTrap & target)
{
  unsigned int damages = 70;

  if (this->_energyPoints < 20)
  {
    std::cout << this->_name << " try to use its special ninja power on the FragTrap " << target.getName() << " but its energy is too low..." << std::endl;
    return 0;
  }
  std::cout << this->_name << " use its special ninja power on the FragTrap " << target.getName() << " causing " << damages << " damages" << std::endl;
  this->_energyPoints -= 20;
  return damages;
}

unsigned int NinjaTrap::ninjaShoebox(ClapTrap & target)
{
  unsigned int damages = 20;

  if (this->_energyPoints < 20)
  {
    std::cout << this->_name << " try to use its special ninja power on the ClapTrap " << target.getName() << " but its energy is too low..." << std::endl;
    return 0;
  }
  std::cout << this->_name << " use its special ninja power on the ClapTrap " << target.getName() << " causing " << damages << " damages" << std::endl;
  this->_energyPoints -= 20;
  return damages;
}
