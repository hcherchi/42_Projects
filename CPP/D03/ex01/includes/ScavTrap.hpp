# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{
  private:
    unsigned int _hitPoints;
    unsigned int _maxHitPoints;
    unsigned int _energyPoints;
    unsigned int _maxEnergyPoints;
    unsigned int _level;
    std::string _name;
    unsigned int _meleeDamage;
    unsigned int _rangedDamage;
    unsigned int _armor;
    
  public:
    ScavTrap(void);
    ScavTrap(std::string _name);
    ~ScavTrap(void);
    ScavTrap(const ScavTrap & src);
    ScavTrap & operator = (const ScavTrap & src);

    unsigned int rangedAttack(std::string const &target);
    unsigned int meleeAttack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    unsigned int challengeNewcomer(std::string const & target);

    std::string getName();
    unsigned int getHP();
    unsigned int getMP();
};

#endif
