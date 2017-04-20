# ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{
  protected:
    std::string _name;
    int _apcost;
    int _damage;
  public:
    AWeapon(void);
    AWeapon(std::string const & name, int apcost, int damage);
    virtual ~AWeapon(void);
    AWeapon(const AWeapon & src);
    AWeapon & operator = (const AWeapon & src);

    std::string const & getName(void) const;
    int getApcost(void) const;
    int getDamage(void) const;
    virtual void attack() const = 0;
};

#endif
