# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
    FragTrap(void);
    FragTrap(std::string _name);
    ~FragTrap(void);
    FragTrap(const FragTrap & src);
    FragTrap & operator = (const FragTrap & src);

    unsigned int meleeAttack(std::string const & target);
    unsigned int rangedAttack(std::string const & target);
    unsigned int vaulthunter_dot_exe(std::string const & target);
};

#endif
