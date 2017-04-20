# ifndef WEAPON_HPP
# define WEAPON_HPP

#include "Object.hpp"

class Weapon : public Object {

  public:
    Weapon(void);
    Weapon(int x, int y, char direction, int color);
    ~Weapon(void);
    Weapon(const Weapon & src);
    Weapon & operator = (const Weapon & src);
};

#endif
