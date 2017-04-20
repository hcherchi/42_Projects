# ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
  protected:
  public:
    PowerFist(void);
    ~PowerFist(void);
    PowerFist(const PowerFist & src);
    PowerFist & operator = (const PowerFist & src);

    void attack(void) const;
};

#endif
