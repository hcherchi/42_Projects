# ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class NinjaTrap : public ClapTrap
{
  public:
    NinjaTrap(void);
    NinjaTrap(std::string _name);
    ~NinjaTrap(void);
    NinjaTrap(const NinjaTrap & src);
    NinjaTrap & operator = (const NinjaTrap & src);

    unsigned int meleeAttack(std::string const & target);
    unsigned int rangedAttack(std::string const & target);
    unsigned int ninjaShoebox(NinjaTrap & target);
    unsigned int ninjaShoebox(ClapTrap & target);
    unsigned int ninjaShoebox(ScavTrap & target);
    unsigned int ninjaShoebox(FragTrap & target);
};
#endif
