# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>

class FragTrap
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
    FragTrap(void);
    FragTrap(std::string _name);
    ~FragTrap(void);
    FragTrap(const FragTrap & src);
    FragTrap & operator = (const FragTrap & src);

    unsigned int rangedAttack(std::string const &target);
    unsigned int meleeAttack(std::string const &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    unsigned int vaulthunter_dot_exe(std::string const & target);

    std::string getName();
    unsigned int getHP();
    unsigned int getMP();
};

#endif
