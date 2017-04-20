# ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
  protected:
  public:
    PlasmaRifle(void);
    ~PlasmaRifle(void);
    PlasmaRifle(const PlasmaRifle & src);
    PlasmaRifle & operator = (const PlasmaRifle & src);

    void attack(void) const;
};

#endif
