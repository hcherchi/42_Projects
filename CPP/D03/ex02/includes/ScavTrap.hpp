# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  public:
    ScavTrap(void);
    ScavTrap(std::string _name);
    ~ScavTrap(void);
    ScavTrap(const ScavTrap & src);
    ScavTrap & operator = (const ScavTrap & src);

    unsigned int meleeAttack(std::string const & target);
    unsigned int rangedAttack(std::string const & target);
    unsigned int challengeNewcomer(std::string const & target);
};

#endif
