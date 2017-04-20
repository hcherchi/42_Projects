# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
  protected:
    unsigned int _hitPoints;
    unsigned int _maxHitPoints;
    unsigned int _energyPoints;
    unsigned int _maxEnergyPoints;
    unsigned int _level;
    std::string _name;
    unsigned int _meleeDamage;
    unsigned int _rangedDamage;
    unsigned int _armor;
    std::string _type;
  public:
    ClapTrap(int _hitPoints, int maxHintPoints, int _energyPoints, int _maxEnergyPoints, int _meleeDamage, int _rangedDamage, int _armor, std::string _type);
    ClapTrap(std::string _name, int _hitPoints, int maxHintPoints, int _energyPoints, int _maxEnergyPoints, int _meleeDamage, int _rangedDamage, int _armor, std::string _type);
    ~ClapTrap(void);
    ClapTrap(const ClapTrap & src);
    ClapTrap & operator = (const ClapTrap & src);

    unsigned int meleeAttack(std::string const & target);
    unsigned int rangedAttack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName();
    unsigned int getHP();
    unsigned int getMP();
    std::string getType(void);
};

#endif
