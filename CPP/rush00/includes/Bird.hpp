# ifndef BIRD_HPP
# define BIRD_HPP

#include "Object.hpp"
#include "Weapon.hpp"

class Bird : public Object {

    public:
        Bird(void);
        ~Bird(void);
        Bird(const Bird & src);
        Bird & operator = (const Bird & src);

        Weapon *dropWeapon(void);
};

#endif
